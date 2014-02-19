#include "interpreter.h"
#include <stdio.h>

#define GetTypeFromTarget(target, type)     *((type *) target)
#define GetTypeAndAdvance(target, type)     GetTypeFromTarget(target, type); target += sizeof(type)

#define GetInstruction(target)              GetTypeFromTarget(target, struct instruction)
#define GetInstructionAndAdvance(target)    GetTypeAndAdvance(target, struct instruction)

#define GetParameter(target)                GetTypeFromTarget(target, struct paramOption)
#define GetParameterAndAdvance(target)      GetTypeAndAdvance(target, struct paramOption)

#define GetParamData(target, source, size)          memcpy(target, source, (size))
#define GetParamDataAndAdvance(target, source, size)    GetParamData(target,source,(size)); source += (size)

union parameter {
	float flt;
	double dbl;
	int i;
	long l;
	char byte;
	void *ptr;
	char rawData[8];
};

void interpreteByteCode(char *progBuf, int length)
{
	char *stop = progBuf + length;
	struct instruction instruct;
	struct paramOption options[3];
	union parameter params[3];
	int i;
	int paramCount;

	while (progBuf < stop) {
		/*get instruction info*/
		instruct = GetInstructionAndAdvance(progBuf);
		paramCount = getParamCountForInstruction(instruct);

		for (i = 0; i < paramCount; ++i) {
			options[i] = GetParameterAndAdvance(progBuf);
		}
		for (i = 0; i < paramCount; ++i) {
			GetParamDataAndAdvance(&params[i], progBuf, 1 << options[i].size);
		}

		switch(instruct.opType){
			case iHELLO:
				printf("Hello First Instruct\n");
				break;
			default:
				printf("OP NOT SUPPORTED!\n");
				break;
		}

	}
}