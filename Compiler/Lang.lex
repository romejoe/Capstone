%option noyywrap

%{
	#include <stdio.h>
%}

DIGIT		[0-9]
WHITESPACE 	[ \t\n\r]

%%

{DIGIT}+ { printf("Found Number => {%s}\n", yytext); }

[a-zA-Z_]([a-zA-Z_]|{DIGIT})* { printf("Found Identifier => {%s}\n", yytext); }

"(" { printf("Found Left Paren => (\n"); }

")" { printf("Found Right Paren => )\n"); }

"{" { printf("Found Left Curly => {\n"); }

"}" { printf("Found Right Curly => }\n"); }

"[" { printf("Found Left Bracket => [\n"); }

"]" { printf("Found Right Bracket => ]\n"); }

"+" { printf("Found Plus => +\n"); }
"-" { printf("Found Minus => -\n"); }
"*" { printf("Found Times => *\n"); }
"/" { printf("Found Multiplication => /\n"); }
"%" { printf("Found Mod => %\n"); }
"^" { printf("Found Exp => ^\n"); }
"=" { printf("Found Equal => =\n"); }

"\"" { printf("Found String => {%s}\n", yytext); }

{WHITESPACE}+ /* ignore whitespace */

. { printf("Found unknown char => {%s}\n", yytext);}

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
