using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.ConstrainedExecution;
using System.Runtime.InteropServices;
using System.Security;
using System.Text;

namespace Steamhook
{
    public static class Inject32
    {
        /// <summary>
        /// Injects a native DLL into a process
        /// </summary>
        /// <param name="TargetPid">The target process PID</param>
        /// <param name="DllPath">The full path to the DLL to load</param>
        /// <exception cref="Exception">A win32 API call failed</exception>
        /// <exception cref="ArgumentException">DLL path does not exist</exception>
        public static void InjectPid(int TargetPid, string DllPath)
        {
            IntPtr thrdHandle = IntPtr.Zero;
            IntPtr procHandle = IntPtr.Zero;

            try
            {
                if (!File.Exists(DllPath))
                {
                    throw new ArgumentException("File does not exist");
                }

                procHandle = OpenProcess(
                    ProcessAccessFlags.CreateThread |
                    ProcessAccessFlags.QueryInformation |
                    ProcessAccessFlags.VirtualMemoryOperation |
                    ProcessAccessFlags.VirtualMemoryWrite |
                    ProcessAccessFlags.VirtualMemoryRead,
                    false,
                    TargetPid
                );

                if (procHandle == null)
                    throw new Exception("Could not open handle to target process");

                IntPtr loadLibrary = GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");

                if (loadLibrary == null)
                    throw new Exception("Could not get kernel32.dll LoadLibraryA");

                uint dwSize = (uint)DllPath.Length + 1;

                IntPtr strMem = VirtualAllocEx(procHandle, IntPtr.Zero, dwSize, AllocationType.Commit | AllocationType.Reserve, MemoryProtection.ReadWrite);
                if (strMem == null)
                    throw new Exception("Failed VirtualAllocEx");

                uint lpBytesWritten;
                WriteProcessMemory(procHandle, strMem, Encoding.ASCII.GetBytes(DllPath), dwSize, out lpBytesWritten);

                if (lpBytesWritten != dwSize)
                    throw new Exception("WriteProcessMemory did not write all bytes");

                // LoadLibraryA is a valid LPTHREAD_START_ROUTINE since it returns a 32-bit value and
                thrdHandle = CreateRemoteThread(procHandle, IntPtr.Zero, 0, loadLibrary, strMem, 0, IntPtr.Zero);

                if (thrdHandle == null)
                    throw new Exception("CreateRemoteThread failed");

                VirtualFreeEx(procHandle, strMem, dwSize, AllocationType.Decommit | AllocationType.Release);

                // Wait on remote LoadLibrary to finish to so we can get the return HMODULE
                WaitForSingleObject(thrdHandle, 1000);



            }
            catch (Exception)
            {
                if(thrdHandle != null)
                {
                    CloseHandle(thrdHandle);
                }

                if(procHandle != null)
                {
                    CloseHandle(procHandle);
                }

                throw;
            }
        }

        /// <summary>
        /// Uninjects a native DLL from a process by calling FreeLibrary
        /// </summary>
        /// <param name="TargetPid">The target process PID</param>
        /// <param name="DllPath">The full path to the DLL to load</param>
        /// <exception cref="Exception">A win32 API call failed</exception>
        /// <exception cref="ArgumentException">DLL path does not exist</exception>
        public static void UninjectPid(int TargetPid, string DllPath)
        {
            IntPtr thrdHandle = IntPtr.Zero;
            IntPtr procHandle = IntPtr.Zero;

            try
            {
                if (!File.Exists(DllPath))
                {
                    throw new ArgumentException("File does not exist");
                }

                procHandle = OpenProcess(
                    ProcessAccessFlags.CreateThread |
                    ProcessAccessFlags.QueryInformation |
                    ProcessAccessFlags.VirtualMemoryOperation |
                    ProcessAccessFlags.VirtualMemoryWrite |
                    ProcessAccessFlags.VirtualMemoryRead,
                    false,
                    TargetPid
                );

                if (procHandle == null)
                    throw new Exception("Could not open handle to target process");

                IntPtr loadLibrary = GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");

                if (loadLibrary == null)
                    throw new Exception("Could not get kernel32.dll LoadLibraryA");

                uint dwSize = (uint)DllPath.Length + 1;

                IntPtr strMem = VirtualAllocEx(procHandle, IntPtr.Zero, dwSize, AllocationType.Commit | AllocationType.Reserve, MemoryProtection.ReadWrite);
                if (strMem == null)
                    throw new Exception("Failed VirtualAllocEx");

                uint lpBytesWritten;
                WriteProcessMemory(procHandle, strMem, Encoding.ASCII.GetBytes(DllPath), dwSize, out lpBytesWritten);

                if (lpBytesWritten != dwSize)
                    throw new Exception("WriteProcessMemory did not write all bytes");

                thrdHandle = CreateRemoteThread(procHandle, IntPtr.Zero, 0, loadLibrary, strMem, 0, IntPtr.Zero);

                if (thrdHandle == null)
                    throw new Exception("CreateRemoteThread failed");

                VirtualFreeEx(procHandle, strMem, dwSize, AllocationType.Decommit | AllocationType.Release);

            }
            catch (Exception)
            {
                if (thrdHandle != null)
                {
                    CloseHandle(thrdHandle);
                }

                if (procHandle != null)
                {
                    CloseHandle(procHandle);
                }

                throw;
            }
        }

