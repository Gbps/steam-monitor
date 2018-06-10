#include "TCPSocketClient.h"

using namespace steamhook;


bool CTcpSocketClient::InitConnect(const char * targetHost, const char * targetPort)
{
	// -- Incoming pasta --
	WSADATA wsaData;
	struct addrinfo *result = nullptr,
		*ptr = nullptr,
		hints;

	auto iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		Util::Debug::Warning("WSAStartup failed with error: %d", iResult);
		return false;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
	iResult = getaddrinfo(targetHost, targetPort, &hints, &result);
	if (iResult != 0)
	{
		Util::Debug::Warning("getaddrinfo failed with error: %d", iResult);
		WSACleanup();
		return false;
	}

	// Attempt to connect to an address until one succeeds
	for (ptr = result; ptr != nullptr; ptr = ptr->ai_next)
	{
		// Create a SOCKET for connecting to server
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
			ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET) {
			Util::Debug::Warning("socket failed with error: %ld", WSAGetLastError());
			WSACleanup();
			return false;
		}

		// Connect to server.
		iResult = connect(ConnectSocket, ptr->ai_addr, static_cast<int>(ptr->ai_addrlen));
		if (iResult == SOCKET_ERROR) {
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET) {  // NOLINT(readability-simplify-boolean-expr)
		Util::Debug::Warning("Unable to connect to server!");
		WSACleanup();
		return false;
	}

	return true;
}

void steamhook::CTcpSocketClient::SendPacket(const CDataPacket& packet) const
{
	auto pktToSend = packet.Serialize();

	send(ConnectSocket, &pktToSend[0], pktToSend.size(), 0);
}

CTcpSocketClient::CTcpSocketClient() = default;


CTcpSocketClient::~CTcpSocketClient() = default;
