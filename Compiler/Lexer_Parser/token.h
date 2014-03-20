#include <stdlib.h>
#include <string.h>
#include "enumDefs.h"
#ifndef __TOKEN_H__
#define __TOKEN_H__

typedef struct {
	/*int line_num;*/
	enum datasource type;
	union {
		long intData;
		double floatData;
		char *stringData;
		char *literal;
	};
} Token;

Token *getToken(char *, enum datasource);
Token *getEmptyToken();


#endif /* __TOKEN_H__ */

