/*
Microcode Execute

Microcode Op
  31:24, Opcode
     23, Last Uop (Continue to next Opcode)
     22, Use registers from uOp (vs source op)
     21, Use immed from uOp (vs source op)

Z Form:  oooo-oooo z00x-xxxx xxxx-xxxx xxxx-xxxx
A Form:  oooo-oooo z10d-dddd ddss-ssss sttt-tttt
B Form:  oooo-oooo z010-iiii iiii-iiii iiii-iiii
C Form:  oooo-oooo z011-dddd iiii-iiii iiii-iiii
DZ Form: oooo-oooo z110-dddd ssss-tttt iiii-iiii	//Zero Extend
DS Form: oooo-oooo z111-dddd ssss-tttt iiii-iiii	//Sign Extend

Forms with 4-bit register IDs will only access base GPRs.
If a form does not define a field, the value will be used from the base opcode.

Op16 Forms:
  0100-0000 z010-0001 yyyy-yyyy yyyy-yyyy
  0100-0000 z010-0010 yyyy-nnnn mmmm-yyyy
  Forward an SH op to the uOp decoder.
  Used for opcodes that are special-cases.

BRTF Form:  0101-0000 z000-00nt xxxx-xxxx xxxx-xxxx
	N: No Delay Slot
	T: True/False

MOVxxx Form:  0011-wttt z000-00pd xxxx-xxxx xxxx-xxxx
	W: Write
	T: Type
	P: PostInc/PostDec
	D: Direction (0=Rm+, 1=-Rm)

 */


parameter[7:0] UOP_BRINST	= 8'h00;	//Drop, Branch Decode Instr
parameter[7:0] UOP_ADDI		= 8'h01;
parameter[7:0] UOP_SUBI		= 8'h02;
parameter[7:0] UOP_MULI		= 8'h03;
parameter[7:0] UOP_ANDI		= 8'h04;
parameter[7:0] UOP_ORI		= 8'h05;
parameter[7:0] UOP_XORI		= 8'h06;
parameter[7:0] UOP_SHLI		= 8'h07;
parameter[7:0] UOP_SHRI		= 8'h08;
parameter[7:0] UOP_SARI		= 8'h09;

parameter[7:0] UOP_ADDCI	= 8'h14;
parameter[7:0] UOP_ADDVI	= 8'h15;
parameter[7:0] UOP_SUBCI	= 8'h16;
parameter[7:0] UOP_SUBVI	= 8'h17;
parameter[7:0] UOP_TESTI	= 8'h18;

parameter[7:0] UOP_CMPEQI	= 8'h1B;
parameter[7:0] UOP_CMPGTI	= 8'h1C;
parameter[7:0] UOP_CMPGEI	= 8'h1D;
parameter[7:0] UOP_CMPHSI	= 8'h1E;
parameter[7:0] UOP_CMPHII	= 8'h1F;

parameter[7:0] UOP_JMP		= 8'h20;	//PC=PC+Rt

parameter[7:0] UOP_LEAB		= 8'h21;	//Normal Lea
parameter[7:0] UOP_LEAW		= 8'h22;
parameter[7:0] UOP_LEAI		= 8'h23;
parameter[7:0] UOP_LEAQ		= 8'h24;
parameter[7:0] UOP_LEAV		= 8'h25;

parameter[7:0] UOP_MOVI		= 8'h27;	//Rd=Rs  (32-bit)

parameter[7:0] UOP_LEADJB	= 8'h29;	//Lea for post-adjust
parameter[7:0] UOP_LEADJW	= 8'h2A;
parameter[7:0] UOP_LEADJI	= 8'h2B;
parameter[7:0] UOP_LEADJQ	= 8'h2C;
parameter[7:0] UOP_LEADJV	= 8'h2D;

parameter[7:0] UOP_MOVQ		= 8'h2F;	//Rd=Rs (64-bit)

parameter[7:0] UOP_JSR		= 8'h30;	//PR=PC; PC=PC+Rt

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

