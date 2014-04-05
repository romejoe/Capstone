%{
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "LangParse.h"
#include "token.h"


struct lexerData{
	void *_pParser;
	struct Program *_program;
};

void LEXDEBUG_LOG(const char *item, char *ytext) {
	#ifdef __LEX_DEBUG__
		fprintf(stderr, "Found %s => {%s}\n", item, ytext);
	#endif
}

void *ParseAlloc(void *(*mallocProc)(size_t));
struct Program *getProgram(void *yyparser);
%}

%option noyywrap
%option reentrant
%option extra-type="struct lexerData *"

DIGIT		[0-9]
WHITESPACE 	[ \t\n\r]

%%

	/* Integer */
{DIGIT}+ { 
	LEXDEBUG_LOG("Integer", yytext);
	Token *tok = getToken(yytext, INTEGER);
	
	Parse(yyextra->_pParser, T_INTEGER, tok);
}

	/* Float */
{DIGIT}*"."{DIGIT}* { 
	LEXDEBUG_LOG("Float", yytext);
	Token *tok = getToken(yytext, FLOAT);
	
	Parse(yyextra->_pParser, T_FLOAT, tok);
}

"if" {
	LEXDEBUG_LOG("IF", yytext);
	
	Parse(yyextra->_pParser, T_KEYWORD_IF, NULL);
}

"else" {
	LEXDEBUG_LOG("ELSE", yytext);
	
	Parse(yyextra->_pParser, T_KEYWORD_ELSE, NULL);
}

"while" {
	LEXDEBUG_LOG("WHILE", yytext);
	Parse(yyextra->_pParser, T_KEYWORD_WHILE, NULL);
}

"print" {
	LEXDEBUG_LOG("PRINT KEYWORD", yytext);
	Parse(yyextra->_pParser, T_KEYWORD_PRINT, NULL);
}

"Integer" {
	LEXDEBUG_LOG("INTEGER KEYWORD", yytext);
	Parse(yyextra->_pParser, T_KEYWORD_INTEGER, NULL);
}

"Float" {
	LEXDEBUG_LOG("FLOAT KEYWORD", yytext);
	Parse(yyextra->_pParser, T_KEYWORD_FLOAT, NULL);
}


	/* Identifier */
[a-zA-Z_]([a-zA-Z_]|{DIGIT})* { 
	LEXDEBUG_LOG("Identifier", yytext);
	Token *tok = getToken(yytext, SYMBOL);
	Parse(yyextra->_pParser, T_IDENTIFIER, tok);
}

	/* Parenthesis Section */
"(" { 
	LEXDEBUG_LOG("Left Paren", yytext);
	/*Token *tok = getToken(yytext, NA);*/
	
	Parse(yyextra->_pParser, T_LPAREN, NULL);
}
")" { 
	LEXDEBUG_LOG("Right Paren => )\n", yytext); 
	/*Token *tok = getToken(yytext, NA);*/
	
	Parse(yyextra->_pParser, T_RPAREN, NULL);
}
	/* Curly Brace Section */
"{" { 
	LEXDEBUG_LOG("Left Curly", yytext);
	Token *tok = getToken(yytext, NA);
	
	Parse(yyextra->_pParser, T_LCURLY, tok);
}
"}" { 
	LEXDEBUG_LOG("Right Curly", yytext);
	Token *tok = getToken(yytext, NA);
	
	Parse(yyextra->_pParser, T_RCURLY, tok);
}

	/* Square Brace Section */
"[" { 
	LEXDEBUG_LOG("Left Bracket", yytext);
	
	/*Parse(yyextra->_pParser, T_, <<<token>>>);*/
}
"]" { 
	LEXDEBUG_LOG("Right Bracket", yytext);
	
	/*Parse(yyextra->_pParser, T_, <<<token>>>);*/
}

	/* Operator Section */
"+" { 
	LEXDEBUG_LOG("Plus", yytext);
	Token *tok = getToken(yytext, NA);
	/*printf("prog = %p\n".prog);*/
	Parse(yyextra->_pParser, T_PLUS, tok);
}
"-" { 
	LEXDEBUG_LOG("Minus", yytext);
	Token *tok = getToken(yytext, NA);
	
	Parse(yyextra->_pParser, T_MINUS, tok);
}
"*" { 
	LEXDEBUG_LOG("Multiplication", yytext);
	Token *tok = getToken(yytext, NA);
	
	Parse(yyextra->_pParser, T_MUL, tok);
}
"/" { 
	LEXDEBUG_LOG("Division", yytext);
	Token *tok = getToken(yytext, NA);
	
	Parse(yyextra->_pParser, T_DIV, tok);
}
"%" { 
	LEXDEBUG_LOG("Mod", yytext);
	Token *tok = getToken(yytext, NA);
	
	Parse(yyextra->_pParser, T_MOD, tok);
}
"^" { 
	LEXDEBUG_LOG("Exp", yytext);
	Token *tok = getToken(yytext, NA);
	
	Parse(yyextra->_pParser, T_EXP, tok);
}
"=" { 
	LEXDEBUG_LOG("Equal", yytext);
	
	Parse(yyextra->_pParser, T_EQUAL, NULL);
}

	/* Comparison Operator Section */
