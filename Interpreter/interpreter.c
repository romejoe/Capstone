#include "interpreter.h"

#define GetTypeFromTarget(target, type)     *((type *) target)
#define GetTypeAndAdvance(target, type)     GetTypeFromTarget(target, type); target += sizeof(type)

#define GetInstruction(target)              GetTypeFromTarget(target, struct instruction)
#define GetInstructionAndAdvance(target)    GetTypeAndAdvance(target, struct instruction)

#define GetParamData(target, source, size)          memcpy(target, source, (size))
#define GetParamDataAndAdvance(target, source, size)    GetParamData(target,source,(size)); source += (size)

#define GetTarget(location, ptr) ((location == 0)? (void *)&registers[location - 1] : (void *)ptr)

#define PopComputationalStackItem() AStack_Top(computationalStack, holder, struct computationalStackItem); AStack_Pop(computationalStack)
#define GetItemValue(item)  ((item.type == INTEGER)? item.value.l:(item.type == FLOAT)? item.value.dbl: 0)

#define ADD(a,b) a + b
#define SUB(a,b) a - b
#define MUL(a,b) a * b
#define DIV(a,b) a / b
#define MOD(a,b) (long)(a) % (long)(b)
#define POW(a,b) pow((double) a, (double) b)

#define CHECK_LESS_THAN(a,b) a < b
#define CHECK_LESS_THAN_EQUAL(a,b) a <= b
#define CHECK_GREATER_THAN(a,b) a > b
#define CHECK_GREATER_THAN_EQUAL(a,b) a >= b

#define LOGICAL_AND(a,b) {\
		resultItem.value.l = (a.value.l != 0) && (b.value.l != 0);\
		resultItem.type = INTEGER;\
	}

#define LOGICAL_OR(a,b) {\
		resultItem.value.l = (a.value.l != 0) || (b.value.l != 0);\
		resultItem.type = INTEGER;\
	}

#define LOGICAL_XOR(a,b) {\
		resultItem.value.l = (a.value.l != 0) ^ (b.value.l != 0);\
		resultItem.type = INTEGER;\
	}



#define BasicOperation(op) {\
		assert(computationalStack.top >= 1);\
		struct computationalStackItem i1 = PopComputationalStackItem();\
		struct computationalStackItem i2 = PopComputationalStackItem();\
		op(i2, i1);\
		AStack_Push(computationalStack, resultItem, struct computationalStackItem);\
		break;\
	}

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

struct computationalStackItem {
	union data value;
	long varIndex;
	enum datasource type;
};
struct computationalStackItem holder;

