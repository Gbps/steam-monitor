using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace Steamhook.TCPServer
{
    /// <summary>
    /// Handles a single client
    /// </summary>
    class ProtoServerClient
    {
        /// <summary>
        /// The TCP client associated with this object
        /// </summary>
        public TcpClient Client { get; private set; }

        /// <summary>
        /// The thread accepting data from the client
        /// </summary>
        public Thread AcceptorThread { get; set; }

        private NetworkStream m_Stream;

        private delegate object PacketParser(System.IO.Stream stream);

        public ProtoServerClient(TcpClient client)
        {
            Client = client;
            m_Stream = client.GetStream();
        }

        /// <summary>
        /// Handles all client interaction until the client disconnects
        /// </summary>
        public void HandleForever()
        {
            while(true)
            {
                // Get a packet descriptor of the packet to follow
                //var packetdesc = RecvPacketDescriptor();

                // Read in the packet and handle it
                //DispatchPacket(packetdesc);
            }
        }

    }
}
