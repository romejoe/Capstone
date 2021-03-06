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

%type statementgroup 		{struct Context *}
%type statement 			{struct GenericStatement *}
%type flowstatement 		{struct GenericStatement *}
%type fexpression 			{struct Expression *}
%type expression 			{struct Expression *}
%type definition	 		{struct Symbol *}
%type datatype				{struct Symbol *}
%type term					{struct Expression *}
%type signedFactor			{struct Expression *}
%type factor 				{struct Expression *}

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
	stmntgrp->parent = NULL;
	tmpHack->context = stmntgrp;
}

statementgroup(val) ::=  statementgroup(stmntgrp) statement(stmt) SEMICOLON.{
	/*stmntgrp will be a Context*/
	/*stmt will be a GenericStatement*/
	struct GenericStatement *gStmnt;

	/*add statement to the end of the statement group*/
	List_Add_Value(stmntgrp->statements, stmt, struct GenericStatement *);
	if(stmt->hasDef){
		List_Add_Value(stmntgrp->symbols, stmt->sym, struct Symbol *);
	}
	if(stmt->type == IFSTATEMENT){
		stmt->ifstmt->yes->parent = stmntgrp;
		if(stmt->ifstmt->no){
			stmt->ifstmt->no->parent = stmntgrp;
		}
	}
	else if (stmt->type == WHILESTATEMENT){
		stmt->whilestmt->code->parent = stmntgrp;
	}
	val = stmntgrp;
}

statementgroup(val) ::=  statementgroup(stmntgrp) flowstatement(stmt).{
	/*stmntgrp will be a Context*/
	/*stmt will be a GenericStatement*/
	struct GenericStatement *gStmnt;

	printf("\t\tf\n");
	/*add statement to the end of the statement group*/
	List_Add_Value(stmntgrp->statements, stmt,struct GenericStatement *);
	if(stmt->hasDef){
		List_Add_Value(stmntgrp->symbols, stmt->sym, struct Symbol *);
	}

	if(stmt->type == IFSTATEMENT){
		stmt->ifstmt->yes->parent = stmntgrp;
		if(stmt->ifstmt->no){
			stmt->ifstmt->no->parent = stmntgrp;
		}
	}
	else if (stmt->type == WHILESTATEMENT){
		stmt->whilestmt->code->parent = stmntgrp;
	}
	val = stmntgrp;
}

statementgroup(val) ::= flowstatement(stmt).{
	printf("\t\tasdf\n");
	val = new_context(stmt);
	if(stmt->type == IFSTATEMENT){
		stmt->ifstmt->yes->parent = val;
		if(stmt->ifstmt->no){
			stmt->ifstmt->no->parent = val;
		}
	}
	else if (stmt->type == WHILESTATEMENT){
		stmt->whilestmt->code->parent = val;
	}
}

statementgroup(val) ::= statement(stmt) SEMICOLON.{
	val = new_context(stmt);
}


flowstatement(val) ::= KEYWORD_IF LPAREN fexpression(test) RPAREN LCURLY statementgroup(yesCode) RCURLY.{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = IFSTATEMENT;
	stmt->ifstmt = malloc(sizeof(struct IfStatement));
	stmt->ifstmt->testStatement = test;
	stmt->ifstmt->yes = yesCode;
	stmt->ifstmt->no = NULL;
	val = stmt;
}

flowstatement(val) ::= KEYWORD_IF LPAREN fexpression(test) RPAREN LCURLY statementgroup(yesCode) RCURLY KEYWORD_ELSE LCURLY statementgroup(noCode) RCURLY.{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = IFSTATEMENT;
	stmt->ifstmt = malloc(sizeof(struct IfStatement));
	stmt->ifstmt->testStatement = test;
	stmt->ifstmt->yes = yesCode;
	stmt->ifstmt->no = noCode;
	val = stmt;
}

flowstatement(val) ::= KEYWORD_WHILE LPAREN fexpression(test) RPAREN LCURLY statementgroup(loopCode) RCURLY.{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = WHILESTATEMENT;
	stmt->ifstmt = malloc(sizeof(struct WhileStatement));
	stmt->whilestmt->testStatement = test;
	stmt->whilestmt->code = loopCode;
	val = stmt;
}

