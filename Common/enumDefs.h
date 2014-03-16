
#ifndef ___ENUMS_H___
#define ___ENUMS_H___

enum datasource {
	NA = -1,
	INTEGER,
	FLOAT,
	STRING,
	SYMBOL
};

enum expression_type {
	PASS,
	SOURCE,
	ASSIGNMENT,
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	MODULUS,
	POWER
};
enum data_type {
	tVOID = 0,
	tINTEGER,
	tFLOAT,
	tFUNCTION
};

#endif