#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "assembler.h"
#ifndef ___COMPILER_H___

void compileString(char *filename, char **bytecode, int *codesize);
void compileFile(char *filename, char **bytecode, int *codesize);
#endif