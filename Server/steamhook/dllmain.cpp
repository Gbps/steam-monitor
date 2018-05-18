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
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		CallMsg();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

