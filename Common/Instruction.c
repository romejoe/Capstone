#include "Instruction.h"

struct instruction new_instruction(enum instruction_type type)
{
	struct instruction ret;

	ret.opType = type;

	switch (type) {
		case iMOV:
		case iADD:
		case iFADD:
		case iSUB:
		case iFSUB:
		case iMUL:
		case iFMUL:
		case iDIV:
		case iFDIV:
			break;
		case iHELLO:
			break;
	}

	return ret;
}

int getParamCountForInstruction(struct instruction instruct){
	switch(instruct.opType){
		case iHELLO:
			return 0;
		default:
			return 0;
	}
}