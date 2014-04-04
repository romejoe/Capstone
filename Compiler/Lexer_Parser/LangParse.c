/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#include <stdio.h>
#line 1 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"

	#include <stdlib.h>
	#include <assert.h>
	#include "token.h"
	#include "program.h"


	struct Program *tmpHack = NULL;

	struct Program *getProgram(void *yyparser){
  		return tmpHack;
	}

#line 22 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
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
#define YYNOCODE 40
#define YYACTIONTYPE unsigned char
#define ParseTOKENTYPE Token *
typedef union {
  int yyinit;
  ParseTOKENTYPE yy0;
  struct GenericStatement * yy8;
  struct Symbol * yy12;
  struct Expression * yy32;
  struct Context * yy67;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define ParseARG_SDECL
#define ParseARG_PDECL
#define ParseARG_FETCH
#define ParseARG_STORE
#define YYNSTATE 70
#define YYNRULE 37
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
#define YY_ACTTAB_COUNT (222)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    70,   64,   40,   17,   25,   63,   57,   17,   69,   29,
 /*    10 */     6,   45,   44,   60,   40,   17,   15,   36,   37,   24,
 /*    20 */    23,   29,    6,   45,   44,   59,   58,   38,   14,   59,
 /*    30 */    58,   24,   23,    2,   56,   40,   17,   59,   58,   67,
 /*    40 */    19,    1,   29,    6,   45,   44,   18,   16,   22,   21,
 /*    50 */    20,   19,   24,   23,   33,   63,   57,    7,   59,   58,
 /*    60 */     5,   27,   43,   48,   26,   35,   28,   25,   63,   57,
 /*    70 */   108,    4,   27,   43,   48,   26,   35,   28,   25,   63,
 /*    80 */    57,   40,   17,   32,   63,   57,   46,   42,   29,    6,
 /*    90 */    45,   44,   31,   63,   57,   62,   39,   26,   24,   23,
 /*   100 */    25,   63,   57,   61,   59,   58,    3,   27,   43,   48,
 /*   110 */    26,   35,   28,   25,   63,   57,  109,  109,   41,   68,
 /*   120 */    48,   26,   35,   28,   25,   63,   57,   13,   12,   11,
 /*   130 */    10,    9,    8,   17,  109,  109,   66,   26,  109,   60,
 /*   140 */    25,   63,   57,   30,   63,   57,  109,   65,   26,   24,
 /*   150 */    23,   25,   63,   57,  109,   59,   58,   54,   26,  109,
 /*   160 */   109,   25,   63,   57,   53,   26,  109,  109,   25,   63,
 /*   170 */    57,   52,   26,  109,  109,   25,   63,   57,  109,   51,
 /*   180 */    26,  109,  109,   25,   63,   57,  109,   50,   26,  109,
 /*   190 */   109,   25,   63,   57,   49,   26,  109,  109,   25,   63,
 /*   200 */    57,   47,   26,  109,  109,   25,   63,   57,   34,  109,
 /*   210 */   109,   25,   63,   57,  109,  109,   55,  109,  109,   25,
 /*   220 */    63,   57,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     0,   32,    2,    3,   35,   36,   37,    3,    1,    9,
 /*    10 */    10,   11,   12,    9,    2,    3,    3,    7,    6,   19,
 /*    20 */    20,    9,   10,   11,   12,   25,   26,    4,    8,   25,
 /*    30 */    26,   19,   20,    5,    4,    2,    3,   25,   26,    6,
 /*    40 */    24,    5,    9,   10,   11,   12,   19,   20,   21,   22,
 /*    50 */    23,   24,   19,   20,   35,   36,   37,    8,   25,   26,
 /*    60 */    28,   29,   30,   31,   32,   33,   34,   35,   36,   37,
 /*    70 */    38,   28,   29,   30,   31,   32,   33,   34,   35,   36,
 /*    80 */    37,    2,    3,   35,   36,   37,    9,    1,    9,   10,
 /*    90 */    11,   12,   35,   36,   37,   37,   31,   32,   19,   20,
 /*   100 */    35,   36,   37,   37,   25,   26,   28,   29,   30,   31,
 /*   110 */    32,   33,   34,   35,   36,   37,   39,   39,   29,   30,
 /*   120 */    31,   32,   33,   34,   35,   36,   37,   13,   14,   15,
 /*   130 */    16,   17,   18,    3,   39,   39,   31,   32,   39,    9,
 /*   140 */    35,   36,   37,   35,   36,   37,   39,   31,   32,   19,
 /*   150 */    20,   35,   36,   37,   39,   25,   26,   31,   32,   39,
 /*   160 */    39,   35,   36,   37,   31,   32,   39,   39,   35,   36,
 /*   170 */    37,   31,   32,   39,   39,   35,   36,   37,   39,   31,
 /*   180 */    32,   39,   39,   35,   36,   37,   39,   31,   32,   39,
 /*   190 */    39,   35,   36,   37,   31,   32,   39,   39,   35,   36,
 /*   200 */    37,   31,   32,   39,   39,   35,   36,   37,   32,   39,
 /*   210 */    39,   35,   36,   37,   39,   39,   32,   39,   39,   35,
 /*   220 */    36,   37,
};
#define YY_SHIFT_USE_DFLT (-1)
#define YY_SHIFT_COUNT (41)
#define YY_SHIFT_MIN   (0)
#define YY_SHIFT_MAX   (130)
static const short yy_shift_ofst[] = {
 /*     0 */    79,   79,   79,   33,   12,    0,  130,  130,  130,  130,
 /*    10 */   130,  130,  130,  130,  130,  130,  130,  130,  130,  130,
 /*    20 */   130,  130,  130,    4,    4,   27,  114,   86,   77,   49,
 /*    30 */    16,   16,   16,   16,   30,   20,   36,   10,   28,   23,
 /*    40 */    13,    7,
};
#define YY_REDUCE_USE_DFLT (-32)
#define YY_REDUCE_COUNT (24)
#define YY_REDUCE_MIN   (-31)
#define YY_REDUCE_MAX   (184)
static const short yy_reduce_ofst[] = {
 /*     0 */    32,   78,   43,   89,   89,   89,  170,  163,  156,  148,
 /*    10 */   140,  133,  126,  116,  105,   65,  184,  176,  -31,  108,
 /*    20 */    57,   48,   19,   66,   58,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   107,  107,  107,  107,  107,  107,  107,  107,  107,  107,
 /*    10 */   107,  107,  107,  107,  107,  107,  107,  107,  107,  107,
 /*    20 */   107,  107,  107,  107,  107,   94,   91,  107,  107,  104,
 /*    30 */    98,   97,   96,   95,  107,   78,  107,   75,  107,  107,
 /*    40 */   107,  107,   74,   73,   84,   83,   82,   81,   80,   79,
 /*    50 */    90,   89,   88,   87,   86,   93,  103,  102,  106,  105,
 /*    60 */   104,  101,  100,   99,   92,   85,   77,   76,   72,   71,
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
  "EQUAL",         "IDENTIFIER",    "KEYWORD_PRINT",  "KEYWORD_INTEGER",
  "KEYWORD_FLOAT",  "LOGICAL_EQ",    "LOGICAL_NE",    "LOGICAL_GT",  
  "LOGICAL_LT",    "LOGICAL_GTE",   "LOGICAL_LTE",   "PLUS",        
  "MINUS",         "MUL",           "DIV",           "MOD",         
  "EXP",           "INTEGER",       "FLOAT",         "error",       
  "statementgroup",  "statement",     "flowstatement",  "fexpression", 
  "expression",    "definition",    "datatype",      "term",        
  "signedFactor",  "factor",        "program",     
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
 /*   9 */ "statement ::= IDENTIFIER EQUAL fexpression",
 /*  10 */ "statement ::= fexpression",
 /*  11 */ "statement ::= KEYWORD_PRINT fexpression",
 /*  12 */ "definition ::= datatype IDENTIFIER",
 /*  13 */ "datatype ::= KEYWORD_INTEGER",
 /*  14 */ "datatype ::= KEYWORD_FLOAT",
 /*  15 */ "fexpression ::= expression LOGICAL_EQ fexpression",
 /*  16 */ "fexpression ::= expression LOGICAL_NE fexpression",
 /*  17 */ "fexpression ::= expression LOGICAL_GT fexpression",
 /*  18 */ "fexpression ::= expression LOGICAL_LT fexpression",
 /*  19 */ "fexpression ::= expression LOGICAL_GTE fexpression",
 /*  20 */ "fexpression ::= expression LOGICAL_LTE fexpression",
 /*  21 */ "fexpression ::= expression",
 /*  22 */ "expression ::= term PLUS expression",
 /*  23 */ "expression ::= term MINUS expression",
 /*  24 */ "expression ::= term",
 /*  25 */ "term ::= term MUL term",
 /*  26 */ "term ::= term DIV term",
 /*  27 */ "term ::= term MOD term",
 /*  28 */ "term ::= term EXP term",
 /*  29 */ "term ::= signedFactor",
 /*  30 */ "signedFactor ::= PLUS factor",
 /*  31 */ "signedFactor ::= MINUS factor",
 /*  32 */ "signedFactor ::= factor",
 /*  33 */ "factor ::= LPAREN expression RPAREN",
 /*  34 */ "factor ::= IDENTIFIER",
 /*  35 */ "factor ::= INTEGER",
 /*  36 */ "factor ::= FLOAT",
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
#line 37 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"

	printf("\tstack overflowed\n");
#line 646 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
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
  { 38, 1 },
  { 28, 3 },
  { 28, 2 },
  { 28, 1 },
  { 28, 2 },
  { 30, 7 },
  { 30, 11 },
  { 29, 3 },
  { 29, 1 },
  { 29, 3 },
  { 29, 1 },
  { 29, 2 },
  { 33, 2 },
  { 34, 1 },
  { 34, 1 },
  { 31, 3 },
  { 31, 3 },
  { 31, 3 },
  { 31, 3 },
  { 31, 3 },
  { 31, 3 },
  { 31, 1 },
  { 32, 3 },
  { 32, 3 },
  { 32, 1 },
  { 35, 3 },
  { 35, 3 },
  { 35, 3 },
  { 35, 3 },
  { 35, 1 },
  { 36, 2 },
  { 36, 2 },
  { 36, 1 },
  { 37, 3 },
  { 37, 1 },
  { 37, 1 },
  { 37, 1 },
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
#line 43 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	tmpHack = malloc(sizeof(struct Program));
	yymsp[0].minor.yy67->parent = NULL;
	tmpHack->context = yymsp[0].minor.yy67;
}
#line 801 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 1: /* statementgroup ::= statementgroup statement SEMICOLON */
#line 49 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	/*yymsp[-2].minor.yy67 will be a Context*/
	/*yymsp[-1].minor.yy8 will be a GenericStatement*/
	struct GenericStatement *gStmnt;

	/*add statement to the end of the statement group*/
	List_Add_Value(yymsp[-2].minor.yy67->statements, yymsp[-1].minor.yy8, struct GenericStatement *);
	if(yymsp[-1].minor.yy8->hasDef){
		List_Add_Value(yymsp[-2].minor.yy67->symbols, yymsp[-1].minor.yy8->sym, struct Symbol *);
	}
	if(yymsp[-1].minor.yy8->type == IFSTATEMENT){
		yymsp[-1].minor.yy8->ifstmt->yes->parent = yymsp[-2].minor.yy67;
		if(yymsp[-1].minor.yy8->ifstmt->no){
			yymsp[-1].minor.yy8->ifstmt->no->parent = yymsp[-2].minor.yy67;
		}
	}
	yygotominor.yy67 = yymsp[-2].minor.yy67;
}
#line 823 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 2: /* statementgroup ::= statementgroup flowstatement */
#line 68 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	/*yymsp[-1].minor.yy67 will be a Context*/
	/*yymsp[0].minor.yy8 will be a GenericStatement*/
	struct GenericStatement *gStmnt;

	/*add statement to the end of the statement group*/
	List_Add_Value(yymsp[-1].minor.yy67->statements, yymsp[0].minor.yy8,struct GenericStatement *);
	if(yymsp[0].minor.yy8->hasDef){
		List_Add_Value(yymsp[-1].minor.yy67->symbols, yymsp[0].minor.yy8->sym, struct Symbol *);
	}
	yygotominor.yy67 = yymsp[-1].minor.yy67;
}
#line 839 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 3: /* statementgroup ::= flowstatement */
#line 81 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy67 = new_context(yymsp[0].minor.yy8);
}
#line 846 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 4: /* statementgroup ::= statement SEMICOLON */
#line 85 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy67 = new_context(yymsp[-1].minor.yy8);
}
#line 853 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 5: /* flowstatement ::= KEYWORD_IF LPAREN fexpression RPAREN LCURLY statementgroup RCURLY */
#line 90 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = IFSTATEMENT;
	stmt->ifstmt = malloc(sizeof(struct IfStatement));
	stmt->ifstmt->testStatement = yymsp[-4].minor.yy32;
	stmt->ifstmt->yes = yymsp[-1].minor.yy67;
	stmt->ifstmt->no = NULL;
	yygotominor.yy8 = stmt;
}
#line 867 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 6: /* flowstatement ::= KEYWORD_IF LPAREN fexpression RPAREN LCURLY statementgroup RCURLY KEYWORD_ELSE LCURLY statementgroup RCURLY */
#line 101 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = IFSTATEMENT;
	stmt->ifstmt = malloc(sizeof(struct IfStatement));
	stmt->ifstmt->testStatement = yymsp[-8].minor.yy32;
	stmt->ifstmt->yes = yymsp[-5].minor.yy67;
	stmt->ifstmt->no = yymsp[-1].minor.yy67;
	yygotominor.yy8 = stmt;
}
#line 881 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 7: /* statement ::= definition EQUAL fexpression */
#line 112 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *dst;
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 1;
	stmt->sym = yymsp[-2].minor.yy12;

	dst = new_expression(SOURCE);
	dst->dataSource.sym = yymsp[-2].minor.yy12;
	dst->source_type = SYMBOL;
	
	stmt->exp = new_expression_children(ASSIGNMENT, dst, yymsp[0].minor.yy32);
	
	yygotominor.yy8 = stmt;
}
#line 901 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 8: /* statement ::= definition */
#line 129 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 1;
	stmt->sym = yymsp[0].minor.yy12;
	stmt->exp = NULL;

	yygotominor.yy8 = stmt;
}
#line 915 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 9: /* statement ::= IDENTIFIER EQUAL fexpression */
#line 140 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *dst;
	struct GenericStatement *stmt;

	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 0;

	dst = new_expression(SOURCE);
	dst->dataSource.sym = new_symbol(yymsp[-2].minor.yy0->literal, tVOID);;
	dst->source_type = SYMBOL;
	
	stmt->exp = new_expression_children(ASSIGNMENT, dst, yymsp[0].minor.yy32);
	
	yygotominor.yy8 = stmt;
}
#line 935 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 10: /* statement ::= fexpression */
#line 157 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 0;
	stmt->sym = NULL;

	stmt->exp = yymsp[0].minor.yy32;
	
	yygotominor.yy8 = stmt;
}
#line 950 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 11: /* statement ::= KEYWORD_PRINT fexpression */
#line 170 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	struct Expression *print = new_expression(PRINT);
	print->left = NULL;
	print->right = yymsp[0].minor.yy32;

	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 0;
	stmt->sym = NULL;

	stmt->exp = print;
	
	yygotominor.yy8 = stmt;
}
#line 969 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 12: /* definition ::= datatype IDENTIFIER */
#line 186 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yymsp[-1].minor.yy12->name = yymsp[0].minor.yy0->literal;
	yygotominor.yy12 = yymsp[-1].minor.yy12;
}
#line 977 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 13: /* datatype ::= KEYWORD_INTEGER */
#line 191 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy12 = new_symbol(NULL, tINTEGER);
}
#line 984 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 14: /* datatype ::= KEYWORD_FLOAT */
#line 195 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy12 = new_symbol(NULL, tFLOAT);
}
#line 991 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 15: /* fexpression ::= expression LOGICAL_EQ fexpression */
#line 200 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy32 = new_expression_children(CHECK_EQ, yymsp[-2].minor.yy32, yymsp[0].minor.yy32);
}
#line 998 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 16: /* fexpression ::= expression LOGICAL_NE fexpression */
#line 204 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy32 = new_expression_children(CHECK_NE, yymsp[-2].minor.yy32, yymsp[0].minor.yy32);
}
#line 1005 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 17: /* fexpression ::= expression LOGICAL_GT fexpression */
#line 208 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy32 = new_expression_children(CHECK_GT, yymsp[-2].minor.yy32, yymsp[0].minor.yy32);
}
#line 1012 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 18: /* fexpression ::= expression LOGICAL_LT fexpression */
#line 212 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy32 = new_expression_children(CHECK_LT, yymsp[-2].minor.yy32, yymsp[0].minor.yy32);
}
#line 1019 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 19: /* fexpression ::= expression LOGICAL_GTE fexpression */
#line 216 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy32 = new_expression_children(CHECK_GTE, yymsp[-2].minor.yy32, yymsp[0].minor.yy32);
}
#line 1026 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 20: /* fexpression ::= expression LOGICAL_LTE fexpression */
#line 220 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy32 = new_expression_children(CHECK_LTE, yymsp[-2].minor.yy32, yymsp[0].minor.yy32);
}
#line 1033 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 21: /* fexpression ::= expression */
      case 24: /* expression ::= term */ yytestcase(yyruleno==24);
      case 29: /* term ::= signedFactor */ yytestcase(yyruleno==29);
      case 32: /* signedFactor ::= factor */ yytestcase(yyruleno==32);
