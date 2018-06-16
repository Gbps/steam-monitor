#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamMusic_Hooks : CHookManager<ISteamMusic>
	{

	public:
		ISteamMusic_Hooks() = delete;
		ISteamMusic_Hooks(ISteamMusic* obj) : CHookManager<ISteamMusic>(obj) {};

        		
		HOOK_DECL(BIsEnabled, 0, bool)
		{
			Util::Debug::PrintLine("BIsEnabled!");

			return BIsEnabledOriginal(This);
		}
				
		HOOK_DECL(BIsPlaying, 1, bool)
		{
			Util::Debug::PrintLine("BIsPlaying!");

			return BIsPlayingOriginal(This);
		}
				
		HOOK_DECL(GetPlaybackStatus, 2, AudioPlayback_Status)
		{
			Util::Debug::PrintLine("GetPlaybackStatus!");

			return GetPlaybackStatusOriginal(This);
		}
				
		HOOK_DECL(Play, 3, void)
		{
			Util::Debug::PrintLine("Play!");

			return PlayOriginal(This);
		}
				
		HOOK_DECL(Pause, 4, void)
		{
			Util::Debug::PrintLine("Pause!");

			return PauseOriginal(This);
		}
				
		HOOK_DECL(PlayPrevious, 5, void)
		{
			Util::Debug::PrintLine("PlayPrevious!");

			return PlayPreviousOriginal(This);
		}
				
		HOOK_DECL(PlayNext, 6, void)
		{
			Util::Debug::PrintLine("PlayNext!");

			return PlayNextOriginal(This);
		}
				
		HOOK_DECL(SetVolume, 7, void, float flVolume)
		{
			Util::Debug::PrintLine("SetVolume!");

			return SetVolumeOriginal(This, flVolume);
		}
				
		HOOK_DECL(GetVolume, 8, float)
		{
			Util::Debug::PrintLine("GetVolume!");

			return GetVolumeOriginal(This);
		}
		
	};
}