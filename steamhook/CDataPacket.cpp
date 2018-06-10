#include "CDataPacket.h"

void CDataPacket::InitPacket(const std::string & name)
{
	m_Packet.Header.Id = PKT_TYPE_DATA;
	m_Packet.Name.Name = name;
	m_Packet.Name.NameSize = (uint16_t)name.length();

}

CDataPacket::CDataPacket()
{
}


CDataPacket::~CDataPacket()
{
}
