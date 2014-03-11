#include "Instruction.h"
#include <stdlib.h>

struct instruction new_instruction(enum instruction_type type)
{
	struct instruction ret;

	ret.opType = type;

	return ret;
}

int getParamCountForInstruction(struct instruction instruct){
	switch(instruct.opType){
		case iRELJMP:
			return 1;
		case iHELLO:
			return 0;
		default:
			return 0;
	}
}

struct complete_instruction *new_complete_instruction(enum instruction_type type){
	struct complete_instruction *ret;
	struct instruction tmp;
	tmp = new_instruction(type);
	int optionCount = getParamCountForInstruction(tmp);

	ret = malloc(sizeof(struct complete_instruction) + sizeof(struct paramOption) * optionCount);
	ret->instruct = tmp;
	ret->optionCount = optionCount;

	return ret;
}
