#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamGameCoordinator_Hooks : CHookManager<ISteamGameCoordinator>
	{

	public:
		ISteamGameCoordinator_Hooks() = delete;
		ISteamGameCoordinator_Hooks(ISteamGameCoordinator* obj) : CHookManager<ISteamGameCoordinator>(obj) {};

        		
		HOOK_DECL(SendMessage, 0, EGCResults, uint32 unMsgType, const void *pubData, uint32 cubData)
		{
			Util::Debug::PrintLine("SendMessage!");

			return SendMessageOriginal(This, unMsgType, pubData, cubData);
		}
				
		HOOK_DECL(IsMessageAvailable, 1, bool, uint32 *pcubMsgSize)
		{
			Util::Debug::PrintLine("IsMessageAvailable!");

			return IsMessageAvailableOriginal(This, pcubMsgSize);
		}
				
		HOOK_DECL(RetrieveMessage, 2, EGCResults, uint32 *punMsgType, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize)
		{
			Util::Debug::PrintLine("RetrieveMessage!");

			return RetrieveMessageOriginal(This, punMsgType, pubDest, cubDest, pcubMsgSize);
		}
		
	};
}