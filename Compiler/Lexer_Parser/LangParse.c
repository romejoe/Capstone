/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#include <stdio.h>
#line 1 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"

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

#line 57 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/* 
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands. 
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    ParseTOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is ParseTOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    ParseARG_SDECL     A static variable declaration for the %extra_argument
**    ParseARG_PDECL     A parameter declaration for the %extra_argument
**    ParseARG_STORE     Code to store %extra_argument into yypParser
**    ParseARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 32
#define YYACTIONTYPE unsigned char
#define ParseTOKENTYPE Token *
typedef union {
  int yyinit;
  ParseTOKENTYPE yy0;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define ParseARG_SDECL
#define ParseARG_PDECL
#define ParseARG_FETCH
#define ParseARG_STORE
#define YYNSTATE 48
#define YYNRULE 26
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)

/* The yyzerominor constant is used to initialize instances of
** YYMINORTYPE objects to zero. */
static const YYMINORTYPE yyzerominor = { 0 };

/* Define the yytestcase() macro to be a no-op if is not already defined
** otherwise.
**
** Applications can choose to define yytestcase() in the %include section
** to a macro that can assist in verifying code coverage.  For production
** code the yytestcase() macro should be turned off.  But it is useful
** for testing.
*/
#ifndef yytestcase
# define yytestcase(X)
#endif


