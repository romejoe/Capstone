#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef ___BYTE_STREAM_H___
#define ___BYTE_STREAM_H___



struct ByteStream {
	char *buffer;
	long actualsize;
	long bufsize;
	void (*resizeBuff)(struct ByteStream *);

};

#define DEFAULTSIZE 1024

int defaultResizeStream(struct ByteStream *stream)
{
	long newSize = stream->bufsize << 1;
	char *newBuff = realloc(stream->buffer, newSize);
	if (!newBuff) return 0;
	stream->buffer = newBuff;
	stream->bufsize = newSize;
	return 1;
}

int initByteStreamWithSize(struct ByteStream *stream, long defaultSize)
{
	stream->bufsize = defaultSize;
	stream->actualsize = 0;
	stream->buffer = malloc(defaultSize);
	return stream->buffer == NULL;
}

int initByteStream(struct ByteStream *stream)
{
	return initByteStreamWithSize(stream, DEFAULTSIZE);
}

#define writeToByteStream(obj, stream){\
		if((stream)->actualsize + sizeof(obj) > (stream)->bufsize){\
			stream->resizeBuff(stream);\
		}\
		memcpy(stream->buffer + stream->actualsize, &obj, sizeof(obj));\
		(stream)->actualsize += sizeof(obj);\
	}

void writeStreamToFile(FILE *f, struct ByteStream *stream)
{
	fwrite(stream->buffer, stream->actualsize, 1, f);
}

#endif
