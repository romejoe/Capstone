/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#include <stdio.h>
#line 1 "build/Compiler/Lexer_Parser/LangParse.y"

	#include <stdlib.h>
	#include <assert.h>
	#include "token.h"
	#include "program.h"


	struct Program *tmpHack = NULL;

	struct Program *getProgram(void *yyparser){
  		return tmpHack;
	}

#line 22 "build/Compiler/Lexer_Parser/LangParse.c"
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
#define YYNOCODE 45
#define YYACTIONTYPE unsigned char
#define ParseTOKENTYPE Token *
typedef union {
  int yyinit;
  ParseTOKENTYPE yy0;
  struct Symbol * yy22;
  struct GenericStatement * yy42;
  struct Context * yy65;
  struct Expression * yy68;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define ParseARG_SDECL
#define ParseARG_PDECL
#define ParseARG_FETCH
#define ParseARG_STORE
#define YYNSTATE 85
#define YYNRULE 42
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
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    36,    9,   82,   38,   70,    3,   41,   27,   49,   13,
 /*    10 */    52,   55,   35,   73,   75,   32,   44,   50,   33,   60,
 /*    20 */    81,   29,   30,   85,   11,   36,    9,   31,   53,   84,
 /*    30 */    14,   41,   40,   49,   13,   52,   55,   23,   24,   28,
 /*    40 */    25,   26,   27,    9,    2,   43,   29,   30,   79,   58,
 /*    50 */    54,   17,   31,   53,   84,   36,    9,   76,   56,   39,
 /*    60 */    83,   41,    1,   49,   13,   52,   55,   16,   66,   32,
 /*    70 */    53,   84,   33,   60,   81,   80,   29,   30,   33,   60,
 /*    80 */    81,   78,   31,   53,   84,   36,    9,  129,  129,   68,
 /*    90 */   129,   41,  129,   49,   13,   52,   55,  129,   59,   32,
 /*   100 */   129,  129,   33,   60,   81,  129,   29,   30,  129,   36,
 /*   110 */     9,  129,   31,   53,   84,   41,  129,   49,   13,   52,
 /*   120 */    55,   45,   32,  129,  129,   33,   60,   81,   57,   32,
 /*   130 */    29,   30,   33,   60,   81,  129,   31,   53,   84,  129,
 /*   140 */   129,    7,   51,   72,   75,   32,   44,   50,   33,   60,
 /*   150 */    81,  128,    6,   51,   72,   75,   32,   44,   50,   33,
 /*   160 */    60,   81,  129,  129,    4,   51,   72,   75,   32,   44,
 /*   170 */    50,   33,   60,   81,  129,    5,   51,   72,   75,   32,
 /*   180 */    44,   50,   33,   60,   81,   19,   10,    8,   22,   21,
 /*   190 */    20,   18,   15,   12,    9,   46,   60,   81,   74,   32,
 /*   200 */   129,   54,   33,   60,   81,   71,   32,  129,  129,   33,
 /*   210 */    60,   81,   77,   32,   29,   30,   33,   60,   81,  129,
 /*   220 */    31,   53,   84,   42,   32,  129,  129,   33,   60,   81,
 /*   230 */    69,   32,  129,  129,   33,   60,   81,  129,   37,   32,
 /*   240 */   129,  129,   33,   60,   81,  129,   67,   32,  129,  129,
 /*   250 */    33,   60,   81,   64,   32,  129,  129,   33,   60,   81,
 /*   260 */    65,   32,  129,  129,   33,   60,   81,   63,   32,  129,
 /*   270 */   129,   33,   60,   81,  129,   61,   32,  129,  129,   33,
 /*   280 */    60,   81,   62,  129,  129,   33,   60,   81,   48,   60,
 /*   290 */    81,   34,   60,   81,   47,   60,   81,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     2,    3,   10,    4,    6,    5,    8,   28,   10,   11,
 /*    10 */    12,   13,   34,   35,   36,   37,   38,   39,   40,   41,
 /*    20 */    42,   23,   24,    0,    9,    2,    3,   29,   30,   31,
 /*    30 */     3,    8,    7,   10,   11,   12,   13,   23,   24,   25,
 /*    40 */    26,   27,   28,    3,    5,    4,   23,   24,    4,   42,
 /*    50 */    10,    9,   29,   30,   31,    2,    3,    1,   42,    6,
 /*    60 */    42,    8,    5,   10,   11,   12,   13,    3,   36,   37,
 /*    70 */    30,   31,   40,   41,   42,   37,   23,   24,   40,   41,
 /*    80 */    42,    1,   29,   30,   31,    2,    3,   44,   44,    6,
 /*    90 */    44,    8,   44,   10,   11,   12,   13,   44,   36,   37,
 /*   100 */    44,   44,   40,   41,   42,   44,   23,   24,   44,    2,
 /*   110 */     3,   44,   29,   30,   31,    8,   44,   10,   11,   12,
 /*   120 */    13,   36,   37,   44,   44,   40,   41,   42,   36,   37,
 /*   130 */    23,   24,   40,   41,   42,   44,   29,   30,   31,   44,
 /*   140 */    44,   33,   34,   35,   36,   37,   38,   39,   40,   41,
 /*   150 */    42,   43,   33,   34,   35,   36,   37,   38,   39,   40,
 /*   160 */    41,   42,   44,   44,   33,   34,   35,   36,   37,   38,
 /*   170 */    39,   40,   41,   42,   44,   33,   34,   35,   36,   37,
 /*   180 */    38,   39,   40,   41,   42,   14,   15,   16,   17,   18,
 /*   190 */    19,   20,   21,   22,    3,   40,   41,   42,   36,   37,
 /*   200 */    44,   10,   40,   41,   42,   36,   37,   44,   44,   40,
 /*   210 */    41,   42,   36,   37,   23,   24,   40,   41,   42,   44,
 /*   220 */    29,   30,   31,   36,   37,   44,   44,   40,   41,   42,
 /*   230 */    36,   37,   44,   44,   40,   41,   42,   44,   36,   37,
 /*   240 */    44,   44,   40,   41,   42,   44,   36,   37,   44,   44,
 /*   250 */    40,   41,   42,   36,   37,   44,   44,   40,   41,   42,
 /*   260 */    36,   37,   44,   44,   40,   41,   42,   36,   37,   44,
 /*   270 */    44,   40,   41,   42,   44,   36,   37,   44,   44,   40,
 /*   280 */    41,   42,   37,   44,   44,   40,   41,   42,   40,   41,
 /*   290 */    42,   40,   41,   42,   40,   41,   42,
};
#define YY_SHIFT_USE_DFLT (-22)
#define YY_SHIFT_MAX 51
static const short yy_shift_ofst[] = {
 /*     0 */   107,  107,  107,  107,   53,   83,   -2,   23,  191,  191,
 /*    10 */   191,  191,  191,  191,  191,  191,  191,  191,  191,  191,
 /*    20 */   191,  191,  191,  191,  191,  191,  191,  191,  191,   40,
 /*    30 */    40,   40,  171,   14,  -21,   56,   64,   -1,    0,   25,
 /*    40 */    39,   27,   41,   57,   42,   44,  -21,  -21,  -21,   15,
 /*    50 */    -8,   80,
};
#define YY_REDUCE_USE_DFLT (-23)
#define YY_REDUCE_MAX 31
static const short yy_reduce_ofst[] = {
 /*     0 */   108,  142,  119,  131,  -22,  -22,  -22,  -22,   62,   85,
 /*    10 */    92,  162,  169,  176,  187,  194,  202,   32,  210,  217,
 /*    20 */   224,  231,  239,  245,   38,  254,  251,  248,  155,    7,
 /*    30 */    16,   18,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   127,  127,  127,  127,  127,  127,  127,  127,  127,  127,
 /*    10 */   127,  127,  127,  127,  127,  127,  127,  127,  127,  127,
 /*    20 */   127,  127,  127,  127,  127,  127,  127,  127,  127,  127,
 /*    30 */   127,  127,  110,  113,  116,  127,  127,  127,  127,   90,
 /*    40 */   127,  127,  127,  127,   94,  127,  114,  115,  117,  124,
 /*    50 */   127,  127,   99,  125,  124,  100,  120,  102,  119,  103,
 /*    60 */   118,  104,  111,  105,  101,  106,   93,  107,   92,  108,
 /*    70 */    91,  109,   88,   87,   95,   96,   86,   97,   89,  123,
 /*    80 */   112,  122,   98,  121,  126,
};
#define YY_SZ_ACTTAB (int)(sizeof(yy_action)/sizeof(yy_action[0]))

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
  "KEYWORD_WHILE",  "EQUAL",         "IDENTIFIER",    "KEYWORD_PRINT",
  "KEYWORD_INTEGER",  "KEYWORD_FLOAT",  "LOGICAL_EQ",    "LOGICAL_NE",  
  "LOGICAL_GT",    "LOGICAL_LT",    "LOGICAL_GTE",   "LOGICAL_LTE", 
  "LOGICAL_AND",   "LOGICAL_OR",    "LOGICAL_XOR",   "PLUS",        
  "MINUS",         "MUL",           "DIV",           "MOD",         
  "EXP",           "LOGICAL_NOT",   "INTEGER",       "FLOAT",       
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
 /*   7 */ "flowstatement ::= KEYWORD_WHILE LPAREN fexpression RPAREN LCURLY statementgroup RCURLY",
 /*   8 */ "statement ::= definition EQUAL fexpression",
 /*   9 */ "statement ::= definition",
 /*  10 */ "statement ::= IDENTIFIER EQUAL fexpression",
 /*  11 */ "statement ::= fexpression",
 /*  12 */ "statement ::= KEYWORD_PRINT fexpression",
 /*  13 */ "definition ::= datatype IDENTIFIER",
 /*  14 */ "datatype ::= KEYWORD_INTEGER",
 /*  15 */ "datatype ::= KEYWORD_FLOAT",
 /*  16 */ "fexpression ::= expression LOGICAL_EQ fexpression",
 /*  17 */ "fexpression ::= expression LOGICAL_NE fexpression",
 /*  18 */ "fexpression ::= expression LOGICAL_GT fexpression",
 /*  19 */ "fexpression ::= expression LOGICAL_LT fexpression",
 /*  20 */ "fexpression ::= expression LOGICAL_GTE fexpression",
 /*  21 */ "fexpression ::= expression LOGICAL_LTE fexpression",
 /*  22 */ "fexpression ::= expression LOGICAL_AND fexpression",
 /*  23 */ "fexpression ::= expression LOGICAL_OR fexpression",
 /*  24 */ "fexpression ::= expression LOGICAL_XOR fexpression",
 /*  25 */ "fexpression ::= expression",
 /*  26 */ "expression ::= term PLUS expression",
 /*  27 */ "expression ::= term MINUS expression",
 /*  28 */ "expression ::= term",
 /*  29 */ "term ::= term MUL term",
 /*  30 */ "term ::= term DIV term",
 /*  31 */ "term ::= term MOD term",
 /*  32 */ "term ::= term EXP term",
 /*  33 */ "term ::= signedFactor",
 /*  34 */ "signedFactor ::= PLUS factor",
 /*  35 */ "signedFactor ::= MINUS factor",
 /*  36 */ "signedFactor ::= LOGICAL_NOT factor",
 /*  37 */ "signedFactor ::= factor",
 /*  38 */ "factor ::= LPAREN fexpression RPAREN",
 /*  39 */ "factor ::= IDENTIFIER",
 /*  40 */ "factor ::= INTEGER",
 /*  41 */ "factor ::= FLOAT",
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
 
  if( stateno>YY_SHIFT_MAX || (i = yy_shift_ofst[stateno])==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
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
        if( j>=0 && j<YY_SZ_ACTTAB && yy_lookahead[j]==YYWILDCARD ){
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
  if( stateno>YY_REDUCE_MAX ){
    return yy_default[stateno];
  }
#else
  assert( stateno<=YY_REDUCE_MAX );
#endif
  i = yy_reduce_ofst[stateno];
  assert( i!=YY_REDUCE_USE_DFLT );
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
#ifdef YYERRORSYMBOL
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }
#else
  assert( i>=0 && i<YY_SZ_ACTTAB );
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
#line 37 "build/Compiler/Lexer_Parser/LangParse.y"

	printf("\tstack overflowed\n");
#line 657 "build/Compiler/Lexer_Parser/LangParse.c"
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
  { 43, 1 },
  { 33, 3 },
  { 33, 2 },
  { 33, 1 },
  { 33, 2 },
  { 35, 7 },
  { 35, 11 },
  { 35, 7 },
  { 34, 3 },
  { 34, 1 },
  { 34, 3 },
  { 34, 1 },
  { 34, 2 },
  { 38, 2 },
  { 39, 1 },
  { 39, 1 },
  { 36, 3 },
  { 36, 3 },
  { 36, 3 },
  { 36, 3 },
  { 36, 3 },
  { 36, 3 },
  { 36, 3 },
  { 36, 3 },
  { 36, 3 },
  { 36, 1 },
  { 37, 3 },
  { 37, 3 },
  { 37, 1 },
  { 40, 3 },
  { 40, 3 },
  { 40, 3 },
  { 40, 3 },
  { 40, 1 },
  { 41, 2 },
  { 41, 2 },
  { 41, 2 },
  { 41, 1 },
  { 42, 3 },
  { 42, 1 },
  { 42, 1 },
  { 42, 1 },
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
#line 43 "build/Compiler/Lexer_Parser/LangParse.y"
{
	tmpHack = malloc(sizeof(struct Program));
	yymsp[0].minor.yy65->parent = NULL;
	tmpHack->context = yymsp[0].minor.yy65;
}
#line 817 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 1: /* statementgroup ::= statementgroup statement SEMICOLON */
#line 49 "build/Compiler/Lexer_Parser/LangParse.y"
{
	/*yymsp[-2].minor.yy65 will be a Context*/
	/*yymsp[-1].minor.yy42 will be a GenericStatement*/
	struct GenericStatement *gStmnt;

	/*add statement to the end of the statement group*/
	List_Add_Value(yymsp[-2].minor.yy65->statements, yymsp[-1].minor.yy42, struct GenericStatement *);
	if(yymsp[-1].minor.yy42->hasDef){
		List_Add_Value(yymsp[-2].minor.yy65->symbols, yymsp[-1].minor.yy42->sym, struct Symbol *);
	}
	if(yymsp[-1].minor.yy42->type == IFSTATEMENT){
		yymsp[-1].minor.yy42->ifstmt->yes->parent = yymsp[-2].minor.yy65;
		if(yymsp[-1].minor.yy42->ifstmt->no){
			yymsp[-1].minor.yy42->ifstmt->no->parent = yymsp[-2].minor.yy65;
		}
	}
	else if (yymsp[-1].minor.yy42->type == WHILESTATEMENT){
		yymsp[-1].minor.yy42->whilestmt->code->parent = yymsp[-2].minor.yy65;
	}
	yygotominor.yy65 = yymsp[-2].minor.yy65;
}
#line 842 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 2: /* statementgroup ::= statementgroup flowstatement */
#line 71 "build/Compiler/Lexer_Parser/LangParse.y"
{
	/*yymsp[-1].minor.yy65 will be a Context*/
	/*yymsp[0].minor.yy42 will be a GenericStatement*/
	struct GenericStatement *gStmnt;

	printf("\t\tf\n");
	/*add statement to the end of the statement group*/
	List_Add_Value(yymsp[-1].minor.yy65->statements, yymsp[0].minor.yy42,struct GenericStatement *);
	if(yymsp[0].minor.yy42->hasDef){
		List_Add_Value(yymsp[-1].minor.yy65->symbols, yymsp[0].minor.yy42->sym, struct Symbol *);
	}

	if(yymsp[0].minor.yy42->type == IFSTATEMENT){
		yymsp[0].minor.yy42->ifstmt->yes->parent = yymsp[-1].minor.yy65;
		if(yymsp[0].minor.yy42->ifstmt->no){
			yymsp[0].minor.yy42->ifstmt->no->parent = yymsp[-1].minor.yy65;
		}
	}
	else if (yymsp[0].minor.yy42->type == WHILESTATEMENT){
		yymsp[0].minor.yy42->whilestmt->code->parent = yymsp[-1].minor.yy65;
	}
	yygotominor.yy65 = yymsp[-1].minor.yy65;
}
#line 869 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 3: /* statementgroup ::= flowstatement */
#line 95 "build/Compiler/Lexer_Parser/LangParse.y"
{
	printf("\t\tasdf\n");
	yygotominor.yy65 = new_context(yymsp[0].minor.yy42);
	if(yymsp[0].minor.yy42->type == IFSTATEMENT){
		yymsp[0].minor.yy42->ifstmt->yes->parent = yygotominor.yy65;
		if(yymsp[0].minor.yy42->ifstmt->no){
			yymsp[0].minor.yy42->ifstmt->no->parent = yygotominor.yy65;
		}
	}
	else if (yymsp[0].minor.yy42->type == WHILESTATEMENT){
		yymsp[0].minor.yy42->whilestmt->code->parent = yygotominor.yy65;
	}
}
#line 886 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 4: /* statementgroup ::= statement SEMICOLON */
#line 109 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy65 = new_context(yymsp[-1].minor.yy42);
}
#line 893 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 5: /* flowstatement ::= KEYWORD_IF LPAREN fexpression RPAREN LCURLY statementgroup RCURLY */
#line 114 "build/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = IFSTATEMENT;
	stmt->ifstmt = malloc(sizeof(struct IfStatement));
	stmt->ifstmt->testStatement = yymsp[-4].minor.yy68;
	stmt->ifstmt->yes = yymsp[-1].minor.yy65;
	stmt->ifstmt->no = NULL;
	yygotominor.yy42 = stmt;
}
#line 907 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 6: /* flowstatement ::= KEYWORD_IF LPAREN fexpression RPAREN LCURLY statementgroup RCURLY KEYWORD_ELSE LCURLY statementgroup RCURLY */
#line 125 "build/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = IFSTATEMENT;
	stmt->ifstmt = malloc(sizeof(struct IfStatement));
	stmt->ifstmt->testStatement = yymsp[-8].minor.yy68;
	stmt->ifstmt->yes = yymsp[-5].minor.yy65;
	stmt->ifstmt->no = yymsp[-1].minor.yy65;
	yygotominor.yy42 = stmt;
}
#line 921 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 7: /* flowstatement ::= KEYWORD_WHILE LPAREN fexpression RPAREN LCURLY statementgroup RCURLY */
#line 136 "build/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = WHILESTATEMENT;
	stmt->ifstmt = malloc(sizeof(struct WhileStatement));
	stmt->whilestmt->testStatement = yymsp[-4].minor.yy68;
	stmt->whilestmt->code = yymsp[-1].minor.yy65;
	yygotominor.yy42 = stmt;
}
#line 934 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 8: /* statement ::= definition EQUAL fexpression */
#line 146 "build/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *dst;
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 1;
	stmt->sym = yymsp[-2].minor.yy22;

	dst = new_expression(SOURCE);
	dst->dataSource.sym = yymsp[-2].minor.yy22;
	dst->source_type = SYMBOL;
	
	stmt->exp = new_expression_children(ASSIGNMENT, dst, yymsp[0].minor.yy68);
	
	yygotominor.yy42 = stmt;
}
#line 954 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 9: /* statement ::= definition */
#line 163 "build/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 1;
	stmt->sym = yymsp[0].minor.yy22;
	stmt->exp = NULL;

	yygotominor.yy42 = stmt;
}
#line 968 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 10: /* statement ::= IDENTIFIER EQUAL fexpression */
#line 174 "build/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *dst;
	struct GenericStatement *stmt;

	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 0;

	dst = new_expression(SOURCE);
	dst->dataSource.sym = new_symbol(yymsp[-2].minor.yy0->literal, tVOID);;
	dst->source_type = SYMBOL;
	
	stmt->exp = new_expression_children(ASSIGNMENT, dst, yymsp[0].minor.yy68);
	
	yygotominor.yy42 = stmt;
}
#line 988 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 11: /* statement ::= fexpression */
#line 191 "build/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 0;
	stmt->sym = NULL;

	stmt->exp = yymsp[0].minor.yy68;
	
	yygotominor.yy42 = stmt;
}
#line 1003 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 12: /* statement ::= KEYWORD_PRINT fexpression */
#line 204 "build/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	struct Expression *print = new_expression(PRINT);
	print->left = NULL;
	print->right = yymsp[0].minor.yy68;

	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 0;
	stmt->sym = NULL;

	stmt->exp = print;
	
	yygotominor.yy42 = stmt;
}
#line 1022 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 13: /* definition ::= datatype IDENTIFIER */
#line 220 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yymsp[-1].minor.yy22->name = yymsp[0].minor.yy0->literal;
	yygotominor.yy22 = yymsp[-1].minor.yy22;
}
#line 1030 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 14: /* datatype ::= KEYWORD_INTEGER */
#line 225 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy22 = new_symbol(NULL, tINTEGER);
}
#line 1037 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 15: /* datatype ::= KEYWORD_FLOAT */
#line 229 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy22 = new_symbol(NULL, tFLOAT);
}
#line 1044 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 16: /* fexpression ::= expression LOGICAL_EQ fexpression */
#line 234 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = new_expression_children(CHECK_EQ, yymsp[-2].minor.yy68, yymsp[0].minor.yy68);
}
#line 1051 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 17: /* fexpression ::= expression LOGICAL_NE fexpression */
#line 238 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = new_expression_children(CHECK_NE, yymsp[-2].minor.yy68, yymsp[0].minor.yy68);
}
#line 1058 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 18: /* fexpression ::= expression LOGICAL_GT fexpression */
#line 242 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = new_expression_children(CHECK_GT, yymsp[-2].minor.yy68, yymsp[0].minor.yy68);
}
#line 1065 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 19: /* fexpression ::= expression LOGICAL_LT fexpression */
#line 246 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = new_expression_children(CHECK_LT, yymsp[-2].minor.yy68, yymsp[0].minor.yy68);
}
#line 1072 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 20: /* fexpression ::= expression LOGICAL_GTE fexpression */
#line 250 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = new_expression_children(CHECK_GTE, yymsp[-2].minor.yy68, yymsp[0].minor.yy68);
}
#line 1079 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 21: /* fexpression ::= expression LOGICAL_LTE fexpression */
#line 254 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = new_expression_children(CHECK_LTE, yymsp[-2].minor.yy68, yymsp[0].minor.yy68);
}
#line 1086 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 22: /* fexpression ::= expression LOGICAL_AND fexpression */
#line 258 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = new_expression_children(LOG_AND, yymsp[-2].minor.yy68, yymsp[0].minor.yy68);
}
#line 1093 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 23: /* fexpression ::= expression LOGICAL_OR fexpression */
#line 262 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = new_expression_children(LOG_OR, yymsp[-2].minor.yy68, yymsp[0].minor.yy68);
}
#line 1100 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 24: /* fexpression ::= expression LOGICAL_XOR fexpression */
#line 266 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = new_expression_children(LOG_XOR, yymsp[-2].minor.yy68, yymsp[0].minor.yy68);
}
#line 1107 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 25: /* fexpression ::= expression */
      case 28: /* expression ::= term */ yytestcase(yyruleno==28);
      case 33: /* term ::= signedFactor */ yytestcase(yyruleno==33);
      case 37: /* signedFactor ::= factor */ yytestcase(yyruleno==37);
