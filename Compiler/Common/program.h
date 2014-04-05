
#include <stdlib.h>
#include "enumDefs.h"
#include "List.h"
#ifndef ___PROGRAM_H__
#define ___PROGRAM_H__

/* prototypes */
struct Symbol;
struct Context;
struct IfStatement;
struct GenericStatement;

struct Symbol{
	char *name;
	enum data_type type;
	int index;
	char isGlobal;
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
	struct Context *parent;
	struct List *statements; /* (struct GenericStatement *) */
	struct List *symbols; /* (struct Symbol *) */
};

struct IfStatement{
	struct Expression *testStatement;
	struct Context *yes, *no;
};

struct WhileStatement{
	struct Expression *testStatement;
	struct Context *code;
};

struct GenericStatement{
	enum statementType type;
	char hasDef;
	union{
		struct Expression *exp;
		struct IfStatement *ifstmt;
		struct WhileStatement *whilestmt;
	};
	struct Symbol *sym;
};

struct Program {
	/*struct expression *root;*/
	struct Context *context;

};

/*Protoypes*/

struct Expression *new_expression(enum expression_type);
struct Expression *new_expression_children(enum expression_type, struct Expression *left, struct Expression *right);
struct Symbol *new_symbol(char *name, enum data_type type);
struct Context *new_context(struct GenericStatement *exp);

char *getPrettyTypeName(enum data_type type);

#define printSymbol(sym) printf("name: %s, type: %s\n", (sym)->name, getPrettyTypeName((sym)->type))

#endif