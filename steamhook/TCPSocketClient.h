#pragma once

#include "stdafx.h"
#include "CDataPacket.h"

#pragma comment (lib, "Ws2_32.lib")

namespace steamhook
{
	class CTcpSocketClient
	{
	private:

		// Main socket connection to the server process
		SOCKET ConnectSocket = INVALID_SOCKET;

	public:

		// Initiates a connection to the server process
		bool InitConnect(const char* targetHost, const char* targetPort);

		// Queue packet to be sent over the connection
		void SendPacket(const CDataPacket& packet) const;


		CTcpSocketClient() = default;
	};
}


