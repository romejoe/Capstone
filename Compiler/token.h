#include <stdlib.h>
#include <string.h>
#include "enumDefs.h"
#ifndef __TOKEN_H__
#define __TOKEN_H__

typedef struct {
	//int line_num;
	enum datasource type;
	union{
		void * __exp;
		long intData;
		double floatData;
		char *stringData;
	};
} Token;

Token *getToken(char *, enum datasource);



#endif /* __TOKEN_H__ */

