#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class CSteamAPIContext_Hooks : CHookManager<CSteamAPIContext>
	{

	public:
		CSteamAPIContext_Hooks() = delete;
		CSteamAPIContext_Hooks(CSteamAPIContext* obj) : CHookManager<CSteamAPIContext>(obj) {};

        		
		HOOK_DECL(Run, 0, void, void *pvParam)
		{
			Util::Debug::PrintLine("Run!");

			return RunOriginal(This, pvParam);
		}
				
		HOOK_DECL(Run, 1, void, void *pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall)
		{
			Util::Debug::PrintLine("Run!");

			return RunOriginal(This, pvParam, bIOFailure, hSteamAPICall);
		}
				
		HOOK_DECL(GetCallbackSizeBytes, 2, int)
		{
			Util::Debug::PrintLine("GetCallbackSizeBytes!");

			return GetCallbackSizeBytesOriginal(This);
		}
				
		HOOK_DECL(Run, 3, void, void *pvParam)
		{
			Util::Debug::PrintLine("Run!");

			return RunOriginal(This, pvParam);
		}
				
		HOOK_DECL(Run, 4, void, void *pvParam, bool /*bIOFailure*/, SteamAPICall_t /*hSteamAPICall*/)
		{
			Util::Debug::PrintLine("Run!");

			return RunOriginal(This, pvParam, /*bIOFailure*/, /*hSteamAPICall*/);
		}
				
		HOOK_DECL(GetCallbackSizeBytes, 5, int)
		{
			Util::Debug::PrintLine("GetCallbackSizeBytes!");

			return GetCallbackSizeBytesOriginal(This);
		}
				
		HOOK_DECL(Run, 6, void, void *pvParam)
		{
			Util::Debug::PrintLine("Run!");

			return RunOriginal(This, pvParam);
		}
				
		HOOK_DECL(Run, 7, void, void *pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall)
		{
			Util::Debug::PrintLine("Run!");

			return RunOriginal(This, pvParam, bIOFailure, hSteamAPICall);
		}
				
		HOOK_DECL(GetCallbackSizeBytes, 8, int)
		{
			Util::Debug::PrintLine("GetCallbackSizeBytes!");

			return GetCallbackSizeBytesOriginal(This);
		}
				
		HOOK_DECL(Run, 9, void, void *pvParam)
		{
			Util::Debug::PrintLine("Run!");

			return RunOriginal(This, pvParam);
		}
		
	};
}