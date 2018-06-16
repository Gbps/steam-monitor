#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamFriends_Hooks : CHookManager<ISteamFriends>
	{

	public:
		ISteamFriends_Hooks() = delete;
		ISteamFriends_Hooks(ISteamFriends* obj) : CHookManager<ISteamFriends>(obj) {};

        		
		HOOK_DECL(GetPersonaName, 0, const char *)
		{
			Util::Debug::PrintLine("GetPersonaName!");

			return GetPersonaNameOriginal(This);
		}
				
		HOOK_DECL(SetPersonaName, 1, SteamAPICall_t, const char *pchPersonaName)
		{
			Util::Debug::PrintLine("SetPersonaName!");

			return SetPersonaNameOriginal(This, pchPersonaName);
		}
				
		HOOK_DECL(GetPersonaState, 2, EPersonaState)
		{
			Util::Debug::PrintLine("GetPersonaState!");

			return GetPersonaStateOriginal(This);
		}
				
		HOOK_DECL(GetFriendCount, 3, int, int iFriendFlags)
		{
			Util::Debug::PrintLine("GetFriendCount!");

			return GetFriendCountOriginal(This, iFriendFlags);
		}
				
		HOOK_DECL(GetFriendByIndex, 4, CSteamID, int iFriend, int iFriendFlags)
		{
			Util::Debug::PrintLine("GetFriendByIndex!");

			return GetFriendByIndexOriginal(This, iFriend, iFriendFlags);
		}
				
		HOOK_DECL(GetFriendRelationship, 5, EFriendRelationship, CSteamID steamIDFriend)
		{
			Util::Debug::PrintLine("GetFriendRelationship!");

			return GetFriendRelationshipOriginal(This, steamIDFriend);
		}
				
		HOOK_DECL(GetFriendPersonaState, 6, EPersonaState, CSteamID steamIDFriend)
		{
			Util::Debug::PrintLine("GetFriendPersonaState!");

			return GetFriendPersonaStateOriginal(This, steamIDFriend);
		}
				
		HOOK_DECL(GetFriendPersonaName, 7, const char *, CSteamID steamIDFriend)
		{
			Util::Debug::PrintLine("GetFriendPersonaName!");

			return GetFriendPersonaNameOriginal(This, steamIDFriend);
		}
				
		HOOK_DECL(GetFriendGamePlayed, 8, bool, CSteamID steamIDFriend,  FriendGameInfo_t *pFriendGameInfo)
		{
			Util::Debug::PrintLine("GetFriendGamePlayed!");

			return GetFriendGamePlayedOriginal(This, steamIDFriend, pFriendGameInfo);
		}
				
		HOOK_DECL(GetFriendPersonaNameHistory, 9, const char *, CSteamID steamIDFriend, int iPersonaName)
		{
			Util::Debug::PrintLine("GetFriendPersonaNameHistory!");

			return GetFriendPersonaNameHistoryOriginal(This, steamIDFriend, iPersonaName);
		}
				
		HOOK_DECL(GetFriendSteamLevel, 10, int, CSteamID steamIDFriend)
		{
			Util::Debug::PrintLine("GetFriendSteamLevel!");

			return GetFriendSteamLevelOriginal(This, steamIDFriend);
		}
				
		HOOK_DECL(GetPlayerNickname, 11, const char *, CSteamID steamIDPlayer)
		{
			Util::Debug::PrintLine("GetPlayerNickname!");

			return GetPlayerNicknameOriginal(This, steamIDPlayer);
		}
				
		HOOK_DECL(GetFriendsGroupCount, 12, int)
		{
			Util::Debug::PrintLine("GetFriendsGroupCount!");

			return GetFriendsGroupCountOriginal(This);
		}
				
		HOOK_DECL(GetFriendsGroupIDByIndex, 13, FriendsGroupID_t, int iFG)
		{
			Util::Debug::PrintLine("GetFriendsGroupIDByIndex!");

			return GetFriendsGroupIDByIndexOriginal(This, iFG);
		}
				
		HOOK_DECL(GetFriendsGroupName, 14, const char *, FriendsGroupID_t friendsGroupID)
		{
			Util::Debug::PrintLine("GetFriendsGroupName!");

			return GetFriendsGroupNameOriginal(This, friendsGroupID);
		}
				
		HOOK_DECL(GetFriendsGroupMembersCount, 15, int, FriendsGroupID_t friendsGroupID)
		{
			Util::Debug::PrintLine("GetFriendsGroupMembersCount!");

			return GetFriendsGroupMembersCountOriginal(This, friendsGroupID);
		}
				
		HOOK_DECL(GetFriendsGroupMembersList, 16, void, FriendsGroupID_t friendsGroupID,  CSteamID *pOutSteamIDMembers, int nMembersCount)
		{
			Util::Debug::PrintLine("GetFriendsGroupMembersList!");

			return GetFriendsGroupMembersListOriginal(This, friendsGroupID, pOutSteamIDMembers, nMembersCount);
		}
				
		HOOK_DECL(HasFriend, 17, bool, CSteamID steamIDFriend, int iFriendFlags)
		{
			Util::Debug::PrintLine("HasFriend!");

			return HasFriendOriginal(This, steamIDFriend, iFriendFlags);
		}
				
		HOOK_DECL(GetClanCount, 18, int)
		{
			Util::Debug::PrintLine("GetClanCount!");

			return GetClanCountOriginal(This);
		}
				
		HOOK_DECL(GetClanByIndex, 19, CSteamID, int iClan)
		{
			Util::Debug::PrintLine("GetClanByIndex!");

			return GetClanByIndexOriginal(This, iClan);
		}
				
		HOOK_DECL(GetClanName, 20, const char *, CSteamID steamIDClan)
		{
			Util::Debug::PrintLine("GetClanName!");

			return GetClanNameOriginal(This, steamIDClan);
		}
				
		HOOK_DECL(GetClanTag, 21, const char *, CSteamID steamIDClan)
		{
			Util::Debug::PrintLine("GetClanTag!");

			return GetClanTagOriginal(This, steamIDClan);
		}
				
		HOOK_DECL(GetClanActivityCounts, 22, bool, CSteamID steamIDClan, int *pnOnline, int *pnInGame, int *pnChatting)
		{
			Util::Debug::PrintLine("GetClanActivityCounts!");

			return GetClanActivityCountsOriginal(This, steamIDClan, pnOnline, pnInGame, pnChatting);
		}
				
		HOOK_DECL(DownloadClanActivityCounts, 23, SteamAPICall_t, CSteamID *psteamIDClans, int cClansToRequest)
		{
			Util::Debug::PrintLine("DownloadClanActivityCounts!");

			return DownloadClanActivityCountsOriginal(This, psteamIDClans, cClansToRequest);
		}
				
		HOOK_DECL(GetFriendCountFromSource, 24, int, CSteamID steamIDSource)
		{
			Util::Debug::PrintLine("GetFriendCountFromSource!");

			return GetFriendCountFromSourceOriginal(This, steamIDSource);
		}
				
		HOOK_DECL(GetFriendFromSourceByIndex, 25, CSteamID, CSteamID steamIDSource, int iFriend)
		{
			Util::Debug::PrintLine("GetFriendFromSourceByIndex!");

			return GetFriendFromSourceByIndexOriginal(This, steamIDSource, iFriend);
		}
				
		HOOK_DECL(IsUserInSource, 26, bool, CSteamID steamIDUser, CSteamID steamIDSource)
		{
			Util::Debug::PrintLine("IsUserInSource!");

			return IsUserInSourceOriginal(This, steamIDUser, steamIDSource);
		}
				
		HOOK_DECL(SetInGameVoiceSpeaking, 27, void, CSteamID steamIDUser, bool bSpeaking)
		{
			Util::Debug::PrintLine("SetInGameVoiceSpeaking!");

			return SetInGameVoiceSpeakingOriginal(This, steamIDUser, bSpeaking);
		}
				
		HOOK_DECL(ActivateGameOverlay, 28, void, const char *pchDialog)
		{
			Util::Debug::PrintLine("ActivateGameOverlay!");

			return ActivateGameOverlayOriginal(This, pchDialog);
		}
				
		HOOK_DECL(ActivateGameOverlayToUser, 29, void, const char *pchDialog, CSteamID steamID)
		{
			Util::Debug::PrintLine("ActivateGameOverlayToUser!");

			return ActivateGameOverlayToUserOriginal(This, pchDialog, steamID);
		}
				
		HOOK_DECL(ActivateGameOverlayToWebPage, 30, void, const char *pchURL)
		{
			Util::Debug::PrintLine("ActivateGameOverlayToWebPage!");

			return ActivateGameOverlayToWebPageOriginal(This, pchURL);
		}
				
		HOOK_DECL(ActivateGameOverlayToStore, 31, void, AppId_t nAppID, EOverlayToStoreFlag eFlag)
		{
			Util::Debug::PrintLine("ActivateGameOverlayToStore!");

			return ActivateGameOverlayToStoreOriginal(This, nAppID, eFlag);
		}
				
		HOOK_DECL(SetPlayedWith, 32, void, CSteamID steamIDUserPlayedWith)
		{
			Util::Debug::PrintLine("SetPlayedWith!");

			return SetPlayedWithOriginal(This, steamIDUserPlayedWith);
		}
				
		HOOK_DECL(ActivateGameOverlayInviteDialog, 33, void, CSteamID steamIDLobby)
		{
			Util::Debug::PrintLine("ActivateGameOverlayInviteDialog!");

			return ActivateGameOverlayInviteDialogOriginal(This, steamIDLobby);
		}
				
		HOOK_DECL(GetSmallFriendAvatar, 34, int, CSteamID steamIDFriend)
		{
			Util::Debug::PrintLine("GetSmallFriendAvatar!");

			return GetSmallFriendAvatarOriginal(This, steamIDFriend);
		}
				
		HOOK_DECL(GetMediumFriendAvatar, 35, int, CSteamID steamIDFriend)
		{
			Util::Debug::PrintLine("GetMediumFriendAvatar!");

			return GetMediumFriendAvatarOriginal(This, steamIDFriend);
		}
				
		HOOK_DECL(GetLargeFriendAvatar, 36, int, CSteamID steamIDFriend)
		{
			Util::Debug::PrintLine("GetLargeFriendAvatar!");

			return GetLargeFriendAvatarOriginal(This, steamIDFriend);
		}
				
		HOOK_DECL(RequestUserInformation, 37, bool, CSteamID steamIDUser, bool bRequireNameOnly)
		{
			Util::Debug::PrintLine("RequestUserInformation!");

			return RequestUserInformationOriginal(This, steamIDUser, bRequireNameOnly);
		}
				
		HOOK_DECL(RequestClanOfficerList, 38, SteamAPICall_t, CSteamID steamIDClan)
		{
			Util::Debug::PrintLine("RequestClanOfficerList!");

			return RequestClanOfficerListOriginal(This, steamIDClan);
		}
				
		HOOK_DECL(GetClanOwner, 39, CSteamID, CSteamID steamIDClan)
		{
			Util::Debug::PrintLine("GetClanOwner!");

			return GetClanOwnerOriginal(This, steamIDClan);
		}
				
		HOOK_DECL(GetClanOfficerCount, 40, int, CSteamID steamIDClan)
		{
			Util::Debug::PrintLine("GetClanOfficerCount!");

			return GetClanOfficerCountOriginal(This, steamIDClan);
		}
				
		HOOK_DECL(GetClanOfficerByIndex, 41, CSteamID, CSteamID steamIDClan, int iOfficer)
		{
			Util::Debug::PrintLine("GetClanOfficerByIndex!");

			return GetClanOfficerByIndexOriginal(This, steamIDClan, iOfficer);
		}
				
		HOOK_DECL(GetUserRestrictions, 42, uint32)
		{
			Util::Debug::PrintLine("GetUserRestrictions!");

			return GetUserRestrictionsOriginal(This);
		}
				
		HOOK_DECL(SetRichPresence, 43, bool, const char *pchKey, const char *pchValue)
		{
			Util::Debug::PrintLine("SetRichPresence!");

			return SetRichPresenceOriginal(This, pchKey, pchValue);
		}
				
		HOOK_DECL(ClearRichPresence, 44, void)
		{
			Util::Debug::PrintLine("ClearRichPresence!");

			return ClearRichPresenceOriginal(This);
		}
				
		HOOK_DECL(GetFriendRichPresence, 45, const char *, CSteamID steamIDFriend, const char *pchKey)
		{
			Util::Debug::PrintLine("GetFriendRichPresence!");

			return GetFriendRichPresenceOriginal(This, steamIDFriend, pchKey);
		}
				
		HOOK_DECL(GetFriendRichPresenceKeyCount, 46, int, CSteamID steamIDFriend)
		{
			Util::Debug::PrintLine("GetFriendRichPresenceKeyCount!");

			return GetFriendRichPresenceKeyCountOriginal(This, steamIDFriend);
		}
				
		HOOK_DECL(GetFriendRichPresenceKeyByIndex, 47, const char *, CSteamID steamIDFriend, int iKey)
		{
			Util::Debug::PrintLine("GetFriendRichPresenceKeyByIndex!");

			return GetFriendRichPresenceKeyByIndexOriginal(This, steamIDFriend, iKey);
		}
				
		HOOK_DECL(RequestFriendRichPresence, 48, void, CSteamID steamIDFriend)
		{
			Util::Debug::PrintLine("RequestFriendRichPresence!");

			return RequestFriendRichPresenceOriginal(This, steamIDFriend);
		}
				
		HOOK_DECL(InviteUserToGame, 49, bool, CSteamID steamIDFriend, const char *pchConnectString)
		{
			Util::Debug::PrintLine("InviteUserToGame!");

			return InviteUserToGameOriginal(This, steamIDFriend, pchConnectString);
		}
				
		HOOK_DECL(GetCoplayFriendCount, 50, int)
		{
			Util::Debug::PrintLine("GetCoplayFriendCount!");

			return GetCoplayFriendCountOriginal(This);
		}
				
		HOOK_DECL(GetCoplayFriend, 51, CSteamID, int iCoplayFriend)
		{
			Util::Debug::PrintLine("GetCoplayFriend!");

			return GetCoplayFriendOriginal(This, iCoplayFriend);
		}
				
		HOOK_DECL(GetFriendCoplayTime, 52, int, CSteamID steamIDFriend)
		{
			Util::Debug::PrintLine("GetFriendCoplayTime!");

			return GetFriendCoplayTimeOriginal(This, steamIDFriend);
		}
				
		HOOK_DECL(GetFriendCoplayGame, 53, AppId_t, CSteamID steamIDFriend)
		{
			Util::Debug::PrintLine("GetFriendCoplayGame!");

			return GetFriendCoplayGameOriginal(This, steamIDFriend);
		}
				
		HOOK_DECL(JoinClanChatRoom, 54, SteamAPICall_t, CSteamID steamIDClan)
		{
			Util::Debug::PrintLine("JoinClanChatRoom!");

			return JoinClanChatRoomOriginal(This, steamIDClan);
		}
				
		HOOK_DECL(LeaveClanChatRoom, 55, bool, CSteamID steamIDClan)
		{
			Util::Debug::PrintLine("LeaveClanChatRoom!");

			return LeaveClanChatRoomOriginal(This, steamIDClan);
		}
				
		HOOK_DECL(GetClanChatMemberCount, 56, int, CSteamID steamIDClan)
		{
			Util::Debug::PrintLine("GetClanChatMemberCount!");

			return GetClanChatMemberCountOriginal(This, steamIDClan);
		}
				
		HOOK_DECL(GetChatMemberByIndex, 57, CSteamID, CSteamID steamIDClan, int iUser)
		{
			Util::Debug::PrintLine("GetChatMemberByIndex!");

			return GetChatMemberByIndexOriginal(This, steamIDClan, iUser);
		}
				
		HOOK_DECL(SendClanChatMessage, 58, bool, CSteamID steamIDClanChat, const char *pchText)
		{
			Util::Debug::PrintLine("SendClanChatMessage!");

			return SendClanChatMessageOriginal(This, steamIDClanChat, pchText);
		}
				
		HOOK_DECL(GetClanChatMessage, 59, int, CSteamID steamIDClanChat, int iMessage, void *prgchText, int cchTextMax, EChatEntryType *peChatEntryType,  CSteamID *psteamidChatter)
		{
			Util::Debug::PrintLine("GetClanChatMessage!");

			return GetClanChatMessageOriginal(This, steamIDClanChat, iMessage, prgchText, cchTextMax, peChatEntryType, psteamidChatter);
		}
				
		HOOK_DECL(IsClanChatAdmin, 60, bool, CSteamID steamIDClanChat, CSteamID steamIDUser)
		{
			Util::Debug::PrintLine("IsClanChatAdmin!");

			return IsClanChatAdminOriginal(This, steamIDClanChat, steamIDUser);
		}
				
		HOOK_DECL(IsClanChatWindowOpenInSteam, 61, bool, CSteamID steamIDClanChat)
		{
			Util::Debug::PrintLine("IsClanChatWindowOpenInSteam!");

			return IsClanChatWindowOpenInSteamOriginal(This, steamIDClanChat);
		}
				
		HOOK_DECL(OpenClanChatWindowInSteam, 62, bool, CSteamID steamIDClanChat)
		{
			Util::Debug::PrintLine("OpenClanChatWindowInSteam!");

			return OpenClanChatWindowInSteamOriginal(This, steamIDClanChat);
		}
				
		HOOK_DECL(CloseClanChatWindowInSteam, 63, bool, CSteamID steamIDClanChat)
		{
			Util::Debug::PrintLine("CloseClanChatWindowInSteam!");

			return CloseClanChatWindowInSteamOriginal(This, steamIDClanChat);
		}
				
		HOOK_DECL(SetListenForFriendsMessages, 64, bool, bool bInterceptEnabled)
		{
			Util::Debug::PrintLine("SetListenForFriendsMessages!");

			return SetListenForFriendsMessagesOriginal(This, bInterceptEnabled);
		}
				
		HOOK_DECL(ReplyToFriendMessage, 65, bool, CSteamID steamIDFriend, const char *pchMsgToSend)
		{
			Util::Debug::PrintLine("ReplyToFriendMessage!");

			return ReplyToFriendMessageOriginal(This, steamIDFriend, pchMsgToSend);
		}
				
		HOOK_DECL(GetFriendMessage, 66, int, CSteamID steamIDFriend, int iMessageID, void *pvData, int cubData, EChatEntryType *peChatEntryType)
		{
			Util::Debug::PrintLine("GetFriendMessage!");

			return GetFriendMessageOriginal(This, steamIDFriend, iMessageID, pvData, cubData, peChatEntryType);
		}
				
		HOOK_DECL(GetFollowerCount, 67, SteamAPICall_t, CSteamID steamID)
		{
			Util::Debug::PrintLine("GetFollowerCount!");

			return GetFollowerCountOriginal(This, steamID);
		}
				
		HOOK_DECL(IsFollowing, 68, SteamAPICall_t, CSteamID steamID)
		{
			Util::Debug::PrintLine("IsFollowing!");

			return IsFollowingOriginal(This, steamID);
		}
				
		HOOK_DECL(EnumerateFollowingList, 69, SteamAPICall_t, uint32 unStartIndex)
		{
			Util::Debug::PrintLine("EnumerateFollowingList!");

			return EnumerateFollowingListOriginal(This, unStartIndex);
		}
				
		HOOK_DECL(IsClanPublic, 70, bool, CSteamID steamIDClan)
		{
			Util::Debug::PrintLine("IsClanPublic!");

			return IsClanPublicOriginal(This, steamIDClan);
		}
				
		HOOK_DECL(IsClanOfficialGameGroup, 71, bool, CSteamID steamIDClan)
		{
			Util::Debug::PrintLine("IsClanOfficialGameGroup!");

			return IsClanOfficialGameGroupOriginal(This, steamIDClan);
		}
		
	};
}