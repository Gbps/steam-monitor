#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamRemoteStorage_Hooks : CHookManager<ISteamRemoteStorage>
	{

	public:
		ISteamRemoteStorage_Hooks() = delete;
		ISteamRemoteStorage_Hooks(ISteamRemoteStorage* obj) : CHookManager<ISteamRemoteStorage>(obj) {};

        		
		HOOK_DECL(FileWriteAsync, 0, SteamAPICall_t, const char *pchFile, const void *pvData, uint32 cubData)
		{
			Util::Debug::PrintLine("FileWriteAsync!");

			return FileWriteAsyncOriginal(This, pchFile, pvData, cubData);
		}
				
		HOOK_DECL(FileReadAsync, 1, SteamAPICall_t, const char *pchFile, uint32 nOffset, uint32 cubToRead)
		{
			Util::Debug::PrintLine("FileReadAsync!");

			return FileReadAsyncOriginal(This, pchFile, nOffset, cubToRead);
		}
				
		HOOK_DECL(FileShare, 2, SteamAPICall_t, const char *pchFile)
		{
			Util::Debug::PrintLine("FileShare!");

			return FileShareOriginal(This, pchFile);
		}
				
		HOOK_DECL(FileWriteStreamOpen, 3, UGCFileWriteStreamHandle_t, const char *pchFile)
		{
			Util::Debug::PrintLine("FileWriteStreamOpen!");

			return FileWriteStreamOpenOriginal(This, pchFile);
		}
				
		HOOK_DECL(FileWriteStreamWriteChunk, 4, bool, UGCFileWriteStreamHandle_t writeHandle, const void *pvData, int32 cubData)
		{
			Util::Debug::PrintLine("FileWriteStreamWriteChunk!");

			return FileWriteStreamWriteChunkOriginal(This, writeHandle, pvData, cubData);
		}
				
		HOOK_DECL(FileWriteStreamClose, 5, bool, UGCFileWriteStreamHandle_t writeHandle)
		{
			Util::Debug::PrintLine("FileWriteStreamClose!");

			return FileWriteStreamCloseOriginal(This, writeHandle);
		}
				
		HOOK_DECL(FileWriteStreamCancel, 6, bool, UGCFileWriteStreamHandle_t writeHandle)
		{
			Util::Debug::PrintLine("FileWriteStreamCancel!");

			return FileWriteStreamCancelOriginal(This, writeHandle);
		}
				
		HOOK_DECL(GetSyncPlatforms, 7, ERemoteStoragePlatform, const char *pchFile)
		{
			Util::Debug::PrintLine("GetSyncPlatforms!");

			return GetSyncPlatformsOriginal(This, pchFile);
		}
				
		HOOK_DECL(GetFileCount, 8, int32)
		{
			Util::Debug::PrintLine("GetFileCount!");

			return GetFileCountOriginal(This);
		}
				
		HOOK_DECL(GetFileNameAndSize, 9, const char *, int iFile, int32 *pnFileSizeInBytes)
		{
			Util::Debug::PrintLine("GetFileNameAndSize!");

			return GetFileNameAndSizeOriginal(This, iFile, pnFileSizeInBytes);
		}
				
		HOOK_DECL(GetQuota, 10, bool, uint64 *pnTotalBytes, uint64 *puAvailableBytes)
		{
			Util::Debug::PrintLine("GetQuota!");

			return GetQuotaOriginal(This, pnTotalBytes, puAvailableBytes);
		}
				
		HOOK_DECL(IsCloudEnabledForAccount, 11, bool)
		{
			Util::Debug::PrintLine("IsCloudEnabledForAccount!");

			return IsCloudEnabledForAccountOriginal(This);
		}
				
		HOOK_DECL(IsCloudEnabledForApp, 12, bool)
		{
			Util::Debug::PrintLine("IsCloudEnabledForApp!");

			return IsCloudEnabledForAppOriginal(This);
		}
				
		HOOK_DECL(SetCloudEnabledForApp, 13, void, bool bEnabled)
		{
			Util::Debug::PrintLine("SetCloudEnabledForApp!");

			return SetCloudEnabledForAppOriginal(This, bEnabled);
		}
				
		HOOK_DECL(UGCDownload, 14, SteamAPICall_t, UGCHandle_t hContent, uint32 unPriority)
		{
			Util::Debug::PrintLine("UGCDownload!");

			return UGCDownloadOriginal(This, hContent, unPriority);
		}
				
		HOOK_DECL(GetFileListFromServer, 15, void)
		{
			Util::Debug::PrintLine("GetFileListFromServer!");

			return GetFileListFromServerOriginal(This);
		}
				
		HOOK_DECL(FileFetch, 16, bool, const char *pchFile)
		{
			Util::Debug::PrintLine("FileFetch!");

			return FileFetchOriginal(This, pchFile);
		}
				
		HOOK_DECL(FilePersist, 17, bool, const char *pchFile)
		{
			Util::Debug::PrintLine("FilePersist!");

			return FilePersistOriginal(This, pchFile);
		}
				
		HOOK_DECL(SynchronizeToClient, 18, bool)
		{
			Util::Debug::PrintLine("SynchronizeToClient!");

			return SynchronizeToClientOriginal(This);
		}
				
		HOOK_DECL(SynchronizeToServer, 19, bool)
		{
			Util::Debug::PrintLine("SynchronizeToServer!");

			return SynchronizeToServerOriginal(This);
		}
				
		HOOK_DECL(ResetFileRequestState, 20, bool)
		{
			Util::Debug::PrintLine("ResetFileRequestState!");

			return ResetFileRequestStateOriginal(This);
		}
				
		HOOK_DECL(CreatePublishedFileUpdateRequest, 21, PublishedFileUpdateHandle_t, PublishedFileId_t unPublishedFileId)
		{
			Util::Debug::PrintLine("CreatePublishedFileUpdateRequest!");

			return CreatePublishedFileUpdateRequestOriginal(This, unPublishedFileId);
		}
				
		HOOK_DECL(UpdatePublishedFileFile, 22, bool, PublishedFileUpdateHandle_t updateHandle, const char *pchFile)
		{
			Util::Debug::PrintLine("UpdatePublishedFileFile!");

			return UpdatePublishedFileFileOriginal(This, updateHandle, pchFile);
		}
				
		HOOK_DECL(UpdatePublishedFilePreviewFile, 23, bool, PublishedFileUpdateHandle_t updateHandle, const char *pchPreviewFile)
		{
			Util::Debug::PrintLine("UpdatePublishedFilePreviewFile!");

			return UpdatePublishedFilePreviewFileOriginal(This, updateHandle, pchPreviewFile);
		}
				
		HOOK_DECL(UpdatePublishedFileTitle, 24, bool, PublishedFileUpdateHandle_t updateHandle, const char *pchTitle)
		{
			Util::Debug::PrintLine("UpdatePublishedFileTitle!");

			return UpdatePublishedFileTitleOriginal(This, updateHandle, pchTitle);
		}
				
		HOOK_DECL(UpdatePublishedFileDescription, 25, bool, PublishedFileUpdateHandle_t updateHandle, const char *pchDescription)
		{
			Util::Debug::PrintLine("UpdatePublishedFileDescription!");

			return UpdatePublishedFileDescriptionOriginal(This, updateHandle, pchDescription);
		}
				
		HOOK_DECL(UpdatePublishedFileVisibility, 26, bool, PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility)
		{
			Util::Debug::PrintLine("UpdatePublishedFileVisibility!");

			return UpdatePublishedFileVisibilityOriginal(This, updateHandle, eVisibility);
		}
				
		HOOK_DECL(UpdatePublishedFileTags, 27, bool, PublishedFileUpdateHandle_t updateHandle, SteamParamStringArray_t *pTags)
		{
			Util::Debug::PrintLine("UpdatePublishedFileTags!");

			return UpdatePublishedFileTagsOriginal(This, updateHandle, pTags);
		}
				
		HOOK_DECL(UpdatePublishedFileSetChangeDescription, 28, bool, PublishedFileUpdateHandle_t updateHandle, const char *pchChangeDescription)
		{
			Util::Debug::PrintLine("UpdatePublishedFileSetChangeDescription!");

			return UpdatePublishedFileSetChangeDescriptionOriginal(This, updateHandle, pchChangeDescription);
		}
				
		HOOK_DECL(UGCDownloadToLocation, 29, SteamAPICall_t, UGCHandle_t hContent, const char *pchLocation, uint32 unPriority)
		{
			Util::Debug::PrintLine("UGCDownloadToLocation!");

			return UGCDownloadToLocationOriginal(This, hContent, pchLocation, unPriority);
		}
		
	};
}