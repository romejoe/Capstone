
#ifndef ___BYTECODEDEF_H___
#define ___BYTECODEDEF_H___

struct paramOption{
	int location:4;

	int size:3;/*size in bytes of the following address*/
	int padding:1;
	
};

struct instruction { 
	int opType: 6; /*allows for 2^6 (64) commands*/
	int paramCount: 2; /*allows for [0,1,2,3] parameters*/
};


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
		//exp how?
*/

#endif