#ifndef __TOKEN_H__
#define __TOKEN_H__

enum union_type{
	NA = -1,
	integer,
	string

};

typedef struct {
	int line_num;
	enum union_type type;
	union{
		void * __exp;

	};
} Token;


#endif /* __TOKEN_H__ */

