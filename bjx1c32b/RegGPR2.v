/*
GPR Bank

Reads from Rs, Rt, and Rm.
Writes to Rn.
 */

`include "CoreDefs.v"

module RegGPR2(
	/* verilator lint_off UNUSED */
	clock,		reset,
	regIdRs,	regValRs,
	regIdRt,	regValRt,
	regIdRn,	regValRn,
	regIdRo,	regValRo,
	regSrVal,	regExHold,
	idImm,
	
	oregSr,		exNextSr2,
	oregPr,		exNextPr2,
	oregPc,		exNextPc2,
	oregMac,	exNextMac2,
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

output[31:0]	regValRs;
output[31:0]	regValRt;
output[31:0]	regValRn;

input[6:0]		regIdRo;
input[31:0]		regValRo;

input[31:0]		regSrVal;

input			regExHold;

input[31:0]		idImm;

input[31:0]		exNextSr2;			//SR in
input[31:0]		exNextPr2;			//PR in
input[31:0]		exNextPc2;			//PC in
input[63:0]		exNextMac2;			//MACH:MACL
input[31:0]		exNextGbr2;			//GBR
input[31:0]		exNextVbr2;			//VBR
input[31:0]		exNextSSr2;			//SSR
input[31:0]		exNextSPc2;			//SPC
input[31:0]		exNextSGr2;			//SGR (Saved R15)
input[31:0]		exNextFpul2;		//
input[31:0]		exNextFpScr2;		//
input[31:0]		exNextSp2;			//

output[63:0]	oregMac;			//MACH:MACL
output[31:0]	oregPr;			//PR
output[31:0]	oregSGr;			//SGR (Saved R15)
output[31:0]	oregFpul;		//FPUL
output[31:0]	oregFpScr;		//FPSCR
output[31:0]	oregSr;			//SR
output[31:0]	oregGbr;			//GBR
output[31:0]	oregVbr;			//VBR
output[31:0]	oregSSr;			//SSR
output[31:0]	oregSPc;			//SPC
output[31:0]	oregPc;			//PC
output[31:0]	oregSp;			//SP/GR (R15)

reg[63:0]		regMac;			//MACH:MACL
reg[31:0]		regPr;			//PR
reg[31:0]		regSGr;			//SGR (Saved R15)
reg[31:0]		regFpul;		//FPUL
reg[31:0]		regFpScr;		//FPSCR
reg[31:0]		regSr;			//SR
reg[31:0]		regGbr;			//GBR
reg[31:0]		regVbr;			//VBR
reg[31:0]		regSSr;			//SSR
reg[31:0]		regSPc;			//SPC
reg[31:0]		regPc;			//PC
reg[31:0]		regSp;			//SP/GR (R15)

assign		oregMac		= regMac;
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
reg[31:0]	tRegValRs;
reg[31:0]	tRegValRt;
reg[31:0]	tRegValRn;


//reg[31:0]	regGprLA[7:0];
//reg[31:0]	regGprLB[7:0];
//reg[31:0]	regGprH[7:0];

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
// reg[31:0]	regGprR15;

// reg[31:0]	regGprR7A;

/*
reg[31:0]	nxtRegGprR0A;
reg[31:0]	nxtRegGprR1A;
reg[31:0]	nxtRegGprR2A;
reg[31:0]	nxtRegGprR3A;
reg[31:0]	nxtRegGprR4A;
reg[31:0]	nxtRegGprR5A;
reg[31:0]	nxtRegGprR6A;
reg[31:0]	nxtRegGprR7A;

reg[31:0]	nxtRegGprR0B;
reg[31:0]	nxtRegGprR1B;
reg[31:0]	nxtRegGprR2B;
reg[31:0]	nxtRegGprR3B;
reg[31:0]	nxtRegGprR4B;
reg[31:0]	nxtRegGprR5B;
reg[31:0]	nxtRegGprR6B;
reg[31:0]	nxtRegGprR7B;

reg[31:0]	nxtRegGprR8;
reg[31:0]	nxtRegGprR9;
reg[31:0]	nxtRegGprR10;
reg[31:0]	nxtRegGprR11;
reg[31:0]	nxtRegGprR12;
reg[31:0]	nxtRegGprR13;
reg[31:0]	nxtRegGprR14;
*/

assign regValRs = tRegValRs;
assign regValRt = tRegValRt;
assign regValRn = tRegValRn;

always @*
begin
	tRegValRs=UV32_XX;
	tRegValRt=UV32_XX;
	tRegValRn=UV32_XX;

//	regSrRB=regSrVal[29];
//	regSrRB=0;
	nxtRegSrRB=regSrVal[29];

	case(regIdRs)
/*
		UREG_R0:	tRegValRs=regSrRB?regGprR0B:regGprR0A;
		UREG_R1:	tRegValRs=regSrRB?regGprR1B:regGprR1A;
		UREG_R2:	tRegValRs=regSrRB?regGprR2B:regGprR2A;
		UREG_R3:	tRegValRs=regSrRB?regGprR3B:regGprR3A;
		UREG_R4:	tRegValRs=regSrRB?regGprR4B:regGprR4A;
		UREG_R5:	tRegValRs=regSrRB?regGprR5B:regGprR5A;
		UREG_R6:	tRegValRs=regSrRB?regGprR6B:regGprR6A;
		UREG_R7:	tRegValRs=regSrRB?regGprR7B:regGprR7A;
*/

// /*
		UREG_R0:	tRegValRs=regGprR0A;
		UREG_R1:	tRegValRs=regGprR1A;
		UREG_R2:	tRegValRs=regGprR2A;
		UREG_R3:	tRegValRs=regGprR3A;
		UREG_R4:	tRegValRs=regGprR4A;
		UREG_R5:	tRegValRs=regGprR5A;
		UREG_R6:	tRegValRs=regGprR6A;
		UREG_R7:	tRegValRs=regGprR7A;
// */

		UREG_R8:	tRegValRs=regGprR8;
		UREG_R9:	tRegValRs=regGprR9;
		UREG_R10:	tRegValRs=regGprR10;
		UREG_R11:	tRegValRs=regGprR11;
		UREG_R12:	tRegValRs=regGprR12;
		UREG_R13:	tRegValRs=regGprR13;
		UREG_R14:	tRegValRs=regGprR14;
		UREG_R15:	tRegValRs=regSp;

//		UREG_PCW:	tRegValRs = tRegGenIdPr +	{idImm[30:0], 1'b0};
//		UREG_PCL: begin
//			idRegValS2[1:0] = 0;
//			idRegValS2[31:2] = tRegGenIdPr[31:2] + idImm[29:0];
//		end

		UREG_MR_IMM:	tRegValRs = idImm;
		UREG_ZZR:	tRegValRs = 0;

		UREG_MACH:	tRegValRs = regMac[63:32];
		UREG_MACL:	tRegValRs = regMac[31: 0];
		UREG_PR:	tRegValRs = regPr;
		UREG_SGR:	tRegValRs = regSGr;
		UREG_FPUL:	tRegValRs = regFpul;
		UREG_FPSCR:	tRegValRs = regFpScr;

		UREG_SR:	tRegValRs = regSr;
		UREG_GBR:	tRegValRs = regGbr;
		UREG_VBR:	tRegValRs = regVbr;
		UREG_SSR:	tRegValRs = regSSr;
		UREG_SPC:	tRegValRs = regSPc;
		UREG_PC:	tRegValRs = regPc;

		default:	tRegValRs=UV32_XX;
	endcase

	case(regIdRt)
		UREG_R0:	tRegValRt=regGprR0A;
		UREG_R1:	tRegValRt=regGprR1A;
		UREG_R2:	tRegValRt=regGprR2A;
		UREG_R3:	tRegValRt=regGprR3A;
		UREG_R4:	tRegValRt=regGprR4A;
		UREG_R5:	tRegValRt=regGprR5A;
		UREG_R6:	tRegValRt=regGprR6A;
		UREG_R7:	tRegValRt=regGprR7A;

		UREG_R8:	tRegValRt=regGprR8;
		UREG_R9:	tRegValRt=regGprR9;
		UREG_R10:	tRegValRt=regGprR10;
		UREG_R11:	tRegValRt=regGprR11;
		UREG_R12:	tRegValRt=regGprR12;
		UREG_R13:	tRegValRt=regGprR13;
		UREG_R14:	tRegValRt=regGprR14;
		UREG_R15:	tRegValRt=regSp;

		UREG_MR_IMM:	tRegValRt = idImm;
		UREG_ZZR:	tRegValRt = 0;

//		UREG_MACH:	tRegValRt = regMac[63:32];
//		UREG_MACL:	tRegValRt = regMac[31: 0];
//		UREG_PR:	tRegValRt = regPr;
//		UREG_SGR:	tRegValRt = regSGr;
//		UREG_FPUL:	tRegValRt = regFpul;
//		UREG_FPSCR:	tRegValRt = regFpScr;

//		UREG_SR:	tRegValRt = regSr;
//		UREG_GBR:	tRegValRt = regGbr;
//		UREG_VBR:	tRegValRt = regVbr;
//		UREG_SSR:	tRegValRt = regSSr;
//		UREG_SPC:	tRegValRt = regSPc;
//		UREG_PC:	tRegValRt = regPc;

		default:	tRegValRt=UV32_XX;
	endcase

	case(regIdRn)
		UREG_R0:	tRegValRn=regGprR0A;
		UREG_R1:	tRegValRn=regGprR1A;
		UREG_R2:	tRegValRn=regGprR2A;
		UREG_R3:	tRegValRn=regGprR3A;
		UREG_R4:	tRegValRn=regGprR4A;
		UREG_R5:	tRegValRn=regGprR5A;
		UREG_R6:	tRegValRn=regGprR6A;
		UREG_R7:	tRegValRn=regGprR7A;

		UREG_R8:	tRegValRn=regGprR8;
		UREG_R9:	tRegValRn=regGprR9;
		UREG_R10:	tRegValRn=regGprR10;
		UREG_R11:	tRegValRn=regGprR11;
		UREG_R12:	tRegValRn=regGprR12;
		UREG_R13:	tRegValRn=regGprR13;
		UREG_R14:	tRegValRn=regGprR14;
		UREG_R15:	tRegValRn=regSp;

		UREG_GBR:	tRegValRn = regGbr;

		default:	tRegValRn=UV32_XX;
	endcase


/*
	nxtRegGprR0A = regGprR0A;
	nxtRegGprR1A = regGprR1A;
	nxtRegGprR2A = regGprR2A;
	nxtRegGprR3A = regGprR3A;
	nxtRegGprR4A = regGprR4A;
	nxtRegGprR5A = regGprR5A;
	nxtRegGprR6A = regGprR6A;
	nxtRegGprR7A = regGprR7A;

	nxtRegGprR0B = regGprR0B;
	nxtRegGprR1B = regGprR1B;
	nxtRegGprR2B = regGprR2B;
	nxtRegGprR3B = regGprR3B;
	nxtRegGprR4B = regGprR4B;
	nxtRegGprR5B = regGprR5B;
	nxtRegGprR6B = regGprR6B;
	nxtRegGprR7B = regGprR7B;

	nxtRegGprR8  = regGprR8 ;
	nxtRegGprR9  = regGprR9 ;
	nxtRegGprR10 = regGprR10;
	nxtRegGprR11 = regGprR11;
	nxtRegGprR12 = regGprR12;
	nxtRegGprR13 = regGprR13;
	nxtRegGprR14 = regGprR14;

	case(regIdRn)
		UREG_R0:	nxtRegGprR0A=regValRo;
		UREG_R1:	nxtRegGprR1A=regValRo;
		UREG_R2:	nxtRegGprR2A=regValRo;
		UREG_R3:	nxtRegGprR3A=regValRo;
		UREG_R4:	nxtRegGprR4A=regValRo;
		UREG_R5:	nxtRegGprR5A=regValRo;
		UREG_R6:	nxtRegGprR6A=regValRo;
		UREG_R7:	nxtRegGprR7A=regValRo;

		UREG_R8:	nxtRegGprR8 =regValRo;
		UREG_R9:	nxtRegGprR9 =regValRo;
		UREG_R10:	nxtRegGprR10=regValRo;
		UREG_R11:	nxtRegGprR11=regValRo;
		UREG_R12:	nxtRegGprR12=regValRo;
		UREG_R13:	nxtRegGprR13=regValRo;
		UREG_R14:	nxtRegGprR14=regValRo;

		default:	tRegValRn=0;
	endcase
*/

end

always @ (posedge clock)
begin

/*
	regGprR0A	<= nxtRegGprR0A;
	regGprR1A	<= nxtRegGprR1A;
	regGprR2A	<= nxtRegGprR2A;
	regGprR3A	<= nxtRegGprR3A;
	regGprR4A	<= nxtRegGprR4A;
	regGprR5A	<= nxtRegGprR5A;
	regGprR6A	<= nxtRegGprR6A;
	regGprR7A	<= nxtRegGprR7A;

	regGprR0B	<= nxtRegGprR0B;
	regGprR1B	<= nxtRegGprR1B;
	regGprR2B	<= nxtRegGprR2B;
	regGprR3B	<= nxtRegGprR3B;
	regGprR4B	<= nxtRegGprR4B;
	regGprR5B	<= nxtRegGprR5B;
	regGprR6B	<= nxtRegGprR6B;
	regGprR7B	<= nxtRegGprR7B;

	regGprR8	<= nxtRegGprR8;
	regGprR9	<= nxtRegGprR9;
	regGprR10	<= nxtRegGprR10;
	regGprR11	<= nxtRegGprR11;
	regGprR12	<= nxtRegGprR12;
	regGprR13	<= nxtRegGprR13;
	regGprR14	<= nxtRegGprR14;
//	regGprR15	<= nxtRegGprR15;
*/

/*
	regGprR0A <= (!regSrRB && (regIdRo==UREG_R0)) ? regValRo : regGprR0A;
	regGprR1A <= (!regSrRB && (regIdRo==UREG_R1)) ? regValRo : regGprR1A;
	regGprR2A <= (!regSrRB && (regIdRo==UREG_R2)) ? regValRo : regGprR2A;
	regGprR3A <= (!regSrRB && (regIdRo==UREG_R3)) ? regValRo : regGprR3A;
	regGprR4A <= (!regSrRB && (regIdRo==UREG_R4)) ? regValRo : regGprR4A;
	regGprR5A <= (!regSrRB && (regIdRo==UREG_R5)) ? regValRo : regGprR5A;
	regGprR6A <= (!regSrRB && (regIdRo==UREG_R6)) ? regValRo : regGprR6A;
	regGprR7A <= (!regSrRB && (regIdRo==UREG_R7)) ? regValRo : regGprR7A;
	
	regGprR0B <= (regSrRB && (regIdRo==UREG_R0)) ? regValRo : regGprR0B;
	regGprR1B <= (regSrRB && (regIdRo==UREG_R1)) ? regValRo : regGprR1B;
	regGprR2B <= (regSrRB && (regIdRo==UREG_R2)) ? regValRo : regGprR2B;
	regGprR3B <= (regSrRB && (regIdRo==UREG_R3)) ? regValRo : regGprR3B;
	regGprR4B <= (regSrRB && (regIdRo==UREG_R4)) ? regValRo : regGprR4B;
	regGprR5B <= (regSrRB && (regIdRo==UREG_R5)) ? regValRo : regGprR5B;
	regGprR6B <= (regSrRB && (regIdRo==UREG_R6)) ? regValRo : regGprR6B;
	regGprR7B <= (regSrRB && (regIdRo==UREG_R7)) ? regValRo : regGprR7B;

	regGprR8  <= (regIdRo==UREG_R8 ) ? regValRo : regGprR8 ;
	regGprR9  <= (regIdRo==UREG_R9 ) ? regValRo : regGprR9 ;
	regGprR10 <= (regIdRo==UREG_R10) ? regValRo : regGprR10;
	regGprR11 <= (regIdRo==UREG_R11) ? regValRo : regGprR11;
	regGprR12 <= (regIdRo==UREG_R12) ? regValRo : regGprR12;
	regGprR13 <= (regIdRo==UREG_R13) ? regValRo : regGprR13;
	regGprR14 <= (regIdRo==UREG_R14) ? regValRo : regGprR14;
*/

	regSrRB		<= nxtRegSrRB;
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
		regGprR0A <= (regIdRo==UREG_R0) ? regValRo : regGprR0A;
		regGprR1A <= (regIdRo==UREG_R1) ? regValRo : regGprR1A;
		regGprR2A <= (regIdRo==UREG_R2) ? regValRo : regGprR2A;
		regGprR3A <= (regIdRo==UREG_R3) ? regValRo : regGprR3A;
		regGprR4A <= (regIdRo==UREG_R4) ? regValRo : regGprR4A;
		regGprR5A <= (regIdRo==UREG_R5) ? regValRo : regGprR5A;
		regGprR6A <= (regIdRo==UREG_R6) ? regValRo : regGprR6A;
		regGprR7A <= (regIdRo==UREG_R7) ? regValRo : regGprR7A;

		regGprR0B <= (regIdRo==UREG_R0B) ? regValRo : regGprR0B;
		regGprR1B <= (regIdRo==UREG_R1B) ? regValRo : regGprR1B;
		regGprR2B <= (regIdRo==UREG_R2B) ? regValRo : regGprR2B;
		regGprR3B <= (regIdRo==UREG_R3B) ? regValRo : regGprR3B;
		regGprR4B <= (regIdRo==UREG_R4B) ? regValRo : regGprR4B;
		regGprR5B <= (regIdRo==UREG_R5B) ? regValRo : regGprR5B;
		regGprR6B <= (regIdRo==UREG_R6B) ? regValRo : regGprR6B;
		regGprR7B <= (regIdRo==UREG_R7B) ? regValRo : regGprR7B;
	end

	regGprR8  <= (regIdRo==UREG_R8 ) ? regValRo : regGprR8 ;
	regGprR9  <= (regIdRo==UREG_R9 ) ? regValRo : regGprR9 ;
	regGprR10 <= (regIdRo==UREG_R10) ? regValRo : regGprR10;
	regGprR11 <= (regIdRo==UREG_R11) ? regValRo : regGprR11;
	regGprR12 <= (regIdRo==UREG_R12) ? regValRo : regGprR12;
	regGprR13 <= (regIdRo==UREG_R13) ? regValRo : regGprR13;
	regGprR14 <= (regIdRo==UREG_R14) ? regValRo : regGprR14;


	if(reset)
	begin
	/* Common */
		regSr		<= 0;
		regPr		<= 0;
		regPc		<= 32'hA000_0000;
		regMac		<= 0;
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
/*
		tRegSr		<= exNextSr2;			//SR
		tRegPr		<= exNextPr2;			//PR
		tRegPc		<= exNextPc2;			//PC
		tRegMac		<= exNextMac2;			//MACH:MACL
		tRegSp		<= exNextSp2;			//SP
		tRegGbr		<= exNextGbr2;
		tRegVbr		<= exNextVbr2;
		tRegSSr		<= exNextSSr2;
		tRegSPc		<= exNextSPc2;
		tRegSGr		<= exNextSGr2;
		tRegFpul	<= exNextFpul2;
		tRegFpScr	<= exNextFpScr2;
*/

// /*
		regSr		<= (regIdRo==UREG_SR    ) ? regValRo : exNextSr2;
		regPr		<= (regIdRo==UREG_PR    ) ? regValRo : exNextPr2;
		regPc		<= (regIdRo==UREG_PC    ) ? regValRo : exNextPc2;
		regMac[31: 0]	<= (regIdRo==UREG_MACL) ? regValRo : exNextMac2[31: 0];
		regMac[63:32]	<= (regIdRo==UREG_MACH) ? regValRo : exNextMac2[63:32];
		regSp		<= (regIdRo==UREG_R15   ) ? regValRo : exNextSp2;
		regGbr		<= (regIdRo==UREG_GBR   ) ? regValRo : exNextGbr2;
		regVbr		<= (regIdRo==UREG_VBR   ) ? regValRo : exNextVbr2;
		regSSr		<= (regIdRo==UREG_SSR   ) ? regValRo : exNextSSr2;
		regSPc		<= (regIdRo==UREG_SPC   ) ? regValRo : exNextSPc2;
		regSGr		<= (regIdRo==UREG_SGR   ) ? regValRo : exNextSGr2;
		regFpul		<= (regIdRo==UREG_FPUL  ) ? regValRo : exNextFpul2;
		regFpScr	<= (regIdRo==UREG_FPSCR ) ? regValRo : exNextFpScr2;
// */

	end
end

endmodule
