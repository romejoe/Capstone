
#ifndef ___ENUMS_H___
#define ___ENUMS_H___

enum datasource{
	NA = -1,
	INTEGER,
	DOUBLE,
	SYMBOL
};

enum expression_type{
	PASS,
	DATA,
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	MODULUS,
	POWER
};

enum data_type{
	tVOID = 0,
	/*integer types, from smallest to largest*/		
	tBOOL = 	1,
	tCHAR = 	8,
	tSHORT = 16,
	tINT = 	32,
	tLONG = 	64,
	/*float types, from smallest to largest*/
	tFLOAT =  33,
	tDOUBLE = 65
};
#endif