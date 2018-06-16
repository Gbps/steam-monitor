#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamAppList_Hooks : CHookManager<ISteamAppList>
	{

	public:
		ISteamAppList_Hooks() = delete;
		ISteamAppList_Hooks(ISteamAppList* obj) : CHookManager<ISteamAppList>(obj) {};

        		
		HOOK_DECL(GetNumInstalledApps, 0, uint32)
		{
			Util::Debug::PrintLine("GetNumInstalledApps!");

			return GetNumInstalledAppsOriginal(This);
		}
				
		HOOK_DECL(GetInstalledApps, 1, uint32, AppId_t *pvecAppID, uint32 unMaxAppIDs)
		{
			Util::Debug::PrintLine("GetInstalledApps!");

			return GetInstalledAppsOriginal(This, pvecAppID, unMaxAppIDs);
		}
				
		HOOK_DECL(GetAppBuildId, 2, int, AppId_t nAppID)
		{
			Util::Debug::PrintLine("GetAppBuildId!");

			return GetAppBuildIdOriginal(This, nAppID);
		}
		
	};
}