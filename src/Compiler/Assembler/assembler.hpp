#include <vector>
#include <stack>
#include "program.hpp"
#include "Instruction.h"
#include "Bytestream.hpp"

using namespace std;

#ifndef ___ASSEMBLER_H___
#define ___ASSEMBLER_H___

Bytestream *AssembleProgram(struct Program *program);

#endif