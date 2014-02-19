#include <stdio.h>
#include <stdlib.h>

#include "interpreter.h"

void interpretFile(char *fileName){
	FILE *input;
	char *byteCode;
	long FileSize;
	input = fopen(fileName, "r");
	fseek(input, 0, SEEK_END);
	FileSize = ftell(input);

	fseek(input, 0, SEEK_SET);
	
	byteCode = malloc(FileSize);
	fread(byteCode, FileSize, 1, input);

	interpreteByteCode(byteCode, FileSize);
}

int main(int argc, char **argv)
{
	FILE *output;
	--argc;

	if (argc < 1) {
		fprintf(stderr, "\t\x1b[1m\x1b[91mSyntax: %s <path to executable>\x1b[0m\n",
		        *argv);
		exit(-1);
	}
	++argv;
	interpretFile(*argv);
	
	fprintf(stdout, "\x1b[1m\x1b[92mExiting...\x1b[0m\n");
	return 0;

}