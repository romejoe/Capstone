#include <stdlib.h>

#ifndef ___ASTACK_H___
#define ___ASTACK_H___

#define DEFAULT_SIZE 20

struct stack{
	int size;
	void *stacky;
};

#define initAStack(target, type)\
	target.size = DEFAULT_SIZE;\
	target.top = -1;\
	target.stacky = ((type)*) malloc(DEFAULT_SIZE * sizeof(type))

#define AStack_Resize(target, type, newSize)\
	target.stacky = realloc(target.stacky, newSize * sizeof(type));\
	target.size = newSize;

#define AStack_Push(target, value, type)\
	if(target.top == target.size) {\
		AStack_Resize(target, type, target.size * 2);\
	}\
	++target.top;\
	(((type) *)target.stacky)[target.top] = value

#define AStack_Top(target, default, type)\
	(target.top > -1)? target.stacky[target.top]: (default)

#define AStack_Pop(target)\
	if(target.top > -1) --target.top

#endif
