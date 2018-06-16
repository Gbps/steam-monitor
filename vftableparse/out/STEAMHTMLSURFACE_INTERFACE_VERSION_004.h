#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamHTMLSurface_Hooks : CHookManager<ISteamHTMLSurface>
	{

	public:
		ISteamHTMLSurface_Hooks() = delete;
		ISteamHTMLSurface_Hooks(ISteamHTMLSurface* obj) : CHookManager<ISteamHTMLSurface>(obj) {};

        		
		HOOK_DECL(Init, 0, bool)
		{
			Util::Debug::PrintLine("Init!");

			return InitOriginal(This);
		}
				
		HOOK_DECL(Shutdown, 1, bool)
		{
			Util::Debug::PrintLine("Shutdown!");

			return ShutdownOriginal(This);
		}
				
		HOOK_DECL(CreateBrowser, 2, SteamAPICall_t, const char *pchUserAgent, const char *pchUserCSS)
		{
			Util::Debug::PrintLine("CreateBrowser!");

			return CreateBrowserOriginal(This, pchUserAgent, pchUserCSS);
		}
				
		HOOK_DECL(RemoveBrowser, 3, void, HHTMLBrowser unBrowserHandle)
		{
			Util::Debug::PrintLine("RemoveBrowser!");

			return RemoveBrowserOriginal(This, unBrowserHandle);
		}
				
		HOOK_DECL(LoadURL, 4, void, HHTMLBrowser unBrowserHandle, const char *pchURL, const char *pchPostData)
		{
			Util::Debug::PrintLine("LoadURL!");

			return LoadURLOriginal(This, unBrowserHandle, pchURL, pchPostData);
		}
				
		HOOK_DECL(SetSize, 5, void, HHTMLBrowser unBrowserHandle, uint32 unWidth, uint32 unHeight)
		{
			Util::Debug::PrintLine("SetSize!");

			return SetSizeOriginal(This, unBrowserHandle, unWidth, unHeight);
		}
				
		HOOK_DECL(StopLoad, 6, void, HHTMLBrowser unBrowserHandle)
		{
			Util::Debug::PrintLine("StopLoad!");

			return StopLoadOriginal(This, unBrowserHandle);
		}
				
		HOOK_DECL(Reload, 7, void, HHTMLBrowser unBrowserHandle)
		{
			Util::Debug::PrintLine("Reload!");

			return ReloadOriginal(This, unBrowserHandle);
		}
				
		HOOK_DECL(GoBack, 8, void, HHTMLBrowser unBrowserHandle)
		{
			Util::Debug::PrintLine("GoBack!");

			return GoBackOriginal(This, unBrowserHandle);
		}
				
		HOOK_DECL(GoForward, 9, void, HHTMLBrowser unBrowserHandle)
		{
			Util::Debug::PrintLine("GoForward!");

			return GoForwardOriginal(This, unBrowserHandle);
		}
				
		HOOK_DECL(AddHeader, 10, void, HHTMLBrowser unBrowserHandle, const char *pchKey, const char *pchValue)
		{
			Util::Debug::PrintLine("AddHeader!");

			return AddHeaderOriginal(This, unBrowserHandle, pchKey, pchValue);
		}
				
		HOOK_DECL(ExecuteJavascript, 11, void, HHTMLBrowser unBrowserHandle, const char *pchScript)
		{
			Util::Debug::PrintLine("ExecuteJavascript!");

			return ExecuteJavascriptOriginal(This, unBrowserHandle, pchScript);
		}
				
		HOOK_DECL(MouseUp, 12, void, HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton)
		{
			Util::Debug::PrintLine("MouseUp!");

			return MouseUpOriginal(This, unBrowserHandle, eMouseButton);
		}
				
		HOOK_DECL(MouseDown, 13, void, HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton)
		{
			Util::Debug::PrintLine("MouseDown!");

			return MouseDownOriginal(This, unBrowserHandle, eMouseButton);
		}
				
		HOOK_DECL(MouseDoubleClick, 14, void, HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton)
		{
			Util::Debug::PrintLine("MouseDoubleClick!");

			return MouseDoubleClickOriginal(This, unBrowserHandle, eMouseButton);
		}
				
		HOOK_DECL(MouseMove, 15, void, HHTMLBrowser unBrowserHandle, int x, int y)
		{
			Util::Debug::PrintLine("MouseMove!");

			return MouseMoveOriginal(This, unBrowserHandle, x, y);
		}
				
		HOOK_DECL(MouseWheel, 16, void, HHTMLBrowser unBrowserHandle, int32 nDelta)
		{
			Util::Debug::PrintLine("MouseWheel!");

			return MouseWheelOriginal(This, unBrowserHandle, nDelta);
		}
				
		HOOK_DECL(KeyDown, 17, void, HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers)
		{
			Util::Debug::PrintLine("KeyDown!");

			return KeyDownOriginal(This, unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
		}
				
		HOOK_DECL(KeyUp, 18, void, HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers)
		{
			Util::Debug::PrintLine("KeyUp!");

			return KeyUpOriginal(This, unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
		}
				
		HOOK_DECL(KeyChar, 19, void, HHTMLBrowser unBrowserHandle, uint32 cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers)
		{
			Util::Debug::PrintLine("KeyChar!");

			return KeyCharOriginal(This, unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers);
		}
				
		HOOK_DECL(SetHorizontalScroll, 20, void, HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll)
		{
			Util::Debug::PrintLine("SetHorizontalScroll!");

			return SetHorizontalScrollOriginal(This, unBrowserHandle, nAbsolutePixelScroll);
		}
				
		HOOK_DECL(SetVerticalScroll, 21, void, HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll)
		{
			Util::Debug::PrintLine("SetVerticalScroll!");

			return SetVerticalScrollOriginal(This, unBrowserHandle, nAbsolutePixelScroll);
		}
				
		HOOK_DECL(SetKeyFocus, 22, void, HHTMLBrowser unBrowserHandle, bool bHasKeyFocus)
		{
			Util::Debug::PrintLine("SetKeyFocus!");

			return SetKeyFocusOriginal(This, unBrowserHandle, bHasKeyFocus);
		}
				
		HOOK_DECL(ViewSource, 23, void, HHTMLBrowser unBrowserHandle)
		{
			Util::Debug::PrintLine("ViewSource!");

			return ViewSourceOriginal(This, unBrowserHandle);
		}
				
		HOOK_DECL(CopyToClipboard, 24, void, HHTMLBrowser unBrowserHandle)
		{
			Util::Debug::PrintLine("CopyToClipboard!");

			return CopyToClipboardOriginal(This, unBrowserHandle);
		}
				
		HOOK_DECL(PasteFromClipboard, 25, void, HHTMLBrowser unBrowserHandle)
		{
			Util::Debug::PrintLine("PasteFromClipboard!");

			return PasteFromClipboardOriginal(This, unBrowserHandle);
		}
				
		HOOK_DECL(Find, 26, void, HHTMLBrowser unBrowserHandle, const char *pchSearchStr, bool bCurrentlyInFind, bool bReverse)
		{
			Util::Debug::PrintLine("Find!");

			return FindOriginal(This, unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse);
		}
				
		HOOK_DECL(StopFind, 27, void, HHTMLBrowser unBrowserHandle)
		{
			Util::Debug::PrintLine("StopFind!");

			return StopFindOriginal(This, unBrowserHandle);
		}
				
		HOOK_DECL(GetLinkAtPosition, 28, void, HHTMLBrowser unBrowserHandle, int x, int y)
		{
			Util::Debug::PrintLine("GetLinkAtPosition!");

			return GetLinkAtPositionOriginal(This, unBrowserHandle, x, y);
		}
				
		HOOK_DECL(SetCookie, 29, void, const char *pchHostname, const char *pchKey, const char *pchValue, const char *pchPath = "/", RTime32 nExpires = 0, bool bSecure = false, bool bHTTPOnly = false)
		{
			Util::Debug::PrintLine("SetCookie!");

			return SetCookieOriginal(This, pchHostname, pchKey, pchValue, "/", 0, false, false);
		}
				
		HOOK_DECL(SetPageScaleFactor, 30, void, HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY)
		{
			Util::Debug::PrintLine("SetPageScaleFactor!");

			return SetPageScaleFactorOriginal(This, unBrowserHandle, flZoom, nPointX, nPointY);
		}
				
		HOOK_DECL(SetBackgroundMode, 31, void, HHTMLBrowser unBrowserHandle, bool bBackgroundMode)
		{
			Util::Debug::PrintLine("SetBackgroundMode!");

			return SetBackgroundModeOriginal(This, unBrowserHandle, bBackgroundMode);
		}
				
		HOOK_DECL(SetDPIScalingFactor, 32, void, HHTMLBrowser unBrowserHandle, float flDPIScaling)
		{
			Util::Debug::PrintLine("SetDPIScalingFactor!");

			return SetDPIScalingFactorOriginal(This, unBrowserHandle, flDPIScaling);
		}
				
		HOOK_DECL(AllowStartRequest, 33, void, HHTMLBrowser unBrowserHandle, bool bAllowed)
		{
			Util::Debug::PrintLine("AllowStartRequest!");

			return AllowStartRequestOriginal(This, unBrowserHandle, bAllowed);
		}
				
		HOOK_DECL(JSDialogResponse, 34, void, HHTMLBrowser unBrowserHandle, bool bResult)
		{
			Util::Debug::PrintLine("JSDialogResponse!");

			return JSDialogResponseOriginal(This, unBrowserHandle, bResult);
		}
				
		HOOK_DECL(FileLoadDialogResponse, 35, void, HHTMLBrowser unBrowserHandle, const char **pchSelectedFiles)
		{
			Util::Debug::PrintLine("FileLoadDialogResponse!");

			return FileLoadDialogResponseOriginal(This, unBrowserHandle, *pchSelectedFiles);
		}
		
	};
}