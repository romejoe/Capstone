#include "Instruction.h"
#include <stdlib.h>

struct instruction new_instruction(enum instruction_type type)
{
	struct instruction ret;

	ret.opType = type;

	return ret;
}
