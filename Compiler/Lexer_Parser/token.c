#include "token.h"

Token *_emptyToken = NULL;

Token *getToken(char *tokStr, enum datasource type)
{
	Token *ret;
	int stringLength;

	ret = (Token *) malloc(sizeof(Token));
	ret->type = type;
	switch (type) {
		case INTEGER:
			ret->intData = atol(tokStr);
			break;
		case FLOAT:
			ret->floatData = atof(tokStr);
			break;
		case STRING:
			stringLength = strlen(tokStr);
			ret->stringData = (char *) malloc(stringLength - 1);
			memcpy(ret->stringData, tokStr + 1, stringLength - 2);
			ret->stringData[stringLength - 2] = 0x00;
			break;
		case SYMBOL:
			stringLength = strlen(tokStr);
			ret->literal = (char *) malloc(stringLength);
			memcpy(ret->literal, tokStr, stringLength);
			break;
		default:
			break;
	}
	return ret;
}

Token *getEmptyToken(){
	if(!_emptyToken){
		_emptyToken = (Token *) malloc(sizeof(Token));
		_emptyToken->type = NA;
		_emptyToken->intData = 0;
	}

	return _emptyToken;
}