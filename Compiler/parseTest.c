#include <stdio.h>
#include <stdlib.h>
#include "FileUtil.h"
#include "Lexer_Parser/lexer.h"

void printExpression(struct Expression *expression, int depth){
	int i;
	if(expression == NULL) return;
	for(i = 0; i < depth; ++i) printf("_");

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

void printContext(struct Context *prog, int depth){
	struct List *symbols;
	struct Symbol **symbol;
	/* print symbols */
	printf("Symbols:\n======\n");
	if(prog->exports._raw){
		switch(prog->exportType){
			case 1:
				printf("1 symbol\n");
				printSymbol(prog->exports.symbol);
				break;
			case 2:
				symbols = prog->exports.symbols;
				List_ForEach(symbols, {
					symbol = (struct Symbol **) List_Ref(symbols, i);
					printSymbol(*symbol);
				});
				break;
			default:
				break;
		}
	}
	printExpression(prog->exp, 0);
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