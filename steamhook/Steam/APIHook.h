#pragma once

#include "stdafx.h"
#include <functional>
#include "MinHook.h"
#include "Util/ExecutableAllocator.h"

namespace Steam
{
	

	// The executable stub that can be allocated to carry a pointer to the original hook function at runtime
	class APIHookStub
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
		} shellcode;
		#pragma pack(pop)

	public:
		APIHookStub()
		{

		}

		APIHookStub(uint32_t _calltarget, uint32_t _arg0)
		{
			/*
			  0 : 68 78 56 34 12          push   _arg0
			  2 : b8 78 56 34 12          mov    eax, _calltarget
			  7 : ff d0                   call   eax
			  9 : 83 c4 04                add    esp, 0x4
			  c : c3                      ret
			*/
			shellcode = { 0x68, _arg0, 0xb8, _calltarget, 0xff, 0xd0, {0x83, 0xc4, 0x04, 0xc3} };
		}

		// Get the address to the call stub to call
		inline auto* GetStubPtr()
		{
			return &shellcode;
		}

		// Set the call target to call
		inline void SetCallTarget(void* target)
		{
			shellcode.calltarget = (uint32_t)target;
		}

		// Set the argument
		inline void SetArgument(void* arg)
		{
			shellcode.arg0 = (uint32_t)arg;
		}


	};

	class APIHookGlobals
	{
	public:

		// Uses the executable allocator instead of the default std::allocator
		using StubAllocator = std::vector<APIHookStub, Util::ExecutableAllocator<APIHookStub>>;

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
			auto&& stub = APIHookStub{ (uint32_t)callTarget, (uint32_t)firstArgument };

			// Alloate an executable stub address
			auto* obj = &APIHookGlobals::Allocator.emplace_back(stub);

			return obj;
		}
	};

	class APIHook
	{
	private:
		// Original function pointer to call inside detour
		void* m_Original = NULL;

		// Detour function to call for the hook
		void* m_Detour = NULL;

		// Target function to hook
		void* m_Target = NULL;

		// True if hooked
		bool m_Hooked = false;

		// Stub to use for argument capture
		APIHookStub* m_Stub;

		// Name of the hook
		std::string m_Name;

	public:

		APIHook(const APIHook&) = delete;
		APIHook& operator=(const APIHook&) = delete;
		APIHook(APIHook&&) = delete;
		APIHook& operator=(APIHook&&) = delete;

		~APIHook()
		{
			// We leak our call stub here but there's not much we can do about that when using std::vector
			UnHook();
		}

		APIHook(const std::string& name)
		{
			APIHookGlobals::Initialize();
			m_Name = name;
			m_Stub = APIHookGlobals::MakeStub(0, 0);
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

			auto res = MH_CreateHook(m_Target, m_Stub->GetStubPtr(), (LPVOID *)&m_Original);
			if (res != MH_OK)
			{
				Util::Debug::Warning("Failed MH_Createhook on %s", m_Name.c_str());
				return false;
			}

			m_Stub->SetArgument(m_Original);

			m_Hooked = true;
			return true;
		}

		inline bool Enable()
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

		inline bool Disable()
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

		inline bool UnHook()
		{
			if (!MH_RemoveHook(m_Target) != MH_OK)
			{
				Util::Debug::Warning("Failed MH_RemoveHook on %s", m_Name.c_str());
				return false;
			}

			return true;
		}
	};
}