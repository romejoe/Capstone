#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <iterator>

#include "compiler.hpp"

using namespace std;

int main(int argc, char **argv)
{
	Bytestream *dataStream;
	string OutputName = "b.out";
	--argc;

	if (argc < 1) {
		fprintf(stderr, "\t\x1b[1m\x1b[91mSyntax: %s <path to test file> [<path to executable>]\x1b[0m\n",
		        *argv);
		exit(-1);
	}
	++argv;
	dataStream = compileFile(*argv);
	printf("\n");
	--argc;
	if (argc) {
		++argv;
		OutputName = *(new string(*argv));
	}
	ofstream output_file(OutputName);
	ostream_iterator<char> output_iterator(output_file);
	std::vector<char> data = dataStream->getBuffer();
	copy(data.begin(), data.end(), output_iterator);

	fprintf(stdout, "\x1b[1m\x1b[92mExiting...\x1b[0m\n");
	return 0;

}