#include "common.h"

char* getInstructionName(enum instruction_type type)
{
	switch (type) {
		case iHELLO:
			return "iHELLO";
		case iJMP:
			return "iJMP";
		case iJMPT:
			return "iJMPT";
		case iJMPF:
			return "iJMPF";
		case iEQ:
			return "iEQ";
		case iNEQ:
			return "iNEQ";
		case iLT:
			return "iLT";
		case iLTE:
			return "iLTE";
		case iGT:
			return "iGT";
		case iGTE:
			return "iGTE";
		case iMOV:
			return "iMOV";
		case iADD:
			return "iADD";
		case iSUB:
			return "iSUB";
		case iMUL:
			return "iMUL";
		case iDIV:
			return "iDIV";
		case iMOD:
			return "iMOD";
		case iPOW:
			return "iPOW";
		case iIPUSH:
			return "iIPUSH";
		case iFPUSH:
			return "iFPUSH";
		case iLVPUSH:
			return "iLVPUSH";
		case iGVPUSH:
			return "iGVPUSH";
		case iASSIGN:
			return "iASSIGN";
		case iVALLOC:
			return "iVALLOC";
		case iVDALLOC:
			return "iVDALLOC";
		case iPRINT:
			return "iPRINT";
		case iVSETTYPE:
			return "iVSETTYPE";
		case iDUMPVARS:
			return "iDUMPVARS";
		default:
			return "???";
	}

}