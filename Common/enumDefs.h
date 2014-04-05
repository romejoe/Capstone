
#ifndef ___ENUMS_H___
#define ___ENUMS_H___

enum datasource {
	__VARIABLE = -2, /* only used in interpreter */
	NA = -1,
	INTEGER,
	FLOAT,
	STRING,
	SYMBOL,
	POINTER
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