/*
GPR Bank

Reads from Rs, Rt, and Rm.
Writes to Rn.

Will go to a 64-bit interface and combine the GPRs and FPRs.
GPRs will remain as 16x 32b for 32-bit.
 */

`include "CoreDefs.v"

module RegGPR3(
	/* verilator lint_off UNUSED */
	clock,		reset,
	regIdRs,	regValRs,
	regIdRt,	regValRt,
	regIdRn,	regValRn,
	regIdRo,	regValRo,
	regSrVal,	regExHold,
	idImm,		idValPc,
	regLdMode,	regStMode,
	
	oregSr,		exNextSr2,
	oregPr,		exNextPr2,
	oregPc,		exNextPc2,
	oregMach,	exNextMach2,
	oregMacl,	exNextMacl2,
	oregSp,		exNextSp2,
	oregGbr,	exNextGbr2,
	oregVbr,	exNextVbr2,
	oregSSr,	exNextSSr2,
	oregSPc,	exNextSPc2,
	oregSGr,	exNextSGr2,
		
	oregFpul,	exNextFpul2,
	oregFpScr,	exNextFpScr2
	);

input clock;
input reset;

input[6:0]		regIdRs;
input[6:0]		regIdRt;
input[6:0]		regIdRn;

output[63:0]	regValRs;
output[63:0]	regValRt;
output[63:0]	regValRn;

input[6:0]		regIdRo;
input[63:0]		regValRo;

input[31:0]		regSrVal;

input			regExHold;

input[31:0]		idImm;
input[31:0]		idValPc;

input[1:0]		regLdMode;			//get mode
input[1:0]		regStMode;			//set mode

input[31:0]		exNextSr2;			//SR in
input[31:0]		exNextPr2;			//PR in
input[31:0]		exNextPc2;			//PC in
input[31:0]		exNextMach2;		//MACH
input[31:0]		exNextMacl2;		//MACL
input[31:0]		exNextGbr2;			//GBR
input[31:0]		exNextVbr2;			//VBR
input[31:0]		exNextSSr2;			//SSR
input[31:0]		exNextSPc2;			//SPC
input[31:0]		exNextSGr2;			//SGR (Saved R15)
input[31:0]		exNextFpul2;		//
input[31:0]		exNextFpScr2;		//
input[31:0]		exNextSp2;			//

output[31:0]	oregMach;			//MACH
output[31:0]	oregMacl;			//MACL
output[31:0]	oregPr;				//PR
output[31:0]	oregSGr;			//SGR (Saved R15)
output[31:0]	oregFpul;			//FPUL
output[31:0]	oregFpScr;			//FPSCR
output[31:0]	oregSr;				//SR
output[31:0]	oregGbr;			//GBR
output[31:0]	oregVbr;			//VBR
output[31:0]	oregSSr;			//SSR
output[31:0]	oregSPc;			//SPC
output[31:0]	oregPc;				//PC
output[31:0]	oregSp;				//SP/GR (R15)

reg[31:0]		regMach;			//MACH
reg[31:0]		regMacl;			//MACL
reg[31:0]		regPr;				//PR
reg[31:0]		regSGr;				//SGR (Saved R15)
reg[31:0]		regFpul;			//FPUL
reg[31:0]		regFpScr;			//FPSCR
reg[31:0]		regSr;				//SR
reg[31:0]		regGbr;				//GBR
reg[31:0]		regVbr;				//VBR
reg[31:0]		regSSr;				//SSR
reg[31:0]		regSPc;				//SPC
reg[31:0]		regPc;				//PC
reg[31:0]		regSp;				//SP/GR (R15)

assign		oregMach	= regMach;
assign		oregMacl	= regMacl;
assign		oregPr		= regPr;
assign		oregSGr		= regSGr;
assign		oregFpul	= regFpul;
assign		oregFpScr	= regFpScr;
assign		oregSr		= regSr;
assign		oregGbr		= regGbr;
assign		oregVbr		= regVbr;
assign		oregSSr		= regSSr;
assign		oregSPc		= regSPc;
assign		oregPc		= regPc;
assign		oregSp		= regSp;

reg			regSrRB;
reg			nxtRegSrRB;
reg			regFprRB;
reg			nxtRegFprRB;

reg[63:0]	tRegValRs;
reg[63:0]	tRegValRt;
reg[63:0]	tRegValRn;

reg 		fprIsLd64;
reg 		fprIsSt64;

reg[31:0]	regGprR0A;
reg[31:0]	regGprR1A;
reg[31:0]	regGprR2A;
reg[31:0]	regGprR3A;
reg[31:0]	regGprR4A;
reg[31:0]	regGprR5A;
reg[31:0]	regGprR6A;
reg[31:0]	regGprR7A;

reg[31:0]	regGprR0B;
reg[31:0]	regGprR1B;
reg[31:0]	regGprR2B;
reg[31:0]	regGprR3B;
reg[31:0]	regGprR4B;
reg[31:0]	regGprR5B;
reg[31:0]	regGprR6B;
reg[31:0]	regGprR7B;

reg[31:0]	regGprR8;
reg[31:0]	regGprR9;
reg[31:0]	regGprR10;
reg[31:0]	regGprR11;
reg[31:0]	regGprR12;
reg[31:0]	regGprR13;
reg[31:0]	regGprR14;


reg[31:0]		regFprFR00;
reg[31:0]		regFprFR01;
reg[31:0]		regFprFR02;
reg[31:0]		regFprFR03;
reg[31:0]		regFprFR04;
reg[31:0]		regFprFR05;
reg[31:0]		regFprFR06;
reg[31:0]		regFprFR07;
reg[31:0]		regFprFR08;
reg[31:0]		regFprFR09;
reg[31:0]		regFprFR10;
reg[31:0]		regFprFR11;
reg[31:0]		regFprFR12;
reg[31:0]		regFprFR13;
reg[31:0]		regFprFR14;
reg[31:0]		regFprFR15;

reg[31:0]		regFprXF00;
reg[31:0]		regFprXF01;
reg[31:0]		regFprXF02;
reg[31:0]		regFprXF03;
reg[31:0]		regFprXF04;
reg[31:0]		regFprXF05;
reg[31:0]		regFprXF06;
reg[31:0]		regFprXF07;
reg[31:0]		regFprXF08;
reg[31:0]		regFprXF09;
reg[31:0]		regFprXF10;
reg[31:0]		regFprXF11;
reg[31:0]		regFprXF12;
reg[31:0]		regFprXF13;
reg[31:0]		regFprXF14;
reg[31:0]		regFprXF15;

/*
reg[31:0]		nxtRegFprFR00;
reg[31:0]		nxtRegFprFR01;
reg[31:0]		nxtRegFprFR02;
reg[31:0]		nxtRegFprFR03;
reg[31:0]		nxtRegFprFR04;
reg[31:0]		nxtRegFprFR05;
reg[31:0]		nxtRegFprFR06;
reg[31:0]		nxtRegFprFR07;
reg[31:0]		nxtRegFprFR08;
reg[31:0]		nxtRegFprFR09;
reg[31:0]		nxtRegFprFR10;
reg[31:0]		nxtRegFprFR11;
reg[31:0]		nxtRegFprFR12;
reg[31:0]		nxtRegFprFR13;
reg[31:0]		nxtRegFprFR14;
reg[31:0]		nxtRegFprFR15;

reg[31:0]		nxtRegFprXF00;
reg[31:0]		nxtRegFprXF01;
reg[31:0]		nxtRegFprXF02;
reg[31:0]		nxtRegFprXF03;
reg[31:0]		nxtRegFprXF04;
reg[31:0]		nxtRegFprXF05;
reg[31:0]		nxtRegFprXF06;
reg[31:0]		nxtRegFprXF07;
reg[31:0]		nxtRegFprXF08;
reg[31:0]		nxtRegFprXF09;
reg[31:0]		nxtRegFprXF10;
reg[31:0]		nxtRegFprXF11;
reg[31:0]		nxtRegFprXF12;
reg[31:0]		nxtRegFprXF13;
reg[31:0]		nxtRegFprXF14;
reg[31:0]		nxtRegFprXF15;
*/

assign regValRs = tRegValRs;
assign regValRt = tRegValRt;
assign regValRn = tRegValRn;

always @*
begin
//	fprIsLd64 = 0;
//	fprIsSt64 = 0;

	fprIsLd64 = regLdMode[0];
	fprIsSt64 = regStMode[0];
	
	nxtRegSrRB=regSrVal[29];
	nxtRegFprRB=regFpScr[21];

	tRegValRs=UV64_XX;
	tRegValRt=UV64_XX;
	tRegValRn=UV64_XX;

	case(regIdRs)
		UREG_R0:	tRegValRs = { UV32_XX, regGprR0A };
		UREG_R1:	tRegValRs = { UV32_XX, regGprR1A };
		UREG_R2:	tRegValRs = { UV32_XX, regGprR2A };
		UREG_R3:	tRegValRs = { UV32_XX, regGprR3A };
		UREG_R4:	tRegValRs = { UV32_XX, regGprR4A };
		UREG_R5:	tRegValRs = { UV32_XX, regGprR5A };
		UREG_R6:	tRegValRs = { UV32_XX, regGprR6A };
		UREG_R7:	tRegValRs = { UV32_XX, regGprR7A };
		UREG_R8:	tRegValRs = { UV32_XX, regGprR8  };
		UREG_R9:	tRegValRs = { UV32_XX, regGprR9  };
		UREG_R10:	tRegValRs = { UV32_XX, regGprR10 };
		UREG_R11:	tRegValRs = { UV32_XX, regGprR11 };
		UREG_R12:	tRegValRs = { UV32_XX, regGprR12 };
		UREG_R13:	tRegValRs = { UV32_XX, regGprR13 };
		UREG_R14:	tRegValRs = { UV32_XX, regGprR14 };
		UREG_R15:	tRegValRs = { UV32_XX, regSp     };

		UREG_FR0:	tRegValRs = fprIsLd64 ?
			{regFprFR00, regFprFR01} : {UV32_XX, regFprFR00};
		UREG_FR1:	tRegValRs = fprIsLd64 ?
			{regFprXF00, regFprXF01} : {UV32_XX, regFprFR01};
		UREG_FR2:	tRegValRs = fprIsLd64 ?
			{regFprFR02, regFprFR03} : {UV32_XX, regFprFR02};
		UREG_FR3:	tRegValRs = fprIsLd64 ?
			{regFprXF02, regFprXF03} : {UV32_XX, regFprFR03};
		UREG_FR4:	tRegValRs = fprIsLd64 ?
			{regFprFR04, regFprFR05} : {UV32_XX, regFprFR04};
		UREG_FR5:	tRegValRs = fprIsLd64 ?
			{regFprXF04, regFprXF05} : {UV32_XX, regFprFR05};
		UREG_FR6:	tRegValRs = fprIsLd64 ?
			{regFprFR06, regFprFR07} : {UV32_XX, regFprFR06};
		UREG_FR7:	tRegValRs = fprIsLd64 ?
			{regFprXF06, regFprXF07} : {UV32_XX, regFprFR07};
		UREG_FR8:	tRegValRs = fprIsLd64 ?
			{regFprFR08, regFprFR09} : {UV32_XX, regFprFR08};
		UREG_FR9:	tRegValRs = fprIsLd64 ?
			{regFprXF08, regFprXF09} : {UV32_XX, regFprFR09};
		UREG_FR10:	tRegValRs = fprIsLd64 ?
			{regFprFR10, regFprFR11} : {UV32_XX, regFprFR10};
		UREG_FR11:	tRegValRs = fprIsLd64 ?
			{regFprXF10, regFprXF11} : {UV32_XX, regFprFR11};
		UREG_FR12:	tRegValRs = fprIsLd64 ?
			{regFprFR12, regFprFR13} : {UV32_XX, regFprFR12};
		UREG_FR13:	tRegValRs = fprIsLd64 ?
			{regFprXF12, regFprXF13} : {UV32_XX, regFprFR13};
		UREG_FR14:	tRegValRs = fprIsLd64 ?
			{regFprFR14, regFprFR15} : {UV32_XX, regFprFR14};
		UREG_FR15:	tRegValRs = fprIsLd64 ?
			{regFprXF14, regFprXF15} : {UV32_XX, regFprFR15};

		UREG_PCW:	tRegValRs = { UV32_XX, idValPc + {idImm[30:0], 1'b0} };
		UREG_PCL: 	tRegValRs = { UV32_XX, idValPc[31:2] + idImm[29:0], 2'b00};

		UREG_MR_IMM:	tRegValRs = { UV32_XX, idImm };
		UREG_ZZR:		tRegValRs = 0;

		UREG_MACH:	tRegValRs = { UV32_XX, regMach };
		UREG_MACL:	tRegValRs = { UV32_XX, regMacl };
		UREG_PR:	tRegValRs = { UV32_XX, regPr    };
		UREG_SGR:	tRegValRs = { UV32_XX, regSGr   };
		UREG_FPUL:	tRegValRs = { UV32_XX, regFpul  };
		UREG_FPSCR:	tRegValRs = { UV32_XX, regFpScr };

		UREG_SR:	tRegValRs = { UV32_XX, regSr  };
		UREG_GBR:	tRegValRs = { UV32_XX, regGbr };
		UREG_VBR:	tRegValRs = { UV32_XX, regVbr };
		UREG_SSR:	tRegValRs = { UV32_XX, regSSr };
		UREG_SPC:	tRegValRs = { UV32_XX, regSPc };
		UREG_PC:	tRegValRs = { UV32_XX, idValPc };

		default:	tRegValRs = UV64_XX;
	endcase

	case(regIdRt)
		UREG_R0:	tRegValRt = { UV32_XX, regGprR0A };
		UREG_R1:	tRegValRt = { UV32_XX, regGprR1A };
		UREG_R2:	tRegValRt = { UV32_XX, regGprR2A };
		UREG_R3:	tRegValRt = { UV32_XX, regGprR3A };
		UREG_R4:	tRegValRt = { UV32_XX, regGprR4A };
		UREG_R5:	tRegValRt = { UV32_XX, regGprR5A };
		UREG_R6:	tRegValRt = { UV32_XX, regGprR6A };
		UREG_R7:	tRegValRt = { UV32_XX, regGprR7A };
		UREG_R8:	tRegValRt = { UV32_XX, regGprR8  };
		UREG_R9:	tRegValRt = { UV32_XX, regGprR9  };
		UREG_R10:	tRegValRt = { UV32_XX, regGprR10 };
		UREG_R11:	tRegValRt = { UV32_XX, regGprR11 };
		UREG_R12:	tRegValRt = { UV32_XX, regGprR12 };
		UREG_R13:	tRegValRt = { UV32_XX, regGprR13 };
		UREG_R14:	tRegValRt = { UV32_XX, regGprR14 };
		UREG_R15:	tRegValRt = { UV32_XX, regSp     };

		UREG_FR0:	tRegValRt = fprIsLd64 ?
			{regFprFR00, regFprFR01} : {UV32_XX, regFprFR00};
		UREG_FR1:	tRegValRt = fprIsLd64 ?
			{regFprXF00, regFprXF01} : {UV32_XX, regFprFR01};
		UREG_FR2:	tRegValRt = fprIsLd64 ?
			{regFprFR02, regFprFR03} : {UV32_XX, regFprFR02};
		UREG_FR3:	tRegValRt = fprIsLd64 ?
			{regFprXF02, regFprXF03} : {UV32_XX, regFprFR03};
		UREG_FR4:	tRegValRt = fprIsLd64 ?
			{regFprFR04, regFprFR05} : {UV32_XX, regFprFR04};
		UREG_FR5:	tRegValRt = fprIsLd64 ?
			{regFprXF04, regFprXF05} : {UV32_XX, regFprFR05};
		UREG_FR6:	tRegValRt = fprIsLd64 ?
			{regFprFR06, regFprFR07} : {UV32_XX, regFprFR06};
		UREG_FR7:	tRegValRt = fprIsLd64 ?
			{regFprXF06, regFprXF07} : {UV32_XX, regFprFR07};
		UREG_FR8:	tRegValRt = fprIsLd64 ?
			{regFprFR08, regFprFR09} : {UV32_XX, regFprFR08};
		UREG_FR9:	tRegValRt = fprIsLd64 ?
			{regFprXF08, regFprXF09} : {UV32_XX, regFprFR09};
		UREG_FR10:	tRegValRt = fprIsLd64 ?
			{regFprFR10, regFprFR11} : {UV32_XX, regFprFR10};
		UREG_FR11:	tRegValRt = fprIsLd64 ?
			{regFprXF10, regFprXF11} : {UV32_XX, regFprFR11};
		UREG_FR12:	tRegValRt = fprIsLd64 ?
			{regFprFR12, regFprFR13} : {UV32_XX, regFprFR12};
		UREG_FR13:	tRegValRt = fprIsLd64 ?
			{regFprXF12, regFprXF13} : {UV32_XX, regFprFR13};
		UREG_FR14:	tRegValRt = fprIsLd64 ?
			{regFprFR14, regFprFR15} : {UV32_XX, regFprFR14};
		UREG_FR15:	tRegValRt = fprIsLd64 ?
			{regFprXF14, regFprXF15} : {UV32_XX, regFprFR15};

		UREG_MR_IMM:	tRegValRt = { UV32_XX, idImm };
		UREG_ZZR:		tRegValRt = 0;

//		UREG_MACH:	tRegValRt = { UV32_XX, regMach  };
//		UREG_MACL:	tRegValRt = { UV32_XX, regMacl  };
//		UREG_PR:	tRegValRt = { UV32_XX, regPr    };
//		UREG_SGR:	tRegValRt = { UV32_XX, regSGr   };
//		UREG_FPUL:	tRegValRt = { UV32_XX, regFpul  };
//		UREG_FPSCR:	tRegValRt = { UV32_XX, regFpScr };

//		UREG_SR:	tRegValRt = { UV32_XX, regSr  };
//		UREG_GBR:	tRegValRt = { UV32_XX, regGbr };
//		UREG_VBR:	tRegValRt = { UV32_XX, regVbr };
//		UREG_SSR:	tRegValRt = { UV32_XX, regSSr };
//		UREG_SPC:	tRegValRt = { UV32_XX, regSPc };
//		UREG_PC:	tRegValRt = { UV32_XX, idValPc };

		default:	tRegValRt = UV64_XX;
	endcase

	case(regIdRn)
		UREG_R0:	tRegValRn = { UV32_XX, regGprR0A };
		UREG_R1:	tRegValRn = { UV32_XX, regGprR1A };
		UREG_R2:	tRegValRn = { UV32_XX, regGprR2A };
		UREG_R3:	tRegValRn = { UV32_XX, regGprR3A };
		UREG_R4:	tRegValRn = { UV32_XX, regGprR4A };
		UREG_R5:	tRegValRn = { UV32_XX, regGprR5A };
		UREG_R6:	tRegValRn = { UV32_XX, regGprR6A };
		UREG_R7:	tRegValRn = { UV32_XX, regGprR7A };
		UREG_R8:	tRegValRn = { UV32_XX, regGprR8  };
		UREG_R9:	tRegValRn = { UV32_XX, regGprR9  };
		UREG_R10:	tRegValRn = { UV32_XX, regGprR10 };
		UREG_R11:	tRegValRn = { UV32_XX, regGprR11 };
		UREG_R12:	tRegValRn = { UV32_XX, regGprR12 };
		UREG_R13:	tRegValRn = { UV32_XX, regGprR13 };
		UREG_R14:	tRegValRn = { UV32_XX, regGprR14 };
		UREG_R15:	tRegValRn = { UV32_XX, regSp     };

		UREG_GBR:	tRegValRn = { UV32_XX, regGbr    };

		default:	tRegValRn = UV64_XX;
	endcase

/*
	nxtRegFprFR00 = regFprFR00;		nxtRegFprFR01 = regFprFR01;
	nxtRegFprFR02 = regFprFR02;		nxtRegFprFR03 = regFprFR03;
	nxtRegFprFR04 = regFprFR04;		nxtRegFprFR05 = regFprFR05;
	nxtRegFprFR06 = regFprFR06;		nxtRegFprFR07 = regFprFR07;
	nxtRegFprFR08 = regFprFR08;		nxtRegFprFR09 = regFprFR09;
	nxtRegFprFR10 = regFprFR10;		nxtRegFprFR11 = regFprFR11;
	nxtRegFprFR12 = regFprFR12;		nxtRegFprFR13 = regFprFR13;
	nxtRegFprFR14 = regFprFR14;		nxtRegFprFR15 = regFprFR15;

	nxtRegFprXF00 = regFprXF00;		nxtRegFprXF01 = regFprXF01;
	nxtRegFprXF02 = regFprXF02;		nxtRegFprXF03 = regFprXF03;
	nxtRegFprXF04 = regFprXF04;		nxtRegFprXF05 = regFprXF05;
	nxtRegFprXF06 = regFprXF06;		nxtRegFprXF07 = regFprXF07;
	nxtRegFprXF08 = regFprXF08;		nxtRegFprXF09 = regFprXF09;
	nxtRegFprXF10 = regFprXF10;		nxtRegFprXF11 = regFprXF11;
	nxtRegFprXF12 = regFprXF12;		nxtRegFprXF13 = regFprXF13;
	nxtRegFprXF14 = regFprXF14;		nxtRegFprXF15 = regFprXF15;

	if(fprIsSt64)
	begin

		case(regIdRo)
			UREG_FR0:	{nxtRegFprFR00, nxtRegFprFR01} = regValRo;
			UREG_FR1:	{nxtRegFprXF00, nxtRegFprXF01} = regValRo;
			UREG_FR2:	{nxtRegFprFR02, nxtRegFprFR03} = regValRo;
			UREG_FR3:	{nxtRegFprXF02, nxtRegFprXF03} = regValRo;
			UREG_FR4:	{nxtRegFprFR04, nxtRegFprFR05} = regValRo;
			UREG_FR5:	{nxtRegFprXF04, nxtRegFprXF05} = regValRo;
			UREG_FR6:	{nxtRegFprFR06, nxtRegFprFR07} = regValRo;
			UREG_FR7:	{nxtRegFprXF06, nxtRegFprXF07} = regValRo;
			UREG_FR8:	{nxtRegFprFR08, nxtRegFprFR09} = regValRo;
			UREG_FR9:	{nxtRegFprXF08, nxtRegFprXF09} = regValRo;
			UREG_FR10:	{nxtRegFprFR10, nxtRegFprFR11} = regValRo;
			UREG_FR11:	{nxtRegFprXF10, nxtRegFprXF11} = regValRo;
			UREG_FR12:	{nxtRegFprFR12, nxtRegFprFR13} = regValRo;
			UREG_FR13:	{nxtRegFprXF12, nxtRegFprXF13} = regValRo;
			UREG_FR14:	{nxtRegFprFR14, nxtRegFprFR15} = regValRo;
			UREG_FR15:	{nxtRegFprXF14, nxtRegFprXF15} = regValRo;
			default:	begin end
		endcase

	end
	else
	begin

		case(regIdRo)
			UREG_FR0:	nxtRegFprFR00 = regValRo[31:0];
			UREG_FR1:	nxtRegFprFR01 = regValRo[31:0];
			UREG_FR2:	nxtRegFprFR02 = regValRo[31:0];
			UREG_FR3:	nxtRegFprFR03 = regValRo[31:0];
			UREG_FR4:	nxtRegFprFR04 = regValRo[31:0];
			UREG_FR5:	nxtRegFprFR05 = regValRo[31:0];
			UREG_FR6:	nxtRegFprFR06 = regValRo[31:0];
			UREG_FR7:	nxtRegFprFR07 = regValRo[31:0];
			UREG_FR8:	nxtRegFprFR08 = regValRo[31:0];
			UREG_FR9:	nxtRegFprFR09 = regValRo[31:0];
			UREG_FR10:	nxtRegFprFR10 = regValRo[31:0];
			UREG_FR11:	nxtRegFprFR11 = regValRo[31:0];
			UREG_FR12:	nxtRegFprFR12 = regValRo[31:0];
			UREG_FR13:	nxtRegFprFR13 = regValRo[31:0];
			UREG_FR14:	nxtRegFprFR14 = regValRo[31:0];
			UREG_FR15:	nxtRegFprFR15 = regValRo[31:0];

			UREG_XF0:	nxtRegFprXF00 = regValRo[31:0];
			UREG_XF1:	nxtRegFprXF01 = regValRo[31:0];
			UREG_XF2:	nxtRegFprXF02 = regValRo[31:0];
			UREG_XF3:	nxtRegFprXF03 = regValRo[31:0];
			UREG_XF4:	nxtRegFprXF04 = regValRo[31:0];
			UREG_XF5:	nxtRegFprXF05 = regValRo[31:0];
			UREG_XF6:	nxtRegFprXF06 = regValRo[31:0];
			UREG_XF7:	nxtRegFprXF07 = regValRo[31:0];
			UREG_XF8:	nxtRegFprXF08 = regValRo[31:0];
			UREG_XF9:	nxtRegFprXF09 = regValRo[31:0];
			UREG_XF10:	nxtRegFprXF10 = regValRo[31:0];
			UREG_XF11:	nxtRegFprXF11 = regValRo[31:0];
			UREG_XF12:	nxtRegFprXF12 = regValRo[31:0];
			UREG_XF13:	nxtRegFprXF13 = regValRo[31:0];
			UREG_XF14:	nxtRegFprXF14 = regValRo[31:0];
			UREG_XF15:	nxtRegFprXF15 = regValRo[31:0];

			default:	begin end
		endcase

	end
*/

end

always @ (posedge clock)
begin

	regSrRB		<= nxtRegSrRB;
	regFprRB	<= nxtRegFprRB;

	if(regSrRB^nxtRegSrRB)
	begin
		regGprR0A	<= regGprR0B;
		regGprR1A	<= regGprR1B;
		regGprR2A	<= regGprR2B;
		regGprR3A	<= regGprR3B;
		regGprR4A	<= regGprR4B;
		regGprR5A	<= regGprR5B;
		regGprR6A	<= regGprR6B;
		regGprR7A	<= regGprR7B;

		regGprR0B	<= regGprR0A;
		regGprR1B	<= regGprR1A;
		regGprR2B	<= regGprR2A;
		regGprR3B	<= regGprR3A;
		regGprR4B	<= regGprR4A;
		regGprR5B	<= regGprR5A;
		regGprR6B	<= regGprR6A;
		regGprR7B	<= regGprR7A;
	end
	else
	begin
		regGprR0A <= (regIdRo==UREG_R0) ? regValRo[31:0] : regGprR0A;
		regGprR1A <= (regIdRo==UREG_R1) ? regValRo[31:0] : regGprR1A;
		regGprR2A <= (regIdRo==UREG_R2) ? regValRo[31:0] : regGprR2A;
		regGprR3A <= (regIdRo==UREG_R3) ? regValRo[31:0] : regGprR3A;
		regGprR4A <= (regIdRo==UREG_R4) ? regValRo[31:0] : regGprR4A;
		regGprR5A <= (regIdRo==UREG_R5) ? regValRo[31:0] : regGprR5A;
		regGprR6A <= (regIdRo==UREG_R6) ? regValRo[31:0] : regGprR6A;
		regGprR7A <= (regIdRo==UREG_R7) ? regValRo[31:0] : regGprR7A;

		regGprR0B <= (regIdRo==UREG_R0B) ? regValRo[31:0] : regGprR0B;
		regGprR1B <= (regIdRo==UREG_R1B) ? regValRo[31:0] : regGprR1B;
		regGprR2B <= (regIdRo==UREG_R2B) ? regValRo[31:0] : regGprR2B;
		regGprR3B <= (regIdRo==UREG_R3B) ? regValRo[31:0] : regGprR3B;
		regGprR4B <= (regIdRo==UREG_R4B) ? regValRo[31:0] : regGprR4B;
		regGprR5B <= (regIdRo==UREG_R5B) ? regValRo[31:0] : regGprR5B;
		regGprR6B <= (regIdRo==UREG_R6B) ? regValRo[31:0] : regGprR6B;
		regGprR7B <= (regIdRo==UREG_R7B) ? regValRo[31:0] : regGprR7B;
	end

	regGprR8  <= (regIdRo==UREG_R8 ) ? regValRo[31:0] : regGprR8 ;
	regGprR9  <= (regIdRo==UREG_R9 ) ? regValRo[31:0] : regGprR9 ;
	regGprR10 <= (regIdRo==UREG_R10) ? regValRo[31:0] : regGprR10;
	regGprR11 <= (regIdRo==UREG_R11) ? regValRo[31:0] : regGprR11;
	regGprR12 <= (regIdRo==UREG_R12) ? regValRo[31:0] : regGprR12;
	regGprR13 <= (regIdRo==UREG_R13) ? regValRo[31:0] : regGprR13;
	regGprR14 <= (regIdRo==UREG_R14) ? regValRo[31:0] : regGprR14;

	if(regFprRB^nxtRegFprRB)
	begin
/*
		regFprFR00 <= nxtRegFprXF00;	regFprFR01 <= nxtRegFprXF01;
		regFprFR02 <= nxtRegFprXF02;	regFprFR03 <= nxtRegFprXF03;
		regFprFR04 <= nxtRegFprXF04;	regFprFR05 <= nxtRegFprXF05;
		regFprFR06 <= nxtRegFprXF06;	regFprFR07 <= nxtRegFprXF07;
		regFprFR08 <= nxtRegFprXF08;	regFprFR09 <= nxtRegFprXF09;
		regFprFR10 <= nxtRegFprXF10;	regFprFR11 <= nxtRegFprXF11;
		regFprFR12 <= nxtRegFprXF12;	regFprFR13 <= nxtRegFprXF13;
		regFprFR14 <= nxtRegFprXF14;	regFprFR15 <= nxtRegFprXF15;
		regFprXF00 <= nxtRegFprFR00;	regFprXF01 <= nxtRegFprFR01;
		regFprXF02 <= nxtRegFprFR02;	regFprXF03 <= nxtRegFprFR03;
		regFprXF04 <= nxtRegFprFR04;	regFprXF05 <= nxtRegFprFR05;
		regFprXF06 <= nxtRegFprFR06;	regFprXF07 <= nxtRegFprFR07;
		regFprXF08 <= nxtRegFprFR08;	regFprXF09 <= nxtRegFprFR09;
		regFprXF10 <= nxtRegFprFR10;	regFprXF11 <= nxtRegFprFR11;
		regFprXF12 <= nxtRegFprFR12;	regFprXF13 <= nxtRegFprFR13;
		regFprXF14 <= nxtRegFprFR14;	regFprXF15 <= nxtRegFprFR15;
*/

		regFprFR00 <= regFprXF00;	regFprFR01 <= regFprXF01;
		regFprFR02 <= regFprXF02;	regFprFR03 <= regFprXF03;
		regFprFR04 <= regFprXF04;	regFprFR05 <= regFprXF05;
		regFprFR06 <= regFprXF06;	regFprFR07 <= regFprXF07;
		regFprFR08 <= regFprXF08;	regFprFR09 <= regFprXF09;
		regFprFR10 <= regFprXF10;	regFprFR11 <= regFprXF11;
		regFprFR12 <= regFprXF12;	regFprFR13 <= regFprXF13;
		regFprFR14 <= regFprXF14;	regFprFR15 <= regFprXF15;
		regFprXF00 <= regFprFR00;	regFprXF01 <= regFprFR01;
		regFprXF02 <= regFprFR02;	regFprXF03 <= regFprFR03;
		regFprXF04 <= regFprFR04;	regFprXF05 <= regFprFR05;
		regFprXF06 <= regFprFR06;	regFprXF07 <= regFprFR07;
		regFprXF08 <= regFprFR08;	regFprXF09 <= regFprFR09;
		regFprXF10 <= regFprFR10;	regFprXF11 <= regFprFR11;
		regFprXF12 <= regFprFR12;	regFprXF13 <= regFprFR13;
		regFprXF14 <= regFprFR14;	regFprXF15 <= regFprFR15;

	end
	else
	begin
		if(fprIsSt64)
		begin
			regFprFR00 <= (regIdRo==UREG_FR0 ) ? regValRo[63:32] : regFprFR00;
			regFprFR01 <= (regIdRo==UREG_FR0 ) ? regValRo[31: 0] : regFprFR01;
			regFprFR02 <= (regIdRo==UREG_FR2 ) ? regValRo[63:32] : regFprFR02;
			regFprFR03 <= (regIdRo==UREG_FR2 ) ? regValRo[31: 0] : regFprFR03;
			regFprFR04 <= (regIdRo==UREG_FR4 ) ? regValRo[63:32] : regFprFR04;
			regFprFR05 <= (regIdRo==UREG_FR4 ) ? regValRo[31: 0] : regFprFR05;
			regFprFR06 <= (regIdRo==UREG_FR6 ) ? regValRo[63:32] : regFprFR06;
			regFprFR07 <= (regIdRo==UREG_FR6 ) ? regValRo[31: 0] : regFprFR07;
			regFprFR08 <= (regIdRo==UREG_FR8 ) ? regValRo[63:32] : regFprFR08;
			regFprFR09 <= (regIdRo==UREG_FR8 ) ? regValRo[31: 0] : regFprFR09;
			regFprFR10 <= (regIdRo==UREG_FR10) ? regValRo[63:32] : regFprFR10;
			regFprFR11 <= (regIdRo==UREG_FR10) ? regValRo[31: 0] : regFprFR11;
			regFprFR12 <= (regIdRo==UREG_FR12) ? regValRo[63:32] : regFprFR12;
			regFprFR13 <= (regIdRo==UREG_FR12) ? regValRo[31: 0] : regFprFR13;
			regFprFR14 <= (regIdRo==UREG_FR14) ? regValRo[63:32] : regFprFR14;
			regFprFR15 <= (regIdRo==UREG_FR14) ? regValRo[31: 0] : regFprFR15;

			regFprXF00 <= (regIdRo==UREG_FR1 ) ? regValRo[63:32] : regFprXF00;
			regFprXF01 <= (regIdRo==UREG_FR1 ) ? regValRo[31: 0] : regFprXF01;
			regFprXF02 <= (regIdRo==UREG_FR3 ) ? regValRo[63:32] : regFprXF02;
			regFprXF03 <= (regIdRo==UREG_FR3 ) ? regValRo[31: 0] : regFprXF03;
			regFprXF04 <= (regIdRo==UREG_FR5 ) ? regValRo[63:32] : regFprXF04;
			regFprXF05 <= (regIdRo==UREG_FR5 ) ? regValRo[31: 0] : regFprXF05;
			regFprXF06 <= (regIdRo==UREG_FR7 ) ? regValRo[63:32] : regFprXF06;
			regFprXF07 <= (regIdRo==UREG_FR7 ) ? regValRo[31: 0] : regFprXF07;
			regFprXF08 <= (regIdRo==UREG_FR9 ) ? regValRo[63:32] : regFprXF08;
			regFprXF09 <= (regIdRo==UREG_FR9 ) ? regValRo[31: 0] : regFprXF09;
			regFprXF10 <= (regIdRo==UREG_FR11) ? regValRo[63:32] : regFprXF10;
			regFprXF11 <= (regIdRo==UREG_FR11) ? regValRo[31: 0] : regFprXF11;
			regFprXF12 <= (regIdRo==UREG_FR13) ? regValRo[63:32] : regFprXF12;
			regFprXF13 <= (regIdRo==UREG_FR13) ? regValRo[31: 0] : regFprXF13;
			regFprXF14 <= (regIdRo==UREG_FR15) ? regValRo[63:32] : regFprXF14;
			regFprXF15 <= (regIdRo==UREG_FR15) ? regValRo[31: 0] : regFprXF15;
		end
		else
		begin
			regFprFR00 <= (regIdRo==UREG_FR0 ) ? regValRo[31:0] : regFprFR00;
			regFprFR01 <= (regIdRo==UREG_FR1 ) ? regValRo[31:0] : regFprFR01;
			regFprFR02 <= (regIdRo==UREG_FR2 ) ? regValRo[31:0] : regFprFR02;
			regFprFR03 <= (regIdRo==UREG_FR3 ) ? regValRo[31:0] : regFprFR03;
			regFprFR04 <= (regIdRo==UREG_FR4 ) ? regValRo[31:0] : regFprFR04;
			regFprFR05 <= (regIdRo==UREG_FR5 ) ? regValRo[31:0] : regFprFR05;
			regFprFR06 <= (regIdRo==UREG_FR6 ) ? regValRo[31:0] : regFprFR06;
			regFprFR07 <= (regIdRo==UREG_FR7 ) ? regValRo[31:0] : regFprFR07;
			regFprFR08 <= (regIdRo==UREG_FR8 ) ? regValRo[31:0] : regFprFR08;
			regFprFR09 <= (regIdRo==UREG_FR9 ) ? regValRo[31:0] : regFprFR09;
			regFprFR10 <= (regIdRo==UREG_FR10) ? regValRo[31:0] : regFprFR10;
			regFprFR11 <= (regIdRo==UREG_FR11) ? regValRo[31:0] : regFprFR11;
			regFprFR12 <= (regIdRo==UREG_FR12) ? regValRo[31:0] : regFprFR12;
			regFprFR13 <= (regIdRo==UREG_FR13) ? regValRo[31:0] : regFprFR13;
			regFprFR14 <= (regIdRo==UREG_FR14) ? regValRo[31:0] : regFprFR14;
			regFprFR15 <= (regIdRo==UREG_FR15) ? regValRo[31:0] : regFprFR15;

			regFprXF00 <= (regIdRo==UREG_XF0 ) ? regValRo[31:0] : regFprXF00;
			regFprXF01 <= (regIdRo==UREG_XF1 ) ? regValRo[31:0] : regFprXF01;
			regFprXF02 <= (regIdRo==UREG_XF2 ) ? regValRo[31:0] : regFprXF02;
			regFprXF03 <= (regIdRo==UREG_XF3 ) ? regValRo[31:0] : regFprXF03;
			regFprXF04 <= (regIdRo==UREG_XF4 ) ? regValRo[31:0] : regFprXF04;
			regFprXF05 <= (regIdRo==UREG_XF5 ) ? regValRo[31:0] : regFprXF05;
			regFprXF06 <= (regIdRo==UREG_XF6 ) ? regValRo[31:0] : regFprXF06;
			regFprXF07 <= (regIdRo==UREG_XF7 ) ? regValRo[31:0] : regFprXF07;
			regFprXF08 <= (regIdRo==UREG_XF8 ) ? regValRo[31:0] : regFprXF08;
			regFprXF09 <= (regIdRo==UREG_XF9 ) ? regValRo[31:0] : regFprXF09;
			regFprXF10 <= (regIdRo==UREG_XF10) ? regValRo[31:0] : regFprXF10;
			regFprXF11 <= (regIdRo==UREG_XF11) ? regValRo[31:0] : regFprXF11;
			regFprXF12 <= (regIdRo==UREG_XF12) ? regValRo[31:0] : regFprXF12;
			regFprXF13 <= (regIdRo==UREG_XF13) ? regValRo[31:0] : regFprXF13;
			regFprXF14 <= (regIdRo==UREG_XF14) ? regValRo[31:0] : regFprXF14;
			regFprXF15 <= (regIdRo==UREG_XF15) ? regValRo[31:0] : regFprXF15;
		end

/*
		regFprFR00 <= nxtRegFprFR00;	regFprFR01 <= nxtRegFprFR01;
		regFprFR02 <= nxtRegFprFR02;	regFprFR03 <= nxtRegFprFR03;
		regFprFR04 <= nxtRegFprFR04;	regFprFR05 <= nxtRegFprFR05;
		regFprFR06 <= nxtRegFprFR06;	regFprFR07 <= nxtRegFprFR07;
		regFprFR08 <= nxtRegFprFR08;	regFprFR09 <= nxtRegFprFR09;
		regFprFR10 <= nxtRegFprFR10;	regFprFR11 <= nxtRegFprFR11;
		regFprFR12 <= nxtRegFprFR12;	regFprFR13 <= nxtRegFprFR13;
		regFprFR14 <= nxtRegFprFR14;	regFprFR15 <= nxtRegFprFR15;
		regFprXF00 <= nxtRegFprXF00;	regFprXF01 <= nxtRegFprXF01;
		regFprXF02 <= nxtRegFprXF02;	regFprXF03 <= nxtRegFprXF03;
		regFprXF04 <= nxtRegFprXF04;	regFprXF05 <= nxtRegFprXF05;
		regFprXF06 <= nxtRegFprXF06;	regFprXF07 <= nxtRegFprXF07;
		regFprXF08 <= nxtRegFprXF08;	regFprXF09 <= nxtRegFprXF09;
		regFprXF10 <= nxtRegFprXF10;	regFprXF11 <= nxtRegFprXF11;
		regFprXF12 <= nxtRegFprXF12;	regFprXF13 <= nxtRegFprXF13;
		regFprXF14 <= nxtRegFprXF14;	regFprXF15 <= nxtRegFprXF15;
*/
	end

	if(reset)
	begin
	/* Common */
		regSr		<= 0;
		regPr		<= 0;
		regPc		<= 32'hA000_0000;
		regMach		<= 0;
		regMacl		<= 0;
		regSp		<= 0;
		regGbr		<= 0;
		regVbr		<= 0;
		regSSr		<= 0;
		regSPc		<= 0;
		regSGr		<= 0;
		regFpul		<= 0;
		regFpScr	<= 0;
	end
	else
	if(!regExHold)
	begin
		regSr		<= (regIdRo==UREG_SR    ) ? regValRo[31:0] : exNextSr2;
		regPr		<= (regIdRo==UREG_PR    ) ? regValRo[31:0] : exNextPr2;
		regPc		<= (regIdRo==UREG_PC    ) ? regValRo[31:0] : exNextPc2;
		regMach		<= (regIdRo==UREG_MACH  ) ? regValRo[31:0] : exNextMach2;
		regMacl		<= (regIdRo==UREG_MACL  ) ? regValRo[31:0] : exNextMacl2;
		regSp		<= (regIdRo==UREG_R15   ) ? regValRo[31:0] : exNextSp2;
		regGbr		<= (regIdRo==UREG_GBR   ) ? regValRo[31:0] : exNextGbr2;
		regVbr		<= (regIdRo==UREG_VBR   ) ? regValRo[31:0] : exNextVbr2;
		regSSr		<= (regIdRo==UREG_SSR   ) ? regValRo[31:0] : exNextSSr2;
		regSPc		<= (regIdRo==UREG_SPC   ) ? regValRo[31:0] : exNextSPc2;
		regSGr		<= (regIdRo==UREG_SGR   ) ? regValRo[31:0] : exNextSGr2;
		regFpul		<= (regIdRo==UREG_FPUL  ) ? regValRo[31:0] : exNextFpul2;
		regFpScr	<= (regIdRo==UREG_FPSCR ) ? regValRo[31:0] : exNextFpScr2;

	end
end

endmodule
