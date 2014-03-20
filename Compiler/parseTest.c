#include <stdio.h>
#include <stdlib.h>
#include "FileUtil.h"
#include "Lexer_Parser/lexer.h"

void printContext(struct Context *prog, int depth);

void printPadding(int depth){
	int i;
	for(i = 0; i < depth; ++i){
		printf("_");
	}
}

void printExpression(struct Expression *expression, int depth){
	if(expression == NULL) return;
	printPadding(depth);

	switch(expression->type){
		case ASSIGNMENT:
			printf("=\n");
			break;
		case PASS:
			--depth;
			break;
		case ADD:
			printf("+\n");
			break;
		case SOURCE:
			switch(expression->source_type){
				case INTEGER:
					printf("%ld\n", expression->dataSource.Integer);
					break;
				case FLOAT:
					printf("%lf\n", expression->dataSource.Float);
					break;
				case SYMBOL:
					printf("%s\n",expression->dataSource.sym->name);
					/*printSymbol(expression->dataSource.sym);*/
					break;
				default:
					printf("??\n");
					break;
			}
			break;
		default:
			printf("?\n");
			break;
	}

	printExpression(expression->left, depth + 1);
	printExpression(expression->right, depth + 1);

}
void printStatement(struct GenericStatement *stmt, int depth){
	switch(stmt->type){
		case GENERALSTATEMENT:
			printExpression(stmt->exp, depth);
			break;
		case IFSTATEMENT:
			printPadding(depth);
			printf("Test Expression:\n");
			printExpression(stmt->ifstmt->testStatement, depth + 1);
			printPadding(depth);
			printf("Yes Code:\n");
			printContext(stmt->ifstmt->yes, depth+1);
			if(stmt->ifstmt->no){
				printPadding(depth);
				printf("No Code:\n");
				printContext(stmt->ifstmt->no, depth+1);
			}
			break;
		default:
			printPadding(depth);
			printf("Unkown Statement Type\n");
			break;
	}
}

void printContext(struct Context *prog, int depth){
	struct List *symbols;
	struct Symbol *symbol;
	/* print symbols */
	printPadding(depth);
	printf("Symbols:\n======\n");
	
	symbols = prog->symbols;
	List_ForEach(symbols, {
		symbol = List_Ref_Value(symbols, i, struct Symbol *);
		printSymbol(symbol);
	});
	List_ForEach(prog->statements, {
		printStatement(List_Ref_Value(prog->statements, i, struct GenericStatement *), depth + 1);
	});
}

int main(int argc, char **argv)
{
	char *code;
	struct Program *prog;
	--argc;

	if (argc != 1) {
		fprintf(stderr, "\t\x1b[1m\x1b[91mSyntax: %s <path to test file>\x1b[0m\n", *argv);
		exit(-1);
	}
	++argv;
	code = ReadFileToString(*argv);
	prog = parseString(code);
	printContext(prog->context, 0);
	fprintf(stdout, "\x1b[1m\x1b[92mExiting...\x1b[0m\n");
	return 0;

}