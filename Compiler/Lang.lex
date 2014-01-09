%{
	#include <stdio.h>

	struct lexerData{
		void *_pParser;
		struct program * _program;
	};
%}

%option noyywrap
%option reentrant
%option extra-type="struct lexerData *"

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
"*" { printf("Found Multiplication => *\n"); }
"/" { printf("Found Division => /\n"); }
"%" { printf("Found Mod => %%\n"); }
"^" { printf("Found Exp => ^\n"); }
"=" { printf("Found Equal => =\n"); }

	/* Comparison Operator Section */
"==" { printf("Found Equality => ==\n"); }
"!=" { printf("Found Not Equality => !=\n"); }
">" { printf("Found Greater Than => >\n"); }
"<" { printf("Found Less Than => <\n"); }
">=" { printf("Found Greater Than or Equal => >=\n"); }
"<=" { printf("Found Less Than or Equal => <=\n"); }
	
	/* Logical Operator Section */
"!" { printf("Found Logical Not => !\n"); }
"&&" { printf("Found Logical AND => &&\n"); }
"||" { printf("Found Logical OR => ||\n"); }
"@@" { printf("Found Logical XOR => @@\n"); }

	/* Bitwise Operator Section */
"~" { printf("Found Bitwise Not => ~\n"); }
"&" { printf("Found Bitwise AND => &\n"); }
"|" { printf("Found Bitwise OR => |\n"); }
"@" { printf("Found Bitwise XOR => @\n"); }
"<<" { printf("Found Bitwise Left Shift => <<\n"); }
">>" { printf("Found Bitwise Right Shift => >>\n"); }


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

#else
	struct program* parseString(char *srcCode){
		yyscan_t scanner;
		YY_BUFFER_STATE in;
		struct lexerData extraData;

		yylex_init_extra(&extraData, &scanner);
		in = yy_scan_string(srcCode, scanner);
		yylex(scanner);

	}
#endif
