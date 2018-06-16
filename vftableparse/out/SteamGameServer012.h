#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamGameServer_Hooks : CHookManager<ISteamGameServer>
	{

	public:
		ISteamGameServer_Hooks() = delete;
		ISteamGameServer_Hooks(ISteamGameServer* obj) : CHookManager<ISteamGameServer>(obj) {};

        		
		HOOK_DECL(InitGameServer, 0, bool, uint32 unIP, uint16 usGamePort, uint16 usQueryPort, uint32 unFlags, AppId_t nGameAppId, const char *pchVersionString)
		{
			Util::Debug::PrintLine("InitGameServer!");

			return InitGameServerOriginal(This, unIP, usGamePort, usQueryPort, unFlags, nGameAppId, pchVersionString);
		}
				
		HOOK_DECL(SetProduct, 1, void, const char *pszProduct)
		{
			Util::Debug::PrintLine("SetProduct!");

			return SetProductOriginal(This, pszProduct);
		}
				
		HOOK_DECL(SetGameDescription, 2, void, const char *pszGameDescription)
		{
			Util::Debug::PrintLine("SetGameDescription!");

			return SetGameDescriptionOriginal(This, pszGameDescription);
		}
				
		HOOK_DECL(SetModDir, 3, void, const char *pszModDir)
		{
			Util::Debug::PrintLine("SetModDir!");

			return SetModDirOriginal(This, pszModDir);
		}
				
		HOOK_DECL(SetDedicatedServer, 4, void, bool bDedicated)
		{
			Util::Debug::PrintLine("SetDedicatedServer!");

			return SetDedicatedServerOriginal(This, bDedicated);
		}
				
		HOOK_DECL(LogOn, 5, void, const char *pszToken)
		{
			Util::Debug::PrintLine("LogOn!");

			return LogOnOriginal(This, pszToken);
		}
				
		HOOK_DECL(LogOnAnonymous, 6, void)
		{
			Util::Debug::PrintLine("LogOnAnonymous!");

			return LogOnAnonymousOriginal(This);
		}
				
		HOOK_DECL(LogOff, 7, void)
		{
			Util::Debug::PrintLine("LogOff!");

			return LogOffOriginal(This);
		}
				
		HOOK_DECL(BLoggedOn, 8, bool)
		{
			Util::Debug::PrintLine("BLoggedOn!");

			return BLoggedOnOriginal(This);
		}
				
		HOOK_DECL(BSecure, 9, bool)
		{
			Util::Debug::PrintLine("BSecure!");

			return BSecureOriginal(This);
		}
				
		HOOK_DECL(GetSteamID, 10, CSteamID)
		{
			Util::Debug::PrintLine("GetSteamID!");

			return GetSteamIDOriginal(This);
		}
				
		HOOK_DECL(WasRestartRequested, 11, bool)
		{
			Util::Debug::PrintLine("WasRestartRequested!");

			return WasRestartRequestedOriginal(This);
		}
				
		HOOK_DECL(SetMaxPlayerCount, 12, void, int cPlayersMax)
		{
			Util::Debug::PrintLine("SetMaxPlayerCount!");

			return SetMaxPlayerCountOriginal(This, cPlayersMax);
		}
				
		HOOK_DECL(SetBotPlayerCount, 13, void, int cBotplayers)
		{
			Util::Debug::PrintLine("SetBotPlayerCount!");

			return SetBotPlayerCountOriginal(This, cBotplayers);
		}
				
		HOOK_DECL(SetServerName, 14, void, const char *pszServerName)
		{
			Util::Debug::PrintLine("SetServerName!");

			return SetServerNameOriginal(This, pszServerName);
		}
				
		HOOK_DECL(SetMapName, 15, void, const char *pszMapName)
		{
			Util::Debug::PrintLine("SetMapName!");

			return SetMapNameOriginal(This, pszMapName);
		}
				
		HOOK_DECL(SetPasswordProtected, 16, void, bool bPasswordProtected)
		{
			Util::Debug::PrintLine("SetPasswordProtected!");

			return SetPasswordProtectedOriginal(This, bPasswordProtected);
		}
				
		HOOK_DECL(SetSpectatorPort, 17, void, uint16 unSpectatorPort)
		{
			Util::Debug::PrintLine("SetSpectatorPort!");

			return SetSpectatorPortOriginal(This, unSpectatorPort);
		}
				
		HOOK_DECL(SetSpectatorServerName, 18, void, const char *pszSpectatorServerName)
		{
			Util::Debug::PrintLine("SetSpectatorServerName!");

			return SetSpectatorServerNameOriginal(This, pszSpectatorServerName);
		}
				
		HOOK_DECL(ClearAllKeyValues, 19, void)
		{
			Util::Debug::PrintLine("ClearAllKeyValues!");

			return ClearAllKeyValuesOriginal(This);
		}
				
		HOOK_DECL(SetKeyValue, 20, void, const char *pKey, const char *pValue)
		{
			Util::Debug::PrintLine("SetKeyValue!");

			return SetKeyValueOriginal(This, pKey, pValue);
		}
				
		HOOK_DECL(SetGameTags, 21, void, const char *pchGameTags)
		{
			Util::Debug::PrintLine("SetGameTags!");

			return SetGameTagsOriginal(This, pchGameTags);
		}
				
		HOOK_DECL(SetGameData, 22, void, const char *pchGameData)
		{
			Util::Debug::PrintLine("SetGameData!");

			return SetGameDataOriginal(This, pchGameData);
		}
				
		HOOK_DECL(SetRegion, 23, void, const char *pszRegion)
		{
			Util::Debug::PrintLine("SetRegion!");

			return SetRegionOriginal(This, pszRegion);
		}
				
		HOOK_DECL(SendUserConnectAndAuthenticate, 24, bool, uint32 unIPClient, const void *pvAuthBlob, uint32 cubAuthBlobSize, CSteamID *pSteamIDUser)
		{
			Util::Debug::PrintLine("SendUserConnectAndAuthenticate!");

			return SendUserConnectAndAuthenticateOriginal(This, unIPClient, pvAuthBlob, cubAuthBlobSize, pSteamIDUser);
		}
				
		HOOK_DECL(CreateUnauthenticatedUserConnection, 25, CSteamID)
		{
			Util::Debug::PrintLine("CreateUnauthenticatedUserConnection!");

			return CreateUnauthenticatedUserConnectionOriginal(This);
		}
				
		HOOK_DECL(SendUserDisconnect, 26, void, CSteamID steamIDUser)
		{
			Util::Debug::PrintLine("SendUserDisconnect!");

			return SendUserDisconnectOriginal(This, steamIDUser);
		}
				
		HOOK_DECL(BUpdateUserData, 27, bool, CSteamID steamIDUser, const char *pchPlayerName, uint32 uScore)
		{
			Util::Debug::PrintLine("BUpdateUserData!");

			return BUpdateUserDataOriginal(This, steamIDUser, pchPlayerName, uScore);
		}
				
		HOOK_DECL(GetAuthSessionTicket, 28, HAuthTicket, void *pTicket, int cbMaxTicket, uint32 *pcbTicket)
		{
			Util::Debug::PrintLine("GetAuthSessionTicket!");

			return GetAuthSessionTicketOriginal(This, pTicket, cbMaxTicket, pcbTicket);
		}
				
		HOOK_DECL(BeginAuthSession, 29, EBeginAuthSessionResult, const void *pAuthTicket, int cbAuthTicket, CSteamID steamID)
		{
			Util::Debug::PrintLine("BeginAuthSession!");

			return BeginAuthSessionOriginal(This, pAuthTicket, cbAuthTicket, steamID);
		}
				
		HOOK_DECL(EndAuthSession, 30, void, CSteamID steamID)
		{
			Util::Debug::PrintLine("EndAuthSession!");

			return EndAuthSessionOriginal(This, steamID);
		}
				
		HOOK_DECL(CancelAuthTicket, 31, void, HAuthTicket hAuthTicket)
		{
			Util::Debug::PrintLine("CancelAuthTicket!");

			return CancelAuthTicketOriginal(This, hAuthTicket);
		}
				
		HOOK_DECL(UserHasLicenseForApp, 32, EUserHasLicenseForAppResult, CSteamID steamID, AppId_t appID)
		{
			Util::Debug::PrintLine("UserHasLicenseForApp!");

			return UserHasLicenseForAppOriginal(This, steamID, appID);
		}
				
		HOOK_DECL(RequestUserGroupStatus, 33, bool, CSteamID steamIDUser, CSteamID steamIDGroup)
		{
			Util::Debug::PrintLine("RequestUserGroupStatus!");

			return RequestUserGroupStatusOriginal(This, steamIDUser, steamIDGroup);
		}
				
		HOOK_DECL(GetGameplayStats, 34, void)
		{
			Util::Debug::PrintLine("GetGameplayStats!");

			return GetGameplayStatsOriginal(This);
		}
				
		HOOK_DECL(GetServerReputation, 35, SteamAPICall_t)
		{
			Util::Debug::PrintLine("GetServerReputation!");

			return GetServerReputationOriginal(This);
		}
				
		HOOK_DECL(GetPublicIP, 36, uint32)
		{
			Util::Debug::PrintLine("GetPublicIP!");

			return GetPublicIPOriginal(This);
		}
				
		HOOK_DECL(HandleIncomingPacket, 37, bool, const void *pData, int cbData, uint32 srcIP, uint16 srcPort)
		{
			Util::Debug::PrintLine("HandleIncomingPacket!");

			return HandleIncomingPacketOriginal(This, pData, cbData, srcIP, srcPort);
		}
				
		HOOK_DECL(GetNextOutgoingPacket, 38, int, void *pOut, int cbMaxOut, uint32 *pNetAdr, uint16 *pPort)
		{
			Util::Debug::PrintLine("GetNextOutgoingPacket!");

			return GetNextOutgoingPacketOriginal(This, pOut, cbMaxOut, pNetAdr, pPort);
		}
				
		HOOK_DECL(EnableHeartbeats, 39, void, bool bActive)
		{
			Util::Debug::PrintLine("EnableHeartbeats!");

			return EnableHeartbeatsOriginal(This, bActive);
		}
				
		HOOK_DECL(SetHeartbeatInterval, 40, void, int iHeartbeatInterval)
		{
			Util::Debug::PrintLine("SetHeartbeatInterval!");

			return SetHeartbeatIntervalOriginal(This, iHeartbeatInterval);
		}
				
		HOOK_DECL(ForceHeartbeat, 41, void)
		{
			Util::Debug::PrintLine("ForceHeartbeat!");

			return ForceHeartbeatOriginal(This);
		}
				
		HOOK_DECL(AssociateWithClan, 42, SteamAPICall_t, CSteamID steamIDClan)
		{
			Util::Debug::PrintLine("AssociateWithClan!");

			return AssociateWithClanOriginal(This, steamIDClan);
		}
				
		HOOK_DECL(ComputeNewPlayerCompatibility, 43, SteamAPICall_t, CSteamID steamIDNewPlayer)
		{
			Util::Debug::PrintLine("ComputeNewPlayerCompatibility!");

			return ComputeNewPlayerCompatibilityOriginal(This, steamIDNewPlayer);
		}
		
	};
}