using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.Remoting;
using System.IO;

namespace Steamhook
{
    class Injector
    {
        /// <summary>
        /// [pid, HMODULE] of all injected processes 
        /// </summary>
        private Dictionary<int, List<IntPtr>> m_InjectedHandles = new Dictionary<int, List<IntPtr>>();

        public Injector()
        {
        }

        ~Injector()
        {
            UninjectAll();
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
        public IntPtr InjectProc(int pid, string dllname)
        {
            Logger.Server.DebugLine($"PID: {pid}");

            // Find client dll path
            string dllPath = GetInjectionLib(dllname);
            Logger.Server.DebugLine($"DLL Path: {dllPath}");

            var res = Inject32.InjectPid(pid, dllPath);

            Logger.Server.DebugLine("Injection successful");

            if(!m_InjectedHandles.ContainsKey(pid))
            {
                m_InjectedHandles[pid] = new List<IntPtr>();
            }

            m_InjectedHandles[pid].Add(res);

            return res;
        }

        public void UninjectProc(int pid)
        {
            List<IntPtr> handlelist;
            var found = m_InjectedHandles.TryGetValue(pid, out handlelist);
            if(!found)
            {
                throw new Exception("Tried to uninject a non-injected process");
            }

            Logger.Server.DebugLine($"Uninject PID: {pid}");

            foreach( var handle in handlelist )
            {
                Logger.Server.DebugLine($"\tUninject: {handle}");
                Inject32.UninjectPid(pid, handle);
            }

            Logger.Server.DebugLine("Uninjection successful");
        }

        /// <summary>
        /// Get the location of the client dll to be injected
        /// </summary>
        /// <returns>String to the path of the client dll</returns>
        public string GetInjectionLib(string dllname)
        {
            string fullPath = (typeof(Injector)).Assembly.Location;
            string dir = Path.GetDirectoryName(fullPath);
            string file = Path.Combine(dir, dllname);

            if(!File.Exists(file))
            {
                throw new Exception($"Could not find {dllname}!");
            }

            return file;
        }

        /// <summary>
        /// Uninjects all modules from all processes currently injected into. Does not throw.
        /// </summary>
        public void UninjectAll()
        {
            // Clean up all the other modules
            // NOTE: later should be done with pipe connection
            try
            {
                foreach (var kv in m_InjectedHandles)
                {
                    UninjectProc(kv.Key);
                }
            }
            catch (Exception) { };
        }
    }
}