void printResultItem(struct computationalStackItem item)
{
	switch (item.type) {

		case INTEGER:
			/*printf("Integer Value = %ld\n", item.value.l);*/
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
	union data params[3];
	struct astack computationalStack;
	struct computationalStackItem stackItems[3];
	struct computationalStackItem item;
	struct computationalStackItem resultItem;

	struct List *variables;
	long variableIndex = 0;
	int i;
	int paramCount;
	long offset;
	long count;
	enum datasource type;

	initAStack(computationalStack, struct computationalStackItem);

	variables = (struct List *) malloc(sizeof(struct List));
	newList(variables, struct computationalStackItem);

	while (progBuf < stop) {
		/*get instruction info*/
		instruct = GetInstructionAndAdvance(progBuf);
		/*printf("OP = %s\n", getName(instruct.opType));*/
		switch (instruct.opType) {
			case iJMP:
				offset = GetTypeAndAdvance(progBuf, long);
				progBuf += offset;
				break;
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
			case iEQ: {
					assert(computationalStack.top >= 1);
					struct computationalStackItem i1 = PopComputationalStackItem();
					struct computationalStackItem i2 = PopComputationalStackItem();
					resultItem.value.l = memcmp(&i1, &i2, sizeof(union data)) == 0;
					resultItem.type = INTEGER;
					AStack_Push(computationalStack, resultItem, struct computationalStackItem);
				}
				break;
			case iNEQ: {
					assert(computationalStack.top >= 1);
					struct computationalStackItem i1 = PopComputationalStackItem();
					struct computationalStackItem i2 = PopComputationalStackItem();
					resultItem.value.l = memcmp(&i1, &i2, sizeof(union data)) != 0;
					resultItem.type = INTEGER;
					AStack_Push(computationalStack, resultItem, struct computationalStackItem);
				}
				break;
			case iLT:
				BasicArithmeticOperation(CHECK_LESS_THAN);
				break;
			case iLTE:
				BasicArithmeticOperation(CHECK_LESS_THAN_EQUAL);
				break;
			case iGT:
				BasicArithmeticOperation(CHECK_GREATER_THAN);
				break;
			case iGTE:
				BasicArithmeticOperation(CHECK_GREATER_THAN_EQUAL);
				break;

			case iLOGNOT: {
					assert(computationalStack.top >= 0);
					struct computationalStackItem i1 = PopComputationalStackItem();
					resultItem.value.l = !(i1.value.l != 0);
					resultItem.type = INTEGER;
					AStack_Push(computationalStack, resultItem, struct computationalStackItem);
				}
				break;
			case iLOGAND:
				BasicOperation(LOGICAL_AND);
				break;
			case iLOGOR:
				BasicOperation(LOGICAL_OR);
				break;
			case iLOGXOR:
				BasicOperation(LOGICAL_XOR);
				break;

			case iPRINT:
				item = PopComputationalStackItem();
				switch (item.type) {
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
			case iJMPF:
				item = PopComputationalStackItem();
				offset = GetTypeAndAdvance(progBuf, long);
				if (!item.value.l) {
					progBuf += offset;
				}
				break;
			case iJMPT:
				item = PopComputationalStackItem();
				offset = GetTypeAndAdvance(progBuf, long);
				if (item.value.l) {
					progBuf += offset;
				}
				break;

			case iVALLOC:
				count = GetTypeAndAdvance(progBuf, long);
				List_Resize(variables, variables->ListSize + count);
				variables->ListSize += count;
				break;

			case iVDALLOC:
				count = GetTypeAndAdvance(progBuf, long);
				/*printf("Count = %ld\n", count);
				printf("Num Variables = %d\n", variables->ListSize);*/
				assert(count <= variables->ListSize);
				variables->ListSize -= count;
				break;

			case iLVPUSH:
				offset = GetTypeAndAdvance(progBuf, long) + variableIndex;
				resultItem = List_Ref_Value(variables, offset, struct computationalStackItem);
				resultItem.varIndex = offset;
				AStack_Push(computationalStack, resultItem, struct computationalStackItem);
				break;
			case iGVPUSH:
				offset = GetTypeAndAdvance(progBuf, long);
				resultItem = List_Ref_Value(variables, offset, struct computationalStackItem);
				resultItem.varIndex = offset;
				AStack_Push(computationalStack, resultItem, struct computationalStackItem);
				break;
			case iASSIGN:
				resultItem = PopComputationalStackItem();
				item = PopComputationalStackItem();
				assert(item.varIndex >= 0);
				offset = item.varIndex;
				/*printf("Offset = %ld\n", offset);
				/*item = List_Ref_Value(variables,offset, struct computationalStackItem);
				printf("result = ");
				printResultItem(resultItem);
				printf("item = ");
				printResultItem(item);*/
				switch (item.type) {
					case INTEGER:
						List_Ref_Value(variables, offset, struct computationalStackItem).value.l = GetItemValue(resultItem);
						break;
					case FLOAT:
						List_Ref_Value(variables, offset,
						               struct computationalStackItem).value.dbl = GetItemValue(resultItem);
						break;
				}
				/*printResultItem(item);*/
				/*printf("Index = %ld\n", item.varIndex);
				printf("Result = %ld\n", resultItem.value.l);*/
				/*memcpy(
				    List_Ref(variables, offset),
				    &item,
				    sizeof(struct computationalStackItem));*/
				break;

			case iVSETTYPE:
				offset = GetTypeAndAdvance(progBuf, long) + variableIndex;
				/*printf("offset: %ld\n", offset);*/

				((struct computationalStackItem *)List_Ref(variables, offset))->type = GetTypeAndAdvance(progBuf,
				        enum datasource);
				/*List_Ref_Value(variables, offset,
				               struct computationalStackItem).type = GetTypeAndAdvance(progBuf, enum data_type);*/
				break;
			case iDUMPVARS:
				printf("======Begin Variable Dump\n");
				List_ForEach(variables, {
					printf("[%d] ", i);
					printResultItem(List_Ref_Value(variables, i, struct computationalStackItem));
				});
				printf("======End Variable Dump\n");
				break;
			default:
				printf("OP (%s) NOT SUPPORTED!\n", getName(instruct.opType));
				break;
		}
		/*
		printf("======Begin Variable Dump\n");
		List_ForEach(variables, {
		    printf("[%d] ", i);
		    printResultItem(List_Ref_Value(variables, i, struct computationalStackItem));
		});
		printf("======End Variable Dump\n");

		printf("======Begin Stack Dump\n");
		int i;
		for(i = 0; i <= computationalStack.top; ++i){
		    printResultItem(*((struct computationalStackItem *)computationalStack.stacky + i));
		}
		printf("======End Stack Dump\n\n");
		getc(stdin);
		*/
	}
}