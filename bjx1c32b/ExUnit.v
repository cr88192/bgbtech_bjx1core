`include "CoreDefs.v"
`include "Dc2Tile.v"
`include "DcTile3.v"
`include "IcTile2.v"

`include "RegGPR2.v"
// `include "RegFPR.v"

`include "DecOp3.v"
`include "ExOp2.v"
`include "FpuFpD.v"

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

/*
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
*/

// /*
wire[63:0]		regMac;			//MACH:MACL
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
// */

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
reg[31:0]	regIfPc;			//PC, Fetch
reg[31:0]	regIfSr;			//SR, Fetch
wire[47:0]	regIfPcVal;			//PC Instruction Value
wire[1:0]	regIfPcOK;

reg[127:0]	memIfPcData;
wire[31:0]	memIfPcAddr;
wire		memIfPcOE;
reg[1:0]	memIfPcOK;

IcTile2 icf(clock, reset,
	regIfPc,
	regIfPcVal, regIfPcOK,
	memIfPcData,
	memIfPcAddr, memIfPcOE, memIfPcOK);

reg[47:0]	regIfPcVal2;		//PC Instruction Value

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
wire[3:0] idStepPc2;
wire[7:0] idUCmd;

reg[6:0]	idWbRegO;
reg[31:0]	idWbRegValO;

reg[6:0]	wbRegO;
reg[31:0]	wbRegValO;

//DecOp2 dec(clock, regIdPcVal[31:0], regIdCsFl,
DecOp3 dec(clock, regIdPcVal[47:0], regIdCsFl,
	idRegN, idRegS, idRegT, idImm,
	idStepPc, idStepPc2, idUCmd); 

//assign idRegValN=0;
//assign idRegValS=0;
//assign idRegValT=0;

wire[31:0] idRegValN;
wire[31:0] idRegValS;
wire[31:0] idRegValT;

RegGPR2 gpr(
	clock,		reset || (regRstTok != 8'h55),
	idRegS,		idRegValS,
	idRegT,		idRegValT,
	idRegN,		idRegValN,
	idWbRegO,	idWbRegValO,
	regIdSr,	tRegExHold,
	idImm,

	regSr,		exNextSr2,
	regPr,		exNextPr2,
	regPc,		exNextPc2,
	regMac,		exNextMac2,
	regSp,		exNextSp2,
	regGbr,		exNextGbr2,
	regVbr,		exNextVbr2,
	regSSr,		exNextSSr2,
	regSPc,		exNextSPc2,
	regSGr,		exNextSGr2,
	regFpul,	exNextFpul2,
	regFpScr,	exNextFpScr2
	);

wire[63:0]		idRegFpValN;
wire[63:0]		idRegFpValS;
wire[63:0]		idRegFpValT;
reg[1:0]		idRegFpMode;
reg[1:0]		idRegFpStMode;
wire[31:0]		idFpNextFpul;

reg[6:0]		idWbRegFpO;
reg[63:0]		idWbRegFpValO;

reg[6:0]		wbRegFpO;
reg[63:0]		wbRegFpValO;

assign idRegFpValN=0;
assign idRegFpValS=0;
assign idRegFpValT=0;
assign idFpNextFpul = regFpul;

/*
RegFPR fpr(clock, reset,
	idRegS,			idRegFpValS,
	idRegT,			idRegFpValT,
	idRegN,			idRegFpValN,
	idWbRegFpO,		idWbRegFpValO,
	idRegFpMode,	regIdCsFl,
	idRegFpStMode,
	regFpul,		idFpNextFpul
	);
*/

reg[7:0]	idUCmd2;
reg[31:0]	idRegValN2;
reg[31:0]	idRegValS2;
reg[31:0]	idRegValT2;

reg[63:0]	idRegFpValN2;
reg[63:0]	idRegFpValS2;
reg[63:0]	idRegFpValT2;

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

reg[31:0]	exRegValN;
reg[31:0]	exRegValS;
reg[31:0]	exRegValT;

reg[63:0]	exRegFpValN;
reg[63:0]	exRegFpValS;
reg[63:0]	exRegFpValT;

wire[6:0]	exRegO;
wire[31:0]	exRegValO;
wire[1:0]	exRegOutOK;

wire[31:0]	exMemAddr;			//memory address
wire[31:0]	exMemData;			//memory data (write)
wire		exMemLoad;			//load from memory
wire		exMemStore;			//store to memory
wire[4:0]	exMemOpMode;		//mem op mode
wire[7:0]	exMemOpCmd2;		//mem EX chain

wire[31:0]	exNextSr;			//SR in
wire[31:0]	exNextPr;			//PR in
wire[31:0]	exNextPc;			//PC in
wire[63:0]	exNextMac;			//MACH:MACL

wire[31:0]	exNextGbr;			//GBR
wire[31:0]	exNextVbr;			//VBR
wire[31:0]	exNextSSr;			//SSR
wire[31:0]	exNextSPc;			//SPC
wire[31:0]	exNextSGr;			//SGR (R15)

wire[31:0]	exNextSp;			//SP out


ExOp2	exOp(clock, reset,
	exUCmd,			exStepPc,
	exRegS,			exRegValS,
	exRegT,			exRegValT,
	exRegN,			exRegValN,
	exImm,			tRegGenIdPc,
	exRegO,			exRegValO,
	exRegOutOK,

	exMemAddr,		exMemData,
	exMemLoad,		exMemStore,
	exMemOpMode,	exMemOpCmd2,

	regSr,			exNextSr,
	regPr,			exNextPr,
	regExPc,		exNextPc,
	regMac,			exNextMac,
	regSp,			exNextSp,

	regGbr,			exNextGbr,
	regVbr,			exNextVbr,
	regSSr,			exNextSSr,
	regSPc,			exNextSPc,
	regSGr,			exNextSGr
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
reg[31:0]	exNextFpul2;		//
reg[31:0]	exNextFpScr2;		//

reg[31:0]	exNextSp2;			//


wire[6:0]	exRegFpO;
wire[63:0]	exRegFpValO;
wire[1:0]	exRegFpModeO;

wire[31:0]	exFpNextSr;			//
wire[31:0]	exFpNextFpul;		//
wire[31:0]	exFpNextFpScr;		//

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

/*
	case(idStepPc[3:1])
		3'h0: tRegGenIdOpw=regIdPcVal[15:0];
		3'h1: tRegGenIdOpw=regIdPcVal[31:16];
		3'h2: tRegGenIdOpw=regIdPcVal[47:32];
		default: begin end
	endcase

	tRegGenIdStepPc=0;
	case(tRegGenIdOpw[15:8])
		8'h8A:		tRegGenIdStepPc=4;
		8'h8C:		tRegGenIdStepPc=4;
		8'h8E:		tRegGenIdStepPc=4;
		default:	tRegGenIdStepPc=2;
	endcase
*/

	tRegGenIdStepPc=exStepPc2;

/*
	dcfRegInAddr = exMemAddr;
	dcfRegInData = {32'h0, exMemData};
	dcfRegInOE = exMemLoad;
	dcfRegInWR = exMemStore;
	dcfRegInOp = exMemOpMode;
*/
	
// assign		dcfRegOutData;
// assign		dcfRegOutOK;

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

/*
	if(memIfPcOE)
	begin
		dc2RegInAddr	= memIfPcAddr;
		dc2RegInData	= 0;
		dc2RegInOE		= memIfPcOE;
		dc2RegInWR		= 0;
		dc2RegInOp		= 1;
		memIfPcData		= dc2MemOutData;
		memIfPcOK		= dc2RegOutOK;

//		if(dcfMemPcOE || dcfMemPcWR)
//			dcfMemPcOK		= UMEM_OK_HOLD;
	end
	else
	if(dcfMemPcOE || dcfMemPcWR)
	begin
		dc2RegInAddr	= dcfMemPcAddr;
		dc2RegInData	= dcfMemOutData;
		dc2RegInOE		= dcfMemPcOE;
		dc2RegInWR		= dcfMemPcWR;
		dc2RegInOp		= dcfMemOp;
		dcfMemInData	= dc2MemOutData;
		dcfMemPcOK		= dc2RegOutOK;

//		if(memIfPcOE)
//			dcfMemPcOK		= UMEM_OK_HOLD;
	end
*/

	idRegFpMode = 0;
	idRegFpStMode = exRegFpModeO;

	if(regFpScr[19])
		idRegFpMode = 1;
	if(regFpScr[20])
		idRegFpMode = 1;

	/* Non-Delay Branch, Next op becomes No-Op */
	idUCmd2 = idUCmd;
	case(exUCmd)
		UCMD_BRAN:	idUCmd2 = UCMD_NONE;
		UCMD_BSRN:	idUCmd2 = UCMD_NONE;
		UCMD_BT:	idUCmd2 = UCMD_NONE;
		UCMD_BF:	idUCmd2 = UCMD_NONE;
		UCMD_RTSN:	idUCmd2 = UCMD_NONE;
		UCMD_RTEN:	idUCmd2 = UCMD_NONE;
		default: begin end
	endcase
	
//	tRegGenIdPc = regIdPc + {28'h0, idStepPc};
//	tRegGenIdPc = regIdPc + {28'h0, idStepPc} + {28'h0, tRegGenIdStepPc};
	tRegGenIdPc = regIfPc + {28'h0, tRegGenIdStepPc};
//	tRegGenIdPr = regIdPc + {28'h0, idStepPc + 4'h2};
//	tRegGenIdPr = regIdPc + {28'h0, exStepPc2 + 4'h2};
	tRegGenIdPr = regIfPc + 32'h4;
	
	idRegValN2 = idRegValN;
	idRegValS2 = idRegValS;
	idRegValT2 = idRegValT;

	idRegFpValS2 = idRegFpValS;
	idRegFpValT2 = idRegFpValT;
	idRegFpValN2 = idRegFpValN;

	wbRegO = exRegO;
	wbRegValO = exRegValO;

	wbRegFpO = exRegFpO;
	wbRegFpValO = exRegFpValO;

 /*
	if(exMemLoad||exMemStore)
	begin
		if(dcfRegOutOK==UMEM_OK_OK)
		begin
			wbRegO = idRegN;
			wbRegValO = dcfRegOutData[31:0];

			wbRegFpO = idRegN;
			wbRegFpValO = dcfRegOutData;
		end
	end
 */

	/* Short Circuit / Bypass */
	if(idRegS == wbRegO)
		idRegValS2 = wbRegValO;
	if(idRegT == wbRegO)
		idRegValT2 = wbRegValO;	
	if(idRegN == wbRegO)
		idRegValN2 = wbRegValO;

	if(idRegS == wbRegO)
		idRegFpValS2 = wbRegFpValO;
	if(idRegT == wbRegO)
		idRegFpValT2 = wbRegFpValO;	
	if(idRegN == wbRegO)
		idRegFpValN2 = wbRegFpValO;

	exNextSr2 = exNextSr;
	exNextPr2 = exNextPr;
	exNextPc2 = exNextPc;
	exNextMac2 = exNextMac;
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

	exNextFpul2 = idFpNextFpul;
	exNextFpScr2 = exFpNextFpScr;

	exNextSp2 = exNextSp;

/*
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
		UREG_R15:	exNextSp2			= exRegValO;

		default:	begin end
	endcase
*/

	if(regRstTok != 8'h55)
	begin
		$display("Reset");
		exNextPc2 = 32'hA000_0000;
		tRegExHold = 1;
	end

	$display("IF: %X %X", regIfPc, regIfPcVal);
	$display("ID: %X %X", regIdPc, regIdPcVal);

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
	dcfRegInData	<= {32'h0, exMemData};
	dcfRegInOE		<= exMemLoad;
	dcfRegInWR		<= exMemStore;
	dcfRegInOp		<= exMemOpMode;

	idWbRegO		<= wbRegO;
	idWbRegValO		<= wbRegValO;

	if((exMemLoad||exMemStore) &&
		(dcfRegOutOK==UMEM_OK_OK))
	begin
		idWbRegO <= idRegN;
		idWbRegValO <= dcfRegOutData[31:0];

		idWbRegFpO <= idRegN;
		idWbRegFpValO <= dcfRegOutData;
	end
	else
	begin
		idWbRegO		<= wbRegO;
		idWbRegValO		<= wbRegValO;

		idWbRegFpO		<= wbRegFpO;
		idWbRegFpValO	<= wbRegFpValO;
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
/*
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
*/

	/* IF */
		regIfPc		<= 32'hA000_0000;
		regIfSr		<= 0;

	/* ID */
		regIdPc		<= 32'hA000_0000;
		regIdSr		<= 0;
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

/*
		regSr		<= exNextSr2;			//SR
		regPr		<= exNextPr2;			//PR
		regPc		<= exNextPc2;			//PC
		regMac		<= exNextMac2;			//MACH:MACL
		regSp		<= exNextSp2;			//SP

		regGbr		<= exNextGbr2;
		regVbr		<= exNextVbr2;
		regSSr		<= exNextSSr2;
		regSPc		<= exNextSPc2;
		regSGr		<= exNextSGr2;
		
		regFpul		<= exNextFpul2;
		regFpScr	<= exNextFpScr2;
*/

	/* IF */
		regIfPc		<= exNextPc2;
		regIfSr		<= exNextSr2;

	/* ID */
		regIdPc		<= regIfPc;
		regIdSr		<= regIfSr;
		regIdPcVal	<= regIfPcVal2;

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
		exStepPc2	<= idStepPc2;
		exUCmd		<= idUCmd2;
		exRegValN	<= idRegValN2;
		exRegValS	<= idRegValS2;
		exRegValT	<= idRegValT2;

		exRegFpValN	<= idRegFpValN2;
		exRegFpValS	<= idRegFpValS2;
		exRegFpValT	<= idRegFpValT2;
	end
	else
	begin
		$display("Hold");
	end

end

endmodule
