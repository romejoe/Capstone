#include "FullByteStream.h"

struct tmp {
	int asdf;
	int aasdf;
};

struct tmp2 {
	char a;
	char b;
};

int main(int argc, char **argv)
{
	struct ByteStream *stream;
	stream = malloc(sizeof(struct ByteStream));

	initByteStream(stream);
	struct tmp t;
	t.asdf = 5;
	t.aasdf = 6;

	struct tmp2 t2;
	t2.a = 'A';
	t2.b = 'B';

	writeToByteStream(t, stream);
	writeToByteStream(t2, stream);

	printf("stream size: %ld\n", stream->actualsize);

	FILE *f = fopen("tmp.out", "w");
	writeStreamToFile(f, stream);
	return 0;
}