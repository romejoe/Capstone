
#ifndef ___BYTECODEDEF_H___
#define ___BYTECODEDEF_H___


/*
        ihello
    ops needed
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


struct paramOption {
	int location: 4; /* 2^4 = 16 possible locations */

	int size: 3; /*size in bytes of the following address*/
	int padding: 1;

};

struct instruction {
	enum instruction_type opType:8; /*allows for 2^8 (256) commands*/
};


struct instruction new_instruction(enum instruction_type);
int getParamCountForInstruction(struct instruction instruct);

#endif