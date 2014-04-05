#include "interpreter.h"

#define GetTypeFromTarget(target, type)     *((type *) target)
#define GetTypeAndAdvance(target, type)     GetTypeFromTarget(target, type); target += sizeof(type)

#define GetInstruction(target)              GetTypeFromTarget(target, struct instruction)
#define GetInstructionAndAdvance(target)    GetTypeAndAdvance(target, struct instruction)

char *getDataTypeName(enum datasource type)
{
	switch (type) {
		case __VARIABLE:
			return "__VARIABLE";
		case NA:
			return "NA";
		case INTEGER:
			return "INTEGER";
		case FLOAT:
			return "FLOAT";
		case STRING:
			return "STRING";
		case SYMBOL:
			return "SYMBOL";
		case POINTER:
			return "POINTER";
		default:
			return "Unknown";
	}
}

void interpreteByteCode(char *buf, int length)
{
	char *progBuf = buf;
	char *stop = progBuf + length;
	struct instruction instruct;
	long offset;
	long count;
	long l;
	double d;
	enum data_type type;

	while (progBuf < stop) {
		/*get instruction info*/
		printf("Offset: %ld\n", progBuf - buf);
		instruct = GetInstructionAndAdvance(progBuf);
		printf("OP[%X]: %s\n", instruct.opType, getName(instruct.opType));
		switch (instruct.opType) {
			case iJMP:
			case iJMPF:
			case iJMPT:
			case iLVPUSH:
			case iGVPUSH:
				offset = GetTypeAndAdvance(progBuf, long);
				printf("\toffset: %ld\n", offset);
				break;
			case iIPUSH:
				l = GetTypeAndAdvance(progBuf, long);
				printf("\tValue: %ld\n", l);
				break;
			case iFPUSH:
				d = GetTypeAndAdvance(progBuf, double);
				printf("\tValue: %lf\n", d);
				break;

			case iVALLOC:
			case iVDALLOC:
				count = GetTypeAndAdvance(progBuf, long);
				printf("\tCount: %ld\n", count);
				break;


			case iVSETTYPE:
				offset = GetTypeAndAdvance(progBuf, long);
				type = GetTypeAndAdvance(progBuf, enum datasource);
				printf("\tOffset: %ld\n", offset);
				printf("\tType: %s\n", getDataTypeName(type));
				break;
			default:
				break;
		}

	}
}


void disassembleFile(char *fileName)
{
	FILE *input;
	char *byteCode;
	long FileSize;
	input = fopen(fileName, "r");
	fseek(input, 0, SEEK_END);
	FileSize = ftell(input);

	fseek(input, 0, SEEK_SET);

	byteCode = malloc(FileSize);
	fread(byteCode, FileSize, 1, input);

	interpreteByteCode(byteCode, FileSize);
}

int main(int argc, char **argv)
{
	FILE *output;
	--argc;

	if (argc < 1) {
		fprintf(stderr, "\t\x1b[1m\x1b[91mSyntax: %s <path to executable>\x1b[0m\n",
		        *argv);
		exit(-1);
	}
	++argv;
	disassembleFile(*argv);

	fprintf(stdout, "\x1b[1m\x1b[92mExiting...\x1b[0m\n");
	return 0;

}