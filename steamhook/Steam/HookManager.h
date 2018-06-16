#pragma once

#include "stdafx.h"
#include "Steam/APIHook.h"

namespace Steam
{
	template<typename T>
	class CHookManager
	{
	protected:
		// Instance of the object we're hooking
		void* m_Instance = nullptr;

	private:

	public:
		explicit CHookManager(T* instance) : m_Instance(instance) {};

	};

}

#define HOOK_DECL(NAME, VFTABLEIDX, RET, ...) \
	inline static RET (__thiscall* NAME##Original) ( void* This, __VA_ARGS__ ) = nullptr; \
	CApiHook NAME##Hook{ m_Instance, VFTABLEIDX, __##NAME##_Detour, reinterpret_cast<void**>(& NAME##Original) }; \
	inline static RET __fastcall __##NAME##_Detour( void* This, void* __unused, __VA_ARGS__ )
