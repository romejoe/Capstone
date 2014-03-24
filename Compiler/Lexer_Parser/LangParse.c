/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#include <stdio.h>
#line 1 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"

	#include <stdlib.h>
	#include <assert.h>
	#include "token.h"
	#include "program.h"


	struct Program *tmpHack = NULL;

	struct Program *getProgram(void *yyparser){
  		return tmpHack;
	}

#line 22 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
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
#define YYNOCODE 41
#define YYACTIONTYPE unsigned char
#define ParseTOKENTYPE Token *
typedef union {
  int yyinit;
  ParseTOKENTYPE yy0;
  struct Context * yy9;
  struct GenericStatement * yy10;
  struct Expression * yy44;
  struct Symbol * yy70;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define ParseARG_SDECL
#define ParseARG_PDECL
#define ParseARG_FETCH
#define ParseARG_STORE
#define YYNSTATE 67
#define YYNRULE 36
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
#define YY_ACTTAB_COUNT (220)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    67,   14,   38,   16,   66,   36,   38,   16,   18,    6,
 /*    10 */    35,   43,   42,    6,   34,   43,   42,    2,    1,   23,
 /*    20 */    22,   53,   13,   23,   22,   57,   56,   55,   44,   57,
 /*    30 */    56,   55,   38,   16,   40,   59,   64,   58,  105,    6,
 /*    40 */   105,   43,   42,   17,   15,   21,   20,   19,   18,   23,
 /*    50 */    22,  105,   31,   60,   54,   57,   56,   55,  105,  105,
 /*    60 */     5,   26,   41,   46,   25,   33,   27,   24,   60,   54,
 /*    70 */   104,    4,   26,   41,   46,   25,   33,   27,   24,   60,
 /*    80 */    54,   38,   16,   30,   60,   54,  105,  105,    6,   61,
 /*    90 */    43,   42,   24,   60,   54,  105,   37,   25,   23,   22,
 /*   100 */    24,   60,   54,  105,   57,   56,   55,    3,   26,   41,
 /*   110 */    46,   25,   33,   27,   24,   60,   54,  105,  105,   39,
 /*   120 */    65,   46,   25,   33,   27,   24,   60,   54,   12,   11,
 /*   130 */    10,    9,    8,    7,   16,   63,   25,  105,  105,   24,
 /*   140 */    60,   54,   62,   25,  105,  105,   24,   60,   54,   32,
 /*   150 */    23,   22,   24,   60,   54,  105,   57,   56,   55,   51,
 /*   160 */    25,  105,  105,   24,   60,   54,   50,   25,  105,  105,
 /*   170 */    24,   60,   54,   49,   25,  105,  105,   24,   60,   54,
 /*   180 */    48,   25,   16,  105,   24,   60,   54,  105,  105,   47,
 /*   190 */    25,  105,  105,   24,   60,   54,   45,   25,  105,  105,
 /*   200 */    24,   60,   54,  105,   57,   56,   55,   52,  105,  105,
 /*   210 */    24,   60,   54,  105,   29,   60,   54,   28,   60,   54,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     0,    3,    2,    3,    1,    4,    2,    3,   24,    9,
 /*    10 */     6,   11,   12,    9,    7,   11,   12,    5,    5,   19,
 /*    20 */    20,    4,    8,   19,   20,   25,   26,   27,   10,   25,
 /*    30 */    26,   27,    2,    3,    1,   38,    6,   38,   40,    9,
 /*    40 */    40,   11,   12,   19,   20,   21,   22,   23,   24,   19,
 /*    50 */    20,   40,   36,   37,   38,   25,   26,   27,   40,   40,
 /*    60 */    29,   30,   31,   32,   33,   34,   35,   36,   37,   38,
 /*    70 */    39,   29,   30,   31,   32,   33,   34,   35,   36,   37,
 /*    80 */    38,    2,    3,   36,   37,   38,   40,   40,    9,   33,
 /*    90 */    11,   12,   36,   37,   38,   40,   32,   33,   19,   20,
 /*   100 */    36,   37,   38,   40,   25,   26,   27,   29,   30,   31,
 /*   110 */    32,   33,   34,   35,   36,   37,   38,   40,   40,   30,
 /*   120 */    31,   32,   33,   34,   35,   36,   37,   38,   13,   14,
 /*   130 */    15,   16,   17,   18,    3,   32,   33,   40,   40,   36,
 /*   140 */    37,   38,   32,   33,   40,   40,   36,   37,   38,   33,
 /*   150 */    19,   20,   36,   37,   38,   40,   25,   26,   27,   32,
 /*   160 */    33,   40,   40,   36,   37,   38,   32,   33,   40,   40,
 /*   170 */    36,   37,   38,   32,   33,   40,   40,   36,   37,   38,
 /*   180 */    32,   33,    3,   40,   36,   37,   38,   40,   40,   32,
 /*   190 */    33,   40,   40,   36,   37,   38,   32,   33,   40,   40,
 /*   200 */    36,   37,   38,   40,   25,   26,   27,   33,   40,   40,
 /*   210 */    36,   37,   38,   40,   36,   37,   38,   36,   37,   38,
};
#define YY_SHIFT_USE_DFLT (-17)
#define YY_SHIFT_COUNT (39)
#define YY_SHIFT_MIN   (-16)
#define YY_SHIFT_MAX   (179)
static const short yy_shift_ofst[] = {
 /*     0 */    79,   79,   79,   30,    4,    0,  131,  131,  131,  131,
 /*    10 */   131,  131,  131,  131,  131,  131,  131,  131,  131,  131,
 /*    20 */   131,  131,  179,  179,   24,  115,   33,   18,  -16,  -16,
 /*    30 */   -16,  -16,   17,   14,   13,    7,   12,    1,   -2,    3,
};
#define YY_REDUCE_USE_DFLT (-4)
#define YY_REDUCE_COUNT (23)
#define YY_REDUCE_MIN   (-3)
#define YY_REDUCE_MAX   (181)
static const short yy_reduce_ofst[] = {
 /*     0 */    31,   78,   42,   89,   89,   89,  164,  157,  148,  141,
 /*    10 */   134,  127,  110,  103,   64,  174,  116,   56,  181,  178,
 /*    20 */    47,   16,   -1,   -3,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   103,  103,  103,  103,  103,  103,  103,  103,  103,  103,
 /*    10 */   103,  103,  103,  103,  103,  103,  103,  103,  103,  103,
 /*    20 */   103,  103,  103,  103,   90,   87,  103,  103,   94,   93,
 /*    30 */    92,   91,  103,   75,  103,   72,  103,  103,  103,  103,
 /*    40 */    71,   70,   80,   79,   78,   77,   76,   86,   85,   84,
 /*    50 */    83,   82,   89,   99,   98,  102,  101,  100,   97,   96,
 /*    60 */    95,   88,   81,   74,   73,   69,   68,
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
  "$",             "SEMICOLON",     "KEYWORD_IF",    "LPAREN",      
  "RPAREN",        "LCURLY",        "RCURLY",        "KEYWORD_ELSE",
  "EQUAL",         "KEYWORD_PRINT",  "IDENTIFIER",    "KEYWORD_INTEGER",
  "KEYWORD_FLOAT",  "LOGICAL_EQ",    "LOGICAL_NE",    "LOGICAL_GT",  
  "LOGICAL_LT",    "LOGICAL_GTE",   "LOGICAL_LTE",   "PLUS",        
  "MINUS",         "MUL",           "DIV",           "MOD",         
  "EXP",           "SYMBOL",        "INTEGER",       "FLOAT",       
  "error",         "statementgroup",  "statement",     "flowstatement",
  "fexpression",   "expression",    "definition",    "datatype",    
  "term",          "signedFactor",  "factor",        "program",     
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "program ::= statementgroup",
 /*   1 */ "statementgroup ::= statementgroup statement SEMICOLON",
 /*   2 */ "statementgroup ::= statementgroup flowstatement",
 /*   3 */ "statementgroup ::= flowstatement",
 /*   4 */ "statementgroup ::= statement SEMICOLON",
 /*   5 */ "flowstatement ::= KEYWORD_IF LPAREN fexpression RPAREN LCURLY statementgroup RCURLY",
 /*   6 */ "flowstatement ::= KEYWORD_IF LPAREN fexpression RPAREN LCURLY statementgroup RCURLY KEYWORD_ELSE LCURLY statementgroup RCURLY",
 /*   7 */ "statement ::= definition EQUAL fexpression",
 /*   8 */ "statement ::= definition",
 /*   9 */ "statement ::= fexpression",
 /*  10 */ "statement ::= KEYWORD_PRINT fexpression",
 /*  11 */ "definition ::= datatype IDENTIFIER",
 /*  12 */ "datatype ::= KEYWORD_INTEGER",
 /*  13 */ "datatype ::= KEYWORD_FLOAT",
 /*  14 */ "fexpression ::= expression LOGICAL_EQ fexpression",
 /*  15 */ "fexpression ::= expression LOGICAL_NE fexpression",
 /*  16 */ "fexpression ::= expression LOGICAL_GT fexpression",
 /*  17 */ "fexpression ::= expression LOGICAL_LT fexpression",
 /*  18 */ "fexpression ::= expression LOGICAL_GTE fexpression",
 /*  19 */ "fexpression ::= expression LOGICAL_LTE fexpression",
 /*  20 */ "fexpression ::= expression",
 /*  21 */ "expression ::= term PLUS expression",
 /*  22 */ "expression ::= term MINUS expression",
 /*  23 */ "expression ::= term",
 /*  24 */ "term ::= term MUL term",
 /*  25 */ "term ::= term DIV term",
 /*  26 */ "term ::= term MOD term",
 /*  27 */ "term ::= term EXP term",
 /*  28 */ "term ::= signedFactor",
 /*  29 */ "signedFactor ::= PLUS factor",
 /*  30 */ "signedFactor ::= MINUS factor",
 /*  31 */ "signedFactor ::= factor",
 /*  32 */ "factor ::= LPAREN expression RPAREN",
 /*  33 */ "factor ::= SYMBOL",
 /*  34 */ "factor ::= INTEGER",
 /*  35 */ "factor ::= FLOAT",
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
#line 37 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"

	printf("\tstack overflowed\n");
#line 642 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
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
  { 39, 1 },
  { 29, 3 },
  { 29, 2 },
  { 29, 1 },
  { 29, 2 },
  { 31, 7 },
  { 31, 11 },
  { 30, 3 },
  { 30, 1 },
  { 30, 1 },
  { 30, 2 },
  { 34, 2 },
  { 35, 1 },
  { 35, 1 },
  { 32, 3 },
  { 32, 3 },
  { 32, 3 },
  { 32, 3 },
  { 32, 3 },
  { 32, 3 },
  { 32, 1 },
  { 33, 3 },
  { 33, 3 },
  { 33, 1 },
  { 36, 3 },
  { 36, 3 },
  { 36, 3 },
  { 36, 3 },
  { 36, 1 },
  { 37, 2 },
  { 37, 2 },
  { 37, 1 },
  { 38, 3 },
  { 38, 1 },
  { 38, 1 },
  { 38, 1 },
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
#line 43 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	tmpHack = malloc(sizeof(struct Program));
	tmpHack->context = yymsp[0].minor.yy9;
}
#line 795 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 1: /* statementgroup ::= statementgroup statement SEMICOLON */
#line 48 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	/*yymsp[-2].minor.yy9 will be a Context*/
	/*yymsp[-1].minor.yy10 will be a GenericStatement*/
	struct GenericStatement *gStmnt;

	/*add statement to the end of the statement group*/
	List_Add_Value(yymsp[-2].minor.yy9->statements, yymsp[-1].minor.yy10,struct GenericStatement *);
	if(yymsp[-1].minor.yy10->hasDef){
		List_Add_Value(yymsp[-2].minor.yy9->symbols, yymsp[-1].minor.yy10->sym, struct Symbol *);
	}
	yygotominor.yy9 = yymsp[-2].minor.yy9;
}
#line 811 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 2: /* statementgroup ::= statementgroup flowstatement */
#line 61 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	/*yymsp[-1].minor.yy9 will be a Context*/
	/*yymsp[0].minor.yy10 will be a GenericStatement*/
	struct GenericStatement *gStmnt;

	/*add statement to the end of the statement group*/
	List_Add_Value(yymsp[-1].minor.yy9->statements, yymsp[0].minor.yy10,struct GenericStatement *);
	if(yymsp[0].minor.yy10->hasDef){
		List_Add_Value(yymsp[-1].minor.yy9->symbols, yymsp[0].minor.yy10->sym, struct Symbol *);
	}
	yygotominor.yy9 = yymsp[-1].minor.yy9;
}
#line 827 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 3: /* statementgroup ::= flowstatement */
#line 74 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy9 = new_context(yymsp[0].minor.yy10);
}
#line 834 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 4: /* statementgroup ::= statement SEMICOLON */
#line 78 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy9 = new_context(yymsp[-1].minor.yy10);
}
#line 841 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 5: /* flowstatement ::= KEYWORD_IF LPAREN fexpression RPAREN LCURLY statementgroup RCURLY */
#line 83 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = IFSTATEMENT;
	stmt->ifstmt = malloc(sizeof(struct IfStatement));
	stmt->ifstmt->testStatement = yymsp[-4].minor.yy44;
	stmt->ifstmt->yes = yymsp[-1].minor.yy9;
	stmt->ifstmt->no = NULL;
	yygotominor.yy10 = stmt;
}
#line 855 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 6: /* flowstatement ::= KEYWORD_IF LPAREN fexpression RPAREN LCURLY statementgroup RCURLY KEYWORD_ELSE LCURLY statementgroup RCURLY */
#line 94 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = IFSTATEMENT;
	stmt->ifstmt = malloc(sizeof(struct IfStatement));
	stmt->ifstmt->testStatement = yymsp[-8].minor.yy44;
	stmt->ifstmt->yes = yymsp[-5].minor.yy9;
	stmt->ifstmt->no = yymsp[-1].minor.yy9;
	yygotominor.yy10 = stmt;
}
#line 869 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 7: /* statement ::= definition EQUAL fexpression */
#line 105 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *dst;
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 1;
	stmt->sym = yymsp[-2].minor.yy70;

	dst = new_expression(SOURCE);
	dst->dataSource.sym = yymsp[-2].minor.yy70;
	dst->source_type = SYMBOL;
	
	stmt->exp = new_expression_children(ASSIGNMENT, dst, yymsp[0].minor.yy44);
	
	yygotominor.yy10 = stmt;
}
#line 889 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 8: /* statement ::= definition */
#line 122 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 1;
	stmt->sym = yymsp[0].minor.yy70;
	stmt->exp = NULL;

	yygotominor.yy10 = stmt;
}
#line 903 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 9: /* statement ::= fexpression */
#line 133 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 0;
	stmt->sym = NULL;

	stmt->exp = yymsp[0].minor.yy44;
	
	yygotominor.yy10 = stmt;
}
#line 918 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 10: /* statement ::= KEYWORD_PRINT fexpression */
#line 146 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	struct Expression *print = new_expression(PRINT);
	print->left = NULL;
	print->right = yymsp[0].minor.yy44;

	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 0;
	stmt->sym = NULL;

	stmt->exp = print;
	
	yygotominor.yy10 = stmt;
}
#line 937 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 11: /* definition ::= datatype IDENTIFIER */
#line 162 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yymsp[-1].minor.yy70->name = yymsp[0].minor.yy0->literal;
	yygotominor.yy70 = yymsp[-1].minor.yy70;
}
#line 945 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 12: /* datatype ::= KEYWORD_INTEGER */
#line 167 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy70 = new_symbol(NULL, tINTEGER);
}
#line 952 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 13: /* datatype ::= KEYWORD_FLOAT */
#line 171 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy70 = new_symbol(NULL, tFLOAT);
}
#line 959 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 14: /* fexpression ::= expression LOGICAL_EQ fexpression */
#line 176 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy44 = new_expression_children(CHECK_EQ, yymsp[-2].minor.yy44, yymsp[0].minor.yy44);
}
#line 966 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 15: /* fexpression ::= expression LOGICAL_NE fexpression */
#line 180 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy44 = new_expression_children(CHECK_NE, yymsp[-2].minor.yy44, yymsp[0].minor.yy44);
}
#line 973 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 16: /* fexpression ::= expression LOGICAL_GT fexpression */
#line 184 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy44 = new_expression_children(CHECK_GT, yymsp[-2].minor.yy44, yymsp[0].minor.yy44);
}
#line 980 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 17: /* fexpression ::= expression LOGICAL_LT fexpression */
#line 188 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy44 = new_expression_children(CHECK_LT, yymsp[-2].minor.yy44, yymsp[0].minor.yy44);
}
#line 987 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 18: /* fexpression ::= expression LOGICAL_GTE fexpression */
#line 192 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy44 = new_expression_children(CHECK_GTE, yymsp[-2].minor.yy44, yymsp[0].minor.yy44);
}
#line 994 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 19: /* fexpression ::= expression LOGICAL_LTE fexpression */
#line 196 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy44 = new_expression_children(CHECK_LTE, yymsp[-2].minor.yy44, yymsp[0].minor.yy44);
}
#line 1001 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 20: /* fexpression ::= expression */
      case 23: /* expression ::= term */ yytestcase(yyruleno==23);
      case 28: /* term ::= signedFactor */ yytestcase(yyruleno==28);
      case 31: /* signedFactor ::= factor */ yytestcase(yyruleno==31);
