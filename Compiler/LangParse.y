%include{
	#include <stdlib.h>
	#include <assert.h>
	#include "token.h"

	char isFloatType(enum data_type type){
		return (type == tFLOAT || type == tDOUBLE);
	}

	enum data_type DetermineResultType(enum data_type type1, enum data_type type2){
		enum data_type ret;
		//check if same type
		if(type1 == type2){
			return type1;
		}
		//check for void types
		if(type1 == tVOID || type2 == tVOID){
			return TVOID;
		}

		ret = (type1 > type2)? type1 : type2;


		//check wether they are both just integers
		if(isFloatType(type1) || isFloatType(type2)){
			switch(ret){
				case tBOOL:
				case tCHAR:
				case tSHORT:
				case tINT:
					return tFLOAT;
				case tLONG:
					return tDOUBLE;
			}
			
		}
		return ret;
	}

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

%syntax_error	{ printf("\t\x1b[1m\x1b[91mSYNTAX ERROR!!!!\x1b[0m\n");  exit(-1);}

program ::= statementgroup.

statementgroup ::= statementgroup statement SEMICOLON.
statementgroup ::= statement SEMICOLON.

statement ::= IF LPAREN expression RPAREN LCURLY statementgroup RCURLY.
statement ::= DATATYPE KEYWORD EQUAL expression.
statement ::= expression.


expression ::= term PLUS expression.
expression ::= term MINUS expression.
expression ::= term.

%left MUL DIV MOD.
%right EXP.

term(val) ::= term(tm1) MUL term(tm2).{
	struct expression *tmp;
	tmp = new_expression(MULTIPLY);

}
term ::= term DIV term.
term ::= term MOD term.
term ::= term EXP term.
term ::= signedFactor.


signedFactor ::= PLUS factor.
signedFactor ::= MINUS factor.
signedFactor ::= factor.

factor ::= LPAREN expression RPAREN.
factor ::= VARIABLE.
factor ::= INTEGER.
factor ::= FLOAT.
