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
	private:

		template < typename... Args >
		static std::string _FormatMessage(const std::string& prefix, const std::string& format, Args... args)
		{
			auto msgOut = std::string{};
			msgOut.reserve(512);

			auto fmt = (prefix + format + "\n");
			snprintf(msgOut.data(), msgOut.capacity(), fmt.c_str(), args...);

			return msgOut;
		}

		template < typename... Args >
		static void _PrintLinePrefixed(const std::string& prefix, const std::string& format, Args... args)
		{
#ifdef _DEBUG
			auto msgOut = _FormatMessage(prefix, format, args...);
			OutputDebugString(msgOut.c_str());
			printf("%s", msgOut.c_str());
#endif
		}
	public:
		template < typename... Args >
		static void PrintLine(const std::string& format, Args... args)
		{
			_PrintLinePrefixed("[DEBUG] ", format, args...);
		}

		template < typename... Args >
		static void Warning(const std::string& format, Args... args)
		{
			_PrintLinePrefixed("[WARNING] ", format, args...);
		}

		template < typename... Args >
		static void Error(const std::string& format, Args... args)
		{
			auto msgOut = _FormatMessage("[ERROR] ", format, args...);
			throw std::exception(msgOut.c_str());
		}

		static inline void HexDump(void* arr, const size_t size)
		{
			auto* ref = reinterpret_cast<unsigned char*>(arr);

			for (size_t i = 0; i < size; ++i)
			{
				printf("%02X ", ref[i]);
			}
			printf("\n");
		}
	};
}

