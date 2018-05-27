using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading;
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

            if(!Client.Connected)
            {
                throw new Exception("Client disconnected");
            }

            Logger.Server.DebugLine($"Client {type} packet received");

            switch (type)
            {
                case C2SMessageType.ClientHello:
                    HandlePacket(ReadPacket<ClientHello>(ClientHello.Parser.ParseDelimitedFrom));
                    break;

                case C2SMessageType.Invalid:
                default:
                    throw new Exception($"Unexpected packet {type}");
            }
        }

        private T ReadPacket<T>(PacketParser parserfn)
        {
            T packet = (T)parserfn(m_Stream);
            if(!Client.Connected)
            {
                // If we disconnected, this is not a valid packet
                throw new Exception("Client disconnected");
            }

            return packet;
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
