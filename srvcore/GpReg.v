/*
Bank of GPRs.

00..0F: R0..R15
10..1F: CS0..CS15
20..2F: F0L..F15L
30..3F: F16L..F31L

40..4F: R0H..R15H
50..5F: CC0..CC15
60..6F: F0H..F15H
70..7F: F16H..F31H

Special Cases (Handled Externally)
58: Opcode D
59: Opcode S
5A: Opcode T
5B: Opcode Imm
5F: ZZR (Always read as Zero)

Mapping for BJX1:

FR0 =F0H , FR1 =F0L , XF0 =F1H , XF1 =F1L ,
FR2 =F2H , FR3 =F2L , XF2 =F3H , XF3 =F3L ,
FR4 =F4H , FR5 =F4L , XF4 =F5H , XF5 =F5L ,
FR6 =F6H , FR7 =F6L , XF6 =F7H , XF7 =F7L ,
FR8 =F8H , FR9 =F8L , XF8 =F9H , XF9 =F9L ,
FR10=F10H, FR11=F10L, XF10=F11H, XF11=F11L,
FR12=F12H, FR13=F12L, XF12=F13H, XF13=F13L,
FR14=F14H, FR15=F14L, XF14=F15H, XF15=F15L,
...

CS0=MACH
CS1=MACL
CS2=PR
CS3=SGR
CS4=?
CS5=FPUL
CS6=FPSCR
CS7=?
..
CS14=?
CS15=DBR

CC0=SR
CC1=GBR
CC2=VBR
CC3=SSR
CC4=SPC
CC5=?
CC6=?
CC7=PC
CC8 =R0_B
..
CC15=R7_B

*/


parameter[5:0] REGS_R0		= 6'h00;
parameter[5:0] REGS_R15		= 6'h0F;

parameter[5:0] REGS_F0		= 6'h20;
parameter[5:0] REGS_F15		= 6'h2F;
parameter[5:0] REGS_F16		= 6'h30;
parameter[5:0] REGS_F31		= 6'h3F;

// parameter[5:0] REGS_PR		= 6'h12;
// parameter[3:0] CREG_SR		= 4'h00;
// parameter[3:0] CREG_PC		= 4'h0E;
// parameter[4:0] CREG_LR		= 5'h01;

parameter[6:0] REG_R0		= 7'h00;
parameter[6:0] REG_R15		= 7'h0F;

parameter[6:0] REG_F0		= 7'h20;
parameter[6:0] REG_F15		= 7'h2F;
parameter[6:0] REG_F16		= 7'h30;
parameter[6:0] REG_F31		= 7'h3F;

parameter[6:0] REG_MACH		= 7'h10;
parameter[6:0] REG_MACL		= 7'h11;
parameter[6:0] REG_PR		= 7'h12;
parameter[6:0] REG_SGR		= 7'h13;

parameter[6:0] REG_FPUL		= 7'h15;
parameter[6:0] REG_FPSCR	= 7'h16;

parameter[6:0] REG_DBR		= 7'h1F;

parameter[6:0] REG_SR		= 7'h50;
parameter[6:0] REG_GBR		= 7'h51;
parameter[6:0] REG_VBR		= 7'h52;
parameter[6:0] REG_SSR		= 7'h53;
parameter[6:0] REG_SPC		= 7'h54;

parameter[6:0] REG_PC		= 7'h57;

parameter[6:0] REG_IMM		= 7'h5E;
parameter[6:0] REG_ZZR		= 7'h5F;


module GpReg(
	clk,

	isWrD,
	isQwD,
	idRegD,
	dataD,

	idReg1,
	data1,

	idReg2,
	data2,

	idReg3,
	data3
	);

input clk;			//clock

input isWrD;		//Is Write
input isQwD;		//Is QuadWord
input[6:0] idRegD;
input[63:0] dataD;

input[6:0] idReg1;
input[6:0] idReg2;
input[6:0] idReg3;

output[63:0] data1;
output[63:0] data2;
output[63:0] data3;


reg[31:0] regs_lo[64];	//GPRs and FPRs
reg[31:0] regs_hi[64];

// reg[31:0] sreg_lo[16];	//System Registers
// reg[31:0] sreg_hi[16];

reg[31:0] creg_lo[16];	//Control Registers
reg[31:0] creg_hi[16];

reg[63:0] reg_pc;		//PC register, special
reg[63:0] reg_pr;		//PR register, special
reg[63:0] reg_sr;		//SR register, special

// reg[6:0] tIdRegDLo;
// reg[6:0] tIdRegDHi;

// reg[6:0] tIdReg1Lo;
// reg[6:0] tIdReg1Hi;
// reg[6:0] tIdReg2Lo;
// reg[6:0] tIdReg2Hi;
// reg[6:0] tIdReg3Lo;
// reg[6:0] tIdReg3Hi;


reg[5:0] tIdRegDLo;
reg[5:0] tIdReg1Lo;
reg[5:0] tIdReg2Lo;
reg[5:0] tIdReg3Lo;

