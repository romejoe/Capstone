#include "token.hpp"

Token *_emptyToken = NULL;

Token::Token(char *tokStr, enum datasource type)
{
	int stringLength;

	this->type = type;
	switch (type) {
		case INTEGER:
			this->intData = atol(tokStr);
			break;
		case FLOAT:
			this->floatData = atof(tokStr);
			break;
		case STRING:
			stringLength = strlen(tokStr);
			this->stringData = (char *) malloc(stringLength - 1);
			memcpy(this->stringData, tokStr + 1, stringLength - 2);
			this->stringData[stringLength - 2] = 0x00;
			break;
		case SYMBOL:
			stringLength = strlen(tokStr);
			this->literal = (char *) malloc(stringLength);
			memcpy(this->literal, tokStr, stringLength);
			break;
		default:
			break;
	}

}

Token* Token::getEmptyToken(){
	if(!_emptyToken){
		_emptyToken = new Token(NULL, NA);
		_emptyToken->intData = 0;
	}

	return _emptyToken;
}