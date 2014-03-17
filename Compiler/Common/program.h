
#include <stdlib.h>
#include "enumDefs.h"
#include "List.h"
#ifndef ___PROGRAM_H__
#define ___PROGRAM_H__

struct Symbol{
	char *name;
	enum data_type type;
};

struct Expression {
	enum expression_type type;
	enum data_type result_type;
	
	enum datasource source_type;
	
	struct Expression *left, *right;
	union {
		long Integer;
		double Float;
		struct Symbol *sym;
	} dataSource;
};

struct Context{
	struct Expression *exp;
	struct List *expressions;
	/* 1 => symbol */
	/* 2 => symbols */
	char exportType;
	union {
		struct Symbol *symbol;
		struct List *symbols;
		void *_raw;
	} exports;

};

struct Program {
	/*struct expression *root;*/
	struct Context *context;

};

/*Protoypes*/

struct Expression *new_expression(enum expression_type);
struct Symbol *new_symbol(char *name, enum data_type type);
struct Context *new_context(struct Expression *exp, void *symbols, char exportType);

char *getPrettyTypeName(enum data_type type);

#define printSymbol(sym) printf("name: %s, type: %s\n", (sym)->name, getPrettyTypeName((sym)->type))

#endif