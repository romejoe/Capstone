%include{
	#include <stdlib.h>
	#include <assert.h>
	#include "token.h"
	#include "program.h"
/*
	char isFloatType(enum data_type type){
		return (type == tFLOAT || type == tDOUBLE);
	}

	enum data_type DetermineResultType(enum data_type type1, enum data_type type2){
		enum data_type ret;
		check if same type
		if(type1 == type2){
			return type1;
		}
		check for void types
		if(type1 == tVOID || type2 == tVOID){
			return tVOID;
		}

		ret = (type1 > type2)? type1 : type2;


		check wether they are both just integers
		if(isFloatType(type1) || isFloatType(type2)){
			switch(ret){
				case tBOOL:
				case tCHAR:
				case tSHORT:
				case tINT:
					return tFLOAT;
				case tLONG:
					return tDOUBLE;
				default:
				;
			}
			
		}
		return ret;
	}
*/
	struct Program *tmpHack = NULL;

	struct Program *getProgram(void *yyparser){
  		return tmpHack;
	}

}

%token_type {Token *}
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
	tmpHack->context = stmntgrp->context;
}

statementgroup(val) ::=  statement(stmt) SEMICOLON statementgroup(stmntgrp).{
	struct Expression *tmp;
	struct Context *lContext, *rContext;
	struct List *lSymbols, *rSymbols;
	struct Symbol *sym;
	lContext = stmt->context;
	rContext = stmntgrp->context;

	/*merge expressions*/
	tmp = new_expression(PASS);
	tmp->left = lContext->exp;
	tmp->right = rContext->exp;

	rContext->exp = tmp;

	/*merge symbols*/
	lSymbols = lContext->exports.symbols;
	rSymbols = rContext->exports.symbols;
	printf("here\n");
	if(lSymbols){
		printf("lSymbols:\n");
		List_ForEach(lSymbols, {
			sym = List_Ref_Value(lSymbols, i, struct Symbol *);
			printSymbol(sym);	
		});
	}

	if(rSymbols){
		printf("rSymbols:\n");
		List_ForEach(rSymbols, {
			sym = List_Ref_Value(rSymbols, i, struct Symbol *);
			printSymbol(sym);	
		});
	}

	if(lSymbols){
		printf("Merging Lists\n");
		printf("lSymbols ptr = %p\n", lSymbols);
		printf("rSymbols ptr = %p\n", rSymbols);
		List_ForEach(lSymbols, {
			sym = List_Ref_Value(lSymbols, i, struct Symbol *);
			printSymbol(sym);	
		});
	List_ForEach(lSymbols, {
		sym = List_Ref_Value(lSymbols, i, struct Symbol *);
		printSymbol(sym);
		List_Add_Value(rSymbols, sym, struct Symbol *);
	});
}
	val = (Token *) malloc(sizeof(Token));
	val->context = rContext;
}

statementgroup(val) ::= statement(stmt) SEMICOLON.{
	struct Context *context;
	struct List *symbolList;

	symbolList = stmt->context->exports.symbols;
	if(!symbolList){ 
		symbolList = (struct List *) malloc(sizeof(struct List));
		newList(symbolList, struct Symbol *);	
	}

	context = new_context(stmt->context->exp, symbolList, 2);
	

	val = (Token *) malloc(sizeof(Token));
	val->context = context;
}

statement ::= IF LPAREN expression RPAREN LCURLY statementgroup RCURLY.
statement(val) ::= definition(def) EQUAL expression(initial).{
	struct Context *context;
	struct Expression *dst, *exp;
	
	context = def->context;

	dst = new_expression(SOURCE);
	dst->dataSource.sym = List_Ref_Value(context->exports.symbols, 0, struct Symbol *);
	dst->source_type = SYMBOL;
	exp = new_expression(ASSIGNMENT);
	exp->left = dst;
	exp->right = initial->context->exp;

	context->exp = exp;
	val = (Token *) malloc(sizeof(Token));
	val->context = context;
}

statement(val) ::= definition(def).{
	val = (Token *) malloc(sizeof(Token));
	val->context = def->context;
}

statement(val) ::= expression(exp).{
	val = (Token *) malloc(sizeof(Token));
	val->context = exp->context;
}

definition(val) ::= datatype(type) IDENTIFIER(id).{
	struct Symbol **sym = List_Ref(type->context->exports.symbols, 0);
	(*sym)->name = id->literal;

	printf("_List Ptr = %p\n", type->context->exports.symbols);
	printf("[0] = %p\n", *sym);
	printf("Haz definition\n");
	printSymbol(*sym);
	val = (Token *) malloc(sizeof(Token));
	val->context = type->context;
}

datatype(val) ::= KEYWORD_INTEGER.{
	struct Symbol *sym = new_symbol(NULL, tINTEGER);
	struct List *list = (struct List *) malloc(sizeof(struct List));
	struct Context *context;
printf("IList Ptr = %p\n", list);
printf("Isym Ptr = %p\n", sym);
	newList(list, struct Symbol *);
	List_Add_Value(list, sym, struct Symbol *);
	
	context = new_context(NULL, list, 2);
	
	val = (Token *) malloc(sizeof(Token));
	val->context = context;
}

