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

        private List<ProtoServerClient> m_Clients = new List<ProtoServerClient>();

        /// <summary>
        /// The TCP port the server is listening on
        /// </summary>
        public int Port { get; private set; }

        public ProtoServer()
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
                m_Endpoint = new IPEndPoint(IPAddress.Loopback, port);

                m_Listener = new TcpListener(m_Endpoint);
                m_Listener.Start();

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
        /// Spawns a worker thread to handle the client
        /// </summary>
        /// <param name="protoClient"></param>
        private void AcceptClient(ProtoServerClient protoClient)
        {
            Logger.Server.DebugLine($"Client connect: {protoClient.Client.Client.RemoteEndPoint}");

            // Queue the communication into new thread
            // When that thread disconnects, remove that client from the client list
            var newThread = new Thread(o =>
            {
                try
                {

                    protoClient.HandleForever();
                }
                catch (Exception)
                {

                }
                finally
                {
                    RemoveClient(protoClient);
                }
            });

            protoClient.AcceptorThread = newThread;

            m_Clients.Add(protoClient);

            newThread.Start();
        }

        /// <summary>
        /// Removes a current connected client from the active list
        /// </summary>
        /// <param name="client">The client</param>
        private void RemoveClient(ProtoServerClient client)
        {
            Logger.Server.DebugLine($"Client disconnect: {client.Client.Client.RemoteEndPoint}");

            m_Clients.Remove(client);

            // Close resources just in case
            client.Client.Close();
            client.AcceptorThread.Abort();
        }
        /// <summary>
        /// Accept clients from the endpoint and handle their threads
        /// </summary>
        private void ServerMainThread()
        {
            Logger.Server.DebugLine($"Starting server @ {m_Endpoint}");

            while(true)
            {
                var client = m_Listener.AcceptTcpClient();
                var protoClient = new ProtoServerClient(client);
                AcceptClient(protoClient);
            }
        }
    }
}
