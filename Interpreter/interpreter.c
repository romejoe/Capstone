#include "interpreter.h"

#define GetTypeFromTarget(target, type)     *((type *) target)
#define GetTypeAndAdvance(target, type)     GetTypeFromTarget(target, type); target += sizeof(type)

#define GetInstruction(target)              GetTypeFromTarget(target, struct instruction)
#define GetInstructionAndAdvance(target)    GetTypeAndAdvance(target, struct instruction)

#define GetParameter(target)                GetTypeFromTarget(target, struct paramOption)
#define GetParameterAndAdvance(target)      GetTypeAndAdvance(target, struct paramOption)

#define GetParamData(target, source, size)          memcpy(target, source, (size))
#define GetParamDataAndAdvance(target, source, size)    GetParamData(target,source,(size)); source += (size)

#define GetTarget(location, ptr) ((location == 0)? (void *)&registers[location - 1] : (void *)ptr)

#define PopComputationalStackItem() AStack_Top(computationalStack, holder, struct computationalStackItem); AStack_Pop(computationalStack)
#define GetItemValue(item)	((item.type == INTEGER)? item.value.l:(item.type == FLOAT)? item.value.dbl: 0)

#define ADD(a,b) a + b
#define SUB(a,b) a - b
#define MUL(a,b) a * b
#define DIV(a,b) a / b
#define MOD(a,b) (long)(a) % (long)(b)
#define POW(a,b) pow((double) a, (double) b)

#define BasicArithmeticOperation(op) {\
	assert(computationalStack.top >= 1);\
	struct computationalStackItem i1 = PopComputationalStackItem();\
	struct computationalStackItem i2 = PopComputationalStackItem();\
	if(i1.type == FLOAT || i2.type == FLOAT){\
		resultItem.value.dbl = op(GetItemValue(i2), GetItemValue(i1));\
		resultItem.type = FLOAT;\
	}\
	else{\
		resultItem.value.l = op(GetItemValue(i2), GetItemValue(i1));\
		resultItem.type = INTEGER;\
	}\
	AStack_Push(computationalStack, resultItem, struct computationalStackItem);\
	break;\
}

union data {
	double dbl;
	long l;
	char byte;
	char *ptr;
	char rawData[8];
};

struct computationalStackItem{
	union data value;
	enum datasource type;
};
struct computationalStackItem holder;

void printResultItem(struct computationalStackItem item){
	switch(item.type){

		case INTEGER:
			printf("Integer Value = %ld\n", item.value.l);
			break;
		case FLOAT:
			printf("Float Value = %lf\n", item.value.dbl);
			break;
		default:
			printf("item type is unknown\n");
			break;

	}
}


void interpreteByteCode(char *buf, int length)
{
	char *progBuf = buf;
	char *stop = progBuf + length;
	struct instruction instruct;
	struct paramOption options[3];
	union data params[3];
	union data registers [__REGISTER_COUNT];
	struct astack computationalStack;
	struct computationalStackItem stackItems[3];
	struct computationalStackItem item;
	struct computationalStackItem resultItem;
	int i;
	int paramCount;

	initAStack(computationalStack, struct computationalStackItem);

	while (progBuf < stop) {
		/*get instruction info*/
		instruct = GetInstructionAndAdvance(progBuf);
		
		switch(instruct.opType){
			case iRELJMP:
				progBuf += params[0].l;
				break;
			/*case iMOV:
				memcpy(GetTarget(options[1].location, params[1].ptr), GetTarget(options[0].location, params[0].ptr), options[0].size);
				break;*/
			case iADD:
				BasicArithmeticOperation(ADD);
				break;
			case iSUB:
				BasicArithmeticOperation(SUB);
				break;
			case iMUL:
				BasicArithmeticOperation(MUL);
				break;
			case iDIV:
				BasicArithmeticOperation(DIV);
				break;
			case iMOD:
				BasicArithmeticOperation(MOD);
				break;
			case iPOW:
				BasicArithmeticOperation(POW);
				break;
			case iPRINT:
				item = PopComputationalStackItem();
				switch(item.type){
					case INTEGER:
						printf("type: Integer, value: %ld\n", item.value.l);
						break;
					case FLOAT:
						printf("type: Float, value: %lf\n", item.value.dbl);
						break;
					default:
						printf("Not how to tell you this but...\n");
						break;
				}
				break;
			case iIPUSH:
				resultItem.type = INTEGER;
				resultItem.value.l = GetTypeAndAdvance(progBuf, long);
				AStack_Push(computationalStack, resultItem, struct computationalStackItem);
				break;
			case iFPUSH:
				resultItem.type = FLOAT;
				resultItem.value.dbl = GetTypeAndAdvance(progBuf, double);
				AStack_Push(computationalStack, resultItem, struct computationalStackItem);
				break;
			case iHELLO:
				printf("Hello First Instruct\n");
				break;
			default:
				printf("OP NOT SUPPORTED!\n");
				break;
		}

	}
}