#line 224 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy32 = yymsp[0].minor.yy32;
}
#line 1043 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 22: /* expression ::= term PLUS expression */
#line 228 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy32 = new_expression_children(ADD, yymsp[-2].minor.yy32, yymsp[0].minor.yy32);
}
#line 1050 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 23: /* expression ::= term MINUS expression */
#line 232 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy32 = new_expression_children(SUBTRACT, yymsp[-2].minor.yy32, yymsp[0].minor.yy32);
}
#line 1057 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 25: /* term ::= term MUL term */
#line 243 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy32 = new_expression_children(MULTIPLY, yymsp[-2].minor.yy32, yymsp[0].minor.yy32);
}
#line 1064 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 26: /* term ::= term DIV term */
#line 247 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy32 = new_expression_children(DIVIDE, yymsp[-2].minor.yy32, yymsp[0].minor.yy32);
}
#line 1071 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 27: /* term ::= term MOD term */
#line 251 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy32 = new_expression_children(MODULUS, yymsp[-2].minor.yy32, yymsp[0].minor.yy32);
}
#line 1078 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 28: /* term ::= term EXP term */
#line 255 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy32 = new_expression_children(POWER, yymsp[-2].minor.yy32, yymsp[0].minor.yy32);
}
#line 1085 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 30: /* signedFactor ::= PLUS factor */
#line 264 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	/*possibly make this imply absolute value*/
	yygotominor.yy32 = yymsp[0].minor.yy32;
}
#line 1093 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 31: /* signedFactor ::= MINUS factor */
#line 268 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp = new_expression(MULTIPLY);
	struct Expression *LHS = new_expression(SOURCE);
	
	LHS->source_type = INTEGER;
	LHS->dataSource.Integer = -1;
	
	tmp->left = LHS;
	tmp->right = yymsp[0].minor.yy32;
	
	yygotominor.yy32 = tmp;
}
#line 1109 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 33: /* factor ::= LPAREN expression RPAREN */
#line 285 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy32 = yymsp[-1].minor.yy32;
}
#line 1116 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 34: /* factor ::= IDENTIFIER */
#line 288 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = SYMBOL;
	tmp->dataSource.sym = new_symbol(yymsp[0].minor.yy0->literal, tVOID);
	yygotominor.yy32 = tmp;
}
#line 1127 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 35: /* factor ::= INTEGER */
#line 296 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = INTEGER;
	tmp->dataSource.Integer = yymsp[0].minor.yy0->intData;
	yygotominor.yy32 = tmp;
}
#line 1138 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 36: /* factor ::= FLOAT */
#line 304 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = FLOAT;
	tmp->dataSource.Float = yymsp[0].minor.yy0->floatData;
	yygotominor.yy32 = tmp;
}
#line 1149 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
        break;
      default:
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
#line 34 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"

	printf("\tparse failed\n");
#line 1200 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
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
#line 41 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"
 printf("\t\x1b[1m\x1b[91mSYNTAX ERROR!!!!\x1b[0m\n");  exit(-1);
#line 1217 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
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
#line 31 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.y"

	printf("\tparse accepted\n");
#line 1239 "/Users/Joey/Desktop/School/CS 498/Compiler/Lexer_Parser/LangParse.c"
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