        [DllImport("kernel32.dll", SetLastError = true)]
        static extern UInt32 WaitForSingleObject(IntPtr hHandle, UInt32 dwMilliseconds);

        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern bool WriteProcessMemory(
            IntPtr hProcess,
            IntPtr lpBaseAddress,
            byte[] lpBuffer,
            UInt32 nSize,
            out uint lpNumberOfBytesWritten);

        [DllImport("kernel32.dll")]
        public static extern IntPtr CreateRemoteThread(IntPtr hProcess,
            IntPtr lpThreadAttributes, uint dwStackSize, IntPtr
            lpStartAddress, IntPtr lpParameter, uint dwCreationFlags, IntPtr lpThreadId);

        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern IntPtr OpenProcess(
                ProcessAccessFlags processAccess,
                bool bInheritHandle,
                int processId
        );

        [DllImport("kernel32", CharSet = CharSet.Ansi, ExactSpelling = true, SetLastError = true)]
        public static extern IntPtr GetProcAddress(IntPtr hModule, string procName);

        [DllImport("kernel32.dll", CharSet = CharSet.Auto)]
        public static extern IntPtr GetModuleHandle(string lpModuleName);

        [DllImport("kernel32.dll", SetLastError = true, ExactSpelling = true)]
        public static extern IntPtr VirtualAllocEx(IntPtr hProcess, IntPtr lpAddress,
                uint dwSize, AllocationType flAllocationType, MemoryProtection flProtect);

        [DllImport("kernel32.dll", SetLastError = true, ExactSpelling = true)]
        static extern bool VirtualFreeEx(IntPtr hProcess, IntPtr lpAddress,
            uint dwSize, AllocationType dwFreeType);

        [DllImport("kernel32.dll", SetLastError = true)]
        [ReliabilityContract(Consistency.WillNotCorruptState, Cer.Success)]
        [SuppressUnmanagedCodeSecurity]
        [return: MarshalAs(UnmanagedType.Bool)]
        static extern bool CloseHandle(IntPtr hObject);

        [Flags]
        public enum AllocationType
        {
            Commit = 0x1000,
            Reserve = 0x2000,
            Decommit = 0x4000,
            Release = 0x8000,
            Reset = 0x80000,
            Physical = 0x400000,
            TopDown = 0x100000,
            WriteWatch = 0x200000,
            LargePages = 0x20000000
        }

        [Flags]
        public enum MemoryProtection
        {
            Execute = 0x10,
            ExecuteRead = 0x20,
            ExecuteReadWrite = 0x40,
            ExecuteWriteCopy = 0x80,
            NoAccess = 0x01,
            ReadOnly = 0x02,
            ReadWrite = 0x04,
            WriteCopy = 0x08,
            GuardModifierflag = 0x100,
            NoCacheModifierflag = 0x200,
            WriteCombineModifierflag = 0x400
        }

        [Flags]
        public enum ProcessAccessFlags : uint
        {
            All = 0x001F0FFF,
            Terminate = 0x00000001,
            CreateThread = 0x00000002,
            VirtualMemoryOperation = 0x00000008,
            VirtualMemoryRead = 0x00000010,
            VirtualMemoryWrite = 0x00000020,
            DuplicateHandle = 0x00000040,
            CreateProcess = 0x000000080,
            SetQuota = 0x00000100,
            SetInformation = 0x00000200,
            QueryInformation = 0x00000400,
            QueryLimitedInformation = 0x00001000,
            Synchronize = 0x00100000
        }
    }
}
