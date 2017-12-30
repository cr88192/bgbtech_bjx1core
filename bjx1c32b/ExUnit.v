module ExUnit(clock, reset,
	extAddr,	extData,
	extOE,		extWR,
	extOK);

input clock;		//clock
input reset;		//reset

/* External Memory */
output[31:0]	extAddr;		//external memory address
inout[31:0]		extData;		//external memory data (read/write)
output			extOE;			//external output enable
output			extWR;			//external write
input			extOK;			//external access is OK

/* Baseline Registers */
reg[63:0]		regMac;			//MACH:MACL
reg[31:0]		regPr;			//PR
reg[31:0]		regSGr;			//SGR (R15)
reg[31:0]		regFpul;		//FPUL
reg[31:0]		regFpScr;		//FPSCR

reg[31:0]		regSr;			//SR
reg[31:0]		regGbr;			//GBR
reg[31:0]		regVbr;			//VBR
reg[31:0]		regSSr;			//SSR
reg[31:0]		regSPc;			//SPC
reg[31:0]		regPc;			//PC


/* IF */
reg[31:0]	regIfPc;			//PC, Fetch
wire[47:0]	regIfPcVal;			//PC Instruction Value
wire		regIfPcOK;

reg[31:0]	memIfPcData;
wire[31:0]	memIfPcAddr;
wire		memIfPcOE;
reg			memIfPcOK;

IcTile2 icf(clock, reset,
	regIfPc,
	regIfPcVal, regIfPcOK,
	memIfPcData,
	memIfPcAddr, memIfPcOE, memIfPcOK);

/* ID */

reg[47:0]	regIdPcVal;			//PC Instruction Value
reg[15:0]	regIdCsFl;			//Control State Flags

reg[31:0]	regIdPc;			//ID PC Value
reg[31:0]	regIdSr;			//ID SR Value

wire[6:0] idRegN;
wire[6:0] idRegS;
wire[6:0] idRegT;
wire[31:0] idImm;
wire[3:0] idStepPc;
wire[7:0] idUCmd;

wire[31:0] idRegValN;
wire[31:0] idRegValS;
wire[31:0] idRegValT;

DecOp2 dec(clock, regIdPcVal, regIdCsFl,
	idRegN, idRegS, idRegT, idImm,
	idStepPc, idUCmd); 

RegGPR gpr(clock, reset,
	idRegS, idRegValS,
	idRegT, idRegValT,
	idRegN, idRegValN,
	exRegO, exRegValO,
	regIdSrVal);

wire[63:0]		idRegFpValN;
wire[63:0]		idRegFpValS;
wire[63:0]		idRegFpValT;
reg[1:0]		idRegFpMode;
reg[1:0]		idRegFpStMode;
reg[31:0]		idFpNextFpul;

RegFPR fpr(clock, reset,
	idRegS,			idRegFpValS,
	idRegT,			idRegFpValT,
	idRegN,			idRegFpValN,
	exRegFpO,		exRegFpValO,
	idRegFpMode,	regIdCsFl,
	idRegFpStMode,
	regFpul,		idFpNextFpul
	);

reg[31:0]	idRegValN2;
reg[31:0]	idRegValS2;
reg[31:0]	idRegValT2;

/* EX */

reg[47:0]	regExPcVal;			//PC Instruction Value
reg[15:0]	regExCsFl;			//Control State Flags

reg[31:0]	regExPc;			//ID PC Value
reg[31:0]	regExSr;			//ID SR Value

reg[6:0]	exRegN;
reg[6:0]	exRegS;
reg[6:0]	exRegT;
reg[31:0]	exImm;
reg[3:0]	exStepPc;
reg[7:0]	exUCmd;

reg[31:0]	exRegValN;
reg[31:0]	exRegValS;
reg[31:0]	exRegValT;

reg[63:0]	exRegFpValN;
reg[63:0]	exRegFpValS;
reg[63:0]	exRegFpValT;

wire[6:0]	exRegO;
wire[31:0]	exRegValO;

wire[31:0]	exMemAddr;			//memory address
wire[31:0]	exMemData;			//memory data (write)
wire		exMemLoad;			//load from memory
wire		exMemStore;			//store to memory

wire[31:0]	exNextSr;			//SR in
wire[31:0]	exNextPr;			//PR in
wire[31:0]	exNextPc;			//PC in
wire[63:0]	exNextMac;			//MACH:MACL

