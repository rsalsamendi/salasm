/*
	Copyright (c) 2013 Ryan Salsamendi

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.
*/
#ifndef __SALSASM_TYPES__
#define __SALSASM_TYPES__

#include "salsasm.h"

typedef union ModRmByte
{
	struct
	{
		uint8_t rm : 3;
		uint8_t reg : 3;
		uint8_t mod : 2;
	};
	uint8_t byte;
} ModRmByte;

typedef union RexByte
{
	struct
	{
		uint8_t b : 1;
		uint8_t x : 1;
		uint8_t r : 1;
		uint8_t w : 1;
		uint8_t rex : 4;
	};
	uint8_t byte;
} RexByte;

typedef union SIBByte
{
	struct
	{
		uint8_t base : 3;
		uint8_t index : 3;
		uint8_t scale : 2;
	};
	uint8_t byte;
} SibByte;

typedef enum SecondaryOpCodeTable
{
	SECONDARY_TABLE_NORMAL = 0,
	SECONDARY_TABLE_F3 = 1,
	SECONDARY_TABLE_66 = 2,
	SECONDARY_TABLE_F2 = 3
} SecondaryOpCodeTable;

typedef enum X86DecoderMode
{
	X86_16BIT = 0,
	X86_32BIT = 1,
	X86_64BIT = 2
} X86DecoderMode;

typedef struct X86DecoderState
{
	X86Instruction* instr;
	InstructionFetchCallback fetch;
	void* ctxt;
	X86DecoderMode mode;
	X86DecoderMode addrMode;
	X86DecoderMode operandMode;
	RexByte rex;
	uint8_t currentByte;
	SecondaryOpCodeTable secondaryTable;
} X86DecoderState;

#endif /* __SALSASM_TYPES__ */