statement(val) ::= definition(def) EQUAL fexpression(initial).{
	struct Expression *dst;
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 1;
	stmt->sym = def;

	dst = new_expression(SOURCE);
	dst->dataSource.sym = def;
	dst->source_type = SYMBOL;
	
	stmt->exp = new_expression_children(ASSIGNMENT, dst, initial);
	
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

statement(val) ::= IDENTIFIER(id) EQUAL fexpression(fexp).{
	struct Expression *dst;
	struct GenericStatement *stmt;

	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 0;

	dst = new_expression(SOURCE);
	dst->dataSource.sym = new_symbol(id->literal, tVOID);;
	dst->source_type = SYMBOL;
	
	stmt->exp = new_expression_children(ASSIGNMENT, dst, fexp);
	
	val = stmt;
}

statement(val) ::= fexpression(expression).{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 0;
	stmt->sym = NULL;

	stmt->exp = expression;
	
	val = stmt;
}


statement(val) ::= KEYWORD_PRINT fexpression(expression).{
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


fexpression(val) ::= expression(leftExp) LOGICAL_EQ fexpression(rightExp).{
	val = new_expression_children(CHECK_EQ, leftExp, rightExp);
}

fexpression(val) ::= expression(leftExp) LOGICAL_NE fexpression(rightExp).{
	val = new_expression_children(CHECK_NE, leftExp, rightExp);
}

fexpression(val) ::= expression(leftExp) LOGICAL_GT fexpression(rightExp).{
	val = new_expression_children(CHECK_GT, leftExp, rightExp);
}

fexpression(val) ::= expression(leftExp) LOGICAL_LT fexpression(rightExp).{
	val = new_expression_children(CHECK_LT, leftExp, rightExp);
}

fexpression(val) ::= expression(leftExp) LOGICAL_GTE fexpression(rightExp).{
	val = new_expression_children(CHECK_GTE, leftExp, rightExp);
}

fexpression(val) ::= expression(leftExp) LOGICAL_LTE fexpression(rightExp).{
	val = new_expression_children(CHECK_LTE, leftExp, rightExp);
}

fexpression(val) ::= expression(leftExp) LOGICAL_AND fexpression(rightExp).{
	val = new_expression_children(LOG_AND, leftExp, rightExp);
}

fexpression(val) ::= expression(leftExp) LOGICAL_OR fexpression(rightExp).{
	val = new_expression_children(LOG_OR, leftExp, rightExp);
}

fexpression(val) ::= expression(leftExp) LOGICAL_XOR fexpression(rightExp).{
	val = new_expression_children(LOG_XOR, leftExp, rightExp);
}

fexpression(val) ::= expression(exp).{
	val = exp;
}

expression(val) ::= term(tm) PLUS expression(exp).{
	val = new_expression_children(ADD, tm, exp);
}

expression(val) ::= term(tm) MINUS expression(exp).{
	val = new_expression_children(SUBTRACT, tm, exp);
}

expression(val) ::= term(tm).{
	val = tm;
}

%left MUL DIV MOD.
%right EXP.

term(val) ::= term(tm1) MUL term(tm2).{
	val = new_expression_children(MULTIPLY, tm1, tm2);
}

term(val) ::= term(tm1) DIV term(tm2).{
	val = new_expression_children(DIVIDE, tm1, tm2);
}

term(val) ::= term(tm1) MOD term(tm2).{
	val = new_expression_children(MODULUS, tm1, tm2);
}

term(val) ::= term(tm1) EXP term(tm2).{
	val = new_expression_children(POWER, tm1, tm2);
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

signedFactor(val) ::= LOGICAL_NOT factor(factor).{
	val = new_expression_children(LOG_NOT, NULL, factor);
}

signedFactor(val) ::= factor(fact).{
	val = fact;
}

factor(val) ::= LPAREN fexpression(exp) RPAREN.{
	val = exp;
}
factor(val) ::= IDENTIFIER(symToken).{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = SYMBOL;
	tmp->dataSource.sym = new_symbol(symToken->literal, tVOID);
	val = tmp;
}

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
