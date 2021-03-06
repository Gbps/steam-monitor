// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

#include "TCPSocketClient.h"

typedef void (__cdecl * MsgFn)(char const* pMsg, ...);
MsgFn Msg;

void CallMsg()
{
	Msg = (MsgFn)GetProcAddress(GetModuleHandle("tier0.dll"), "Msg");
	if (Msg)
	{
		Msg("[SteamHook Injected]");
	}
}

DWORD WINAPI SteamHookMain(LPVOID param)
{
	CallMsg();

	steamhook::CTcpSocketClient client;

	client.InitConnect("127.0.0.1", "10405");

	return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
	DWORD outThreadId;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		// Let's get out of DllMain because you aren't supposed to do shit here
		CreateThread(NULL, 0, SteamHookMain, NULL, 0, &outThreadId);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

