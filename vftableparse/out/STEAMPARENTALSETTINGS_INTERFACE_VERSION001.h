#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamParentalSettings_Hooks : CHookManager<ISteamParentalSettings>
	{

	public:
		ISteamParentalSettings_Hooks() = delete;
		ISteamParentalSettings_Hooks(ISteamParentalSettings* obj) : CHookManager<ISteamParentalSettings>(obj) {};

        		
		HOOK_DECL(BIsParentalLockEnabled, 0, bool)
		{
			Util::Debug::PrintLine("BIsParentalLockEnabled!");

			return BIsParentalLockEnabledOriginal(This);
		}
				
		HOOK_DECL(BIsParentalLockLocked, 1, bool)
		{
			Util::Debug::PrintLine("BIsParentalLockLocked!");

			return BIsParentalLockLockedOriginal(This);
		}
				
		HOOK_DECL(BIsAppBlocked, 2, bool, AppId_t nAppID)
		{
			Util::Debug::PrintLine("BIsAppBlocked!");

			return BIsAppBlockedOriginal(This, nAppID);
		}
				
		HOOK_DECL(BIsAppInBlockList, 3, bool, AppId_t nAppID)
		{
			Util::Debug::PrintLine("BIsAppInBlockList!");

			return BIsAppInBlockListOriginal(This, nAppID);
		}
				
		HOOK_DECL(BIsFeatureBlocked, 4, bool, EParentalFeature eFeature)
		{
			Util::Debug::PrintLine("BIsFeatureBlocked!");

			return BIsFeatureBlockedOriginal(This, eFeature);
		}
				
		HOOK_DECL(BIsFeatureInBlockList, 5, bool, EParentalFeature eFeature)
		{
			Util::Debug::PrintLine("BIsFeatureInBlockList!");

			return BIsFeatureInBlockListOriginal(This, eFeature);
		}
		
	};
}