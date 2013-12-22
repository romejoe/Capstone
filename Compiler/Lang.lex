%option noyywrap

%{
	#include <stdio.h>
%}

DIGIT		[0-9]
WHITESPACE 	[ \t\n\r]

%%

	/* Integer */
{DIGIT}+ { printf("Found Integer => {%s}\n", yytext); }

	/* Float */
{DIGIT}*"."{DIGIT}* { printf("Found Float => {%s}\n", yytext); }

	/* Identifier */
[a-zA-Z_]([a-zA-Z_]|{DIGIT})* { printf("Found Identifier => {%s}\n", yytext); }

	/* Parenthesis Section */
"(" { printf("Found Left Paren => (\n"); }
")" { printf("Found Right Paren => )\n"); }

	/* Curly Brace Section */
"{" { printf("Found Left Curly => {\n"); }
"}" { printf("Found Right Curly => }\n"); }

	/* Square Brace Section */
"[" { printf("Found Left Bracket => [\n"); }
"]" { printf("Found Right Bracket => ]\n"); }

	/* Operator Section */
"+" { printf("Found Plus => +\n"); }
"-" { printf("Found Minus => -\n"); }
"*" { printf("Found Times => *\n"); }
"/" { printf("Found Multiplication => /\n"); }
"%" { printf("Found Mod => %\n"); }
"^" { printf("Found Exp => ^\n"); }
"=" { printf("Found Equal => =\n"); }

	/* String Section */
\"[^\"]*\" { printf("Found String => {%s}\n", yytext); }

	/* Semicolon Section */
";" { printf("Found Semicolon => ;\n"); }

	/* Comment Section */
"//"[^\n]* { printf("Found Single Line Comment => %s\n", yytext); }
"/*".*"*/" { printf("Found Block Comment => %s\n", yytext); }

{WHITESPACE}+ /* ignore whitespace */

. { printf("Found unknown char => {%s}\n", yytext); }

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
