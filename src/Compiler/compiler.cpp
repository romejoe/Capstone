#include "compiler.hpp"

void AssignVariableIndices(struct Context* ctx, int startIndex){
	int i;
	list<Symbol*> symbols = ctx->symbols;
	list<GenericStatement*> statements = ctx->statements;

	i = 0;
	for(list<Symbol*>::iterator it = symbols.begin();it != symbols.end(); ++it){
//	List_ForEach(symbols, {
		struct Symbol *lSym = *it;//List_Ref_Value(symbols, i, struct Symbol *);
		lSym->index = startIndex + i;
		if(ctx->parent == NULL) lSym->isGlobal = 1;
		else lSym->isGlobal = 0;
		++i;
	}//);

	startIndex = startIndex + symbols.size();
	i = 0;
	for(list<GenericStatement*>::iterator it = statements.begin();it != statements.end(); ++it){
		struct GenericStatement *lGstmt = *it;
//		lGstmt = List_Ref_Value(statements, i, struct GenericStatement *);
		if(lGstmt->type == IFSTATEMENT){
			struct IfStatement *stmt;
			stmt = lGstmt->ifstmt;
			AssignVariableIndices(stmt->yes, startIndex);
			if(stmt->no)
				AssignVariableIndices(stmt->no, startIndex);
		}
		if(lGstmt->type == WHILESTATEMENT){
			struct WhileStatement *stmt;
			stmt = lGstmt->whilestmt;
			AssignVariableIndices(stmt->code, startIndex);
		}
		++i;
	}

}

void fillInSymbolReferences(struct Expression *exp, struct Context *ctx){
	if(!exp) return;
	if(exp->type == SOURCE){
		if(exp->source_type == SYMBOL){
			/* find symbol */
			struct  Context *tmpContext = ctx;
			while(tmpContext){
				list<Symbol*> symbols = tmpContext->symbols;
				for(list<Symbol*>::iterator it = symbols.begin();it != symbols.end(); ++it){


					Symbol *curSym = *it;
					if(exp->dataSource.sym->name == curSym->name){
						
						/*free(exp->dataSource.sym);*/
						
						exp->dataSource.sym = curSym;
						return;
					}
					
				}
				tmpContext = tmpContext->parent;
			}
			printf("Variable %s not found\n", exp->dataSource.sym->name.c_str());
			exit(-1);
		}
		return;
	}
	if(exp->left) fillInSymbolReferences(exp->left, ctx);
	if(exp->right) fillInSymbolReferences(exp->right, ctx);
}
void _updateSymbolReferences(struct Context* prog){
	list<GenericStatement*> statements = prog->statements;
	struct GenericStatement *tmp;

	for(list<GenericStatement*>::iterator it = statements.begin();it != statements.end(); ++it){

		tmp = *it;//List_Ref_Value(statements, i, struct GenericStatement *);
		if(tmp->type == IFSTATEMENT){
			fillInSymbolReferences(tmp->ifstmt->testStatement, prog);
			_updateSymbolReferences(tmp->ifstmt->yes);
			if(tmp->ifstmt->no)
				_updateSymbolReferences(tmp->ifstmt->no);
		}
		else if(tmp->type == WHILESTATEMENT){
			fillInSymbolReferences(tmp->whilestmt->testStatement, prog);
			_updateSymbolReferences(tmp->whilestmt->code);
		}else{
			fillInSymbolReferences(tmp->exp, prog);
		
		}
	}
	
}

void UpdateSymbolReferences(struct Context* prog){
	AssignVariableIndices(prog, 0);
	_updateSymbolReferences(prog);
}
	
Bytestream *compileFile(char *filename)
{
	FILE *f;
	char *buff;
	int fileSize;
	f = fopen(filename, "r");
	if (!f) {
		fprintf(stderr, "Error opening <%s> for reading\n", filename);
		return NULL;
	}

	fseek(f, 0, SEEK_END);
	fileSize = ftell(f) + 1;
	fseek(f, 0, SEEK_SET);

	buff = (char *) malloc(fileSize);
	fread(buff, fileSize, 1, f);
	buff[fileSize - 1] = 0;

	return compileString(buff);

}

Bytestream *compileString(char *srcCode)
{
	struct Program *prog = parseString(srcCode);
	UpdateSymbolReferences(prog->context);
	return AssembleProgram(prog);

}