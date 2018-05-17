using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Client
{
    public class EntryPoint : EasyHook.IEntryPoint
    {
        /// <summary>
        /// Reference to the server interface within FileMonitor
        /// </summary>
        Server.ServerInterface _server = null;

        public EntryPoint(EasyHook.RemoteHooking.IContext context, string channelName)
        {
            // Connect to server object using provided channel name
            _server = EasyHook.RemoteHooking.IpcConnectClient<Server.ServerInterface>(channelName);

            // If Ping fails then the Run method will be not be called
            _server.Ping();
        }

        public void Run(EasyHook.RemoteHooking.IContext context, string channelName)
        {
            _server.IsInstalled(EasyHook.RemoteHooking.GetCurrentProcessId());
        }
    }
}
