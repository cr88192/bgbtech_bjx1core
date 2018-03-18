/*
Execute Module (64-bit, Secondary)

The secondary execute units omit some features:
	Can't access memory.
	Dont have a multiply or shift.
	...
*/

`include "CoreDefs.v"

module ExOp64_3B(
	/* verilator lint_off UNUSED */
	clock,		reset,
	opCmd,		opStepPc,
	regIdRs,	regValRs,
	regIdRt,	regValRt,
	regIdRn,	regValRn,
	immValRi,	idInGenPc,
	regOutId,	regOutVal,
	regOutOK,	ctlInSr
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


/* Special Registers */
input[63:0]		ctlInSr;		//SR in
// input[63:0]		ctlInPr;		//PR in
// input[63:0]		ctlInPc;		//PC in

// input[63:0]	ctlInMach;		//MACH:MACL in
// input[63:0]	ctlInMacl;		//MACH:MACL in
// output[63:0]	ctlOutMach;		//MACH:MACL out
// output[63:0]	ctlOutMacl;		//MACH:MACL out


/* Temporary */
reg[63:0]	tRegOutVal;			//Rn, output value
reg[6:0]	tRegOutId;			//Rn, output register
reg[1:0]	tRegOutOK;			//execute status


/* verilator lint_off UNOPTFLAT */

reg[63:0]	tAguRtRi;			//AGU Rt+Ri
reg[63:0]	tAguRtRiSc;			//AGU (Rt+Ri)*Sc
reg[63:0]	tAguAddr;			//AGU Address

/* verilator lint_on UNOPTFLAT */


assign regOutVal = tRegOutVal;
assign regOutId = tRegOutId;
assign regOutOK = tRegOutOK;

reg			tInAluC;
reg			tOutAluC;
reg			tTriggerExc;

/*
reg[63:0]	tShadValRs;
reg[ 7:0]	tShadValRt;
wire[63:0]	tShadValRn;
reg[ 2:0]	tShadOp;

ExShad64	sh64(
	clock, reset,
	tShadValRs, tShadValRt,
	tShadValRn, tShadOp);
*/

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
		
	tInAluC=1'bX;
	tOutAluC=1'bX;

//	tMacValRs=64'hX;
//	tMacValRt=64'hX;
//	tMacValRu=64'hX;
//	tMacOp=0;
	
//	tShadValRs=32'hXXXXXXXX;
//	tShadValRt=8'hXX;
//	tShadOp=0;
	
	tTriggerExc=0;

//	tCtlNxtPc=ctlInPc+{28'h0, opStepPc};
//	tCtlPrPc=tCtlNxtPc + 2;
//	tCtlBraPc=tCtlPrPc + (immValRi<<1);


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

/*
	tAguRtRi=regValRt+immValRi;
	case(opCmd[1:0])
		2'h0:	tAguRtRiSc=tAguRtRi;
		2'h1:	tAguRtRiSc={tAguRtRi[62:0], 1'b0};
		2'h2:	tAguRtRiSc={tAguRtRi[61:0], 2'b0};
		2'h3:	tAguRtRiSc={tAguRtRi[60:0], 3'b0};
	endcase
	tAguAddr=(opCmd[2]?regValRs:regValRn)+
		((regIdRt==UREG_R0)?tAguRtRi:tAguRtRiSc);
*/

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

/*
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
*/

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
		
//			tMacValRs = {32'h0, regValRs};
//			tMacValRt = {32'h0, regValRt};
//			tMacOp = 2'h3;
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
//			tCtlOutSr[0]=tOutAluC;
			tRegOutId=regIdRn;
		end

		UCMD_ALU_SUBC: begin
			tInAluC=ctlInSr[0];
			{tOutAluC, tRegOutVal}=
				{ 1'b0, regValRs-regValRt}-
				{64'h0, tInAluC};
//			tCtlOutSr[0]=tOutAluC;
			tRegOutId=regIdRn;
		end

		UCMD_ALU_ADDV: begin
			{tOutAluC, tRegOutVal}=
				{ regValRs[63], regValRs}+
				{ regValRt[63], regValRt};
//			tCtlOutSr[0]=tOutAluC^tRegOutVal[31];
			tRegOutId=regIdRn;
		end

		UCMD_ALU_SUBV: begin
			{tOutAluC, tRegOutVal}=
				{ regValRs[63], regValRs}-
				{ regValRt[63], regValRt};
//			tCtlOutSr[0]=tOutAluC^tRegOutVal[31];
			tRegOutId=regIdRn;
		end

/*
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
*/

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
								
		default: begin end
	endcase

end


endmodule
