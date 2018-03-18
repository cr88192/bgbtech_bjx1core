/*
IF: Fetch
  PC->ICache
ID: Decode
  ICache->Decoder
EX: Execute
  In Regs->Output Reg (Reg Only)
  May initiate a memory access.

MA: Memory Access
WB: Write Back
  Memory Load -> Register

Execute Module (32-bit)
*/

`include "CoreDefs.v"

`include "ExShad32.v"

`include "FpuFpF_Mul.v"
`include "FpuFpF_Add.v"

module ExOp2(
	/* verilator lint_off UNUSED */
	clock,		reset,
	opCmd,		opStepPc,
	regIdRs,	regValRsB,
	regIdRt,	regValRtB,
	regIdRn,	regValRnB,
	immValRi,	idInGenPc,
	regOutId,	regOutVal,
	regOutOK,	regOutStMode,

	memAddr,	memData,
	memLoad,	memStore,
	memOpMode,	memOpCmd2,

	ctlInSr,	ctlOutSr,
	ctlInPr,	ctlOutPr,
	ctlInPc,	ctlOutPc,
	ctlInMach,	ctlOutMach,
	ctlInMacl,	ctlOutMacl,
	ctlInSp,	ctlOutSp,
	ctlInFpul,	ctlOutFpul,
	ctlInFpScr,	ctlOutFpScr,

	ctlInGbr,	ctlOutGbr,
	ctlInVbr,	ctlOutVbr,
	ctlInSSr,	ctlOutSSr,
	ctlInSPc,	ctlOutSPc,
	ctlInSGr,	ctlOutSGr
	);

input			clock;
input			reset;

input[7:0]		opCmd;			//command opcode
input[3:0]		opStepPc;
input[31:0]		idInGenPc;		//ID's Next PC (Next Fetch)

input[6:0]		regIdRs;
input[6:0]		regIdRt;
input[6:0]		regIdRn;

input[63:0]		regValRsB;		//Rs input value
input[63:0]		regValRtB;		//Rt input value
input[63:0]		regValRnB;		//Rn input value
input[31:0]		immValRi;		//immediate/disp value

output[63:0]	regOutVal;		//Rn output value
output[6:0]		regOutId;		//Rn, value to write
output[1:0]		regOutOK;		//execute status
output[1:0]		regOutStMode;	//output store mode

/* Memory */
output[31:0]	memAddr;		//memory address
output[63:0]	memData;		//memory data (write)
output			memLoad;		//load from memory
output			memStore;		//store to memory
output[4:0]		memOpMode;		//mem op mode
output[7:0]		memOpCmd2;		//mem EX chain


/* Special Registers */
input[31:0]		ctlInSr;		//SR in
input[31:0]		ctlInPr;		//PR in
input[31:0]		ctlInPc;		//PC in
output[31:0]	ctlOutSr;		//SR out
output[31:0]	ctlOutPr;		//PR out
output[31:0]	ctlOutPc;		//PC out

input[31:0]		ctlInMach;		//MACH in
input[31:0]		ctlInMacl;		//MACL in
output[31:0]	ctlOutMach;		//MACH out
output[31:0]	ctlOutMacl;		//MACL out

input[31:0]		ctlInSp;		//SP in
output[31:0]	ctlOutSp;		//SP out

input[31:0]		ctlInFpul;		//SP in
output[31:0]	ctlOutFpul;		//SP out
input[31:0]		ctlInFpScr;		//SP in
output[31:0]	ctlOutFpScr;	//SP out

input[31:0]		ctlInGbr;
input[31:0]		ctlInVbr;
input[31:0]		ctlInSSr;
input[31:0]		ctlInSPc;
input[31:0]		ctlInSGr;

output[31:0]	ctlOutGbr;
output[31:0]	ctlOutVbr;
output[31:0]	ctlOutSSr;
output[31:0]	ctlOutSPc;
output[31:0]	ctlOutSGr;


wire[31:0]		regValRs;		//Rs input value
wire[31:0]		regValRt;		//Rt input value
wire[31:0]		regValRn;		//Rn input value

assign		regValRs = regValRsB[31:0];
assign		regValRt = regValRtB[31:0];
assign		regValRn = regValRnB[31:0];

