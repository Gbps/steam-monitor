#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamUGC_Hooks : CHookManager<ISteamUGC>
	{

	public:
		ISteamUGC_Hooks() = delete;
		ISteamUGC_Hooks(ISteamUGC* obj) : CHookManager<ISteamUGC>(obj) {};

        		
		HOOK_DECL(CreateQueryUserUGCRequest, 0, UGCQueryHandle_t, AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage)
		{
			Util::Debug::PrintLine("CreateQueryUserUGCRequest!");

			return CreateQueryUserUGCRequestOriginal(This, unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage);
		}
				
		HOOK_DECL(CreateQueryAllUGCRequest, 1, UGCQueryHandle_t, EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage)
		{
			Util::Debug::PrintLine("CreateQueryAllUGCRequest!");

			return CreateQueryAllUGCRequestOriginal(This, eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage);
		}
				
		HOOK_DECL(CreateQueryUGCDetailsRequest, 2, UGCQueryHandle_t, PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs)
		{
			Util::Debug::PrintLine("CreateQueryUGCDetailsRequest!");

			return CreateQueryUGCDetailsRequestOriginal(This, pvecPublishedFileID, unNumPublishedFileIDs);
		}
				
		HOOK_DECL(SendQueryUGCRequest, 3, SteamAPICall_t, UGCQueryHandle_t handle)
		{
			Util::Debug::PrintLine("SendQueryUGCRequest!");

			return SendQueryUGCRequestOriginal(This, handle);
		}
				
		HOOK_DECL(GetQueryUGCResult, 4, bool, UGCQueryHandle_t handle, uint32 index, SteamUGCDetails_t *pDetails)
		{
			Util::Debug::PrintLine("GetQueryUGCResult!");

			return GetQueryUGCResultOriginal(This, handle, index, pDetails);
		}
				
		HOOK_DECL(GetQueryUGCPreviewURL, 5, bool, UGCQueryHandle_t handle, uint32 index,  char *pchURL, uint32 cchURLSize)
		{
			Util::Debug::PrintLine("GetQueryUGCPreviewURL!");

			return GetQueryUGCPreviewURLOriginal(This, handle, index, pchURL, cchURLSize);
		}
				
		HOOK_DECL(GetQueryUGCMetadata, 6, bool, UGCQueryHandle_t handle, uint32 index,  char *pchMetadata, uint32 cchMetadatasize)
		{
			Util::Debug::PrintLine("GetQueryUGCMetadata!");

			return GetQueryUGCMetadataOriginal(This, handle, index, pchMetadata, cchMetadatasize);
		}
				
		HOOK_DECL(GetQueryUGCChildren, 7, bool, UGCQueryHandle_t handle, uint32 index, PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries)
		{
			Util::Debug::PrintLine("GetQueryUGCChildren!");

			return GetQueryUGCChildrenOriginal(This, handle, index, pvecPublishedFileID, cMaxEntries);
		}
				
		HOOK_DECL(GetQueryUGCStatistic, 8, bool, UGCQueryHandle_t handle, uint32 index, EItemStatistic eStatType, uint64 *pStatValue)
		{
			Util::Debug::PrintLine("GetQueryUGCStatistic!");

			return GetQueryUGCStatisticOriginal(This, handle, index, eStatType, pStatValue);
		}
				
		HOOK_DECL(GetQueryUGCNumAdditionalPreviews, 9, uint32, UGCQueryHandle_t handle, uint32 index)
		{
			Util::Debug::PrintLine("GetQueryUGCNumAdditionalPreviews!");

			return GetQueryUGCNumAdditionalPreviewsOriginal(This, handle, index);
		}
				
		HOOK_DECL(GetQueryUGCAdditionalPreview, 10, bool, UGCQueryHandle_t handle, uint32 index, uint32 previewIndex,  char *pchURLOrVideoID, uint32 cchURLSize,  char *pchOriginalFileName, uint32 cchOriginalFileNameSize, EItemPreviewType *pPreviewType)
		{
			Util::Debug::PrintLine("GetQueryUGCAdditionalPreview!");

			return GetQueryUGCAdditionalPreviewOriginal(This, handle, index, previewIndex, pchURLOrVideoID, cchURLSize, pchOriginalFileName, cchOriginalFileNameSize, pPreviewType);
		}
				
		HOOK_DECL(GetQueryUGCNumKeyValueTags, 11, uint32, UGCQueryHandle_t handle, uint32 index)
		{
			Util::Debug::PrintLine("GetQueryUGCNumKeyValueTags!");

			return GetQueryUGCNumKeyValueTagsOriginal(This, handle, index);
		}
				
		HOOK_DECL(GetQueryUGCKeyValueTag, 12, bool, UGCQueryHandle_t handle, uint32 index, uint32 keyValueTagIndex,  char *pchKey, uint32 cchKeySize,  char *pchValue, uint32 cchValueSize)
		{
			Util::Debug::PrintLine("GetQueryUGCKeyValueTag!");

			return GetQueryUGCKeyValueTagOriginal(This, handle, index, keyValueTagIndex, pchKey, cchKeySize, pchValue, cchValueSize);
		}
				
		HOOK_DECL(ReleaseQueryUGCRequest, 13, bool, UGCQueryHandle_t handle)
		{
			Util::Debug::PrintLine("ReleaseQueryUGCRequest!");

			return ReleaseQueryUGCRequestOriginal(This, handle);
		}
				
		HOOK_DECL(AddRequiredTag, 14, bool, UGCQueryHandle_t handle, const char *pTagName)
		{
			Util::Debug::PrintLine("AddRequiredTag!");

			return AddRequiredTagOriginal(This, handle, pTagName);
		}
				
		HOOK_DECL(AddExcludedTag, 15, bool, UGCQueryHandle_t handle, const char *pTagName)
		{
			Util::Debug::PrintLine("AddExcludedTag!");

			return AddExcludedTagOriginal(This, handle, pTagName);
		}
				
		HOOK_DECL(SetReturnOnlyIDs, 16, bool, UGCQueryHandle_t handle, bool bReturnOnlyIDs)
		{
			Util::Debug::PrintLine("SetReturnOnlyIDs!");

			return SetReturnOnlyIDsOriginal(This, handle, bReturnOnlyIDs);
		}
				
		HOOK_DECL(SetReturnKeyValueTags, 17, bool, UGCQueryHandle_t handle, bool bReturnKeyValueTags)
		{
			Util::Debug::PrintLine("SetReturnKeyValueTags!");

			return SetReturnKeyValueTagsOriginal(This, handle, bReturnKeyValueTags);
		}
				
		HOOK_DECL(SetReturnLongDescription, 18, bool, UGCQueryHandle_t handle, bool bReturnLongDescription)
		{
			Util::Debug::PrintLine("SetReturnLongDescription!");

			return SetReturnLongDescriptionOriginal(This, handle, bReturnLongDescription);
		}
				
		HOOK_DECL(SetReturnMetadata, 19, bool, UGCQueryHandle_t handle, bool bReturnMetadata)
		{
			Util::Debug::PrintLine("SetReturnMetadata!");

			return SetReturnMetadataOriginal(This, handle, bReturnMetadata);
		}
				
		HOOK_DECL(SetReturnChildren, 20, bool, UGCQueryHandle_t handle, bool bReturnChildren)
		{
			Util::Debug::PrintLine("SetReturnChildren!");

			return SetReturnChildrenOriginal(This, handle, bReturnChildren);
		}
				
		HOOK_DECL(SetReturnAdditionalPreviews, 21, bool, UGCQueryHandle_t handle, bool bReturnAdditionalPreviews)
		{
			Util::Debug::PrintLine("SetReturnAdditionalPreviews!");

			return SetReturnAdditionalPreviewsOriginal(This, handle, bReturnAdditionalPreviews);
		}
				
		HOOK_DECL(SetReturnTotalOnly, 22, bool, UGCQueryHandle_t handle, bool bReturnTotalOnly)
		{
			Util::Debug::PrintLine("SetReturnTotalOnly!");

			return SetReturnTotalOnlyOriginal(This, handle, bReturnTotalOnly);
		}
				
		HOOK_DECL(SetReturnPlaytimeStats, 23, bool, UGCQueryHandle_t handle, uint32 unDays)
		{
			Util::Debug::PrintLine("SetReturnPlaytimeStats!");

			return SetReturnPlaytimeStatsOriginal(This, handle, unDays);
		}
				
		HOOK_DECL(SetLanguage, 24, bool, UGCQueryHandle_t handle, const char *pchLanguage)
		{
			Util::Debug::PrintLine("SetLanguage!");

			return SetLanguageOriginal(This, handle, pchLanguage);
		}
				
		HOOK_DECL(SetAllowCachedResponse, 25, bool, UGCQueryHandle_t handle, uint32 unMaxAgeSeconds)
		{
			Util::Debug::PrintLine("SetAllowCachedResponse!");

			return SetAllowCachedResponseOriginal(This, handle, unMaxAgeSeconds);
		}
				
		HOOK_DECL(SetCloudFileNameFilter, 26, bool, UGCQueryHandle_t handle, const char *pMatchCloudFileName)
		{
			Util::Debug::PrintLine("SetCloudFileNameFilter!");

			return SetCloudFileNameFilterOriginal(This, handle, pMatchCloudFileName);
		}
				
		HOOK_DECL(SetMatchAnyTag, 27, bool, UGCQueryHandle_t handle, bool bMatchAnyTag)
		{
			Util::Debug::PrintLine("SetMatchAnyTag!");

			return SetMatchAnyTagOriginal(This, handle, bMatchAnyTag);
		}
				
		HOOK_DECL(SetSearchText, 28, bool, UGCQueryHandle_t handle, const char *pSearchText)
		{
			Util::Debug::PrintLine("SetSearchText!");

			return SetSearchTextOriginal(This, handle, pSearchText);
		}
				
		HOOK_DECL(SetRankedByTrendDays, 29, bool, UGCQueryHandle_t handle, uint32 unDays)
		{
			Util::Debug::PrintLine("SetRankedByTrendDays!");

			return SetRankedByTrendDaysOriginal(This, handle, unDays);
		}
				
		HOOK_DECL(AddRequiredKeyValueTag, 30, bool, UGCQueryHandle_t handle, const char *pKey, const char *pValue)
		{
			Util::Debug::PrintLine("AddRequiredKeyValueTag!");

			return AddRequiredKeyValueTagOriginal(This, handle, pKey, pValue);
		}
				
		HOOK_DECL(RequestUGCDetails, 31, SteamAPICall_t, PublishedFileId_t nPublishedFileID, uint32 unMaxAgeSeconds)
		{
			Util::Debug::PrintLine("RequestUGCDetails!");

			return RequestUGCDetailsOriginal(This, nPublishedFileID, unMaxAgeSeconds);
		}
				
		HOOK_DECL(CreateItem, 32, SteamAPICall_t, AppId_t nConsumerAppId, EWorkshopFileType eFileType)
		{
			Util::Debug::PrintLine("CreateItem!");

			return CreateItemOriginal(This, nConsumerAppId, eFileType);
		}
				
		HOOK_DECL(StartItemUpdate, 33, UGCUpdateHandle_t, AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID)
		{
			Util::Debug::PrintLine("StartItemUpdate!");

			return StartItemUpdateOriginal(This, nConsumerAppId, nPublishedFileID);
		}
				
		HOOK_DECL(SetItemTitle, 34, bool, UGCUpdateHandle_t handle, const char *pchTitle)
		{
			Util::Debug::PrintLine("SetItemTitle!");

			return SetItemTitleOriginal(This, handle, pchTitle);
		}
				
		HOOK_DECL(SetItemDescription, 35, bool, UGCUpdateHandle_t handle, const char *pchDescription)
		{
			Util::Debug::PrintLine("SetItemDescription!");

			return SetItemDescriptionOriginal(This, handle, pchDescription);
		}
				
		HOOK_DECL(SetItemUpdateLanguage, 36, bool, UGCUpdateHandle_t handle, const char *pchLanguage)
		{
			Util::Debug::PrintLine("SetItemUpdateLanguage!");

			return SetItemUpdateLanguageOriginal(This, handle, pchLanguage);
		}
				
		HOOK_DECL(SetItemMetadata, 37, bool, UGCUpdateHandle_t handle, const char *pchMetaData)
		{
			Util::Debug::PrintLine("SetItemMetadata!");

			return SetItemMetadataOriginal(This, handle, pchMetaData);
		}
				
		HOOK_DECL(SetItemVisibility, 38, bool, UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility)
		{
			Util::Debug::PrintLine("SetItemVisibility!");

			return SetItemVisibilityOriginal(This, handle, eVisibility);
		}
				
		HOOK_DECL(SetItemTags, 39, bool, UGCUpdateHandle_t updateHandle, const SteamParamStringArray_t *pTags)
		{
			Util::Debug::PrintLine("SetItemTags!");

			return SetItemTagsOriginal(This, updateHandle, pTags);
		}
				
		HOOK_DECL(SetItemContent, 40, bool, UGCUpdateHandle_t handle, const char *pszContentFolder)
		{
			Util::Debug::PrintLine("SetItemContent!");

			return SetItemContentOriginal(This, handle, pszContentFolder);
		}
				
		HOOK_DECL(SetItemPreview, 41, bool, UGCUpdateHandle_t handle, const char *pszPreviewFile)
		{
			Util::Debug::PrintLine("SetItemPreview!");

			return SetItemPreviewOriginal(This, handle, pszPreviewFile);
		}
				
		HOOK_DECL(RemoveItemKeyValueTags, 42, bool, UGCUpdateHandle_t handle, const char *pchKey)
		{
			Util::Debug::PrintLine("RemoveItemKeyValueTags!");

			return RemoveItemKeyValueTagsOriginal(This, handle, pchKey);
		}
				
		HOOK_DECL(AddItemKeyValueTag, 43, bool, UGCUpdateHandle_t handle, const char *pchKey, const char *pchValue)
		{
			Util::Debug::PrintLine("AddItemKeyValueTag!");

			return AddItemKeyValueTagOriginal(This, handle, pchKey, pchValue);
		}
				
		HOOK_DECL(AddItemPreviewFile, 44, bool, UGCUpdateHandle_t handle, const char *pszPreviewFile, EItemPreviewType type)
		{
			Util::Debug::PrintLine("AddItemPreviewFile!");

			return AddItemPreviewFileOriginal(This, handle, pszPreviewFile, type);
		}
				
		HOOK_DECL(AddItemPreviewVideo, 45, bool, UGCUpdateHandle_t handle, const char *pszVideoID)
		{
			Util::Debug::PrintLine("AddItemPreviewVideo!");

			return AddItemPreviewVideoOriginal(This, handle, pszVideoID);
		}
				
		HOOK_DECL(UpdateItemPreviewFile, 46, bool, UGCUpdateHandle_t handle, uint32 index, const char *pszPreviewFile)
		{
			Util::Debug::PrintLine("UpdateItemPreviewFile!");

			return UpdateItemPreviewFileOriginal(This, handle, index, pszPreviewFile);
		}
				
		HOOK_DECL(UpdateItemPreviewVideo, 47, bool, UGCUpdateHandle_t handle, uint32 index, const char *pszVideoID)
		{
			Util::Debug::PrintLine("UpdateItemPreviewVideo!");

			return UpdateItemPreviewVideoOriginal(This, handle, index, pszVideoID);
		}
				
		HOOK_DECL(RemoveItemPreview, 48, bool, UGCUpdateHandle_t handle, uint32 index)
		{
			Util::Debug::PrintLine("RemoveItemPreview!");

			return RemoveItemPreviewOriginal(This, handle, index);
		}
				
		HOOK_DECL(SubmitItemUpdate, 49, SteamAPICall_t, UGCUpdateHandle_t handle, const char *pchChangeNote)
		{
			Util::Debug::PrintLine("SubmitItemUpdate!");

			return SubmitItemUpdateOriginal(This, handle, pchChangeNote);
		}
				
		HOOK_DECL(GetItemUpdateProgress, 50, EItemUpdateStatus, UGCUpdateHandle_t handle, uint64 *punBytesProcessed, uint64* punBytesTotal)
		{
			Util::Debug::PrintLine("GetItemUpdateProgress!");

			return GetItemUpdateProgressOriginal(This, handle, punBytesProcessed, punBytesTotal);
		}
				
		HOOK_DECL(SetUserItemVote, 51, SteamAPICall_t, PublishedFileId_t nPublishedFileID, bool bVoteUp)
		{
			Util::Debug::PrintLine("SetUserItemVote!");

			return SetUserItemVoteOriginal(This, nPublishedFileID, bVoteUp);
		}
				
		HOOK_DECL(GetUserItemVote, 52, SteamAPICall_t, PublishedFileId_t nPublishedFileID)
		{
			Util::Debug::PrintLine("GetUserItemVote!");

			return GetUserItemVoteOriginal(This, nPublishedFileID);
		}
				
		HOOK_DECL(AddItemToFavorites, 53, SteamAPICall_t, AppId_t nAppId, PublishedFileId_t nPublishedFileID)
		{
			Util::Debug::PrintLine("AddItemToFavorites!");

			return AddItemToFavoritesOriginal(This, nAppId, nPublishedFileID);
		}
				
		HOOK_DECL(RemoveItemFromFavorites, 54, SteamAPICall_t, AppId_t nAppId, PublishedFileId_t nPublishedFileID)
		{
			Util::Debug::PrintLine("RemoveItemFromFavorites!");

			return RemoveItemFromFavoritesOriginal(This, nAppId, nPublishedFileID);
		}
				
		HOOK_DECL(SubscribeItem, 55, SteamAPICall_t, PublishedFileId_t nPublishedFileID)
		{
			Util::Debug::PrintLine("SubscribeItem!");

			return SubscribeItemOriginal(This, nPublishedFileID);
		}
				
		HOOK_DECL(UnsubscribeItem, 56, SteamAPICall_t, PublishedFileId_t nPublishedFileID)
		{
			Util::Debug::PrintLine("UnsubscribeItem!");

			return UnsubscribeItemOriginal(This, nPublishedFileID);
		}
				
		HOOK_DECL(GetNumSubscribedItems, 57, uint32)
		{
			Util::Debug::PrintLine("GetNumSubscribedItems!");

			return GetNumSubscribedItemsOriginal(This);
		}
				
		HOOK_DECL(GetSubscribedItems, 58, uint32, PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries)
		{
			Util::Debug::PrintLine("GetSubscribedItems!");

			return GetSubscribedItemsOriginal(This, pvecPublishedFileID, cMaxEntries);
		}
				
		HOOK_DECL(GetItemState, 59, uint32, PublishedFileId_t nPublishedFileID)
		{
			Util::Debug::PrintLine("GetItemState!");

			return GetItemStateOriginal(This, nPublishedFileID);
		}
				
		HOOK_DECL(GetItemInstallInfo, 60, bool, PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk,  char *pchFolder, uint32 cchFolderSize, uint32 *punTimeStamp)
		{
			Util::Debug::PrintLine("GetItemInstallInfo!");

			return GetItemInstallInfoOriginal(This, nPublishedFileID, punSizeOnDisk, pchFolder, cchFolderSize, punTimeStamp);
		}
				
		HOOK_DECL(GetItemDownloadInfo, 61, bool, PublishedFileId_t nPublishedFileID, uint64 *punBytesDownloaded, uint64 *punBytesTotal)
		{
			Util::Debug::PrintLine("GetItemDownloadInfo!");

			return GetItemDownloadInfoOriginal(This, nPublishedFileID, punBytesDownloaded, punBytesTotal);
		}
				
		HOOK_DECL(DownloadItem, 62, bool, PublishedFileId_t nPublishedFileID, bool bHighPriority)
		{
			Util::Debug::PrintLine("DownloadItem!");

			return DownloadItemOriginal(This, nPublishedFileID, bHighPriority);
		}
				
		HOOK_DECL(BInitWorkshopForGameServer, 63, bool, DepotId_t unWorkshopDepotID, const char *pszFolder)
		{
			Util::Debug::PrintLine("BInitWorkshopForGameServer!");

			return BInitWorkshopForGameServerOriginal(This, unWorkshopDepotID, pszFolder);
		}
				
		HOOK_DECL(SuspendDownloads, 64, void, bool bSuspend)
		{
			Util::Debug::PrintLine("SuspendDownloads!");

			return SuspendDownloadsOriginal(This, bSuspend);
		}
				
		HOOK_DECL(StartPlaytimeTracking, 65, SteamAPICall_t, PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs)
		{
			Util::Debug::PrintLine("StartPlaytimeTracking!");

			return StartPlaytimeTrackingOriginal(This, pvecPublishedFileID, unNumPublishedFileIDs);
		}
				
		HOOK_DECL(StopPlaytimeTracking, 66, SteamAPICall_t, PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs)
		{
			Util::Debug::PrintLine("StopPlaytimeTracking!");

			return StopPlaytimeTrackingOriginal(This, pvecPublishedFileID, unNumPublishedFileIDs);
		}
				
		HOOK_DECL(StopPlaytimeTrackingForAllItems, 67, SteamAPICall_t)
		{
			Util::Debug::PrintLine("StopPlaytimeTrackingForAllItems!");

			return StopPlaytimeTrackingForAllItemsOriginal(This);
		}
				
		HOOK_DECL(AddDependency, 68, SteamAPICall_t, PublishedFileId_t nParentPublishedFileID, PublishedFileId_t nChildPublishedFileID)
		{
			Util::Debug::PrintLine("AddDependency!");

			return AddDependencyOriginal(This, nParentPublishedFileID, nChildPublishedFileID);
		}
				
		HOOK_DECL(RemoveDependency, 69, SteamAPICall_t, PublishedFileId_t nParentPublishedFileID, PublishedFileId_t nChildPublishedFileID)
		{
			Util::Debug::PrintLine("RemoveDependency!");

			return RemoveDependencyOriginal(This, nParentPublishedFileID, nChildPublishedFileID);
		}
				
		HOOK_DECL(AddAppDependency, 70, SteamAPICall_t, PublishedFileId_t nPublishedFileID, AppId_t nAppID)
		{
			Util::Debug::PrintLine("AddAppDependency!");

			return AddAppDependencyOriginal(This, nPublishedFileID, nAppID);
		}
				
		HOOK_DECL(RemoveAppDependency, 71, SteamAPICall_t, PublishedFileId_t nPublishedFileID, AppId_t nAppID)
		{
			Util::Debug::PrintLine("RemoveAppDependency!");

			return RemoveAppDependencyOriginal(This, nPublishedFileID, nAppID);
		}
				
		HOOK_DECL(GetAppDependencies, 72, SteamAPICall_t, PublishedFileId_t nPublishedFileID)
		{
			Util::Debug::PrintLine("GetAppDependencies!");

			return GetAppDependenciesOriginal(This, nPublishedFileID);
		}
				
		HOOK_DECL(DeleteItem, 73, SteamAPICall_t, PublishedFileId_t nPublishedFileID)
		{
			Util::Debug::PrintLine("DeleteItem!");

			return DeleteItemOriginal(This, nPublishedFileID);
		}
		
	};
}