datatype(val) ::= KEYWORD_FLOAT.{
	struct Symbol *sym = new_symbol(NULL, tFLOAT);
	struct List *list = (struct List *) malloc(sizeof(struct List));
	printf("FList Ptr = %p\n", list);
	printf("Fsym Ptr = %p\n", sym);
	struct Context *context;
	newList(list, struct Symbol *);
	List_Add_Value(list, sym, struct Symbol *);
	context = new_context(NULL, list, 2);
	val = (Token *) malloc(sizeof(Token));
	val->context = context;
}

expression(val) ::= term(tm) PLUS expression(expTkn).{
	struct Expression *tmExp = tm->context->exp;
	struct Expression *expExp = expTkn->context->exp;
	struct Expression *tmp;
	tmp = new_expression(ADD);
	tmp->left = tmExp;
	tmp->right = expExp;

	expTkn->context->exp = tmp;
	val = (Token *) malloc(sizeof(Token));
	val->context = expTkn->context;
}

expression(val) ::= term(tm) MINUS expression(expTkn).{
	struct Expression *tmExp = tm->context->exp;
	struct Expression *expExp = expTkn->context->exp;
	struct Expression *tmp;
	tmp = new_expression(SUBTRACT);
	tmp->left = tmExp;
	tmp->right = expExp;

	expTkn->context->exp = tmp;
	val = (Token *) malloc(sizeof(Token));
	val->context = expTkn->context;
}

expression(val) ::= term(tm).{
	val = (Token *) malloc(sizeof(Token));
	val->context = tm->context;
}

%left MUL DIV MOD.
%right EXP.

term(val) ::= term(tm1) MUL term(tm2).{
	struct Expression *tm1Exp = tm1->context->exp;
	struct Expression *tm2Exp = tm2->context->exp;
	struct Expression *tmp;
	tmp = new_expression(MULTIPLY);
	tmp->left = tm1Exp;
	tmp->right = tm2Exp;

	tm2->context->exp = tmp;
	val = (Token *) malloc(sizeof(Token));
	val->context = tm2->context;
}

term(val) ::= term(tm1) DIV term(tm2).{
	struct Expression *tm1Exp = tm1->context->exp;
	struct Expression *tm2Exp = tm2->context->exp;
	struct Expression *tmp;
	tmp = new_expression(DIVIDE);
	tmp->left = tm1Exp;
	tmp->right = tm2Exp;

	tm2->context->exp = tmp;
	val = (Token *) malloc(sizeof(Token));
	val->context = tm2->context;
}

term(val) ::= term(tm1) MOD term(tm2).{
	struct Expression *tm1Exp = tm1->context->exp;
	struct Expression *tm2Exp = tm2->context->exp;
	struct Expression *tmp;
	tmp = new_expression(MODULUS);
	tmp->left = tm1Exp;
	tmp->right = tm2Exp;

	tm2->context->exp = tmp;
	val = (Token *) malloc(sizeof(Token));
	val->context = tm2->context;
}

term(val) ::= term(tm1) EXP term(tm2).{
	struct Expression *tm1Exp = tm1->context->exp;
	struct Expression *tm2Exp = tm2->context->exp;
	struct Expression *tmp;
	tmp = new_expression(POWER);
	tmp->left = tm1Exp;
	tmp->right = tm2Exp;

	tm2->context->exp = tmp;
	val = (Token *) malloc(sizeof(Token));
	val->context = tm2->context;
}

term(val) ::= signedFactor(fact).{
	val = (Token *) malloc(sizeof(Token));
	val->context = fact->context;
}


signedFactor(val) ::= PLUS factor(fact).{
	/*possibly make this imply absolute value*/
	val = (Token *) malloc(sizeof(Token));
	val->context = fact->context;
}
signedFactor(val) ::= MINUS factor(fact).{
	struct Expression *tmp = new_expression(MULTIPLY);
	struct Expression *LHS = new_expression(SOURCE);
	
	LHS->source_type = INTEGER;
	LHS->dataSource.Integer = -1;
	
	tmp->left = LHS;
	tmp->right = fact->context->exp;
	
	fact->context->exp = tmp;
	val = (Token *) malloc(sizeof(Token));
	val->context = fact->context;

}

signedFactor(val) ::= factor(fact).{
	val = (Token *) malloc(sizeof(Token));
	val->context = fact->context;
}

factor(val) ::= LPAREN expression(expression) RPAREN.{
	val = (Token *) malloc(sizeof(Token));
	val->context = expression->context;
}
factor ::= SYMBOL.

factor(val) ::= INTEGER(intToken).{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = INTEGER;
	tmp->dataSource.Integer = intToken->intData;
	val = (Token *) malloc(sizeof(Token));
	val->context = new_context(tmp, NULL, 0);
}

factor(val) ::= FLOAT(flt).{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = FLOAT;
	tmp->dataSource.Float = flt->floatData;
	val = (Token *) malloc(sizeof(Token));
	val->context = new_context(tmp, NULL, 0);
}
