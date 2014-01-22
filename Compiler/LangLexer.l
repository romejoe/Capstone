%{
#include <stdio.h>
#include "lexer.h"
#include "LangParse.h"
#include "token.h"

struct lexerData{
	void *_pParser;
	struct program * _program;
};

#define ___LEX_DEBUG___ 1

void LEXDEBUG_LOG(const char *item, char *ytext) {
	#ifdef ___LEX_DEBUG___ 
		fprintf(stderr, "Found %s => {%s}\n", item, ytext);
	#endif
}
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
	Token *tok = getToken(yytext, NA);
	Parse(yyextra->_pParser, T_IF, tok);
}

	/* Identifier */
[a-zA-Z_]([a-zA-Z_]|{DIGIT})* { 
	LEXDEBUG_LOG("Identifier", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}

	/* Parenthesis Section */
"(" { 
	LEXDEBUG_LOG("Left Paren", yytext);
	Token *tok = getToken(yytext, NA);
	Parse(yyextra->_pParser, T_LPAREN, tok);
}
")" { 
	LEXDEBUG_LOG("Right Paren => )\n", yytext); 
	Token *tok = getToken(yytext, NA);
	Parse(yyextra->_pParser, T_RPAREN, tok);
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
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}
"]" { 
	LEXDEBUG_LOG("Right Bracket", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}

	/* Operator Section */
"+" { 
	LEXDEBUG_LOG("Plus", yytext);
	Token *tok = getToken(yytext, NA);
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
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}

	/* Comparison Operator Section */
"==" { 
	LEXDEBUG_LOG("Equality", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}
"!=" { 
	LEXDEBUG_LOG("Not Equality", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}
">" { 
	LEXDEBUG_LOG("Greater Than", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}
"<" { 
	LEXDEBUG_LOG("Less Than", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}
">=" { 
	LEXDEBUG_LOG("Greater Than or Equal", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}
"<=" { 
	LEXDEBUG_LOG("Less Than or Equal", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}
	
	/* Logical Operator Section */
"!" { 
	LEXDEBUG_LOG("Logical Not", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}
"&&" { 
	LEXDEBUG_LOG("Logical AND", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}
"||" { 
	LEXDEBUG_LOG("Logical OR", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}
"@@" { 
	LEXDEBUG_LOG("Logical XOR", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}

	/* Bitwise Operator Section */
"~" { 
	LEXDEBUG_LOG("Bitwise Not", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}
"&" { 
	LEXDEBUG_LOG("Bitwise AND", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}
"|" { 
	LEXDEBUG_LOG("Bitwise OR", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}
"@" { 
	LEXDEBUG_LOG("Bitwise XOR", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}
"<<" { 
	LEXDEBUG_LOG("Bitwise Left Shift", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}
">>" { 
	LEXDEBUG_LOG("Bitwise Right Shift", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
}


	/* String Section */
\"[^\"]*\" { 
	LEXDEBUG_LOG("String", yytext);
	//Parse(yyextra->_pParser, T_, <<<token>>>);
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

"/*".*"*/" { 
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


	struct program* parseString(char *srcCode){
		yyscan_t scanner;
		YY_BUFFER_STATE in;
		struct lexerData extraData;
		extraData._pParser = ParseAlloc( malloc );
		
		#ifdef ___LEX_DEBUG___
			ParseTrace(stdout, "\t\t@@@ ");
		#endif

		yylex_init_extra(&extraData, &scanner);
		in = yy_scan_string(srcCode, scanner);
		yylex(scanner);
		return NULL;
	}
