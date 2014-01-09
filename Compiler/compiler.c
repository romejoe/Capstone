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
	fileSize = ftell(f);
	buff = (char *) malloc(fileSize);
	fread(buff, fileSize, 1, f);
	compileString(buff);

}

void compileString(char * srcCode){
	parseString(srcCode);
}