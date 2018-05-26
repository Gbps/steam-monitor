# Parses virtual function declarations from Steam API header files into JSON format

import re
import os
import json
import glob

# Path to the interfaces directory
dir_path = os.path.dirname(os.path.realpath(__file__))
SDK_PATH = os.path.realpath(os.path.join(dir_path, "..\\steamhook\\includes\\sdk\\public\\steam"))

# An SDK header file to parse
class SDKFile:

    # Parses out the class name and data from the file
    # Group 1: Name of the class
    # Group 2: Contents of class between braces { }
    re_class = re.compile(r"class (\S+)\s*\{([\S\s]+)(?=\}\s*;)")

    # Parses a single virtual function, including its // comments
    # Each match is one function:
        # Group 1: All // comments before the function, including newlines and slashes
        # Group 2: Return value of function
        # Group 3: Name of function
        # Group 4: All arguments between the parens ( )
    re_virtfunc = re.compile(r"(//[\S\s]+?)?(?=\s*virtual).*?virtual ((?:\w+ )+(?!\()\*?)(\w+)\(([^\)]*)\)")
   
    # Finds the interface version based on the #define in the file
    # Group 1: Name of the interface
    # Group 2: Interface version string
    re_interface = re.compile(r"^\#define (\S+?(?=INTERFACE_VERSION)INTERFACE_VERSION) \"([^\"]+)\"\s*$", re.MULTILINE)

    # Cleans extra argument macros that Valve uses
    re_clean = re.compile(r"(ARRAY_COUNT_D|OUT_STRING|ARRAY_COUNT|OUT_ARRAY_CALL|OUT_STRUCT|OUT_ARRAY_CALL|OUT_ARRAY_COUNT|OUT_BUFFER_COUNT|OUT_STRING_COUNT)\([^\)]+\)")

    # filedata: The contents of the header file to parse
    def __init__(self, filedata):
        self.funcs = {}
        self.cppinterface = None
        self.cppinterfacev = None
        filedata = self.cleanfile(filedata)
        self.parsefile(filedata)
        self.parseinterface(filedata)

    def parsefile(self, filedata):
        # Find header class and grab contents
        mtch = SDKFile.re_class.search(filedata)
        if not mtch:
            # No class defined in file, stop scanning
            self.cppclass = ""
            return

        self.cppclass = mtch.group(1)
        data = mtch.group(2)

        mtches = SDKFile.re_virtfunc.findall(data)
        idx = 0

        # Parse out each virtual function match
        for mtch in mtches:
            func = SDKVirtualFunction(mtch, idx)
            idx += 1
            self.funcs[func.vfindex] = func
    
    def parseinterface(self, filedata):
        # Pulls out the interface name of the class
        mtch = SDKFile.re_interface.search(filedata)
        if mtch:
            self.cppinterface = mtch.group(1)
            self.cppinterfacev = mtch.group(2)
    
    def cleanfile(self, filedata):
        # Huge hack to fix argument parsing due to lack of recursive regex functionality in `re`
        return SDKFile.re_clean.sub("", filedata)
    
    def __str__(self):
        if not self.cppinterface:
            return f"[{self.cppclass} | {len(self.funcs)} functions]"
        else:
            return f"[{self.cppclass} ({self.cppinterfacev}) | {len(self.funcs)} functions]"
    
    __repr__ = __str__
# A single virtual function parsed with regex
class SDKVirtualFunction:
    def __init__(self, mtch, idx):
        self._fixcomments(mtch[0])
        self.retval = mtch[1].strip()
        self.name = mtch[2].strip()
        self.argsstr = mtch[3].strip()
        self.parseargs(self.argsstr)
        self.vfindex = idx

    # Parses each individual argument and populates args and nargs
    def parseargs(self, args):
        if args == "":
            self.args = []
            self.nargs = 0
            return
        
        splt = args.split(",")
        self.nargs = len(splt)
        self.args = [self._fixarg(x) for x in splt]

    # Fix the type *name declaration for pointers because it messes with the type/name split
    def _fixarg(self, arg):
        return arg.replace(" *", "* ").strip()
    
    # Removes // and strips extra whitespace
    def _fixcomments(self, comments):
        if comments == "":
            return
        self.comments = comments.replace("//", "").replace("\t", "").strip()
        self.comments = self.comments[0].upper() + self.comments[1:]

    def __str__(self):
        return f"{self.retval} {self.name}( {self.argsstr} )"
    
    __repr__ = __str__

# Save json form of the python object to a file
def SaveJson(obj, outfile, **kwargs):
    s = json.dumps(obj, default=lambda x: x.__dict__, **kwargs)
    with open(outfile, "w") as f:
        f.write(s)
        print(f"Wrote out to {outfile}")

# Parse all sdk header files
def GetAllClassesFromDir(path):
    gpath = os.path.join(path, "*.h")
    out = {}
    for path in glob.glob(gpath):
        print(f"Parsing {path}")

        # Read and parse file
        with open(path) as f:
            sdk = SDKFile(f.read())
            if sdk.cppclass != "" and len(sdk.funcs) > 0:
                # Valid parse
                out[sdk.cppclass] = (sdk)
                print(f"\t{sdk}")
    
    return out

if __name__ == "__main__":
    files = GetAllClassesFromDir(SDK_PATH)
    SaveJson(files, "./sdkfuncs.min.json")
    SaveJson(files, "./sdkfuncs.json", indent=4, sort_keys=True)


        
        


