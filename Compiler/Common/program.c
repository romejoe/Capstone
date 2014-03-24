#include <stdio.h>
#include "program.h"

struct Expression *new_expression(enum expression_type type)
{
	struct Expression *_ret = (struct Expression *) malloc(sizeof(struct Expression));

	_ret->type = type;
	_ret->result_type = tVOID;

	_ret->left = NULL;
	_ret->right = NULL;

	return _ret;
}

struct Expression *new_expression_children(enum expression_type type, struct Expression *left, struct Expression *right){
	struct Expression *ret;
	ret = new_expression(type);
	ret->left = left;
	ret->right = right;
	return ret;
}

struct Symbol *new_symbol(char *name, enum data_type type){
	struct Symbol *ret;
	ret = (struct Symbol *) malloc(sizeof(struct Symbol));
	ret->name = name;
	ret->type = type;
	printf("creating symbol of type: %s\n", getPrettyTypeName(type));

	return ret;
}

struct Context *new_context(struct GenericStatement *statement){
	struct Context *ret;
	ret = (struct Context *) malloc(sizeof(struct Context));
	
	ret->statements = malloc(sizeof(struct List));
	newList(ret->statements, struct GenericStatement *);
	
	ret->symbols = malloc(sizeof(struct List));
	newList(ret->symbols, struct Symbol *);

	if(statement){
		List_Add_Value(ret->statements, statement, struct GenericStatement *);
		if(statement->hasDef){
			List_Add_Value(ret->symbols, statement->sym, struct Symbol *);
		}
	}

	return ret;
}
char *getPrettyTypeName(enum data_type type){
	switch(type){
		case tVOID:
			return "VOID";
			break;
		case tINTEGER:
			return "INTEGER";
			break;
		case tFLOAT:
			return "FLOAT";
			break;
		case tFUNCTION:
			return "FUNCTION";
			break;
	}
}