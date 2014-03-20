%include{
	#include <stdlib.h>
	#include <assert.h>
	#include "token.h"
	#include "program.h"


	struct Program *tmpHack = NULL;

	struct Program *getProgram(void *yyparser){
  		return tmpHack;
	}

}

%token_type {Token *}

%type statementgroup 	{struct Context *}
%type statement 		{struct GenericStatement *}
%type expression 		{struct Expression *}
%type definition 		{struct Symbol *}
%type datatype			{struct Symbol *}
%type term				{struct Expression *}
%type signedFactor		{struct Expression *}
%type factor 			{struct Expression *}

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
	tmpHack = malloc(sizeof(struct Program));
	tmpHack->context = stmntgrp;
}

statementgroup(val) ::=  statementgroup(stmntgrp) statement(stmt) SEMICOLON.{
	/*stmntgrp will be a Context*/
	/*stmt will be a GenericStatement*/
	struct GenericStatement *gStmnt;

	/*add statement to the end of the statement group*/
	List_Add_Value(stmntgrp->statements, stmt,struct GenericStatement *);
	if(stmt->hasDef){
		List_Add_Value(stmntgrp->symbols, stmt->sym, struct Symbol *);
	}
	val = stmntgrp;
}

statementgroup(val) ::= statement(stmt) SEMICOLON.{
	val = new_context(stmt);
}

statement(val) ::= IF LPAREN expression(test) RPAREN LCURLY statementgroup(yesCode) RCURLY.{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = IFSTATEMENT;
	stmt->ifstmt = malloc(sizeof(struct IfStatement));
	stmt->ifstmt->testStatement = test;
	stmt->ifstmt->yes = yesCode;
	stmt->ifstmt->no = NULL;
	val = stmt;
}

statement(val) ::= IF LPAREN expression(test) RPAREN LCURLY statementgroup(yesCode) RCURLY KEYWORD_ELSE LCURLY statementgroup(noCode) RCURLY.{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = IFSTATEMENT;
	stmt->ifstmt = malloc(sizeof(struct IfStatement));
	stmt->ifstmt->testStatement = test;
	stmt->ifstmt->yes = yesCode;
	stmt->ifstmt->no = noCode;
	val = stmt;
}

statement(val) ::= definition(def) EQUAL expression(initial).{
	struct Expression *dst, *exp;
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 1;
	stmt->sym = def;

	dst = new_expression(SOURCE);
	dst->dataSource.sym = def;
	dst->source_type = SYMBOL;
	
	exp = new_expression(ASSIGNMENT);
	exp->left = dst;
	exp->right = initial;

	stmt->exp = exp;
	
	val = stmt;
}

statement(val) ::= definition(def).{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 1;
	stmt->sym = def;
	stmt->exp = NULL;

	val = stmt;
}

statement(val) ::= expression(expression).{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 0;
	stmt->sym = NULL;

	stmt->exp = expression;
	
	val = stmt;
}


statement(val) ::= KEYWORD_PRINT expression(expression).{
	struct GenericStatement *stmt;
	struct Expression *print = new_expression(PRINT);
	print->left = NULL;
	print->right = expression;

	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 0;
	stmt->sym = NULL;

	stmt->exp = print;
	
	val = stmt;
}

definition(val) ::= datatype(type) IDENTIFIER(id).{
	type->name = id->literal;
	val = type;
}

datatype(val) ::= KEYWORD_INTEGER.{
	val = new_symbol(NULL, tINTEGER);
}

datatype(val) ::= KEYWORD_FLOAT.{
	val = new_symbol(NULL, tFLOAT);
}

expression(val) ::= term(tm) PLUS expression(exp).{
	struct Expression *tmp;
	tmp = new_expression(ADD);
	tmp->left = tm;
	tmp->right = exp;

	val = tmp;
}

expression(val) ::= term(tm) MINUS expression(exp).{
	struct Expression *tmp;
	tmp = new_expression(SUBTRACT);
	tmp->left = tm;
	tmp->right = exp;

	val = tmp;
}

expression(val) ::= term(tm).{
	val = tm;
}

%left MUL DIV MOD.
%right EXP.

term(val) ::= term(tm1) MUL term(tm2).{
	struct Expression *tmp;
	tmp = new_expression(MULTIPLY);
	tmp->left = tm1;
	tmp->right = tm2;

	val = tmp;
}

term(val) ::= term(tm1) DIV term(tm2).{
	struct Expression *tmp;
	tmp = new_expression(DIVIDE);
	tmp->left = tm1;
	tmp->right = tm2;

	val = tmp;
}

term(val) ::= term(tm1) MOD term(tm2).{
	struct Expression *tmp;
	tmp = new_expression(MODULUS);
	tmp->left = tm1;
	tmp->right = tm2;

	val = tmp;
}

term(val) ::= term(tm1) EXP term(tm2).{
	struct Expression *tmp;
	tmp = new_expression(POWER);
	tmp->left = tm1;
	tmp->right = tm2;

	val = tmp;
}

term(val) ::= signedFactor(fact).{
	val = fact;
}


signedFactor(val) ::= PLUS factor(fact).{
	/*possibly make this imply absolute value*/
	val = fact;
}
signedFactor(val) ::= MINUS factor(fact).{
	struct Expression *tmp = new_expression(MULTIPLY);
	struct Expression *LHS = new_expression(SOURCE);
	
	LHS->source_type = INTEGER;
	LHS->dataSource.Integer = -1;
	
	tmp->left = LHS;
	tmp->right = fact;
	
	val = tmp;
}

signedFactor(val) ::= factor(fact).{
	val = fact;
}

factor(val) ::= LPAREN expression(exp) RPAREN.{
	val = exp;
}
factor ::= SYMBOL.

factor(val) ::= INTEGER(intToken).{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = INTEGER;
	tmp->dataSource.Integer = intToken->intData;
	val = tmp;
}

factor(val) ::= FLOAT(flt).{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = FLOAT;
	tmp->dataSource.Float = flt->floatData;
	val = tmp;
}
