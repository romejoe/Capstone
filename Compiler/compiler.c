#include "compiler.h"

void compileFile(char * filename){
	FILE *f;
	char *buff;
	int fileSize;
	f = fopen(filename, "r");
	if(!f){
		fprintf(stderr, "Error opening <%s> for reading\n", filename);
		return;
	}

	fseek(f, 0, SEEK_END);
	fileSize = ftell(f) + 1;
	fseek(f, 0, SEEK_SET);

	buff = (char *) malloc(fileSize);
	fread(buff, fileSize, 1, f);
	buff[fileSize - 1] = 0;

	compileString(buff);

}

void compileString(char * srcCode){
	struct Program *prog = parseString(srcCode);
	printf("prog = %p\n", prog);

}