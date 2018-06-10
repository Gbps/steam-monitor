using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
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

        private BinaryReader m_Stream;

        private delegate object PacketParser(System.IO.Stream stream);

        public ProtoServerClient(TcpClient client)
        {
            Client = client;
            m_Stream = new BinaryReader(client.GetStream());
        }

        private const UInt16 PKT_HEADER_MAGIC = 0xABBA;
        private const UInt16 PKT_TYPE_DATA = 0x01;

        private static string ByteArrayToString(byte[] ba)
        {
            return BitConverter.ToString(ba).Replace("-", " ");
        }

        /// <summary>
        /// Receives a CDataPacket
        /// </summary>
        /// <param name="size">Size of the remaining packet</param>
        private void RecvDataPacket(UInt32 size)
        {
            var pkt = CDataPacket.Receive(m_Stream);
            Logger.Client.DebugLine($"Data Packet {pkt.Name}:");
            foreach( var arg in pkt.Args )
            {
                Logger.Client.DebugLine($"\tType {arg.Type.ToString()}: {ByteArrayToString(arg.Data)}");
            }
        }

        // Receives the packet header, id, and checks for size
        private void RecvPacket()
        {
            var magic = m_Stream.ReadUInt16();
            if(magic != PKT_HEADER_MAGIC)
            {
                throw new Exception("Invalid magic header");
            }

            var id = m_Stream.ReadUInt16();
            var size = m_Stream.ReadUInt32();

            switch(id)
            {
                case PKT_TYPE_DATA:
                    RecvDataPacket(size);
                break;
            }

        }

        /// <summary>
        /// Handles all client interaction until the client disconnects
        /// </summary>
        public void HandleForever()
        {
            while(true)
            {
                // Get a packet descriptor of the packet to follow
                RecvPacket();

                // Read in the packet and handle it
                //DispatchPacket(packetdesc);
            }
        }

    }
}
