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
#define YYNOCODE 33
#define YYACTIONTYPE unsigned char
#define ParseTOKENTYPE Token *
typedef union {
  int yyinit;
  ParseTOKENTYPE yy0;
  struct GenericStatement * yy10;
  struct Expression * yy12;
  struct Symbol * yy38;
  struct Context * yy57;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define ParseARG_SDECL
#define ParseARG_PDECL
#define ParseARG_FETCH
#define ParseARG_STORE
#define YYNSTATE 52
#define YYNRULE 27
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
#define YY_ACTTAB_COUNT (165)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    52,   30,   31,    8,   18,   47,   41,   51,   11,    6,
 /*    10 */    27,   35,   34,   17,   16,   24,   47,   41,   29,   44,
 /*    20 */    43,   42,   31,    8,    2,   10,   28,    1,   40,    6,
 /*    30 */    12,   35,   34,   17,   16,   23,   47,   41,   36,   44,
 /*    40 */    43,   42,   31,    8,   33,   46,   50,   81,   45,    6,
 /*    50 */    81,   35,   34,   17,   16,   31,    8,   81,   81,   44,
 /*    60 */    43,   42,    6,   81,   35,   34,   17,   16,   81,   22,
 /*    70 */    47,   41,   44,   43,   42,    5,   19,   38,   26,   20,
 /*    80 */    18,   47,   41,   80,    4,   19,   38,   26,   20,   18,
 /*    90 */    47,   41,   81,   21,   47,   41,    3,   19,   38,   26,
 /*   100 */    20,   18,   47,   41,   32,   38,   26,   20,   18,   47,
 /*   110 */    41,    9,    7,   15,   14,   13,   12,    8,   81,   81,
 /*   120 */     8,   81,   81,   81,   81,   81,   49,   17,   16,   18,
 /*   130 */    47,   41,   81,   44,   43,   42,   44,   43,   42,   81,
 /*   140 */    48,   81,   81,   18,   47,   41,   25,   81,   81,   18,
 /*   150 */    47,   41,   39,   81,   81,   18,   47,   41,   81,   37,
 /*   160 */    81,   81,   18,   47,   41,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     0,   25,    2,    3,   28,   29,   30,    1,    3,    9,
 /*    10 */     7,   11,   12,   13,   14,   28,   29,   30,    4,   19,
 /*    20 */    20,   21,    2,    3,    5,    8,    6,    5,    4,    9,
 /*    30 */    18,   11,   12,   13,   14,   28,   29,   30,   10,   19,
 /*    40 */    20,   21,    2,    3,    1,   30,    6,   32,   30,    9,
 /*    50 */    32,   11,   12,   13,   14,    2,    3,   32,   32,   19,
 /*    60 */    20,   21,    9,   32,   11,   12,   13,   14,   32,   28,
 /*    70 */    29,   30,   19,   20,   21,   23,   24,   25,   26,   27,
 /*    80 */    28,   29,   30,   31,   23,   24,   25,   26,   27,   28,
 /*    90 */    29,   30,   32,   28,   29,   30,   23,   24,   25,   26,
 /*   100 */    27,   28,   29,   30,   24,   25,   26,   27,   28,   29,
 /*   110 */    30,   13,   14,   15,   16,   17,   18,    3,   32,   32,
 /*   120 */     3,   32,   32,   32,   32,   32,   25,   13,   14,   28,
 /*   130 */    29,   30,   32,   19,   20,   21,   19,   20,   21,   32,
 /*   140 */    25,   32,   32,   28,   29,   30,   25,   32,   32,   28,
 /*   150 */    29,   30,   25,   32,   32,   28,   29,   30,   32,   25,
 /*   160 */    32,   32,   28,   29,   30,
};
#define YY_SHIFT_USE_DFLT (-1)
#define YY_SHIFT_COUNT (32)
#define YY_SHIFT_MIN   (0)
#define YY_SHIFT_MAX   (117)
static const signed char yy_shift_ofst[] = {
 /*     0 */    53,   53,   53,   40,   20,    0,  114,  114,  114,  114,
 /*    10 */   114,  114,  114,  114,  114,  114,  117,  117,   98,   43,
 /*    20 */    28,   12,   12,   12,   12,   24,   17,   22,    3,   19,
 /*    30 */    14,    5,    6,
};
#define YY_REDUCE_USE_DFLT (-25)
#define YY_REDUCE_COUNT (17)
#define YY_REDUCE_MIN   (-24)
#define YY_REDUCE_MAX   (134)
static const short yy_reduce_ofst[] = {
 /*     0 */    52,   73,   61,   80,   80,   80,  134,  127,  121,  115,
 /*    10 */   101,  -24,   65,   41,    7,  -13,   18,   15,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */    79,   79,   79,   79,   79,   79,   79,   79,   79,   79,
 /*    10 */    79,   79,   79,   79,   79,   79,   79,   79,   66,   79,
 /*    20 */    79,   70,   69,   68,   67,   79,   58,   79,   55,   79,
 /*    30 */    79,   79,   79,   54,   63,   62,   61,   60,   59,   65,
 /*    40 */    75,   74,   78,   77,   76,   73,   72,   71,   64,   57,
 /*    50 */    56,   53,
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
  "RPAREN",        "LCURLY",        "RCURLY",        "KEYWORD_ELSE",
  "EQUAL",         "KEYWORD_PRINT",  "IDENTIFIER",    "KEYWORD_INTEGER",
  "KEYWORD_FLOAT",  "PLUS",          "MINUS",         "MUL",         
  "DIV",           "MOD",           "EXP",           "SYMBOL",      
  "INTEGER",       "FLOAT",         "error",         "statementgroup",
  "statement",     "expression",    "definition",    "datatype",    
  "term",          "signedFactor",  "factor",        "program",     
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
 /*   4 */ "statement ::= IF LPAREN expression RPAREN LCURLY statementgroup RCURLY KEYWORD_ELSE LCURLY statementgroup RCURLY",
 /*   5 */ "statement ::= definition EQUAL expression",
 /*   6 */ "statement ::= definition",
 /*   7 */ "statement ::= expression",
 /*   8 */ "statement ::= KEYWORD_PRINT expression",
 /*   9 */ "definition ::= datatype IDENTIFIER",
 /*  10 */ "datatype ::= KEYWORD_INTEGER",
 /*  11 */ "datatype ::= KEYWORD_FLOAT",
 /*  12 */ "expression ::= term PLUS expression",
 /*  13 */ "expression ::= term MINUS expression",
 /*  14 */ "expression ::= term",
 /*  15 */ "term ::= term MUL term",
 /*  16 */ "term ::= term DIV term",
 /*  17 */ "term ::= term MOD term",
 /*  18 */ "term ::= term EXP term",
 /*  19 */ "term ::= signedFactor",
 /*  20 */ "signedFactor ::= PLUS factor",
 /*  21 */ "signedFactor ::= MINUS factor",
 /*  22 */ "signedFactor ::= factor",
 /*  23 */ "factor ::= LPAREN expression RPAREN",
 /*  24 */ "factor ::= SYMBOL",
 /*  25 */ "factor ::= INTEGER",
 /*  26 */ "factor ::= FLOAT",
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
#line 35 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"

	printf("\tstack overflowed\n");
#line 619 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
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
  { 31, 1 },
  { 23, 3 },
  { 23, 2 },
  { 24, 7 },
  { 24, 11 },
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
#line 41 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	tmpHack = malloc(sizeof(struct Program));
	tmpHack->context = yymsp[0].minor.yy57;
}
#line 763 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 1: /* statementgroup ::= statementgroup statement SEMICOLON */
#line 46 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	/*yymsp[-2].minor.yy57 will be a Context*/
	/*yymsp[-1].minor.yy10 will be a GenericStatement*/
	struct GenericStatement *gStmnt;

	/*add statement to the end of the statement group*/
	List_Add_Value(yymsp[-2].minor.yy57->statements, yymsp[-1].minor.yy10,struct GenericStatement *);
	if(yymsp[-1].minor.yy10->hasDef){
		List_Add_Value(yymsp[-2].minor.yy57->symbols, yymsp[-1].minor.yy10->sym, struct Symbol *);
	}
	yygotominor.yy57 = yymsp[-2].minor.yy57;
}
#line 779 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 2: /* statementgroup ::= statement SEMICOLON */
#line 59 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy57 = new_context(yymsp[-1].minor.yy10);
}
#line 786 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 3: /* statement ::= IF LPAREN expression RPAREN LCURLY statementgroup RCURLY */
#line 63 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = IFSTATEMENT;
	stmt->ifstmt = malloc(sizeof(struct IfStatement));
	stmt->ifstmt->testStatement = yymsp[-4].minor.yy12;
	stmt->ifstmt->yes = yymsp[-1].minor.yy57;
	stmt->ifstmt->no = NULL;
	yygotominor.yy10 = stmt;
}
#line 800 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 4: /* statement ::= IF LPAREN expression RPAREN LCURLY statementgroup RCURLY KEYWORD_ELSE LCURLY statementgroup RCURLY */
#line 74 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = IFSTATEMENT;
	stmt->ifstmt = malloc(sizeof(struct IfStatement));
	stmt->ifstmt->testStatement = yymsp[-8].minor.yy12;
	stmt->ifstmt->yes = yymsp[-5].minor.yy57;
	stmt->ifstmt->no = yymsp[-1].minor.yy57;
	yygotominor.yy10 = stmt;
}
#line 814 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 5: /* statement ::= definition EQUAL expression */
#line 85 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *dst, *exp;
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 1;
	stmt->sym = yymsp[-2].minor.yy38;

	dst = new_expression(SOURCE);
	dst->dataSource.sym = yymsp[-2].minor.yy38;
	dst->source_type = SYMBOL;
	
	exp = new_expression(ASSIGNMENT);
	exp->left = dst;
	exp->right = yymsp[0].minor.yy12;

	stmt->exp = exp;
	
	yygotominor.yy10 = stmt;
}
#line 838 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 6: /* statement ::= definition */
#line 106 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 1;
	stmt->sym = yymsp[0].minor.yy38;
	stmt->exp = NULL;

	yygotominor.yy10 = stmt;
}
#line 852 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 7: /* statement ::= expression */
#line 117 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 0;
	stmt->sym = NULL;

	stmt->exp = yymsp[0].minor.yy12;
	
	yygotominor.yy10 = stmt;
}
#line 867 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 8: /* statement ::= KEYWORD_PRINT expression */
#line 130 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct GenericStatement *stmt;
	struct Expression *print = new_expression(PRINT);
	print->left = NULL;
	print->right = yymsp[0].minor.yy12;

	stmt = malloc(sizeof(struct GenericStatement));
	stmt->type = GENERALSTATEMENT;
	stmt->hasDef = 0;
	stmt->sym = NULL;

	stmt->exp = print;
	
	yygotominor.yy10 = stmt;
}
#line 886 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 9: /* definition ::= datatype IDENTIFIER */
#line 146 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yymsp[-1].minor.yy38->name = yymsp[0].minor.yy0->literal;
	yygotominor.yy38 = yymsp[-1].minor.yy38;
}
#line 894 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 10: /* datatype ::= KEYWORD_INTEGER */
#line 151 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy38 = new_symbol(NULL, tINTEGER);
}
#line 901 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 11: /* datatype ::= KEYWORD_FLOAT */
#line 155 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy38 = new_symbol(NULL, tFLOAT);
}
#line 908 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 12: /* expression ::= term PLUS expression */
#line 159 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(ADD);
	tmp->left = yymsp[-2].minor.yy12;
	tmp->right = yymsp[0].minor.yy12;

	yygotominor.yy12 = tmp;
}
#line 920 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 13: /* expression ::= term MINUS expression */
#line 168 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(SUBTRACT);
	tmp->left = yymsp[-2].minor.yy12;
	tmp->right = yymsp[0].minor.yy12;

	yygotominor.yy12 = tmp;
}
#line 932 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 14: /* expression ::= term */
      case 19: /* term ::= signedFactor */ yytestcase(yyruleno==19);
      case 22: /* signedFactor ::= factor */ yytestcase(yyruleno==22);
