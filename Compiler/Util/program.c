#include "program.h"

#include <stdio.h>
struct expression *new_expression(enum expression_type type)
{
	struct expression *_ret = (struct expression *) malloc(sizeof(struct expression));

	_ret->type = type;
	_ret->result_type = tVOID;

	_ret->left = NULL;
	_ret->right = NULL;

	return _ret;
}