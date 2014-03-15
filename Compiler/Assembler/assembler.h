#include "program.h"
#include "astack.h"
#include "Instruction.h"

#include "CByteStream/ByteStream.h"

#ifndef ___ASSEMBLER_H___
#define ___ASSEMBLER_H___

struct ByteStream *AssembleProgram(struct Program *program);

#endif