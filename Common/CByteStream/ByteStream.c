#include "ByteStream.h"

int defaultResizeStream(struct ByteStream *stream, long desiredSize)
{
	long newSize = stream->bufsize;
	while (newSize < desiredSize) {
		newSize = newSize << 1;
	}
	char *newBuff = realloc(stream->buffer, newSize);
	if (!newBuff) return 0;
	stream->buffer = newBuff;
	stream->bufsize = newSize;
	return 1;
}

int initByteStreamWithSize(struct ByteStream *stream, long size)
{
	stream->bufsize = size;
	stream->actualsize = 0;
	stream->buffer = malloc(size);
	stream->resizeBuff = defaultResizeStream;
	return stream->buffer == NULL;
}

int initByteStream(struct ByteStream *stream)
{
	return initByteStreamWithSize(stream, DEFAULTSIZE);
}

void appendByteStreamToByteStream(struct ByteStream *dst, struct ByteStream *appendee){
	if(dst->actualsize + appendee->actualsize > dst->bufsize)
		dst->resizeBuff(dst, dst->actualsize + appendee->actualsize);

	memcpy(dst->buffer + dst->actualsize, appendee->buffer, appendee->actualsize);
	dst->actualsize += appendee->actualsize;
}

void resetByteStream(struct ByteStream *stream){
	stream->actualsize = 0;
}

void writeStreamToFile(FILE *f, struct ByteStream *stream)
{
	fwrite(stream->buffer, stream->actualsize, 1, f);
}