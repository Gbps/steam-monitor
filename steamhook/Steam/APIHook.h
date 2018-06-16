#pragma once

#include "stdafx.h"
#include <functional>
#include "MinHook.h"

namespace Steam
{
	class CApiHook
	{
	private:
		// Detour function to call for the hook
		void* m_Detour = nullptr;

		// Pointer to the location to put the original function pointer
		void** m_Original = nullptr;

		// Target function to hook
		void* m_Target = nullptr;

		// True if hooked
		bool m_Hooked = false;

	public:

		~CApiHook();
		CApiHook(const CApiHook&) = delete;
		CApiHook& operator=(const CApiHook&) = delete;
		CApiHook(CApiHook&&) = default;
		CApiHook& operator=(CApiHook&&) = default;

		/**
		 * \brief Initialize a hook's parameters but do not yet hook a function
		 * \param pDetour The target function to run before the execution of the original
		 * \param pOutOriginal Memory location to place the original function pointer to call from within the detour's context
		 */
		CApiHook(void* pDetour, void** pOutOriginal);

		/**
		 * \brief Initializes a hook and automatically hooks the target object on creation
		 * \param pTargetObject Target object with a virtual function table
		 * \param vtableidx The index in the virtual function table to hook
		 * \param pDetour The target function to run before the execution of the original
		 * \param pOutOriginal Memory location to place the original function pointer to call from within the detour's context
		 */
		CApiHook(void* pTargetObject, uint16_t vtableidx, void* pDetour, void** pOutOriginal);

		/**
		 * \brief Hook the target function. Does not enable the hook, instead call Enable
		 * \param pTarget The target function to hook
		 * \return True on success
		 */
		bool Hook(void* pTarget);

		/**
		 * \brief 
		 * \param pTargetObject Hook a virtual member function given an instance of the object and its vtable index
		 * \param vtableidx  The index in the virtual function table to hook
		 * \return True on success
		 */
		inline bool HookVirtual(void* pTargetObject, uint16_t vtableidx);

		
		/**
		 * \brief 
		 * \return Enables the hook. Must be called after a Hook* function.
		 */
		inline bool Enable() const;

		
		/**
		 * \brief 
		 * \return Disable the hook, to be re-enabled later
		 */
		inline bool Disable() const;

		
		/**
		 * \brief 
		 * \return Unhooks the function entirely and frees assoicated resources. Can be hooked again.
		 */
		inline bool UnHook() const;
	};

	inline CApiHook::~CApiHook()
	{
		auto unused = UnHook();
	}

	inline CApiHook::CApiHook(void* pDetour, void** pOutOriginal) : m_Detour(pDetour), m_Original(pOutOriginal)
	{
	}

	inline CApiHook::CApiHook(void* pTargetObject, const uint16_t vtableidx, void* pDetour, void** pOutOriginal) : CApiHook(pDetour, pOutOriginal)
	{
		HookVirtual(pTargetObject, vtableidx);
		auto unused = Enable();
	}

	inline bool CApiHook::Hook(void* pTarget)
	{
		if (m_Hooked)
			return true;

		MH_Initialize();

		m_Target = pTarget;

		Util::Debug::PrintLine("m_Target: %08X", m_Target);

		const auto res = MH_CreateHook(m_Target, m_Detour, m_Original);
		if (res != MH_OK)
		{
			Util::Debug::Warning("Failed MH_CreateHook");
			return false;
		}

		m_Hooked = true;
		return true;
	}

	inline bool CApiHook::HookVirtual(void* pTargetObject, uint16_t vtableidx)
	{
		auto** vtable = *reinterpret_cast<void***>(pTargetObject);
		auto* faddr = vtable[vtableidx];
		return Hook(faddr);
	}

	inline bool CApiHook::Enable() const
	{
		if (!m_Hooked)
		{
			return false;
		}

		if (MH_EnableHook(m_Target) != MH_OK)
		{
			Util::Debug::Warning("Failed MH_EnableHook");
			return false;
		}

		return true;
	}

	inline bool CApiHook::Disable() const
	{
		if (!m_Hooked)
		{
			return false;
		}

		if (MH_DisableHook(m_Target) != MH_OK)
		{
			Util::Debug::Warning("Failed MH_DisableHook on %s");
			return false;
		}

		return true;
	}

	inline bool CApiHook::UnHook() const
	{
		if (!m_Hooked)
		{
			return false;
		}

		if (!MH_RemoveHook(m_Target) != MH_OK) // NOLINT(readability-simplify-boolean-expr)
		{
			Util::Debug::Warning("Failed MH_RemoveHook on %s");
			return false;
		}
		return true;
	}
}
