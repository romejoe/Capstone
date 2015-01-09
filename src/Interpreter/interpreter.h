#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "Instruction.h"
#include "enumDefs.h"
#include "astack.h"
#include "List.h"

#ifndef ___INTERPRETER_H___
#define ___INTERPRETER_H___

void interpreteByteCode(char *todo, int length);

#endif
