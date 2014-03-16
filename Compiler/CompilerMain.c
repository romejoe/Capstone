#include <stdio.h>
#include <stdlib.h>

#include "compiler.h"

int main(int argc, char **argv)
{
	struct ByteStream *data;
	FILE *output;
	--argc;

	if (argc < 1) {
		fprintf(stderr, "\t\x1b[1m\x1b[91mSyntax: %s <path to test file> [<path to executable>]\x1b[0m\n",
		        *argv);
		exit(-1);
	}
	++argv;
	data = compileFile(*argv);
	printf("\n");
	--argc;
	if (argc) {
		++argv;
		output = fopen(*argv, "w");
	} else {
		output = fopen("b.out", "w");
	}
	writeStreamToFile(output, data);
	fclose(output);
	fprintf(stdout, "\x1b[1m\x1b[92mExiting...\x1b[0m\n");
	return 0;

}