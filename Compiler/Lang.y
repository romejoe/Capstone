%include{
	#include <stdlib.h>
	#include "token.h"

}

%token_type {Token}
%token_prefix {T_}

%parse_accept	{
	printf("\tparse accepted\n");
}
%parse_failure	{
	printf("\tparse failed\n");
}
%stack_overflow	{
	printf("\tstack overflowed\n");
}

%syntax_error	{ printf("\t\x1b[1m\x1b[91mSYNTAX ERROR!!!!\x1b[0m\n"); }

program ::= statement.
program ::= program statement.

expression ::= LPAREN expression RPAREN.

expression ::= factor ADD expression.
expression ::= factor SUB expression.
expression ::= factor.

factor ::= factor EXP expression.
factor ::= factor MUL expression.
factor ::= factor DIV expression.
factor ::= factor MOD expression.
factor ::= INTEGER.
factor ::= FLOAT.