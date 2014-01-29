#include "token.h"

Token *getToken(char *tokStr, enum datasource type){
	Token *ret;
	int stringLength;

	ret = (Token *) malloc(sizeof(Token));
	ret->type = type;
	switch(type){
		case INTEGER:
			ret->intData = atol(tokStr);
			break;
		case DOUBLE:
			ret->floatData = atof(tokStr);
			break;
		case SYMBOL:
			stringLength = strlen(tokStr);
			ret->stringData = (char *) malloc(stringLength - 1);
			memcpy(ret->stringData, tokStr + 1, stringLength - 2);
			ret->stringData[stringLength - 2] = 0x00;
			break;
		default:
			break;
	}
	return ret;
}