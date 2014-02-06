%include{
	#include <stdlib.h>
	#include <assert.h>
	#include "token.h"
	#include "Util/program.h"

	char isFloatType(enum data_type type){
		return (type == tFLOAT || type == tDOUBLE);
	}

	enum data_type DetermineResultType(enum data_type type1, enum data_type type2){
		enum data_type ret;
		/*check if same type*/
		if(type1 == type2){
			return type1;
		}
		/*check for void types*/
		if(type1 == tVOID || type2 == tVOID){
			return tVOID;
		}

		ret = (type1 > type2)? type1 : type2;


		/*check wether they are both just integers*/
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
%extra_argument { struct Program *pProgram }
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

program ::= statementgroup(stmntgrp).{
	pProgram->root = stmntgrp.__exp;
}

statementgroup(val) ::=  statement(stmt) SEMICOLON statementgroup(stmntgrp).{
	struct expression *tmp;

	tmp = new_expression(PASS);
	tmp->left = stmt.__exp;
	tmp->right = stmntgrp.__exp;
	val.__exp = tmp;
}

statementgroup(val) ::= statement(stmt) SEMICOLON.{
	val.__exp = stmt.__exp;
}

statement ::= IF LPAREN expression RPAREN LCURLY statementgroup RCURLY.
statement ::= DATATYPE KEYWORD EQUAL expression.
statement(val) ::= expression(exp).{
	val.__exp = exp.__exp;
}


expression(val) ::= term(tm) PLUS expression(exp).{
	struct expression *tmExp = (struct expression *)tm.__exp;
	struct expression *expExp = (struct expression *)exp.__exp;
	struct expression *tmp;
	tmp = new_expression(ADD);
	tmp->result_type = DetermineResultType(tmExp->result_type, expExp->result_type);
	tmp->left = tmExp;
	tmp->right = expExp;

	val.__exp = tmp;
}

expression(val) ::= term(tm) MINUS expression(exp).{
	struct expression *tmExp = (struct expression *)tm.__exp;
	struct expression *expExp = (struct expression *)exp.__exp;
	struct expression *tmp;
	tmp = new_expression(SUBTRACT);
	tmp->result_type = DetermineResultType(tmExp->result_type, expExp->result_type);
	tmp->left = tmExp;
	tmp->right = expExp;

	val.__exp = tmp;
}

expression(val) ::= term(tm).{
	val.__exp = tm.__exp;
}

%left MUL DIV MOD.
%right EXP.

term(val) ::= term(tm1) MUL term(tm2).{
	struct expression *tm1Exp = (struct expression *)tm1.__exp;
	struct expression *tm2Exp = (struct expression *)tm2.__exp;
	struct expression *tmp;
	tmp = new_expression(MULTIPLY);
	tmp->result_type = DetermineResultType(tm1Exp->result_type, tm2Exp->result_type);
	tmp->left = tm1Exp;
	tmp->right = tm2Exp;

	val.__exp = tmp;
}

term(val) ::= term(tm1) DIV term(tm2).{
	struct expression *tm1Exp = (struct expression *)tm1.__exp;
	struct expression *tm2Exp = (struct expression *)tm2.__exp;
	struct expression *tmp;
	tmp = new_expression(DIVIDE);
	tmp->result_type = DetermineResultType(tm1Exp->result_type, tm2Exp->result_type);
	tmp->left = tm1Exp;
	tmp->right = tm2Exp;

	val.__exp = tmp;
}

term(val) ::= term(tm1) MOD term(tm2).{
	struct expression *tm1Exp = (struct expression *)tm1.__exp;
	struct expression *tm2Exp = (struct expression *)tm2.__exp;
	struct expression *tmp;
	tmp = new_expression(MODULUS);
	tmp->result_type = DetermineResultType(tm1Exp->result_type, tm2Exp->result_type);
	tmp->left = tm1Exp;
	tmp->right = tm2Exp;

	val.__exp = tmp;
}

term(val) ::= term(tm1) EXP term(tm2).{
	struct expression *tm1Exp = (struct expression *)tm1.__exp;
	struct expression *tm2Exp = (struct expression *)tm2.__exp;
	struct expression *tmp;
	tmp = new_expression(POWER);
	tmp->result_type = DetermineResultType(tm1Exp->result_type, tm2Exp->result_type);
	tmp->left = tm1Exp;
	tmp->right = tm2Exp;

	val.__exp = tmp;
}

term(val) ::= signedFactor(fact).{
	val.__exp = fact.__exp;
}


signedFactor(val) ::= PLUS factor(fact).{
	/*possibly make this imply absolute value*/
	val.__exp = fact.__exp;
}
signedFactor(val) ::= MINUS factor(fact).{
	struct expression *tmp = new_expression(MULTIPLY);
	struct expression *LHS = new_expression(DATA);
	LHS->source_type = INTEGER;
	LHS->dataSource.Integer = -1;
	tmp->left = LHS;
	tmp->right = fact.__exp;
	val.__exp = tmp;

}

signedFactor(val) ::= factor(fact).{
	val.__exp = fact.__exp;
}

factor(val) ::= LPAREN expression(expression) RPAREN.{
	val.__exp = expression.__exp;
}
factor ::= SYMBOL.

factor(val) ::= INTEGER(intToken).{
	struct expression *tmp;
	tmp = new_expression(DATA);
	tmp->source_type = INTEGER;
	tmp->dataSource.Integer = intToken.intData;
	val.__exp = tmp;
}

factor(val) ::= FLOAT(flt).{
	struct expression *tmp;
	tmp = new_expression(DATA);
	tmp->source_type = DOUBLE;
	tmp->dataSource.Float = flt.floatData;
	val.__exp = tmp;
}