parameter[7:0] UOP_FWOP		= 8'h40;	//Forwarded Op

parameter[7:0] UOP_FADDS	= 8'h41;
parameter[7:0] UOP_FSUBS	= 8'h42;
parameter[7:0] UOP_FMULS	= 8'h43;
parameter[7:0] UOP_FDIVS	= 8'h44;
parameter[7:0] UOP_FABSS	= 8'h45;
parameter[7:0] UOP_FNEGS	= 8'h46;
parameter[7:0] UOP_FRCPS	= 8'h47;
parameter[7:0] UOP_FSQRTS	= 8'h48;

parameter[7:0] UOP_FCMPEQS	= 8'h4A;
parameter[7:0] UOP_FCMPGTS	= 8'h4B;

parameter[7:0] UOP_FCNVSI	= 8'h4E;
parameter[7:0] UOP_FCNVIS	= 8'h4F;

parameter[7:0] UOP_BRTF		= 8'h50;	//Branch BT/BF/BTS/BFS

parameter[7:0] UOP_FADDD	= 8'h51;
parameter[7:0] UOP_FSUBD	= 8'h52;
parameter[7:0] UOP_FMULD	= 8'h53;
parameter[7:0] UOP_FDIVD	= 8'h54;
parameter[7:0] UOP_FABSD	= 8'h55;
parameter[7:0] UOP_FNEGD	= 8'h56;
parameter[7:0] UOP_FRCPD	= 8'h57;
parameter[7:0] UOP_FSQRTD	= 8'h58;

parameter[7:0] UOP_FCMPEQD	= 8'h5A;
parameter[7:0] UOP_FCMPGTD	= 8'h5B;
parameter[7:0] UOP_FCNVSD	= 8'h5C;
parameter[7:0] UOP_FCNVDS	= 8'h5D;
parameter[7:0] UOP_FCNVDI	= 8'h5E;
parameter[7:0] UOP_FCNVID	= 8'h5F;


`include "ArithAlu.v"
`include "MemAlu.v"
`include "FpuFp64B.v"
`include "GpReg.v"
`include "MemTile2.v"
`include "DecOp.v"

module ExUop(clk, reset,
	extAddr,	extData,
	extOE,		extWR,
	extNotReady);

input clk;			//clock
input reset;		//reset

/* External Memory */
output[31:0] extAddr;			//external memory address
inout[31:0] extData;			//external memory data (read/write)
output extOE;					//external output enable
output extWR;					//external write
input extNotReady;				//external access is not ready

/* Stage 1: IF, Fetch */
reg[31:0]	ifRegPc;		//PC at point instr was read


/* Stage 2: ID, Decode */
reg[31:0]	idNextInstWord;	//source instruction word

reg[31:0]	idInstWord;		//source instruction word
reg[6:0]	idRegD;			//Source Opcode D (or N)
reg[6:0]	idRegS;			//Source Opcode S (N or M)
reg[6:0]	idRegT;			//Source Opcode T (or M)
reg[31:0]	idImm;			//Source Immediate
reg[11:0]	idUopPc;		//Instruction Uop PC
reg[31:0]	idUopWord;		//uop word
reg[31:0]	idRegPc;		//PC at point instr was read
reg[31:0]	idRegNextPc;	//Next PC at point instr was read


/* Stage 3: EX, Execute */

reg[31:0]	uopWord;		//uop word
reg[31:0]	uopNextWord;	//uop word
reg[7:0]	uopCmd;			//uop command

reg[6:0]	ixRegD;			//Source Opcode D (or N)
reg[6:0]	ixRegS;			//Source Opcode S (N or M)
reg[6:0]	ixRegT;			//Source Opcode T (M)
reg[31:0]	ixImm;			//Source Immediate
reg[31:0]	ixRegPc;		//PC at point instr was read
reg[31:0]	ixRegNextPc;	//PC at point instr was read

