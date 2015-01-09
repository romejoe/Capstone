#include <stdlib.h>
#include <string.h>
#include "enumDefs.h"
#ifndef __TOKEN_H__
#define __TOKEN_H__

struct Token{
	/*int line_num;*/
	enum datasource type;
	union {
		long intData;
		double floatData;
		char *stringData;
		char *literal;
	};

	Token(char *, enum datasource);
	static Token *getEmptyToken();
};


#endif /* __TOKEN_HPP__ */

