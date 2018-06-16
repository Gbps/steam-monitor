#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamNetworking_Hooks : CHookManager<ISteamNetworking>
	{

	public:
		ISteamNetworking_Hooks() = delete;
		ISteamNetworking_Hooks(ISteamNetworking* obj) : CHookManager<ISteamNetworking>(obj) {};

        		
		HOOK_DECL(SendP2PPacket, 0, bool, CSteamID steamIDRemote, const void *pubData, uint32 cubData, EP2PSend eP2PSendType, int nChannel = 0)
		{
			Util::Debug::PrintLine("SendP2PPacket!");

			return SendP2PPacketOriginal(This, steamIDRemote, pubData, cubData, eP2PSendType, 0);
		}
				
		HOOK_DECL(IsP2PPacketAvailable, 1, bool, uint32 *pcubMsgSize, int nChannel = 0)
		{
			Util::Debug::PrintLine("IsP2PPacketAvailable!");

			return IsP2PPacketAvailableOriginal(This, pcubMsgSize, 0);
		}
				
		HOOK_DECL(ReadP2PPacket, 2, bool, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize, CSteamID *psteamIDRemote, int nChannel = 0)
		{
			Util::Debug::PrintLine("ReadP2PPacket!");

			return ReadP2PPacketOriginal(This, pubDest, cubDest, pcubMsgSize, psteamIDRemote, 0);
		}
				
		HOOK_DECL(AcceptP2PSessionWithUser, 3, bool, CSteamID steamIDRemote)
		{
			Util::Debug::PrintLine("AcceptP2PSessionWithUser!");

			return AcceptP2PSessionWithUserOriginal(This, steamIDRemote);
		}
				
		HOOK_DECL(CloseP2PSessionWithUser, 4, bool, CSteamID steamIDRemote)
		{
			Util::Debug::PrintLine("CloseP2PSessionWithUser!");

			return CloseP2PSessionWithUserOriginal(This, steamIDRemote);
		}
				
		HOOK_DECL(CloseP2PChannelWithUser, 5, bool, CSteamID steamIDRemote, int nChannel)
		{
			Util::Debug::PrintLine("CloseP2PChannelWithUser!");

			return CloseP2PChannelWithUserOriginal(This, steamIDRemote, nChannel);
		}
				
		HOOK_DECL(GetP2PSessionState, 6, bool, CSteamID steamIDRemote, P2PSessionState_t *pConnectionState)
		{
			Util::Debug::PrintLine("GetP2PSessionState!");

			return GetP2PSessionStateOriginal(This, steamIDRemote, pConnectionState);
		}
				
		HOOK_DECL(AllowP2PPacketRelay, 7, bool, bool bAllow)
		{
			Util::Debug::PrintLine("AllowP2PPacketRelay!");

			return AllowP2PPacketRelayOriginal(This, bAllow);
		}
				
		HOOK_DECL(CreateListenSocket, 8, SNetListenSocket_t, int nVirtualP2PPort, uint32 nIP, uint16 nPort, bool bAllowUseOfPacketRelay)
		{
			Util::Debug::PrintLine("CreateListenSocket!");

			return CreateListenSocketOriginal(This, nVirtualP2PPort, nIP, nPort, bAllowUseOfPacketRelay);
		}
				
		HOOK_DECL(CreateP2PConnectionSocket, 9, SNetSocket_t, CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay)
		{
			Util::Debug::PrintLine("CreateP2PConnectionSocket!");

			return CreateP2PConnectionSocketOriginal(This, steamIDTarget, nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay);
		}
				
		HOOK_DECL(CreateConnectionSocket, 10, SNetSocket_t, uint32 nIP, uint16 nPort, int nTimeoutSec)
		{
			Util::Debug::PrintLine("CreateConnectionSocket!");

			return CreateConnectionSocketOriginal(This, nIP, nPort, nTimeoutSec);
		}
				
		HOOK_DECL(DestroySocket, 11, bool, SNetSocket_t hSocket, bool bNotifyRemoteEnd)
		{
			Util::Debug::PrintLine("DestroySocket!");

			return DestroySocketOriginal(This, hSocket, bNotifyRemoteEnd);
		}
				
		HOOK_DECL(DestroyListenSocket, 12, bool, SNetListenSocket_t hSocket, bool bNotifyRemoteEnd)
		{
			Util::Debug::PrintLine("DestroyListenSocket!");

			return DestroyListenSocketOriginal(This, hSocket, bNotifyRemoteEnd);
		}
				
		HOOK_DECL(SendDataOnSocket, 13, bool, SNetSocket_t hSocket, void *pubData, uint32 cubData, bool bReliable)
		{
			Util::Debug::PrintLine("SendDataOnSocket!");

			return SendDataOnSocketOriginal(This, hSocket, pubData, cubData, bReliable);
		}
				
		HOOK_DECL(IsDataAvailableOnSocket, 14, bool, SNetSocket_t hSocket, uint32 *pcubMsgSize)
		{
			Util::Debug::PrintLine("IsDataAvailableOnSocket!");

			return IsDataAvailableOnSocketOriginal(This, hSocket, pcubMsgSize);
		}
				
		HOOK_DECL(RetrieveDataFromSocket, 15, bool, SNetSocket_t hSocket, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize)
		{
			Util::Debug::PrintLine("RetrieveDataFromSocket!");

			return RetrieveDataFromSocketOriginal(This, hSocket, pubDest, cubDest, pcubMsgSize);
		}
				
		HOOK_DECL(IsDataAvailable, 16, bool, SNetListenSocket_t hListenSocket, uint32 *pcubMsgSize, SNetSocket_t *phSocket)
		{
			Util::Debug::PrintLine("IsDataAvailable!");

			return IsDataAvailableOriginal(This, hListenSocket, pcubMsgSize, phSocket);
		}
				
		HOOK_DECL(RetrieveData, 17, bool, SNetListenSocket_t hListenSocket, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize, SNetSocket_t *phSocket)
		{
			Util::Debug::PrintLine("RetrieveData!");

			return RetrieveDataOriginal(This, hListenSocket, pubDest, cubDest, pcubMsgSize, phSocket);
		}
				
		HOOK_DECL(GetSocketInfo, 18, bool, SNetSocket_t hSocket, CSteamID *pSteamIDRemote, int *peSocketStatus, uint32 *punIPRemote, uint16 *punPortRemote)
		{
			Util::Debug::PrintLine("GetSocketInfo!");

			return GetSocketInfoOriginal(This, hSocket, pSteamIDRemote, peSocketStatus, punIPRemote, punPortRemote);
		}
				
		HOOK_DECL(GetListenSocketInfo, 19, bool, SNetListenSocket_t hListenSocket, uint32 *pnIP, uint16 *pnPort)
		{
			Util::Debug::PrintLine("GetListenSocketInfo!");

			return GetListenSocketInfoOriginal(This, hListenSocket, pnIP, pnPort);
		}
				
		HOOK_DECL(GetSocketConnectionType, 20, ESNetSocketConnectionType, SNetSocket_t hSocket)
		{
			Util::Debug::PrintLine("GetSocketConnectionType!");

			return GetSocketConnectionTypeOriginal(This, hSocket);
		}
				
		HOOK_DECL(GetMaxPacketSize, 21, int, SNetSocket_t hSocket)
		{
			Util::Debug::PrintLine("GetMaxPacketSize!");

			return GetMaxPacketSizeOriginal(This, hSocket);
		}
		
	};
}