reg[6:0] iRegD;				//Ex Opcode D (or N)
reg[6:0] iRegS;				//Ex Opcode S (N or M)
reg[6:0] iRegT;				//Ex Opcode T (M)
reg[31:0] iImm;				//Ex Immediate

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

GpReg regs(clk,
		oIsWr2D, oIsQw2D, oIdReg2D, oData2D,
		iRegD, iDataD, iRegS, iDataS, iRegT, iDataT);

reg[31:0] iDataAluS;
reg[31:0] iDataAluT;
reg[31:0] tDataAluD;

reg[31:0] regSr;
reg[31:0] regNextSr;

reg[31:0] regPc;
reg[31:0] regNextPc;
reg[31:0] regPrNextPc;
reg[31:0] regPrPc;

reg[31:0] regPr;
reg[31:0] regNextPr;

reg[4:0] aluCmd;
reg[3:0] tAluSr;
ArithAlu alu1(clk, aluCmd,
	iDataAluS, iDataAluT, tDataAluD, regSr[3:0], tAluSr);

reg[31:0] aguDataHeldS;
reg[31:0] aguDataNextHeldS;

reg aguHasIndex;
reg[31:0] tDataAguD;
reg[2:0] aguCmd;
reg[31:0] aguDataS;
reg[31:0] aguDataT;
MemAlu agu1(clk, aguCmd,
	aguDataS, aguDataT, iImm, tDataAguD);
assign aguDataT = aguHasIndex ? iDataT[31:0] : 0;
assign aguDataS = tPostIncr ? aguDataHeldS[31:0] : iDataS[31:0];

reg fpuOpFp32;
reg[3:0] fpuCmd;
reg[3:0] tFpuSr;
reg[63:0] iDataFpuD;
reg[63:0] iDataFpuS;
reg[63:0] iDataFpuT;
reg[63:0] fpuDataD;
FpuFp64B fpu1(clk, fpuOpFp32, fpuCmd, iDataFpuS, iDataFpuT, iDataFpuD, fpuDataD,
	regSr[3:0], tFpuSr);

/* Data Memory */
reg			memRd;
reg			memWr;
reg[2:0]	memCmd;
reg[31:0]	memAddr;

/* verilator lint_off UNOPTFLAT */
reg[63:0]	memRdValue;
/* verilator lint_off UNOPTFLAT */
reg[63:0]	memWrValue;


/* Instruction Memory */

reg			imemRd;
reg[31:0]	imemAddr;
wire[63:0]	imemRdValue;
wire memHold;

MemTile2 mem1(clk, reset,
	memRd, memWr, memCmd,
	memAddr, memRdValue, memWrValue,
	imemRd, imemAddr, imemRdValue,
	extAddr, extData, extOE, extWR,
	memHold, extNotReady);

reg[1:0] idStepPc;
DecOp dec1(clk, idInstWord, regSr[31:0],
	idRegD, idRegS, idRegT, idImm, idStepPc, idUopPc, idUopWord);

reg[31:0]	tRegStepPc;
reg[11:0]	uopPc;
reg[11:0]	uopNextPc;
reg			uopPcLive;
reg			uopNextPcLive;

reg[15:0]	tResetMagic;
reg			tResetOK;
reg			tHold;

reg[2:0]	tPipeFlush;
reg[2:0]	tNextPipeFlush;

reg			tPipeDsFlush;
reg			tNextPipeDsFlush;

reg[2:0]	tPipeHold;
reg[2:0]	tNextPipeHold;

reg			tPostIncr;
reg			tNextPostIncr;
reg			tPostIncrDn;
reg			tNextPostIncrDn;
reg			tPostIncrDir;
reg			tNextPostIncrDir;

assign	tResetOK = !reset && (tResetMagic==12345);
assign	tHold = !tResetOK && !memHold;

assign	regPc = regs.reg_pc;
assign	regPr = regs.reg_pr;
assign	regSr = regs.reg_sr;

