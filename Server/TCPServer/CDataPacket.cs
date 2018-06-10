using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Steamhook.TCPServer
{

    enum EArgumentType
    {
        ARG_INVALID = 0,
        ARG_SIGNED,
        ARG_UNSIGNED,
        ARG_STRING,
        ARG_STRUCT,
        ARG_FLOAT,
        ARG_DOUBLE
    };

    class SDataPacketArg
    {
        public EArgumentType Type = EArgumentType.ARG_INVALID;
        public Byte[] Data;
    }

    class CDataPacket
    {
        public string Name;
        public List<SDataPacketArg> Args = new List<SDataPacketArg>();


        /// <summary>
        /// Reads a packed string from the length and data
        /// </summary>
        /// <returns>The packed ASCII string</returns>
        private static string ReadString(BinaryReader m_Stream)
        {
            var size = m_Stream.ReadUInt16();
            var str = m_Stream.ReadBytes(size);
            return Encoding.ASCII.GetString(str);
        }

        /// <summary>
        /// Reads a packed string from the length and data
        /// </summary>
        /// <returns>The packed ASCII string</returns>
        private static Byte[] ReadBytes32(BinaryReader m_Stream)
        {
            var size = m_Stream.ReadUInt32();
            var str = m_Stream.ReadBytes((int)size);
            return str;
        }

        public static CDataPacket Receive(BinaryReader m_Stream)
        {
            var packet = new CDataPacket();
            packet.Name = ReadString(m_Stream);

            var numArgs = m_Stream.ReadUInt16();

            for(int i = 0; i < numArgs; i++)
            {
                var recvArg = new SDataPacketArg();
                recvArg.Type = (EArgumentType)m_Stream.ReadUInt16();
                recvArg.Data = ReadBytes32(m_Stream);
                packet.Args.Add(recvArg);
            }

            return packet;
        }
    }
}
