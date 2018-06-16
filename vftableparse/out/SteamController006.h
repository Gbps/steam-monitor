#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamController_Hooks : CHookManager<ISteamController>
	{

	public:
		ISteamController_Hooks() = delete;
		ISteamController_Hooks(ISteamController* obj) : CHookManager<ISteamController>(obj) {};

        		
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
				
		HOOK_DECL(RunFrame, 2, void)
		{
			Util::Debug::PrintLine("RunFrame!");

			return RunFrameOriginal(This);
		}
				
		HOOK_DECL(GetConnectedControllers, 3, int, ControllerHandle_t *handlesOut)
		{
			Util::Debug::PrintLine("GetConnectedControllers!");

			return GetConnectedControllersOriginal(This, handlesOut);
		}
				
		HOOK_DECL(ShowBindingPanel, 4, bool, ControllerHandle_t controllerHandle)
		{
			Util::Debug::PrintLine("ShowBindingPanel!");

			return ShowBindingPanelOriginal(This, controllerHandle);
		}
				
		HOOK_DECL(GetActionSetHandle, 5, ControllerActionSetHandle_t, const char *pszActionSetName)
		{
			Util::Debug::PrintLine("GetActionSetHandle!");

			return GetActionSetHandleOriginal(This, pszActionSetName);
		}
				
		HOOK_DECL(ActivateActionSet, 6, void, ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle)
		{
			Util::Debug::PrintLine("ActivateActionSet!");

			return ActivateActionSetOriginal(This, controllerHandle, actionSetHandle);
		}
				
		HOOK_DECL(GetCurrentActionSet, 7, ControllerActionSetHandle_t, ControllerHandle_t controllerHandle)
		{
			Util::Debug::PrintLine("GetCurrentActionSet!");

			return GetCurrentActionSetOriginal(This, controllerHandle);
		}
				
		HOOK_DECL(ActivateActionSetLayer, 8, void, ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetLayerHandle)
		{
			Util::Debug::PrintLine("ActivateActionSetLayer!");

			return ActivateActionSetLayerOriginal(This, controllerHandle, actionSetLayerHandle);
		}
				
		HOOK_DECL(DeactivateActionSetLayer, 9, void, ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetLayerHandle)
		{
			Util::Debug::PrintLine("DeactivateActionSetLayer!");

			return DeactivateActionSetLayerOriginal(This, controllerHandle, actionSetLayerHandle);
		}
				
		HOOK_DECL(DeactivateAllActionSetLayers, 10, void, ControllerHandle_t controllerHandle)
		{
			Util::Debug::PrintLine("DeactivateAllActionSetLayers!");

			return DeactivateAllActionSetLayersOriginal(This, controllerHandle);
		}
				
		HOOK_DECL(GetActiveActionSetLayers, 11, int, ControllerHandle_t controllerHandle, ControllerActionSetHandle_t *handlesOut)
		{
			Util::Debug::PrintLine("GetActiveActionSetLayers!");

			return GetActiveActionSetLayersOriginal(This, controllerHandle, handlesOut);
		}
				
		HOOK_DECL(GetDigitalActionHandle, 12, ControllerDigitalActionHandle_t, const char *pszActionName)
		{
			Util::Debug::PrintLine("GetDigitalActionHandle!");

			return GetDigitalActionHandleOriginal(This, pszActionName);
		}
				
		HOOK_DECL(GetDigitalActionData, 13, ControllerDigitalActionData_t, ControllerHandle_t controllerHandle, ControllerDigitalActionHandle_t digitalActionHandle)
		{
			Util::Debug::PrintLine("GetDigitalActionData!");

			return GetDigitalActionDataOriginal(This, controllerHandle, digitalActionHandle);
		}
				
		HOOK_DECL(GetDigitalActionOrigins, 14, int, ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle, ControllerDigitalActionHandle_t digitalActionHandle, EControllerActionOrigin *originsOut)
		{
			Util::Debug::PrintLine("GetDigitalActionOrigins!");

			return GetDigitalActionOriginsOriginal(This, controllerHandle, actionSetHandle, digitalActionHandle, originsOut);
		}
				
		HOOK_DECL(GetAnalogActionHandle, 15, ControllerAnalogActionHandle_t, const char *pszActionName)
		{
			Util::Debug::PrintLine("GetAnalogActionHandle!");

			return GetAnalogActionHandleOriginal(This, pszActionName);
		}
				
		HOOK_DECL(GetAnalogActionData, 16, ControllerAnalogActionData_t, ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t analogActionHandle)
		{
			Util::Debug::PrintLine("GetAnalogActionData!");

			return GetAnalogActionDataOriginal(This, controllerHandle, analogActionHandle);
		}
				
		HOOK_DECL(GetAnalogActionOrigins, 17, int, ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle, ControllerAnalogActionHandle_t analogActionHandle, EControllerActionOrigin *originsOut)
		{
			Util::Debug::PrintLine("GetAnalogActionOrigins!");

			return GetAnalogActionOriginsOriginal(This, controllerHandle, actionSetHandle, analogActionHandle, originsOut);
		}
				
		HOOK_DECL(StopAnalogActionMomentum, 18, void, ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t eAction)
		{
			Util::Debug::PrintLine("StopAnalogActionMomentum!");

			return StopAnalogActionMomentumOriginal(This, controllerHandle, eAction);
		}
				
		HOOK_DECL(TriggerHapticPulse, 19, void, ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec)
		{
			Util::Debug::PrintLine("TriggerHapticPulse!");

			return TriggerHapticPulseOriginal(This, controllerHandle, eTargetPad, usDurationMicroSec);
		}
				
		HOOK_DECL(TriggerRepeatedHapticPulse, 20, void, ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec, unsigned short usOffMicroSec, unsigned short unRepeat, unsigned int nFlags)
		{
			Util::Debug::PrintLine("TriggerRepeatedHapticPulse!");

			return TriggerRepeatedHapticPulseOriginal(This, controllerHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags);
		}
				
		HOOK_DECL(TriggerVibration, 21, void, ControllerHandle_t controllerHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed)
		{
			Util::Debug::PrintLine("TriggerVibration!");

			return TriggerVibrationOriginal(This, controllerHandle, usLeftSpeed, usRightSpeed);
		}
				
		HOOK_DECL(SetLEDColor, 22, void, ControllerHandle_t controllerHandle, uint8 nColorR, uint8 nColorG, uint8 nColorB, unsigned int nFlags)
		{
			Util::Debug::PrintLine("SetLEDColor!");

			return SetLEDColorOriginal(This, controllerHandle, nColorR, nColorG, nColorB, nFlags);
		}
				
		HOOK_DECL(GetGamepadIndexForController, 23, int, ControllerHandle_t ulControllerHandle)
		{
			Util::Debug::PrintLine("GetGamepadIndexForController!");

			return GetGamepadIndexForControllerOriginal(This, ulControllerHandle);
		}
				
		HOOK_DECL(GetControllerForGamepadIndex, 24, ControllerHandle_t, int nIndex)
		{
			Util::Debug::PrintLine("GetControllerForGamepadIndex!");

			return GetControllerForGamepadIndexOriginal(This, nIndex);
		}
				
		HOOK_DECL(GetMotionData, 25, ControllerMotionData_t, ControllerHandle_t controllerHandle)
		{
			Util::Debug::PrintLine("GetMotionData!");

			return GetMotionDataOriginal(This, controllerHandle);
		}
				
		HOOK_DECL(ShowDigitalActionOrigins, 26, bool, ControllerHandle_t controllerHandle, ControllerDigitalActionHandle_t digitalActionHandle, float flScale, float flXPosition, float flYPosition)
		{
			Util::Debug::PrintLine("ShowDigitalActionOrigins!");

			return ShowDigitalActionOriginsOriginal(This, controllerHandle, digitalActionHandle, flScale, flXPosition, flYPosition);
		}
				
		HOOK_DECL(ShowAnalogActionOrigins, 27, bool, ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t analogActionHandle, float flScale, float flXPosition, float flYPosition)
		{
			Util::Debug::PrintLine("ShowAnalogActionOrigins!");

			return ShowAnalogActionOriginsOriginal(This, controllerHandle, analogActionHandle, flScale, flXPosition, flYPosition);
		}
				
		HOOK_DECL(GetStringForActionOrigin, 28, const char *, EControllerActionOrigin eOrigin)
		{
			Util::Debug::PrintLine("GetStringForActionOrigin!");

			return GetStringForActionOriginOriginal(This, eOrigin);
		}
				
		HOOK_DECL(GetGlyphForActionOrigin, 29, const char *, EControllerActionOrigin eOrigin)
		{
			Util::Debug::PrintLine("GetGlyphForActionOrigin!");

			return GetGlyphForActionOriginOriginal(This, eOrigin);
		}
				
		HOOK_DECL(GetInputTypeForHandle, 30, ESteamInputType, ControllerHandle_t controllerHandle)
		{
			Util::Debug::PrintLine("GetInputTypeForHandle!");

			return GetInputTypeForHandleOriginal(This, controllerHandle);
		}
		
	};
}