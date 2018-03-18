/*
 * Pipeline: IF D1 D2 EX WB
 */

`include "CoreDefs.v"
`include "Dc2Tile.v"
`include "DcTile3.v"
`include "IcTile2.v"

`include "RegGPR3.v"

`include "DecOp4.v"
// `include "DecOp3.v"
`include "ExOp2.v"
// `include "FpuFpD.v"

// `include "TxtNtModW.v"

module ExUnit(
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


/* Baseline Registers */

wire[31:0]		regMach;		//MACH
wire[31:0]		regMacl;		//MACL
wire[31:0]		regPr;			//PR
wire[31:0]		regSGr;			//SGR (Saved R15)
wire[31:0]		regFpul;		//FPUL
wire[31:0]		regFpScr;		//FPSCR

wire[31:0]		regSr;			//SR
wire[31:0]		regGbr;			//GBR
wire[31:0]		regVbr;			//VBR
wire[31:0]		regSSr;			//SSR
wire[31:0]		regSPc;			//SPC
wire[31:0]		regPc;			//PC

wire[31:0]		regSp;			//SP/GR (R15)


reg[7:0]		regRstTok;
reg[7:0]		regNextRstTok;


/* L2 */

reg[31:0]	dc2RegInAddr;
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

reg[31:0]	dcfRegInAddr;
reg[63:0]	dcfRegInData;
wire[63:0]	dcfRegOutData;
wire[1:0]	dcfRegOutOK;
reg			dcfRegInOE;
reg			dcfRegInWR;
reg[4:0]	dcfRegInOp;

reg[127:0]	dcfMemInData;
wire[127:0]	dcfMemOutData;
wire[31:0]	dcfMemPcAddr;
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

reg[31:0]	ifValPc;			//PC, Fetch
reg[31:0]	ifValSr;			//SR, Fetch
wire[47:0]	regIfPcVal;			//PC Instruction Value
wire[1:0]	regIfPcOK;

reg[127:0]	memIfPcData;
wire[31:0]	memIfPcAddr;
wire		memIfPcOE;
reg[1:0]	memIfPcOK;

IcTile2 icf(clock, reset,
	ifValPc,
	regIfPcVal, regIfPcOK,
	memIfPcData,
	memIfPcAddr, memIfPcOE, memIfPcOK);

reg[47:0]	regIfPcVal2;		//PC Instruction Value


/* ID / D1 */

reg[47:0]	regIdPcVal;			//PC Instruction Value
reg[15:0]	regIdCsFl;			//Control State Flags

reg[31:0]	idValPc;			//ID PC Value
reg[31:0]	idValSr;			//ID SR Value

wire[6:0] idRegN;
wire[6:0] idRegS;
wire[6:0] idRegT;
wire[31:0] idImm;
wire[3:0] idStepPc;
wire[3:0] idStepPc2;
wire[7:0] idUCmd;

reg[6:0]	idWbRegO;
reg[63:0]	idWbRegValO;

reg[6:0]	wbRegO;
reg[63:0]	wbRegValO;

//DecOp2 dec(clock, regIdPcVal[31:0], regIdCsFl,
// DecOp3 dec(
DecOp4 dec(
	clock, regIdPcVal[47:0], regIdCsFl,
	idRegN, idRegS, idRegT, idImm,
	idStepPc, idStepPc2, idUCmd); 


/* RF / D2 */

reg[31:0]	id2ValPc;
reg[31:0]	id2ValSr;			//ID SR Value

wire[31:0]	id2ValPrPc;
assign		id2ValPrPc = id2ValPc + {28'h0, id2StepPc} + 2;

reg[47:0]	regId2PcVal;		//PC Instruction Value
reg[15:0]	regId2CsFl;			//Control State Flags

reg[6:0]	id2RegN;
reg[6:0]	id2RegS;
reg[6:0]	id2RegT;
reg[31:0]	id2Imm;
reg[3:0]	id2StepPc;
reg[3:0]	id2StepPc2;
reg[7:0]	id2UCmd;

wire[63:0]	id2RegValN;
wire[63:0]	id2RegValS;
wire[63:0]	id2RegValT;

reg[1:0]	id2RegFpLdMode;
reg[1:0]	idWbRegFpStMode;


RegGPR3 gpr(
	clock,		reset || (regRstTok != 8'h55),
	id2RegS,	id2RegValS,
	id2RegT,	id2RegValT,
	id2RegN,	id2RegValN,
	idWbRegO,	idWbRegValO,
	id2ValSr,	tRegExHold,
	id2Imm,		id2ValPrPc,
	id2RegFpLdMode,
	idWbRegFpStMode,

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

reg[7:0]	id2UCmd2;
reg[63:0]	id2RegValN2;
reg[63:0]	id2RegValS2;
reg[63:0]	id2RegValT2;


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
reg[3:0]	exStepPc2;
reg[7:0]	exUCmd;

reg[63:0]	exRegValN;
reg[63:0]	exRegValS;
reg[63:0]	exRegValT;

wire[6:0]	exRegO;
wire[63:0]	exRegValO;
wire[1:0]	exRegOutOK;
wire[1:0]	exRegOutStMode;

wire[31:0]	exMemAddr;			//memory address
wire[63:0]	exMemData;			//memory data (write)
wire		exMemLoad;			//load from memory
wire		exMemStore;			//store to memory
wire[4:0]	exMemOpMode;		//mem op mode
wire[7:0]	exMemOpCmd2;		//mem EX chain

wire[31:0]	exNextSr;			//SR in
wire[31:0]	exNextPr;			//PR in
wire[31:0]	exNextPc;			//PC in
wire[31:0]	exNextMach;			//MACH
wire[31:0]	exNextMacl;			//MACL

wire[31:0]	exNextGbr;			//GBR
wire[31:0]	exNextVbr;			//VBR
wire[31:0]	exNextSSr;			//SSR
wire[31:0]	exNextSPc;			//SPC
wire[31:0]	exNextSGr;			//SGR (R15)

wire[31:0]	exNextSp;			//SP out
wire[31:0]	exNextFpul;			//SP out
wire[31:0]	exNextFpScr;		//SP out


ExOp2	exOp(clock, reset,
	exUCmd,			exStepPc,
	exRegS,			exRegValS,
	exRegT,			exRegValT,
	exRegN,			exRegValN,
	exImm,			tRegGenIdPc,
	exRegO,			exRegValO,
	exRegOutOK,		exRegOutStMode,

	exMemAddr,		exMemData,
	exMemLoad,		exMemStore,
	exMemOpMode,	exMemOpCmd2,

	regSr,			exNextSr,
	regPr,			exNextPr,
	regExPc,		exNextPc,
	regMach,		exNextMach,
	regMacl,		exNextMacl,
	regSp,			exNextSp,
	regFpul,		exNextFpul,
	regFpScr,		exNextFpScr,

	regGbr,			exNextGbr,
	regVbr,			exNextVbr,
	regSSr,			exNextSSr,
	regSPc,			exNextSPc,
	regSGr,			exNextSGr
	);

reg[31:0]	exNextSr2;			//SR in
reg[31:0]	exNextPr2;			//PR in
reg[31:0]	exNextPc2;			//PC in
reg[31:0]	exNextMach2;		//MACH
reg[31:0]	exNextMacl2;		//MACL

reg[31:0]	exNextGbr2;			//GBR
reg[31:0]	exNextVbr2;			//VBR
reg[31:0]	exNextSSr2;			//SSR
reg[31:0]	exNextSPc2;			//SPC
reg[31:0]	exNextSGr2;			//SGR (Saved R15)
reg[31:0]	exNextFpul2;		//
reg[31:0]	exNextFpScr2;		//

reg[31:0]	exNextSp2;			//



reg[31:0]	tRegGenIdPc;			//Generated PC
reg[31:0]	tRegGenIdPr;			//Generated PR

reg[15:0]	tRegGenIdOpw;			//
reg[3:0]	tRegGenIdStepPc;		//
reg			tRegExHold;				//Execution is held

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

	tRegGenIdStepPc=exStepPc2;

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

	id2RegFpLdMode = 0;
	idWbRegFpStMode = exRegOutStMode;

	if(regFpScr[19])
		id2RegFpLdMode = 1;
	if(regFpScr[20])
		id2RegFpLdMode = 1;

	/* Non-Delay Branch, Next op becomes No-Op */
	id2UCmd2 = id2UCmd;
	case(exUCmd)
		UCMD_BRAN:	id2UCmd2 = UCMD_NONE;
		UCMD_BSRN:	id2UCmd2 = UCMD_NONE;
		UCMD_BT:	id2UCmd2 = UCMD_NONE;
		UCMD_BF:	id2UCmd2 = UCMD_NONE;
		UCMD_RTSN:	id2UCmd2 = UCMD_NONE;
		UCMD_RTEN:	id2UCmd2 = UCMD_NONE;
		default: begin end
	endcase
	
//	tRegGenIdPc = idValPc + {28'h0, idStepPc};
//	tRegGenIdPc = idValPc + {28'h0, idStepPc} + {28'h0, tRegGenIdStepPc};
	tRegGenIdPc = ifValPc + {28'h0, tRegGenIdStepPc};
//	tRegGenIdPr = idValPc + {28'h0, idStepPc + 4'h2};
//	tRegGenIdPr = idValPc + {28'h0, exStepPc2 + 4'h2};
	tRegGenIdPr = ifValPc + 32'h4;
	
	id2RegValN2 = id2RegValN;
	id2RegValS2 = id2RegValS;
	id2RegValT2 = id2RegValT;

	wbRegO = exRegO;
	wbRegValO = exRegValO;

	/* Short Circuit / Bypass */
	if(id2RegS == wbRegO)
		id2RegValS2 = wbRegValO;
	if(id2RegT == wbRegO)
		id2RegValT2 = wbRegValO;	
	if(id2RegN == wbRegO)
		id2RegValN2 = wbRegValO;

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
	
	if(exNextPc != tRegGenIdPc)
	begin
		regIfPcVal2 = 48'h0F09_0F09_0E09;
	end

	exNextFpul2 = exNextFpul;
	exNextFpScr2 = exNextFpScr;

//	exNextFpScr2[11] = ntscPwm[3];	//debug

	exNextSp2 = exNextSp;

	if(regRstTok != 8'h55)
	begin
		$display("Reset");
		exNextPc2 = 32'hA000_0000;
		tRegExHold = 1;
	end

	$display("IF: %X %X", ifValPc, regIfPcVal);
	$display("ID: %X %X", idValPc, regIdPcVal);

// /*
	$display("EX: %X %X %X Rs:R%X=%X Rt:R%X=%X Rn:R%X=%X Wb:R%X=%X",
		regExPc, regExPcVal, exUCmd,
		exRegS, exRegValS,
		exRegT, exRegValT,
		exRegN, exRegValN,
		wbRegO, wbRegValO);
// */

end


always @ (posedge clock)
begin
	regRstTok <= regNextRstTok;

	dcfRegInAddr	<= exMemAddr;
	dcfRegInData	<= exMemData;
	dcfRegInOE		<= exMemLoad;
	dcfRegInWR		<= exMemStore;
	dcfRegInOp		<= exMemOpMode;

	idWbRegO		<= wbRegO;
	idWbRegValO		<= wbRegValO;

	if((exMemLoad||exMemStore) &&
		(dcfRegOutOK==UMEM_OK_OK))
	begin
		idWbRegO	<= id2RegN;
		idWbRegValO <= dcfRegOutData[63:0];
	end
	else
	begin
		idWbRegO		<= wbRegO;
		idWbRegValO		<= wbRegValO;
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

	if(regRstTok != 8'h55)
	begin
	/* Common */

	/* IF */
		ifValPc		<= 32'hA000_0000;
		ifValSr		<= 0;

	/* ID */
		idValPc		<= 32'hA000_0000;
		idValSr		<= 0;
		regIdPcVal	<= 0;

	/* EX */
		regExPcVal	<= 0;
		regExCsFl	<= 0;
		regExPc		<= 32'hA000_0000;
		regExSr		<= 0;
		exStepPc	<= 0;
		exStepPc2	<= 0;
	end
	else
	if(!tRegExHold)
	begin
		$display("Step");
		
	/* Common */

	/* IF */

		ifValPc		<= exNextPc2;
		ifValSr		<= exNextSr2;

	/* D1 */

		idValPc		<= ifValPc;
		idValSr		<= ifValSr;
		regIdPcVal	<= regIfPcVal2;

	/* D2 */

		id2ValPc	<= idValPc;
		id2ValSr	<= idValSr;
		regId2PcVal	<= regIdPcVal;
		regId2CsFl	<= regIdCsFl;
		id2RegN		<= idRegN;
		id2RegS		<= idRegS;
		id2RegT		<= idRegT;
		id2Imm		<= idImm;
		id2StepPc	<= idStepPc;
		id2StepPc2	<= idStepPc2;
		id2UCmd		<= idUCmd;

	/* EX */

		regExPcVal	<= regId2PcVal;
		regExCsFl	<= regId2CsFl;
		regExPc		<= id2ValPc;
		regExSr		<= id2ValSr;
		exRegN		<= id2RegN;
		exRegS		<= id2RegS;
		exRegT		<= id2RegT;
		exImm		<= id2Imm;
		exStepPc	<= id2StepPc;
		exStepPc2	<= id2StepPc2;
		exUCmd		<= id2UCmd2;
		exRegValN	<= id2RegValN2;
		exRegValS	<= id2RegValS2;
		exRegValT	<= id2RegValT2;

	end
	else
	begin
		$display("Hold");
	end

end

endmodule
