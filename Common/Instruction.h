
#ifndef ___BYTECODEDEF_H___
#define ___BYTECODEDEF_H___


/*
        ihello
    ops needed
    	rjmp {dst}
        mov {src}, {dst}
        add {src}, {dst}
        fadd {src}, {dst}
        sub {src}, {dst}
        fsub {src}, {dst}
        mul {src}, {dst}
        fmul {src}, {dst}
        div {src}, {dst}
        fdiv {src}, {dst}
        tof {src}, {dst}
        toi {src}, {dst}
        //exp how?
*/
enum instruction_type {
	iHELLO,
	iRELJMP,
	iMOV,
	iADD,
	iFADD,
	iSUB,
	iFSUB,
	iMUL,
	iFMUL,
	iDIV,
	iFDIV
};

#define __REGISTER_COUNT 15


struct paramOption {
	int location: 4; /* 2^4 = 16 possible locations */
	/* 0: memory location */
	int dereferenceLocation: 1;
	int size: 3; /*size in bytes of the following address*/

};

struct instruction {
	enum instruction_type opType:8; /*allows for 2^8 (256) commands*/
};

struct complete_instruction {
	struct instruction instruct;
	int optionCount;
	struct paramOption options[];
};

struct instruction new_instruction(enum instruction_type);
int getParamCountForInstruction(struct instruction instruct);

struct complete_instruction *new_complete_instruction(enum instruction_type);

#endif