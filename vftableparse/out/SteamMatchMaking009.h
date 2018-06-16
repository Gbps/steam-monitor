#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamMatchmaking_Hooks : CHookManager<ISteamMatchmaking>
	{

	public:
		ISteamMatchmaking_Hooks() = delete;
		ISteamMatchmaking_Hooks(ISteamMatchmaking* obj) : CHookManager<ISteamMatchmaking>(obj) {};

        		
		HOOK_DECL(GetFavoriteGameCount, 0, int)
		{
			Util::Debug::PrintLine("GetFavoriteGameCount!");

			return GetFavoriteGameCountOriginal(This);
		}
				
		HOOK_DECL(GetFavoriteGame, 1, bool, int iGame, AppId_t *pnAppID, uint32 *pnIP, uint16 *pnConnPort, uint16 *pnQueryPort, uint32 *punFlags, uint32 *pRTime32LastPlayedOnServer)
		{
			Util::Debug::PrintLine("GetFavoriteGame!");

			return GetFavoriteGameOriginal(This, iGame, pnAppID, pnIP, pnConnPort, pnQueryPort, punFlags, pRTime32LastPlayedOnServer);
		}
				
		HOOK_DECL(AddFavoriteGame, 2, int, AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer)
		{
			Util::Debug::PrintLine("AddFavoriteGame!");

			return AddFavoriteGameOriginal(This, nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer);
		}
				
		HOOK_DECL(RemoveFavoriteGame, 3, bool, AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags)
		{
			Util::Debug::PrintLine("RemoveFavoriteGame!");

			return RemoveFavoriteGameOriginal(This, nAppID, nIP, nConnPort, nQueryPort, unFlags);
		}
				
		HOOK_DECL(RequestLobbyList, 4, SteamAPICall_t)
		{
			Util::Debug::PrintLine("RequestLobbyList!");

			return RequestLobbyListOriginal(This);
		}
				
		HOOK_DECL(AddRequestLobbyListStringFilter, 5, void, const char *pchKeyToMatch, const char *pchValueToMatch, ELobbyComparison eComparisonType)
		{
			Util::Debug::PrintLine("AddRequestLobbyListStringFilter!");

			return AddRequestLobbyListStringFilterOriginal(This, pchKeyToMatch, pchValueToMatch, eComparisonType);
		}
				
		HOOK_DECL(AddRequestLobbyListNumericalFilter, 6, void, const char *pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType)
		{
			Util::Debug::PrintLine("AddRequestLobbyListNumericalFilter!");

			return AddRequestLobbyListNumericalFilterOriginal(This, pchKeyToMatch, nValueToMatch, eComparisonType);
		}
				
		HOOK_DECL(AddRequestLobbyListNearValueFilter, 7, void, const char *pchKeyToMatch, int nValueToBeCloseTo)
		{
			Util::Debug::PrintLine("AddRequestLobbyListNearValueFilter!");

			return AddRequestLobbyListNearValueFilterOriginal(This, pchKeyToMatch, nValueToBeCloseTo);
		}
				
		HOOK_DECL(AddRequestLobbyListFilterSlotsAvailable, 8, void, int nSlotsAvailable)
		{
			Util::Debug::PrintLine("AddRequestLobbyListFilterSlotsAvailable!");

			return AddRequestLobbyListFilterSlotsAvailableOriginal(This, nSlotsAvailable);
		}
				
		HOOK_DECL(AddRequestLobbyListDistanceFilter, 9, void, ELobbyDistanceFilter eLobbyDistanceFilter)
		{
			Util::Debug::PrintLine("AddRequestLobbyListDistanceFilter!");

			return AddRequestLobbyListDistanceFilterOriginal(This, eLobbyDistanceFilter);
		}
				
		HOOK_DECL(AddRequestLobbyListResultCountFilter, 10, void, int cMaxResults)
		{
			Util::Debug::PrintLine("AddRequestLobbyListResultCountFilter!");

			return AddRequestLobbyListResultCountFilterOriginal(This, cMaxResults);
		}
				
		HOOK_DECL(AddRequestLobbyListCompatibleMembersFilter, 11, void, CSteamID steamIDLobby)
		{
			Util::Debug::PrintLine("AddRequestLobbyListCompatibleMembersFilter!");

			return AddRequestLobbyListCompatibleMembersFilterOriginal(This, steamIDLobby);
		}
				
		HOOK_DECL(GetLobbyByIndex, 12, CSteamID, int iLobby)
		{
			Util::Debug::PrintLine("GetLobbyByIndex!");

			return GetLobbyByIndexOriginal(This, iLobby);
		}
				
		HOOK_DECL(CreateLobby, 13, SteamAPICall_t, ELobbyType eLobbyType, int cMaxMembers)
		{
			Util::Debug::PrintLine("CreateLobby!");

			return CreateLobbyOriginal(This, eLobbyType, cMaxMembers);
		}
				
		HOOK_DECL(JoinLobby, 14, SteamAPICall_t, CSteamID steamIDLobby)
		{
			Util::Debug::PrintLine("JoinLobby!");

			return JoinLobbyOriginal(This, steamIDLobby);
		}
				
		HOOK_DECL(LeaveLobby, 15, void, CSteamID steamIDLobby)
		{
			Util::Debug::PrintLine("LeaveLobby!");

			return LeaveLobbyOriginal(This, steamIDLobby);
		}
				
		HOOK_DECL(InviteUserToLobby, 16, bool, CSteamID steamIDLobby, CSteamID steamIDInvitee)
		{
			Util::Debug::PrintLine("InviteUserToLobby!");

			return InviteUserToLobbyOriginal(This, steamIDLobby, steamIDInvitee);
		}
				
		HOOK_DECL(GetNumLobbyMembers, 17, int, CSteamID steamIDLobby)
		{
			Util::Debug::PrintLine("GetNumLobbyMembers!");

			return GetNumLobbyMembersOriginal(This, steamIDLobby);
		}
				
		HOOK_DECL(GetLobbyMemberByIndex, 18, CSteamID, CSteamID steamIDLobby, int iMember)
		{
			Util::Debug::PrintLine("GetLobbyMemberByIndex!");

			return GetLobbyMemberByIndexOriginal(This, steamIDLobby, iMember);
		}
				
		HOOK_DECL(GetLobbyData, 19, const char *, CSteamID steamIDLobby, const char *pchKey)
		{
			Util::Debug::PrintLine("GetLobbyData!");

			return GetLobbyDataOriginal(This, steamIDLobby, pchKey);
		}
				
		HOOK_DECL(SetLobbyData, 20, bool, CSteamID steamIDLobby, const char *pchKey, const char *pchValue)
		{
			Util::Debug::PrintLine("SetLobbyData!");

			return SetLobbyDataOriginal(This, steamIDLobby, pchKey, pchValue);
		}
				
		HOOK_DECL(GetLobbyDataCount, 21, int, CSteamID steamIDLobby)
		{
			Util::Debug::PrintLine("GetLobbyDataCount!");

			return GetLobbyDataCountOriginal(This, steamIDLobby);
		}
				
		HOOK_DECL(GetLobbyDataByIndex, 22, bool, CSteamID steamIDLobby, int iLobbyData, char *pchKey, int cchKeyBufferSize, char *pchValue, int cchValueBufferSize)
		{
			Util::Debug::PrintLine("GetLobbyDataByIndex!");

			return GetLobbyDataByIndexOriginal(This, steamIDLobby, iLobbyData, pchKey, cchKeyBufferSize, pchValue, cchValueBufferSize);
		}
				
		HOOK_DECL(DeleteLobbyData, 23, bool, CSteamID steamIDLobby, const char *pchKey)
		{
			Util::Debug::PrintLine("DeleteLobbyData!");

			return DeleteLobbyDataOriginal(This, steamIDLobby, pchKey);
		}
				
		HOOK_DECL(GetLobbyMemberData, 24, const char *, CSteamID steamIDLobby, CSteamID steamIDUser, const char *pchKey)
		{
			Util::Debug::PrintLine("GetLobbyMemberData!");

			return GetLobbyMemberDataOriginal(This, steamIDLobby, steamIDUser, pchKey);
		}
				
		HOOK_DECL(SetLobbyMemberData, 25, void, CSteamID steamIDLobby, const char *pchKey, const char *pchValue)
		{
			Util::Debug::PrintLine("SetLobbyMemberData!");

			return SetLobbyMemberDataOriginal(This, steamIDLobby, pchKey, pchValue);
		}
				
		HOOK_DECL(SendLobbyChatMsg, 26, bool, CSteamID steamIDLobby, const void *pvMsgBody, int cubMsgBody)
		{
			Util::Debug::PrintLine("SendLobbyChatMsg!");

			return SendLobbyChatMsgOriginal(This, steamIDLobby, pvMsgBody, cubMsgBody);
		}
				
		HOOK_DECL(GetLobbyChatEntry, 27, int, CSteamID steamIDLobby, int iChatID,  CSteamID *pSteamIDUser, void *pvData, int cubData, EChatEntryType *peChatEntryType)
		{
			Util::Debug::PrintLine("GetLobbyChatEntry!");

			return GetLobbyChatEntryOriginal(This, steamIDLobby, iChatID, pSteamIDUser, pvData, cubData, peChatEntryType);
		}
				
		HOOK_DECL(RequestLobbyData, 28, bool, CSteamID steamIDLobby)
		{
			Util::Debug::PrintLine("RequestLobbyData!");

			return RequestLobbyDataOriginal(This, steamIDLobby);
		}
				
		HOOK_DECL(SetLobbyGameServer, 29, void, CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer)
		{
			Util::Debug::PrintLine("SetLobbyGameServer!");

			return SetLobbyGameServerOriginal(This, steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer);
		}
				
		HOOK_DECL(GetLobbyGameServer, 30, bool, CSteamID steamIDLobby, uint32 *punGameServerIP, uint16 *punGameServerPort,  CSteamID *psteamIDGameServer)
		{
			Util::Debug::PrintLine("GetLobbyGameServer!");

			return GetLobbyGameServerOriginal(This, steamIDLobby, punGameServerIP, punGameServerPort, psteamIDGameServer);
		}
				
		HOOK_DECL(SetLobbyMemberLimit, 31, bool, CSteamID steamIDLobby, int cMaxMembers)
		{
			Util::Debug::PrintLine("SetLobbyMemberLimit!");

			return SetLobbyMemberLimitOriginal(This, steamIDLobby, cMaxMembers);
		}
				
		HOOK_DECL(GetLobbyMemberLimit, 32, int, CSteamID steamIDLobby)
		{
			Util::Debug::PrintLine("GetLobbyMemberLimit!");

			return GetLobbyMemberLimitOriginal(This, steamIDLobby);
		}
				
		HOOK_DECL(SetLobbyType, 33, bool, CSteamID steamIDLobby, ELobbyType eLobbyType)
		{
			Util::Debug::PrintLine("SetLobbyType!");

			return SetLobbyTypeOriginal(This, steamIDLobby, eLobbyType);
		}
				
		HOOK_DECL(SetLobbyJoinable, 34, bool, CSteamID steamIDLobby, bool bLobbyJoinable)
		{
			Util::Debug::PrintLine("SetLobbyJoinable!");

			return SetLobbyJoinableOriginal(This, steamIDLobby, bLobbyJoinable);
		}
				
		HOOK_DECL(GetLobbyOwner, 35, CSteamID, CSteamID steamIDLobby)
		{
			Util::Debug::PrintLine("GetLobbyOwner!");

			return GetLobbyOwnerOriginal(This, steamIDLobby);
		}
				
		HOOK_DECL(SetLobbyOwner, 36, bool, CSteamID steamIDLobby, CSteamID steamIDNewOwner)
		{
			Util::Debug::PrintLine("SetLobbyOwner!");

			return SetLobbyOwnerOriginal(This, steamIDLobby, steamIDNewOwner);
		}
				
		HOOK_DECL(SetLinkedLobby, 37, bool, CSteamID steamIDLobby, CSteamID steamIDLobbyDependent)
		{
			Util::Debug::PrintLine("SetLinkedLobby!");

			return SetLinkedLobbyOriginal(This, steamIDLobby, steamIDLobbyDependent);
		}
				
		HOOK_DECL(CheckForPSNGameBootInvite, 38, void, unsigned int iGameBootAttributes)
		{
			Util::Debug::PrintLine("CheckForPSNGameBootInvite!");

			return CheckForPSNGameBootInviteOriginal(This, iGameBootAttributes);
		}
				
		HOOK_DECL(ServerResponded, 39, void, HServerListRequest hRequest, int iServer)
		{
			Util::Debug::PrintLine("ServerResponded!");

			return ServerRespondedOriginal(This, hRequest, iServer);
		}
				
		HOOK_DECL(ServerFailedToRespond, 40, void, HServerListRequest hRequest, int iServer)
		{
			Util::Debug::PrintLine("ServerFailedToRespond!");

			return ServerFailedToRespondOriginal(This, hRequest, iServer);
		}
				
		HOOK_DECL(RefreshComplete, 41, void, HServerListRequest hRequest, EMatchMakingServerResponse response)
		{
			Util::Debug::PrintLine("RefreshComplete!");

			return RefreshCompleteOriginal(This, hRequest, response);
		}
				
		HOOK_DECL(ServerResponded, 42, void, gameserveritem_t &server)
		{
			Util::Debug::PrintLine("ServerResponded!");

			return ServerRespondedOriginal(This, &server);
		}
				
		HOOK_DECL(ServerFailedToRespond, 43, void)
		{
			Util::Debug::PrintLine("ServerFailedToRespond!");

			return ServerFailedToRespondOriginal(This);
		}
				
		HOOK_DECL(AddPlayerToList, 44, void, const char *pchName, int nScore, float flTimePlayed)
		{
			Util::Debug::PrintLine("AddPlayerToList!");

			return AddPlayerToListOriginal(This, pchName, nScore, flTimePlayed);
		}
				
		HOOK_DECL(PlayersFailedToRespond, 45, void)
		{
			Util::Debug::PrintLine("PlayersFailedToRespond!");

			return PlayersFailedToRespondOriginal(This);
		}
				
		HOOK_DECL(PlayersRefreshComplete, 46, void)
		{
			Util::Debug::PrintLine("PlayersRefreshComplete!");

			return PlayersRefreshCompleteOriginal(This);
		}
				
		HOOK_DECL(RulesResponded, 47, void, const char *pchRule, const char *pchValue)
		{
			Util::Debug::PrintLine("RulesResponded!");

			return RulesRespondedOriginal(This, pchRule, pchValue);
		}
				
		HOOK_DECL(RulesFailedToRespond, 48, void)
		{
			Util::Debug::PrintLine("RulesFailedToRespond!");

			return RulesFailedToRespondOriginal(This);
		}
				
		HOOK_DECL(RulesRefreshComplete, 49, void)
		{
			Util::Debug::PrintLine("RulesRefreshComplete!");

			return RulesRefreshCompleteOriginal(This);
		}
				
		HOOK_DECL(RequestInternetServerList, 50, HServerListRequest, AppId_t iApp,  MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse)
		{
			Util::Debug::PrintLine("RequestInternetServerList!");

			return RequestInternetServerListOriginal(This, iApp, *ppchFilters, nFilters, pRequestServersResponse);
		}
				
		HOOK_DECL(RequestLANServerList, 51, HServerListRequest, AppId_t iApp, ISteamMatchmakingServerListResponse *pRequestServersResponse)
		{
			Util::Debug::PrintLine("RequestLANServerList!");

			return RequestLANServerListOriginal(This, iApp, pRequestServersResponse);
		}
				
		HOOK_DECL(RequestFriendsServerList, 52, HServerListRequest, AppId_t iApp,  MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse)
		{
			Util::Debug::PrintLine("RequestFriendsServerList!");

			return RequestFriendsServerListOriginal(This, iApp, *ppchFilters, nFilters, pRequestServersResponse);
		}
				
		HOOK_DECL(RequestFavoritesServerList, 53, HServerListRequest, AppId_t iApp,  MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse)
		{
			Util::Debug::PrintLine("RequestFavoritesServerList!");

			return RequestFavoritesServerListOriginal(This, iApp, *ppchFilters, nFilters, pRequestServersResponse);
		}
				
		HOOK_DECL(RequestHistoryServerList, 54, HServerListRequest, AppId_t iApp,  MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse)
		{
			Util::Debug::PrintLine("RequestHistoryServerList!");

			return RequestHistoryServerListOriginal(This, iApp, *ppchFilters, nFilters, pRequestServersResponse);
		}
				
		HOOK_DECL(RequestSpectatorServerList, 55, HServerListRequest, AppId_t iApp,  MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse)
		{
			Util::Debug::PrintLine("RequestSpectatorServerList!");

			return RequestSpectatorServerListOriginal(This, iApp, *ppchFilters, nFilters, pRequestServersResponse);
		}
				
		HOOK_DECL(ReleaseRequest, 56, void, HServerListRequest hServerListRequest)
		{
			Util::Debug::PrintLine("ReleaseRequest!");

			return ReleaseRequestOriginal(This, hServerListRequest);
		}
				
		HOOK_DECL(GetServerDetails, 57, gameserveritem_t *, HServerListRequest hRequest, int iServer)
		{
			Util::Debug::PrintLine("GetServerDetails!");

			return GetServerDetailsOriginal(This, hRequest, iServer);
		}
				
		HOOK_DECL(CancelQuery, 58, void, HServerListRequest hRequest)
		{
			Util::Debug::PrintLine("CancelQuery!");

			return CancelQueryOriginal(This, hRequest);
		}
				
		HOOK_DECL(RefreshQuery, 59, void, HServerListRequest hRequest)
		{
			Util::Debug::PrintLine("RefreshQuery!");

			return RefreshQueryOriginal(This, hRequest);
		}
				
		HOOK_DECL(IsRefreshing, 60, bool, HServerListRequest hRequest)
		{
			Util::Debug::PrintLine("IsRefreshing!");

			return IsRefreshingOriginal(This, hRequest);
		}
				
		HOOK_DECL(GetServerCount, 61, int, HServerListRequest hRequest)
		{
			Util::Debug::PrintLine("GetServerCount!");

			return GetServerCountOriginal(This, hRequest);
		}
				
		HOOK_DECL(RefreshServer, 62, void, HServerListRequest hRequest, int iServer)
		{
			Util::Debug::PrintLine("RefreshServer!");

			return RefreshServerOriginal(This, hRequest, iServer);
		}
				
		HOOK_DECL(PingServer, 63, HServerQuery, uint32 unIP, uint16 usPort, ISteamMatchmakingPingResponse *pRequestServersResponse)
		{
			Util::Debug::PrintLine("PingServer!");

			return PingServerOriginal(This, unIP, usPort, pRequestServersResponse);
		}
				
		HOOK_DECL(PlayerDetails, 64, HServerQuery, uint32 unIP, uint16 usPort, ISteamMatchmakingPlayersResponse *pRequestServersResponse)
		{
			Util::Debug::PrintLine("PlayerDetails!");

			return PlayerDetailsOriginal(This, unIP, usPort, pRequestServersResponse);
		}
				
		HOOK_DECL(ServerRules, 65, HServerQuery, uint32 unIP, uint16 usPort, ISteamMatchmakingRulesResponse *pRequestServersResponse)
		{
			Util::Debug::PrintLine("ServerRules!");

			return ServerRulesOriginal(This, unIP, usPort, pRequestServersResponse);
		}
				
		HOOK_DECL(CancelServerQuery, 66, void, HServerQuery hServerQuery)
		{
			Util::Debug::PrintLine("CancelServerQuery!");

			return CancelServerQueryOriginal(This, hServerQuery);
		}
		
	};
}