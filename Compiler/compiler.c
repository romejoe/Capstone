#include "compiler.h"

void AssignVariableIndices(struct Context* ctx, int startIndex){
	
	struct List *symbols = ctx->symbols;
	struct List *statements = ctx->statements;

	List_ForEach(symbols, {
		struct Symbol * lSym = List_Ref_Value(symbols, i, struct Symbol *);
		lSym->index = startIndex + i;
		if(ctx->parent == NULL) lSym->isGlobal = 1;
		else lSym->isGlobal = 0;
		
	});

	startIndex = startIndex + symbols->ListSize;
	List_ForEach(statements, {
		struct GenericStatement *lGstmt;
		lGstmt = List_Ref_Value(statements, i, struct GenericStatement *);
		if(lGstmt->type == IFSTATEMENT){
			struct IfStatement *stmt;
			stmt = lGstmt->ifstmt;
			AssignVariableIndices(stmt->yes, startIndex);
			if(stmt->no)
				AssignVariableIndices(stmt->no, startIndex);
		}
	})

}

void fillInSymbolReferences(struct Expression *exp, struct Context *ctx){
	if(!exp) return;
	if(exp->type == SOURCE){
		if(exp->source_type == SYMBOL){
			/* find symbol */
			struct  Context *tmpContext = ctx;
			while(tmpContext){
				struct List *symbols = tmpContext->symbols;
				List_ForEach(symbols,{
					struct Symbol *curSym = List_Ref_Value(symbols, i, struct Symbol *);
					if(strcmp(exp->dataSource.sym->name, curSym->name) == 0){
						
						/*free(exp->dataSource.sym);*/
						
						exp->dataSource.sym = curSym;
						return;
					}
					
				});
				tmpContext = tmpContext->parent;
			}
			printf("Variable %s not found\n", exp->dataSource.sym->name);
			exit(-1);
		}
		return;
	}
	if(exp->left) fillInSymbolReferences(exp->left, ctx);
	if(exp->right) fillInSymbolReferences(exp->right, ctx);
}
void _updateSymbolReferences(struct Context* prog){
	struct List *statements = prog->statements;
	struct GenericStatement *tmp;
	List_ForEach(statements,{
		tmp = List_Ref_Value(statements, i, struct GenericStatement *);
		if(tmp->type == IFSTATEMENT){
			fillInSymbolReferences(tmp->ifstmt->testStatement, prog);
			_updateSymbolReferences(tmp->ifstmt->yes);
			if(tmp->ifstmt->no)
				_updateSymbolReferences(tmp->ifstmt->no);
		}
		else{
			fillInSymbolReferences(tmp->exp, prog);
		}
	});
	
}

void UpdateSymbolReferences(struct Context* prog){
	AssignVariableIndices(prog, 0);
	_updateSymbolReferences(prog);
}
	
struct ByteStream *compileFile(char *filename)
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

struct ByteStream *compileString(char *srcCode)
{
	struct Program *prog = parseString(srcCode);
	UpdateSymbolReferences(prog->context);
	return AssembleProgram(prog);

}