using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using EasyHook;
using System.Runtime.Remoting;
using System.IO;

namespace Server
{
    class Injector
    {
        public const string ClientDLLName = "Client.dll";

        public Injector()
        {
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
        public bool InjectProc(int pid)
        {
            string channelName = null;

            Logger.Server.DebugLine($"PID: {pid}");

            // Create server for communicating with injected processes
            RemoteHooking.IpcCreateServer<ServerInterface>(ref channelName, WellKnownObjectMode.Singleton);

            // Find Client dll
            string dllPath = GetInjectionLib();
            Logger.Server.DebugLine($"DLL Path: {dllPath}");

            try
            {
                EasyHook.RemoteHooking.Inject(
                      pid,          // ID of process to inject into
                      dllPath,      // 32-bit library to inject (if target is 32-bit)
                      dllPath,      // 64-bit library to inject (if target is 64-bit)
                      channelName   // the parameters to pass into injected library
                );
            }
            catch (Exception e)
            {
                Logger.Server.Error("Failed to inject into target", e);
                return false;
            }

            Logger.Server.DebugLine("Injection successful");
            return true;
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
