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
