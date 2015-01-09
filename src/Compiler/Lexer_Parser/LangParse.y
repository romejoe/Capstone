%include{
	#include <stdlib.h>
	#include <assert.h>
	#include "token.hpp"
	#include "program.hpp"


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
	tmpHack = new Program();
//	tmpHack = malloc(sizeof(struct Program));
	stmntgrp->parent = NULL;
	tmpHack->context = stmntgrp;
}

statementgroup(val) ::=  statementgroup(stmntgrp) statement(stmt) SEMICOLON.{
	/*stmntgrp will be a Context*/
	/*stmt will be a GenericStatement*/
	struct GenericStatement *gStmnt = (GenericStatement *) stmt;

	/*add statement to the end of the statement group*/
	stmntgrp->statements.push_back(gStmnt);

	if(stmt->hasDef){
		stmntgrp->symbols.push_back(gStmnt->sym);
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
	struct GenericStatement *gStmnt = stmt;

	printf("\t\tf\n");
	/*add statement to the end of the statement group*/
	stmntgrp->statements.push_back(gStmnt);
	if(stmt->hasDef){
		stmntgrp->symbols.push_back(gStmnt->sym);
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
	val = new Context(stmt);
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
	val = new Context(stmt);
}


flowstatement(val) ::= KEYWORD_IF LPAREN fexpression(test) RPAREN LCURLY statementgroup(yesCode) RCURLY.{
	struct GenericStatement *stmt;
	stmt = new GenericStatement();
	stmt->type = IFSTATEMENT;
	stmt->ifstmt = new IfStatement();
	stmt->ifstmt->testStatement = test;
	stmt->ifstmt->yes = yesCode;
	stmt->ifstmt->no = NULL;
	val = stmt;
}

flowstatement(val) ::= KEYWORD_IF LPAREN fexpression(test) RPAREN LCURLY statementgroup(yesCode) RCURLY KEYWORD_ELSE LCURLY statementgroup(noCode) RCURLY.{
	struct GenericStatement *stmt;
	stmt = new GenericStatement();
	stmt->type = IFSTATEMENT;
	stmt->ifstmt = new IfStatement();
	stmt->ifstmt->testStatement = test;
	stmt->ifstmt->yes = yesCode;
	stmt->ifstmt->no = noCode;
	val = stmt;
}

flowstatement(val) ::= KEYWORD_WHILE LPAREN fexpression(test) RPAREN LCURLY statementgroup(loopCode) RCURLY.{
	struct GenericStatement *stmt;
	stmt = new GenericStatement();
	stmt->type = WHILESTATEMENT;
	stmt->whilestmt = new WhileStatement();
	stmt->whilestmt->testStatement = test;
	stmt->whilestmt->code = loopCode;
	val = stmt;
}

statement(val) ::= definition(def) EQUAL fexpression(initial).{
	struct Expression *dst;
	struct GenericStatement *stmt;
	stmt = new GenericStatement();
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 1;
	stmt->sym = def;

	dst = new Expression(SOURCE);
	dst->dataSource.sym = def;
	dst->source_type = SYMBOL;
	
	stmt->exp = new Expression(ASSIGNMENT, dst, initial);
	
	val = stmt;
}

statement(val) ::= definition(def).{
	struct GenericStatement *stmt;
	stmt = new GenericStatement();
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 1;
	stmt->sym = def;
	stmt->exp = NULL;

	val = stmt;
}

statement(val) ::= IDENTIFIER(id) EQUAL fexpression(fexp).{
	struct Expression *dst;
	struct GenericStatement *stmt;

	stmt = new GenericStatement();
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 0;

	dst = new Expression(SOURCE);
	dst->dataSource.sym = new Symbol(id->literal, tVOID);;
	dst->source_type = SYMBOL;
	
	stmt->exp = new Expression(ASSIGNMENT, dst, fexp);
	
	val = stmt;
}

statement(val) ::= fexpression(expression).{
	struct GenericStatement *stmt;
	stmt = new GenericStatement();
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 0;
	stmt->sym = NULL;

	stmt->exp = expression;
	
	val = stmt;
}


statement(val) ::= KEYWORD_PRINT fexpression(expression).{
	struct GenericStatement *stmt;
	struct Expression *print = new Expression(PRINT);
	print->left = NULL;
	print->right = expression;

	stmt = new GenericStatement();
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
	val = new Symbol(NULL, tINTEGER);
}

datatype(val) ::= KEYWORD_FLOAT.{
	val = new Symbol(NULL, tFLOAT);
}


fexpression(val) ::= expression(leftExp) LOGICAL_EQ fexpression(rightExp).{
	val = new Expression(CHECK_EQ, leftExp, rightExp);
}

fexpression(val) ::= expression(leftExp) LOGICAL_NE fexpression(rightExp).{
	val = new Expression(CHECK_NE, leftExp, rightExp);
}

fexpression(val) ::= expression(leftExp) LOGICAL_GT fexpression(rightExp).{
	val = new Expression(CHECK_GT, leftExp, rightExp);
}

fexpression(val) ::= expression(leftExp) LOGICAL_LT fexpression(rightExp).{
	val = new Expression(CHECK_LT, leftExp, rightExp);
}

fexpression(val) ::= expression(leftExp) LOGICAL_GTE fexpression(rightExp).{
	val = new Expression(CHECK_GTE, leftExp, rightExp);
}

fexpression(val) ::= expression(leftExp) LOGICAL_LTE fexpression(rightExp).{
	val = new Expression(CHECK_LTE, leftExp, rightExp);
}

fexpression(val) ::= expression(leftExp) LOGICAL_AND fexpression(rightExp).{
	val = new Expression(LOG_AND, leftExp, rightExp);
}

fexpression(val) ::= expression(leftExp) LOGICAL_OR fexpression(rightExp).{
	val = new Expression(LOG_OR, leftExp, rightExp);
}

fexpression(val) ::= expression(leftExp) LOGICAL_XOR fexpression(rightExp).{
	val = new Expression(LOG_XOR, leftExp, rightExp);
}

fexpression(val) ::= expression(exp).{
	val = exp;
}

expression(val) ::= term(tm) PLUS expression(exp).{
	val = new Expression(ADD, tm, exp);
}

expression(val) ::= term(tm) MINUS expression(exp).{
	val = new Expression(SUBTRACT, tm, exp);
}

expression(val) ::= term(tm).{
	val = tm;
}

%left MUL DIV MOD.
%right EXP.

term(val) ::= term(tm1) MUL term(tm2).{
	val = new Expression(MULTIPLY, tm1, tm2);
}

term(val) ::= term(tm1) DIV term(tm2).{
	val = new Expression(DIVIDE, tm1, tm2);
}

term(val) ::= term(tm1) MOD term(tm2).{
	val = new Expression(MODULUS, tm1, tm2);
}

term(val) ::= term(tm1) EXP term(tm2).{
	val = new Expression(POWER, tm1, tm2);
}

term(val) ::= signedFactor(fact).{
	val = fact;
}

signedFactor(val) ::= PLUS factor(fact).{
	/*possibly make this imply absolute value*/
	val = fact;
}
signedFactor(val) ::= MINUS factor(fact).{
	struct Expression *tmp = new Expression(MULTIPLY);
	struct Expression *LHS = new Expression(SOURCE);
	
	LHS->source_type = INTEGER;
	LHS->dataSource.Integer = -1;
	
	tmp->left = LHS;
	tmp->right = fact;
	
	val = tmp;
}

signedFactor(val) ::= LOGICAL_NOT factor(factor).{
	val = new Expression(LOG_NOT, NULL, factor);
}

signedFactor(val) ::= factor(fact).{
	val = fact;
}

factor(val) ::= LPAREN fexpression(exp) RPAREN.{
	val = exp;
}
factor(val) ::= IDENTIFIER(symToken).{
	struct Expression *tmp;
	tmp = new Expression(SOURCE);
	tmp->source_type = SYMBOL;
	tmp->dataSource.sym = new Symbol(symToken->literal, tVOID);
	val = tmp;
}

factor(val) ::= INTEGER(intToken).{
	struct Expression *tmp;
	tmp = new Expression(SOURCE);
	tmp->source_type = INTEGER;
	tmp->dataSource.Integer = intToken->intData;
	val = tmp;
}

factor(val) ::= FLOAT(flt).{
	struct Expression *tmp;
	tmp = new Expression(SOURCE);
	tmp->source_type = FLOAT;
	tmp->dataSource.Float = flt->floatData;
	val = tmp;
}
