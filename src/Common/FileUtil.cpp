#include "FileUtil.h"
char *ReadFileToString(char *path){
	FILE *f;
	char *buff;
	int fileSize;
	f = fopen(path, "r");
	if (!f) {
		fprintf(stderr, "Error opening <%s> for reading\n", path);
		return NULL;
	}

	fseek(f, 0, SEEK_END);
	fileSize = ftell(f) + 1;
	fseek(f, 0, SEEK_SET);

	buff = (char *) malloc(fileSize);
	fread(buff, fileSize, 1, f);
	buff[fileSize - 1] = 0;
	return buff;

}