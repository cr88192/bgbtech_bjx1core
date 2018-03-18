/*
Execute Module (64-bit, Primary)
*/

`include "CoreDefs.v"

`include "ExShad64.v"

module ExOp64_3A(
	/* verilator lint_off UNUSED */
	clock,		reset,
	opCmd,		opStepPc,
	regIdRs,	regValRs,
	regIdRt,	regValRt,
	regIdRn,	regValRn,
	immValRi,	idInGenPc,
	regOutId,	regOutVal,
	regOutOK,

	memAddr,	memData,
	memLoad,	memStore,
	memOpMode,	memOpCmd2,

	ctlInSr,	ctlOutSr,
	ctlInPr,	ctlOutPr,
	ctlInPc,	ctlOutPc,
	ctlInMach,	ctlOutMach,
	ctlInMacl,	ctlOutMacl,
	ctlInSp,	ctlOutSp,

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
input[63:0]		idInGenPc;		//ID's Next PC (Next Fetch)

input[6:0]		regIdRs;
input[6:0]		regIdRt;
input[6:0]		regIdRn;

input[63:0]		regValRs;		//Rs input value
input[63:0]		regValRt;		//Rt input value
input[63:0]		regValRn;		//Rn input value
input[63:0]		immValRi;		//immediate/disp value

output[63:0]	regOutVal;		//Rn output value
output[6:0]		regOutId;		//Rn, value to write
output[1:0]		regOutOK;		//execute status

/* Memory */
output[63:0]	memAddr;		//memory address
output[63:0]	memData;		//memory data (write)
output			memLoad;		//load from memory
output			memStore;		//store to memory
output[4:0]		memOpMode;		//mem op mode
output[7:0]		memOpCmd2;		//mem EX chain


/* Special Registers */
input[63:0]		ctlInSr;		//SR in
input[63:0]		ctlInPr;		//PR in
input[63:0]		ctlInPc;		//PC in
output[63:0]	ctlOutSr;		//SR out
output[63:0]	ctlOutPr;		//PR out
output[63:0]	ctlOutPc;		//PC out

input[63:0]		ctlInMach;		//MACH:MACL in
input[63:0]		ctlInMacl;		//MACH:MACL in
output[63:0]	ctlOutMach;		//MACH:MACL out
output[63:0]	ctlOutMacl;		//MACH:MACL out

input[63:0]		ctlInSp;		//SP in
output[63:0]	ctlOutSp;		//SP out

input[63:0]		ctlInGbr;
input[63:0]		ctlInVbr;
input[63:0]		ctlInSSr;
input[63:0]		ctlInSPc;
input[63:0]		ctlInSGr;

output[63:0]	ctlOutGbr;
output[63:0]	ctlOutVbr;
output[63:0]	ctlOutSSr;
output[63:0]	ctlOutSPc;
output[63:0]	ctlOutSGr;


/* Temporary */
reg[63:0]	tRegOutVal;			//Rn, output value
reg[6:0]	tRegOutId;			//Rn, output register
reg[1:0]	tRegOutOK;			//execute status

reg[63:0]	tMemAddr;			//memory address
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

reg[63:0]	tAguRtRi;			//AGU Rt+Ri
reg[63:0]	tAguRtRiSc;			//AGU (Rt+Ri)*Sc
reg[63:0]	tAguAddr;			//AGU Address

reg[63:0]	tCtlOutSr;
reg[63:0]	tCtlOutPr;
reg[63:0]	tCtlOutPc;
reg[63:0]	tCtlOutMach;
reg[63:0]	tCtlOutMacl;
reg[63:0]	tCtlOutSp;

reg[63:0]	tCtlNxtPc;
reg[63:0]	tCtlBraPc;
reg[63:0]	tCtlPrPc;

reg[63:0]	tCtlOutGbr;
reg[63:0]	tCtlOutVbr;
reg[63:0]	tCtlOutSSr;
reg[63:0]	tCtlOutSPc;
reg[63:0]	tCtlOutSGr;

/* verilator lint_on UNOPTFLAT */


assign regOutVal = tRegOutVal;
assign regOutId = tRegOutId;
assign regOutOK = tRegOutOK;

assign	ctlOutSr = tCtlOutSr;
assign	ctlOutPr = tCtlOutPr;
assign	ctlOutPc = tCtlOutPc;
assign	ctlOutMach = tCtlOutMach;
assign	ctlOutMacl = tCtlOutMacl;
assign	ctlOutSp = tCtlOutSp;

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
reg[127:0]	tMacValRu;
reg[127:0]	tMacValRuA;
reg[1:0]	tMacOpA;
reg[1:0]	tMacOpB;


reg[63:0]	tShadValRs;
reg[ 7:0]	tShadValRt;
wire[63:0]	tShadValRn;
reg[ 2:0]	tShadOp;

// reg[63:0]	tShadValRu;

ExShad64	sh64(
	clock, reset,
	tShadValRs, tShadValRt,
	tShadValRn, tShadOp);

reg[64:0]	tAluDn1;
reg[64:0]	tAluDn2;
reg			tAluQ0;
reg			tAluM0;
reg			tAluT0;
reg			tAluQ1;
reg			tAluM1;
reg			tAluT1;
reg			tAluQ2;
reg			tAluM2;
reg			tAluT2;

/* EX */
always @*
begin
	tRegOutVal=0;
	tRegOutId=UREG_ZZR;
	tRegOutOK=UMEM_OK_OK;
	
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
	
	tShadValRs=64'hXXXXXXXX;
	tShadValRt=8'hXX;
	tShadOp=0;
	
	tTriggerExc=0;

	tCtlNxtPc=ctlInPc+{60'h0, opStepPc};
	tCtlPrPc=tCtlNxtPc + 2;
	tCtlBraPc=tCtlPrPc + (immValRi<<1);
	
	tCtlOutSr=ctlInSr;
	tCtlOutPr=ctlInPr;
	tCtlOutPc=idInGenPc;
	tCtlOutMach=ctlInMach;
	tCtlOutMacl=ctlInMacl;
	tCtlOutSp=ctlInSp;

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
		2'h1:	tAguRtRiSc={tAguRtRi[62:0], 1'b0};
		2'h2:	tAguRtRiSc={tAguRtRi[61:0], 2'b0};
		2'h3:	tAguRtRiSc={tAguRtRi[60:0], 3'b0};
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
				tMemData=regValRs;
				tMemStore=1;
				tRegOutVal=regValRn-1;
				tRegOutId=regIdRn;
			end
			else
			begin
				tMemAddr=tAguAddr;
				tMemData=regValRs;
				tMemStore=1;
			end
		end

		UCMD_MOVW_RM: begin
			tMemOpMode=5'h01;

			if(regIdRt==UREG_MR_MEMDEC)
			begin
				tMemAddr=tAguAddr-2;
				tMemData=regValRs;
				tMemStore=1;
				tRegOutVal=regValRn-2;
				tRegOutId=regIdRn;
			end
			else
			begin
				tMemAddr=tAguAddr;
				tMemData=regValRs;
				tMemStore=1;
			end
		end

		UCMD_MOVL_RM: begin
			tMemOpMode=5'h02;
			if(regIdRt==UREG_MR_MEMDEC)
			begin
				tMemAddr=tAguAddr-4;
				tMemData=regValRs;
				tMemStore=1;
				tRegOutVal=regValRn-4;
				tRegOutId=regIdRn;
			end
			else
			begin
				tMemAddr=tAguAddr;
				tMemData=regValRs;
				tMemStore=1;
			end
		end

		UCMD_MOVQ_RM: begin
			tMemOpMode=5'h03;
			if(regIdRt==UREG_MR_MEMDEC)
			begin
				tMemAddr=tAguAddr-8;
				tMemData=regValRs;
				tMemStore=1;
				tRegOutVal=regValRn-8;
				tRegOutId=regIdRn;
			end
			else
			begin
				tMemAddr=tAguAddr;
				tMemData=regValRs;
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
		
			tMacValRs = {32'h0, regValRs[31:0]};
			tMacValRt = {32'h0, regValRt[31:0]};
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
				{64'h0, tInAluC};
			tCtlOutSr[0]=tOutAluC;
			tRegOutId=regIdRn;
		end

		UCMD_ALU_SUBC: begin
			tInAluC=ctlInSr[0];
			{tOutAluC, tRegOutVal}=
				{ 1'b0, regValRs-regValRt}-
				{64'h0, tInAluC};
			tCtlOutSr[0]=tOutAluC;
			tRegOutId=regIdRn;
		end

		UCMD_ALU_ADDV: begin
			{tOutAluC, tRegOutVal}=
				{ regValRs[63], regValRs}+
				{ regValRt[63], regValRt};
			tCtlOutSr[0]=tOutAluC^tRegOutVal[63];
			tRegOutId=regIdRn;
		end

		UCMD_ALU_SUBV: begin
			{tOutAluC, tRegOutVal}=
				{ regValRs[63], regValRs}-
				{ regValRt[63], regValRt};
			tCtlOutSr[0]=tOutAluC^tRegOutVal[63];
			tRegOutId=regIdRn;
		end

		UCMD_ALU_SHAD: begin
			tShadValRs=regValRs;
			tShadOp=2;
			tShadValRt=regValRt[7:0];
			tRegOutId=regIdRn;
		end

		UCMD_ALU_SHLD: begin
			tShadValRs=regValRs;
			tShadOp=1;
			tShadValRt=regValRt[7:0];
			tRegOutId=regIdRn;
		end

		UCMD_ALU_SHADR: begin
			tShadValRs=regValRs;
			tShadOp=4;
			tShadValRt=regValRt[7:0];
			tRegOutId=regIdRn;
		end

		UCMD_ALU_SHLDR: begin
			tShadValRs=regValRs;
			tShadOp=3;
			tShadValRt=regValRt[7:0];
			tRegOutId=regIdRn;
		end


		UCMD_ALU_LDSH16: begin
			tRegOutVal={regValRs[47:0], 16'h0} +
				regValRt;
			tRegOutId=regIdRn;
		end
		
		UCMD_ALU_NOT: begin
			tRegOutVal=~regValRs;
			tRegOutId=regIdRn;
		end

		UCMD_ALU_SWAPB: begin
			tRegOutVal={
				regValRs[55:48],
				regValRs[63:56],
				regValRs[39:32],
				regValRs[47:40],
				regValRs[23:16],
				regValRs[31:24],
				regValRs[ 7: 0],
				regValRs[15: 8]
				};
			tRegOutId=regIdRn;
		end
		UCMD_ALU_SWAPW: begin
			tRegOutVal={
				regValRs[47:32],
				regValRs[63:48],
				regValRs[15: 0],
				regValRs[31:16]};
			tRegOutId=regIdRn;
		end
		UCMD_ALU_EXTUB: begin
			tRegOutVal={56'h0, regValRs[7:0]};
			tRegOutId=regIdRn;
		end
		UCMD_ALU_EXTUW: begin
			tRegOutVal={48'h0, regValRs[15:0]};
			tRegOutId=regIdRn;
		end
		UCMD_ALU_EXTSB: begin
			tRegOutVal={regValRs[7]?56'hFF_FFFF_FFFF_FFFF:56'h0, regValRs[7:0]};
			tRegOutId=regIdRn;
		end
		UCMD_ALU_EXTSW: begin
			tRegOutVal={regValRs[15]?48'hFFFF_FFFF_FFFF:48'h0, regValRs[15:0]};
			tRegOutId=regIdRn;
		end

		UCMD_ALU_NEG: begin
			tRegOutVal=-regValRs;
			tRegOutId=regIdRn;
		end

		UCMD_ALU_NEGC: begin
			{tOutAluC, tRegOutVal}=
				{1'b1, ~regValRs}+
				(ctlInSr[0] ? 65'h0 : 65'h1);
			tRegOutId=regIdRn;
		end

		UCMD_ALU_DIV0S: begin
			tCtlOutSr[8] = regValRs[63];
			tCtlOutSr[9] = regValRt[63];
			tCtlOutSr[0] = regValRs[63] ^ regValRt[63];
		end

		UCMD_ALU_DIV1: begin
			tAluQ0 = ctlInSr[8];
			tAluM0 = ctlInSr[9];
			tAluT0 = ctlInSr[0];
			tAluQ1 = regValRs[63];
			tAluDn1[64:1] = regValRs;
			tAluDn1[   0] = tAluT0;
			if (tAluQ0 == tAluM0)
				tAluDn2 = tAluDn1 - {1'b0, regValRt};
			else
				tAluDn2 = tAluDn1 + {1'b0, regValRt};
			tAluM1 = tAluDn2[64];
			tAluQ2 = (tAluQ1 ^ tAluM0) ^ tAluM1;
			tAluT2 = ! (tAluQ2 ^ tAluM0);
			tRegOutVal = tAluDn2[63:0];
			tCtlOutSr[8] = tAluQ2;
			tCtlOutSr[0] = tAluT2;
			tRegOutId=regIdRn;
		end
		
		UCMD_CMP_EQ: begin
			tCtlOutSr[0]=(regValRs[31:0]==regValRt[31:0]);
		end

		UCMD_CMP_GT: begin
			tCtlOutSr[0]=(regValRs[31:0]>regValRt[31:0])^
				(regValRs[31]^regValRt[31]);
		end

		UCMD_CMP_HI: begin
			tCtlOutSr[0]=(regValRs[31:0]>regValRt[31:0]);
		end

		UCMD_CMP_GE: begin
			tCtlOutSr[0]=(regValRs[31:0]>=regValRt[31:0])^
				(regValRs[31]^regValRt[31]);
		end

		UCMD_CMP_HS: begin
			tCtlOutSr[0]=(regValRs[31:0]>=regValRt[31:0]);
		end

		UCMD_CMP_TST: begin
			tCtlOutSr[0]=((regValRs[31:0] & regValRt[31:0])==0);
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
			tMacValRs = {32'h0, regValRs[31:0]};
			tMacValRt = {32'h0, regValRt[31:0]};
			tMacOp = 2'h1;
		end

		UCMD_ALU_DMULS: begin
			tMacValRs = {regValRs[31]?32'hFFFFFFFF:32'h00000000, regValRs[31:0]};
			tMacValRt = {regValRt[31]?32'hFFFFFFFF:32'h00000000, regValRt[31:0]};
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
		
		default: begin end
	endcase

	if(tMacOp!=0)
	begin
		case(tMacOp)
			2'h0:
				{tCtlOutMach, tCtlOutMacl} =
					{ ctlInMach, ctlInMacl };
			2'h1:
				{tCtlOutMach, tCtlOutMacl} = tMacValRu;
			2'h2:
				{tCtlOutMach, tCtlOutMacl} =
					{ ctlInMach, ctlInMacl } + tMacValRu;
			2'h3: begin
				{tCtlOutMach, tCtlOutMacl} =
					{ ctlInMach, ctlInMacl };
				tRegOutVal = tMacValRu[63:0];
			end
		endcase

		tRegOutOK = (tMacOpB==tMacOp) ?
			UMEM_OK_OK : UMEM_OK_HOLD;
	end

	if(tShadOp!=0)
		tRegOutVal = tShadValRn;
	
	if(tTriggerExc)
	begin
		tCtlOutSSr = ctlInSr;
		tCtlOutSPc = ctlInPc;
		tCtlOutSGr = ctlInSp;

		tCtlOutPc=ctlInVbr+64'h00000100;
		tCtlOutSr=ctlInSr;
		tCtlOutSr[30:28]=3'b111;
	end
end

reg[63:0]	tMacValRsA;
reg[63:0]	tMacValRtA;

reg[31:0]	tMacValRuA_AA;
reg[31:0]	tMacValRuA_AB;
reg[31:0]	tMacValRuA_AC;
reg[31:0]	tMacValRuA_AD;
reg[31:0]	tMacValRuA_BA;
reg[31:0]	tMacValRuA_BB;
reg[31:0]	tMacValRuA_BC;
reg[31:0]	tMacValRuA_BD;
reg[31:0]	tMacValRuA_CA;
reg[31:0]	tMacValRuA_CB;
reg[31:0]	tMacValRuA_CC;
reg[31:0]	tMacValRuA_CD;
reg[31:0]	tMacValRuA_DA;
reg[31:0]	tMacValRuA_DB;
reg[31:0]	tMacValRuA_DC;
reg[31:0]	tMacValRuA_DD;

reg[1:0]	tMacOpA0;
reg[1:0]	tMacOpA1;

reg[31:0]	tMacValRuB_AA;
reg[31:0]	tMacValRuB_AB;
reg[31:0]	tMacValRuB_AC;
reg[31:0]	tMacValRuB_AD;
reg[31:0]	tMacValRuB_BA;
reg[31:0]	tMacValRuB_BB;
reg[31:0]	tMacValRuB_BC;
reg[31:0]	tMacValRuB_BD;
reg[31:0]	tMacValRuB_CA;
reg[31:0]	tMacValRuB_CB;
reg[31:0]	tMacValRuB_CC;
reg[31:0]	tMacValRuB_CD;
reg[31:0]	tMacValRuB_DA;
reg[31:0]	tMacValRuB_DB;
reg[31:0]	tMacValRuB_DC;
reg[31:0]	tMacValRuB_DD;

reg[1:0]	tMacOpB0;
reg[1:0]	tMacOpB1;

always @*
begin
	/* EX+1 */
	tMacValRuA_AA	=
		{16'h0, tMacValRsA[15: 0]} *
		{16'h0, tMacValRtA[15: 0]};
	tMacValRuA_AB	=
		{16'h0, tMacValRsA[15: 0]} *
		{16'h0, tMacValRtA[31:16]};
	tMacValRuA_AC	=
		{16'h0, tMacValRsA[15: 0]} *
		{16'h0, tMacValRtA[47:32]};
	tMacValRuA_AD	=
		{16'h0, tMacValRsA[15: 0]} *
		{16'h0, tMacValRtA[63:48]};

	tMacValRuA_BA	=
		{16'h0, tMacValRsA[31:16]} *
		{16'h0, tMacValRtA[15: 0]};
	tMacValRuA_BB	=
		{16'h0, tMacValRsA[31:16]} *
		{16'h0, tMacValRtA[31:16]};
	tMacValRuA_BC	=
		{16'h0, tMacValRsA[31:16]} *
		{16'h0, tMacValRtA[47:32]};
	tMacValRuA_BD	=
		{16'h0, tMacValRsA[31:16]} *
		{16'h0, tMacValRtA[56:48]};

	tMacValRuA_CA	=
		{16'h0, tMacValRsA[47:32]} *
		{16'h0, tMacValRtA[15: 0]};
	tMacValRuA_CB	=
		{16'h0, tMacValRsA[47:32]} *
		{16'h0, tMacValRtA[31:16]};
	tMacValRuA_CC	=
		{16'h0, tMacValRsA[47:32]} *
		{16'h0, tMacValRtA[47:32]};
	tMacValRuA_CD	=
		{16'h0, tMacValRsA[47:32]} *
		{16'h0, tMacValRtA[63:48]};

	tMacValRuA_DA	=
		{16'h0, tMacValRsA[63:48]} *
		{16'h0, tMacValRtA[15: 0]};
	tMacValRuA_DB	=
		{16'h0, tMacValRsA[63:48]} *
		{16'h0, tMacValRtA[31:16]};
	tMacValRuA_DC	=
		{16'h0, tMacValRsA[63:48]} *
		{16'h0, tMacValRtA[47:32]};
	tMacValRuA_DD	=
		{16'h0, tMacValRsA[63:48]} *
		{16'h0, tMacValRtA[56:48]};

	tMacOpA1=tMacOpA0;

	/* EX+2 */
	tMacValRuA = {tMacValRuB_DD, tMacValRuB_CC, tMacValRuB_BB, tMacValRuB_AA} +
		{ 48'h0, tMacValRuB_AD, tMacValRuB_AB, 16'h0} +
		{ 48'h0, tMacValRuB_DA, tMacValRuB_BA, 16'h0} +
		{ 64'h0, tMacValRuB_AC, 32'h0} +
		{ 64'h0, tMacValRuB_CA, 32'h0};
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
	tMacValRuB_AC	<= tMacValRuA_AC;
	tMacValRuB_AD	<= tMacValRuA_AD;
	tMacValRuB_BA	<= tMacValRuA_BA;
	tMacValRuB_BB	<= tMacValRuA_BB;
	tMacValRuB_BA	<= tMacValRuA_BC;
	tMacValRuB_BB	<= tMacValRuA_BD;
	tMacValRuB_CA	<= tMacValRuA_CA;
	tMacValRuB_CB	<= tMacValRuA_DB;
	tMacValRuB_CC	<= tMacValRuA_CC;
	tMacValRuB_CD	<= tMacValRuA_CD;
	tMacValRuB_DA	<= tMacValRuA_DA;
	tMacValRuB_DB	<= tMacValRuA_DB;
	tMacValRuB_DC	<= tMacValRuA_DC;
	tMacValRuB_DD	<= tMacValRuA_DD;

	tMacOpB0		<= tMacOpA1;

	/* EX+2 */
	tMacValRu	<= tMacValRuA;
	tMacOpB		<= tMacOpB1;
end


endmodule
