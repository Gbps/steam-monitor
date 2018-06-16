#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamUser_Hooks : CHookManager<ISteamUser>
	{

	public:
		ISteamUser_Hooks() = delete;
		ISteamUser_Hooks(ISteamUser* obj) : CHookManager<ISteamUser>(obj) {};

        		
		HOOK_DECL(GetHSteamUser, 0, HSteamUser)
		{
			Util::Debug::PrintLine("GetHSteamUser!");

			return GetHSteamUserOriginal(This);
		}
				
		HOOK_DECL(BLoggedOn, 1, bool)
		{
			Util::Debug::PrintLine("BLoggedOn!");

			return BLoggedOnOriginal(This);
		}
				
		HOOK_DECL(GetSteamID, 2, CSteamID)
		{
			Util::Debug::PrintLine("GetSteamID!");

			return GetSteamIDOriginal(This);
		}
				
		HOOK_DECL(InitiateGameConnection, 3, int, void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure)
		{
			Util::Debug::PrintLine("InitiateGameConnection!");

			return InitiateGameConnectionOriginal(This, pAuthBlob, cbMaxAuthBlob, steamIDGameServer, unIPServer, usPortServer, bSecure);
		}
				
		HOOK_DECL(TerminateGameConnection, 4, void, uint32 unIPServer, uint16 usPortServer)
		{
			Util::Debug::PrintLine("TerminateGameConnection!");

			return TerminateGameConnectionOriginal(This, unIPServer, usPortServer);
		}
				
		HOOK_DECL(TrackAppUsageEvent, 5, void, CGameID gameID, int eAppUsageEvent, const char *pchExtraInfo = "")
		{
			Util::Debug::PrintLine("TrackAppUsageEvent!");

			return TrackAppUsageEventOriginal(This, gameID, eAppUsageEvent, "");
		}
				
		HOOK_DECL(GetUserDataFolder, 6, bool, char *pchBuffer, int cubBuffer)
		{
			Util::Debug::PrintLine("GetUserDataFolder!");

			return GetUserDataFolderOriginal(This, pchBuffer, cubBuffer);
		}
				
		HOOK_DECL(StartVoiceRecording, 7, void)
		{
			Util::Debug::PrintLine("StartVoiceRecording!");

			return StartVoiceRecordingOriginal(This);
		}
				
		HOOK_DECL(StopVoiceRecording, 8, void)
		{
			Util::Debug::PrintLine("StopVoiceRecording!");

			return StopVoiceRecordingOriginal(This);
		}
				
		HOOK_DECL(GetAvailableVoice, 9, EVoiceResult, uint32 *pcbCompressed, uint32 *pcbUncompressed_Deprecated = 0, uint32 nUncompressedVoiceDesiredSampleRate_Deprecated = 0)
		{
			Util::Debug::PrintLine("GetAvailableVoice!");

			return GetAvailableVoiceOriginal(This, pcbCompressed, 0, 0);
		}
				
		HOOK_DECL(GetVoice, 10, EVoiceResult, bool bWantCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten, bool bWantUncompressed_Deprecated = false, void *pUncompressedDestBuffer_Deprecated = 0, uint32 cbUncompressedDestBufferSize_Deprecated = 0, uint32 *nUncompressBytesWritten_Deprecated = 0, uint32 nUncompressedVoiceDesiredSampleRate_Deprecated = 0)
		{
			Util::Debug::PrintLine("GetVoice!");

			return GetVoiceOriginal(This, bWantCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, false, 0, 0, 0, 0);
		}
				
		HOOK_DECL(DecompressVoice, 11, EVoiceResult, const void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten, uint32 nDesiredSampleRate)
		{
			Util::Debug::PrintLine("DecompressVoice!");

			return DecompressVoiceOriginal(This, pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, nDesiredSampleRate);
		}
				
		HOOK_DECL(GetVoiceOptimalSampleRate, 12, uint32)
		{
			Util::Debug::PrintLine("GetVoiceOptimalSampleRate!");

			return GetVoiceOptimalSampleRateOriginal(This);
		}
				
		HOOK_DECL(GetAuthSessionTicket, 13, HAuthTicket, void *pTicket, int cbMaxTicket, uint32 *pcbTicket)
		{
			Util::Debug::PrintLine("GetAuthSessionTicket!");

			return GetAuthSessionTicketOriginal(This, pTicket, cbMaxTicket, pcbTicket);
		}
				
		HOOK_DECL(BeginAuthSession, 14, EBeginAuthSessionResult, const void *pAuthTicket, int cbAuthTicket, CSteamID steamID)
		{
			Util::Debug::PrintLine("BeginAuthSession!");

			return BeginAuthSessionOriginal(This, pAuthTicket, cbAuthTicket, steamID);
		}
				
		HOOK_DECL(EndAuthSession, 15, void, CSteamID steamID)
		{
			Util::Debug::PrintLine("EndAuthSession!");

			return EndAuthSessionOriginal(This, steamID);
		}
				
		HOOK_DECL(CancelAuthTicket, 16, void, HAuthTicket hAuthTicket)
		{
			Util::Debug::PrintLine("CancelAuthTicket!");

			return CancelAuthTicketOriginal(This, hAuthTicket);
		}
				
		HOOK_DECL(UserHasLicenseForApp, 17, EUserHasLicenseForAppResult, CSteamID steamID, AppId_t appID)
		{
			Util::Debug::PrintLine("UserHasLicenseForApp!");

			return UserHasLicenseForAppOriginal(This, steamID, appID);
		}
				
		HOOK_DECL(BIsBehindNAT, 18, bool)
		{
			Util::Debug::PrintLine("BIsBehindNAT!");

			return BIsBehindNATOriginal(This);
		}
				
		HOOK_DECL(AdvertiseGame, 19, void, CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer)
		{
			Util::Debug::PrintLine("AdvertiseGame!");

			return AdvertiseGameOriginal(This, steamIDGameServer, unIPServer, usPortServer);
		}
				
		HOOK_DECL(RequestEncryptedAppTicket, 20, SteamAPICall_t, void *pDataToInclude, int cbDataToInclude)
		{
			Util::Debug::PrintLine("RequestEncryptedAppTicket!");

			return RequestEncryptedAppTicketOriginal(This, pDataToInclude, cbDataToInclude);
		}
				
		HOOK_DECL(GetEncryptedAppTicket, 21, bool, void *pTicket, int cbMaxTicket, uint32 *pcbTicket)
		{
			Util::Debug::PrintLine("GetEncryptedAppTicket!");

			return GetEncryptedAppTicketOriginal(This, pTicket, cbMaxTicket, pcbTicket);
		}
				
		HOOK_DECL(GetGameBadgeLevel, 22, int, int nSeries, bool bFoil)
		{
			Util::Debug::PrintLine("GetGameBadgeLevel!");

			return GetGameBadgeLevelOriginal(This, nSeries, bFoil);
		}
				
		HOOK_DECL(GetPlayerSteamLevel, 23, int)
		{
			Util::Debug::PrintLine("GetPlayerSteamLevel!");

			return GetPlayerSteamLevelOriginal(This);
		}
				
		HOOK_DECL(RequestStoreAuthURL, 24, SteamAPICall_t, const char *pchRedirectURL)
		{
			Util::Debug::PrintLine("RequestStoreAuthURL!");

			return RequestStoreAuthURLOriginal(This, pchRedirectURL);
		}
				
		HOOK_DECL(BIsPhoneVerified, 25, bool)
		{
			Util::Debug::PrintLine("BIsPhoneVerified!");

			return BIsPhoneVerifiedOriginal(This);
		}
				
		HOOK_DECL(BIsTwoFactorEnabled, 26, bool)
		{
			Util::Debug::PrintLine("BIsTwoFactorEnabled!");

			return BIsTwoFactorEnabledOriginal(This);
		}
				
		HOOK_DECL(BIsPhoneIdentifying, 27, bool)
		{
			Util::Debug::PrintLine("BIsPhoneIdentifying!");

			return BIsPhoneIdentifyingOriginal(This);
		}
				
		HOOK_DECL(BIsPhoneRequiringVerification, 28, bool)
		{
			Util::Debug::PrintLine("BIsPhoneRequiringVerification!");

			return BIsPhoneRequiringVerificationOriginal(This);
		}
		
	};
}