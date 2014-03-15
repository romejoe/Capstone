#include "compiler.h"

struct ByteStream *compileFile(char *filename)
{
	FILE *f;
	char *buff;
	int fileSize;
	f = fopen(filename, "r");
	if (!f) {
		fprintf(stderr, "Error opening <%s> for reading\n", filename);
		return NULL;
	}

	fseek(f, 0, SEEK_END);
	fileSize = ftell(f) + 1;
	fseek(f, 0, SEEK_SET);

	buff = (char *) malloc(fileSize);
	fread(buff, fileSize, 1, f);
	buff[fileSize - 1] = 0;

	return compileString(buff);

}

struct ByteStream *compileString(char *srcCode)
{
	struct Program *prog = parseString(srcCode);
	if (prog->context) printf("context != null\n");
	else printf("context = null\n");
	return AssembleProgram(prog);

}