#pragma once

#include "stdafx.h"
#include <vector>
#include <memory>
#include <sstream>

#define PKT_HEADER_MAGIC 0xABBA
#define PKT_TYPE_DATA 0x01;

enum class EArgumentType
{
	ARG_INVALID = 0,
	ARG_SIGNED,
	ARG_UNSIGNED,
	ARG_STRING,
	ARG_STRUCT,
	ARG_FLOAT,
	ARG_DOUBLE
};

// Header of the packet
class CDataPacketHeader
{
public:
	uint16_t Magic = PKT_HEADER_MAGIC;
	uint16_t Id = 0;
};

// Name packet
class CDataPacketName
{
public:
	uint16_t NameSize = 0;
	std::string Name;
	uint16_t NumArgs = 0;
};

// Data of arguments
class CDataPacketArg
{
public:
	uint16_t TypeNum = 0;
	uint32_t DataSize = 0;
	std::string Data;

	CDataPacketArg(EArgumentType typenum, const std::string& data)
	{
		Data = data;
		DataSize = static_cast<uint32_t>(data.length());
		TypeNum = static_cast<uint16_t>(typenum);
	}

};

// Data packet sent to server containing a single API call
class CDataPacketData
{
public:
	CDataPacketHeader Header;
	CDataPacketName Name;
	std::vector<CDataPacketArg> Args{};
};


// Data packet serializer for sending over the wire
class CDataPacket
{

private:
	CDataPacketData m_Packet;
	
	// Create std::string based on POD (Plain old data) types using sizeof to copy their little-endian bytes
	template <class T, typename = std::enable_if_t<std::is_pod_v<T>>>
	static std::string StringFromRaw(T arg);

	// Copy any std::string constructible data into a new std::string
	template <class T, typename = std::enable_if_t<std::is_constructible<std::string, T>>>
	static std::string StringFromRaw(std::string arg);

public:

	/*
		These templates will automatically assign a packet type designator based on the general type of the object passed in
	*/

	// Anything default is typed to struct
	template<typename T, typename Enable = void>
	struct CArgumentType {
		constexpr static EArgumentType type = EArgumentType::ARG_STRUCT;
	};

	// 4-byte float
	template<typename T>
	struct CArgumentType<T, typename std::enable_if_t<std::is_same_v<T, float>>> {
		constexpr static EArgumentType type = EArgumentType::ARG_FLOAT;
	};
	
	// 8-byte double
	template<typename T>
	struct CArgumentType<T, typename std::enable_if_t<std::is_same_v<T, double> || std::is_same_v<T, long double>>> {
		constexpr static EArgumentType type = EArgumentType::ARG_DOUBLE;
	};
	
	// Signed integers
	template<typename T>
	struct CArgumentType<T, typename std::enable_if_t<std::is_integral_v<T> && std::is_signed_v<T>>> {
		constexpr static EArgumentType type = EArgumentType::ARG_SIGNED;
	};
	
	// Unsigned integers
	template<typename T>
	struct CArgumentType<T, typename std::enable_if_t<std::is_integral_v<T> && std::is_unsigned_v<T>>> {
		constexpr static EArgumentType type = EArgumentType::ARG_UNSIGNED;
	};

	// String argument (std::string or char* or const char*)
	template<typename T>
	struct CArgumentType<T, typename std::enable_if_t<std::is_convertible_v<T, std::string>>> {
		constexpr static EArgumentType type = EArgumentType::ARG_STRING;
	};

	
	// Create packet with the given function name
	void InitPacket(const std::string & name);

	// Add an argument to the data packet
	// Accepts all forms of POD (plain old data like structs and fundamental types) and most c-string objects
	template <typename T>
	void AddArgument(T argument);

#define WRITE_TO_STREAM(OBJ) outstr.write((const char*)&OBJ, sizeof(decltype(OBJ)))
#define WRITE_TO_STREAM_STR(OBJ) outstr << OBJ

	// Serialize the packet to flat data 
	inline std::string Serialize() const;

	CDataPacket();
	~CDataPacket();

};

template <class T, typename>
std::string CDataPacket::StringFromRaw(T arg)
{
	return std::string{reinterpret_cast<char*>(&arg), sizeof(T)};
}

template <class T, typename>
std::string CDataPacket::StringFromRaw(std::string arg)
{
	return arg;
}

template <typename T>
void CDataPacket::AddArgument(T argument)
{
	const auto typeCode = CArgumentType<T>::type;

	m_Packet.Args.emplace_back(typeCode, StringFromRaw(argument));
	m_Packet.Name.NumArgs += 1;
}

inline std::string CDataPacket::Serialize() const
{
	std::stringstream outstr;

	auto zero = 0x00000000;

	// Packet Type Header
	WRITE_TO_STREAM(m_Packet.Header.Magic);
	WRITE_TO_STREAM(m_Packet.Header.Id);

	// Name Header
	WRITE_TO_STREAM(m_Packet.Name.NameSize);
	WRITE_TO_STREAM_STR(m_Packet.Name.Name);
	WRITE_TO_STREAM(m_Packet.Name.NumArgs);

	// Arguments
	for (const auto& arg : m_Packet.Args)
	{
		WRITE_TO_STREAM(arg.TypeNum);
		WRITE_TO_STREAM(arg.DataSize);
		WRITE_TO_STREAM_STR(arg.Data);
	}

	return outstr.str();
}
