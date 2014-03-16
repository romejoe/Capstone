
#ifndef ___BYTECODEDEF_H___
#define ___BYTECODEDEF_H___


/*
        ihello
    ops needed
    	rjmp {dst}
        mov {src}, {dst}
        add
        sub
        mul
        div
        mod
        exp
        tof {src}, {dst}
        toi {src}, {dst}
        Ipush
        Fpush

        //exp how?
*/
enum instruction_type {
	iHELLO = -1,
	iRELJMP,
	iMOV,
	iADD,
	iSUB,
	iMUL,
	iDIV,
	iMOD,
	iEXP,
	iIPUSH,
	iFPUSH
};

#define __REGISTER_COUNT 14


struct paramOption {
	int location: 7; /* 2^4 = 16 possible locations */
	/* 0: raw data */
	/* 1: memory location */
	int dereferenceLocation: 1;
	unsigned char size:8; /*size in bytes of the following data*/

};
#define ParamOptionSize 2

struct instruction {
	char opType; /*allows for 2^8 (256) commands*/
};

struct complete_instruction {
	struct instruction instruct;
	char optionCount;
	struct paramOption *options;
};

struct instruction new_instruction(enum instruction_type);
int getParamCountForInstruction(struct instruction instruct);

struct complete_instruction *new_complete_instruction(enum instruction_type);

#endif