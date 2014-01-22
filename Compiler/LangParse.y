%include{
	#include <stdlib.h>
	#include <assert.h>
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

program ::= statementgroup.

statementgroup ::= statementgroup statement.
statementgroup ::= statement SEMICOLON.

statement ::= IF LPAREN expression RPAREN LCURLY statementgroup RCURLY.
statement ::= expression.



expression ::= term PLUS expression.
expression ::= term MINUS expression.
expression ::= term.

%left MUL DIV MOD.
%right EXP.

term ::= term MUL term.
term ::= term DIV term.
term ::= term MOD term.
term ::= term EXP term.
term ::= factor.

factor ::= LPAREN expression RPAREN.
factor ::= INTEGER.
factor ::= FLOAT.
