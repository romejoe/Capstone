#include <stdlib.h>
#include <string>
#include "enumDefs.h"
#ifndef __TOKEN_H__
#define __TOKEN_H__
using namespace std;

struct Token{
	/*int line_num;*/
	enum datasource type;
	union {
		long intData;
		double floatData;
		string stringData;
		string literal;
	};

	Token(string, enum datasource);
	static Token *getEmptyToken();
};


#endif /* __TOKEN_HPP__ */

