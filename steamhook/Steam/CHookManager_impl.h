#pragma once

#include "stdafx.h"
#include "Steam/APIHook.h"
#include "HookManager.h"

#define DETOUR_DECL(NAME, VFTABLEIDX, RET, ...) \
	CApiHook GetPersonaName{ m_Instance, VFTABLEIDX, NAME##_Detour }; \
	inline static RET NAME##_Detour( RET (*original)( __VA_ARGS__ ) )

namespace Steam
{
	class ISteamFriends_Hooks : CHookManager<ISteamFriends>
	{
	protected:

	private:

	public:
		ISteamFriends_Hooks() = delete;
		ISteamFriends_Hooks(ISteamFriends* obj) : CHookManager<ISteamFriends>(obj) {};


		DETOUR_DECL(GetPersonaName, 0, const char*, void)
		{
			Util::Debug::PrintLine("GetPersonaName!");
			// how the fuck am i going to do this
			return std::invoke(original, this);
		}

	};

}

#undef DETOUR_DECL