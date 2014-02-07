#include "Instruction.h"

struct instruction new_instruction(enum instruction_type type){
	struct instruction ret;

	ret.opType = type;

	switch(type){
		case MOV:
		case ADD:
		case FADD:
		case SUB:
		case FSUB:
		case MUL:
		case FMUL:
		case DIV:
		case FDIV:
		ret.paramCount = 2;
		break;
	}
}