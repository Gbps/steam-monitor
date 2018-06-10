#pragma once

#include <string>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <sstream>

namespace Util
{
	class Debug
	{
	public:
		template < typename... Args >
		static void PrintLine(std::string format, Args... args)
		{
#ifdef _DEBUG
			printf(("[DEBUG] " + format + "\n").c_str(), args...);
#endif
		}

		template < typename... Args >
		static void Warning(std::string format, Args... args)
		{
#ifdef _DEBUG
			printf(("[WARNING] " + format + "\n").c_str(), args...);
#endif
		}

		template < typename... Args >
		static void Error(std::string format, Args... args)
		{
#ifdef _DEBUG
			std::string out = ("[ERROR] " + format + "\n");
			printf(out.c_str(), args...);
			throw std::exception(out.c_str());
#endif
		}

		static inline void HexDump(void* arr, size_t size)
		{
			std::stringstream ss;

			auto* ref = reinterpret_cast<unsigned char*>(arr);

			for (size_t i = 0; i < size; ++i)
			{
				printf("%02X ", ref[i]);
			}
			printf("\n");
		}
	};


}

