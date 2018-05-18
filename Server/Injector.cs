using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.Remoting;
using System.IO;

namespace Server
{
    class Injector
    {
        public const string ClientDLLName = "steamhook32.dll";

        /// <summary>
        /// [pid, HMODULE] of all injected processes 
        /// </summary>
        private Dictionary<int, IntPtr> m_InjectedHandles = new Dictionary<int, IntPtr>();

        public Injector()
        {
        }

        ~Injector()
        {
            try
            {
                foreach (var kv in m_InjectedHandles)
                {
                    UninjectProc(kv.Key);
                }
            }
            catch (Exception) { };
        }

        /// <summary>
        /// Displays a dialog to ask the user what process to inject into
        /// </summary>
        /// <returns></returns>
        public int QueryUserForProcess()
        {
            var dialog = new PIDSelector();
            dialog.ShowDialog();
            
            if(dialog.SelectedPID == null)
            {
                return -1;
            }

            return int.Parse(dialog.SelectedPID);
        }

        /// <summary>
        /// Inject into process specified by pid
        /// </summary>
        /// <param name="pid"></param>
        public IntPtr InjectProc(int pid)
        {
            Logger.Server.DebugLine($"PID: {pid}");

            // Find client dll path
            string dllPath = GetInjectionLib();
            Logger.Server.DebugLine($"DLL Path: {dllPath}");

            var res = Inject32.InjectPid(pid, dllPath);

            Logger.Server.DebugLine("Injection successful");

            m_InjectedHandles[pid] = res;

            return res;
        }

        public void UninjectProc(int pid)
        {
            IntPtr handle;
            var found = m_InjectedHandles.TryGetValue(pid, out handle);
            if(!found)
            {
                throw new Exception("Tried to uninject a non-injected process");
            }

            Logger.Server.DebugLine($"Uninject PID: {pid}");

            Inject32.UninjectPid(pid, handle);

            Logger.Server.DebugLine("Uninjection successful");
        }

        /// <summary>
        /// Get the location of the client dll to be injected
        /// </summary>
        /// <returns>String to the path of the client dll</returns>
        public string GetInjectionLib()
        {
            string fullPath = (typeof(Injector)).Assembly.Location;
            string dir = Path.GetDirectoryName(fullPath);
            string file = Path.Combine(dir, ClientDLLName);

            if(!File.Exists(file))
            {
                throw new Exception($"Could not find {ClientDLLName}!");
            }

            return file;
        }
    }
}
