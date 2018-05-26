using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Steamhook.TCPServer
{
    /// <summary>
    /// Handles all communiation from an injected client
    /// </summary>
    class ProtoServer
    {

        private TcpListener m_Listener;

        private IPEndPoint m_Endpoint;

        private Thread m_Thread;

        /// <summary>
        /// The TCP port the server is listening on
        /// </summary>
        public int Port { get; private set; }

        ProtoServer()
        {

        }

        /// <summary>
        /// Start listening for connections on localhost
        /// </summary>
        /// <param name="port">The TCP port to listen on</param>
        public void StartListen(int port)
        {
            if(m_Thread != null)
            {
                throw new Exception($"Server is already running on {m_Endpoint}");
            }

            try
            {
                var addr = Dns.GetHostEntry(Dns.GetHostName()).AddressList[0];
                m_Endpoint = new IPEndPoint(addr, port);

                m_Listener = new TcpListener(m_Endpoint);

                m_Thread = new Thread(ServerMainThread);
                m_Thread.Start();
            }
            catch (Exception e)
            {
                Logger.Server.Error("Failed to StartListen", e);
                throw;
            }
        }

        /// <summary>
        /// Accept clients from the endpoint and handle their threads
        /// </summary>
        private void ServerMainThread()
        {
            var client = m_Listener.AcceptTcpClient();

            Logger.Server.DebugLine($"Incoming client: {client.Client.RemoteEndPoint}");
            k
        }
    }
}
