#include "Util/program.h"
#include "Common/astack.h"
#include "Common/Instruction.h"

#include "Common/CByteStream/ByteStream.h"

#ifndef ___ASSEMBLER_H___
#define ___ASSEMBLER_H___

struct ByteStream *AssembleProgram(struct Program *program);

#endif