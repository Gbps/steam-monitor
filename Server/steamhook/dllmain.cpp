// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

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

DWORD * __stdcall SteamHookMain()
{
	CallMsg();
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
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&SteamHookMain, NULL, 0, &outThreadId);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

