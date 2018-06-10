#include "CDataPacket.h"

void CDataPacket::InitPacket(const std::string & name)
{
	m_Packet.Header.Id = PKT_TYPE_DATA;
	m_Packet.Name.Name = name;
	m_Packet.Name.NameSize = static_cast<uint16_t>(name.length());

}

CDataPacket::CDataPacket() = default;


CDataPacket::~CDataPacket() = default;
