#include "CByteStream/FullByteStream.h"
#include "assembler.h"

void writeCompleteInstructionToStream(struct complete_instruction *instruct, struct ByteStream *stream){
	
	int i;
	struct paramOption tmpOption;
	writeTypeToByteStream(instruct->instruct,stream, struct instruction);
	writeTypeToByteStream(instruct->optionCount,stream, char);
	
	i = 0;
	while(i < instruct->optionCount){
		tmpOption = instruct->options[i];
		printf("%d:\n", i);
		/*printOption(tmpOption);*/
	 	writeSizeToByteStream(tmpOption, stream, ParamOptionSize);
	 ++i;
	}
}

void writeInstructionToStream(struct instruction *instruct, struct ByteStream *stream){
	
	int i;
	struct paramOption tmpOption;
	writeTypeToByteStream(*instruct,stream, struct instruction);
	
}

void assembleExpression(struct Expression *exp, struct ByteStream *stream)
{
	struct instruction tmp;
	struct instruction in;
	struct instruction *inPtr;
	if (!exp) return;
	/*determine instruction to use*/
	switch (exp->type) {
		
		case ADD:
			in = new_instruction(iADD);
			goto recurse;
		case SUBTRACT:
			in = new_instruction(iSUB);
			goto recurse;
		case MULTIPLY:
			in = new_instruction(iMUL);
			goto recurse;
		case DIVIDE:
			in = new_instruction(iDIV);
			goto recurse;
		case MODULUS:
			in = new_instruction(iMOD);
			goto recurse;
		case POWER:
			in = new_instruction(iEXP);

			recurse:
			assembleExpression(exp->left, stream);
			assembleExpression(exp->right, stream);
			printf("Add\n");
			writeToByteStream(in, stream);
			/*writeToByteStream(*inPtr, stream);*/
			break;
		case SOURCE:
			printf("Source\n");
			if(exp->source_type != SYMBOL){
				
				
				switch(exp->source_type){
					case INTEGER:
						in = new_instruction(iIPUSH);
						writeToByteStream(in, stream);
						writeTypeToByteStream(exp->dataSource.Integer, stream, long);
						break;
					case FLOAT:
						in = new_instruction(iFPUSH);
						writeToByteStream(in, stream);
						writeTypeToByteStream(exp->dataSource.Float, stream, double);	
						break;
				}
			}
			break;
			
		default:
			if (exp->left) assembleExpression(exp->left, stream);
			if (exp->right) assembleExpression(exp->right, stream);
			break;
	}
}

void assembleContext(struct Context *context, struct ByteStream *stream){
	/*write symbols to stream */
	/*write expression to stream */
	assembleExpression(context->exp, stream);
}

struct ByteStream *AssembleProgram(struct Program *program)
{

	struct ByteStream *output;

	output = malloc(sizeof(struct ByteStream));

	initByteStream(output);
	assembleContext(program->context, output);
	/*assembleExpression(program->context->exp, output);*/
	return output;

}