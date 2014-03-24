
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
	POWER,
	PRINT,
	CHECK_EQ,
	CHECK_NE,
	CHECK_GT,
	CHECK_LT,
	CHECK_GTE,
	CHECK_LTE
};
enum data_type {
	tVOID = 0,
	tINTEGER,
	tFLOAT,
	tFUNCTION
};

enum statementType{
	GENERALSTATEMENT,
	IFSTATEMENT
};

#endif