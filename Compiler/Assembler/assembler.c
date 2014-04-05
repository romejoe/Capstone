#include "CByteStream/FullByteStream.h"
#include "assembler.h"

void writeInstructionToStream(struct instruction *instruct, struct ByteStream *stream);
void assembleExpression(struct Expression *exp, struct ByteStream *stream);
void assembleContext(struct Context *context, struct ByteStream *stream);

void writeInstructionToStream(struct instruction *instruct, struct ByteStream *stream){
	writeTypeToByteStream(*instruct,stream, struct instruction);
}

void assembleIfStatement(struct GenericStatement *stmt, struct ByteStream *stream){
	struct IfStatement *ifStmt = stmt->ifstmt;
	struct ByteStream *yesCode, *noCode;
	struct instruction jmp;
	
	assembleExpression(ifStmt->testStatement, stream);
	
	/* if statement*/
	if(!ifStmt->no){
		jmp = new_instruction(iJMPF);
		writeInstructionToStream(&jmp, stream);

		/*assemble true code*/
		yesCode = malloc(sizeof(struct ByteStream));
		initByteStream(yesCode);
		assembleContext(ifStmt->yes, yesCode);

		/*write jump coordinates to stream*/
		writeTypeToByteStream(yesCode->actualsize, stream, long);
		appendByteStreamToByteStream(stream, yesCode);
	}
	/* if/else statement*/
	else{
		jmp = new_instruction(iJMPT);
		

		noCode = malloc(sizeof(struct ByteStream));
		initByteStream(noCode);
		assembleContext(ifStmt->no, noCode);
		
		/*write jump coordinate, bad code + jmp instruction*/
		writeInstructionToStream(&jmp, stream);
		writeTypeToByteStream(noCode->actualsize + sizeof(long) + sizeof(struct instruction), stream, long);
		
		appendByteStreamToByteStream(stream, noCode);
		

		/*assemble true code*/
		yesCode = malloc(sizeof(struct ByteStream));
		initByteStream(yesCode);
		assembleContext(ifStmt->yes, yesCode);
		/*write jump coordinate, good code*/
		jmp = new_instruction(iJMP);
		writeInstructionToStream(&jmp, stream);
		writeTypeToByteStream(yesCode->actualsize, stream, long);
		appendByteStreamToByteStream(stream, yesCode);
		
	}
	
}

void assembleStatement(struct GenericStatement *stmt, struct ByteStream *stream){
	switch(stmt->type){
		case GENERALSTATEMENT:
			assembleExpression(stmt->exp, stream);
			break;
		case IFSTATEMENT:
			assembleIfStatement(stmt, stream);
			break;
		default:
			printf("Statement type is unsupported!!!\n");
			break;
	}
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
			in = new_instruction(iPOW);
			goto recurse;
		case PRINT:
			in = new_instruction(iPRINT);
			goto recurse;
		case CHECK_EQ:
			in = new_instruction(iEQ);
			goto recurse;
		case CHECK_NE:
			in = new_instruction(iNEQ);
			goto recurse;
		case CHECK_GT:
			in = new_instruction(iGT);
			goto recurse;
		case CHECK_LT:
			in = new_instruction(iLT);
			goto recurse;
		case CHECK_GTE:
			in = new_instruction(iGTE);
			goto recurse;
		case CHECK_LTE:
			in = new_instruction(iLTE);
			goto recurse;
		case ASSIGNMENT:
			in = new_instruction(iASSIGN);
			goto recurse;

			recurse:
			assembleExpression(exp->left, stream);
			assembleExpression(exp->right, stream);
			writeToByteStream(in, stream);
			break;

		case SOURCE:
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
				case SYMBOL:
					printf("Symbol Name: %s; Global: %d\n", exp->dataSource.sym->name, exp->dataSource.sym->isGlobal);
					if(exp->dataSource.sym->isGlobal)
						in = new_instruction(iGVPUSH);
					else
						in = new_instruction(iLVPUSH);

					writeToByteStream(in, stream);
					writeTypeToByteStream(exp->dataSource.sym->index, stream, long);
					break;
				default:
					printf("Source is unsupported!!!\n");
					break;
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
	struct List *statements = context->statements;
	
	/*printf("list size = %d\n", statements->ListSize);*/
	struct instruction tmp;
	long varCount = context->symbols->ListSize;
	
	tmp = new_instruction(iVALLOC);
	writeInstructionToStream(&tmp, stream);
	writeTypeToByteStream(varCount, stream, long);

	tmp = new_instruction(iVSETTYPE);
	List_ForEach(context->symbols, {
		struct Symbol *lSym;
		writeInstructionToStream(&tmp, stream);
		lSym = List_Ref_Value(context->symbols, i, struct Symbol *);
		
		writeTypeToByteStream(
			lSym->index,
			stream, long);
		switch(lSym->type){
			case tINTEGER:
				writeTypeToByteStream(
				INTEGER,
				stream, enum datasource);	
				break;
			case tFLOAT:
				writeTypeToByteStream(
				FLOAT,
				stream, enum datasource);	
				break;
		}/*
		writeTypeToByteStream(
			lSym->type,
			stream, enum data_type);*/
	});
	/*
	tmp = new_instruction(iDUMPVARS);
	writeInstructionToStream(&tmp, stream);
	*/
	List_ForEach(statements,{
		assembleStatement(List_Ref_Value(statements, i, struct GenericStatement *), stream);	
		/*
		tmp = new_instruction(iDUMPVARS);
		writeInstructionToStream(&tmp, stream);
		*/
	});

	tmp = new_instruction(iVDALLOC);
	writeInstructionToStream(&tmp, stream);
	writeTypeToByteStream(varCount, stream, long);
	
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