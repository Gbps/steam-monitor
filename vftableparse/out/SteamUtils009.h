#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamUtils_Hooks : CHookManager<ISteamUtils>
	{

	public:
		ISteamUtils_Hooks() = delete;
		ISteamUtils_Hooks(ISteamUtils* obj) : CHookManager<ISteamUtils>(obj) {};

        		
		HOOK_DECL(GetSecondsSinceAppActive, 0, uint32)
		{
			Util::Debug::PrintLine("GetSecondsSinceAppActive!");

			return GetSecondsSinceAppActiveOriginal(This);
		}
				
		HOOK_DECL(GetSecondsSinceComputerActive, 1, uint32)
		{
			Util::Debug::PrintLine("GetSecondsSinceComputerActive!");

			return GetSecondsSinceComputerActiveOriginal(This);
		}
				
		HOOK_DECL(GetConnectedUniverse, 2, EUniverse)
		{
			Util::Debug::PrintLine("GetConnectedUniverse!");

			return GetConnectedUniverseOriginal(This);
		}
				
		HOOK_DECL(GetServerRealTime, 3, uint32)
		{
			Util::Debug::PrintLine("GetServerRealTime!");

			return GetServerRealTimeOriginal(This);
		}
				
		HOOK_DECL(GetIPCountry, 4, const char *)
		{
			Util::Debug::PrintLine("GetIPCountry!");

			return GetIPCountryOriginal(This);
		}
				
		HOOK_DECL(GetImageSize, 5, bool, int iImage, uint32 *pnWidth, uint32 *pnHeight)
		{
			Util::Debug::PrintLine("GetImageSize!");

			return GetImageSizeOriginal(This, iImage, pnWidth, pnHeight);
		}
				
		HOOK_DECL(GetImageRGBA, 6, bool, int iImage, uint8 *pubDest, int nDestBufferSize)
		{
			Util::Debug::PrintLine("GetImageRGBA!");

			return GetImageRGBAOriginal(This, iImage, pubDest, nDestBufferSize);
		}
				
		HOOK_DECL(GetCSERIPPort, 7, bool, uint32 *unIP, uint16 *usPort)
		{
			Util::Debug::PrintLine("GetCSERIPPort!");

			return GetCSERIPPortOriginal(This, unIP, usPort);
		}
				
		HOOK_DECL(GetCurrentBatteryPower, 8, uint8)
		{
			Util::Debug::PrintLine("GetCurrentBatteryPower!");

			return GetCurrentBatteryPowerOriginal(This);
		}
				
		HOOK_DECL(GetAppID, 9, uint32)
		{
			Util::Debug::PrintLine("GetAppID!");

			return GetAppIDOriginal(This);
		}
				
		HOOK_DECL(SetOverlayNotificationPosition, 10, void, ENotificationPosition eNotificationPosition)
		{
			Util::Debug::PrintLine("SetOverlayNotificationPosition!");

			return SetOverlayNotificationPositionOriginal(This, eNotificationPosition);
		}
				
		HOOK_DECL(IsAPICallCompleted, 11, bool, SteamAPICall_t hSteamAPICall, bool *pbFailed)
		{
			Util::Debug::PrintLine("IsAPICallCompleted!");

			return IsAPICallCompletedOriginal(This, hSteamAPICall, pbFailed);
		}
				
		HOOK_DECL(GetAPICallFailureReason, 12, ESteamAPICallFailure, SteamAPICall_t hSteamAPICall)
		{
			Util::Debug::PrintLine("GetAPICallFailureReason!");

			return GetAPICallFailureReasonOriginal(This, hSteamAPICall);
		}
				
		HOOK_DECL(GetAPICallResult, 13, bool, SteamAPICall_t hSteamAPICall, void *pCallback, int cubCallback, int iCallbackExpected, bool *pbFailed)
		{
			Util::Debug::PrintLine("GetAPICallResult!");

			return GetAPICallResultOriginal(This, hSteamAPICall, pCallback, cubCallback, iCallbackExpected, pbFailed);
		}
				
		HOOK_DECL(RunFrame, 14, void)
		{
			Util::Debug::PrintLine("RunFrame!");

			return RunFrameOriginal(This);
		}
				
		HOOK_DECL(GetIPCCallCount, 15, uint32)
		{
			Util::Debug::PrintLine("GetIPCCallCount!");

			return GetIPCCallCountOriginal(This);
		}
				
		HOOK_DECL(SetWarningMessageHook, 16, void, SteamAPIWarningMessageHook_t pFunction)
		{
			Util::Debug::PrintLine("SetWarningMessageHook!");

			return SetWarningMessageHookOriginal(This, pFunction);
		}
				
		HOOK_DECL(IsOverlayEnabled, 17, bool)
		{
			Util::Debug::PrintLine("IsOverlayEnabled!");

			return IsOverlayEnabledOriginal(This);
		}
				
		HOOK_DECL(BOverlayNeedsPresent, 18, bool)
		{
			Util::Debug::PrintLine("BOverlayNeedsPresent!");

			return BOverlayNeedsPresentOriginal(This);
		}
				
		HOOK_DECL(CheckFileSignature, 19, SteamAPICall_t, const char *szFileName)
		{
			Util::Debug::PrintLine("CheckFileSignature!");

			return CheckFileSignatureOriginal(This, szFileName);
		}
				
		HOOK_DECL(ShowGamepadTextInput, 20, bool, EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char *pchDescription, uint32 unCharMax, const char *pchExistingText)
		{
			Util::Debug::PrintLine("ShowGamepadTextInput!");

			return ShowGamepadTextInputOriginal(This, eInputMode, eLineInputMode, pchDescription, unCharMax, pchExistingText);
		}
				
		HOOK_DECL(GetEnteredGamepadTextLength, 21, uint32)
		{
			Util::Debug::PrintLine("GetEnteredGamepadTextLength!");

			return GetEnteredGamepadTextLengthOriginal(This);
		}
				
		HOOK_DECL(GetEnteredGamepadTextInput, 22, bool, char *pchText, uint32 cchText)
		{
			Util::Debug::PrintLine("GetEnteredGamepadTextInput!");

			return GetEnteredGamepadTextInputOriginal(This, pchText, cchText);
		}
				
		HOOK_DECL(GetSteamUILanguage, 23, const char *)
		{
			Util::Debug::PrintLine("GetSteamUILanguage!");

			return GetSteamUILanguageOriginal(This);
		}
				
		HOOK_DECL(IsSteamRunningInVR, 24, bool)
		{
			Util::Debug::PrintLine("IsSteamRunningInVR!");

			return IsSteamRunningInVROriginal(This);
		}
				
		HOOK_DECL(SetOverlayNotificationInset, 25, void, int nHorizontalInset, int nVerticalInset)
		{
			Util::Debug::PrintLine("SetOverlayNotificationInset!");

			return SetOverlayNotificationInsetOriginal(This, nHorizontalInset, nVerticalInset);
		}
				
		HOOK_DECL(IsSteamInBigPictureMode, 26, bool)
		{
			Util::Debug::PrintLine("IsSteamInBigPictureMode!");

			return IsSteamInBigPictureModeOriginal(This);
		}
				
		HOOK_DECL(StartVRDashboard, 27, void)
		{
			Util::Debug::PrintLine("StartVRDashboard!");

			return StartVRDashboardOriginal(This);
		}
				
		HOOK_DECL(IsVRHeadsetStreamingEnabled, 28, bool)
		{
			Util::Debug::PrintLine("IsVRHeadsetStreamingEnabled!");

			return IsVRHeadsetStreamingEnabledOriginal(This);
		}
				
		HOOK_DECL(SetVRHeadsetStreamingEnabled, 29, void, bool bEnabled)
		{
			Util::Debug::PrintLine("SetVRHeadsetStreamingEnabled!");

			return SetVRHeadsetStreamingEnabledOriginal(This, bEnabled);
		}
		
	};
}