/* Temporary */
reg[31:0]	tRegOutVal;			//Rn, output value
reg[6:0]	tRegOutId;			//Rn, output register
reg[1:0]	tRegOutOK;			//execute status
reg[1:0]	tRegOutStMode;		//register store mode

reg[31:0]	tRegOutValHi;		//Rn, output value

reg[31:0]	tMemAddr;			//memory address
reg[63:0]	tMemData;			//memory data (write)
reg			tMemLoad;			//load from memory
reg			tMemStore;			//store to memory
reg[4:0]	tMemOpMode;			//mem op mode
reg[7:0]	tMemOpCmd2;			//mem EX chain

assign		memAddr		= tMemAddr;
assign		memData		= tMemData;
assign		memLoad		= tMemLoad;
assign		memStore	= tMemStore;
assign		memOpMode	= tMemOpMode;
assign		memOpCmd2	= tMemOpCmd2;


/* verilator lint_off UNOPTFLAT */

reg[31:0]	tAguRtRi;			//AGU Rt+Ri
reg[31:0]	tAguRtRiSc;			//AGU (Rt+Ri)*Sc
reg[31:0]	tAguAddr;			//AGU Address

reg[31:0]	tCtlOutSr;
reg[31:0]	tCtlOutPr;
reg[31:0]	tCtlOutPc;
reg[63:0]	tCtlOutMac;
reg[31:0]	tCtlOutSp;
reg[31:0]	tCtlOutFpul;
reg[31:0]	tCtlOutFpScr;

reg[31:0]	tCtlNxtPc;
reg[31:0]	tCtlBraPc;
reg[31:0]	tCtlPrPc;

reg[31:0]	tCtlOutGbr;
reg[31:0]	tCtlOutVbr;
reg[31:0]	tCtlOutSSr;
reg[31:0]	tCtlOutSPc;
reg[31:0]	tCtlOutSGr;

/* verilator lint_on UNOPTFLAT */


// assign regOutVal = tRegOutVal;
assign regOutVal = { tRegOutValHi, tRegOutVal };
assign regOutId = tRegOutId;
assign regOutOK = tRegOutOK;
assign regOutStMode = tRegOutStMode;

assign	ctlOutSr = tCtlOutSr;
assign	ctlOutPr = tCtlOutPr;
assign	ctlOutPc = tCtlOutPc;
assign	ctlOutMach = tCtlOutMac[63:32];
assign	ctlOutMacl = tCtlOutMac[31: 0];
assign	ctlOutSp = tCtlOutSp;

assign	ctlOutFpul = tCtlOutFpul;
assign	ctlOutFpScr = tCtlOutFpScr;

assign	ctlOutGbr = tCtlOutGbr;
assign	ctlOutVbr = tCtlOutVbr;
assign	ctlOutSSr = tCtlOutSSr;
assign	ctlOutSPc = tCtlOutSPc;
assign	ctlOutSGr = tCtlOutSGr;

reg			tInAluC;
reg			tOutAluC;
reg			tTriggerExc;

reg[1:0]	tMacOp;
reg[63:0]	tMacValRs;
reg[63:0]	tMacValRt;
reg[63:0]	tMacValRu;
reg[63:0]	tMacValRuA;
reg[1:0]	tMacOpA;
reg[1:0]	tMacOpB;


reg[31:0]	tShadValRs;
reg[ 7:0]	tShadValRt;
wire[31:0]	tShadValRn;
reg[ 2:0]	tShadOp;

// reg[63:0]	tShadValRu;

ExShad32	sh32(
	clock, reset,
	tShadValRs, tShadValRt,
	tShadValRn, tShadOp);

reg[32:0]	tAluDn1;
reg[32:0]	tAluDn2;
reg			tAluQ0;
reg			tAluM0;
reg			tAluT0;
reg			tAluQ1;
reg			tAluM1;
reg			tAluT1;
reg			tAluQ2;
reg			tAluM2;
reg			tAluT2;


reg fpaIsEn;
reg fpmIsEn;
wire fpaIsSub;

wire[31:0] fpaSrcA;
wire[31:0] fpaSrcB;
wire[31:0] fpaDst;
wire[31:0] fpmDst;

