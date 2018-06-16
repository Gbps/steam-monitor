#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamUserStats_Hooks : CHookManager<ISteamUserStats>
	{

	public:
		ISteamUserStats_Hooks() = delete;
		ISteamUserStats_Hooks(ISteamUserStats* obj) : CHookManager<ISteamUserStats>(obj) {};

        		
		HOOK_DECL(RequestCurrentStats, 0, bool)
		{
			Util::Debug::PrintLine("RequestCurrentStats!");

			return RequestCurrentStatsOriginal(This);
		}
				
		HOOK_DECL(GetStat, 1, bool, const char *pchName, int32 *pData)
		{
			Util::Debug::PrintLine("GetStat!");

			return GetStatOriginal(This, pchName, pData);
		}
				
		HOOK_DECL(GetStat, 2, bool, const char *pchName, float *pData)
		{
			Util::Debug::PrintLine("GetStat!");

			return GetStatOriginal(This, pchName, pData);
		}
				
		HOOK_DECL(SetStat, 3, bool, const char *pchName, int32 nData)
		{
			Util::Debug::PrintLine("SetStat!");

			return SetStatOriginal(This, pchName, nData);
		}
				
		HOOK_DECL(SetStat, 4, bool, const char *pchName, float fData)
		{
			Util::Debug::PrintLine("SetStat!");

			return SetStatOriginal(This, pchName, fData);
		}
				
		HOOK_DECL(UpdateAvgRateStat, 5, bool, const char *pchName, float flCountThisSession, double dSessionLength)
		{
			Util::Debug::PrintLine("UpdateAvgRateStat!");

			return UpdateAvgRateStatOriginal(This, pchName, flCountThisSession, dSessionLength);
		}
				
		HOOK_DECL(GetAchievement, 6, bool, const char *pchName, bool *pbAchieved)
		{
			Util::Debug::PrintLine("GetAchievement!");

			return GetAchievementOriginal(This, pchName, pbAchieved);
		}
				
		HOOK_DECL(SetAchievement, 7, bool, const char *pchName)
		{
			Util::Debug::PrintLine("SetAchievement!");

			return SetAchievementOriginal(This, pchName);
		}
				
		HOOK_DECL(ClearAchievement, 8, bool, const char *pchName)
		{
			Util::Debug::PrintLine("ClearAchievement!");

			return ClearAchievementOriginal(This, pchName);
		}
				
		HOOK_DECL(GetAchievementAndUnlockTime, 9, bool, const char *pchName, bool *pbAchieved, uint32 *punUnlockTime)
		{
			Util::Debug::PrintLine("GetAchievementAndUnlockTime!");

			return GetAchievementAndUnlockTimeOriginal(This, pchName, pbAchieved, punUnlockTime);
		}
				
		HOOK_DECL(StoreStats, 10, bool)
		{
			Util::Debug::PrintLine("StoreStats!");

			return StoreStatsOriginal(This);
		}
				
		HOOK_DECL(GetAchievementIcon, 11, int, const char *pchName)
		{
			Util::Debug::PrintLine("GetAchievementIcon!");

			return GetAchievementIconOriginal(This, pchName);
		}
				
		HOOK_DECL(GetAchievementDisplayAttribute, 12, const char *, const char *pchName, const char *pchKey)
		{
			Util::Debug::PrintLine("GetAchievementDisplayAttribute!");

			return GetAchievementDisplayAttributeOriginal(This, pchName, pchKey);
		}
				
		HOOK_DECL(IndicateAchievementProgress, 13, bool, const char *pchName, uint32 nCurProgress, uint32 nMaxProgress)
		{
			Util::Debug::PrintLine("IndicateAchievementProgress!");

			return IndicateAchievementProgressOriginal(This, pchName, nCurProgress, nMaxProgress);
		}
				
		HOOK_DECL(GetNumAchievements, 14, uint32)
		{
			Util::Debug::PrintLine("GetNumAchievements!");

			return GetNumAchievementsOriginal(This);
		}
				
		HOOK_DECL(GetAchievementName, 15, const char *, uint32 iAchievement)
		{
			Util::Debug::PrintLine("GetAchievementName!");

			return GetAchievementNameOriginal(This, iAchievement);
		}
				
		HOOK_DECL(RequestUserStats, 16, SteamAPICall_t, CSteamID steamIDUser)
		{
			Util::Debug::PrintLine("RequestUserStats!");

			return RequestUserStatsOriginal(This, steamIDUser);
		}
				
		HOOK_DECL(GetUserStat, 17, bool, CSteamID steamIDUser, const char *pchName, int32 *pData)
		{
			Util::Debug::PrintLine("GetUserStat!");

			return GetUserStatOriginal(This, steamIDUser, pchName, pData);
		}
				
		HOOK_DECL(GetUserStat, 18, bool, CSteamID steamIDUser, const char *pchName, float *pData)
		{
			Util::Debug::PrintLine("GetUserStat!");

			return GetUserStatOriginal(This, steamIDUser, pchName, pData);
		}
				
		HOOK_DECL(GetUserAchievement, 19, bool, CSteamID steamIDUser, const char *pchName, bool *pbAchieved)
		{
			Util::Debug::PrintLine("GetUserAchievement!");

			return GetUserAchievementOriginal(This, steamIDUser, pchName, pbAchieved);
		}
				
		HOOK_DECL(GetUserAchievementAndUnlockTime, 20, bool, CSteamID steamIDUser, const char *pchName, bool *pbAchieved, uint32 *punUnlockTime)
		{
			Util::Debug::PrintLine("GetUserAchievementAndUnlockTime!");

			return GetUserAchievementAndUnlockTimeOriginal(This, steamIDUser, pchName, pbAchieved, punUnlockTime);
		}
				
		HOOK_DECL(ResetAllStats, 21, bool, bool bAchievementsToo)
		{
			Util::Debug::PrintLine("ResetAllStats!");

			return ResetAllStatsOriginal(This, bAchievementsToo);
		}
				
		HOOK_DECL(FindOrCreateLeaderboard, 22, SteamAPICall_t, const char *pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType)
		{
			Util::Debug::PrintLine("FindOrCreateLeaderboard!");

			return FindOrCreateLeaderboardOriginal(This, pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType);
		}
				
		HOOK_DECL(FindLeaderboard, 23, SteamAPICall_t, const char *pchLeaderboardName)
		{
			Util::Debug::PrintLine("FindLeaderboard!");

			return FindLeaderboardOriginal(This, pchLeaderboardName);
		}
				
		HOOK_DECL(GetLeaderboardName, 24, const char *, SteamLeaderboard_t hSteamLeaderboard)
		{
			Util::Debug::PrintLine("GetLeaderboardName!");

			return GetLeaderboardNameOriginal(This, hSteamLeaderboard);
		}
				
		HOOK_DECL(GetLeaderboardEntryCount, 25, int, SteamLeaderboard_t hSteamLeaderboard)
		{
			Util::Debug::PrintLine("GetLeaderboardEntryCount!");

			return GetLeaderboardEntryCountOriginal(This, hSteamLeaderboard);
		}
				
		HOOK_DECL(GetLeaderboardSortMethod, 26, ELeaderboardSortMethod, SteamLeaderboard_t hSteamLeaderboard)
		{
			Util::Debug::PrintLine("GetLeaderboardSortMethod!");

			return GetLeaderboardSortMethodOriginal(This, hSteamLeaderboard);
		}
				
		HOOK_DECL(GetLeaderboardDisplayType, 27, ELeaderboardDisplayType, SteamLeaderboard_t hSteamLeaderboard)
		{
			Util::Debug::PrintLine("GetLeaderboardDisplayType!");

			return GetLeaderboardDisplayTypeOriginal(This, hSteamLeaderboard);
		}
				
		HOOK_DECL(DownloadLeaderboardEntries, 28, SteamAPICall_t, SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd)
		{
			Util::Debug::PrintLine("DownloadLeaderboardEntries!");

			return DownloadLeaderboardEntriesOriginal(This, hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd);
		}
				
		HOOK_DECL(DownloadLeaderboardEntriesForUsers, 29, SteamAPICall_t, SteamLeaderboard_t hSteamLeaderboard,
															    CSteamID *prgUsers, int cUsers)
		{
			Util::Debug::PrintLine("DownloadLeaderboardEntriesForUsers!");

			return DownloadLeaderboardEntriesForUsersOriginal(This, hSteamLeaderboard, prgUsers, cUsers);
		}
				
		HOOK_DECL(GetDownloadedLeaderboardEntry, 30, bool, SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, LeaderboardEntry_t *pLeaderboardEntry, int32 *pDetails, int cDetailsMax)
		{
			Util::Debug::PrintLine("GetDownloadedLeaderboardEntry!");

			return GetDownloadedLeaderboardEntryOriginal(This, hSteamLeaderboardEntries, index, pLeaderboardEntry, pDetails, cDetailsMax);
		}
				
		HOOK_DECL(UploadLeaderboardScore, 31, SteamAPICall_t, SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, const int32 *pScoreDetails, int cScoreDetailsCount)
		{
			Util::Debug::PrintLine("UploadLeaderboardScore!");

			return UploadLeaderboardScoreOriginal(This, hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount);
		}
				
		HOOK_DECL(AttachLeaderboardUGC, 32, SteamAPICall_t, SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC)
		{
			Util::Debug::PrintLine("AttachLeaderboardUGC!");

			return AttachLeaderboardUGCOriginal(This, hSteamLeaderboard, hUGC);
		}
				
		HOOK_DECL(GetNumberOfCurrentPlayers, 33, SteamAPICall_t)
		{
			Util::Debug::PrintLine("GetNumberOfCurrentPlayers!");

			return GetNumberOfCurrentPlayersOriginal(This);
		}
				
		HOOK_DECL(RequestGlobalAchievementPercentages, 34, SteamAPICall_t)
		{
			Util::Debug::PrintLine("RequestGlobalAchievementPercentages!");

			return RequestGlobalAchievementPercentagesOriginal(This);
		}
				
		HOOK_DECL(GetMostAchievedAchievementInfo, 35, int, char *pchName, uint32 unNameBufLen, float *pflPercent, bool *pbAchieved)
		{
			Util::Debug::PrintLine("GetMostAchievedAchievementInfo!");

			return GetMostAchievedAchievementInfoOriginal(This, pchName, unNameBufLen, pflPercent, pbAchieved);
		}
				
		HOOK_DECL(GetNextMostAchievedAchievementInfo, 36, int, int iIteratorPrevious, char *pchName, uint32 unNameBufLen, float *pflPercent, bool *pbAchieved)
		{
			Util::Debug::PrintLine("GetNextMostAchievedAchievementInfo!");

			return GetNextMostAchievedAchievementInfoOriginal(This, iIteratorPrevious, pchName, unNameBufLen, pflPercent, pbAchieved);
		}
				
		HOOK_DECL(GetAchievementAchievedPercent, 37, bool, const char *pchName, float *pflPercent)
		{
			Util::Debug::PrintLine("GetAchievementAchievedPercent!");

			return GetAchievementAchievedPercentOriginal(This, pchName, pflPercent);
		}
				
		HOOK_DECL(RequestGlobalStats, 38, SteamAPICall_t, int nHistoryDays)
		{
			Util::Debug::PrintLine("RequestGlobalStats!");

			return RequestGlobalStatsOriginal(This, nHistoryDays);
		}
				
		HOOK_DECL(GetGlobalStat, 39, bool, const char *pchStatName, int64 *pData)
		{
			Util::Debug::PrintLine("GetGlobalStat!");

			return GetGlobalStatOriginal(This, pchStatName, pData);
		}
				
		HOOK_DECL(GetGlobalStat, 40, bool, const char *pchStatName, double *pData)
		{
			Util::Debug::PrintLine("GetGlobalStat!");

			return GetGlobalStatOriginal(This, pchStatName, pData);
		}
				
		HOOK_DECL(GetGlobalStatHistory, 41, int32, const char *pchStatName,  int64 *pData, uint32 cubData)
		{
			Util::Debug::PrintLine("GetGlobalStatHistory!");

			return GetGlobalStatHistoryOriginal(This, pchStatName, pData, cubData);
		}
				
		HOOK_DECL(GetGlobalStatHistory, 42, int32, const char *pchStatName,  double *pData, uint32 cubData)
		{
			Util::Debug::PrintLine("GetGlobalStatHistory!");

			return GetGlobalStatHistoryOriginal(This, pchStatName, pData, cubData);
		}
				
		HOOK_DECL(InstallPS3Trophies, 43, bool)
		{
			Util::Debug::PrintLine("InstallPS3Trophies!");

			return InstallPS3TrophiesOriginal(This);
		}
				
		HOOK_DECL(GetTrophySpaceRequiredBeforeInstall, 44, uint64)
		{
			Util::Debug::PrintLine("GetTrophySpaceRequiredBeforeInstall!");

			return GetTrophySpaceRequiredBeforeInstallOriginal(This);
		}
				
		HOOK_DECL(SetUserStatsData, 45, bool, const void *pvData, uint32 cubData)
		{
			Util::Debug::PrintLine("SetUserStatsData!");

			return SetUserStatsDataOriginal(This, pvData, cubData);
		}
				
		HOOK_DECL(GetUserStatsData, 46, bool, void *pvData, uint32 cubData, uint32 *pcubWritten)
		{
			Util::Debug::PrintLine("GetUserStatsData!");

			return GetUserStatsDataOriginal(This, pvData, cubData, pcubWritten);
		}
		
	};
}