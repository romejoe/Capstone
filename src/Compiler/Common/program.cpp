#include <stdio.h>
#include "program.hpp"


Symbol::Symbol(string name, enum data_type type){
	this->name = name;
	this->type = type;
	cout << "creating symbol of type: " << getPrettyTypeName(type) << endl;
}

Expression::Expression(enum expression_type type)
{
	this->type = type;
	result_type = tVOID;

	left = NULL;
	right = NULL;
}

Expression::Expression(enum expression_type type, struct Expression *left, struct Expression *right):Expression(type){
	this->left = left;
	this->right = right;
}

Context::Context(GenericStatement *statement){
	if(statement){
		statements.push_back(statement);
		if(statement->hasDef){
			symbols.push_back(statement->sym);
		}
	}
}

string getPrettyTypeName(enum data_type type){
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