FpuFpF_Add fpadd(
	clock, fpaIsEn, fpaIsSub,
	fpaSrcA, fpaSrcB, fpaDst);
FpuFpF_Mul fpmul(
	clock, fpmIsEn,
	fpaSrcA, fpaSrcB, fpmDst);

assign fpaSrcA = regValRs;
assign fpaSrcB = regValRt;
assign fpaIsSub = (opCmd==UCMD_FPU_FSUB);


/* EX */
always @*
begin
	tRegOutValHi = 32'hXXXXXXXX;
	tRegOutVal=0;
	tRegOutId=UREG_ZZR;
	tRegOutOK=UMEM_OK_OK;
	tRegOutStMode=0;
	
	tMemAddr=0;
	tMemData=0;
	tMemLoad=0;
	tMemStore=0;
	tMemOpMode=0;
	tMemOpCmd2=0;
	
	tInAluC=1'bX;
	tOutAluC=1'bX;

	tMacValRs=64'hX;
	tMacValRt=64'hX;
//	tMacValRu=64'hX;
	tMacOp=0;
	
	tShadValRs=32'hXXXXXXXX;
	tShadValRt=8'hXX;
	tShadOp=0;
	
	fpaIsEn = 0;
	fpmIsEn = 0;
//	fpaIsSub = 0;
	
	tTriggerExc=0;

	tCtlNxtPc=ctlInPc+{28'h0, opStepPc};
	tCtlPrPc=tCtlNxtPc + 2;
	tCtlBraPc=tCtlPrPc + (immValRi<<1);
	
	tCtlOutSr=ctlInSr;
	tCtlOutPr=ctlInPr;
	tCtlOutPc=idInGenPc;
	tCtlOutMac={ctlInMach, ctlInMacl};
	tCtlOutSp=ctlInSp;

	tCtlOutFpul=ctlInFpul;
	tCtlOutFpScr=ctlInFpScr;

	tCtlOutGbr = ctlInGbr;
	tCtlOutVbr = ctlInVbr;
	tCtlOutSSr = ctlInSSr;
	tCtlOutSPc = ctlInSPc;
	tCtlOutSGr = ctlInSGr;


/*
	tAguRtRi=regValRt+immValRi;
	if(regIdRt==UREG_R0)
	begin
		tAguAddr=opCmd[2]?
			(regValRs+tAguRtRi):
			(regValRn+tAguRtRi);
	end
	else
	begin
		case(opCmd[2:0])
			3'h0:	tAguAddr=regValRn+tAguRtRi;
			3'h1:	tAguAddr=regValRn+(tAguRtRi<<1);
			3'h2:	tAguAddr=regValRn+(tAguRtRi<<2);
			3'h3:	tAguAddr=regValRn+(tAguRtRi<<3);
			3'h4:	tAguAddr=regValRs+tAguRtRi;
			3'h5:	tAguAddr=regValRs+(tAguRtRi<<1);
			3'h6:	tAguAddr=regValRs+(tAguRtRi<<2);
			3'h7:	tAguAddr=regValRs+(tAguRtRi<<3);
		endcase
	end
*/

	tAguRtRi=regValRt+immValRi;
	case(opCmd[1:0])
		2'h0:	tAguRtRiSc=tAguRtRi;
		2'h1:	tAguRtRiSc={tAguRtRi[30:0], 1'b0};
		2'h2:	tAguRtRiSc={tAguRtRi[29:0], 2'b0};
		2'h3:	tAguRtRiSc={tAguRtRi[28:0], 3'b0};
	endcase
	tAguAddr=(opCmd[2]?regValRs:regValRn)+
		((regIdRt==UREG_R0)?tAguRtRi:tAguRtRiSc);

	casez(opCmd)
		UCMD_NONE: begin
		end

		UCMD_MOV_RR: begin
			tRegOutVal=regValRs;
			tRegOutId=regIdRn;
		end

		UCMD_MOV_RI: begin
			tRegOutVal=immValRi;
			tRegOutId=regIdRn;
		end


		UCMD_LEAB_MR: begin
			tRegOutVal=tAguAddr;
			tRegOutId=regIdRn;
		end

		UCMD_LEAW_MR: begin
			tRegOutVal=tAguAddr;
			tRegOutId=regIdRn;
		end

		UCMD_LEAL_MR: begin
			tRegOutVal=tAguAddr;
			tRegOutId=regIdRn;
		end

		UCMD_LEAQ_MR: begin
			tRegOutVal=tAguAddr;
			tRegOutId=regIdRn;
		end

		UCMD_MOVB_RM: begin
			tMemOpMode=5'h00;

			if(regIdRt==UREG_MR_MEMDEC)
			begin
				tMemAddr=tAguAddr-1;
				tMemData=regValRsB;
				tMemStore=1;
				tRegOutVal=regValRn-1;
				tRegOutId=regIdRn;
			end
			else
			begin
				tMemAddr=tAguAddr;
				tMemData=regValRsB;
				tMemStore=1;
			end
		end

		UCMD_MOVW_RM: begin
			tMemOpMode=5'h01;

			if(regIdRt==UREG_MR_MEMDEC)
			begin
				tMemAddr=tAguAddr-2;
				tMemData=regValRsB;
				tMemStore=1;
				tRegOutVal=regValRn-2;
				tRegOutId=regIdRn;
			end
			else
			begin
				tMemAddr=tAguAddr;
				tMemData=regValRsB;
				tMemStore=1;
			end
		end

		UCMD_MOVL_RM: begin
			tMemOpMode=5'h02;
			if(regIdRt==UREG_MR_MEMDEC)
			begin
				tMemAddr=tAguAddr-4;
				tMemData=regValRsB;
				tMemStore=1;
				tRegOutVal=regValRn-4;
				tRegOutId=regIdRn;
			end
			else
			begin
				tMemAddr=tAguAddr;
				tMemData=regValRsB;
				tMemStore=1;
			end
		end

		UCMD_MOVQ_RM: begin
			tMemOpMode=5'h03;
			if(regIdRt==UREG_MR_MEMDEC)
			begin
				tMemAddr=tAguAddr-8;
				tMemData=regValRsB;
				tMemStore=1;
				tRegOutVal=regValRn-8;
				tRegOutId=regIdRn;
			end
			else
			begin
				tMemAddr=tAguAddr;
				tMemData=regValRsB;
				tMemStore=1;
			end
		end


		UCMD_MOVB_MR: begin
			tMemAddr=tAguAddr;
			tMemLoad=1;
			tMemOpMode=5'h00;

			if(regIdRt==UREG_MR_MEMINC)
			begin
				tRegOutVal=regValRs+1;
				tRegOutId=regIdRs;
			end
		end

		UCMD_MOVW_MR: begin
			tMemAddr=tAguAddr;
			tMemLoad=1;
			tMemOpMode=5'h01;

			if(regIdRt==UREG_MR_MEMINC)
			begin
				tRegOutVal=regValRs+2;
				tRegOutId=regIdRs;
			end
		end

		UCMD_MOVL_MR: begin
			tMemAddr=tAguAddr;
			tMemLoad=1;
			tMemOpMode=5'h02;

			if(regIdRt==UREG_MR_MEMINC)
			begin
				tRegOutVal=regValRs+4;
				tRegOutId=regIdRs;
			end
		end

		UCMD_MOVQ_MR: begin
			tMemAddr=tAguAddr;
			tMemLoad=1;
			tMemOpMode=5'h03;

			if(regIdRt==UREG_MR_MEMINC)
			begin
				tRegOutVal=regValRs+8;
				tRegOutId=regIdRs;
			end
		end

		UCMD_ALU_ADD: begin
			tRegOutVal=regValRs+regValRt;
			tRegOutId=regIdRn;
		end

		UCMD_ALU_SUB: begin
			tRegOutVal=regValRs-regValRt;
			tRegOutId=regIdRn;
		end

		UCMD_ALU_MUL: begin
