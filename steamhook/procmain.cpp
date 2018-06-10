// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

#include "TCPSocketClient.h"
#include "CDataPacket.h"
#include "Steam/Interfaces.h"
#include "Steam/APIHook.h"

struct Test
{
	int test;
	unsigned int test2;
};


void ToHook()
{
	Util::Debug::PrintLine("ToHook function!");
}

void ToHookDetour(decltype(ToHook)* original)
{
	Util::Debug::PrintLine("ToHook Detour!");
	original();
}

int main(int argc, char *argv[])
{
	steamhook::CTcpSocketClient client;

	client.InitConnect("127.0.0.1", "10405");

	CDataPacket pkt;

	Test test = { 0x1337, 0xCAFEBABE };

	pkt.InitPacket("Hello");
	pkt.AddArgument(test);
	pkt.AddArgument(1.0L);
	pkt.AddArgument(-2);

	client.SendPacket(pkt);

	SteamAPI_Init();
	
	Steam::CInterfaces interfaces;
	if (!interfaces.InitSteamConnection())
	{ 
		Util::Debug::Error("Failed to initialize Steam::Interfaces");
		return 0;
	}
		
	auto test3 = interfaces.GetISteamNetworking(STEAMNETWORKING_INTERFACE_VERSION);

	Steam::CApiHook hook{ "TestHook" };

	hook.Hook(ToHook, ToHookDetour);
	hook.Enable();

	ToHook();
	getchar();
	return 0;
}
