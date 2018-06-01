#pragma once

#include "stdafx.h"

#pragma comment (lib, "Ws2_32.lib")

namespace steamhook
{
	class TCPSocketClient
	{
	private:
		SOCKET ConnectSocket = INVALID_SOCKET;

	public:
		bool InitConnect(const char* targetHost, const char* targetPort);

		TCPSocketClient();
		~TCPSocketClient();
	};
}


