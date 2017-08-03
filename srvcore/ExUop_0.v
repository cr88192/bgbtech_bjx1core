/*
Microcode Execute

Microcode Op
  31:24, Opcode
     23, Last Uop (Reset to Start)
 */

`include "ArithAlu.v"
`include "MemAlu.v"
`include "GpReg.v"
`include "MemTile.v"
`include "DecOp.v"

/*
module ExUop(
	clk,
	istrWord,
	uopWord,
	uopCmd,
	idRegD,
	idRegS,
	idRegT,
	idImm
	);
*/

module ExUop(clk);

input clk;			//clock

/*
input[31:0] istrWord;	//source instruction word
input[31:0] uopWord;	//uop word

input[7:0] uopCmd;
input[6:0] idRegD;	//Source Opcode D (or N)
input[6:0] idRegS;	//Source Opcode S (or M)
input[6:0] idRegT;	//Source Opcode T
input[31:0] idImm;	//Source Immediate
*/

reg[31:0] istrWord;	//source instruction word
reg[31:0] uopWord;	//uop word

reg[7:0] uopCmd;
reg[6:0] idRegD;	//Source Opcode D (or N)
reg[6:0] idRegS;	//Source Opcode S (or M)
reg[6:0] idRegT;	//Source Opcode T
reg[31:0] idImm;	//Source Immediate
reg[11:0] idUopPc;	//Instruction Uop PC

parameter[7:0] UOP_BRINST	= 8'h00;	//Branch Decoded Instruction
parameter[7:0] UOP_ADDI		= 8'h01;
parameter[7:0] UOP_SUBI		= 8'h02;
parameter[7:0] UOP_MULI		= 8'h03;
parameter[7:0] UOP_ANDI		= 8'h04;
parameter[7:0] UOP_ORI		= 8'h05;
parameter[7:0] UOP_XORI		= 8'h06;
parameter[7:0] UOP_SHLI		= 8'h07;
parameter[7:0] UOP_SHRI		= 8'h08;
parameter[7:0] UOP_SARI		= 8'h09;
parameter[7:0] UOP_ADDCI	= 8'h0A;
parameter[7:0] UOP_CMPEQI	= 8'h0B;
parameter[7:0] UOP_CMPGTI	= 8'h0C;
parameter[7:0] UOP_CMPGEI	= 8'h0D;
parameter[7:0] UOP_CMPHSI	= 8'h0E;
parameter[7:0] UOP_CMPHII	= 8'h0F;
parameter[7:0] UOP_GETINST	= 8'h10;	//Fetch Instruction
parameter[7:0] UOP_ADDQ		= 8'h11;
parameter[7:0] UOP_SUBQ		= 8'h12;
parameter[7:0] UOP_MULQ		= 8'h13;
parameter[7:0] UOP_ANDQ		= 8'h14;
parameter[7:0] UOP_ORQ		= 8'h15;
parameter[7:0] UOP_XORQ		= 8'h16;
parameter[7:0] UOP_SHLQ		= 8'h17;
parameter[7:0] UOP_SHRQ		= 8'h18;
parameter[7:0] UOP_SARQ		= 8'h19;
parameter[7:0] UOP_ADDCQ	= 8'h1A;
parameter[7:0] UOP_CMPEQQ	= 8'h1B;
parameter[7:0] UOP_CMPGTQ	= 8'h1C;
parameter[7:0] UOP_CMPGEQ	= 8'h1D;
parameter[7:0] UOP_CMPHSQ	= 8'h1E;
parameter[7:0] UOP_CMPHIQ	= 8'h1F;

parameter[7:0] UOP_LEAB		= 8'h21;
parameter[7:0] UOP_LEAW		= 8'h22;
parameter[7:0] UOP_LEAI		= 8'h23;
parameter[7:0] UOP_LEAQ		= 8'h24;
parameter[7:0] UOP_LEAV		= 8'h25;

parameter[7:0] UOP_MOVLDB	= 8'h31;
parameter[7:0] UOP_MOVLDW	= 8'h32;
parameter[7:0] UOP_MOVLDI	= 8'h33;
parameter[7:0] UOP_MOVLDQ	= 8'h34;

parameter[7:0] UOP_MOVLDUB	= 8'h36;
parameter[7:0] UOP_MOVLDUW	= 8'h37;

parameter[7:0] UOP_MOVSTB	= 8'h39;
parameter[7:0] UOP_MOVSTW	= 8'h3A;
parameter[7:0] UOP_MOVSTI	= 8'h3B;
parameter[7:0] UOP_MOVSTQ	= 8'h3C;

reg[63:0] iDataD;
reg[63:0] iDataS;
reg[63:0] iDataT;

reg[63:0] tData2D;
reg[6:0] tIdReg2D;
reg tIsWr2D;
reg tIsQw2D;

reg[63:0] oData2D;
reg[6:0] oIdReg2D;
reg oIsWr2D;
reg oIsQw2D;


// ArithAlu alu1;
// MemAlu agu1;
GpReg regs(clk,
		oIsWr2D, oIsWr2D, oIdReg2D, oData2D,
		idRegD, iDataD, idRegS, iDataS, idRegT, iDataT);

reg[63:0] tDataAluD;
reg[31:0] regSr;
reg[31:0] tRegSr;

reg[63:0] regPc;
reg[63:0] regNextPc;

reg[3:0] aluCmd;
reg[3:0] tAluSr;
ArithAlu alu1(clk, aluCmd,
	iDataS, iDataT, tDataAluD, regSr[3:0], tAluSr);

reg[63:0] tDataAguD;
reg[2:0] aguCmd;
MemAlu agu1(clk, aguCmd,
	iDataS, iDataT[31:0], idImm, tDataAguD);

reg			memRd;
reg			memWr;
reg[2:0]	memCmd;
reg[47:0]	memAddr;
reg[63:0]	memRdValue;
reg[63:0]	memWrValue;
MemTile mem1(clk, memRd, memWr, memCmd,
	memAddr, memRdValue, memWrValue);

reg[1:0] idStepPc;
DecOp dec1(clk, istrWord,
	idRegD, idRegS, idRegT, idImm, idUopPc, idStepPc);

reg[63:0] tRegStepPc;
reg[11:0] uopPc;
reg[11:0] uopNextPc;

reg[31:0] uopPgm[4096];

always @ (clk)
begin
	uopWord=uopPgm[uopPc];
	if(uopWord[23])
		uopNextPc=12'h000;
	else
		uopNextPc=uopPc+1;
	uopCmd=uopWord[31:24];

	regPc[31: 0]=regs.regs[regs.REG_PC_LO];
	regPc[63:32]=regs.regs[regs.REG_PC_HI];
	regNextPc=regPc;

	regSr=regs.regs[regs.REG_SR];
	case(uopCmd[7:4])
		4'h0:
		begin
			if(uopCmd[3:0]==4'h0)
			begin
				uopNextPc=idUopPc;
				tRegStepPc[63:3]=61'h0;
				tRegStepPc[2:1]=idStepPc[1:0];
				tRegStepPc[0]=1'b0;
				regNextPc=regPc+tRegStepPc;
			end
			else
			begin
				aluCmd=uopCmd[3:0];
				tData2D=tDataAluD;
				tIsWr2D=aluCmd<alu1.UOP_CMPEQ;
				tIsQw2D=1'b0;
				if(aluCmd<alu1.UOP_ADDC)
					tRegSr=regSr;
				else
				begin
					tRegSr[31:1]=regSr[31:1];
					tRegSr[0]=tAluSr[0];
				end
			end
		end

		4'h1:
		begin
			if(uopCmd[3:0]==4'h0)
			begin
				memAddr[47:0]=regPc[47:0];
				memCmd=mem1.MD_DWORD;
				memRd=1'b1;
				memWr=1'b0;
				
				istrWord=memRdValue[31:0];

				tData2D=tDataAguD;
				tIsWr2D=1'b0;
				tIsQw2D=1'b0;
				tRegSr=regSr;
			end
			else
			begin
				aluCmd=uopCmd[3:0];
				tData2D=tDataAluD;
				tIsWr2D=aluCmd<alu1.UOP_CMPEQ;
				tIsQw2D=1'b1;
				if(aluCmd<alu1.UOP_ADDC)
					tRegSr=regSr;
				else
				begin
					tRegSr[31:1]=regSr[31:1];
					tRegSr[0]=tAluSr[1];
				end
			end
		end

		4'h2:
		begin
			aguCmd=uopCmd[2:0];
			tData2D=tDataAguD;
			tIsWr2D=1'b1;
			tIsQw2D=1'b1;
			tRegSr=regSr;
		end

		4'h3:
		begin
			aguCmd=uopCmd[2:0];
			memCmd=uopCmd[2:0];
			memAddr=tDataAguD[47:0];
			tIsWr2D=uopCmd[3];
			tIsQw2D=uopCmd[2];
			tRegSr=regSr;

			memWrValue=iDataD;
			tData2D=memRdValue;

			if(uopCmd[3])
			begin
				memRd=1'b0;
				memWr=1'b1;
			end
			else
			begin
				memRd=1'b1;
				memWr=1'b0;
			end
		end

		default: begin
			tData2D=iDataD;
			tIsWr2D=1'b0;
			tIsQw2D=1'b0;
			tRegSr=regSr;
		end
	endcase
end

always @ (posedge clk) begin
	oData2D <= tData2D;
	oIsWr2D <= tIsWr2D;
	oIsQw2D <= tIsQw2D;
//	regSr <= tRegSr;
	regs.regs[regs.REG_SR] <= tRegSr;
	uopPc <= uopNextPc;

	regs.regs[regs.REG_PC_LO] <= regNextPc[31: 0];
	regs.regs[regs.REG_PC_HI] <= regNextPc[63:32];
end

endmodule