/* Next are the tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < YYNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   YYNSTATE <= N < YYNSTATE+YYNRULE   Reduce by rule N-YYNSTATE.
**
**   N == YYNSTATE+YYNRULE              A syntax error has occurred.
**
**   N == YYNSTATE+YYNRULE+1            The parser accepts its input.
**
**   N == YYNSTATE+YYNRULE+2            No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
#define YY_ACTTAB_COUNT (133)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    48,   26,   27,    6,   16,   43,   37,   47,    4,   25,
 /*    10 */    31,   30,   15,   14,   22,   43,   37,    9,   40,   39,
 /*    20 */    38,   27,    6,    1,    8,   46,   36,    4,   10,   31,
 /*    30 */    30,   15,   14,   32,   27,    6,   29,   40,   39,   38,
 /*    40 */     4,   76,   31,   30,   15,   14,   42,   76,   76,   76,
 /*    50 */    40,   39,   38,   75,    3,   17,   34,   24,   18,   16,
 /*    60 */    43,   37,    2,   17,   34,   24,   18,   16,   43,   37,
 /*    70 */    28,   34,   24,   18,   16,   43,   37,    7,    5,   13,
 /*    80 */    12,   11,   10,    6,   45,   41,    6,   16,   43,   37,
 /*    90 */    76,   44,   15,   14,   16,   43,   37,   76,   40,   39,
 /*   100 */    38,   40,   39,   38,   23,   76,   76,   16,   43,   37,
 /*   110 */    35,   76,   76,   16,   43,   37,   76,   33,   76,   76,
 /*   120 */    16,   43,   37,   21,   43,   37,   76,   20,   43,   37,
 /*   130 */    19,   43,   37,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     0,   25,    2,    3,   28,   29,   30,    1,    8,    4,
 /*    10 */    10,   11,   12,   13,   28,   29,   30,    3,   18,   19,
 /*    20 */    20,    2,    3,    5,    7,    6,    4,    8,   17,   10,
 /*    30 */    11,   12,   13,    9,    2,    3,    1,   18,   19,   20,
 /*    40 */     8,   31,   10,   11,   12,   13,   30,   31,   31,   31,
 /*    50 */    18,   19,   20,   22,   23,   24,   25,   26,   27,   28,
 /*    60 */    29,   30,   23,   24,   25,   26,   27,   28,   29,   30,
 /*    70 */    24,   25,   26,   27,   28,   29,   30,   12,   13,   14,
 /*    80 */    15,   16,   17,    3,   25,   30,    3,   28,   29,   30,
 /*    90 */    31,   25,   12,   13,   28,   29,   30,   31,   18,   19,
 /*   100 */    20,   18,   19,   20,   25,   31,   31,   28,   29,   30,
 /*   110 */    25,   31,   31,   28,   29,   30,   31,   25,   31,   31,
 /*   120 */    28,   29,   30,   28,   29,   30,   31,   28,   29,   30,
 /*   130 */    28,   29,   30,
};
#define YY_SHIFT_USE_DFLT (-1)
#define YY_SHIFT_COUNT (28)
#define YY_SHIFT_MIN   (0)
#define YY_SHIFT_MAX   (83)
static const signed char yy_shift_ofst[] = {
 /*     0 */    32,   32,   19,    0,   80,   80,   80,   80,   80,   80,
 /*    10 */    80,   80,   80,   80,   83,   83,   65,   35,   24,   11,
 /*    20 */    11,   11,   11,   22,   17,   18,    5,   14,    6,
};
#define YY_REDUCE_USE_DFLT (-25)
#define YY_REDUCE_COUNT (15)
#define YY_REDUCE_MIN   (-24)
#define YY_REDUCE_MAX   (102)
static const signed char yy_reduce_ofst[] = {
 /*     0 */    31,   39,   46,   46,   92,   85,   79,   66,   59,  -24,
 /*    10 */   102,   99,   95,  -14,   55,   16,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */    74,   74,   74,   74,   74,   74,   74,   74,   74,   74,
 /*    10 */    74,   74,   74,   74,   74,   74,   61,   74,   74,   65,
 /*    20 */    64,   63,   62,   74,   53,   74,   74,   74,   74,   50,
 /*    30 */    58,   57,   56,   55,   54,   60,   70,   69,   73,   72,
 /*    40 */    71,   68,   67,   66,   59,   52,   51,   49,
};

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammar, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct yyStackEntry {
  YYACTIONTYPE stateno;  /* The state-number */
  YYCODETYPE major;      /* The major token value.  This is the code
                         ** number for the token at this stack level */
  YYMINORTYPE minor;     /* The user-supplied minor token value.  This
                         ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
#ifdef YYTRACKMAXSTACKDEPTH
  int yyidxMax;                 /* Maximum value of yyidx */
#endif
  int yyerrcnt;                 /* Shifts left before out of the error */
  ParseARG_SDECL                /* A place to hold %extra_argument */
#if YYSTACKDEPTH<=0
  int yystksz;                  /* Current side of the stack */
  yyStackEntry *yystack;        /* The parser's stack */
#else
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
#endif
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void ParseTrace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const yyTokenName[] = { 
  "$",             "SEMICOLON",     "IF",            "LPAREN",      
  "RPAREN",        "LCURLY",        "RCURLY",        "EQUAL",       
  "KEYWORD_PRINT",  "IDENTIFIER",    "KEYWORD_INTEGER",  "KEYWORD_FLOAT",
  "PLUS",          "MINUS",         "MUL",           "DIV",         
  "MOD",           "EXP",           "SYMBOL",        "INTEGER",     
  "FLOAT",         "error",         "program",       "statementgroup",
  "statement",     "expression",    "definition",    "datatype",    
  "term",          "signedFactor",  "factor",      
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "program ::= statementgroup",
 /*   1 */ "statementgroup ::= statementgroup statement SEMICOLON",
 /*   2 */ "statementgroup ::= statement SEMICOLON",
 /*   3 */ "statement ::= IF LPAREN expression RPAREN LCURLY statementgroup RCURLY",
 /*   4 */ "statement ::= definition EQUAL expression",
 /*   5 */ "statement ::= definition",
 /*   6 */ "statement ::= expression",
 /*   7 */ "statement ::= KEYWORD_PRINT expression",
 /*   8 */ "definition ::= datatype IDENTIFIER",
 /*   9 */ "datatype ::= KEYWORD_INTEGER",
 /*  10 */ "datatype ::= KEYWORD_FLOAT",
 /*  11 */ "expression ::= term PLUS expression",
 /*  12 */ "expression ::= term MINUS expression",
 /*  13 */ "expression ::= term",
 /*  14 */ "term ::= term MUL term",
 /*  15 */ "term ::= term DIV term",
 /*  16 */ "term ::= term MOD term",
 /*  17 */ "term ::= term EXP term",
 /*  18 */ "term ::= signedFactor",
 /*  19 */ "signedFactor ::= PLUS factor",
 /*  20 */ "signedFactor ::= MINUS factor",
 /*  21 */ "signedFactor ::= factor",
 /*  22 */ "factor ::= LPAREN expression RPAREN",
 /*  23 */ "factor ::= SYMBOL",
 /*  24 */ "factor ::= INTEGER",
 /*  25 */ "factor ::= FLOAT",
};
#endif /* NDEBUG */


#if YYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.
*/
static void yyGrowStack(yyParser *p){
  int newSize;
  yyStackEntry *pNew;

  newSize = p->yystksz*2 + 100;
  pNew = realloc(p->yystack, newSize*sizeof(pNew[0]));
  if( pNew ){
    p->yystack = pNew;
    p->yystksz = newSize;
#ifndef NDEBUG
    if( yyTraceFILE ){
      fprintf(yyTraceFILE,"%sStack grows to %d entries!\n",
              yyTracePrompt, p->yystksz);
    }
#endif
  }
}
#endif

/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to Parse and ParseFree.
*/
void *ParseAlloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
#ifdef YYTRACKMAXSTACKDEPTH
    pParser->yyidxMax = 0;
#endif
#if YYSTACKDEPTH<=0
    pParser->yystack = NULL;
    pParser->yystksz = 0;
    yyGrowStack(pParser);
#endif
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(
  yyParser *yypParser,    /* The parser */
  YYCODETYPE yymajor,     /* Type code for object to destroy */
  YYMINORTYPE *yypminor   /* The object to be destroyed */
){
  ParseARG_FETCH;
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;
  yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor(pParser, yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from ParseAlloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void ParseFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
#if YYSTACKDEPTH<=0
  free(pParser->yystack);
#endif
  (*freeProc)((void*)pParser);
}

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef YYTRACKMAXSTACKDEPTH
int ParseStackPeak(void *p){
  yyParser *pParser = (yyParser*)p;
  return pParser->yyidxMax;
}
#endif

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;
 
  if( stateno>YY_SHIFT_COUNT
   || (i = yy_shift_ofst[stateno])==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    if( iLookAhead>0 ){
#ifdef YYFALLBACK
      YYCODETYPE iFallback;            /* Fallback token */
      if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
             && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
             yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
        }
#endif
        return yy_find_shift_action(pParser, iFallback);
      }
#endif
#ifdef YYWILDCARD
      {
        int j = i - iLookAhead + YYWILDCARD;
        if( 
#if YY_SHIFT_MIN+YYWILDCARD<0
          j>=0 &&
#endif
#if YY_SHIFT_MAX+YYWILDCARD>=YY_ACTTAB_COUNT
          j<YY_ACTTAB_COUNT &&
#endif
          yy_lookahead[j]==YYWILDCARD
        ){
#ifndef NDEBUG
          if( yyTraceFILE ){
            fprintf(yyTraceFILE, "%sWILDCARD %s => %s\n",
               yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[YYWILDCARD]);
          }
#endif /* NDEBUG */
          return yy_action[j];
        }
      }
#endif /* YYWILDCARD */
    }
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_reduce_action(
  int stateno,              /* Current state number */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
#ifdef YYERRORSYMBOL
  if( stateno>YY_REDUCE_COUNT ){
    return yy_default[stateno];
  }
#else
  assert( stateno<=YY_REDUCE_COUNT );
#endif
  i = yy_reduce_ofst[stateno];
  assert( i!=YY_REDUCE_USE_DFLT );
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
#ifdef YYERRORSYMBOL
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }
#else
  assert( i>=0 && i<YY_ACTTAB_COUNT );
  assert( yy_lookahead[i]==iLookAhead );
#endif
  return yy_action[i];
}

