using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using static Steamhook.C2SMessage.Types;

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

        private NetworkStream m_Stream;

        ProtoServerClient(TcpClient client)
        {
            Client = client;
            m_Stream = client.GetStream();
        }

        /// <summary>
        /// Receive the packet descriptor of the packet that will follow
        /// </summary>
        private C2SMessage RecvPacketDescriptor()
        {
            try
            {
                var message = C2SMessage.Parser.ParseFrom(m_Stream);
                return message;
            }
            catch(Exception e)
            {
                Logger.Server.Error("Failed to receive C2SMessage", e);
                throw;
            }
        }

        /// <summary>
        /// Handles packets from the client
        /// </summary>
        /// <param name="message">The packet descriptor</param>
        private void DispatchPacket(C2SMessage message)
        {
            var type = message.Type;

            Logger.Server.DebugLine($"{type} received");

            switch (type)
            {
                case C2SMessageType.ClientHello:
                    HandlePacket(ClientHello.Parser.ParseDelimitedFrom(m_Stream));
                    break;

                default:
                    throw new Exception($"Unexpected packet type {type}");
            }
        }

        private void HandlePacket(ClientHello message)
        {
        }
        /// <summary>
        /// Handles all client interaction until the client disconnects
        /// </summary>
        public void HandleForever()
        {
            while(true)
            {
                // Get a packet descriptor of the packet to follow
                var packetdesc = RecvPacketDescriptor();

                // Read in the packet and handle it
                DispatchPacket(packetdesc);
            }
        }

    }
}