#line 270 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = yymsp[0].minor.yy68;
}
#line 1117 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 26: /* expression ::= term PLUS expression */
#line 274 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = new_expression_children(ADD, yymsp[-2].minor.yy68, yymsp[0].minor.yy68);
}
#line 1124 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 27: /* expression ::= term MINUS expression */
#line 278 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = new_expression_children(SUBTRACT, yymsp[-2].minor.yy68, yymsp[0].minor.yy68);
}
#line 1131 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 29: /* term ::= term MUL term */
#line 289 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = new_expression_children(MULTIPLY, yymsp[-2].minor.yy68, yymsp[0].minor.yy68);
}
#line 1138 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 30: /* term ::= term DIV term */
#line 293 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = new_expression_children(DIVIDE, yymsp[-2].minor.yy68, yymsp[0].minor.yy68);
}
#line 1145 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 31: /* term ::= term MOD term */
#line 297 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = new_expression_children(MODULUS, yymsp[-2].minor.yy68, yymsp[0].minor.yy68);
}
#line 1152 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 32: /* term ::= term EXP term */
#line 301 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = new_expression_children(POWER, yymsp[-2].minor.yy68, yymsp[0].minor.yy68);
}
#line 1159 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 34: /* signedFactor ::= PLUS factor */
#line 309 "build/Compiler/Lexer_Parser/LangParse.y"
{
	/*possibly make this imply absolute value*/
	yygotominor.yy68 = yymsp[0].minor.yy68;
}
#line 1167 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 35: /* signedFactor ::= MINUS factor */
#line 313 "build/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp = new_expression(MULTIPLY);
	struct Expression *LHS = new_expression(SOURCE);
	
	LHS->source_type = INTEGER;
	LHS->dataSource.Integer = -1;
	
	tmp->left = LHS;
	tmp->right = yymsp[0].minor.yy68;
	
	yygotominor.yy68 = tmp;
}
#line 1183 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 36: /* signedFactor ::= LOGICAL_NOT factor */
#line 326 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = new_expression_children(LOG_NOT, NULL, yymsp[0].minor.yy68);
}
#line 1190 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 38: /* factor ::= LPAREN fexpression RPAREN */
#line 334 "build/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy68 = yymsp[-1].minor.yy68;
}
#line 1197 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 39: /* factor ::= IDENTIFIER */
#line 337 "build/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = SYMBOL;
	tmp->dataSource.sym = new_symbol(yymsp[0].minor.yy0->literal, tVOID);
	yygotominor.yy68 = tmp;
}
#line 1208 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 40: /* factor ::= INTEGER */
#line 345 "build/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = INTEGER;
	tmp->dataSource.Integer = yymsp[0].minor.yy0->intData;
	yygotominor.yy68 = tmp;
}
#line 1219 "build/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 41: /* factor ::= FLOAT */
#line 353 "build/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = FLOAT;
	tmp->dataSource.Float = yymsp[0].minor.yy0->floatData;
	yygotominor.yy68 = tmp;
}
#line 1230 "build/Compiler/Lexer_Parser/LangParse.c"
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
#line 34 "build/Compiler/Lexer_Parser/LangParse.y"

	printf("\tparse failed\n");
#line 1281 "build/Compiler/Lexer_Parser/LangParse.c"
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
#line 41 "build/Compiler/Lexer_Parser/LangParse.y"
 printf("\t\x1b[1m\x1b[91mSYNTAX ERROR!!!!\x1b[0m\n");  exit(-1);
#line 1298 "build/Compiler/Lexer_Parser/LangParse.c"
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
#line 31 "build/Compiler/Lexer_Parser/LangParse.y"

	printf("\tparse accepted\n");
#line 1320 "build/Compiler/Lexer_Parser/LangParse.c"
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