//			tRegOutVal=regValRs*regValRt;
			tRegOutId=regIdRn;
		
			tMacValRs = {32'h0, regValRs};
			tMacValRt = {32'h0, regValRt};
			tMacOp = 2'h3;
		end

		UCMD_ALU_AND: begin
			tRegOutVal=regValRs&regValRt;
			tRegOutId=regIdRn;
		end

		UCMD_ALU_OR: begin
			tRegOutVal=regValRs|regValRt;
			tRegOutId=regIdRn;
		end

		UCMD_ALU_XOR: begin
			tRegOutVal=regValRs^regValRt;
			tRegOutId=regIdRn;
		end
		

		UCMD_ALU_ADDC: begin
			tInAluC=ctlInSr[0];
			{tOutAluC, tRegOutVal}=
				{ 1'b0, regValRs+regValRt}+
				{32'h0, tInAluC};
			tCtlOutSr[0]=tOutAluC;
			tRegOutId=regIdRn;
		end

		UCMD_ALU_SUBC: begin
			tInAluC=ctlInSr[0];
			{tOutAluC, tRegOutVal}=
				{ 1'b0, regValRs-regValRt}-
				{32'h0, tInAluC};
			tCtlOutSr[0]=tOutAluC;
			tRegOutId=regIdRn;
		end

		UCMD_ALU_ADDV: begin
			{tOutAluC, tRegOutVal}=
				{ regValRs[31], regValRs}+
				{ regValRt[31], regValRt};
			tCtlOutSr[0]=tOutAluC^tRegOutVal[31];
			tRegOutId=regIdRn;
		end

		UCMD_ALU_SUBV: begin
			{tOutAluC, tRegOutVal}=
				{ regValRs[31], regValRs}-
				{ regValRt[31], regValRt};
			tCtlOutSr[0]=tOutAluC^tRegOutVal[31];
			tRegOutId=regIdRn;
		end

		UCMD_ALU_SHAD: begin
			tShadValRs=regValRs;
			tShadOp=2;
			tShadValRt=regValRt[7:0];
			tRegOutId=regIdRn;

/*
			if(regValRt[7])
			begin
				tMacValRs= {
					regValRs[31]?32'hFFFFFFFF:32'h00000000,
					regValRs};
				tShadOp=3;
				tShadValRt=(32-regValRt[4:0]);
				tRegOutId=regIdRn;
			end
			else
			begin
//				tRegOutVal=regValRs<<<regValRt[4:0];
//				tRegOutId=regIdRn;

				tMacValRs= {
					regValRs[31]?32'hFFFFFFFF:32'h00000000,
					regValRs};
				tShadOp=1;
				tShadValRt={ 1'b0, regValRt[4:0] };
				tRegOutId=regIdRn;
			end
*/
		end

		UCMD_ALU_SHLD: begin
			tShadValRs=regValRs;
			tShadOp=1;
			tShadValRt=regValRt[7:0];
			tRegOutId=regIdRn;

/*
			if(regValRt[7])
			begin
				tMacValRs = {32'h00000000, regValRs};
				tShadOp=2;
				tShadValRt=(32-regValRt[4:0]);
				tRegOutId=regIdRn;
			end
			else
			begin
				tMacValRs = {32'h00000000, regValRs};
				tShadOp=1;
				tShadValRt={ 1'b0, regValRt[4:0] };
				tRegOutId=regIdRn;
			end
*/
		end

		UCMD_ALU_SHADR: begin
			tShadValRs=regValRs;
			tShadOp=4;
			tShadValRt=regValRt[7:0];
			tRegOutId=regIdRn;

/*
			if(regValRt[7])
			begin
				tMacValRs= {
					regValRs[31]?32'hFFFFFFFF:32'h00000000,
					regValRs};
				tShadOp=1;
				tShadValRt=(32-regValRt[4:0]);
				tRegOutId=regIdRn;
			end
			else
			begin
				tMacValRs= {
					regValRs[31]?32'hFFFFFFFF:32'h00000000,
					regValRs};
				tShadOp=3;
				tShadValRt={ 1'b0, regValRt[4:0] };
				tRegOutId=regIdRn;
			end
*/
		end

		UCMD_ALU_SHLDR: begin
			tShadValRs=regValRs;
			tShadOp=3;
			tShadValRt=regValRt[7:0];
			tRegOutId=regIdRn;

/*
			if(regValRt[7])
			begin
				tMacValRs = {32'h00000000, regValRs};
				tShadOp=1;
				tShadValRt=(32-regValRt[4:0]);
				tRegOutId=regIdRn;
			end
			else
			begin
				tMacValRs = {32'h00000000, regValRs};
				tShadOp=2;
				tShadValRt={ 1'b0, regValRt[4:0] };
				tRegOutId=regIdRn;
			end
*/
		end


		UCMD_ALU_LDSH16: begin
			tRegOutVal={regValRs[15:0], 16'h0} +
				regValRt;
			tRegOutId=regIdRn;
		end
		
		UCMD_ALU_NOT: begin
			tRegOutVal=~regValRs;
			tRegOutId=regIdRn;
		end

		UCMD_ALU_SWAPB: begin
			tRegOutVal={
				regValRs[23:16],
				regValRs[31:24],
				regValRs[ 7: 0],
				regValRs[15: 8] };
			tRegOutId=regIdRn;
		end
		UCMD_ALU_SWAPW: begin
			tRegOutVal={
				regValRs[15: 0],
				regValRs[31:16]};
			tRegOutId=regIdRn;
		end
		UCMD_ALU_EXTUB: begin
			tRegOutVal={24'h0, regValRs[7:0]};
			tRegOutId=regIdRn;
		end
		UCMD_ALU_EXTUW: begin
			tRegOutVal={16'h0, regValRs[15:0]};
			tRegOutId=regIdRn;
		end
		UCMD_ALU_EXTSB: begin
			tRegOutVal={regValRs[7]?24'hF:24'h0, regValRs[7:0]};
			tRegOutId=regIdRn;
		end
		UCMD_ALU_EXTSW: begin
			tRegOutVal={regValRs[15]?16'hF:16'h0, regValRs[15:0]};
			tRegOutId=regIdRn;
		end

		UCMD_ALU_NEG: begin
			tRegOutVal=-regValRs;
			tRegOutId=regIdRn;
		end

		UCMD_ALU_NEGC: begin
			{tOutAluC, tRegOutVal}=
				{1'b1, ~regValRs}+
				(ctlInSr[0] ? 33'h0 : 33'h1);
			tRegOutId=regIdRn;
		end

		UCMD_ALU_DIV0S: begin
			tCtlOutSr[8] = regValRs[31];
			tCtlOutSr[9] = regValRt[31];
			tCtlOutSr[0] = regValRs[31] ^ regValRt[31];
		end

		UCMD_ALU_DIV1: begin
			tAluQ0 = ctlInSr[8];
			tAluM0 = ctlInSr[9];
			tAluT0 = ctlInSr[0];
			tAluQ1 = regValRs[31];
			tAluDn1[32:1] = regValRs;
			tAluDn1[   0] = tAluT0;
			if (tAluQ0 == tAluM0)
				tAluDn2 = tAluDn1 - {1'b0, regValRt};
			else
				tAluDn2 = tAluDn1 + {1'b0, regValRt};
			tAluM1 = tAluDn2[32];
			tAluQ2 = (tAluQ1 ^ tAluM0) ^ tAluM1;
			tAluT2 = ! (tAluQ2 ^ tAluM0);
			tRegOutVal = tAluDn2[31:0];
			tCtlOutSr[8] = tAluQ2;
			tCtlOutSr[0] = tAluT2;
			tRegOutId=regIdRn;
		end
		
		UCMD_CMP_EQ: begin
			tCtlOutSr[0]=(regValRs==regValRt);
		end

		UCMD_CMP_GT: begin
			tCtlOutSr[0]=(regValRs>regValRt)^
				(regValRs[31]^regValRt[31]);
		end

		UCMD_CMP_HI: begin
			tCtlOutSr[0]=(regValRs>regValRt);
		end

		UCMD_CMP_GE: begin
			tCtlOutSr[0]=(regValRs>=regValRt)^
				(regValRs[31]^regValRt[31]);
		end

		UCMD_CMP_HS: begin
			tCtlOutSr[0]=(regValRs>=regValRt);
		end

		UCMD_CMP_TST: begin
			tCtlOutSr[0]=((regValRs&regValRt)==0);
		end

		UCMD_ALU_MULUW: begin
			tMacValRs = {48'h0, regValRs[15:0]};
			tMacValRt = {48'h0, regValRt[15:0]};
			tMacOp = 2'h1;
		end

		UCMD_ALU_MULSW: begin
			tMacValRs = {
				regValRs[15]?48'hFFFFFFFFFFFF:48'h000000000000,
				regValRs[15:0]};
			tMacValRt = {
				regValRt[15]?48'hFFFFFFFFFFFF:48'h000000000000,
				regValRt[15:0]};
			tMacOp = 2'h1;
		end
		
		UCMD_ALU_DMULU: begin
			tMacValRs = {32'h0, regValRs};
			tMacValRt = {32'h0, regValRt};
			tMacOp = 2'h1;
		end

		UCMD_ALU_DMULS: begin
			tMacValRs = {regValRs[31]?32'hFFFFFFFF:32'h00000000, regValRs};
			tMacValRt = {regValRt[31]?32'hFFFFFFFF:32'h00000000, regValRt};
			tMacOp = 2'h1;
		end
		
		UCMD_BRAx: begin
			tCtlOutPc=tCtlBraPc;
		end
		UCMD_BSRx: begin
			tCtlOutPc=tCtlBraPc;
			tCtlOutPr=tCtlPrPc;
		end

		UCMD_RTSx: begin
			tCtlOutPc=ctlInPr;
		end

		UCMD_RTEx: begin
			tCtlOutPc=ctlInSPc;
			tCtlOutSr=ctlInSSr;
			tCtlOutSp=ctlInSGr;
		end


		UCMD_FPU_FADD: begin
			fpaIsEn = 1;
//			fpaIsSub = 0;
			tRegOutVal = fpaDst;
			tRegOutId = regIdRn;
		end

		UCMD_FPU_FSUB: begin
			fpaIsEn = 1;
//			fpaIsSub = 1;
			tRegOutVal = fpaDst;
			tRegOutId = regIdRn;
		end

		UCMD_FPU_FMUL: begin
			fpmIsEn = 1;
			tRegOutVal = fpmDst;
			tRegOutId = regIdRn;
		end

		UCMD_FPU_FABS: begin
			tRegOutVal[31] = 0;
			tRegOutVal[30:0] = regValRt[30:0];
			tRegOutId = regIdRn;
		end
		UCMD_FPU_FNEG: begin
			tRegOutVal[31] = !regValRt[31];
			tRegOutVal[30:0] = regValRt[30:0];
			tRegOutId = regIdRn;
		end

		UCMD_FPU_FRCP: begin
			tRegOutVal[31] = regValRt[31];
			tRegOutVal[30:0] = (0-(regValRt[30:0]-31'h3F800000))+
				31'h3F800000;
			tRegOutId = regIdRn;
		end

		UCMD_FPU_FSQRT: begin
			tRegOutVal[31] = regValRt[31];
			tRegOutVal[30:0] = ((regValRt[30:0]-31'h3F800000)>>>1)+
				31'h3F800000;
			tRegOutId = regIdRn;
		end

		UCMD_FPU_FCMPEQ: begin
			tCtlOutSr[0] = (regValRs == regValRt);
		end

		UCMD_FPU_FCMPGT: begin
			if(regValRs[31])
			begin
				if(regValRt[31])
				begin
					tCtlOutSr[0] = (regValRs[30:0] < regValRt[30:0]);
				end else begin
					tCtlOutSr[0] = 0;
				end
			end else begin
				if(!regValRt[31])
				begin
					tCtlOutSr[0] = (regValRs[30:0] > regValRt[30:0]);
				end else begin
					tCtlOutSr[0] = 1;
				end
			end
		end

		default: begin end
	endcase

 /*
	tMacValRu = tMacValRs * tMacValRt;
	case(tMacOp)
		2'h0: tCtlOutMac = ctlInMac;
		2'h1: tCtlOutMac = tMacValRu;
		2'h2: tCtlOutMac = ctlInMac + tMacValRu;
		2'h3: begin
			tCtlOutMac = ctlInMac;
			tRegOutVal = tMacValRu[31:0];
		end
	endcase
 */

	if(tMacOp!=0)
	begin
		case(tMacOp)
			2'h0: tCtlOutMac = {ctlInMach, ctlInMacl};
			2'h1: tCtlOutMac = tMacValRu;
			2'h2: tCtlOutMac = {ctlInMach, ctlInMacl} + tMacValRu;
			2'h3: begin
				tCtlOutMac = {ctlInMach, ctlInMacl};
				tRegOutVal = tMacValRu[31:0];
			end
		endcase

		tRegOutOK = (tMacOpB==tMacOp) ?
			UMEM_OK_OK : UMEM_OK_HOLD;
	end

/*
	case(tShadOp)
		3'h0: begin end
		3'h1: begin
			tShadValRu = tMacValRs << tShadValRt;
			tRegOutVal = tShadValRu[31:0];
		end
		3'h2: begin
			tShadValRu = tMacValRs >> tShadValRt;
			tRegOutVal = tShadValRu[31:0];
		end
		3'h3: begin
			tShadValRu = tMacValRs >>> tShadValRt;
			tRegOutVal = tShadValRu[31:0];
		end

		default: begin
		end
	endcase
*/

	if(tShadOp!=0)
		tRegOutVal = tShadValRn;
	
	if(tTriggerExc)
	begin
		tCtlOutSSr = ctlInSr;
		tCtlOutSPc = ctlInPc;
		tCtlOutSGr = ctlInSp;

		tCtlOutPc=ctlInVbr+32'h00000100;
		tCtlOutSr=ctlInSr;
		tCtlOutSr[30:28]=3'b111;
	end
end

reg[63:0]	tMacValRsA;
reg[63:0]	tMacValRtA;

reg[31:0]	tMacValRuA_AA;
reg[31:0]	tMacValRuA_AB;
reg[31:0]	tMacValRuA_BA;
reg[31:0]	tMacValRuA_BB;
reg[1:0]	tMacOpA0;
reg[1:0]	tMacOpA1;

reg[31:0]	tMacValRuB_AA;
reg[31:0]	tMacValRuB_AB;
reg[31:0]	tMacValRuB_BA;
reg[31:0]	tMacValRuB_BB;
reg[1:0]	tMacOpB0;
reg[1:0]	tMacOpB1;

always @*
begin
	/* EX+1 */
	tMacValRuA_AA	=
		{16'h0, tMacValRsA[15: 0]} *
		{16'h0, tMacValRsA[15: 0]};
	tMacValRuA_AB	=
		{16'h0, tMacValRsA[15: 0]} *
		{16'h0, tMacValRsA[31:16]};
	tMacValRuA_BA	=
		{16'h0, tMacValRsA[31:16]} *
		{16'h0, tMacValRsA[15: 0]};
	tMacValRuA_BB	=
		{16'h0, tMacValRsA[31:16]} *
		{16'h0, tMacValRsA[31:16]};
	tMacOpA1=tMacOpA0;

	/* EX+2 */
	tMacValRuA = {tMacValRuB_BB, tMacValRuB_AA} +
		{ 16'h0, tMacValRuB_AB, 16'h0} +
		{ 16'h0, tMacValRuB_BA, 16'h0};
	tMacOpB1 = tMacOpB0;
end

always @ (posedge clock)
begin
	/* EX+0 */
	tMacValRsA		<= tMacValRs;
	tMacValRtA		<= tMacValRt;
	tMacOpA0		<= tMacOp;

	/* EX+1 */
	tMacValRuB_AA	<= tMacValRuA_AA;
	tMacValRuB_AB	<= tMacValRuA_AB;
	tMacValRuB_BA	<= tMacValRuA_BA;
	tMacValRuB_BB	<= tMacValRuA_BB;
	tMacOpB0		<= tMacOpA1;

//	tMacValRu	<= {tMacValRuA_BB, tMacValRuA_AA} +
//		{ 16'h0, tMacValRuA_AB, 16'h0} +
//		{ 16'h0, tMacValRuA_BA, 16'h0};
//	tMacValRuA	<= tMacValRs * tMacValRt;

	/* EX+2 */
	tMacValRu	<= tMacValRuA;
	tMacOpB		<= tMacOpB1;
end


endmodule
