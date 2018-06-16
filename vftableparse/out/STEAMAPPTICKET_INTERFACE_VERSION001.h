#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamAppTicket_Hooks : CHookManager<ISteamAppTicket>
	{

	public:
		ISteamAppTicket_Hooks() = delete;
		ISteamAppTicket_Hooks(ISteamAppTicket* obj) : CHookManager<ISteamAppTicket>(obj) {};

        		
		HOOK_DECL(GetAppOwnershipTicketData, 0, uint32, uint32 nAppID, void *pvBuffer, uint32 cbBufferLength, uint32 *piAppId, uint32 *piSteamId, uint32 *piSignature, uint32 *pcbSignature)
		{
			Util::Debug::PrintLine("GetAppOwnershipTicketData!");

			return GetAppOwnershipTicketDataOriginal(This, nAppID, pvBuffer, cbBufferLength, piAppId, piSteamId, piSignature, pcbSignature);
		}
		
	};
}