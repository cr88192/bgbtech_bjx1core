`include "CoreDefs.v"

module RegWGPR(
	/* verilator lint_off UNUSED */
	clock,	idNextPc,
	idRegN1, idRegS1, idRegT1, idRegW1,
	idRegN2, idRegS2, idRegT2, idRegW2,
	idRegN3, idRegS3, idRegT3, idRegW3,
	idRegN4, idRegS4, idRegT4, idRegW4,
	idRegN5, idRegS5, idRegT5, idRegW5,

	odValN1, odValS1, odValT1, idValW1, idImm1,
	odValN2, odValS2, odValT2, idValW2, idImm2,
	odValN3, odValS3, odValT3, idValW3, idImm3,
	odValN4, odValS4, odValT4, idValW4, idImm4,
	odValN5, odValS5, odValT5, idValW5, idImm5,

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

parameter		wgprEnableLane4 = 0;
parameter		wgprEnableLane5 = 0;

input			clock;
input[63:0]		idNextPc;

input[6:0]		idRegN1;
input[6:0]		idRegS1;
input[6:0]		idRegT1;
input[6:0]		idRegN2;
input[6:0]		idRegS2;
input[6:0]		idRegT2;
input[6:0]		idRegN3;
input[6:0]		idRegS3;
input[6:0]		idRegT3;
input[6:0]		idRegN4;
input[6:0]		idRegS4;
input[6:0]		idRegT4;
input[6:0]		idRegN5;
input[6:0]		idRegS5;
input[6:0]		idRegT5;

input[6:0]		idRegW1;
input[6:0]		idRegW2;
input[6:0]		idRegW3;
input[6:0]		idRegW4;
input[6:0]		idRegW5;

output[63:0]	odValN1;
output[63:0]	odValS1;
output[63:0]	odValT1;
output[63:0]	odValN2;
output[63:0]	odValS2;
output[63:0]	odValT2;
output[63:0]	odValN3;
output[63:0]	odValS3;
output[63:0]	odValT3;
output[63:0]	odValN4;
output[63:0]	odValS4;
output[63:0]	odValT4;
output[63:0]	odValN5;
output[63:0]	odValS5;
output[63:0]	odValT5;

input[63:0]		idValW1;
input[63:0]		idValW2;
input[63:0]		idValW3;
input[63:0]		idValW4;
input[63:0]		idValW5;

input[63:0]		idImm1;
input[63:0]		idImm2;
input[63:0]		idImm3;
input[63:0]		idImm4;
input[63:0]		idImm5;


input[63:0]		exNextSr2;			//SR in
input[63:0]		exNextPr2;			//PR in
input[63:0]		exNextPc2;			//PC in
input[63:0]		exNextMach2;		//MACH
input[63:0]		exNextMacl2;		//MACL
input[63:0]		exNextGbr2;			//GBR
input[63:0]		exNextVbr2;			//VBR
input[63:0]		exNextSSr2;			//SSR
input[63:0]		exNextSPc2;			//SPC
input[63:0]		exNextSGr2;			//SGR (Saved R15)
input[63:0]		exNextFpul2;		//
input[63:0]		exNextFpScr2;		//
input[63:0]		exNextSp2;			//

output[63:0]	oregMach;			//MACH
output[63:0]	oregMacl;			//MACL
output[63:0]	oregPr;				//PR
output[63:0]	oregSGr;			//SGR (Saved R15)
output[63:0]	oregFpul;			//FPUL
output[63:0]	oregFpScr;			//FPSCR
output[63:0]	oregSr;				//SR
output[63:0]	oregGbr;			//GBR
output[63:0]	oregVbr;			//VBR
output[63:0]	oregSSr;			//SSR
output[63:0]	oregSPc;			//SPC
output[63:0]	oregPc;				//PC
output[63:0]	oregSp;				//SP/GR (R15)

reg[63:0]		regMach;			//MACH
reg[63:0]		regMacl;			//MACL
reg[63:0]		regPr;				//PR
reg[63:0]		regSGr;				//SGR (Saved R15)
reg[63:0]		regFpul;			//FPUL
reg[63:0]		regFpScr;			//FPSCR
reg[63:0]		regSr;				//SR
reg[63:0]		regGbr;				//GBR
reg[63:0]		regVbr;				//VBR
reg[63:0]		regSSr;				//SSR
reg[63:0]		regSPc;				//SPC
reg[63:0]		regPc;				//PC
reg[63:0]		regSp;				//SP/GR (R15)

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


reg[63:0]	tValN1;
reg[63:0]	tValS1;
reg[63:0]	tValT1;
reg[63:0]	tValN2;
reg[63:0]	tValS2;
reg[63:0]	tValT2;
reg[63:0]	tValN3;
reg[63:0]	tValS3;
reg[63:0]	tValT3;
reg[63:0]	tValN4;
reg[63:0]	tValS4;
reg[63:0]	tValT4;
reg[63:0]	tValN5;
reg[63:0]	tValS5;
reg[63:0]	tValT5;

assign	odValN1 = tValN1;
assign	odValS1 = tValS1;
assign	odValT1 = tValT1;
assign	odValN2 = tValN2;
assign	odValS2 = tValS2;
assign	odValT2 = tValT2;
assign	odValN3 = tValN3;
assign	odValS3 = tValS3;
assign	odValT3 = tValT3;
assign	odValN4 = tValN4;
assign	odValS4 = tValS4;
assign	odValT4 = tValT4;
assign	odValN5 = tValN5;
assign	odValS5 = tValS5;
assign	odValT5 = tValT5;

reg			regSrRB;
reg			nxtRegSrRB;
reg			regFprRB;
reg			nxtRegFprRB;

reg 		fprIsLd64;
reg 		fprIsSt64;


reg[63:0]	regGprR0;
reg[63:0]	regGprR1;
reg[63:0]	regGprR2;
reg[63:0]	regGprR3;
reg[63:0]	regGprR4;
reg[63:0]	regGprR5;
reg[63:0]	regGprR6;
reg[63:0]	regGprR7;

reg[63:0]	regGprR8;
reg[63:0]	regGprR9;
reg[63:0]	regGprR10;
reg[63:0]	regGprR11;
reg[63:0]	regGprR12;
reg[63:0]	regGprR13;
reg[63:0]	regGprR14;
reg[63:0]	regGprR15;

reg[63:0]	regGprR16;
reg[63:0]	regGprR17;
reg[63:0]	regGprR18;
reg[63:0]	regGprR19;
reg[63:0]	regGprR20;
reg[63:0]	regGprR21;
reg[63:0]	regGprR22;
reg[63:0]	regGprR23;

reg[63:0]	regGprR24;
reg[63:0]	regGprR25;
reg[63:0]	regGprR26;
reg[63:0]	regGprR27;
reg[63:0]	regGprR28;
reg[63:0]	regGprR29;
reg[63:0]	regGprR30;
reg[63:0]	regGprR31;


reg[63:0]	regGprR0B;
reg[63:0]	regGprR1B;
reg[63:0]	regGprR2B;
reg[63:0]	regGprR3B;
reg[63:0]	regGprR4B;
reg[63:0]	regGprR5B;
reg[63:0]	regGprR6B;
reg[63:0]	regGprR7B;

reg[63:0]	regGprR16B;
reg[63:0]	regGprR17B;
reg[63:0]	regGprR18B;
reg[63:0]	regGprR19B;
reg[63:0]	regGprR20B;
reg[63:0]	regGprR21B;
reg[63:0]	regGprR22B;
reg[63:0]	regGprR23B;


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


always @*
begin

	fprIsLd64 = 0;
	fprIsSt64 = 0;

//	fprIsLd64 = regLdMode[0];
//	fprIsSt64 = regStMode[0];

	nxtRegSrRB  = 0;
	nxtRegFprRB = 0;

//	nxtRegSrRB=regSrVal[29];
//	nxtRegFprRB=regFpScr[21];

	tValN2 = UV64_XX;
	tValN3 = UV64_XX;
	tValN4 = UV64_XX;
	tValN5 = UV64_XX;

	tValS4 = UV64_XX;
	tValS5 = UV64_XX;
	tValT4 = UV64_XX;
	tValT5 = UV64_XX;

	case(idRegN1)
		UREG_R0:  tValN1 = regGprR0;	UREG_R1:  tValN1 = regGprR1;
		UREG_R2:  tValN1 = regGprR2;	UREG_R3:  tValN1 = regGprR3;
		UREG_R4:  tValN1 = regGprR4;	UREG_R5:  tValN1 = regGprR5;
		UREG_R6:  tValN1 = regGprR6;	UREG_R7:  tValN1 = regGprR7;
		UREG_R8:  tValN1 = regGprR8;	UREG_R9:  tValN1 = regGprR9;
		UREG_R10: tValN1 = regGprR10;	UREG_R11: tValN1 = regGprR11;
		UREG_R12: tValN1 = regGprR12;	UREG_R13: tValN1 = regGprR13;
		UREG_R14: tValN1 = regGprR14;	UREG_R15: tValN1 = regGprR15;
		UREG_R16: tValN1 = regGprR16;	UREG_R17: tValN1 = regGprR17;
		UREG_R18: tValN1 = regGprR18;	UREG_R19: tValN1 = regGprR19;
		UREG_R20: tValN1 = regGprR20;	UREG_R21: tValN1 = regGprR21;
		UREG_R22: tValN1 = regGprR22;	UREG_R23: tValN1 = regGprR23;
		UREG_R24: tValN1 = regGprR24;	UREG_R25: tValN1 = regGprR25;
		UREG_R26: tValN1 = regGprR26;	UREG_R27: tValN1 = regGprR27;
		UREG_R28: tValN1 = regGprR28;	UREG_R29: tValN1 = regGprR29;
		UREG_R30: tValN1 = regGprR30;	UREG_R31: tValN1 = regGprR31;
		default:  tValN1 = UV64_XX;
	endcase

	case(idRegS1)
		UREG_R0:  tValS1 = regGprR0;	UREG_R1:  tValS1 = regGprR1;
		UREG_R2:  tValS1 = regGprR2;	UREG_R3:  tValS1 = regGprR3;
		UREG_R4:  tValS1 = regGprR4;	UREG_R5:  tValS1 = regGprR5;
		UREG_R6:  tValS1 = regGprR6;	UREG_R7:  tValS1 = regGprR7;
		UREG_R8:  tValS1 = regGprR8;	UREG_R9:  tValS1 = regGprR9;
		UREG_R10: tValS1 = regGprR10;	UREG_R11: tValS1 = regGprR11;
		UREG_R12: tValS1 = regGprR12;	UREG_R13: tValS1 = regGprR13;
		UREG_R14: tValS1 = regGprR14;	UREG_R15: tValS1 = regGprR15;
		UREG_R16: tValS1 = regGprR16;	UREG_R17: tValS1 = regGprR17;
		UREG_R18: tValS1 = regGprR18;	UREG_R19: tValS1 = regGprR19;
		UREG_R20: tValS1 = regGprR20;	UREG_R21: tValS1 = regGprR21;
		UREG_R22: tValS1 = regGprR22;	UREG_R23: tValS1 = regGprR23;
		UREG_R24: tValS1 = regGprR24;	UREG_R25: tValS1 = regGprR25;
		UREG_R26: tValS1 = regGprR26;	UREG_R27: tValS1 = regGprR27;
		UREG_R28: tValS1 = regGprR28;	UREG_R29: tValS1 = regGprR29;
		UREG_R30: tValS1 = regGprR30;	UREG_R31: tValS1 = regGprR31;

		UREG_R0B:  tValS1 = regGprR0B;	UREG_R1B:  tValS1 = regGprR1B;
		UREG_R2B:  tValS1 = regGprR2B;	UREG_R3B:  tValS1 = regGprR3B;
		UREG_R4B:  tValS1 = regGprR4B;	UREG_R5B:  tValS1 = regGprR5B;
		UREG_R6B:  tValS1 = regGprR6B;	UREG_R7B:  tValS1 = regGprR7B;

		UREG_R16B: tValS1 = regGprR16B;	UREG_R17B: tValS1 = regGprR17B;
		UREG_R18B: tValS1 = regGprR18B;	UREG_R19B: tValS1 = regGprR19B;
		UREG_R20B: tValS1 = regGprR20B;	UREG_R21B: tValS1 = regGprR21B;
		UREG_R22B: tValS1 = regGprR22B;	UREG_R23B: tValS1 = regGprR23B;

		UREG_FR0:	tValS1 = fprIsLd64 ?
			{regFprFR00, regFprFR01} : {UV32_XX, regFprFR00};
		UREG_FR1:	tValS1 = fprIsLd64 ?
			{regFprXF00, regFprXF01} : {UV32_XX, regFprFR01};
		UREG_FR2:	tValS1 = fprIsLd64 ?
			{regFprFR02, regFprFR03} : {UV32_XX, regFprFR02};
		UREG_FR3:	tValS1 = fprIsLd64 ?
			{regFprXF02, regFprXF03} : {UV32_XX, regFprFR03};
		UREG_FR4:	tValS1 = fprIsLd64 ?
			{regFprFR04, regFprFR05} : {UV32_XX, regFprFR04};
		UREG_FR5:	tValS1 = fprIsLd64 ?
			{regFprXF04, regFprXF05} : {UV32_XX, regFprFR05};
		UREG_FR6:	tValS1 = fprIsLd64 ?
			{regFprFR06, regFprFR07} : {UV32_XX, regFprFR06};
		UREG_FR7:	tValS1 = fprIsLd64 ?
			{regFprXF06, regFprXF07} : {UV32_XX, regFprFR07};
		UREG_FR8:	tValS1 = fprIsLd64 ?
			{regFprFR08, regFprFR09} : {UV32_XX, regFprFR08};
		UREG_FR9:	tValS1 = fprIsLd64 ?
			{regFprXF08, regFprXF09} : {UV32_XX, regFprFR09};
		UREG_FR10:	tValS1 = fprIsLd64 ?
			{regFprFR10, regFprFR11} : {UV32_XX, regFprFR10};
		UREG_FR11:	tValS1 = fprIsLd64 ?
			{regFprXF10, regFprXF11} : {UV32_XX, regFprFR11};
		UREG_FR12:	tValS1 = fprIsLd64 ?
			{regFprFR12, regFprFR13} : {UV32_XX, regFprFR12};
		UREG_FR13:	tValS1 = fprIsLd64 ?
			{regFprXF12, regFprXF13} : {UV32_XX, regFprFR13};
		UREG_FR14:	tValS1 = fprIsLd64 ?
			{regFprFR14, regFprFR15} : {UV32_XX, regFprFR14};
		UREG_FR15:	tValS1 = fprIsLd64 ?
			{regFprXF14, regFprXF15} : {UV32_XX, regFprFR15};
		
		UREG_SR:  tValS1 = regSr;		UREG_GBR: tValS1 = regGbr;
		UREG_VBR: tValS1 = regVbr;		UREG_SSR: tValS1 = regSSr;
		UREG_SPC: tValS1 = regSPc;
		
		UREG_MACH: tValS1 = regMach;	UREG_MACL: tValS1 = regMacl;
		UREG_PR:   tValS1 = regPr;		UREG_SGR: tValS1 = regSGr;
		UREG_FPUL: tValS1 = regFpul;	UREG_FPSCR: tValS1 = regFpScr;

		UREG_PCW: tValS1 = idNextPc;	UREG_PCL: tValS1 = idNextPc;
		UREG_MR_IMM: tValS1 = idImm1;	UREG_ZZR: tValS1 = 0;
		
		default:  tValS1 = UV64_XX;
	endcase

	case(idRegT1)
		UREG_R0:  tValT1 = regGprR0;	UREG_R1:  tValT1 = regGprR1;
		UREG_R2:  tValT1 = regGprR2;	UREG_R3:  tValT1 = regGprR3;
		UREG_R4:  tValT1 = regGprR4;	UREG_R5:  tValT1 = regGprR5;
		UREG_R6:  tValT1 = regGprR6;	UREG_R7:  tValT1 = regGprR7;
		UREG_R8:  tValT1 = regGprR8;	UREG_R9:  tValT1 = regGprR9;
		UREG_R10: tValT1 = regGprR10;	UREG_R11: tValT1 = regGprR11;
		UREG_R12: tValT1 = regGprR12;	UREG_R13: tValT1 = regGprR13;
		UREG_R14: tValT1 = regGprR14;	UREG_R15: tValT1 = regGprR15;
		UREG_R16: tValT1 = regGprR16;	UREG_R17: tValT1 = regGprR17;
		UREG_R18: tValT1 = regGprR18;	UREG_R19: tValT1 = regGprR19;
		UREG_R20: tValT1 = regGprR20;	UREG_R21: tValT1 = regGprR21;
		UREG_R22: tValT1 = regGprR22;	UREG_R23: tValT1 = regGprR23;
		UREG_R24: tValT1 = regGprR24;	UREG_R25: tValT1 = regGprR25;
		UREG_R26: tValT1 = regGprR26;	UREG_R27: tValT1 = regGprR27;
		UREG_R28: tValT1 = regGprR28;	UREG_R29: tValT1 = regGprR29;
		UREG_R30: tValT1 = regGprR30;	UREG_R31: tValT1 = regGprR31;

		UREG_R0B:  tValT1 = regGprR0B;	UREG_R1B:  tValT1 = regGprR1B;
		UREG_R2B:  tValT1 = regGprR2B;	UREG_R3B:  tValT1 = regGprR3B;
		UREG_R4B:  tValT1 = regGprR4B;	UREG_R5B:  tValT1 = regGprR5B;
		UREG_R6B:  tValT1 = regGprR6B;	UREG_R7B:  tValT1 = regGprR7B;

		UREG_R16B: tValT1 = regGprR16B;	UREG_R17B: tValT1 = regGprR17B;
		UREG_R18B: tValT1 = regGprR18B;	UREG_R19B: tValT1 = regGprR19B;
		UREG_R20B: tValT1 = regGprR20B;	UREG_R21B: tValT1 = regGprR21B;
		UREG_R22B: tValT1 = regGprR22B;	UREG_R23B: tValT1 = regGprR23B;

		UREG_FR0:	tValT1 = fprIsLd64 ?
			{regFprFR00, regFprFR01} : {UV32_XX, regFprFR00};
		UREG_FR1:	tValT1 = fprIsLd64 ?
			{regFprXF00, regFprXF01} : {UV32_XX, regFprFR01};
		UREG_FR2:	tValT1 = fprIsLd64 ?
			{regFprFR02, regFprFR03} : {UV32_XX, regFprFR02};
		UREG_FR3:	tValT1 = fprIsLd64 ?
			{regFprXF02, regFprXF03} : {UV32_XX, regFprFR03};
		UREG_FR4:	tValT1 = fprIsLd64 ?
			{regFprFR04, regFprFR05} : {UV32_XX, regFprFR04};
		UREG_FR5:	tValT1 = fprIsLd64 ?
			{regFprXF04, regFprXF05} : {UV32_XX, regFprFR05};
		UREG_FR6:	tValT1 = fprIsLd64 ?
			{regFprFR06, regFprFR07} : {UV32_XX, regFprFR06};
		UREG_FR7:	tValT1 = fprIsLd64 ?
			{regFprXF06, regFprXF07} : {UV32_XX, regFprFR07};
		UREG_FR8:	tValT1 = fprIsLd64 ?
			{regFprFR08, regFprFR09} : {UV32_XX, regFprFR08};
		UREG_FR9:	tValT1 = fprIsLd64 ?
			{regFprXF08, regFprXF09} : {UV32_XX, regFprFR09};
		UREG_FR10:	tValT1 = fprIsLd64 ?
			{regFprFR10, regFprFR11} : {UV32_XX, regFprFR10};
		UREG_FR11:	tValT1 = fprIsLd64 ?
			{regFprXF10, regFprXF11} : {UV32_XX, regFprFR11};
		UREG_FR12:	tValT1 = fprIsLd64 ?
			{regFprFR12, regFprFR13} : {UV32_XX, regFprFR12};
		UREG_FR13:	tValT1 = fprIsLd64 ?
			{regFprXF12, regFprXF13} : {UV32_XX, regFprFR13};
		UREG_FR14:	tValT1 = fprIsLd64 ?
			{regFprFR14, regFprFR15} : {UV32_XX, regFprFR14};
		UREG_FR15:	tValT1 = fprIsLd64 ?
			{regFprXF14, regFprXF15} : {UV32_XX, regFprFR15};

		UREG_SR:  tValT1 = regSr;		UREG_GBR: tValT1 = regGbr;
		UREG_VBR: tValT1 = regVbr;		UREG_SSR: tValT1 = regSSr;
		UREG_SPC: tValT1 = regSPc;
		
		UREG_MACH: tValT1 = regMach;	UREG_MACL:  tValT1 = regMacl;
		UREG_PR:   tValT1 = regPr;		UREG_SGR:   tValT1 = regSGr;
		UREG_FPUL: tValT1 = regFpul;	UREG_FPSCR: tValT1 = regFpScr;

		UREG_PCW: tValT1 = idNextPc;	UREG_PCL: tValT1 = idNextPc;
		UREG_MR_IMM: tValT1 = idImm1;	UREG_ZZR: tValT1 = 0;

		default:  tValT1 = UV64_XX;
	endcase

/*
	case(idRegN2)
		UREG_R0:  tValN2 = regGprR0;	UREG_R1:  tValN2 = regGprR1;
		UREG_R2:  tValN2 = regGprR2;	UREG_R3:  tValN2 = regGprR3;
		UREG_R4:  tValN2 = regGprR4;	UREG_R5:  tValN2 = regGprR5;
		UREG_R6:  tValN2 = regGprR6;	UREG_R7:  tValN2 = regGprR7;
		UREG_R8:  tValN2 = regGprR8;	UREG_R9:  tValN2 = regGprR9;
		UREG_R10: tValN2 = regGprR10;	UREG_R11: tValN2 = regGprR11;
		UREG_R12: tValN2 = regGprR12;	UREG_R13: tValN2 = regGprR13;
		UREG_R14: tValN2 = regGprR14;	UREG_R15: tValN2 = regGprR15;
		UREG_R16: tValN2 = regGprR16;	UREG_R17: tValN2 = regGprR17;
		UREG_R18: tValN2 = regGprR18;	UREG_R19: tValN2 = regGprR19;
		UREG_R20: tValN2 = regGprR20;	UREG_R21: tValN2 = regGprR21;
		UREG_R22: tValN2 = regGprR22;	UREG_R23: tValN2 = regGprR23;
		UREG_R24: tValN2 = regGprR24;	UREG_R25: tValN2 = regGprR25;
		UREG_R26: tValN2 = regGprR26;	UREG_R27: tValN2 = regGprR27;
		UREG_R28: tValN2 = regGprR28;	UREG_R29: tValN2 = regGprR29;
		UREG_R30: tValN2 = regGprR30;	UREG_R31: tValN2 = regGprR31;
		default:  tValN2 = UV64_XX;
	endcase
*/

	case(idRegS2)
		UREG_R0:  tValS2 = regGprR0;	UREG_R1:  tValS2 = regGprR1;
		UREG_R2:  tValS2 = regGprR2;	UREG_R3:  tValS2 = regGprR3;
		UREG_R4:  tValS2 = regGprR4;	UREG_R5:  tValS2 = regGprR5;
		UREG_R6:  tValS2 = regGprR6;	UREG_R7:  tValS2 = regGprR7;
		UREG_R8:  tValS2 = regGprR8;	UREG_R9:  tValS2 = regGprR9;
		UREG_R10: tValS2 = regGprR10;	UREG_R11: tValS2 = regGprR11;
		UREG_R12: tValS2 = regGprR12;	UREG_R13: tValS2 = regGprR13;
		UREG_R14: tValS2 = regGprR14;	UREG_R15: tValS2 = regGprR15;
		UREG_R16: tValS2 = regGprR16;	UREG_R17: tValS2 = regGprR17;
		UREG_R18: tValS2 = regGprR18;	UREG_R19: tValS2 = regGprR19;
		UREG_R20: tValS2 = regGprR20;	UREG_R21: tValS2 = regGprR21;
		UREG_R22: tValS2 = regGprR22;	UREG_R23: tValS2 = regGprR23;
		UREG_R24: tValS2 = regGprR24;	UREG_R25: tValS2 = regGprR25;
		UREG_R26: tValS2 = regGprR26;	UREG_R27: tValS2 = regGprR27;
		UREG_R28: tValS2 = regGprR28;	UREG_R29: tValS2 = regGprR29;
		UREG_R30: tValS2 = regGprR30;	UREG_R31: tValS2 = regGprR31;

		UREG_PCW: tValS2 = idNextPc;	UREG_PCL: tValS2 = idNextPc;
		UREG_MR_IMM: tValS2 = idImm2;	UREG_ZZR: tValS2 = 0;

		default:  tValS2 = UV64_XX;
	endcase

	case(idRegT2)
		UREG_R0:  tValT2 = regGprR0;	UREG_R1:  tValT2 = regGprR1;
		UREG_R2:  tValT2 = regGprR2;	UREG_R3:  tValT2 = regGprR3;
		UREG_R4:  tValT2 = regGprR4;	UREG_R5:  tValT2 = regGprR5;
		UREG_R6:  tValT2 = regGprR6;	UREG_R7:  tValT2 = regGprR7;
		UREG_R8:  tValT2 = regGprR8;	UREG_R9:  tValT2 = regGprR9;
		UREG_R10: tValT2 = regGprR10;	UREG_R11: tValT2 = regGprR11;
		UREG_R12: tValT2 = regGprR12;	UREG_R13: tValT2 = regGprR13;
		UREG_R14: tValT2 = regGprR14;	UREG_R15: tValT2 = regGprR15;
		UREG_R16: tValT2 = regGprR16;	UREG_R17: tValT2 = regGprR17;
		UREG_R18: tValT2 = regGprR18;	UREG_R19: tValT2 = regGprR19;
		UREG_R20: tValT2 = regGprR20;	UREG_R21: tValT2 = regGprR21;
		UREG_R22: tValT2 = regGprR22;	UREG_R23: tValT2 = regGprR23;
		UREG_R24: tValT2 = regGprR24;	UREG_R25: tValT2 = regGprR25;
		UREG_R26: tValT2 = regGprR26;	UREG_R27: tValT2 = regGprR27;
		UREG_R28: tValT2 = regGprR28;	UREG_R29: tValT2 = regGprR29;
		UREG_R30: tValT2 = regGprR30;	UREG_R31: tValT2 = regGprR31;

		UREG_PCW: tValT2 = idNextPc;	UREG_PCL: tValT2 = idNextPc;
		UREG_MR_IMM: tValT2 = idImm2;	UREG_ZZR: tValT2 = 0;

		default:  tValT2 = UV64_XX;
	endcase

/*
	case(idRegN3)
		UREG_R0:  tValN3 = regGprR0;	UREG_R1:  tValN3 = regGprR1;
		UREG_R2:  tValN3 = regGprR2;	UREG_R3:  tValN3 = regGprR3;
		UREG_R4:  tValN3 = regGprR4;	UREG_R5:  tValN3 = regGprR5;
		UREG_R6:  tValN3 = regGprR6;	UREG_R7:  tValN3 = regGprR7;
		UREG_R8:  tValN3 = regGprR8;	UREG_R9:  tValN3 = regGprR9;
		UREG_R10: tValN3 = regGprR10;	UREG_R11: tValN3 = regGprR11;
		UREG_R12: tValN3 = regGprR12;	UREG_R13: tValN3 = regGprR13;
		UREG_R14: tValN3 = regGprR14;	UREG_R15: tValN3 = regGprR15;
		UREG_R16: tValN3 = regGprR16;	UREG_R17: tValN3 = regGprR17;
		UREG_R18: tValN3 = regGprR18;	UREG_R19: tValN3 = regGprR19;
		UREG_R20: tValN3 = regGprR20;	UREG_R21: tValN3 = regGprR21;
		UREG_R22: tValN3 = regGprR22;	UREG_R23: tValN3 = regGprR23;
		UREG_R24: tValN3 = regGprR24;	UREG_R25: tValN3 = regGprR25;
		UREG_R26: tValN3 = regGprR26;	UREG_R27: tValN3 = regGprR27;
		UREG_R28: tValN3 = regGprR28;	UREG_R29: tValN3 = regGprR29;
		UREG_R30: tValN3 = regGprR30;	UREG_R31: tValN3 = regGprR31;
		default:  tValN3 = UV64_XX;
	endcase
*/

	case(idRegS3)
		UREG_R0:  tValS3 = regGprR0;	UREG_R1:  tValS3 = regGprR1;
		UREG_R2:  tValS3 = regGprR2;	UREG_R3:  tValS3 = regGprR3;
		UREG_R4:  tValS3 = regGprR4;	UREG_R5:  tValS3 = regGprR5;
		UREG_R6:  tValS3 = regGprR6;	UREG_R7:  tValS3 = regGprR7;
		UREG_R8:  tValS3 = regGprR8;	UREG_R9:  tValS3 = regGprR9;
		UREG_R10: tValS3 = regGprR10;	UREG_R11: tValS3 = regGprR11;
		UREG_R12: tValS3 = regGprR12;	UREG_R13: tValS3 = regGprR13;
		UREG_R14: tValS3 = regGprR14;	UREG_R15: tValS3 = regGprR15;
		UREG_R16: tValS3 = regGprR16;	UREG_R17: tValS3 = regGprR17;
		UREG_R18: tValS3 = regGprR18;	UREG_R19: tValS3 = regGprR19;
		UREG_R20: tValS3 = regGprR20;	UREG_R21: tValS3 = regGprR21;
		UREG_R22: tValS3 = regGprR22;	UREG_R23: tValS3 = regGprR23;
		UREG_R24: tValS3 = regGprR24;	UREG_R25: tValS3 = regGprR25;
		UREG_R26: tValS3 = regGprR26;	UREG_R27: tValS3 = regGprR27;
		UREG_R28: tValS3 = regGprR28;	UREG_R29: tValS3 = regGprR29;
		UREG_R30: tValS3 = regGprR30;	UREG_R31: tValS3 = regGprR31;

		UREG_PCW: tValS3 = idNextPc;	UREG_PCL: tValS3 = idNextPc;
		UREG_MR_IMM: tValS3 = idImm3;	UREG_ZZR: tValS3 = 0;

		default:  tValS3 = UV64_XX;
	endcase

	case(idRegT3)
		UREG_R0:  tValT3 = regGprR0;	UREG_R1:  tValT3 = regGprR1;
		UREG_R2:  tValT3 = regGprR2;	UREG_R3:  tValT3 = regGprR3;
		UREG_R4:  tValT3 = regGprR4;	UREG_R5:  tValT3 = regGprR5;
		UREG_R6:  tValT3 = regGprR6;	UREG_R7:  tValT3 = regGprR7;
		UREG_R8:  tValT3 = regGprR8;	UREG_R9:  tValT3 = regGprR9;
		UREG_R10: tValT3 = regGprR10;	UREG_R11: tValT3 = regGprR11;
		UREG_R12: tValT3 = regGprR12;	UREG_R13: tValT3 = regGprR13;
		UREG_R14: tValT3 = regGprR14;	UREG_R15: tValT3 = regGprR15;
		UREG_R16: tValT3 = regGprR16;	UREG_R17: tValT3 = regGprR17;
		UREG_R18: tValT3 = regGprR18;	UREG_R19: tValT3 = regGprR19;
		UREG_R20: tValT3 = regGprR20;	UREG_R21: tValT3 = regGprR21;
		UREG_R22: tValT3 = regGprR22;	UREG_R23: tValT3 = regGprR23;
		UREG_R24: tValT3 = regGprR24;	UREG_R25: tValT3 = regGprR25;
		UREG_R26: tValT3 = regGprR26;	UREG_R27: tValT3 = regGprR27;
		UREG_R28: tValT3 = regGprR28;	UREG_R29: tValT3 = regGprR29;
		UREG_R30: tValT3 = regGprR30;	UREG_R31: tValT3 = regGprR31;

		UREG_PCW: tValT3 = idNextPc;	UREG_PCL: tValT3 = idNextPc;
		UREG_MR_IMM: tValT3 = idImm3;	UREG_ZZR: tValT3 = 0;

		default:  tValT3 = UV64_XX;
	endcase


	if(wgprEnableLane4)
	begin

/*
	case(idRegN4)
		UREG_R0:  tValN4 = regGprR0;	UREG_R1:  tValN4 = regGprR1;
		UREG_R2:  tValN4 = regGprR2;	UREG_R3:  tValN4 = regGprR3;
		UREG_R4:  tValN4 = regGprR4;	UREG_R5:  tValN4 = regGprR5;
		UREG_R6:  tValN4 = regGprR6;	UREG_R7:  tValN4 = regGprR7;
		UREG_R8:  tValN4 = regGprR8;	UREG_R9:  tValN4 = regGprR9;
		UREG_R10: tValN4 = regGprR10;	UREG_R11: tValN4 = regGprR11;
		UREG_R12: tValN4 = regGprR12;	UREG_R13: tValN4 = regGprR13;
		UREG_R14: tValN4 = regGprR14;	UREG_R15: tValN4 = regGprR15;
		UREG_R16: tValN4 = regGprR16;	UREG_R17: tValN4 = regGprR17;
		UREG_R18: tValN4 = regGprR18;	UREG_R19: tValN4 = regGprR19;
		UREG_R20: tValN4 = regGprR20;	UREG_R21: tValN4 = regGprR21;
		UREG_R22: tValN4 = regGprR22;	UREG_R23: tValN4 = regGprR23;
		UREG_R24: tValN4 = regGprR24;	UREG_R25: tValN4 = regGprR25;
		UREG_R26: tValN4 = regGprR26;	UREG_R27: tValN4 = regGprR27;
		UREG_R28: tValN4 = regGprR28;	UREG_R29: tValN4 = regGprR29;
		UREG_R30: tValN4 = regGprR30;	UREG_R31: tValN4 = regGprR31;
		default:  tValN4 = UV64_XX;
	endcase
*/

	case(idRegS4)
		UREG_R0:  tValS4 = regGprR0;	UREG_R1:  tValS4 = regGprR1;
		UREG_R2:  tValS4 = regGprR2;	UREG_R3:  tValS4 = regGprR3;
		UREG_R4:  tValS4 = regGprR4;	UREG_R5:  tValS4 = regGprR5;
		UREG_R6:  tValS4 = regGprR6;	UREG_R7:  tValS4 = regGprR7;
		UREG_R8:  tValS4 = regGprR8;	UREG_R9:  tValS4 = regGprR9;
		UREG_R10: tValS4 = regGprR10;	UREG_R11: tValS4 = regGprR11;
		UREG_R12: tValS4 = regGprR12;	UREG_R13: tValS4 = regGprR13;
		UREG_R14: tValS4 = regGprR14;	UREG_R15: tValS4 = regGprR15;
		UREG_R16: tValS4 = regGprR16;	UREG_R17: tValS4 = regGprR17;
		UREG_R18: tValS4 = regGprR18;	UREG_R19: tValS4 = regGprR19;
		UREG_R20: tValS4 = regGprR20;	UREG_R21: tValS4 = regGprR21;
		UREG_R22: tValS4 = regGprR22;	UREG_R23: tValS4 = regGprR23;
		UREG_R24: tValS4 = regGprR24;	UREG_R25: tValS4 = regGprR25;
		UREG_R26: tValS4 = regGprR26;	UREG_R27: tValS4 = regGprR27;
		UREG_R28: tValS4 = regGprR28;	UREG_R29: tValS4 = regGprR29;
		UREG_R30: tValS4 = regGprR30;	UREG_R31: tValS4 = regGprR31;

		UREG_PCW: tValS4 = idNextPc;	UREG_PCL: tValS4 = idNextPc;
		UREG_MR_IMM: tValS4 = idImm4;	UREG_ZZR: tValS4 = 0;

		default:  tValS4 = UV64_XX;
	endcase

	case(idRegT4)
		UREG_R0:  tValT4 = regGprR0;	UREG_R1:  tValT4 = regGprR1;
		UREG_R2:  tValT4 = regGprR2;	UREG_R3:  tValT4 = regGprR3;
		UREG_R4:  tValT4 = regGprR4;	UREG_R5:  tValT4 = regGprR5;
		UREG_R6:  tValT4 = regGprR6;	UREG_R7:  tValT4 = regGprR7;
		UREG_R8:  tValT4 = regGprR8;	UREG_R9:  tValT4 = regGprR9;
		UREG_R10: tValT4 = regGprR10;	UREG_R11: tValT4 = regGprR11;
		UREG_R12: tValT4 = regGprR12;	UREG_R13: tValT4 = regGprR13;
		UREG_R14: tValT4 = regGprR14;	UREG_R15: tValT4 = regGprR15;
		UREG_R16: tValT4 = regGprR16;	UREG_R17: tValT4 = regGprR17;
		UREG_R18: tValT4 = regGprR18;	UREG_R19: tValT4 = regGprR19;
		UREG_R20: tValT4 = regGprR20;	UREG_R21: tValT4 = regGprR21;
		UREG_R22: tValT4 = regGprR22;	UREG_R23: tValT4 = regGprR23;
		UREG_R24: tValT4 = regGprR24;	UREG_R25: tValT4 = regGprR25;
		UREG_R26: tValT4 = regGprR26;	UREG_R27: tValT4 = regGprR27;
		UREG_R28: tValT4 = regGprR28;	UREG_R29: tValT4 = regGprR29;
		UREG_R30: tValT4 = regGprR30;	UREG_R31: tValT4 = regGprR31;

		UREG_PCW: tValT4 = idNextPc;	UREG_PCL: tValT4 = idNextPc;
		UREG_MR_IMM: tValT4 = idImm4;	UREG_ZZR: tValT4 = 0;

		default:  tValT4 = UV64_XX;
	endcase

	end

	if(wgprEnableLane5)
	begin

/*
	case(idRegN5)
		UREG_R0:  tValN5 = regGprR0;	UREG_R1:  tValN5 = regGprR1;
		UREG_R2:  tValN5 = regGprR2;	UREG_R3:  tValN5 = regGprR3;
		UREG_R4:  tValN5 = regGprR4;	UREG_R5:  tValN5 = regGprR5;
		UREG_R6:  tValN5 = regGprR6;	UREG_R7:  tValN5 = regGprR7;
		UREG_R8:  tValN5 = regGprR8;	UREG_R9:  tValN5 = regGprR9;
		UREG_R10: tValN5 = regGprR10;	UREG_R11: tValN5 = regGprR11;
		UREG_R12: tValN5 = regGprR12;	UREG_R13: tValN5 = regGprR13;
		UREG_R14: tValN5 = regGprR14;	UREG_R15: tValN5 = regGprR15;
		UREG_R16: tValN5 = regGprR16;	UREG_R17: tValN5 = regGprR17;
		UREG_R18: tValN5 = regGprR18;	UREG_R19: tValN5 = regGprR19;
		UREG_R20: tValN5 = regGprR20;	UREG_R21: tValN5 = regGprR21;
		UREG_R22: tValN5 = regGprR22;	UREG_R23: tValN5 = regGprR23;
		UREG_R24: tValN5 = regGprR24;	UREG_R25: tValN5 = regGprR25;
		UREG_R26: tValN5 = regGprR26;	UREG_R27: tValN5 = regGprR27;
		UREG_R28: tValN5 = regGprR28;	UREG_R29: tValN5 = regGprR29;
		UREG_R30: tValN5 = regGprR30;	UREG_R31: tValN5 = regGprR31;
		default:  tValN5 = UV64_XX;
	endcase
*/

	case(idRegS5)
		UREG_R0:  tValS5 = regGprR0;	UREG_R1:  tValS5 = regGprR1;
		UREG_R2:  tValS5 = regGprR2;	UREG_R3:  tValS5 = regGprR3;
		UREG_R4:  tValS5 = regGprR4;	UREG_R5:  tValS5 = regGprR5;
		UREG_R6:  tValS5 = regGprR6;	UREG_R7:  tValS5 = regGprR7;
		UREG_R8:  tValS5 = regGprR8;	UREG_R9:  tValS5 = regGprR9;
		UREG_R10: tValS5 = regGprR10;	UREG_R11: tValS5 = regGprR11;
		UREG_R12: tValS5 = regGprR12;	UREG_R13: tValS5 = regGprR13;
		UREG_R14: tValS5 = regGprR14;	UREG_R15: tValS5 = regGprR15;
		UREG_R16: tValS5 = regGprR16;	UREG_R17: tValS5 = regGprR17;
		UREG_R18: tValS5 = regGprR18;	UREG_R19: tValS5 = regGprR19;
		UREG_R20: tValS5 = regGprR20;	UREG_R21: tValS5 = regGprR21;
		UREG_R22: tValS5 = regGprR22;	UREG_R23: tValS5 = regGprR23;
		UREG_R24: tValS5 = regGprR24;	UREG_R25: tValS5 = regGprR25;
		UREG_R26: tValS5 = regGprR26;	UREG_R27: tValS5 = regGprR27;
		UREG_R28: tValS5 = regGprR28;	UREG_R29: tValS5 = regGprR29;
		UREG_R30: tValS5 = regGprR30;	UREG_R31: tValS5 = regGprR31;

		UREG_PCW: tValS5 = idNextPc;	UREG_PCL: tValS5 = idNextPc;
		UREG_MR_IMM: tValS5 = idImm5;	UREG_ZZR: tValS5 = 0;

		default:  tValS5 = UV64_XX;
	endcase

	case(idRegT5)
		UREG_R0:  tValT5 = regGprR0;	UREG_R1:  tValT5 = regGprR1;
		UREG_R2:  tValT5 = regGprR2;	UREG_R3:  tValT5 = regGprR3;
		UREG_R4:  tValT5 = regGprR4;	UREG_R5:  tValT5 = regGprR5;
		UREG_R6:  tValT5 = regGprR6;	UREG_R7:  tValT5 = regGprR7;
		UREG_R8:  tValT5 = regGprR8;	UREG_R9:  tValT5 = regGprR9;
		UREG_R10: tValT5 = regGprR10;	UREG_R11: tValT5 = regGprR11;
		UREG_R12: tValT5 = regGprR12;	UREG_R13: tValT5 = regGprR13;
		UREG_R14: tValT5 = regGprR14;	UREG_R15: tValT5 = regGprR15;
		UREG_R16: tValT5 = regGprR16;	UREG_R17: tValT5 = regGprR17;
		UREG_R18: tValT5 = regGprR18;	UREG_R19: tValT5 = regGprR19;
		UREG_R20: tValT5 = regGprR20;	UREG_R21: tValT5 = regGprR21;
		UREG_R22: tValT5 = regGprR22;	UREG_R23: tValT5 = regGprR23;
		UREG_R24: tValT5 = regGprR24;	UREG_R25: tValT5 = regGprR25;
		UREG_R26: tValT5 = regGprR26;	UREG_R27: tValT5 = regGprR27;
		UREG_R28: tValT5 = regGprR28;	UREG_R29: tValT5 = regGprR29;
		UREG_R30: tValT5 = regGprR30;	UREG_R31: tValT5 = regGprR31;

		UREG_PCW: tValT5 = idNextPc;	UREG_PCL: tValT5 = idNextPc;
		UREG_MR_IMM: tValT5 = idImm1;	UREG_ZZR: tValT5 = 0;

		default:  tValT5 = UV64_XX;
	endcase

	end


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

		case(idRegW1)
			UREG_FR0:	{nxtRegFprFR00, nxtRegFprFR01} = idValW1;
			UREG_FR1:	{nxtRegFprXF00, nxtRegFprXF01} = idValW1;
			UREG_FR2:	{nxtRegFprFR02, nxtRegFprFR03} = idValW1;
			UREG_FR3:	{nxtRegFprXF02, nxtRegFprXF03} = idValW1;
			UREG_FR4:	{nxtRegFprFR04, nxtRegFprFR05} = idValW1;
			UREG_FR5:	{nxtRegFprXF04, nxtRegFprXF05} = idValW1;
			UREG_FR6:	{nxtRegFprFR06, nxtRegFprFR07} = idValW1;
			UREG_FR7:	{nxtRegFprXF06, nxtRegFprXF07} = idValW1;
			UREG_FR8:	{nxtRegFprFR08, nxtRegFprFR09} = idValW1;
			UREG_FR9:	{nxtRegFprXF08, nxtRegFprXF09} = idValW1;
			UREG_FR10:	{nxtRegFprFR10, nxtRegFprFR11} = idValW1;
			UREG_FR11:	{nxtRegFprXF10, nxtRegFprXF11} = idValW1;
			UREG_FR12:	{nxtRegFprFR12, nxtRegFprFR13} = idValW1;
			UREG_FR13:	{nxtRegFprXF12, nxtRegFprXF13} = idValW1;
			UREG_FR14:	{nxtRegFprFR14, nxtRegFprFR15} = idValW1;
			UREG_FR15:	{nxtRegFprXF14, nxtRegFprXF15} = idValW1;
			default:	begin end
		endcase

	end
	else
	begin

		case(idRegW1)
			UREG_FR0:	nxtRegFprFR00 = idValW1[31:0];
			UREG_FR1:	nxtRegFprFR01 = idValW1[31:0];
			UREG_FR2:	nxtRegFprFR02 = idValW1[31:0];
			UREG_FR3:	nxtRegFprFR03 = idValW1[31:0];
			UREG_FR4:	nxtRegFprFR04 = idValW1[31:0];
			UREG_FR5:	nxtRegFprFR05 = idValW1[31:0];
			UREG_FR6:	nxtRegFprFR06 = idValW1[31:0];
			UREG_FR7:	nxtRegFprFR07 = idValW1[31:0];
			UREG_FR8:	nxtRegFprFR08 = idValW1[31:0];
			UREG_FR9:	nxtRegFprFR09 = idValW1[31:0];
			UREG_FR10:	nxtRegFprFR10 = idValW1[31:0];
			UREG_FR11:	nxtRegFprFR11 = idValW1[31:0];
			UREG_FR12:	nxtRegFprFR12 = idValW1[31:0];
			UREG_FR13:	nxtRegFprFR13 = idValW1[31:0];
			UREG_FR14:	nxtRegFprFR14 = idValW1[31:0];
			UREG_FR15:	nxtRegFprFR15 = idValW1[31:0];

			UREG_XF0:	nxtRegFprXF00 = idValW1[31:0];
			UREG_XF1:	nxtRegFprXF01 = idValW1[31:0];
			UREG_XF2:	nxtRegFprXF02 = idValW1[31:0];
			UREG_XF3:	nxtRegFprXF03 = idValW1[31:0];
			UREG_XF4:	nxtRegFprXF04 = idValW1[31:0];
			UREG_XF5:	nxtRegFprXF05 = idValW1[31:0];
			UREG_XF6:	nxtRegFprXF06 = idValW1[31:0];
			UREG_XF7:	nxtRegFprXF07 = idValW1[31:0];
			UREG_XF8:	nxtRegFprXF08 = idValW1[31:0];
			UREG_XF9:	nxtRegFprXF09 = idValW1[31:0];
			UREG_XF10:	nxtRegFprXF10 = idValW1[31:0];
			UREG_XF11:	nxtRegFprXF11 = idValW1[31:0];
			UREG_XF12:	nxtRegFprXF12 = idValW1[31:0];
			UREG_XF13:	nxtRegFprXF13 = idValW1[31:0];
			UREG_XF14:	nxtRegFprXF14 = idValW1[31:0];
			UREG_XF15:	nxtRegFprXF15 = idValW1[31:0];

			default:	begin end
		endcase

	end

end

always @(posedge clock)
begin
	regSrRB		<= nxtRegSrRB;
	regFprRB	<= nxtRegFprRB;

	if(regSrRB ^ nxtRegSrRB)
	begin
		regGprR0	<=	regGprR0B;		regGprR1	<=	regGprR1B;
		regGprR2	<=	regGprR2B;		regGprR3	<=	regGprR3B;
		regGprR4	<=	regGprR4B;		regGprR5	<=	regGprR5B;
		regGprR6	<=	regGprR6B;		regGprR7	<=	regGprR7B;
		regGprR16	<=	regGprR16B;		regGprR17	<=	regGprR17B;
		regGprR18	<=	regGprR18B;		regGprR19	<=	regGprR19B;
		regGprR20	<=	regGprR20B;		regGprR21	<=	regGprR21B;
		regGprR22	<=	regGprR22B;		regGprR23	<=	regGprR23B;

		regGprR0B	<=	regGprR0;		regGprR1B	<=	regGprR1;
		regGprR2B	<=	regGprR2;		regGprR3B	<=	regGprR3;
		regGprR4B	<=	regGprR4;		regGprR5B	<=	regGprR5;
		regGprR6B	<=	regGprR6;		regGprR7B	<=	regGprR7;
		regGprR16B	<=	regGprR16;		regGprR17B	<=	regGprR17;
		regGprR18B	<=	regGprR18;		regGprR19B	<=	regGprR19;
		regGprR20B	<=	regGprR20;		regGprR21B	<=	regGprR21;
		regGprR22B	<=	regGprR22;		regGprR23B	<=	regGprR23;

	end
	else
	begin

		if(wgprEnableLane5)
		begin

			regGprR0	<=
				(idRegW1==UREG_R0) ? idValW1:	(idRegW2==UREG_R0) ? idValW2:
				(idRegW3==UREG_R0) ? idValW3:	(idRegW4==UREG_R0) ? idValW4:
				(idRegW5==UREG_R0) ? idValW5:	regGprR0;
			regGprR1	<=
				(idRegW1==UREG_R1) ? idValW1:	(idRegW2==UREG_R1) ? idValW2:
				(idRegW3==UREG_R1) ? idValW3:	(idRegW4==UREG_R1) ? idValW4:
				(idRegW5==UREG_R1) ? idValW5:	regGprR1;
			regGprR2	<=
				(idRegW1==UREG_R2) ? idValW1:	(idRegW2==UREG_R2) ? idValW2:
				(idRegW3==UREG_R2) ? idValW3:	(idRegW4==UREG_R2) ? idValW4:
				(idRegW5==UREG_R2) ? idValW5:	regGprR2;
			regGprR3	<=
				(idRegW1==UREG_R3) ? idValW1:	(idRegW2==UREG_R3) ? idValW2:
				(idRegW3==UREG_R3) ? idValW3:	(idRegW4==UREG_R3) ? idValW4:
				(idRegW5==UREG_R3) ? idValW5:	regGprR3;

			regGprR4	<=
				(idRegW1==UREG_R4) ? idValW1:	(idRegW2==UREG_R4) ? idValW2:
				(idRegW3==UREG_R4) ? idValW3:	(idRegW4==UREG_R4) ? idValW4:
				(idRegW5==UREG_R4) ? idValW5:	regGprR4;
			regGprR5	<=
				(idRegW1==UREG_R5) ? idValW1:	(idRegW2==UREG_R5) ? idValW2:
				(idRegW3==UREG_R5) ? idValW3:	(idRegW4==UREG_R5) ? idValW4:
				(idRegW5==UREG_R5) ? idValW5:	regGprR5;
			regGprR6	<=
				(idRegW1==UREG_R6) ? idValW1:	(idRegW2==UREG_R6) ? idValW2:
				(idRegW3==UREG_R6) ? idValW3:	(idRegW4==UREG_R6) ? idValW4:
				(idRegW5==UREG_R6) ? idValW5:	regGprR6;
			regGprR7	<=
				(idRegW1==UREG_R7) ? idValW1:	(idRegW2==UREG_R7) ? idValW2:
				(idRegW3==UREG_R7) ? idValW3:	(idRegW4==UREG_R7) ? idValW4:
				(idRegW5==UREG_R7) ? idValW5:	regGprR7;


			regGprR8	<=
				(idRegW1==UREG_R8) ? idValW1:	(idRegW2==UREG_R8) ? idValW2:
				(idRegW3==UREG_R8) ? idValW3:	(idRegW4==UREG_R8) ? idValW4:
				(idRegW5==UREG_R8) ? idValW5:	regGprR8;
			regGprR9	<=
				(idRegW1==UREG_R9) ? idValW1:	(idRegW2==UREG_R9) ? idValW2:
				(idRegW3==UREG_R9) ? idValW3:	(idRegW4==UREG_R9) ? idValW4:
				(idRegW5==UREG_R9) ? idValW5:	regGprR9;
			regGprR10	<=
				(idRegW1==UREG_R10) ? idValW1:	(idRegW2==UREG_R10) ? idValW2:
				(idRegW3==UREG_R10) ? idValW3:	(idRegW4==UREG_R10) ? idValW4:
				(idRegW5==UREG_R10) ? idValW5:	regGprR10;
			regGprR11	<=
				(idRegW1==UREG_R11) ? idValW1:	(idRegW2==UREG_R11) ? idValW2:
				(idRegW3==UREG_R11) ? idValW3:	(idRegW4==UREG_R11) ? idValW4:
				(idRegW5==UREG_R11) ? idValW5:	regGprR11;

			regGprR12	<=
				(idRegW1==UREG_R12) ? idValW1:	(idRegW2==UREG_R12) ? idValW2:
				(idRegW3==UREG_R12) ? idValW3:	(idRegW4==UREG_R12) ? idValW4:
				(idRegW5==UREG_R12) ? idValW5:	regGprR12;
			regGprR13	<=
				(idRegW1==UREG_R13) ? idValW1:	(idRegW2==UREG_R13) ? idValW2:
				(idRegW3==UREG_R13) ? idValW3:	(idRegW4==UREG_R13) ? idValW4:
				(idRegW5==UREG_R13) ? idValW5:	regGprR13;
			regGprR14	<=
				(idRegW1==UREG_R14) ? idValW1:	(idRegW2==UREG_R14) ? idValW2:
				(idRegW3==UREG_R14) ? idValW3:	(idRegW4==UREG_R14) ? idValW4:
				(idRegW5==UREG_R14) ? idValW5:	regGprR14;
			regGprR15	<=
				(idRegW1==UREG_R15) ? idValW1:	(idRegW2==UREG_R15) ? idValW2:
				(idRegW3==UREG_R15) ? idValW3:	(idRegW4==UREG_R15) ? idValW4:
				(idRegW5==UREG_R15) ? idValW5:	regGprR15;

			regGprR16	<=
				(idRegW1==UREG_R16) ? idValW1:	(idRegW2==UREG_R16) ? idValW2:
				(idRegW3==UREG_R16) ? idValW3:	(idRegW4==UREG_R16) ? idValW4:
				(idRegW5==UREG_R16) ? idValW5:	regGprR16;
			regGprR17	<=
				(idRegW1==UREG_R17) ? idValW1:	(idRegW2==UREG_R17) ? idValW2:
				(idRegW3==UREG_R17) ? idValW3:	(idRegW4==UREG_R17) ? idValW4:
				(idRegW5==UREG_R17) ? idValW5:	regGprR17;
			regGprR18	<=
				(idRegW1==UREG_R18) ? idValW1:	(idRegW2==UREG_R18) ? idValW2:
				(idRegW3==UREG_R18) ? idValW3:	(idRegW4==UREG_R18) ? idValW4:
				(idRegW5==UREG_R18) ? idValW5:	regGprR18;
			regGprR19	<=
				(idRegW1==UREG_R19) ? idValW1:	(idRegW2==UREG_R19) ? idValW2:
				(idRegW3==UREG_R19) ? idValW3:	(idRegW4==UREG_R19) ? idValW4:
				(idRegW5==UREG_R19) ? idValW5:	regGprR19;

			regGprR20	<=
				(idRegW1==UREG_R20) ? idValW1:	(idRegW2==UREG_R20) ? idValW2:
				(idRegW3==UREG_R20) ? idValW3:	(idRegW4==UREG_R20) ? idValW4:
				(idRegW5==UREG_R20) ? idValW5:	regGprR20;
			regGprR21	<=
				(idRegW1==UREG_R21) ? idValW1:	(idRegW2==UREG_R21) ? idValW2:
				(idRegW3==UREG_R21) ? idValW3:	(idRegW4==UREG_R21) ? idValW4:
				(idRegW5==UREG_R21) ? idValW5:	regGprR21;
			regGprR22	<=
				(idRegW1==UREG_R22) ? idValW1:	(idRegW2==UREG_R22) ? idValW2:
				(idRegW3==UREG_R22) ? idValW3:	(idRegW4==UREG_R22) ? idValW4:
				(idRegW5==UREG_R22) ? idValW5:	regGprR22;
			regGprR23	<=
				(idRegW1==UREG_R23) ? idValW1:	(idRegW2==UREG_R23) ? idValW2:
				(idRegW3==UREG_R23) ? idValW3:	(idRegW4==UREG_R23) ? idValW4:
				(idRegW5==UREG_R23) ? idValW5:	regGprR23;

			regGprR24	<=
				(idRegW1==UREG_R24) ? idValW1:	(idRegW2==UREG_R24) ? idValW2:
				(idRegW3==UREG_R24) ? idValW3:	(idRegW4==UREG_R24) ? idValW4:
				(idRegW5==UREG_R24) ? idValW5:	regGprR24;
			regGprR25	<=
				(idRegW1==UREG_R25) ? idValW1:	(idRegW2==UREG_R25) ? idValW2:
				(idRegW3==UREG_R25) ? idValW3:	(idRegW4==UREG_R25) ? idValW4:
				(idRegW5==UREG_R25) ? idValW5:	regGprR25;
			regGprR26	<=
				(idRegW1==UREG_R26) ? idValW1:	(idRegW2==UREG_R26) ? idValW2:
				(idRegW3==UREG_R26) ? idValW3:	(idRegW4==UREG_R26) ? idValW4:
				(idRegW5==UREG_R26) ? idValW5:	regGprR26;
			regGprR27	<=
				(idRegW1==UREG_R27) ? idValW1:	(idRegW2==UREG_R27) ? idValW2:
				(idRegW3==UREG_R27) ? idValW3:	(idRegW4==UREG_R27) ? idValW4:
				(idRegW5==UREG_R27) ? idValW5:	regGprR27;

			regGprR28	<=
				(idRegW1==UREG_R28) ? idValW1:	(idRegW2==UREG_R28) ? idValW2:
				(idRegW3==UREG_R28) ? idValW3:	(idRegW4==UREG_R28) ? idValW4:
				(idRegW5==UREG_R28) ? idValW5:	regGprR28;
			regGprR29	<=
				(idRegW1==UREG_R29) ? idValW1:	(idRegW2==UREG_R29) ? idValW2:
				(idRegW3==UREG_R29) ? idValW3:	(idRegW4==UREG_R29) ? idValW4:
				(idRegW5==UREG_R29) ? idValW5:	regGprR29;
			regGprR30	<=
				(idRegW1==UREG_R30) ? idValW1:	(idRegW2==UREG_R30) ? idValW2:
				(idRegW3==UREG_R30) ? idValW3:	(idRegW4==UREG_R30) ? idValW4:
				(idRegW5==UREG_R30) ? idValW5:	regGprR30;
			regGprR31	<=
				(idRegW1==UREG_R31) ? idValW1:	(idRegW2==UREG_R31) ? idValW2:
				(idRegW3==UREG_R31) ? idValW3:	(idRegW4==UREG_R31) ? idValW4:
				(idRegW5==UREG_R31) ? idValW5:	regGprR31;

		end
		else
		begin

			regGprR0	<=
				(idRegW1==UREG_R0) ? idValW1:	(idRegW2==UREG_R0) ? idValW2:
				(idRegW3==UREG_R0) ? idValW3:	regGprR0;
			regGprR1	<=
				(idRegW1==UREG_R1) ? idValW1:	(idRegW2==UREG_R1) ? idValW2:
				(idRegW3==UREG_R1) ? idValW3:	regGprR1;
			regGprR2	<=
				(idRegW1==UREG_R2) ? idValW1:	(idRegW2==UREG_R2) ? idValW2:
				(idRegW3==UREG_R2) ? idValW3:	regGprR2;
			regGprR3	<=
				(idRegW1==UREG_R3) ? idValW1:	(idRegW2==UREG_R3) ? idValW2:
				(idRegW3==UREG_R3) ? idValW3:	regGprR3;

			regGprR4	<=
				(idRegW1==UREG_R4) ? idValW1:	(idRegW2==UREG_R4) ? idValW2:
				(idRegW3==UREG_R4) ? idValW3:	regGprR4;
			regGprR5	<=
				(idRegW1==UREG_R5) ? idValW1:	(idRegW2==UREG_R5) ? idValW2:
				(idRegW3==UREG_R5) ? idValW3:	regGprR5;
			regGprR6	<=
				(idRegW1==UREG_R6) ? idValW1:	(idRegW2==UREG_R6) ? idValW2:
				(idRegW3==UREG_R6) ? idValW3:	regGprR6;
			regGprR7	<=
				(idRegW1==UREG_R7) ? idValW1:	(idRegW2==UREG_R7) ? idValW2:
				(idRegW3==UREG_R7) ? idValW3:	regGprR7;


			regGprR8	<=
				(idRegW1==UREG_R8) ? idValW1:	(idRegW2==UREG_R8) ? idValW2:
				(idRegW3==UREG_R8) ? idValW3:	regGprR8;
			regGprR9	<=
				(idRegW1==UREG_R9) ? idValW1:	(idRegW2==UREG_R9) ? idValW2:
				(idRegW3==UREG_R9) ? idValW3:	regGprR9;
			regGprR10	<=
				(idRegW1==UREG_R10) ? idValW1:	(idRegW2==UREG_R10) ? idValW2:
				(idRegW3==UREG_R10) ? idValW3:	regGprR10;
			regGprR11	<=
				(idRegW1==UREG_R11) ? idValW1:	(idRegW2==UREG_R11) ? idValW2:
				(idRegW3==UREG_R11) ? idValW3:	regGprR11;

			regGprR12	<=
				(idRegW1==UREG_R12) ? idValW1:	(idRegW2==UREG_R12) ? idValW2:
				(idRegW3==UREG_R12) ? idValW3:	regGprR12;
			regGprR13	<=
				(idRegW1==UREG_R13) ? idValW1:	(idRegW2==UREG_R13) ? idValW2:
				(idRegW3==UREG_R13) ? idValW3:	regGprR13;
			regGprR14	<=
				(idRegW1==UREG_R14) ? idValW1:	(idRegW2==UREG_R14) ? idValW2:
				(idRegW3==UREG_R14) ? idValW3:	regGprR14;
			regGprR15	<=
				(idRegW1==UREG_R15) ? idValW1:	(idRegW2==UREG_R15) ? idValW2:
				(idRegW3==UREG_R15) ? idValW3:	regGprR15;

			regGprR16	<=
				(idRegW1==UREG_R16) ? idValW1:	(idRegW2==UREG_R16) ? idValW2:
				(idRegW3==UREG_R16) ? idValW3:	regGprR16;
			regGprR17	<=
				(idRegW1==UREG_R17) ? idValW1:	(idRegW2==UREG_R17) ? idValW2:
				(idRegW3==UREG_R17) ? idValW3:	regGprR17;
			regGprR18	<=
				(idRegW1==UREG_R18) ? idValW1:	(idRegW2==UREG_R18) ? idValW2:
				(idRegW3==UREG_R18) ? idValW3:	regGprR18;
			regGprR19	<=
				(idRegW1==UREG_R19) ? idValW1:	(idRegW2==UREG_R19) ? idValW2:
				(idRegW3==UREG_R19) ? idValW3:	regGprR19;

			regGprR20	<=
				(idRegW1==UREG_R20) ? idValW1:	(idRegW2==UREG_R20) ? idValW2:
				(idRegW3==UREG_R20) ? idValW3:	regGprR20;
			regGprR21	<=
				(idRegW1==UREG_R21) ? idValW1:	(idRegW2==UREG_R21) ? idValW2:
				(idRegW3==UREG_R21) ? idValW3:	regGprR21;
			regGprR22	<=
				(idRegW1==UREG_R22) ? idValW1:	(idRegW2==UREG_R22) ? idValW2:
				(idRegW3==UREG_R22) ? idValW3:	regGprR22;
			regGprR23	<=
				(idRegW1==UREG_R23) ? idValW1:	(idRegW2==UREG_R23) ? idValW2:
				(idRegW3==UREG_R23) ? idValW3:	regGprR23;

			regGprR24	<=
				(idRegW1==UREG_R24) ? idValW1:	(idRegW2==UREG_R24) ? idValW2:
				(idRegW3==UREG_R24) ? idValW3:	regGprR24;
			regGprR25	<=
				(idRegW1==UREG_R25) ? idValW1:	(idRegW2==UREG_R25) ? idValW2:
				(idRegW3==UREG_R25) ? idValW3:	regGprR25;
			regGprR26	<=
				(idRegW1==UREG_R26) ? idValW1:	(idRegW2==UREG_R26) ? idValW2:
				(idRegW3==UREG_R26) ? idValW3:	regGprR26;
			regGprR27	<=
				(idRegW1==UREG_R27) ? idValW1:	(idRegW2==UREG_R27) ? idValW2:
				(idRegW3==UREG_R27) ? idValW3:	regGprR27;

			regGprR28	<=
				(idRegW1==UREG_R28) ? idValW1:	(idRegW2==UREG_R28) ? idValW2:
				(idRegW3==UREG_R28) ? idValW3:	regGprR28;
			regGprR29	<=
				(idRegW1==UREG_R29) ? idValW1:	(idRegW2==UREG_R29) ? idValW2:
				(idRegW3==UREG_R29) ? idValW3:	regGprR29;
			regGprR30	<=
				(idRegW1==UREG_R30) ? idValW1:	(idRegW2==UREG_R30) ? idValW2:
				(idRegW3==UREG_R30) ? idValW3:	regGprR30;
			regGprR31	<=
				(idRegW1==UREG_R31) ? idValW1:	(idRegW2==UREG_R31) ? idValW2:
				(idRegW3==UREG_R31) ? idValW3:	regGprR31;

		end

		regGprR0B	<=	(idRegW1==UREG_R0B) ? idValW1:	regGprR0B;
		regGprR1B	<=	(idRegW1==UREG_R1B) ? idValW1:	regGprR1B;
		regGprR2B	<=	(idRegW1==UREG_R2B) ? idValW1:	regGprR2B;
		regGprR3B	<=	(idRegW1==UREG_R3B) ? idValW1:	regGprR3B;
		regGprR4B	<=	(idRegW1==UREG_R4B) ? idValW1:	regGprR4B;
		regGprR5B	<=	(idRegW1==UREG_R5B) ? idValW1:	regGprR5B;
		regGprR6B	<=	(idRegW1==UREG_R6B) ? idValW1:	regGprR6B;
		regGprR7B	<=	(idRegW1==UREG_R7B) ? idValW1:	regGprR7B;

		regGprR16B	<=	(idRegW1==UREG_R16B) ? idValW1:	regGprR16B;
		regGprR17B	<=	(idRegW1==UREG_R17B) ? idValW1:	regGprR17B;
		regGprR18B	<=	(idRegW1==UREG_R18B) ? idValW1:	regGprR18B;
		regGprR19B	<=	(idRegW1==UREG_R19B) ? idValW1:	regGprR19B;
		regGprR20B	<=	(idRegW1==UREG_R20B) ? idValW1:	regGprR20B;
		regGprR21B	<=	(idRegW1==UREG_R21B) ? idValW1:	regGprR21B;
		regGprR22B	<=	(idRegW1==UREG_R22B) ? idValW1:	regGprR22B;
		regGprR23B	<=	(idRegW1==UREG_R23B) ? idValW1:	regGprR23B;
	end

	if(regFprRB^nxtRegFprRB)
	begin
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
	end
	else
	begin
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
	end

	regSr		<= (idRegW1==UREG_SR    ) ? idValW1 : exNextSr2;
	regPr		<= (idRegW1==UREG_PR    ) ? idValW1 : exNextPr2;
	regPc		<= (idRegW1==UREG_PC    ) ? idValW1 : exNextPc2;
	regMach		<= (idRegW1==UREG_MACL  ) ? idValW1 : exNextMach2;
	regMacl		<= (idRegW1==UREG_MACH  ) ? idValW1 : exNextMacl2;
	regSp		<= (idRegW1==UREG_R15   ) ? idValW1 : exNextSp2;
	regGbr		<= (idRegW1==UREG_GBR   ) ? idValW1 : exNextGbr2;
	regVbr		<= (idRegW1==UREG_VBR   ) ? idValW1 : exNextVbr2;
	regSSr		<= (idRegW1==UREG_SSR   ) ? idValW1 : exNextSSr2;
	regSPc		<= (idRegW1==UREG_SPC   ) ? idValW1 : exNextSPc2;
	regSGr		<= (idRegW1==UREG_SGR   ) ? idValW1 : exNextSGr2;
	regFpul		<= (idRegW1==UREG_FPUL  ) ? idValW1 : exNextFpul2;
	regFpScr	<= (idRegW1==UREG_FPSCR ) ? idValW1 : exNextFpScr2;
end

endmodule