// reg rb_curBank;
// reg rb_reqBank;
// reg rb_isSwap;
// reg[3:0] rb_tSwapBank;
// reg[3:0] rb_tNextSwapBank;

always @ (clk) begin
//	tIdRegDLo = idRegD;
//	tIdRegDHi = idRegD | (7'h40);

//	if(rb_isSwap)
//	begin
//		if(rb_tSwapBank[0])
//	end

	tIdRegDLo = idRegD[5:0];
	tIdReg1Lo = idReg1[5:0];
	tIdReg2Lo = idReg2[5:0];
	tIdReg3Lo = idReg3[5:0];

//	if(idReg1!=REG_ZZR)
	if(idReg1[5:4]!=2'b01)
	begin
		if(idReg1[6])
		begin
			data1[31: 0] = regs_hi[tIdReg1Lo];
			data1[63:32] = 32'h0000_0000 ;
		end
		else
		begin
			data1[31: 0] = regs_lo[tIdReg1Lo];
			data1[63:32] = regs_hi[tIdReg1Lo];
		end
	end
	else
	begin
		if(idReg1[6])
		begin
			data1[31: 0] = creg_lo[tIdReg1Lo[3:0]];
			data1[63:32] = creg_hi[tIdReg1Lo[3:0]];
		end
		else
		begin
			data1[31: 0] = regs_lo[tIdReg1Lo];
			data1[63:32] = regs_hi[tIdReg1Lo];
		end

//		data1 = 64'h0000_0000_0000_0000;
	end

//	if(idReg2!=REG_ZZR)
	if(idReg2[5:4]!=2'b01)
	begin
		if(idReg2[6])
		begin
			data2[31: 0] = regs_hi[tIdReg2Lo];
			data2[63:32] = 32'h0000_0000 ;
		end
		else
		begin
			data2[31: 0] = regs_lo[tIdReg2Lo];
			data2[63:32] = regs_hi[tIdReg2Lo];
		end
	end
	else
	begin
		if(idReg2[6])
		begin
			data2[31: 0] = creg_lo[tIdReg2Lo[3:0]];
			data2[63:32] = creg_hi[tIdReg2Lo[3:0]];
		end
		else
		begin
			data2[31: 0] = regs_lo[tIdReg2Lo];
			data2[63:32] = regs_hi[tIdReg2Lo];
		end

//		data2 = 64'h0000_0000_0000_0000;
	end

//	if(idReg3!=REG_ZZR)
	if(idReg3[5:4]!=2'b01)
	begin
		if(idReg3[6])
		begin
			data3[31: 0] = regs_hi[tIdReg3Lo];
			data3[63:32] = 32'h0000_0000 ;
		end
		else
		begin
			data3[31: 0] = regs_lo[tIdReg3Lo];
			data3[63:32] = regs_hi[tIdReg3Lo];
		end
	end
	else
	begin
		if(idReg3[6])
		begin
			data3[31: 0] = creg_lo[tIdReg3Lo[3:0]];
			data3[63:32] = creg_hi[tIdReg3Lo[3:0]];
		end
		else
		begin
			data3[31: 0] = regs_lo[tIdReg3Lo];
			data3[63:32] = regs_hi[tIdReg3Lo];
		end

//		data3 = 64'h0000_0000_0000_0000;
	end
end

always @ (posedge clk) begin
	if(isWrD==1'b1)
	begin
		if(idRegD[5:4]!=2'b01)
		begin
			if(isQwD==1'b1)
			begin
				$display("R[%X]Q=%X", tIdRegDLo, dataD);
			
				regs_lo[tIdRegDLo] <= dataD[31:0];
				regs_hi[tIdRegDLo] <= dataD[63:32];
			end
			else
			begin
				$display("R[%X]D=%X", tIdRegDLo, dataD);

				if(idRegD[6])
					regs_hi[tIdRegDLo] <= dataD[31:0];
				else
					regs_lo[tIdRegDLo] <= dataD[31:0];
			end
		end
		else
		begin
			$display("CSR[%X]=%X", tIdRegDLo, dataD);

			if(idRegD[6])
			begin
				creg_lo[tIdRegDLo[3:0]] <= dataD[31:0];
				if(isQwD==1'b1)
					creg_hi[tIdRegDLo[3:0]] <= dataD[63:32];
			end
			else
			begin
//				sreg_lo[tIdRegDLo[3:0]] <= dataD[31:0];
//				if(isQwD==1'b1)
//					sreg_hi[tIdRegDLo[3:0]] <= dataD[63:32];

				regs_lo[tIdRegDLo] <= dataD[31:0];
				if(isQwD==1'b1)
					regs_hi[tIdRegDLo] <= dataD[63:32];
			end
		end
	end

//	if(rb_isSwap)
//	begin
//		rb_isSwap <= rb_isNextSwap;
//		rb_tSwapBank = rb_tNextSwapBank;
//	end
//	else if(rb_curBank!=rb_reqBank)
//	begin
//		rb_isSwap <= 1;
//		rb_tSwapBank = 15;
//	end

end

endmodule
