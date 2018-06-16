#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamApps_Hooks : CHookManager<ISteamApps>
	{

	public:
		ISteamApps_Hooks() = delete;
		ISteamApps_Hooks(ISteamApps* obj) : CHookManager<ISteamApps>(obj) {};

        		
		HOOK_DECL(BIsSubscribed, 0, bool)
		{
			Util::Debug::PrintLine("BIsSubscribed!");

			return BIsSubscribedOriginal(This);
		}
				
		HOOK_DECL(BIsLowViolence, 1, bool)
		{
			Util::Debug::PrintLine("BIsLowViolence!");

			return BIsLowViolenceOriginal(This);
		}
				
		HOOK_DECL(BIsCybercafe, 2, bool)
		{
			Util::Debug::PrintLine("BIsCybercafe!");

			return BIsCybercafeOriginal(This);
		}
				
		HOOK_DECL(BIsVACBanned, 3, bool)
		{
			Util::Debug::PrintLine("BIsVACBanned!");

			return BIsVACBannedOriginal(This);
		}
				
		HOOK_DECL(GetCurrentGameLanguage, 4, const char *)
		{
			Util::Debug::PrintLine("GetCurrentGameLanguage!");

			return GetCurrentGameLanguageOriginal(This);
		}
				
		HOOK_DECL(GetAvailableGameLanguages, 5, const char *)
		{
			Util::Debug::PrintLine("GetAvailableGameLanguages!");

			return GetAvailableGameLanguagesOriginal(This);
		}
				
		HOOK_DECL(BIsSubscribedApp, 6, bool, AppId_t appID)
		{
			Util::Debug::PrintLine("BIsSubscribedApp!");

			return BIsSubscribedAppOriginal(This, appID);
		}
				
		HOOK_DECL(BIsDlcInstalled, 7, bool, AppId_t appID)
		{
			Util::Debug::PrintLine("BIsDlcInstalled!");

			return BIsDlcInstalledOriginal(This, appID);
		}
				
		HOOK_DECL(GetEarliestPurchaseUnixTime, 8, uint32, AppId_t nAppID)
		{
			Util::Debug::PrintLine("GetEarliestPurchaseUnixTime!");

			return GetEarliestPurchaseUnixTimeOriginal(This, nAppID);
		}
				
		HOOK_DECL(BIsSubscribedFromFreeWeekend, 9, bool)
		{
			Util::Debug::PrintLine("BIsSubscribedFromFreeWeekend!");

			return BIsSubscribedFromFreeWeekendOriginal(This);
		}
				
		HOOK_DECL(GetDLCCount, 10, int)
		{
			Util::Debug::PrintLine("GetDLCCount!");

			return GetDLCCountOriginal(This);
		}
				
		HOOK_DECL(BGetDLCDataByIndex, 11, bool, int iDLC, AppId_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize)
		{
			Util::Debug::PrintLine("BGetDLCDataByIndex!");

			return BGetDLCDataByIndexOriginal(This, iDLC, pAppID, pbAvailable, pchName, cchNameBufferSize);
		}
				
		HOOK_DECL(InstallDLC, 12, void, AppId_t nAppID)
		{
			Util::Debug::PrintLine("InstallDLC!");

			return InstallDLCOriginal(This, nAppID);
		}
				
		HOOK_DECL(UninstallDLC, 13, void, AppId_t nAppID)
		{
			Util::Debug::PrintLine("UninstallDLC!");

			return UninstallDLCOriginal(This, nAppID);
		}
				
		HOOK_DECL(RequestAppProofOfPurchaseKey, 14, void, AppId_t nAppID)
		{
			Util::Debug::PrintLine("RequestAppProofOfPurchaseKey!");

			return RequestAppProofOfPurchaseKeyOriginal(This, nAppID);
		}
				
		HOOK_DECL(GetCurrentBetaName, 15, bool, char *pchName, int cchNameBufferSize)
		{
			Util::Debug::PrintLine("GetCurrentBetaName!");

			return GetCurrentBetaNameOriginal(This, pchName, cchNameBufferSize);
		}
				
		HOOK_DECL(MarkContentCorrupt, 16, bool, bool bMissingFilesOnly)
		{
			Util::Debug::PrintLine("MarkContentCorrupt!");

			return MarkContentCorruptOriginal(This, bMissingFilesOnly);
		}
				
		HOOK_DECL(GetInstalledDepots, 17, uint32, AppId_t appID, DepotId_t *pvecDepots, uint32 cMaxDepots)
		{
			Util::Debug::PrintLine("GetInstalledDepots!");

			return GetInstalledDepotsOriginal(This, appID, pvecDepots, cMaxDepots);
		}
				
		HOOK_DECL(GetAppInstallDir, 18, uint32, AppId_t appID, char *pchFolder, uint32 cchFolderBufferSize)
		{
			Util::Debug::PrintLine("GetAppInstallDir!");

			return GetAppInstallDirOriginal(This, appID, pchFolder, cchFolderBufferSize);
		}
				
		HOOK_DECL(BIsAppInstalled, 19, bool, AppId_t appID)
		{
			Util::Debug::PrintLine("BIsAppInstalled!");

			return BIsAppInstalledOriginal(This, appID);
		}
				
		HOOK_DECL(GetAppOwner, 20, CSteamID)
		{
			Util::Debug::PrintLine("GetAppOwner!");

			return GetAppOwnerOriginal(This);
		}
				
		HOOK_DECL(GetLaunchQueryParam, 21, const char *, const char *pchKey)
		{
			Util::Debug::PrintLine("GetLaunchQueryParam!");

			return GetLaunchQueryParamOriginal(This, pchKey);
		}
				
		HOOK_DECL(GetDlcDownloadProgress, 22, bool, AppId_t nAppID, uint64 *punBytesDownloaded, uint64 *punBytesTotal)
		{
			Util::Debug::PrintLine("GetDlcDownloadProgress!");

			return GetDlcDownloadProgressOriginal(This, nAppID, punBytesDownloaded, punBytesTotal);
		}
				
		HOOK_DECL(GetAppBuildId, 23, int)
		{
			Util::Debug::PrintLine("GetAppBuildId!");

			return GetAppBuildIdOriginal(This);
		}
				
		HOOK_DECL(RequestAllProofOfPurchaseKeys, 24, void)
		{
			Util::Debug::PrintLine("RequestAllProofOfPurchaseKeys!");

			return RequestAllProofOfPurchaseKeysOriginal(This);
		}
				
		HOOK_DECL(GetFileDetails, 25, SteamAPICall_t, const char* pszFileName)
		{
			Util::Debug::PrintLine("GetFileDetails!");

			return GetFileDetailsOriginal(This, pszFileName);
		}
		
	};
}