wire[31:0]	exNextGbr;			//GBR
wire[31:0]	exNextVbr;			//VBR
wire[31:0]	exNextSSr;			//SSR
wire[31:0]	exNextSPc;			//SPC
wire[31:0]	exNextSGr;			//SGR (R15)


ExOp2	exOp(clock, reset,
	exUCmd,		exStepPc,
	exRegS,		exRegValS,
	exRegT,		exRegValT,
	exRegN,		exRegValN,
	exImm,
	exRegO,		exRegValO,
	exMemAddr,	exMemData,
	exMemLoad,	exMemStore,
	regSr,		exNextSr,
	regPr,		exNextPr,
	regExPc,	exNextPc,
	regMac,		exNextMac

	regGbr,		exNextGbr,
	regVbr,		exNextVbr,
	regSSr,		exNextSSr,
	regSPc,		exNextSPc,
	regSGr,		exNextSGr
	);

reg[31:0]	exNextSr2;			//SR in
reg[31:0]	exNextPr2;			//PR in
reg[31:0]	exNextPc2;			//PC in
reg[63:0]	exNextMac2;			//MACH:MACL

reg[31:0]	exNextGbr2;			//GBR
reg[31:0]	exNextVbr2;			//VBR
reg[31:0]	exNextSSr2;			//SSR
reg[31:0]	exNextSPc2;			//SPC
reg[31:0]	exNextSGr2;			//SGR (Saved R15)
wire[31:0]	exNextFpul2;		//
wire[31:0]	exNextFpScr2;		//

wire[6:0]	exRegFpO;
wire[31:0]	exRegFpValO;
wire[1:0]	exRegFpModeO;

wire[31:0]	exFpNextSr;			//
wire[31:0]	exNextFpul;			//
wire[31:0]	exNextFpScr;		//

FpuFpD	exFpu(clock,
	exUCmd,		idRegFpMode,
	exRegS,		exRegFpValS,
	exRegT,		exRegFpValT,
	exRegN,		exRegFpValN,
	exRegFpO,	exRegFpValO,	exRegFpModeO,
	regSr,		exFpNextSr,
	regFpul,	exFpNextFpul,
	regFpScr,	exFpNextFpScr
	);


reg[31:0]	tRegGenIdPr;