/*
** The following routine is called if the stack overflows.
*/
static void yyStackOverflow(yyParser *yypParser, YYMINORTYPE *yypMinor){
   ParseARG_FETCH;
   yypParser->yyidx--;
#ifndef NDEBUG
   if( yyTraceFILE ){
     fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
   }
#endif
   while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */
#line 60 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"

	printf("\tstack overflowed\n");
#line 641 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
   ParseARG_STORE; /* Suppress warning about unused %extra_argument var */
}

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer to the minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yyidx++;
#ifdef YYTRACKMAXSTACKDEPTH
  if( yypParser->yyidx>yypParser->yyidxMax ){
    yypParser->yyidxMax = yypParser->yyidx;
  }
#endif
#if YYSTACKDEPTH>0 
  if( yypParser->yyidx>=YYSTACKDEPTH ){
    yyStackOverflow(yypParser, yypMinor);
    return;
  }
#else
  if( yypParser->yyidx>=yypParser->yystksz ){
    yyGrowStack(yypParser);
    if( yypParser->yyidx>=yypParser->yystksz ){
      yyStackOverflow(yypParser, yypMinor);
      return;
    }
  }
#endif
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = (YYACTIONTYPE)yyNewState;
  yytos->major = (YYCODETYPE)yyMajor;
  yytos->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static const struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 22, 1 },
  { 23, 3 },
  { 23, 2 },
  { 24, 7 },
  { 24, 3 },
  { 24, 1 },
  { 24, 1 },
  { 24, 2 },
  { 26, 2 },
  { 27, 1 },
  { 27, 1 },
  { 25, 3 },
  { 25, 3 },
  { 25, 1 },
  { 28, 3 },
  { 28, 3 },
  { 28, 3 },
  { 28, 3 },
  { 28, 1 },
  { 29, 2 },
  { 29, 2 },
  { 29, 1 },
  { 30, 3 },
  { 30, 1 },
  { 30, 1 },
  { 30, 1 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  ParseARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0 
        && yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

  /* Silence complaints from purify about yygotominor being uninitialized
  ** in some cases when it is copied into the stack after the following
  ** switch.  yygotominor is uninitialized when a rule reduces that does
  ** not set the value of its left-hand side nonterminal.  Leaving the
  ** value of the nonterminal uninitialized is utterly harmless as long
  ** as the value is never used.  So really the only thing this code
  ** accomplishes is to quieten purify.  
  **
  ** 2007-01-16:  The wireshark project (www.wireshark.org) reports that
  ** without this code, their parser segfaults.  I'm not sure what there
  ** parser is doing to make this happen.  This is the second bug report
  ** from wireshark this week.  Clearly they are stressing Lemon in ways
  ** that it has not been previously stressed...  (SQLite ticket #2172)
  */
  /*memset(&yygotominor, 0, sizeof(yygotominor));*/
  yygotominor = yyzerominor;


  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0: /* program ::= statementgroup */
#line 66 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	tmpHack = malloc(sizeof(struct Program));
	tmpHack->context = yymsp[0].minor.yy0->context;
}
#line 784 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 1: /* statementgroup ::= statementgroup statement SEMICOLON */
#line 71 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	struct Context *lContext, *rContext;
	struct List *lSymbols, *rSymbols;
	struct List *lExpressions, *rExpressions;
	struct Symbol *sym;
	lContext = yymsp[-1].minor.yy0->context;
	rContext = yymsp[-2].minor.yy0->context;
	
	/*add statement to the end of the statement group*/
	List_Add_Value(yymsp[-2].minor.yy0->context->expressions,
	 /*List_Ref_Value(yymsp[-1].minor.yy0->context->expressions, 0, struct Expression *),*/
	yymsp[-1].minor.yy0->context->exp,
	 struct Expression *);

	/*merge symbols*/
	lSymbols = lContext->exports.symbols;
	rSymbols = rContext->exports.symbols;
	

	if(lSymbols){
		List_ForEach(lSymbols, {
			sym = List_Ref_Value(lSymbols, i, struct Symbol *);
			/*printSymbol(sym);*/
			List_Add_Value(rSymbols, sym, struct Symbol *);
		});
	}
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = rContext;
}
#line 818 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 2: /* statementgroup ::= statement SEMICOLON */
#line 102 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Context *context;
	struct List *symbolList;

	symbolList = yymsp[-1].minor.yy0->context->exports.symbols;
	if(!symbolList){ 
		symbolList = (struct List *) malloc(sizeof(struct List));
		newList(symbolList, struct Symbol *);	
	}

	context = new_context(yymsp[-1].minor.yy0->context->exp, symbolList, 2);

	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = context;
}
#line 837 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 4: /* statement ::= definition EQUAL expression */
#line 119 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Context *context;
	struct Expression *dst, *exp;
	
	context = yymsp[-2].minor.yy0->context;

	dst = new_expression(SOURCE);
	dst->dataSource.sym = List_Ref_Value(context->exports.symbols, 0, struct Symbol *);
	dst->source_type = SYMBOL;
	exp = new_expression(ASSIGNMENT);
	exp->left = dst;
	exp->right = yymsp[0].minor.yy0->context->exp;

	context->exp = exp;
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = context;
}
#line 858 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 5: /* statement ::= definition */
      case 6: /* statement ::= expression */ yytestcase(yyruleno==6);
      case 13: /* expression ::= term */ yytestcase(yyruleno==13);
      case 18: /* term ::= signedFactor */ yytestcase(yyruleno==18);
      case 21: /* signedFactor ::= factor */ yytestcase(yyruleno==21);
