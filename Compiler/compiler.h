#include <stdio.h>
#include <stdlib.h>
#include "Lexer_Parser/lexer.h"
#include "Assembler/assembler.h"
#ifndef ___COMPILER_H___

struct ByteStream *compileString(char *srcCode);
struct ByteStream *compileFile(char *filename);
#endif