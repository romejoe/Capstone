#include <stdio.h>
#include <stdlib.h>

#include "compiler.h"

int main(int argc, char** argv){
	--argc;
	//++argv;

	if(argc != 1){
		fprintf(stderr, "\t\x1b[1m\x1b[91mSyntax: %s <path to test file>\x1b[0m\n", *argv);
		exit(-1);
	}
	++argv;
	compileFile(*argv);
	return 0;
	
}