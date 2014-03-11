
#include <stdlib.h>
#include "enumDefs.h"
#ifndef ___PROGRAM_H__
#define ___PROGRAM_H__

struct symbol{
	char *name;
};

struct expression {
	enum expression_type type;
	enum data_type result_type;
	enum datasource source_type;
	struct expression *left, *right;
	union {
		long Integer;
		double Float;
		char *Variable;
	} dataSource;
};

struct Program {
	struct expression *root;

};

struct ProgramContainer{
	struct Program *prog;
};

struct expression *new_expression(enum expression_type);
#endif