always @ (clk)
begin
	if(!tResetOK)
	begin
		$display("Reset");
	end
	else if(tHold)
	begin
		$display("Hold");
	end
	else
	if((memHold==0) && tResetOK)
	begin	/* Hold */
	
	/* Common */

	/* Stage 1: Fetch */

	if(!uopPcLive)
	begin
		idNextInstWord=imemRdValue[31:0];
		$display("1F: PC=%X Op=%X", ifRegPc, idNextInstWord);

		if(imemRdValue==0)
			idNextInstWord=32'hFFFF_FFFF;
		idRegNextPc=ifRegPc;
	end
	else
	begin
		idNextInstWord=idInstWord;
	end

	/* Stage 2: Decode */

	tRegStepPc[31:3]=29'h0;
	tRegStepPc[2:1]=idStepPc[1:0];
	tRegStepPc[0]=1'b0;

	if(tPipeFlush>1)
	begin
		$display("2D-0/F: PC=%X Op=%X St=%X", idRegPc, idInstWord, idStepPc);
		$display("2D-1/F: uPC=%X uOp=%X", idUopPc, idUopWord);

		regNextPc=regPc;
		regPrNextPc=regPc+4;

		uopNextPc=idUopPc;
		uopNextWord=idUopWord;
		ixRegNextPc=idRegPc;
	end
	else
	if(!uopPcLive)
	begin
		$display("2D-0: PC=%X Op=%X St=%X", idRegPc, idInstWord, idStepPc);
		$display("2D-1: uPC=%X uOp=%X", idUopPc, idUopWord);
		
		if(idInstWord==32'hFFFF_FFFF)
			$finish(0);
	
		uopNextPc=idUopPc;
		uopNextWord=idUopWord;
		regNextPc=ifRegPc+tRegStepPc;
		regPrNextPc=ifRegPc+tRegStepPc;

		ixRegNextPc=idRegPc;
	end
	else
	begin
		if(!memHold)
		begin
			$display("2D-2 uPC=%X uOp=%X", idUopPc, idUopWord);
		end

		regNextPc=regPc;
		regPrNextPc=regPc+4;
	end


	/* Stage 3+0: Execute */

	uopCmd=uopWord[31:24];

	if(tPipeFlush!=0)
	begin
		tNextPipeFlush=tPipeFlush-1;
		tNextPipeDsFlush=tPipeDsFlush;
	end
	else
	begin
		tNextPipeFlush=0;
		tNextPipeDsFlush=0;
	end
	
	if(tPipeHold!=0)
		tNextPipeHold=tPipeHold-1;
	else
		tNextPipeHold=0;

	$display("3E-0: PC=%X", ixRegPc);
	$display("3E-1 uPC=%X uOp=%X", uopPc, uopWord);
	
	if(uopWord[23]==0)
	begin
		uopNextPcLive=0;
	end
	else
	begin
		uopNextPc=uopPc+1;
		uopNextWord=dec1.uopPgm[uopNextPc];
		uopNextPcLive=1;
	end

	if(tPipeFlush!=0)
		uopNextPcLive=0;

	case(uopWord[22:21])
		2'b00:
		begin
			iRegD = ixRegD;
			iRegS = ixRegS;
			iRegT = ixRegT;
			iImm  = ixImm;
		end
		2'b10:
		begin
			iRegD = uopWord[20:14];
			iRegS = uopWord[13: 7];
			iRegT = uopWord[ 6: 0];
			iImm  = ixImm;
		end
		2'b01:
		begin
			if(uopWord[20])
			begin
				iRegS = ixRegS;
				iRegT = ixRegT;
				iRegD[6:4]  = 0;
				iRegD[3:0]  = uopWord[19:16];
				iImm[31:16] = uopWord[15] ? 16'hFFFF : 16'h0000 ;
				iImm[15:0]  = uopWord[15:0];
			end
			else
			begin
				iRegD = ixRegD;
				iRegS = ixRegS;
				iRegT = ixRegT;
//				iImm  = ixImm;
				iImm[31:20] = uopWord[19] ? 12'hFFF : 12'h000 ;
				iImm[19:0]  = uopWord[19:0];
			end
		end

		2'b11:
		begin
			iRegD[6:4] = 0;
			iRegD[3:0] = uopWord[19:16];
			iRegS[6:4] = 0;
			iRegS[3:0] = uopWord[15:12];
			iRegT[6:4] = 0;
			iRegT[3:0] = uopWord[11: 8];

			iImm[31:8] = (uopWord[20] && uopWord[7]) ?
				24'hFFFFFF : 24'h000000 ;
			iImm[ 7:0] = uopWord[7:0];
		end

	endcase

	iDataAluS=iDataS[31:0];
	iDataAluT=iDataT[31:0];

	iDataFpuD=iDataD[63:0];
	iDataFpuS=iDataS[63:0];
	iDataFpuT=iDataT[63:0];

	if(iRegS==regs.REG_ZZR)
	begin
		iDataAluS[31: 0] = 0;
	end
	if(iRegT==regs.REG_IMM)
	begin
		iDataAluT[31: 0] = iImm;
	end

	tData2D=iDataD;
	tIsWr2D=1'b0;
	tIsQw2D=1'b0;
	regNextSr=regSr;
	regNextPr=regPr;

	tIdReg2D=iRegD;
	aguHasIndex = (iRegT[3:0]!=15);

	aguDataNextHeldS = aguDataHeldS;

	aluCmd=0;
	aguCmd=0;
	memCmd=0;
	fpuCmd=0;
	fpuOpFp32=0;
	
	tNextPostIncr=0;
	tNextPostIncrDn=0;
	
	$display("Uop Cmd %X", uopCmd);

	case(uopCmd[7:4])
		4'h0:
		begin
			if(uopCmd[3:0]==4'h0)
			begin
				uopNextPcLive = 0;
			end
			else
			begin
				aluCmd=uopCmd[4:0];
				tData2D={32'h0, tDataAluD};
//				tIsWr2D=aluCmd<alu1.UOP_CMPEQ;
				tIsWr2D=1'b1;
//				tIsQw2D=1'b0;
//				if(aluCmd>=alu1.UOP_ADDC)
//				begin
//					regNextSr[31:1]=regSr[31:1];
//					regNextSr[0]=tAluSr[0];
//				end

				$display("EX ALU.L Op=%X D=%X(%X) S=%X(%X) T=%X(%X) -> %X",
					aluCmd,
					iRegD, iDataD,
					iRegS, iDataAluS,
					iRegT, iDataAluT,
					tDataAluD);
			end
		end

		4'h1:
			aluCmd=uopCmd[4:0];
			tData2D={32'h0, tDataAluD};
			tIsWr2D=aluCmd<alu1.UOP_TEST;
			regNextSr[31:1]=regSr[31:1];
			regNextSr[0]=tAluSr[0];

			$display("EX ALU.L Op=%X D=%X(%X) S=%X(%X) T=%X(%X) -> %X",
				aluCmd,
				iRegD, iDataD,
				iRegS, iDataAluS,
				iRegT, iDataAluT,
				tDataAluD);
		begin

		end

		4'h2:
		begin
			if(uopCmd[3:0]==4'h0)
			begin
				regNextPc = regPrPc + (iDataAluT*2);
				tNextPipeFlush = 2;
				$display("3E BRA PC=%X -> %X (Disp=%X)",
					regPrPc, regNextPc, iDataAluT);
			end
			else
			begin
				if(iRegT==regs.REG_R0)
					aguCmd=agu1.MD_BYTE;
				else
					aguCmd=uopCmd[2:0];

				if(uopCmd[3])
				begin
					tIdReg2D=iRegS;
					aguHasIndex = 0;
				end

				tData2D={32'h0, tDataAguD};
				tIsWr2D=1'b1;
	//			tIsQw2D=1'b1;
//				tIsQw2D = (uopCmd!=UOP_MOVI);
			end
		end

		4'h3:
		begin
			if(uopCmd[3:0]==4'h0)
			begin
				regNextPr = regPrNextPc;
				regNextPc = regPrNextPc + (iDataAluT*2);
				tNextPipeFlush = 2;
				$display("3E BSR PC=%X -> %X (Disp=%X)",
					regPrPc, regNextPc, iDataAluT);
			end
			else
			begin
				if(iRegT==regs.REG_R0)
					aguCmd=agu1.MD_BYTE;
				else
					aguCmd=uopCmd[2:0];

				memCmd=uopCmd[2:0];
//				memAddr=tDataAguD[47:0];
				memAddr=tDataAguD[31:0];
				tIsWr2D=uopCmd[3];
//				tIsQw2D=uopCmd[2];

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
				
				if(tPipeHold==0)
					tNextPipeHold=1;
				
				tPostNextIncr=uopWord[17];
				tPostNextIncrDir=uopWord[16];
				
				if(tPostIncr)
				begin
					if(tPipeHold==0)
						tNextPipeHold=2;

					tNextPostIncrDn=1;
					if(!tPostIncrDn)
					begin
						tIsWr2D=1'b1;
						tIsQw2D=1'b0;
						tIdReg2D=iRegS;
						if(tPostNextIncrDir)
						begin
							case(memCmd)
							3'h1: tData2D=aguDataHeldS-1;
							3'h2: tData2D=aguDataHeldS-2;
							3'h3: tData2D=aguDataHeldS-4;
							3'h4: tData2D=aguDataHeldS-8;
							endcase
						end
						else
						begin
							case(memCmd)
							3'h1: tData2D=aguDataHeldS+1;
							3'h2: tData2D=aguDataHeldS+2;
							3'h3: tData2D=aguDataHeldS+4;
							3'h4: tData2D=aguDataHeldS+8;
							endcase
						end
					end
				end
				else
				begin
					aguDataNextHeldS = iDataS;
				end
			end
		end

		4'h4:
		begin
			if(uopCmd[3:0]==4'h0)
			begin
				/* Forward Op */
			end
			else
			begin
				fpuCmd=uopCmd[3:0];
				tData2D=fpuDataD;
				tIsWr2D=1;
//				tIsQw2D=0;
				if((fpuCmd!=fpu1.OP_CMPEQ) || (fpuCmd!=fpu1.OP_CMPGT))
				begin
					tIsWr2D=0;
					regNextSr[31:1]=regSr[31:1];
					regNextSr[0]=tFpuSr[0];
				end
			end
		end

		4'h5:
		begin
			if(uopCmd[3:0]==4'h0)
			begin
				if((regSr[0]^uopWord[16])==0)
				begin
					regNextPc = regPrPc + (iDataAluT*2);
					tNextPipeFlush = 2;
					tNextPipeDsFlush = uopWord[17];
					$display("3E BRTF PC=%X -> %X (Disp=%X)",
						regPrPc, regNextPc, iDataAluT);
				end
			end
			else
			begin
				fpuCmd=uopCmd[3:0];
				tData2D=fpuDataD;
				tIsWr2D=1;
//				tIsQw2D=1;
				if((fpuCmd!=fpu1.OP_CMPEQ) || (fpuCmd!=fpu1.OP_CMPGT))
				begin
					tIsWr2D=0;
					regNextSr[31:1]=regSr[31:1];
					regNextSr[0]=tFpuSr[0];
				end
			end
		end

		default: begin
		end
	endcase

	if(uopCmd==8'h40)
	begin
		case(uopWord[15:12])

		4'h0:
			case(uopWord[3:0])
			4'h0:
			begin
				/* Unhandled Opcode, TODO: Trap to BIOS */
			end

			4'h8:
				case(uopWord[7:4])
				4'h0:
					regNextSr[0]=0;
				4'h1:
					regNextSr[0]=1;

				4'h4:
					case(uopWord[11:8])
					4'h0:	regNextSr[1]=0;
					4'h1:	regNextSr[12]=0;
					4'h2:	regNextSr[31]=0;
					4'h3:	begin regNextSr[31]=0; regNextSr[12]=0; end
					default:	regNextSr[1]=0;
					endcase
				4'h5:
					case(uopWord[11:8])
					4'h0:	regNextSr[1]=1;
					4'h1:	regNextSr[12]=1;
					4'h2:	regNextSr[31]=1;
					4'h3:	begin regNextSr[31]=1; regNextSr[12]=1; end
					default:	regNextSr[1]=1;
					endcase

				4'h6:
					regNextSr[0]=!regSr[0];

				default:	begin end
				endcase

			4'h9:
				case(uopWord[7:4])
				4'h0:
					begin end		//NOP
				4'h1:
				begin
					regNextSr[0]=0;
					regNextSr[8]=0;
					regNextSr[9]=0;
				end

				4'h2:
				begin
					tData2D[63:0]=0;
					tData2D[0]=regSr[0];
				end

				4'h3:
				begin
					regNextSr[0]=iDataT[0];
				end

				default:	begin end
				endcase

			4'hB:
				case(uopWord[7:4])
				4'h0:
					regNextPc=regPr;

				4'h1:
					begin end		//SLEEP

				4'h2:		//RTE
					begin
					end

				4'h3:
					begin end		//BRK
				default: begin end
				endcase
			default: begin end
			endcase
		default: begin
		end
		endcase
	end
	
	end	/* Hold */
end


always @ (negedge clk)
begin
		oData2D    <= tData2D;
		oIsWr2D    <= tIsWr2D;
		oIsQw2D    <= tIsQw2D;
		oIdReg2D   <= tIdReg2D;
end

always @ (posedge clk)
begin

	/* Stage 3+: Multi-Cycle Operations */
	tPostIncr		<= tNextPostIncr;
	tPostIncrDn		<= tNextPostIncrDn;
	tPostIncrDir	<= tNextPostIncrDir;
	aguDataHeldS	<= aguDataNextHeldS;
	tPipeHold		<= tNextPipeHold;


	if(memHold || (tPipeHold || tNextPipeHold) || !tResetOK)
	begin
		if(!reset)
			tResetMagic		<= 12345;
		else
			tResetMagic		<= 0;

		if(!tResetOK)
		begin
			regs.reg_sr <= 0;
			regs.reg_pc <= 0;
			regs.reg_pr <= 0;

			imemAddr[31:0]	<= 0;
			imemRd			<= 1'b1;
		end
	end

	else

	begin
//		$display("La");

		/* Common */
		regs.reg_sr		<= regNextSr;
		regs.reg_pc		<= regNextPc;
		regs.reg_pr		<= regNextPr;

		tPipeFlush		<= tNextPipeFlush;
		tPipeDsFlush	<= tNextPipeDsFlush;

		/* Stage 1 */

		imemAddr[31:0]	<= regNextPc[31:0];
		imemRd			<= 1'b1;
		ifRegPc			<= regNextPc;


		/* Stage 1->2 */
		
		if((tPipeFlush>1) || (tPipeDsFlush!=0))
		begin
			idInstWord		<= 32'h0F090F09;
			idRegPc			<= ifRegPc;
		end
		else
		if(tPipeFlush!=0)
		begin
			idInstWord		<= imemRdValue[31:0];
			idRegPc			<= ifRegPc;
		end
		else
		begin
			idInstWord		<= imemRdValue[31:0];
			idRegPc			<= idRegNextPc;
		end


		/* Stage 2->3 */
		ixRegD			<= idRegD;
		ixRegS			<= idRegS;
		ixRegT			<= idRegT;
		ixImm			<= idImm;
		ixRegPc			<= ixRegNextPc;
		regPrPc			<= regPrNextPc;


		/* Stage 3+0 */
		uopPc			<= uopNextPc;
		uopWord			<= uopNextWord;
		uopPcLive		<= uopNextPcLive;
	end
end

endmodule
