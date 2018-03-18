/*
 * WJX1 Execute Unit
 * Pipeline: IF D1 D2 E1 E2 M1 M2 WB
 */
 
`include "CoreDefs.v"

`include "Dc2Tile.v"
`include "DcTile3.v"
`include "IcTile3.v"

`include "RegWGPR.v"
`include "DecWOp.v"

`include "ExOp64_3C.v"

module ExUnitW(
	/* verilator lint_off UNUSED */
	clock, reset,
	extAddr,	extData,
	extOE,		extWR,
	extOK,

	mmioAddr,	mmioData,
	mmioOE,		mmioWR,
	mmioOK
	);

input clock;		//clock
input reset;		//reset

/* External Memory */
output[31:0]	extAddr;		//external memory address
inout[127:0]	extData;		//external memory data (read/write)
output			extOE;			//external output enable
output			extWR;			//external write
input			extOK;			//external access is OK

/* External MMIO */
output[31:0]	mmioAddr;		//external memory address
inout[31:0]		mmioData;		//external memory data (read/write)
output			mmioOE;			//external output enable
output			mmioWR;			//external write
input[1:0]		mmioOK;			//external access is OK

assign			extAddr = 32'hZ;
assign			extData = 128'hZ;
assign			extOE = 0;
assign			extWR = 0;

// assign			mmioAddr = 0;
// assign			mmioData = 32'hZ;
// assign			mmioOE = 0;
// assign			mmioWR = 0;

assign			mmioAddr = dc2MmioAddr;
assign			mmioData = dc2MmioWR ? dc2MmioOutData : 32'hZ;
assign			mmioOE = dc2MmioOE;
assign			mmioWR = dc2MmioWR;
assign			dc2MmioOK = mmioOK;


wire[63:0]		regMach;		//MACH:MACL
wire[63:0]		regMacl;		//MACH:MACL
wire[63:0]		regPr;			//PR
wire[63:0]		regSGr;			//SGR (Saved R15)
wire[63:0]		regFpul;		//FPUL
wire[63:0]		regFpScr;		//FPSCR

wire[63:0]		regSr;			//SR
wire[63:0]		regGbr;			//GBR
wire[63:0]		regVbr;			//VBR
wire[63:0]		regSSr;			//SSR
wire[63:0]		regSPc;			//SPC
wire[63:0]		regPc;			//PC

wire[63:0]		regSp;			//SP/GR (R15)


reg[63:0]	exNextSr2;			//SR in
reg[63:0]	exNextPr2;			//PR in
reg[63:0]	exNextPc2;			//PC in
reg[63:0]	exNextMach2;			//MACH:MACL
reg[63:0]	exNextMacl2;			//MACH:MACL

reg[63:0]	exNextGbr2;			//GBR
reg[63:0]	exNextVbr2;			//VBR
reg[63:0]	exNextSSr2;			//SSR
reg[63:0]	exNextSPc2;			//SPC
reg[63:0]	exNextSGr2;			//SGR (Saved R15)
reg[63:0]	exNextFpul2;		//
reg[63:0]	exNextFpScr2;		//

reg[63:0]	exNextSp2;			//

reg			tRegExHold;				//Execution is held
reg[7:0]		regRstTok;
reg[7:0]		regNextRstTok;


/* L2 */

reg[63:0]	dc2RegInAddr;
reg[127:0]	dc2RegInData;
wire[127:0]	dc2RegOutData;
wire[1:0]	dc2RegOutOK;
reg			dc2RegInOE;
reg			dc2RegInWR;
reg[4:0]	dc2RegInOp;

reg[127:0]	dc2MemInData;
wire[127:0]	dc2MemOutData;
wire[31:0]	dc2MemAddr;
wire		dc2MemOE;
wire		dc2MemWR;
reg[1:0]	dc2MemOK;
//wire[1:0]	dc2MemOK;

reg[31:0]	dc2MmioInData;
wire[31:0]	dc2MmioOutData;
wire[31:0]	dc2MmioAddr;
wire		dc2MmioOE;
wire		dc2MmioWR;
//reg[1:0]	dc2MmioOK;
wire[1:0]	dc2MmioOK;

Dc2Tile		dcl2(
	clock,			reset,
	dc2RegInAddr,	dc2RegInData,
	dc2RegOutData,	dc2RegOutOK,
	dc2RegInOE,		dc2RegInWR,
	dc2RegInOp,
	dc2MemInData,	dc2MemOutData,		dc2MemAddr,
	dc2MemOE,		dc2MemWR,			dc2MemOK,
	dc2MmioInData,	dc2MmioOutData,		dc2MmioAddr,		
	dc2MmioOE,		dc2MmioWR,			dc2MmioOK
	);

/* DCache */

reg[63:0]	dcfRegInAddr;
reg[63:0]	dcfRegInData;
wire[63:0]	dcfRegOutData;
wire[1:0]	dcfRegOutOK;
reg			dcfRegInOE;
reg			dcfRegInWR;
reg[4:0]	dcfRegInOp;

reg[127:0]	dcfMemInData;
wire[127:0]	dcfMemOutData;
wire[63:0]	dcfMemPcAddr;
wire		dcfMemPcOE;
wire		dcfMemPcWR;
reg[1:0]	dcfMemPcOK;
wire[4:0]	dcfMemOp;

DcTile3 dcf(
	clock,			reset,
	dcfRegInData,	dcfRegOutData,
	dcfRegInAddr,	dcfRegOutOK,
	dcfRegInOE,		dcfRegInWR,
	dcfRegInOp,

	dcfMemInData,	dcfMemOutData,
	dcfMemPcAddr,	dcfMemPcOK,
	dcfMemPcOE,		dcfMemPcWR,
	dcfMemOp
	);


/* IF */
reg[63:0]	regIfPc;			//PC, Fetch
reg[63:0]	regIfSr;			//SR, Fetch
wire[127:0]	regIfPcVal;			//PC Instruction Value
wire[1:0]	regIfPcOK;

reg[127:0]	memIfPcData;
wire[63:0]	memIfPcAddr;
wire		memIfPcOE;
reg[1:0]	memIfPcOK;

IcTile3 icf(clock, reset,
	regIfPc,
	regIfPcVal, regIfPcOK,
	memIfPcData,
	memIfPcAddr, memIfPcOE, memIfPcOK);

reg[127:0]	regIfPcVal2;		//PC Instruction Value


/* D1, D2 */

reg[63:0]		regIdPc;
reg[63:0]		regIdSr;
reg[15:0]		regIdCsFl;

reg[127:0]		idIstrWord;

wire[6:0]		idRegN1;
wire[6:0]		idRegS1;
wire[6:0]		idRegT1;
wire[6:0]		idRegN2;
wire[6:0]		idRegS2;
wire[6:0]		idRegT2;
wire[6:0]		idRegN3;
wire[6:0]		idRegS3;
wire[6:0]		idRegT3;
wire[6:0]		idRegN4;
wire[6:0]		idRegS4;
wire[6:0]		idRegT4;
wire[6:0]		idRegN5;
wire[6:0]		idRegS5;
wire[6:0]		idRegT5;

wire[31:0]		idImm1;
wire[31:0]		idImm2;
wire[31:0]		idImm3;
wire[31:0]		idImm4;
wire[31:0]		idImm5;

wire[7:0]		idUCmd1;
wire[7:0]		idUCmd2;
wire[7:0]		idUCmd3;
wire[7:0]		idUCmd4;
wire[7:0]		idUCmd5;

wire			idStep;

DecWOp	decw(
	clock, idIstrWord, idStep,
	idRegN1, idRegS1, idRegT1, idImm1, idUCmd1,
	idRegN2, idRegS2, idRegT2, idImm2, idUCmd2,
	idRegN3, idRegS3, idRegT3, idImm3, idUCmd3,
	idRegN4, idRegS4, idRegT4, idImm4, idUCmd4,
	idRegN5, idRegS5, idRegT5, idImm5, idUCmd5);

wire[63:0]		idValN1;
wire[63:0]		idValS1;
wire[63:0]		idValT1;
wire[63:0]		idValN2;
wire[63:0]		idValS2;
wire[63:0]		idValT2;
wire[63:0]		idValN3;
wire[63:0]		idValS3;
wire[63:0]		idValT3;
wire[63:0]		idValN4;
wire[63:0]		idValS4;
wire[63:0]		idValT4;
wire[63:0]		idValN5;
wire[63:0]		idValS5;
wire[63:0]		idValT5;

reg[6:0]		idRegW1;
reg[6:0]		idRegW2;
reg[6:0]		idRegW3;
reg[6:0]		idRegW4;
reg[6:0]		idRegW5;

reg[63:0]		idValW1;
reg[63:0]		idValW2;
reg[63:0]		idValW3;
reg[63:0]		idValW4;
reg[63:0]		idValW5;

reg[63:0]		idNextPc;

wire[63:0]		idImmb1;
wire[63:0]		idImmb2;
wire[63:0]		idImmb3;
wire[63:0]		idImmb4;
wire[63:0]		idImmb5;

assign	idImmb1 = { idImm1[31]?32'hFFFFFFFF:32'h00000000, idImm1 };
assign	idImmb2 = { idImm2[31]?32'hFFFFFFFF:32'h00000000, idImm2 };
assign	idImmb3 = { idImm3[31]?32'hFFFFFFFF:32'h00000000, idImm3 };
assign	idImmb4 = { idImm4[31]?32'hFFFFFFFF:32'h00000000, idImm4 };
assign	idImmb5 = { idImm5[31]?32'hFFFFFFFF:32'h00000000, idImm5 };

RegWGPR	wgpr(
	clock, idNextPc, 
	idRegN1, idRegS1, idRegT1, idRegW1,
	idRegN2, idRegS2, idRegT2, idRegW2,
	idRegN3, idRegS3, idRegT3, idRegW3,
	idRegN4, idRegS4, idRegT4, idRegW4,
	idRegN5, idRegS5, idRegT5, idRegW5,
	idValN1, idValS1, idValT1, idValW1, idImmb1,
	idValN2, idValS2, idValT2, idValW2, idImmb2,
	idValN3, idValS3, idValT3, idValW3, idImmb3,
	idValN4, idValS4, idValT4, idValW4, idImmb4,
	idValN5, idValS5, idValT5, idValW5, idImmb5,

	regSr,		exNextSr2,
	regPr,		exNextPr2,
	regPc,		exNextPc2,
	regMach,	exNextMach2,
	regMacl,	exNextMacl2,
	regSp,		exNextSp2,
	regGbr,		exNextGbr2,
	regVbr,		exNextVbr2,
	regSSr,		exNextSSr2,
	regSPc,		exNextSPc2,
	regSGr,		exNextSGr2,
	regFpul,	exNextFpul2,
	regFpScr,	exNextFpScr2
	);

/* D2 */

reg[63:0]		regId2Pc;
reg[63:0]		regId2Sr;
reg[15:0]		regId2CsFl;

reg[127:0]		id2IstrWord;

reg[6:0]		id2RegN1;
reg[6:0]		id2RegS1;
reg[6:0]		id2RegT1;
reg[6:0]		id2RegN2;
reg[6:0]		id2RegS2;
reg[6:0]		id2RegT2;
reg[6:0]		id2RegN3;
reg[6:0]		id2RegS3;
reg[6:0]		id2RegT3;
reg[6:0]		id2RegN4;
reg[6:0]		id2RegS4;
reg[6:0]		id2RegT4;
reg[6:0]		id2RegN5;
reg[6:0]		id2RegS5;
reg[6:0]		id2RegT5;

reg[31:0]		id2Imm1;
reg[31:0]		id2Imm2;
reg[31:0]		id2Imm3;
reg[31:0]		id2Imm4;
reg[31:0]		id2Imm5;

reg[7:0]		id2UCmd1;
reg[7:0]		id2UCmd2;
reg[7:0]		id2UCmd3;
reg[7:0]		id2UCmd4;
reg[7:0]		id2UCmd5;

reg				id2Step;

reg[63:0]		id2ValN1;
reg[63:0]		id2ValS1;
reg[63:0]		id2ValT1;
reg[63:0]		id2ValN2;
reg[63:0]		id2ValS2;
reg[63:0]		id2ValT2;
reg[63:0]		id2ValN3;
reg[63:0]		id2ValS3;
reg[63:0]		id2ValT3;
reg[63:0]		id2ValN4;
reg[63:0]		id2ValS4;
reg[63:0]		id2ValT4;
reg[63:0]		id2ValN5;
reg[63:0]		id2ValS5;
reg[63:0]		id2ValT5;


/* E1, E2 */

reg[127:0]	regExPcVal;			//PC Instruction Value
reg[15:0]	regExCsFl;			//Control State Flags
reg[63:0]	tRegGenIdPc;		//next PC

reg[63:0]	regExPc;			//ID PC Value
reg[63:0]	regExSr;			//ID SR Value

wire[1:0]	exRegOutOK;
reg[3:0]	exStepPc;
reg[3:0]	exStepPc2;

reg[6:0]	ex1RegN;
reg[6:0]	ex1RegS;
reg[6:0]	ex1RegT;
wire[6:0]	ex1RegO;
reg[63:0]	ex1Imm;
reg[7:0]	ex1UCmd;
reg[63:0]	ex1RegValN;
reg[63:0]	ex1RegValS;
reg[63:0]	ex1RegValT;
wire[63:0]	ex1RegValO;

reg[6:0]	ex2RegN;
reg[6:0]	ex2RegS;
reg[6:0]	ex2RegT;
wire[6:0]	ex2RegO;
reg[63:0]	ex2Imm;
reg[7:0]	ex2UCmd;
reg[63:0]	ex2RegValN;
reg[63:0]	ex2RegValS;
reg[63:0]	ex2RegValT;
wire[63:0]	ex2RegValO;

reg[6:0]	ex3RegN;
reg[6:0]	ex3RegS;
reg[6:0]	ex3RegT;
wire[6:0]	ex3RegO;
reg[63:0]	ex3Imm;
reg[7:0]	ex3UCmd;
reg[63:0]	ex3RegValN;
reg[63:0]	ex3RegValS;
reg[63:0]	ex3RegValT;
wire[63:0]	ex3RegValO;

reg[6:0]	ex4RegN;
reg[6:0]	ex4RegS;
reg[6:0]	ex4RegT;
wire[6:0]	ex4RegO;
reg[63:0]	ex4Imm;
reg[7:0]	ex4UCmd;
reg[63:0]	ex4RegValN;
reg[63:0]	ex4RegValS;
reg[63:0]	ex4RegValT;
wire[63:0]	ex4RegValO;

reg[6:0]	ex5RegN;
reg[6:0]	ex5RegS;
reg[6:0]	ex5RegT;
wire[6:0]	ex5RegO;
reg[63:0]	ex5Imm;
reg[7:0]	ex5UCmd;
reg[63:0]	ex5RegValN;
reg[63:0]	ex5RegValS;
reg[63:0]	ex5RegValT;
wire[63:0]	ex5RegValO;

wire[63:0]	exMemAddr;			//memory address
wire[63:0]	exMemData;			//memory data (write)
wire		exMemLoad;			//load from memory
wire		exMemStore;			//store to memory
wire[4:0]	exMemOpMode;		//mem op mode
wire[7:0]	exMemOpCmd2;		//mem EX chain

wire[63:0]	exNextSr;			//SR in
wire[63:0]	exNextPr;			//PR in
wire[63:0]	exNextPc;			//PC in
wire[63:0]	exNextMach;			//MACH:MACL
wire[63:0]	exNextMacl;			//MACH:MACL

wire[63:0]	exNextGbr;			//GBR
wire[63:0]	exNextVbr;			//VBR
wire[63:0]	exNextSSr;			//SSR
wire[63:0]	exNextSPc;			//SPC
wire[63:0]	exNextSGr;			//SGR (R15)

wire[63:0]	exNextSp;			//SP out

ExOp64_3C exop1(
	clock,			reset,
	exStepPc,		tRegGenIdPc,
	exRegOutOK,

	ex1RegS,		ex1RegValS,
	ex1RegT,		ex1RegValT,
	ex1RegN,		ex1RegValN,
	ex1RegO,		ex1RegValO,
	ex1Imm,			ex1UCmd,

	ex2RegS,		ex2RegValS,
	ex2RegT,		ex2RegValT,
	ex2RegN,		ex2RegValN,
	ex2RegO,		ex2RegValO,
	ex2Imm,			ex2UCmd,

	ex3RegS,		ex3RegValS,
	ex3RegT,		ex3RegValT,
	ex3RegN,		ex3RegValN,
	ex3RegO,		ex3RegValO,
	ex3Imm,			ex3UCmd,

	ex4RegS,		ex4RegValS,
	ex4RegT,		ex4RegValT,
	ex4RegN,		ex4RegValN,
	ex4RegO,		ex4RegValO,
	ex4Imm,			ex4UCmd,

	ex5RegS,		ex5RegValS,
	ex5RegT,		ex5RegValT,
	ex5RegN,		ex5RegValN,
	ex5RegO,		ex5RegValO,
	ex5Imm,			ex5UCmd,

	exMemAddr,		exMemData,
	exMemLoad,		exMemStore,
	exMemOpMode,	exMemOpCmd2,

	regSr,			exNextSr,
	regPr,			exNextPr,
	regExPc,		exNextPc,
	regMach,		exNextMach,
	regMacl,		exNextMacl,
	regSp,			exNextSp,

	regGbr,			exNextGbr,
	regVbr,			exNextVbr,
	regSSr,			exNextSSr,
	regSPc,			exNextSPc,
	regSGr,			exNextSGr
	);

/* MA1 */
wire[6:0]	ma1RegO1;
wire[63:0]	ma1ValO1;
wire[6:0]	ma1RegO2;
wire[63:0]	ma1ValO2;
wire[6:0]	ma1RegO3;
wire[63:0]	ma1ValO3;
wire[6:0]	ma1RegO4;
wire[63:0]	ma1ValO4;
wire[6:0]	ma1RegO5;
wire[63:0]	ma1ValO5;

/* MA2 */
wire[6:0]	ma2RegO1;
wire[63:0]	ma2ValO1;
wire[6:0]	ma2RegO2;
wire[63:0]	ma2ValO2;
wire[6:0]	ma2RegO3;
wire[63:0]	ma2ValO3;
wire[6:0]	ma2RegO4;
wire[63:0]	ma2ValO4;
wire[6:0]	ma2RegO5;
wire[63:0]	ma2ValO5;


always @*
begin
	regIdCsFl=0;
	regIdCsFl[0]=1;					//LE
	regIdCsFl[1]=regFpScr[19];		//FPSCR.PR
	regIdCsFl[2]=regFpScr[20];		//FPSCR.SZ
	regIdCsFl[3]=regFpScr[21];		//FPSCR.FR
	regIdCsFl[4]=regFpScr[24];		//FPSCR.VE
	regIdCsFl[5]=regSr[31];			//SR.JQ
	regIdCsFl[6]=regSr[12];			//SR.DQ

	regNextRstTok=8'h55;
	if(reset)
		regNextRstTok=8'h00;

	tRegExHold		= 0;
	if(regIfPcOK!=UMEM_OK_OK)
		tRegExHold		= 1;
	
	if(exMemLoad||exMemStore)
	begin
		if(dcfRegOutOK!=UMEM_OK_OK)
			tRegExHold		= 1;
	end

	if(exRegOutOK==UMEM_OK_HOLD)
			tRegExHold		= 1;

	dc2MemInData	= 0;				//STUB
	dc2MemOK		= UMEM_OK_READY;	//STUB
	dc2MmioInData	= 0;				//STUB
//	dc2MmioOK		= UMEM_OK_READY;	//STUB

//	dcfMemPcOK		= UMEM_OK_READY;
//	memIfPcOK		= UMEM_OK_READY;

	idNextPc = regIdPc + 16;
	tRegGenIdPc = regIfPc + 8;
	exStepPc = 4;

	exNextSp2 = exNextSp;
	exNextFpScr2 = regFpScr;
	exNextFpul2 = regFpul;

	exNextSr2 = exNextSr;
	exNextPr2 = exNextPr;
	exNextPc2 = exNextPc;
	exNextMach2 = exNextMach;
	exNextMacl2 = exNextMacl;
	exNextGbr2 = exNextGbr;
	exNextVbr2 = exNextVbr;
	exNextSSr2 = exNextSSr;
	exNextSPc2 = exNextSPc;
	exNextSGr2 = exNextSGr;

	regIfPcVal2 = regIfPcVal;

end

always @ (posedge clock)
begin

	regRstTok <= regNextRstTok;

	dcfRegInAddr	<= exMemAddr;
	dcfRegInData	<= exMemData;
	dcfRegInOE		<= exMemLoad;
	dcfRegInWR		<= exMemStore;
	dcfRegInOp		<= exMemOpMode;

//	idWbRegO		<= wbRegO;
//	idWbRegValO		<= wbRegValO;

	if((exMemLoad||exMemStore) &&
		(dcfRegOutOK==UMEM_OK_OK))
	begin
//		idWbRegO <= idRegN;
//		idWbRegValO <= dcfRegOutData[31:0];
	end
	else
	begin
//		idWbRegO		<= wbRegO;
//		idWbRegValO		<= wbRegValO;
	end

	if(memIfPcOE)
	begin
		$display("ExUnit: memIfPcOE");

		dc2RegInAddr	<= memIfPcAddr;
		dc2RegInData	<= 0;
		dc2RegInOE		<= memIfPcOE;
		dc2RegInWR		<= 0;
		dc2RegInOp		<= 1;
		memIfPcData		<= dc2RegOutData;
		memIfPcOK		<= dc2RegOutOK;

//		$display("ExUnit: memIfPcOE: A=%X D=%X OK=%X",
//			memIfPcAddr, dc2RegOutData, dc2RegOutOK);

		dcfMemInData	<= 128'hX;
		if(dcfMemPcOE || dcfMemPcWR)
			dcfMemPcOK		<= UMEM_OK_HOLD;
		else
			dcfMemPcOK		<= UMEM_OK_READY;
	end
	else
	if(dcfMemPcOE || dcfMemPcWR)
	begin
		dc2RegInAddr	<= dcfMemPcAddr;
		dc2RegInData	<= dcfMemOutData;
		dc2RegInOE		<= dcfMemPcOE;
		dc2RegInWR		<= dcfMemPcWR;
		dc2RegInOp		<= dcfMemOp;
		dcfMemInData	<= dc2RegOutData;
		dcfMemPcOK		<= dc2RegOutOK;

		memIfPcData		<= 128'hX;
		if(memIfPcOE)
			memIfPcOK		<= UMEM_OK_HOLD;
		else
			memIfPcOK		<= UMEM_OK_READY;
	end
	else
	begin
		dc2RegInAddr	<= 0;
		dc2RegInData	<= 0;
		dc2RegInOE		<= 0;
		dc2RegInWR		<= 0;
		dc2RegInOp		<= 1;
	end

	/* IF */
		regIfPc		<= exNextPc2;
		regIfSr		<= exNextSr2;
	
	/* D1 */
		regIdPc		<= regIfPc;
		regIdSr		<= regIfSr;
		idIstrWord	<= regIfPcVal;

	/* D2 */
		regId2Pc	<= regIdPc;
		regId2Sr	<= regId2Sr;
		regId2CsFl	<= regId2CsFl;

		id2IstrWord	<= idIstrWord;

		id2RegN1	<= idRegN1;
		id2RegS1	<= idRegS1;
		id2RegT1	<= idRegT1;
		id2RegN2	<= idRegN2;
		id2RegS2	<= idRegS2;
		id2RegT2	<= idRegT2;
		id2RegN3	<= idRegN3;
		id2RegS3	<= idRegS3;
		id2RegT3	<= idRegT3;
		id2RegN4	<= idRegN4;
		id2RegS4	<= idRegS4;
		id2RegT4	<= idRegT4;
		id2RegN5	<= idRegN5;
		id2RegS5	<= idRegS5;
		id2RegT5	<= idRegT5;

		id2Imm1		<= idImm1;
		id2Imm2		<= idImm2;
		id2Imm3		<= idImm3;
		id2Imm4		<= idImm4;
		id2Imm5		<= idImm5;

		id2UCmd1	<= idUCmd1;
		id2UCmd2	<= idUCmd2;
		id2UCmd3	<= idUCmd3;
		id2UCmd4	<= idUCmd4;
		id2UCmd5	<= idUCmd5;

		id2Step		<= idStep;

		id2ValN1	<= idValN1;
		id2ValS1	<= idValS1;
		id2ValT1	<= idValT1;
		id2ValN2	<= idValN2;
		id2ValS2	<= idValS2;
		id2ValT2	<= idValT2;
		id2ValN3	<= idValN3;
		id2ValS3	<= idValS3;
		id2ValT3	<= idValT3;
		id2ValN4	<= idValN4;
		id2ValS4	<= idValS4;
		id2ValT4	<= idValT4;
		id2ValN5	<= idValN5;
		id2ValS5	<= idValS5;
		id2ValT5	<= idValT5;

	/* E1, E2 */

		regExPcVal	<= id2IstrWord;
		regExCsFl	<= regId2CsFl;
		regExPc		<= regId2Pc;
		regExSr		<= regId2Sr;
//		exStepPc	<= idStepPc;
//		exStepPc2	<= idStepPc2;

		ex1RegN		<= id2RegN1;
		ex1RegS		<= id2RegS1;
		ex1RegT		<= id2RegT1;
		ex1RegValN	<= id2ValN1;
		ex1RegValS	<= id2ValS1;
		ex1RegValT	<= id2ValT1;
//		ex1Imm		<= id2Imm1;
		ex1Imm		<= { id2Imm1[31] ? 32'hFFFFFFFF : 32'h0, id2Imm1 };
		ex1UCmd		<= id2UCmd1;

		ex2RegN		<= id2RegN2;
		ex2RegS		<= id2RegS2;
		ex2RegT		<= id2RegT2;
		ex2RegValN	<= id2ValN2;
		ex2RegValS	<= id2ValS2;
		ex2RegValT	<= id2ValT2;
//		ex2Imm		<= id2Imm2;
		ex2Imm		<= { id2Imm2[31] ? 32'hFFFFFFFF : 32'h0, id2Imm2 };
		ex2UCmd		<= id2UCmd2;

		ex3RegN		<= id2RegN3;
		ex3RegS		<= id2RegS3;
		ex3RegT		<= id2RegT3;
		ex3RegValN	<= id2ValN3;
		ex3RegValS	<= id2ValS3;
		ex3RegValT	<= id2ValT3;
//		ex3Imm		<= id2Imm3;
		ex3Imm		<= { id2Imm3[31] ? 32'hFFFFFFFF : 32'h0, id2Imm3 };
		ex3UCmd		<= id2UCmd3;

		ex4RegN		<= id2RegN4;
		ex4RegS		<= id2RegS4;
		ex4RegT		<= id2RegT4;
		ex4RegValN	<= id2ValN4;
		ex4RegValS	<= id2ValS4;
		ex4RegValT	<= id2ValT4;
//		ex4Imm		<= id2Imm4;
		ex4Imm		<= { id2Imm4[31] ? 32'hFFFFFFFF : 32'h0, id2Imm4 };
		ex4UCmd		<= id2UCmd4;

		ex5RegN		<= id2RegN5;
		ex5RegS		<= id2RegS5;
		ex5RegT		<= id2RegT5;
		ex5RegValN	<= id2ValN5;
		ex5RegValS	<= id2ValS5;
		ex5RegValT	<= id2ValT5;
//		ex5Imm		<= id2Imm5;
		ex5Imm		<= { id2Imm5[31] ? 32'hFFFFFFFF : 32'h0, id2Imm5 };
		ex5UCmd		<= id2UCmd5;

	/* M1 */
		idRegW1		<= ex1RegO;
		idValW1		<= ex1RegValO;

		idRegW2		<= ex2RegO;
		idRegW3		<= ex3RegO;
		idRegW4		<= ex4RegO;
		idRegW5		<= ex5RegO;
		idValW2		<= ex2RegValO;
		idValW3		<= ex3RegValO;
		idValW4		<= ex4RegValO;
		idValW5		<= ex5RegValO;

/*		ma1RegO1;
		ma1ValO1;
		ma1RegO2;
		ma1ValO2;
		ma1RegO3;
		ma1ValO3;
		ma1RegO4;
		ma1ValO4;
		ma1RegO5;
		ma1ValO5; */

	/* M2 */

	/* WB */

end

endmodule
