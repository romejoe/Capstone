#include "assembler.hpp"

void writeInstructionToStream(struct instruction *instruct, Bytestream *stream);
void assembleExpression(struct Expression *exp, Bytestream *stream);
void assembleContext(struct Context *context, Bytestream *stream);

void writeInstructionToStream(struct instruction *instruct, Bytestream *stream)
{
	stream->write<struct instruction>(*instruct);
	//writeTypeToByteStream(*instruct, stream, struct instruction);
}

void assembleIfStatement(struct GenericStatement *stmt, Bytestream *stream)
{
	struct IfStatement *ifStmt = stmt->ifstmt;
	Bytestream *yesCode, *noCode;
	struct instruction *jmp;
	long tmp;

	assembleExpression(ifStmt->testStatement, stream);

	/* if statement*/
	if (!ifStmt->no) {
		jmp = new instruction(iJMPF);
		writeInstructionToStream(jmp, stream);

		/*assemble true code*/
		yesCode = new Bytestream();
		assembleContext(ifStmt->yes, yesCode);

		/*write jump coordinates to stream*/
		tmp  = yesCode->size();
		yesCode->write<long>(tmp);
		stream->appendBytestream(yesCode);
		//writeTypeToByteStream(yesCode->actualsize, stream, long);
		//appendByteStreamToByteStream(stream, yesCode);
	}
	/* if/else statement*/
	else {
		jmp = new instruction(iJMPT);

		noCode = new Bytestream();
		//noCode = malloc(sizeof(struct ByteStream));
		//initByteStream(noCode);
		assembleContext(ifStmt->no, noCode);

		/*write jump coordinate, bad code + jmp instruction*/
		writeInstructionToStream(jmp, stream);
		tmp = noCode->size() + sizeof(long) + sizeof(struct instruction);
		stream->write<long>(tmp);
		//writeTypeToByteStream(noCode->actualsize + sizeof(long) + sizeof(struct instruction), stream, long);
		stream->appendBytestream(noCode);
		//appendByteStreamToByteStream(stream, noCode);


		/*assemble true code*/
		yesCode = new Bytestream();
		//yesCode = malloc(sizeof(struct ByteStream));
		//initByteStream(yesCode);
		assembleContext(ifStmt->yes, yesCode);
		/*write jump coordinate, good code*/
		jmp = new instruction(iJMP);
		writeInstructionToStream(jmp, stream);
		tmp = yesCode->size();
		stream->write<long>(tmp);
		//writeTypeToByteStream(yesCode->actualsize, stream, long);
		stream->appendBytestream(yesCode);
		//appendByteStreamToByteStream(stream, yesCode);

	}

}

void assembleWhileStatement(struct GenericStatement *stmt, Bytestream *stream)
{
	struct WhileStatement *whileStmt = stmt->whilestmt;
	Bytestream *Code;
	struct instruction *jmp;
	long offset;
	long tmp;

	offset = stream->size();
	assembleExpression(whileStmt->testStatement, stream);


	jmp = new instruction(iJMPF);
	writeInstructionToStream(jmp, stream);

	/*assemble loop code*/
	Code = new Bytestream();

	assembleContext(whileStmt->code, Code);

	/*jump to after loop code*/
	tmp = Code->size() + sizeof(struct instruction) + sizeof(long);
	stream->write<long>(tmp);

	/* jump to before test statement */

	jmp = new instruction(iJMP);
	writeInstructionToStream(jmp, Code);

	stream->appendBytestream(Code);

	tmp = offset - stream->size() - sizeof(long);
	stream->write<long>(tmp);

}

void assembleStatement(struct GenericStatement *stmt, Bytestream *stream)
{
	switch (stmt->type) {
		case GENERALSTATEMENT:
			assembleExpression(stmt->exp, stream);
			break;
		case IFSTATEMENT:
			assembleIfStatement(stmt, stream);
			break;
		case WHILESTATEMENT:
			assembleWhileStatement(stmt, stream);
			break;
		default:
			printf("Statement type is unsupported!!!\n");
			break;
	}
}

