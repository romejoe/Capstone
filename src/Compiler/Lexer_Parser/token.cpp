#include "token.hpp"

Token *_emptyToken = NULL;

Token::Token(string tokStr, enum datasource type)
{
	int stringLength;

	this->type = type;
	switch (type) {
		case INTEGER:
			this->intData = stol(tokStr);
			break;
		case FLOAT:
			this->floatData = stof(tokStr);
			break;
		case STRING:
			this->stringData = tokStr.substr(1,tokStr.size() -2);
			break;
		case SYMBOL:
			this->literal = tokStr;
			break;
		default:
            this->literal = "";
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