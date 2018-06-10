#pragma once

#include "stdafx.h"
#include <map>

namespace Steam
{
	using SteamInterface = void*;

	using SteamInterfaceMap = std::map<std::string, SteamInterface>;

	// Resolves SteamAPI interface objects from static or dynamic compilation
	// Often times games and applications will link to steam_api.dll -> steamclient.dll and resolve interfaces dynamically
	class CInterfaces
	{
	private:

		// Module for steamclient.dll, if a process doesn't have this, it's probably not using the steam api
		HMODULE m_SteamClient = nullptr;

		// Module for steam_api.dll, if a process doesn't have this, it's probably not using the steam api
		HMODULE m_SteamAPI = nullptr;

		// List of interfaces cached for reference
		SteamInterfaceMap m_Interfaces{};

		// Pointer to CreateInterface
		SteamInterface (__cdecl *m_CreateInterfaceFn)(const char* pName, int* pReturnCode) = nullptr;

		// Pointer to SteamAPI_GetHSteamUser
		HSteamUser (__cdecl *m_SteamAPI_GetHSteamUser)() = nullptr;
		
		// Pointer to SteamAPI_GetHSteamPipe
		HSteamPipe (__cdecl *m_SteamAPI_GetHSteamPipe)() = nullptr;

		// Local steam user handle for pipe connection
		HSteamUser m_SteamUserHandle = 0;

		// Steam pipe handle for pipe connection
		HSteamPipe m_SteamPipeHandle = 0;

		ISteamClient* m_ISteamClient = nullptr;

	public:

		// Connect to the local steam service
		inline bool InitSteamConnection()
		{
			m_SteamClient = ::GetModuleHandle("steamclient.dll");
			if (m_SteamClient == nullptr)
			{
				Util::Debug::Warning("Could not find steamclient.dll in this process");
				return false;
			}

			m_SteamAPI = ::GetModuleHandle("steam_api.dll");
			if (m_SteamAPI == nullptr)
			{
				Util::Debug::Warning("Could not find steam_api.dll in this process");
				return false;
			}

			Util::Debug::PrintLine("steamclient.dll @ 0x%08X", m_SteamClient);
			Util::Debug::PrintLine("steam_api.dll @ 0x%08X", m_SteamAPI);

			// CreateInterface
			if (!GetDLLProc(&m_CreateInterfaceFn, m_SteamClient, "CreateInterface"))
				return false;

			// SteamAPI_GetHSteamUser
			if (!GetDLLProc(&m_SteamAPI_GetHSteamUser, m_SteamAPI, "SteamAPI_GetHSteamUser"))
				return false;

			// SteamAPI_GetHSteamPipe
			if (!GetDLLProc(&m_SteamAPI_GetHSteamPipe, m_SteamAPI, "SteamAPI_GetHSteamPipe"))
				return false;

			m_SteamUserHandle = m_SteamAPI_GetHSteamUser();
			if (!m_SteamUserHandle)
			{
				Util::Debug::Warning("Failed to initialize HSteamUser, SteamAPI is not initialized yet");
				return false;
			}

			m_SteamPipeHandle = m_SteamAPI_GetHSteamPipe();
			if (!m_SteamPipeHandle)
			{
				Util::Debug::Warning("Failed to initialize HSteamPipe, SteamAPI is not initialized yet");
				return false;
			}
			

			return true;
		}

		// Get an interface directly from steam client
		inline SteamInterface GetSteamClientInterface(const char* inf)
		{
			const auto found = m_Interfaces.find(inf);
			if (found != m_Interfaces.end())
			{
				return found->second;
			}

			int iReturnCode;
			const auto inter = m_CreateInterfaceFn(inf, &iReturnCode);
			if (inter == nullptr)
			{
				Util::Debug::Warning("Failed to find interface '%s'", inf);
				return nullptr;
			}

			m_Interfaces[inf] = inter;

			return inter;
		}

		// GetProcAddress for steam DLLs
		template<typename T>
		static bool GetDLLProc(T* targetPtr, const HMODULE mod, const char* name)
		{
			auto res = ::GetProcAddress(mod, name);
			if (!res)
			{
				Util::Debug::Warning("GetProcAddress failed to find '%s'\n", name);
				return false;
			}

			*targetPtr = reinterpret_cast<T>(res);

			Util::Debug::PrintLine("%s @ 0x%08X", name, res);

			return true;
		}

		inline ISteamClient* GetISteamClient()
		{
			if (!m_ISteamClient)
			{
				m_ISteamClient = reinterpret_cast<ISteamClient*>(GetSteamClientInterface(STEAMCLIENT_INTERFACE_VERSION));
			}
			return m_ISteamClient;
		}

		inline HSteamPipe GetHSteamPipe() const
		{
			return m_SteamPipeHandle;
		}

		inline HSteamUser GetHSteamUser() const
		{
			return m_SteamUserHandle;
		}

		#define DEFINE_INTERFACE_FN(STEAMINTERFACECLASSNAME) \
			inline STEAMINTERFACECLASSNAME* Get##STEAMINTERFACECLASSNAME(const char* ver) \
			{ return GetISteamClient()->Get##STEAMINTERFACECLASSNAME(GetHSteamUser(), GetHSteamPipe(), ver); }

		DEFINE_INTERFACE_FN(ISteamUser);
		DEFINE_INTERFACE_FN(ISteamGameServer);
		DEFINE_INTERFACE_FN(ISteamFriends);
		DEFINE_INTERFACE_FN(ISteamMatchmaking);
		DEFINE_INTERFACE_FN(ISteamMatchmakingServers);
		DEFINE_INTERFACE_FN(ISteamUserStats);
		DEFINE_INTERFACE_FN(ISteamApps);
		DEFINE_INTERFACE_FN(ISteamNetworking);
		DEFINE_INTERFACE_FN(ISteamRemoteStorage);
		DEFINE_INTERFACE_FN(ISteamScreenshots);
		DEFINE_INTERFACE_FN(ISteamMusic);
		DEFINE_INTERFACE_FN(ISteamMusicRemote);
		DEFINE_INTERFACE_FN(ISteamGameServerStats);
		DEFINE_INTERFACE_FN(ISteamHTTP);
		DEFINE_INTERFACE_FN(ISteamController);
		DEFINE_INTERFACE_FN(ISteamUGC);
		DEFINE_INTERFACE_FN(ISteamAppList);
		DEFINE_INTERFACE_FN(ISteamHTMLSurface);
		DEFINE_INTERFACE_FN(ISteamInventory);
		DEFINE_INTERFACE_FN(ISteamVideo);
		DEFINE_INTERFACE_FN(ISteamParentalSettings);

	};
}