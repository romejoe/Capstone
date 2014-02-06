#include "interpreter.h"

#define GetTypeFromTarget(target, type)		*((type *) target)
#define GetTypeAndAdvance(target, type)		GetTypeFromTarget(target, type); target += sizeof(type)

#define GetInstruction(target)				GetTypeFromTarget(target, struct instruction)
#define GetInstructionAndAdvance(target)	GetTypeAndAdvance(target, struct instruction)

#define GetParameter(target)				GetTypeFromTarget(target, struct paramOption)
#define GetParameterAndAdvance(target)		GetTypeAndAdvance(target, struct paramOption)

void interpreteByteCode(char *progBuf, int length){
	char *stop = progBuf + length;
	struct instruction instruct;
	struct paramOption option1, option2, option3;

	while(progBuf < stop){
		/*get instruction info*/
		instruct = GetInstructionAndAdvance(progBuf);
		switch((int) instruct.paramCount){
			case 1:
				option1 = GetParameterAndAdvance(progBuf);
				break;
			case 2:
				option1 = GetParameterAndAdvance(progBuf);
				option2 = GetParameterAndAdvance(progBuf);
				break;
			case 3:
				option1 = GetParameterAndAdvance(progBuf);
				option2 = GetParameterAndAdvance(progBuf);
				option3 = GetParameterAndAdvance(progBuf);
				break;
			default:
				;/*do nothing*/
		}



	}
}