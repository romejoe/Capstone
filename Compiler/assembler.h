#include "Util/program.h"
#include "Common/astack.h"
#include "Common/Instruction.h"
#ifndef ___ASSEMBLER_H___
#define ___ASSEMBLER_H___

void AssembleProgram(struct Program *program, void **target, int *targetLength);

#endif