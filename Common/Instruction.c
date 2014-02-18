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
			ret.paramCount = 2;
			break;
		case iHELLO:
			ret.paramCount = 0;
	}

	return ret;
}