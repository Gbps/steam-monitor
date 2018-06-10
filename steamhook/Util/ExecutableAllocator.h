#pragma once

namespace Util
{
	template <typename T>
	class ExecutableAllocator
	{
	public:
		using value_type = T;

		ExecutableAllocator() = default;
		template <class U>
		ExecutableAllocator(const ExecutableAllocator<U>&) {}

		T* allocate(std::size_t n)
		{
			if (n <= std::numeric_limits<std::size_t>::max() / sizeof(T))
			{
				auto alloc = (size_t)::VirtualAlloc(NULL, n * sizeof(T), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
				if (alloc)
				{
					return reinterpret_cast<T*>(alloc);
				}
			}
			throw std::bad_alloc();
		}
		void deallocate(T* ptr, std::size_t n)
		{
			::VirtualFree(ptr, n * sizeof(T), MEM_FREE);
		}
	};

	template <typename T, typename U>
	inline bool operator == (const ExecutableAllocator<T>&, const ExecutableAllocator<U>&) {
		return true;
	}

	template <typename T, typename U>
	inline bool operator != (const ExecutableAllocator<T>& a, const ExecutableAllocator<U>& b) {
		return !(a == b);
	}
}