void assembleExpression(struct Expression *exp, Bytestream *stream)
{
	struct instruction *tmp;
	struct instruction *in;
	struct instruction *inPtr;
	if (!exp) return;
	/*determine instruction to use*/
	switch (exp->type) {

		case ADD:
			in = new instruction(iADD);
			goto recurse;
		case SUBTRACT:
			in = new instruction(iSUB);
			goto recurse;
		case MULTIPLY:
			in = new instruction(iMUL);
			goto recurse;
		case DIVIDE:
			in = new instruction(iDIV);
			goto recurse;
		case MODULUS:
			in = new instruction(iMOD);
			goto recurse;
		case POWER:
			in = new instruction(iPOW);
			goto recurse;
		case PRINT:
			in = new instruction(iPRINT);
			goto recurse;
		case CHECK_EQ:
			in = new instruction(iEQ);
			goto recurse;
		case CHECK_NE:
			in = new instruction(iNEQ);
			goto recurse;
		case CHECK_GT:
			in = new instruction(iGT);
			goto recurse;
		case CHECK_LT:
			in = new instruction(iLT);
			goto recurse;
		case CHECK_GTE:
			in = new instruction(iGTE);
			goto recurse;
		case CHECK_LTE:
			in = new instruction(iLTE);
			goto recurse;

		case LOG_NOT:
			in = new instruction(iLOGNOT);
			goto recurse;
		case LOG_AND:
			in = new instruction(iLOGAND);
			goto recurse;
		case LOG_OR:
			in = new instruction(iLOGOR);
			goto recurse;
		case LOG_XOR:
			in = new instruction(iLOGXOR);
			goto recurse;
		case ASSIGNMENT:
			in = new instruction(iASSIGN);
			goto recurse;

recurse:
			assembleExpression(exp->left, stream);
			assembleExpression(exp->right, stream);
			stream->write<instruction>(*in);
			break;

		case SOURCE:
			switch (exp->source_type) {
				case INTEGER:
					in = new instruction(iIPUSH);
					stream->write<instruction>(*in);
					stream->write<long>(exp->dataSource.Integer);
//					writeTypeToByteStream(exp->dataSource.Integer, stream, long);
					break;
				case FLOAT:
					in = new instruction(iFPUSH);
					stream->write<instruction>(*in);
					stream->write<double>(exp->dataSource.Float);
//					writeTypeToByteStream(exp->dataSource.Float, stream, double);
					break;
				case SYMBOL:
					printf("Symbol Name: %s; Global: %d\n", exp->dataSource.sym->name.c_str(), exp->dataSource.sym->isGlobal);
					if (exp->dataSource.sym->isGlobal)
						in = new instruction(iGVPUSH);
					else
						in = new instruction(iLVPUSH);

					stream->write<instruction>(*in);
					stream->write<long>(exp->dataSource.sym->index);
//					writeTypeToByteStream(exp->dataSource.sym->index, stream, long);
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

void assembleContext(struct Context *context, Bytestream *stream)
{
	/*write symbols to stream */
	/*write expression to stream */
	list<GenericStatement*> statements = context->statements;

	/*printf("list size = %d\n", statements->ListSize);*/
	struct instruction *tmp;
	long varCount = context->symbols.size();

	tmp = new instruction(iVALLOC);
	stream->write<instruction>(*tmp);
	stream->write<long>(varCount);


	tmp = new instruction(iVSETTYPE);
	for(list<GenericStatement*>::iterator it = statements.begin(); it != statements.end(); ++it){
//	List_ForEach(context->symbols, {
		struct Symbol *lSym;
		stream->write<instruction>(*tmp);
//		writeInstructionToStream(&tmp, stream);
//		lSym = List_Ref_Value(context->symbols, i, struct Symbol *);
		lSym = (*it)->sym;
		stream->write<long>(lSym->index);
/*		writeTypeToByteStream(
		    lSym->index,
		    stream, long);*/
		switch (lSym->type)
		{
			case tINTEGER:
				printf("writing int type\n");
				stream->write<enum datasource>(INTEGER);
//				writeTypeToByteStream(
//				    INTEGER,
//				    stream, enum datasource);
				break;
			case tFLOAT:
				printf("writing float type\n");
				stream->write<enum datasource>(FLOAT);
//				writeTypeToByteStream(
//				    FLOAT,
//				    stream, enum datasource);
				break;
			default:
				break;
		}/*
        writeTypeToByteStream(
            lSym->type,
            stream, enum data_type);*/
	}//);
	/*
	tmp = new instruction(iDUMPVARS);
	writeInstructionToStream(&tmp, stream);
	*/
	for(list<GenericStatement*>::iterator it = statements.begin(); it != statements.end(); ++it){
//	List_ForEach(statements, {
		assembleStatement(*it, stream);
//		assembleStatement(List_Ref_Value(statements, i, struct GenericStatement *), stream);
		/*
		tmp = new instruction(iDUMPVARS);
		writeInstructionToStream(&tmp, stream);
		*/
	}

	tmp = new instruction(iVDALLOC);
	stream->write<instruction>(*tmp);
	stream->write<long>(varCount);


}

Bytestream *AssembleProgram(struct Program *program)
{

	Bytestream *output = new Bytestream();
	

	assembleContext(program->context, output);
	return output;

}