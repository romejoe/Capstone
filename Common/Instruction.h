
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
	iJMP,
	iJMPT,
	iJMPF,
	iEQ,
	iNEQ,
	iLT,
	iLTE,
	iGT,
	iGTE,
	iMOV,
	iADD,
	iSUB,
	iMUL,
	iDIV,
	iMOD,
	iPOW,
	iIPUSH,
	iFPUSH,
	iVPUSH,
	iVPOP,
	iVALLOC,
	iVDALLOC,
	iPRINT
};

struct instruction {
	char opType; /*allows for 2^8 (256) commands*/
};


struct instruction new_instruction(enum instruction_type);

#endif