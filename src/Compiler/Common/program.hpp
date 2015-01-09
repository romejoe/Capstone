
#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>

#include "enumDefs.h"

#ifndef ___PROGRAM_H__
#define ___PROGRAM_H__

using namespace std;

/* prototypes */
struct Symbol;
struct Context;
struct IfStatement;
struct GenericStatement;

struct Symbol{
	string name;
	enum data_type type;
	int index;
	char isGlobal;
	Symbol(string name, enum data_type type);
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
	Expression(enum expression_type);
	Expression(enum expression_type, Expression *left, Expression *right);
};

struct Context{
	struct Context *parent;

	list<GenericStatement*> statements;
	list<Symbol*> symbols;

	Context(GenericStatement *exp);
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

string getPrettyTypeName(enum data_type type);

#define printSymbol(sym) printf("name: %s, type: %s\n", (sym)->name.c_str(), getPrettyTypeName((sym)->type).c_str())

#endif