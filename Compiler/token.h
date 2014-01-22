#include <stdlib.h>
#include <string.h>

#ifndef __TOKEN_H__
#define __TOKEN_H__


enum union_type{
	NA = -1,
	INTEGER,
	FLOAT,
	STRING

};

typedef struct {
	//int line_num;
	enum union_type type;
	union{
		void * __exp;
		long intData;
		double floatData;
		char *stringData;
	};
} Token;

Token *getToken(char *, enum union_type);



#endif /* __TOKEN_H__ */

