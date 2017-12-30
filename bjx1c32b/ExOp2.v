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

Execute Module
*/

`include "CoreDefs.v"

module ExOp2(clock, reset,
	opCmd,		opStepPc,
	regIdRs,	regValRs,
	regIdRt,	regValRt,
	regIdRn,	regValRn,
	immValRi,
	regOutId,	regOutVal,
	memAddr,	memData,
	memLoad,	memStore,
	ctlInSr,	ctlOutSr,
	ctlInPr,	ctlOutPr,
	ctlInPc,	ctlOutPc,
	ctlInMac,	ctlOutMac,

	ctlInGbr,	ctlOutGbr,
	ctlInVbr,	ctlOutVbr,
	ctlInSSr,	ctlOutSSr,
	ctlInSPc,	ctlOutSPr,
	ctlInSGr,	ctlOutSGr
	);

input			clock;
input			reset;

input[7:0]		opCmd;			//command opcode
input[3:0]		opStepPc;

input[6:0]		regIdRs;
input[6:0]		regIdRt;
input[6:0]		regIdRn;

input[31:0]		regValRs;		//Rs input value
input[31:0]		regValRt;		//Rt input value
input[31:0]		regValRn;		//Rn input value
input[31:0]		immValRi;		//immediate/disp value

output[31:0]	regOutVal;		//Rn output value
output[6:0]		regOutId;		//Rn, value to write


/* Memory */
output[31:0] memAddr;			//memory address
output[31:0] memData;			//memory data (write)
output memLoad;					//load from memory
output memStore;				//store to memory


/* Special Registers */
input[31:0]		ctlInSr;		//SR in
input[31:0]		ctlInPr;		//PR in
input[31:0]		ctlInPc;		//PC in
output[31:0]	ctlOutSr;		//SR out
output[31:0]	ctlOutPr;		//PR out
output[31:0]	ctlOutPc;		//PC out

input[63:0]		ctlInMac;		//MACH:MACL in
output[63:0]	ctlOutMac;		//MACH:MACL out

input[31:0]		ctlInGbr;
input[31:0]		ctlInVbr;
input[31:0]		ctlInSSr;
input[31:0]		ctlInSPc;

output[31:0]	ctlOutGbr;
output[31:0]	ctlOutVbr;
output[31:0]	ctlOutSSr;
output[31:0]	ctlOutSPr;


/* Temporary */
reg[31:0]	tRegOutVal;			//Rn, output value
reg[6:0]	tRegOutId;			//Rn, output register

reg[31:0]	tMemAddr;			//memory address
reg[31:0]	tMemData;			//memory data (write)
reg			tMemLoad;			//load from memory
reg			tMemStore;			//store to memory


reg[31:0]	tAguRtRi;			//AGU Rt+Ri
reg[31:0]	tAguAddr;			//AGU Address

reg[31:0]	tCtlOutSr;
reg[31:0]	tCtlOutPr;
reg[31:0]	tCtlOutPc;
reg[63:0]	tCtlOutMac;

assign regOutVal = tRegOutVal;
assign regOutId = tRegOutId;

assign	ctlOutSr = tCtlOutSr;
assign	ctlOutPr = tCtlOutPr;
assign	ctlOutPc = tCtlOutPc;
assign	ctlOutMac = tCtlOutMac;


/* EX */
always @ (clock)
begin
	tRegOutVal=0;
	tRegOutId=UREG_ZZR;
	
	tMemAddr=0;
	tMemData=0;
	tMemLoad=0;
	tMemStore=0;
	
	tCtlOutSr=ctlInSr;
	tCtlOutPr=ctlInPr;
	tCtlOutPc=ctlInPc+{28'h0, opStepPc};
	tCtlOutMac=ctlInMac;

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
			3'h1:	tAguAddr=regValRn+tAguRtRi*2;
			3'h2:	tAguAddr=regValRn+tAguRtRi*4;
			3'h3:	tAguAddr=regValRn+tAguRtRi*8;
			3'h4:	tAguAddr=regValRs+tAguRtRi;
			3'h5:	tAguAddr=regValRs+tAguRtRi*2;
			3'h6:	tAguAddr=regValRs+tAguRtRi*4;
			3'h7:	tAguAddr=regValRs+tAguRtRi*8;
		endcase
	end

	case(opCmd)
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

			if(regIdRt==UREG_MR_MEMINC)
			begin
				tRegOutVal=regValRs+1;
				tRegOutId=regIdRs;
			end
		end

		UCMD_MOVW_MR: begin
			tMemAddr=tAguAddr;
			tMemLoad=1;

			if(regIdRt==UREG_MR_MEMINC)
			begin
				tRegOutVal=regValRs+2;
				tRegOutId=regIdRs;
			end
		end

		UCMD_MOVL_MR: begin
			tMemAddr=tAguAddr;
			tMemLoad=1;

			if(regIdRt==UREG_MR_MEMINC)
			begin
				tRegOutVal=regValRs+4;
				tRegOutId=regIdRs;
			end
		end

		UCMD_MOVQ_MR: begin
			tMemAddr=tAguAddr;
			tMemLoad=1;

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
			tRegOutVal=regValRs*regValRt;
			tRegOutId=regIdRn;
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
		
		UCMD_ALU_SHAD: begin
			if(regValRt[7])
			begin
				if(regValRt[4:0]!=0)
				begin
					tRegOutVal=regValRs>>>(32-regValRt[4:0]);
					tRegOutId=regIdRn;
				end
				else
				begin
					tRegOutVal=regValRs[31]?32'hFFFFFFFF:32'h00000000;
				end
			end
			else
			begin
				tRegOutVal=regValRs<<<regValRt[4:0];
				tRegOutId=regIdRn;
			end
		end

		UCMD_ALU_SHLD: begin
			if(regValRt[7])
			begin
				if(regValRt[4:0]!=0)
				begin
					tRegOutVal=regValRs>>(32-regValRt[4:0]);
					tRegOutId=regIdRn;
				end
				else
				begin
					tRegOutVal=0;
					tRegOutId=regIdRn;
				end
			end
			else
			begin
				tRegOutVal=regValRs<<regValRt[4:0];
				tRegOutId=regIdRn;
			end
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
		
		UCMD_ALU_DMULU: begin
			tCtlOutMac=
				{32'h0, regValRs} *
				{32'h0, regValRt};
		end

		UCMD_ALU_DMULS: begin
			tCtlOutMac=
				{regValRs[31]?32'hFFFFFFFF:32'h00000000, regValRs} *
				{regValRt[31]?32'hFFFFFFFF:32'h00000000, regValRt};
		end
		
		default: begin end
	endcase
end

// always @ (posedge clock)
// begin
// end


endmodule
