#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamInventory_Hooks : CHookManager<ISteamInventory>
	{

	public:
		ISteamInventory_Hooks() = delete;
		ISteamInventory_Hooks(ISteamInventory* obj) : CHookManager<ISteamInventory>(obj) {};

        		
		HOOK_DECL(GetResultStatus, 0, EResult, SteamInventoryResult_t resultHandle)
		{
			Util::Debug::PrintLine("GetResultStatus!");

			return GetResultStatusOriginal(This, resultHandle);
		}
				
		HOOK_DECL(GetResultItems, 1, bool, SteamInventoryResult_t resultHandle,
								 SteamItemDetails_t *pOutItemsArray,
								uint32 *punOutItemsArraySize)
		{
			Util::Debug::PrintLine("GetResultItems!");

			return GetResultItemsOriginal(This, resultHandle, pOutItemsArray, punOutItemsArraySize);
		}
				
		HOOK_DECL(GetResultItemProperty, 2, bool, SteamInventoryResult_t resultHandle, 
										uint32 unItemIndex, 
										const char *pchPropertyName,
										 char *pchValueBuffer, uint32 *punValueBufferSizeOut)
		{
			Util::Debug::PrintLine("GetResultItemProperty!");

			return GetResultItemPropertyOriginal(This, resultHandle, unItemIndex, pchPropertyName, pchValueBuffer, punValueBufferSizeOut);
		}
				
		HOOK_DECL(GetResultTimestamp, 3, uint32, SteamInventoryResult_t resultHandle)
		{
			Util::Debug::PrintLine("GetResultTimestamp!");

			return GetResultTimestampOriginal(This, resultHandle);
		}
				
		HOOK_DECL(CheckResultSteamID, 4, bool, SteamInventoryResult_t resultHandle, CSteamID steamIDExpected)
		{
			Util::Debug::PrintLine("CheckResultSteamID!");

			return CheckResultSteamIDOriginal(This, resultHandle, steamIDExpected);
		}
				
		HOOK_DECL(DestroyResult, 5, void, SteamInventoryResult_t resultHandle)
		{
			Util::Debug::PrintLine("DestroyResult!");

			return DestroyResultOriginal(This, resultHandle);
		}
				
		HOOK_DECL(GetAllItems, 6, bool, SteamInventoryResult_t *pResultHandle)
		{
			Util::Debug::PrintLine("GetAllItems!");

			return GetAllItemsOriginal(This, pResultHandle);
		}
				
		HOOK_DECL(GetItemsByID, 7, bool, SteamInventoryResult_t *pResultHandle,  const SteamItemInstanceID_t *pInstanceIDs, uint32 unCountInstanceIDs)
		{
			Util::Debug::PrintLine("GetItemsByID!");

			return GetItemsByIDOriginal(This, pResultHandle, pInstanceIDs, unCountInstanceIDs);
		}
				
		HOOK_DECL(SerializeResult, 8, bool, SteamInventoryResult_t resultHandle,  void *pOutBuffer, uint32 *punOutBufferSize)
		{
			Util::Debug::PrintLine("SerializeResult!");

			return SerializeResultOriginal(This, resultHandle, pOutBuffer, punOutBufferSize);
		}
				
		HOOK_DECL(DeserializeResult, 9, bool, SteamInventoryResult_t *pOutResultHandle, BUFFER_COUNT(punOutBufferSize)
		{
			Util::Debug::PrintLine("DeserializeResult!");

			return DeserializeResultOriginal(This, pOutResultHandle, BUFFER_COUNT(punOutBufferSize);
		}
				
		HOOK_DECL(GenerateItems, 10, bool, SteamInventoryResult_t *pResultHandle,  const SteamItemDef_t *pArrayItemDefs,  const uint32 *punArrayQuantity, uint32 unArrayLength)
		{
			Util::Debug::PrintLine("GenerateItems!");

			return GenerateItemsOriginal(This, pResultHandle, pArrayItemDefs, punArrayQuantity, unArrayLength);
		}
				
		HOOK_DECL(GrantPromoItems, 11, bool, SteamInventoryResult_t *pResultHandle)
		{
			Util::Debug::PrintLine("GrantPromoItems!");

			return GrantPromoItemsOriginal(This, pResultHandle);
		}
				
		HOOK_DECL(AddPromoItem, 12, bool, SteamInventoryResult_t *pResultHandle, SteamItemDef_t itemDef)
		{
			Util::Debug::PrintLine("AddPromoItem!");

			return AddPromoItemOriginal(This, pResultHandle, itemDef);
		}
				
		HOOK_DECL(AddPromoItems, 13, bool, SteamInventoryResult_t *pResultHandle,  const SteamItemDef_t *pArrayItemDefs, uint32 unArrayLength)
		{
			Util::Debug::PrintLine("AddPromoItems!");

			return AddPromoItemsOriginal(This, pResultHandle, pArrayItemDefs, unArrayLength);
		}
				
		HOOK_DECL(ConsumeItem, 14, bool, SteamInventoryResult_t *pResultHandle, SteamItemInstanceID_t itemConsume, uint32 unQuantity)
		{
			Util::Debug::PrintLine("ConsumeItem!");

			return ConsumeItemOriginal(This, pResultHandle, itemConsume, unQuantity);
		}
				
		HOOK_DECL(ExchangeItems, 15, bool, SteamInventoryResult_t *pResultHandle,
								 const SteamItemDef_t *pArrayGenerate,  const uint32 *punArrayGenerateQuantity, uint32 unArrayGenerateLength,
								 const SteamItemInstanceID_t *pArrayDestroy,  const uint32 *punArrayDestroyQuantity, uint32 unArrayDestroyLength)
		{
			Util::Debug::PrintLine("ExchangeItems!");

			return ExchangeItemsOriginal(This, pResultHandle, pArrayGenerate, punArrayGenerateQuantity, unArrayGenerateLength, pArrayDestroy, punArrayDestroyQuantity, unArrayDestroyLength);
		}
				
		HOOK_DECL(TransferItemQuantity, 16, bool, SteamInventoryResult_t *pResultHandle, SteamItemInstanceID_t itemIdSource, uint32 unQuantity, SteamItemInstanceID_t itemIdDest)
		{
			Util::Debug::PrintLine("TransferItemQuantity!");

			return TransferItemQuantityOriginal(This, pResultHandle, itemIdSource, unQuantity, itemIdDest);
		}
				
		HOOK_DECL(SendItemDropHeartbeat, 17, void)
		{
			Util::Debug::PrintLine("SendItemDropHeartbeat!");

			return SendItemDropHeartbeatOriginal(This);
		}
				
		HOOK_DECL(TriggerItemDrop, 18, bool, SteamInventoryResult_t *pResultHandle, SteamItemDef_t dropListDefinition)
		{
			Util::Debug::PrintLine("TriggerItemDrop!");

			return TriggerItemDropOriginal(This, pResultHandle, dropListDefinition);
		}
				
		HOOK_DECL(TradeItems, 19, bool, SteamInventoryResult_t *pResultHandle, CSteamID steamIDTradePartner,
							  const SteamItemInstanceID_t *pArrayGive,  const uint32 *pArrayGiveQuantity, uint32 nArrayGiveLength,
							  const SteamItemInstanceID_t *pArrayGet,  const uint32 *pArrayGetQuantity, uint32 nArrayGetLength)
		{
			Util::Debug::PrintLine("TradeItems!");

			return TradeItemsOriginal(This, pResultHandle, steamIDTradePartner, pArrayGive, pArrayGiveQuantity, nArrayGiveLength, pArrayGet, pArrayGetQuantity, nArrayGetLength);
		}
				
		HOOK_DECL(LoadItemDefinitions, 20, bool)
		{
			Util::Debug::PrintLine("LoadItemDefinitions!");

			return LoadItemDefinitionsOriginal(This);
		}
				
		HOOK_DECL(GetItemDefinitionIDs, 21, bool, SteamItemDef_t *pItemDefIDs,
				DESC(Size of array is passed in and actual size used is returned in this param)
		{
			Util::Debug::PrintLine("GetItemDefinitionIDs!");

			return GetItemDefinitionIDsOriginal(This, pItemDefIDs, param);
		}
				
		HOOK_DECL(GetItemDefinitionProperty, 22, bool, SteamItemDef_t iDefinition, const char *pchPropertyName,
		 char *pchValueBuffer, uint32 *punValueBufferSizeOut)
		{
			Util::Debug::PrintLine("GetItemDefinitionProperty!");

			return GetItemDefinitionPropertyOriginal(This, iDefinition, pchPropertyName, pchValueBuffer, punValueBufferSizeOut);
		}
				
		HOOK_DECL(RequestEligiblePromoItemDefinitionsIDs, 23, SteamAPICall_t, CSteamID steamID)
		{
			Util::Debug::PrintLine("RequestEligiblePromoItemDefinitionsIDs!");

			return RequestEligiblePromoItemDefinitionsIDsOriginal(This, steamID);
		}
				
		HOOK_DECL(GetEligiblePromoItemDefinitionIDs, 24, bool, CSteamID steamID,
		 SteamItemDef_t *pItemDefIDs,
		DESC(Size of array is passed in and actual size used is returned in this param)
		{
			Util::Debug::PrintLine("GetEligiblePromoItemDefinitionIDs!");

			return GetEligiblePromoItemDefinitionIDsOriginal(This, steamID, pItemDefIDs, param);
		}
				
		HOOK_DECL(StartPurchase, 25, SteamAPICall_t, const SteamItemDef_t *pArrayItemDefs,  const uint32 *punArrayQuantity, uint32 unArrayLength)
		{
			Util::Debug::PrintLine("StartPurchase!");

			return StartPurchaseOriginal(This, pArrayItemDefs, punArrayQuantity, unArrayLength);
		}
				
		HOOK_DECL(RequestPrices, 26, SteamAPICall_t)
		{
			Util::Debug::PrintLine("RequestPrices!");

			return RequestPricesOriginal(This);
		}
				
		HOOK_DECL(GetNumItemsWithPrices, 27, uint32)
		{
			Util::Debug::PrintLine("GetNumItemsWithPrices!");

			return GetNumItemsWithPricesOriginal(This);
		}
				
		HOOK_DECL(GetItemsWithPrices, 28, bool, SteamItemDef_t *pArrayItemDefs,
									   uint64 *pPrices,
									 uint32 unArrayLength)
		{
			Util::Debug::PrintLine("GetItemsWithPrices!");

			return GetItemsWithPricesOriginal(This, pArrayItemDefs, pPrices, unArrayLength);
		}
				
		HOOK_DECL(GetItemPrice, 29, bool, SteamItemDef_t iDefinition, uint64 *pPrice)
		{
			Util::Debug::PrintLine("GetItemPrice!");

			return GetItemPriceOriginal(This, iDefinition, pPrice);
		}
				
		HOOK_DECL(StartUpdateProperties, 30, SteamInventoryUpdateHandle_t)
		{
			Util::Debug::PrintLine("StartUpdateProperties!");

			return StartUpdatePropertiesOriginal(This);
		}
				
		HOOK_DECL(RemoveProperty, 31, bool, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char *pchPropertyName)
		{
			Util::Debug::PrintLine("RemoveProperty!");

			return RemovePropertyOriginal(This, handle, nItemID, pchPropertyName);
		}
				
		HOOK_DECL(SetProperty, 32, bool, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char *pchPropertyName, const char *pchPropertyValue)
		{
			Util::Debug::PrintLine("SetProperty!");

			return SetPropertyOriginal(This, handle, nItemID, pchPropertyName, pchPropertyValue);
		}
				
		HOOK_DECL(SetProperty, 33, bool, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char *pchPropertyName, bool bValue)
		{
			Util::Debug::PrintLine("SetProperty!");

			return SetPropertyOriginal(This, handle, nItemID, pchPropertyName, bValue);
		}
				
		HOOK_DECL(SetProperty, 34, bool, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char *pchPropertyName, int64 nValue)
		{
			Util::Debug::PrintLine("SetProperty!");

			return SetPropertyOriginal(This, handle, nItemID, pchPropertyName, nValue);
		}
				
		HOOK_DECL(SetProperty, 35, bool, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char *pchPropertyName, float flValue)
		{
			Util::Debug::PrintLine("SetProperty!");

			return SetPropertyOriginal(This, handle, nItemID, pchPropertyName, flValue);
		}
				
		HOOK_DECL(SubmitUpdateProperties, 36, bool, SteamInventoryUpdateHandle_t handle, SteamInventoryResult_t * pResultHandle)
		{
			Util::Debug::PrintLine("SubmitUpdateProperties!");

			return SubmitUpdatePropertiesOriginal(This, handle, pResultHandle);
		}
		
	};
}