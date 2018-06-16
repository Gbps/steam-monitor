#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamGameServerStats_Hooks : CHookManager<ISteamGameServerStats>
	{

	public:
		ISteamGameServerStats_Hooks() = delete;
		ISteamGameServerStats_Hooks(ISteamGameServerStats* obj) : CHookManager<ISteamGameServerStats>(obj) {};

        		
		HOOK_DECL(RequestUserStats, 0, SteamAPICall_t, CSteamID steamIDUser)
		{
			Util::Debug::PrintLine("RequestUserStats!");

			return RequestUserStatsOriginal(This, steamIDUser);
		}
				
		HOOK_DECL(GetUserStat, 1, bool, CSteamID steamIDUser, const char *pchName, int32 *pData)
		{
			Util::Debug::PrintLine("GetUserStat!");

			return GetUserStatOriginal(This, steamIDUser, pchName, pData);
		}
				
		HOOK_DECL(GetUserStat, 2, bool, CSteamID steamIDUser, const char *pchName, float *pData)
		{
			Util::Debug::PrintLine("GetUserStat!");

			return GetUserStatOriginal(This, steamIDUser, pchName, pData);
		}
				
		HOOK_DECL(GetUserAchievement, 3, bool, CSteamID steamIDUser, const char *pchName, bool *pbAchieved)
		{
			Util::Debug::PrintLine("GetUserAchievement!");

			return GetUserAchievementOriginal(This, steamIDUser, pchName, pbAchieved);
		}
				
		HOOK_DECL(SetUserStat, 4, bool, CSteamID steamIDUser, const char *pchName, int32 nData)
		{
			Util::Debug::PrintLine("SetUserStat!");

			return SetUserStatOriginal(This, steamIDUser, pchName, nData);
		}
				
		HOOK_DECL(SetUserStat, 5, bool, CSteamID steamIDUser, const char *pchName, float fData)
		{
			Util::Debug::PrintLine("SetUserStat!");

			return SetUserStatOriginal(This, steamIDUser, pchName, fData);
		}
				
		HOOK_DECL(UpdateUserAvgRateStat, 6, bool, CSteamID steamIDUser, const char *pchName, float flCountThisSession, double dSessionLength)
		{
			Util::Debug::PrintLine("UpdateUserAvgRateStat!");

			return UpdateUserAvgRateStatOriginal(This, steamIDUser, pchName, flCountThisSession, dSessionLength);
		}
				
		HOOK_DECL(SetUserAchievement, 7, bool, CSteamID steamIDUser, const char *pchName)
		{
			Util::Debug::PrintLine("SetUserAchievement!");

			return SetUserAchievementOriginal(This, steamIDUser, pchName);
		}
				
		HOOK_DECL(ClearUserAchievement, 8, bool, CSteamID steamIDUser, const char *pchName)
		{
			Util::Debug::PrintLine("ClearUserAchievement!");

			return ClearUserAchievementOriginal(This, steamIDUser, pchName);
		}
				
		HOOK_DECL(StoreUserStats, 9, SteamAPICall_t, CSteamID steamIDUser)
		{
			Util::Debug::PrintLine("StoreUserStats!");

			return StoreUserStatsOriginal(This, steamIDUser);
		}
		
	};
}