#line 137 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = yymsp[0].minor.yy0->context;
}
#line 870 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 7: /* statement ::= KEYWORD_PRINT expression */
#line 148 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = yymsp[0].minor.yy0->context;
	struct Expression *print = new_expression(PRINT);
	print->left = NULL;
	print->right = yygotominor.yy0->context->exp;
	yygotominor.yy0->context->exp = print;
}
#line 882 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 8: /* definition ::= datatype IDENTIFIER */
#line 157 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Symbol **sym = List_Ref(yymsp[-1].minor.yy0->context->exports.symbols, 0);
	(*sym)->name = yymsp[0].minor.yy0->literal;

	printf("_List Ptr = %p\n", yymsp[-1].minor.yy0->context->exports.symbols);
	printf("[0] = %p\n", *sym);
	printf("Haz definition\n");
	printSymbol(*sym);
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = yymsp[-1].minor.yy0->context;
}
#line 897 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 9: /* datatype ::= KEYWORD_INTEGER */
#line 169 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Symbol *sym = new_symbol(NULL, tINTEGER);
	struct List *list = (struct List *) malloc(sizeof(struct List));
	struct Context *context;
	printf("IList Ptr = %p\n", list);
	printf("Isym Ptr = %p\n", sym);
	newList(list, struct Symbol *);
	List_Add_Value(list, sym, struct Symbol *);
	
	context = new_context(NULL, list, 2);
	
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = context;
}
#line 915 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 10: /* datatype ::= KEYWORD_FLOAT */
#line 184 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Symbol *sym = new_symbol(NULL, tFLOAT);
	struct List *list = (struct List *) malloc(sizeof(struct List));
	printf("FList Ptr = %p\n", list);
	printf("Fsym Ptr = %p\n", sym);
	struct Context *context;
	newList(list, struct Symbol *);
	List_Add_Value(list, sym, struct Symbol *);
	context = new_context(NULL, list, 2);
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = context;
}
#line 931 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 11: /* expression ::= term PLUS expression */
#line 197 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmExp = yymsp[-2].minor.yy0->context->exp;
	struct Expression *expExp = yymsp[0].minor.yy0->context->exp;
	struct Expression *tmp;
	tmp = new_expression(ADD);
	tmp->left = tmExp;
	tmp->right = expExp;

	yymsp[0].minor.yy0->context->exp = tmp;
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = yymsp[0].minor.yy0->context;
}
#line 947 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 12: /* expression ::= term MINUS expression */
#line 210 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmExp = yymsp[-2].minor.yy0->context->exp;
	struct Expression *expExp = yymsp[0].minor.yy0->context->exp;
	struct Expression *tmp;
	tmp = new_expression(SUBTRACT);
	tmp->left = tmExp;
	tmp->right = expExp;

	yymsp[0].minor.yy0->context->exp = tmp;
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = yymsp[0].minor.yy0->context;
}
#line 963 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 14: /* term ::= term MUL term */
#line 231 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tm1Exp = yymsp[-2].minor.yy0->context->exp;
	struct Expression *tm2Exp = yymsp[0].minor.yy0->context->exp;
	struct Expression *tmp;
	tmp = new_expression(MULTIPLY);
	tmp->left = tm1Exp;
	tmp->right = tm2Exp;

	yymsp[0].minor.yy0->context->exp = tmp;
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = yymsp[0].minor.yy0->context;
}
#line 979 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 15: /* term ::= term DIV term */
#line 244 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tm1Exp = yymsp[-2].minor.yy0->context->exp;
	struct Expression *tm2Exp = yymsp[0].minor.yy0->context->exp;
	struct Expression *tmp;
	tmp = new_expression(DIVIDE);
	tmp->left = tm1Exp;
	tmp->right = tm2Exp;

	yymsp[0].minor.yy0->context->exp = tmp;
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = yymsp[0].minor.yy0->context;
}
#line 995 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 16: /* term ::= term MOD term */
#line 257 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tm1Exp = yymsp[-2].minor.yy0->context->exp;
	struct Expression *tm2Exp = yymsp[0].minor.yy0->context->exp;
	struct Expression *tmp;
	tmp = new_expression(MODULUS);
	tmp->left = tm1Exp;
	tmp->right = tm2Exp;

	yymsp[0].minor.yy0->context->exp = tmp;
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = yymsp[0].minor.yy0->context;
}
#line 1011 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 17: /* term ::= term EXP term */
#line 270 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tm1Exp = yymsp[-2].minor.yy0->context->exp;
	struct Expression *tm2Exp = yymsp[0].minor.yy0->context->exp;
	struct Expression *tmp;
	tmp = new_expression(POWER);
	tmp->left = tm1Exp;
	tmp->right = tm2Exp;

	yymsp[0].minor.yy0->context->exp = tmp;
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = yymsp[0].minor.yy0->context;
}
#line 1027 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 19: /* signedFactor ::= PLUS factor */
#line 289 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	/*possibly make this imply absolute value*/
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = yymsp[0].minor.yy0->context;
}
#line 1036 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 20: /* signedFactor ::= MINUS factor */
#line 294 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp = new_expression(MULTIPLY);
	struct Expression *LHS = new_expression(SOURCE);
	
	LHS->source_type = INTEGER;
	LHS->dataSource.Integer = -1;
	
	tmp->left = LHS;
	tmp->right = yymsp[0].minor.yy0->context->exp;
	
	yymsp[0].minor.yy0->context->exp = tmp;
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = yymsp[0].minor.yy0->context;

}
#line 1055 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 22: /* factor ::= LPAREN expression RPAREN */
#line 315 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = yymsp[-1].minor.yy0->context;
}
#line 1063 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 24: /* factor ::= INTEGER */
#line 321 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = INTEGER;
	tmp->dataSource.Integer = yymsp[0].minor.yy0->intData;
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = new_context(tmp, NULL, 0);
}
#line 1075 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 25: /* factor ::= FLOAT */
#line 330 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = FLOAT;
	tmp->dataSource.Float = yymsp[0].minor.yy0->floatData;
	yygotominor.yy0 = (Token *) malloc(sizeof(Token));
	yygotominor.yy0->context = new_context(tmp, NULL, 0);
}
#line 1087 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      default:
      /* (3) statement ::= IF LPAREN expression RPAREN LCURLY statementgroup RCURLY */ yytestcase(yyruleno==3);
      /* (23) factor ::= SYMBOL */ yytestcase(yyruleno==23);
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yymsp[-yysize].stateno,(YYCODETYPE)yygoto);
  if( yyact < YYNSTATE ){
#ifdef NDEBUG
    /* If we are not debugging and the reduce action popped at least
    ** one element off the stack, then we can push the new element back
    ** onto the stack here, and skip the stack overflow test in yy_shift().
    ** That gives a significant speed improvement. */
    if( yysize ){
      yypParser->yyidx++;
      yymsp -= yysize-1;
      yymsp->stateno = (YYACTIONTYPE)yyact;
      yymsp->major = (YYCODETYPE)yygoto;
      yymsp->minor = yygotominor;
    }else
#endif
    {
      yy_shift(yypParser,yyact,yygoto,&yygotominor);
    }
  }else{
    assert( yyact == YYNSTATE + YYNRULE + 1 );
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
#ifndef YYNOERRORRECOVERY
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  ParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
#line 57 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"

	printf("\tparse failed\n");
#line 1140 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}
#endif /* YYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  ParseARG_FETCH;
#define TOKEN (yyminor.yy0)
#line 64 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"
 printf("\t\x1b[1m\x1b[91mSYNTAX ERROR!!!!\x1b[0m\n");  exit(-1);
#line 1157 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  ParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
#line 54 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.y"

	printf("\tparse accepted\n");
#line 1179 "/home/joe/Desktop/CS 498/Compiler/Lexer_Parser/LangParse.c"
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "ParseAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void Parse(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  ParseTOKENTYPE yyminor       /* The value for the token */
  ParseARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
#ifdef YYERRORSYMBOL
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
#endif
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
#if YYSTACKDEPTH<=0
    if( yypParser->yystksz <=0 ){
      /*memset(&yyminorunion, 0, sizeof(yyminorunion));*/
      yyminorunion = yyzerominor;
      yyStackOverflow(yypParser, &yyminorunion);
      return;
    }
#endif
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  ParseARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,(YYCODETYPE)yymajor);
    if( yyact<YYNSTATE ){
      assert( !yyendofinput );  /* Impossible to shift the $ token */
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      yymajor = YYNOCODE;
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE);
    }else{
      assert( yyact == YY_ERROR_ACTION );
#ifdef YYERRORSYMBOL
      int yymx;
#endif
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yypParser, (YYCODETYPE)yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_reduce_action(
                        yypParser->yystack[yypParser->yyidx].stateno,
                        YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#elif defined(YYNOERRORRECOVERY)
      /* If the YYNOERRORRECOVERY macro is defined, then do not attempt to
      ** do any kind of error recovery.  Instead, simply invoke the syntax
      ** error routine and continue going as if nothing had happened.
      **
      ** Applications can set this macro (for example inside %include) if
      ** they intend to abandon the parse upon the first syntax error seen.
      */
      yy_syntax_error(yypParser,yymajor,yyminorunion);
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      yymajor = YYNOCODE;
      
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}
