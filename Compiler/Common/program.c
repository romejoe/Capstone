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

struct Symbol *new_symbol(char *name, enum data_type type){
	struct Symbol *ret;
	ret = (struct Symbol *) malloc(sizeof(struct Symbol));
	ret->name = name;
	ret->type = type;
	printf("creating symbol of type: %s\n", getPrettyTypeName(type));

	return ret;
}

struct Context *new_context(struct Expression *exp, void *symbols, char exportType){
	struct Context *ret;
	ret = (struct Context *) malloc(sizeof(struct Context));
	
	ret->expressions = malloc(sizeof(struct List));
	newList(ret->expressions, struct Expression *);
	if(exp) List_Add_Value(ret->expressions, exp, struct Expression *);
	ret->exp = exp;

	ret->exports._raw = symbols;
	ret->exportType = exportType;
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