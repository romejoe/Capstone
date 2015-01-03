
#ifndef ___BYTECODEDEF_H___
#define ___BYTECODEDEF_H___

enum instruction_type {
	iHELLO = -1,		/*-1*/
	iJMP,				/*0*/
	iJMPT,				/*1*/
	iJMPF,				/*2*/
	iEQ,				/*3*/
	iNEQ,				/*4*/
	iLT,				/*5*/
	iLTE,				/*6*/
	iGT,				/*7*/
	iGTE,				/*8*/
	iMOV,				/*9*/
	iADD,				/*A*/
	iSUB,				/*B*/
	iMUL,				/*C*/
	iDIV,				/*D*/
	iMOD,				/*E*/
	iPOW,				/*F*/
	iIPUSH,				/*10*/
	iFPUSH,				/*11*/
	/* variable instructions */
	iLVPUSH,			/*12*/
	iGVPUSH,			/*13*/
	iASSIGN,			/*14*/
	iVALLOC,			/*15*/
	iVDALLOC,			/*16*/
	iVSETTYPE,			/*17*/
	iDUMPVARS,			/*18*/
	iLOGNOT,
	iLOGAND,
	iLOGOR,
	iLOGXOR,
	iPRINT				/*19*/
};

struct instruction {
	char opType; /*allows for 2^8 (256) commands*/
};


struct instruction new_instruction(enum instruction_type);
char *getName(enum instruction_type);
#endif