#line 177 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy12 = yymsp[0].minor.yy12;
}
#line 941 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 15: /* term ::= term MUL term */
#line 184 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(MULTIPLY);
	tmp->left = yymsp[-2].minor.yy12;
	tmp->right = yymsp[0].minor.yy12;

	yygotominor.yy12 = tmp;
}
#line 953 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 16: /* term ::= term DIV term */
#line 193 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(DIVIDE);
	tmp->left = yymsp[-2].minor.yy12;
	tmp->right = yymsp[0].minor.yy12;

	yygotominor.yy12 = tmp;
}
#line 965 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 17: /* term ::= term MOD term */
#line 202 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(MODULUS);
	tmp->left = yymsp[-2].minor.yy12;
	tmp->right = yymsp[0].minor.yy12;

	yygotominor.yy12 = tmp;
}
#line 977 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 18: /* term ::= term EXP term */
#line 211 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(POWER);
	tmp->left = yymsp[-2].minor.yy12;
	tmp->right = yymsp[0].minor.yy12;

	yygotominor.yy12 = tmp;
}
#line 989 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 20: /* signedFactor ::= PLUS factor */
#line 225 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	/*possibly make this imply absolute value*/
	yygotominor.yy12 = yymsp[0].minor.yy12;
}
#line 997 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 21: /* signedFactor ::= MINUS factor */
#line 229 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp = new_expression(MULTIPLY);
	struct Expression *LHS = new_expression(SOURCE);
	
	LHS->source_type = INTEGER;
	LHS->dataSource.Integer = -1;
	
	tmp->left = LHS;
	tmp->right = yymsp[0].minor.yy12;
	
	yygotominor.yy12 = tmp;
}
#line 1013 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 23: /* factor ::= LPAREN expression RPAREN */
#line 246 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	yygotominor.yy12 = yymsp[-1].minor.yy12;
}
#line 1020 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 25: /* factor ::= INTEGER */
#line 251 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = INTEGER;
	tmp->dataSource.Integer = yymsp[0].minor.yy0->intData;
	yygotominor.yy12 = tmp;
}
#line 1031 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      case 26: /* factor ::= FLOAT */
#line 259 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
{
	struct Expression *tmp;
	tmp = new_expression(SOURCE);
	tmp->source_type = FLOAT;
	tmp->dataSource.Float = yymsp[0].minor.yy0->floatData;
	yygotominor.yy12 = tmp;
}
#line 1042 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
        break;
      default:
      /* (24) factor ::= SYMBOL */ yytestcase(yyruleno==24);
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
#line 32 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"

	printf("\tparse failed\n");
#line 1094 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
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
#line 39 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"
 printf("\t\x1b[1m\x1b[91mSYNTAX ERROR!!!!\x1b[0m\n");  exit(-1);
#line 1111 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
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
#line 29 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.y"

	printf("\tparse accepted\n");
#line 1133 "/Users/Joey/Desktop/cs-498-capstone/Compiler/Lexer_Parser/LangParse.c"
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
