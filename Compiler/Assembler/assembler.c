#include "Common/CByteStream/FullByteStream.h"
#include "assembler.h"


void assembleExpression(struct expression *exp, struct ByteStream *stream)
{
	struct instruction tmp;

	if (!exp) return;
	/*determine instruction to use*/
	printf("a");
	switch (exp->type) {
		/*case PASS:*/
		case ADD:
		case SUBTRACT:
		case MULTIPLY:
		case DIVIDE:
		case MODULUS:
		case POWER:
			assembleExpression(exp->left, stream);
			assembleExpression(exp->right, stream);


			break;
		case DATA:
		default:
			if (exp->left) assembleExpression(exp->left, stream);
			if (exp->right) assembleExpression(exp->right, stream);

			tmp = new_instruction(iHELLO);
			writeToByteStream(tmp, stream);
			break;
	}
}

struct ByteStream *AssembleProgram(struct Program *program)
{

	struct ByteStream *output;

	output = malloc(sizeof(struct ByteStream));

	initByteStream(output);

	assembleExpression(program->root, output);
	return output;
	/*

	    struct astack stack;

	    initAStack(stack, struct expression *);

	    AStack_Free(stack);
	*/
}