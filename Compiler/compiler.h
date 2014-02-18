#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "assembler.h"
#ifndef ___COMPILER_H___

struct ByteStream *compileString(char *srcCode);
struct ByteStream *compileFile(char *filename);
#endif