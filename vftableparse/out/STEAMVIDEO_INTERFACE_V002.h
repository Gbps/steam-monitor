#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamVideo_Hooks : CHookManager<ISteamVideo>
	{

	public:
		ISteamVideo_Hooks() = delete;
		ISteamVideo_Hooks(ISteamVideo* obj) : CHookManager<ISteamVideo>(obj) {};

        		
		HOOK_DECL(GetVideoURL, 0, void, AppId_t unVideoAppID)
		{
			Util::Debug::PrintLine("GetVideoURL!");

			return GetVideoURLOriginal(This, unVideoAppID);
		}
				
		HOOK_DECL(IsBroadcasting, 1, bool, int *pnNumViewers)
		{
			Util::Debug::PrintLine("IsBroadcasting!");

			return IsBroadcastingOriginal(This, pnNumViewers);
		}
				
		HOOK_DECL(GetOPFSettings, 2, void, AppId_t unVideoAppID)
		{
			Util::Debug::PrintLine("GetOPFSettings!");

			return GetOPFSettingsOriginal(This, unVideoAppID);
		}
				
		HOOK_DECL(GetOPFStringForApp, 3, bool, AppId_t unVideoAppID, char *pchBuffer, int32 *pnBufferSize)
		{
			Util::Debug::PrintLine("GetOPFStringForApp!");

			return GetOPFStringForAppOriginal(This, unVideoAppID, pchBuffer, pnBufferSize);
		}
		
	};
}