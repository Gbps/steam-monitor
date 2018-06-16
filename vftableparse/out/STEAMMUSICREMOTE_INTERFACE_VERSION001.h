#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamMusicRemote_Hooks : CHookManager<ISteamMusicRemote>
	{

	public:
		ISteamMusicRemote_Hooks() = delete;
		ISteamMusicRemote_Hooks(ISteamMusicRemote* obj) : CHookManager<ISteamMusicRemote>(obj) {};

        		
		HOOK_DECL(RegisterSteamMusicRemote, 0, bool, const char *pchName)
		{
			Util::Debug::PrintLine("RegisterSteamMusicRemote!");

			return RegisterSteamMusicRemoteOriginal(This, pchName);
		}
				
		HOOK_DECL(DeregisterSteamMusicRemote, 1, bool)
		{
			Util::Debug::PrintLine("DeregisterSteamMusicRemote!");

			return DeregisterSteamMusicRemoteOriginal(This);
		}
				
		HOOK_DECL(BIsCurrentMusicRemote, 2, bool)
		{
			Util::Debug::PrintLine("BIsCurrentMusicRemote!");

			return BIsCurrentMusicRemoteOriginal(This);
		}
				
		HOOK_DECL(BActivationSuccess, 3, bool, bool bValue)
		{
			Util::Debug::PrintLine("BActivationSuccess!");

			return BActivationSuccessOriginal(This, bValue);
		}
				
		HOOK_DECL(SetDisplayName, 4, bool, const char *pchDisplayName)
		{
			Util::Debug::PrintLine("SetDisplayName!");

			return SetDisplayNameOriginal(This, pchDisplayName);
		}
				
		HOOK_DECL(SetPNGIcon_64x64, 5, bool, void *pvBuffer, uint32 cbBufferLength)
		{
			Util::Debug::PrintLine("SetPNGIcon_64x64!");

			return SetPNGIcon_64x64Original(This, pvBuffer, cbBufferLength);
		}
				
		HOOK_DECL(EnablePlayPrevious, 6, bool, bool bValue)
		{
			Util::Debug::PrintLine("EnablePlayPrevious!");

			return EnablePlayPreviousOriginal(This, bValue);
		}
				
		HOOK_DECL(EnablePlayNext, 7, bool, bool bValue)
		{
			Util::Debug::PrintLine("EnablePlayNext!");

			return EnablePlayNextOriginal(This, bValue);
		}
				
		HOOK_DECL(EnableShuffled, 8, bool, bool bValue)
		{
			Util::Debug::PrintLine("EnableShuffled!");

			return EnableShuffledOriginal(This, bValue);
		}
				
		HOOK_DECL(EnableLooped, 9, bool, bool bValue)
		{
			Util::Debug::PrintLine("EnableLooped!");

			return EnableLoopedOriginal(This, bValue);
		}
				
		HOOK_DECL(EnableQueue, 10, bool, bool bValue)
		{
			Util::Debug::PrintLine("EnableQueue!");

			return EnableQueueOriginal(This, bValue);
		}
				
		HOOK_DECL(EnablePlaylists, 11, bool, bool bValue)
		{
			Util::Debug::PrintLine("EnablePlaylists!");

			return EnablePlaylistsOriginal(This, bValue);
		}
				
		HOOK_DECL(UpdatePlaybackStatus, 12, bool, AudioPlayback_Status nStatus)
		{
			Util::Debug::PrintLine("UpdatePlaybackStatus!");

			return UpdatePlaybackStatusOriginal(This, nStatus);
		}
				
		HOOK_DECL(UpdateShuffled, 13, bool, bool bValue)
		{
			Util::Debug::PrintLine("UpdateShuffled!");

			return UpdateShuffledOriginal(This, bValue);
		}
				
		HOOK_DECL(UpdateLooped, 14, bool, bool bValue)
		{
			Util::Debug::PrintLine("UpdateLooped!");

			return UpdateLoopedOriginal(This, bValue);
		}
				
		HOOK_DECL(UpdateVolume, 15, bool, float flValue)
		{
			Util::Debug::PrintLine("UpdateVolume!");

			return UpdateVolumeOriginal(This, flValue);
		}
				
		HOOK_DECL(CurrentEntryWillChange, 16, bool)
		{
			Util::Debug::PrintLine("CurrentEntryWillChange!");

			return CurrentEntryWillChangeOriginal(This);
		}
				
		HOOK_DECL(CurrentEntryIsAvailable, 17, bool, bool bAvailable)
		{
			Util::Debug::PrintLine("CurrentEntryIsAvailable!");

			return CurrentEntryIsAvailableOriginal(This, bAvailable);
		}
				
		HOOK_DECL(UpdateCurrentEntryText, 18, bool, const char *pchText)
		{
			Util::Debug::PrintLine("UpdateCurrentEntryText!");

			return UpdateCurrentEntryTextOriginal(This, pchText);
		}
				
		HOOK_DECL(UpdateCurrentEntryElapsedSeconds, 19, bool, int nValue)
		{
			Util::Debug::PrintLine("UpdateCurrentEntryElapsedSeconds!");

			return UpdateCurrentEntryElapsedSecondsOriginal(This, nValue);
		}
				
		HOOK_DECL(UpdateCurrentEntryCoverArt, 20, bool, void *pvBuffer, uint32 cbBufferLength)
		{
			Util::Debug::PrintLine("UpdateCurrentEntryCoverArt!");

			return UpdateCurrentEntryCoverArtOriginal(This, pvBuffer, cbBufferLength);
		}
				
		HOOK_DECL(CurrentEntryDidChange, 21, bool)
		{
			Util::Debug::PrintLine("CurrentEntryDidChange!");

			return CurrentEntryDidChangeOriginal(This);
		}
				
		HOOK_DECL(QueueWillChange, 22, bool)
		{
			Util::Debug::PrintLine("QueueWillChange!");

			return QueueWillChangeOriginal(This);
		}
				
		HOOK_DECL(ResetQueueEntries, 23, bool)
		{
			Util::Debug::PrintLine("ResetQueueEntries!");

			return ResetQueueEntriesOriginal(This);
		}
				
		HOOK_DECL(SetQueueEntry, 24, bool, int nID, int nPosition, const char *pchEntryText)
		{
			Util::Debug::PrintLine("SetQueueEntry!");

			return SetQueueEntryOriginal(This, nID, nPosition, pchEntryText);
		}
				
		HOOK_DECL(SetCurrentQueueEntry, 25, bool, int nID)
		{
			Util::Debug::PrintLine("SetCurrentQueueEntry!");

			return SetCurrentQueueEntryOriginal(This, nID);
		}
				
		HOOK_DECL(QueueDidChange, 26, bool)
		{
			Util::Debug::PrintLine("QueueDidChange!");

			return QueueDidChangeOriginal(This);
		}
				
		HOOK_DECL(PlaylistWillChange, 27, bool)
		{
			Util::Debug::PrintLine("PlaylistWillChange!");

			return PlaylistWillChangeOriginal(This);
		}
				
		HOOK_DECL(ResetPlaylistEntries, 28, bool)
		{
			Util::Debug::PrintLine("ResetPlaylistEntries!");

			return ResetPlaylistEntriesOriginal(This);
		}
				
		HOOK_DECL(SetPlaylistEntry, 29, bool, int nID, int nPosition, const char *pchEntryText)
		{
			Util::Debug::PrintLine("SetPlaylistEntry!");

			return SetPlaylistEntryOriginal(This, nID, nPosition, pchEntryText);
		}
				
		HOOK_DECL(SetCurrentPlaylistEntry, 30, bool, int nID)
		{
			Util::Debug::PrintLine("SetCurrentPlaylistEntry!");

			return SetCurrentPlaylistEntryOriginal(This, nID);
		}
				
		HOOK_DECL(PlaylistDidChange, 31, bool)
		{
			Util::Debug::PrintLine("PlaylistDidChange!");

			return PlaylistDidChangeOriginal(This);
		}
		
	};
}