"==" { 
	LEXDEBUG_LOG("Equality", yytext);
	
	Parse(yyextra->_pParser, T_LOGICAL_EQ, NULL);
}
"!=" { 
	LEXDEBUG_LOG("Not Equality", yytext);
	
	Parse(yyextra->_pParser, T_LOGICAL_NE, NULL);
}
">" { 
	LEXDEBUG_LOG("Greater Than", yytext);
	
	Parse(yyextra->_pParser, T_LOGICAL_GT, NULL);
}
"<" { 
	LEXDEBUG_LOG("Less Than", yytext);
	
	Parse(yyextra->_pParser, T_LOGICAL_LT, NULL);
}
">=" { 
	LEXDEBUG_LOG("Greater Than or Equal", yytext);
	
	Parse(yyextra->_pParser, T_LOGICAL_GTE, NULL);
}
"<=" { 
	LEXDEBUG_LOG("Less Than or Equal", yytext);
	
	Parse(yyextra->_pParser, T_LOGICAL_LTE, NULL);
}
	
	/* Logical Operator Section */
"!" { 
	LEXDEBUG_LOG("Logical Not", yytext);
	
	/*Parse(yyextra->_pParser, T_, <<<token>>>);*/
}
"&&" { 
	LEXDEBUG_LOG("Logical AND", yytext);
	
	/*Parse(yyextra->_pParser, T_, <<<token>>>);*/
}
"||" { 
	LEXDEBUG_LOG("Logical OR", yytext);
	
	/*Parse(yyextra->_pParser, T_, <<<token>>>);*/
}
"@@" { 
	LEXDEBUG_LOG("Logical XOR", yytext);
	
	/*Parse(yyextra->_pParser, T_, <<<token>>>);*/
}

	/* Bitwise Operator Section */
"~" { 
	LEXDEBUG_LOG("Bitwise Not", yytext);
	
	/*Parse(yyextra->_pParser, T_, <<<token>>>);*/
}
"&" { 
	LEXDEBUG_LOG("Bitwise AND", yytext);
	
	/*Parse(yyextra->_pParser, T_, <<<token>>>);*/
}
"|" { 
	LEXDEBUG_LOG("Bitwise OR", yytext);
	
	/*Parse(yyextra->_pParser, T_, <<<token>>>);*/
}
"@" { 
	LEXDEBUG_LOG("Bitwise XOR", yytext);
	
	/*Parse(yyextra->_pParser, T_, <<<token>>>);*/
}
"<<" { 
	LEXDEBUG_LOG("Bitwise Left Shift", yytext);
	
	/*Parse(yyextra->_pParser, T_, <<<token>>>);*/
}
">>" { 
	LEXDEBUG_LOG("Bitwise Right Shift", yytext);
	
	/*Parse(yyextra->_pParser, T_, <<<token>>>);*/
}


	/* String Section */
\"[^\"]*\" { 
	LEXDEBUG_LOG("String", yytext);
	
	/*Parse(yyextra->_pParser, T_, <<<token>>>);*/
}

	/* Semicolon Section */
";" { 
	LEXDEBUG_LOG("Semicolon", yytext);
	Token *tok = getToken(yytext, NA);
	
	Parse(yyextra->_pParser, T_SEMICOLON, tok);
}

	/* Comment Section */
"//"[^\n]* {
	LEXDEBUG_LOG("Single Line Comment", yytext);
}

"/*"([^*]*|[^*][^\/]*)*"*/" {
	LEXDEBUG_LOG("Block Comment", yytext);
}

{WHITESPACE}+ /* ignore whitespace */

. { 
	LEXDEBUG_LOG("unknown char", yytext);
}

%%

#ifndef ___LEX_LIBRARY___
	int main(int argc, char **argv){
		++argv, --argc;
		if ( argc > 0 )
    		yyin = fopen( argv[0], "r" );
		else
    		yyin = stdin;
    	yylex();
	}

#endif


	struct Program* parseString(char *srcCode){
		yyscan_t scanner;
		YY_BUFFER_STATE in;
		struct lexerData extraData;
		void *_pParser = ParseAlloc( malloc );
		extraData._pParser = _pParser;
		#ifdef __LEX_DEBUG__
			ParseTrace(stdout, "\t\t@@@ ");
		#endif

		yylex_init_extra(&extraData, &scanner);
		in = yy_scan_string(srcCode, scanner);
		yylex(scanner);
		yy_delete_buffer(in, scanner);
		yylex_destroy(scanner);

		Parse(extraData._pParser, 0, NULL);
		
		return getProgram(extraData._pParser);
	}