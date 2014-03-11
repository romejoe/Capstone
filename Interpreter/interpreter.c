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

#define GetTarget(location, ptr) ((location == 0)? (void *)&registers[location - 1] : (void *)ptr)

/*
union data {
	float flt;
	double dbl;
	int i;
	long l;
	char byte;
	void *ptr;
	char rawData[8];
};
*/

union data {
	double dbl;
	long l;
	char byte;
	char *ptr;
	char rawData[8];
};

void interpreteByteCode(char *buf, int length)
{
	char *progBuf = buf;
	char *stop = progBuf + length;
	struct instruction instruct;
	struct paramOption options[3];
	union data params[3];
	union data registers [__REGISTER_COUNT];
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
			case iRELJMP:
				progBuf += params[0].l;
				break;
			case iMOV:
				memcpy(GetTarget(options[1].location, params[1].ptr), GetTarget(options[0].location, params[0].ptr), options[0].size);
				break;
			case iHELLO:
				printf("Hello First Instruct\n");
				break;
			default:
				printf("OP NOT SUPPORTED!\n");
				break;
		}

	}
}