always @ (clock)
begin
	regIdCsFl=0;
	regIdCsFl[0]=1;					//LE
	regIdCsFl[1]=regFpScr[19];		//FPSCR.PR
	regIdCsFl[2]=regFpScr[20];		//FPSCR.SZ
	regIdCsFl[3]=regFpScr[21];		//FPSCR.FR
	regIdCsFl[4]=regFpScr[24];		//FPSCR.VE
	regIdCsFl[5]=regSr[31];			//SR.JQ
	regIdCsFl[6]=regSr[12];			//SR.DQ

	idRegFpMode = 0;
	idRegFpStMode = exRegFpModeO;

	if(regFpScr[19])
		idRegFpMode = 1;
	if(regFpScr[20])
		idRegFpMode = 1;

	tRegGenIdPr = regIdPc + (idStepPc + 2);

	case(idRegS)
		UREG_MACH:	idRegValS2 = regMac[63:32];
		UREG_MACL:	idRegValS2 = regMac[31: 0];
		UREG_PR:	idRegValS2 = regPr;
		UREG_SGR:	idRegValS2 = regSGr;
		UREG_FPUL:	idRegValS2 = regFpul;
		UREG_FPSCR:	idRegValS2 = regFpScr;

		UREG_SR:	idRegValS2 = regSr;
		UREG_GBR:	idRegValS2 = regGbr;
		UREG_VBR:	idRegValS2 = regVbr;
		UREG_SSR:	idRegValS2 = regSSr;
		UREG_SPC:	idRegValS2 = regSPc;
		UREG_PC:	idRegValS2 = regPc;

		UREG_PCW:	idRegValS2 = tRegGenIdPr +	{idRegImm[30:0], 1'b0};
		UREG_PCL: begin
			idRegValS2[1:0] = 0;
			idRegValS2[31:2] = tRegGenIdPr + idRegImm[29:0];
		end

		UREG_MR_IMM:		idRegValS2 = idRegImm;
		UREG_MR_MEMDEC:		idRegValS2 = 0;
		UREG_MR_MEMINC:		idRegValS2 = 0;
		UREG_ZZR:			idRegValS2 = 0;

		default:	idRegValS2 = idRegValS;
	endcase

	case(idRegT)
		UREG_MACH:	idRegValT2 = regMac[63:32];
		UREG_MACL:	idRegValT2 = regMac[31: 0];
		UREG_PR:	idRegValT2 = regPr;
		UREG_SGR:	idRegValT2 = regSGr;
		UREG_FPUL:	idRegValT2 = regFpul;
		UREG_FPSCR:	idRegValT2 = regFpScr;

		UREG_SR:	idRegValT2 = regSr;
		UREG_GBR:	idRegValT2 = regGbr;
		UREG_VBR:	idRegValT2 = regVbr;
		UREG_SSR:	idRegValT2 = regSSr;
		UREG_SPC:	idRegValT2 = regSPc;
		UREG_PC:	idRegValT2 = regPc;

		UREG_PCW:	idRegValT2 = tRegGenIdPr +	{idRegImm[30:0], 1'b0};
		UREG_PCL: begin
			idRegValT2[1:0] = 0;
			idRegValT2[31:2] = tRegGenIdPr + idRegImm[29:0];
		end

		UREG_MR_IMM:		idRegValT2 = idRegImm;
		UREG_MR_MEMDEC:		idRegValT2 = 0;
		UREG_MR_MEMINC:		idRegValT2 = 0;
		UREG_ZZR:			idRegValT2 = 0;

		default:	idRegValT2 = idRegValS;
	endcase
	
	idRegValN2 = idRegValN;
//	idRegValT2 = idRegValT;

	exNextSr2 = exNextSr;
	exNextPr2 = exNextPr;
	exNextPc2 = exNextPc;
	exNextMac2 = exNextMac;
	exNextGbr2 = exNextGbr;
	exNextVbr2 = exNextVbr;
	exNextSSr2 = exNextSSr;
	exNextSPc2 = exNextSPc;
	exNextSGr2 = exNextSGr;

	exNextFpul2 = idFpNextFpul;
	exNextFpScr2 = exFpNextFpScr;

	case(exRegO)
		UREG_MACH:	exNextMac2[63:32]	= exRegValO;
		UREG_MACL:	exNextMac2[31: 0]	= exRegValO;
		UREG_PR:	exNextPr2			= exRegValO;
		UREG_SGR:	exNextSGr2			= exRegValO;
		UREG_FPUL:	exNextFpul2			= exRegValO;
		UREG_FPSCR:	exNextFpScr2		= exRegValO;
		UREG_SR:	exNextSr2			= exRegValO;
		UREG_GBR:	exNextGbr2			= exRegValO;
		UREG_VBR:	exNextVbr2			= exRegValO;
		UREG_SSR:	exNextSSr2			= exRegValO;
		UREG_SPC:	exNextSPc2			= exRegValO;
		UREG_PC:	exNextPc2			= exRegValO;

		default:	begin end
	endcase

end


always @ (posedge clock)
begin

/* Common */
	regSr		<= exNextSr2;			//SR in
	regPr		<= exNextPr2;			//PR in
	regPc		<= exNextPc2;			//PC in
	regMac		<= exNextMac2;			//MACH:MACL

	regGbr		<= exNextGbr2;
	regVbr		<= exNextVbr2;
	regSSr		<= exNextSSr2;
	regSPc		<= exNextSPc2;
	regSGr		<= exNextSGr2;
	
	regFpul		<= exNextFpul2;
	regFpScr	<= exNextFpScr2;


/* IF */
	regIfPc		<= exNextPc2;

/* ID */
	regIdPc		<= regIfPc;
	regIdSr		<= regIfSr;
	regIdPcVal	<= regIfPcVal;

/* EX */
	regExPcVal	<= regIdPcVal;
	regExCsFl	<= regIdCsFl;
	regExPc		<= regIdPc;
	regExSr		<= regIdSr;
	exRegN		<= idRegN;
	exRegS		<= idRegS;
	exRegT		<= idRegT;
	exImm		<= idImm;
	exStepPc	<= idStepPc;
	exUCmd		<= idUCmd;
	exRegValN	<= idRegValN2;
	exRegValS	<= idRegValS2;
	exRegValT	<= idRegValT2;

end

endmodule