#line 200 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy44 = yymsp[0].minor.yy44;
}
#line 1011 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 21: /* expression ::= term PLUS expression */
#line 204 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy44 = new_expression_children(ADD, yymsp[-2].minor.yy44, yymsp[0].minor.yy44);
}
#line 1018 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 22: /* expression ::= term MINUS expression */
#line 208 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy44 = new_expression_children(SUBTRACT, yymsp[-2].minor.yy44, yymsp[0].minor.yy44);
}
#line 1025 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 24: /* term ::= term MUL term */
#line 219 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy44 = new_expression_children(MULTIPLY, yymsp[-2].minor.yy44, yymsp[0].minor.yy44);
}
#line 1032 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 25: /* term ::= term DIV term */
#line 223 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy44 = new_expression_children(DIVIDE, yymsp[-2].minor.yy44, yymsp[0].minor.yy44);
}
#line 1039 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 26: /* term ::= term MOD term */
#line 227 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy44 = new_expression_children(MODULUS, yymsp[-2].minor.yy44, yymsp[0].minor.yy44);
}
#line 1046 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 27: /* term ::= term EXP term */
#line 231 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy44 = new_expression_children(POWER, yymsp[-2].minor.yy44, yymsp[0].minor.yy44);
}
#line 1053 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 29: /* signedFactor ::= PLUS factor */
#line 240 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	/*possibly make this imply absolute value*/
	yygotominor.yy44 = yymsp[0].minor.yy44;
}
#line 1061 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 30: /* signedFactor ::= MINUS factor */
#line 244 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp = new_expression(MULTIPLY);
	struct Expression *LHS = new_expression(SOURCE);
	
	LHS->source_type = INTEGER;
	LHS->dataSource.Integer = -1;
	
	tmp->left = LHS;
	tmp->right = yymsp[0].minor.yy44;
	
	yygotominor.yy44 = tmp;
}
#line 1077 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 32: /* factor ::= LPAREN expression RPAREN */
#line 261 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy44 = yymsp[-1].minor.yy44;
}
#line 1084 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 34: /* factor ::= INTEGER */
#line 266 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = INTEGER;
	tmp->dataSource.Integer = yymsp[0].minor.yy0->intData;
	yygotominor.yy44 = tmp;
}
#line 1095 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 35: /* factor ::= FLOAT */
#line 274 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = FLOAT;
	tmp->dataSource.Float = yymsp[0].minor.yy0->floatData;
	yygotominor.yy44 = tmp;
}
#line 1106 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      default:
      /* (33) factor ::= SYMBOL */ yytestcase(yyruleno==33);
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
#line 34 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"

	printf("\tparse failed\n");
#line 1158 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
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
#line 41 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
 printf("\t\x1b[1m\x1b[91mSYNTAX ERROR!!!!\x1b[0m\n");  exit(-1);
#line 1175 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
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
#line 31 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"

	printf("\tparse accepted\n");
#line 1197 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
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
