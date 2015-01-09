#include <stdio.h>
#include <stdlib.h>
#include "Lexer_Parser/lexer.hpp"
#include "Assembler/assembler.hpp"
#ifndef ___COMPILER_H___

Bytestream *compileString(char *srcCode);
Bytestream *compileFile(char *filename);
#endif