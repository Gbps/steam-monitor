#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamScreenshots_Hooks : CHookManager<ISteamScreenshots>
	{

	public:
		ISteamScreenshots_Hooks() = delete;
		ISteamScreenshots_Hooks(ISteamScreenshots* obj) : CHookManager<ISteamScreenshots>(obj) {};

        		
		HOOK_DECL(WriteScreenshot, 0, ScreenshotHandle, void *pubRGB, uint32 cubRGB, int nWidth, int nHeight)
		{
			Util::Debug::PrintLine("WriteScreenshot!");

			return WriteScreenshotOriginal(This, pubRGB, cubRGB, nWidth, nHeight);
		}
				
		HOOK_DECL(AddScreenshotToLibrary, 1, ScreenshotHandle, const char *pchFilename, const char *pchThumbnailFilename, int nWidth, int nHeight)
		{
			Util::Debug::PrintLine("AddScreenshotToLibrary!");

			return AddScreenshotToLibraryOriginal(This, pchFilename, pchThumbnailFilename, nWidth, nHeight);
		}
				
		HOOK_DECL(TriggerScreenshot, 2, void)
		{
			Util::Debug::PrintLine("TriggerScreenshot!");

			return TriggerScreenshotOriginal(This);
		}
				
		HOOK_DECL(HookScreenshots, 3, void, bool bHook)
		{
			Util::Debug::PrintLine("HookScreenshots!");

			return HookScreenshotsOriginal(This, bHook);
		}
				
		HOOK_DECL(SetLocation, 4, bool, ScreenshotHandle hScreenshot, const char *pchLocation)
		{
			Util::Debug::PrintLine("SetLocation!");

			return SetLocationOriginal(This, hScreenshot, pchLocation);
		}
				
		HOOK_DECL(TagUser, 5, bool, ScreenshotHandle hScreenshot, CSteamID steamID)
		{
			Util::Debug::PrintLine("TagUser!");

			return TagUserOriginal(This, hScreenshot, steamID);
		}
				
		HOOK_DECL(TagPublishedFile, 6, bool, ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID)
		{
			Util::Debug::PrintLine("TagPublishedFile!");

			return TagPublishedFileOriginal(This, hScreenshot, unPublishedFileID);
		}
				
		HOOK_DECL(IsScreenshotsHooked, 7, bool)
		{
			Util::Debug::PrintLine("IsScreenshotsHooked!");

			return IsScreenshotsHookedOriginal(This);
		}
				
		HOOK_DECL(AddVRScreenshotToLibrary, 8, ScreenshotHandle, EVRScreenshotType eType, const char *pchFilename, const char *pchVRFilename)
		{
			Util::Debug::PrintLine("AddVRScreenshotToLibrary!");

			return AddVRScreenshotToLibraryOriginal(This, eType, pchFilename, pchVRFilename);
		}
		
	};
}