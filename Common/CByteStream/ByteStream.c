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

void writeStreamToFile(FILE *f, struct ByteStream *stream)
{
	fwrite(stream->buffer, stream->actualsize, 1, f);
}