#pragma once

#include "stdafx.h"
#include <functional>
#include "MinHook.h"
#include "Util/ExecutableAllocator.h"

namespace Steam
{
	

	// The executable stub that can be allocated to carry a pointer to the original hook function at runtime
	class CApiHookStub
	{
	private:
		#pragma pack(push,1)
		struct
		{
			unsigned char push;
			uint32_t arg0;
			unsigned char mov;
			uint32_t calltarget;
			unsigned char call;
			unsigned char eax;
			unsigned char add_esp_ret[5];
		} shellcode{};

#pragma pack(pop)

	public:
		CApiHookStub(): shellcode()
		{
		}

		CApiHookStub(uint32_t calltarget, uint32_t arg0);

		// Get the address to the call stub to call
		inline auto* GetStubPtr()
		{
			return &shellcode;
		}

		// Set the call target to call
		inline void SetCallTarget(void* target)
		{
			shellcode.calltarget = reinterpret_cast<uint32_t>(target);
		}

		// Set the argument
		inline void SetArgument(void* arg)
		{
			shellcode.arg0 = reinterpret_cast<uint32_t>(arg);
		}
	};

	inline CApiHookStub::CApiHookStub(uint32_t calltarget, uint32_t arg0)
	{
		/*
		  0 : 68 78 56 34 12          push   _arg0
		  2 : b8 78 56 34 12          mov    eax, _calltarget
		  7 : ff d0                   call   eax
		  9 : 83 c4 04                add    esp, 0x4
		  c : c3                      ret
		*/
		shellcode = {0x68, arg0, 0xb8, calltarget, 0xff, 0xd0, {0x83, 0xc4, 0x04, 0xc3}};
	}

	class CApiHookGlobals
	{
	public:

		// Uses the executable allocator instead of the default std::allocator
		using StubAllocator = std::vector<CApiHookStub, Util::ExecutableAllocator<CApiHookStub>>;

		// Number of payload objects to allocate on initialization. Can grow after that. 
		static const unsigned int DefaultHookNumber = 100;

		// Is the allocator allocated?
		static inline bool Initialized;

		// std::vector that can allocate executable pages
		static inline StubAllocator Allocator;
		
		// Initalize the APIHook globals
		static inline void Initialize()
		{
			if (!Initialized)
			{
				Allocator = StubAllocator{ DefaultHookNumber };
				Initialized = true;
			}
		}

		static inline auto* MakeStub(void* callTarget, void* firstArgument)
		{
			// Create new stub that will have firstArgument as first argument and callTarget as the function to call
			auto&& stub = CApiHookStub{ reinterpret_cast<uint32_t>(callTarget), reinterpret_cast<uint32_t>(firstArgument) };

			// Alloate an executable stub address
			auto* obj = &CApiHookGlobals::Allocator.emplace_back(stub);

			return obj;
		}
	};

	class CApiHook
	{
	private:
		// Original function pointer to call inside detour
		void* m_Original = nullptr;

		// Detour function to call for the hook
		void* m_Detour = nullptr;

		// Target function to hook
		void* m_Target = nullptr;

		// True if hooked
		bool m_Hooked = false;

		// Stub to use for argument capture
		CApiHookStub* m_Stub{};

		// Name of the hook
		std::string m_Name;

	public:

		CApiHook(const CApiHook&) = delete;
		CApiHook& operator=(const CApiHook&) = delete;
		CApiHook(CApiHook&&) = delete;
		CApiHook& operator=(CApiHook&&) = delete;

		~CApiHook()
		{
			// We leak our call stub here but there's not much we can do about that when using std::vector
			UnHook();
		}

		explicit CApiHook(const std::string& name)
		{
			CApiHookGlobals::Initialize();
			m_Name = name;
			m_Stub = CApiHookGlobals::MakeStub(nullptr, nullptr);
		}

		inline bool Hook(void* pTarget, void* hookFunction)
		{
			if (m_Hooked) 
				return true;

			if (MH_Initialize() != MH_OK)
			{
				Util::Debug::Warning("Failed MH_Initialize");
				return false;
			}

			m_Target = pTarget;
			m_Detour = hookFunction;

			m_Stub->SetCallTarget(m_Detour);

			const auto res = MH_CreateHook(m_Target, m_Stub->GetStubPtr(), static_cast<LPVOID *>(&m_Original));
			if (res != MH_OK)
			{
				Util::Debug::Warning("Failed MH_Createhook on %s", m_Name.c_str());
				return false;
			}

			m_Stub->SetArgument(m_Original);

			m_Hooked = true;
			return true;
		}

		inline bool Enable() const
		{
			if (!m_Hooked)
			{
				return false;
			}

			if (MH_EnableHook(m_Target) != MH_OK)
			{
				Util::Debug::Warning("Failed MH_EnableHook on %s", m_Name.c_str());
				return false;
			}

			return true;
		}

		inline bool Disable() const
		{
			if (!m_Hooked)
			{
				return false;
			}

			if (MH_DisableHook(m_Target) != MH_OK)
			{
				Util::Debug::Warning("Failed MH_DisableHook on %s", m_Name.c_str());
				return false;
			}

			return true;
		}

		inline bool UnHook() const
		{
			if (!MH_RemoveHook(m_Target) != MH_OK)  // NOLINT(readability-simplify-boolean-expr)
			{
				Util::Debug::Warning("Failed MH_RemoveHook on %s", m_Name.c_str());
				return false;
			}

			return true;
		}
	};
}