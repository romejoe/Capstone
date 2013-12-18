%option noyywrap

%{
	#include <stdion.h>
%}

DIGIT		[0-9]
WHITESPACE 	[ \t\n\r]

%%

DIGIT+ {
	printf("Found Number => {%s}\n", yytext);
}

WHITESPACE+ /* ignore whitespace */

. {
	printf("Found unknown char => {%s}\n", yytext);
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
