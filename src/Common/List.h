#include <stdlib.h>

#ifndef ___LIST_H___
#define ___LIST_H___

#define DEFAULT_SIZE 20

struct List {
	void *listy;
	int ListSize;
	int _rawSize;
	int _typeSize;
};

#define newListSize(target, type, size){\
	(target)->_rawSize = size;\
	(target)->ListSize = 0;\
	(target)->_typeSize = sizeof(type);\
	(target)->listy = malloc(sizeof(type) * size);\
}

#define newList(target, type) newListSize(target, type, DEFAULT_SIZE)

#define List_Resize(target, newSize){\
	target->listy = realloc((target)->listy, (newSize) * (target->_typeSize));\
	target->_rawSize = newSize;\
}

#define List_Add(target, obj){\
	if((target)->ListSize + 1 > (target)->_rawSize) List_Resize(target, (target)->_rawSize << 1);\
	memcpy(List_Ref(target, (target->ListSize)), &(obj), (target)->_typeSize);\
	(target)->ListSize += 1;\
}

#define List_Add_Value(target, obj, type){\
	if((target)->ListSize + 1 > (target)->_rawSize) List_Resize(target, (target)->_rawSize << 1);\
	*((type *)(List_Ref(target, (target->ListSize)))) = obj;\
	(target)->ListSize += 1;\
}

#define List_ForEach(target, code){\
	int i;\
	for(i = 0; i < (target)->ListSize; ++i){\
		code\
	}\
}

#define List_Ref(target, index) ((target)->listy + (target)->_typeSize * index)
#define List_Ref_Value(target, index, type) (*(type *)((target)->listy + (target)->_typeSize * index))
#endif
