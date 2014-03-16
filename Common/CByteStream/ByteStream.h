#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef ___BYTE_STREAM_H___
#define ___BYTE_STREAM_H___



struct ByteStream {
	char *buffer;
	long actualsize;
	long bufsize;
	int (*resizeBuff)(struct ByteStream *, long);

};

#define DEFAULTSIZE 1024

int defaultResizeStream(struct ByteStream *stream, long desiredSize);

int initByteStreamWithSize(struct ByteStream *stream, long size);

int initByteStream(struct ByteStream *stream);

#define writeToByteStream(obj, stream){\
		if((stream)->actualsize + sizeof(obj) > (stream)->bufsize){\
			stream->resizeBuff(stream, ((stream)->actualsize + sizeof(obj)));\
		}\
		memcpy(stream->buffer + stream->actualsize, &obj, sizeof(obj));\
		(stream)->actualsize += sizeof(obj);\
	}

#define writeSizeToByteStream(obj, stream, size){\
		if((stream)->actualsize + size > (stream)->bufsize){\
			stream->resizeBuff(stream, ((stream)->actualsize + size));\
		}\
		memcpy(stream->buffer + stream->actualsize, &obj, size);\
		(stream)->actualsize += size;\
	}

#define writeTypeToByteStream(obj, stream, type){\
		if((stream)->actualsize + sizeof(type) > (stream)->bufsize){\
			stream->resizeBuff(stream, ((stream)->actualsize + sizeof(type)));\
		}\
		(*(type *) ((stream)->buffer + (stream)->actualsize)) = obj;\
		(stream)->actualsize += sizeof(type);\
	}

void writeStreamToFile(FILE *f, struct ByteStream *stream);

#endif
