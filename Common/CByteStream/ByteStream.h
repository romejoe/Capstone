#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef ___BYTE_STREAM_H___
#define ___BYTE_STREAM_H___



struct ByteStream {
	char *buffer;
	long actualsize;
	long bufsize;
	int (*resizeBuff)(struct ByteStream *);

};

#define DEFAULTSIZE 1024

int defaultResizeStream(struct ByteStream *stream);

int initByteStreamWithSize(struct ByteStream *stream, long size);

int initByteStream(struct ByteStream *stream);

#define writeToByteStream(obj, stream){\
		if((stream)->actualsize + sizeof(obj) > (stream)->bufsize){\
			stream->resizeBuff(stream);\
		}\
		memcpy(stream->buffer + stream->actualsize, &obj, sizeof(obj));\
		(stream)->actualsize += sizeof(obj);\
	}

void writeStreamToFile(FILE *f, struct ByteStream *stream);

#endif
