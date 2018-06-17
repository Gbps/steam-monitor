#pragma once
#include <stdint.h>

#pragma comment(lib, "LDE64.lib")

namespace Util
{
	namespace LDE32
	{
		/**
		* \brief LDE64 Length Disassembler
		* \param lpData Pointer to instructions
		* \param size 0 for 32-bit, 64 for 64-bit
		* \return Size of disassembled instruction at lpData
		*/
		extern "C" size_t __stdcall LDE(const void* lpData, unsigned int size);

		/**
		 * \brief Skip a number of instructions using LDE
		 * \param lpData Pointer to instructions
		 * \param numInstructions Number of instructions to skip
		 * \return Pointer to the memory location directly after the skipped instructions
		 */
		inline void* SkipInstructions(void* lpData, int numInstructions)
		{
			auto* data = reinterpret_cast<char*>(lpData);

			for(int i = 0; i < numInstructions; i++)
			{
				data += LDE(data, 0);
			}

			return data;
		}

		/**
		* \brief Get the immediate value as a DWORD at location of instruction
		* \param lpData Pointer to instruction
		* \return Immediate value as a DWORD at location of instruction
		*/
		template<typename T>
		T GetImmediate(void* lpData)
		{
			auto* offset = static_cast<char*>(lpData) + 1;
			auto* cast = reinterpret_cast<T*>(offset);
			return *cast;
		}

		/**
		* \brief Get the immediate value as a DWORD at location of a mov r32, imm32 instruction
		* \param lpData Pointer to instruction
		* \return Immediate value as a DWORD at location of instruction
		*/
		template<typename T>
		T GetImmediate2(void* lpData)
		{
			auto* offset = static_cast<char*>(lpData) + 2;
			auto* cast = reinterpret_cast<T*>(offset);
			return *cast;
		}

		/**
		* \brief Get the address value of immediate from a jmp instruction
		* \param lpJump Pointer to jmp instruction
		* \return Absolute address of DWORD at location of instruction
		*/
		inline void* GetImmediateJumpAddress(void* lpJump)
		{
			const auto imm = GetImmediate<int>(lpJump);
			const auto res = reinterpret_cast<size_t>(lpJump) + imm + LDE(lpJump, 0);
			return reinterpret_cast<void*>(res);
		}

		/**
		 * \brief Get the address of a immediate from a mov instruction
		 * \param lpMov Pointer to mov r32, imm32 instruction
		 * \return DWORD value of imm32
		 */
		template<typename T>
		inline T GetMovImm32(void* lpMov)
		{
			const auto imm = GetImmediate2<size_t>(lpMov);
			return reinterpret_cast<T>(imm);
		}
	}
	


}
