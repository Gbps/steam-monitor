# Parses virtual function declarations from Steam API header files into JSON format

import re
import os

# An SDK header file to parse
class SDKFile:

    # Parses out the class name and data from the file
    # Group 1: Name of the class
    # Group 2: Contents of class between braces { }
    re_class = re.compile(r"class (\S+)\s*\{([^\}]+)\}")

    # Parses a single virtual function, including its // comments
    # Each match is one function:
        # Group 1: All // comments before the function, including newlines and slashes
        # Group 2: Return value of function
        # Group 3: Name of function
        # Group 4: All arguments between the parens ( )
    re_virtfunc = re.compile(r"(//.+?)(?=\s+virtual).*?virtual (\S+) ([^\(]+)\(([^\)]*)\)", re.DOTALL)
   
    # filedata: The contents of the header file to parse
    def __init__(self, filedata):
        self.funcs = []
        self.parsefile(filedata)

    def parsefile(self, filedata):
        # Find header class and grab contents
        mtch = SDKFile.re_class.search(filedata)
        if not mtch:
            # No class defined in file, stop scanning
            self.sclass = ""
            return
        else:
            self.sclass = mtch.group(1)
            self.data = mtch.group(2)

        mtches = SDKFile.re_virtfunc.findall(self.data)
        idx = 0

        # Parse out each virtual function match
        for mtch in mtches:
            func = SDKVirtualFunction(mtch, idx)
            idx += 1
            self.funcs.append(func)
    
    def __str__(self):
        return f"[SDKFile | {len(self.funcs)} functions]"
    
    __repr__ = __str__
# A single virtual function parsed with regex
class SDKVirtualFunction:
    def __init__(self, mtch, idx):
        self.comments = mtch[0].strip()
        self.retval = mtch[1].strip()
        self.name = mtch[2].strip()
        self.argsstr = mtch[3].strip()
        self.parseargs(self.argsstr)
        self.idx = idx

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
    
    def __str__(self):
        return f"{self.retval} {self.name}( {self.argsstr} )"
    
    __repr__ = __str__

if __name__ == "__main__":
    f = open("./isteamuser.h").read()
    sdk = SDKFile(f)



        
        


