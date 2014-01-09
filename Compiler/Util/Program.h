
enum expression_type{
	PASS
};

enum data_type{
	VOID = 0,
	//integer types, from smallest to largest
	BOOL = 	1,
	CHAR = 	8,
	SHORT = 16,
	INT = 	32,
	LONG = 	64,

	//float types, from smallest to largest
	FLOAT =  33,
	DOUBLE = 65
}

struct expression{
	enum expression_type type;
	enum data_type result_type;
	struct expression *left, *right;
}

struct Program{
	struct expression* root;

};

struct expression * new_expression(enum expression_type);