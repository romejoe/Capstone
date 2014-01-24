
enum expression_type{
	PASS,
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	POWER
};

enum data_type{
	tVOID = 0,
	//integer types, from smallest to largest
	tBOOL = 	1,
	tCHAR = 	8,
	tSHORT = 16,
	tINT = 	32,
	tLONG = 	64,

	//float types, from smallest to largest
	tFLOAT =  33,
	tDOUBLE = 65
};

struct expression{
	enum expression_type type;
	enum data_type result_type;
	struct expression *left, *right;
};

struct Program{
	struct expression* root;

};

struct expression * new_expression(enum expression_type);