
#ifndef ___BYTECODEDEF_H___
#define ___BYTECODEDEF_H___


/*
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
	int location: 4;

	int size: 3; /*size in bytes of the following address*/
	int padding: 1;

};

struct instruction {
	int opType: 6; /*allows for 2^6 (64) commands*/
	int paramCount: 2; /*allows for [0,1,2,3] parameters*/
};


struct instruction new_instruction(enum instruction_type);

#endif