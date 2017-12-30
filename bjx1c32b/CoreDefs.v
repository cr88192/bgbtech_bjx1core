/*
Registers
	00..1F: Reserved for GPRs
		Only 00..0F used in BJX1-32
	20..2F: Banked Regs

	40..4F: FRn
	50..5F: XFn
	60..6F: SR
	70..7F: CR

CSFL_LE			0x01	//Little Endian
CSFL_FPPR		0x02	//FPSCR.PR
CSFL_FPSZ		0x04	//FPSCR.SZ
CSFL_FPFR		0x08	//FPSCR.FR
CSFL_FPVE		0x10	//FPSCR.VE
CSFL_SRJQ		0x20	//SR.JQ
CSFL_SRDQ		0x40	//SR.DQ

 */

parameter[7:0] UCMD_NONE		= 8'h00;	//No-Op
parameter[7:0] UCMD_MOV_RR		= 8'h01;	//MOV Reg, Reg
parameter[7:0] UCMD_MOV_RI		= 8'h02;	//MOV #Imm, Reg
parameter[7:0] UCMD_UDBRK		= 8'h03;	//Undefined/Break (Imm)

parameter[7:0] UCMD_LEAB_MR		= 8'h04;	//LEA.B @(Rs, Rt, Imm), Rn
parameter[7:0] UCMD_LEAW_MR		= 8'h05;	//LEA.W @(Rs, Rt, Imm), Rn
parameter[7:0] UCMD_LEAL_MR		= 8'h06;	//LEA.L @(Rs, Rt, Imm), Rn
parameter[7:0] UCMD_LEAQ_MR		= 8'h07;	//LEA.Q @(Rs, Rt, Imm), Rn
parameter[7:0] UCMD_MOVB_RM		= 8'h08;	//MOV.B Rs, @(Rn, Rt, Imm)
parameter[7:0] UCMD_MOVW_RM		= 8'h09;	//MOV.W Rs, @(Rn, Rt, Imm)
parameter[7:0] UCMD_MOVL_RM		= 8'h0A;	//MOV.L Rs, @(Rn, Rt, Imm)
parameter[7:0] UCMD_MOVQ_RM		= 8'h0B;	//MOV.Q Rs, @(Rn, Rt, Imm)
parameter[7:0] UCMD_MOVB_MR		= 8'h0C;	//MOV.B @(Rs, Rt, Imm), Rn
parameter[7:0] UCMD_MOVW_MR		= 8'h0D;	//MOV.W @(Rs, Rt, Imm), Rn
parameter[7:0] UCMD_MOVL_MR		= 8'h0E;	//MOV.L @(Rs, Rt, Imm), Rn
parameter[7:0] UCMD_MOVQ_MR		= 8'h0F;	//MOV.Q @(Rs, Rt, Imm), Rn

parameter[7:0] UCMD_ALU_ADD		= 8'h10;	//ADD
parameter[7:0] UCMD_ALU_SUB		= 8'h11;	//SUB
parameter[7:0] UCMD_ALU_MUL		= 8'h12;	//MUL
parameter[7:0] UCMD_ALU_AND		= 8'h13;	//AND
parameter[7:0] UCMD_ALU_OR		= 8'h14;	//OR
parameter[7:0] UCMD_ALU_XOR		= 8'h15;	//XOR
parameter[7:0] UCMD_ALU_SHAD	= 8'h16;	//SHAD
parameter[7:0] UCMD_ALU_SHLD	= 8'h17;	//SHLD
parameter[7:0] UCMD_CMP_EQ		= 8'h18;	//Rs==Rt
parameter[7:0] UCMD_CMP_GT		= 8'h19;	//Rs>Rt
parameter[7:0] UCMD_CMP_HI		= 8'h1A;	//Rs>Rt
parameter[7:0] UCMD_CMP_GE		= 8'h1B;	//Rs>=Rt
parameter[7:0] UCMD_CMP_HS		= 8'h1C;	//Rs>=Rt
parameter[7:0] UCMD_CMP_TST		= 8'h1D;	//!(Rs&Rt)
parameter[7:0] UCMD_ALU_DMULU	= 8'h1E;	//DMULU
parameter[7:0] UCMD_ALU_DMULS	= 8'h1F;	//DMULS

parameter[7:0] UCMD_FPU_NONE	= 8'h20;
parameter[7:0] UCMD_FPU_ADD		= 8'h21;	//srca+srcb
parameter[7:0] UCMD_FPU_SUB		= 8'h22;	//srca-srcb
parameter[7:0] UCMD_FPU_MUL		= 8'h23;	//srca*srcb
parameter[7:0] UCMD_FPU_MSC		= 8'h24;	//srcc-(srca*srcb)
parameter[7:0] UCMD_FPU_ABS		= 8'h25;	//|srcb|
parameter[7:0] UCMD_FPU_NEG		= 8'h26;	//-srcb
parameter[7:0] UCMD_FPU_RCP		= 8'h27;	//(1/x), rough approx
parameter[7:0] UCMD_FPU_SQRT	= 8'h28;	//sqrt(x), rough approx
parameter[7:0] UCMD_FPU_MAC		= 8'h29;	//srcc+(srca*srcb)
parameter[7:0] UCMD_FPU_CMPEQ	= 8'h2A;	//srca==srcb
parameter[7:0] UCMD_FPU_CMPGT	= 8'h2B;	//srca>srcb
parameter[7:0] UCMD_FPU_CNVSD	= 8'h2C;	//single to double
parameter[7:0] UCMD_FPU_CNVDS	= 8'h2D;	//double to single
parameter[7:0] UCMD_FPU_CNVSI	= 8'h2E;	//float to int
parameter[7:0] UCMD_FPU_CNVIS	= 8'h2F;	//int to float

parameter[7:0] UCMD_BRA			= 8'h30;
parameter[7:0] UCMD_BSR			= 8'h31;
parameter[7:0] UCMD_BRAN		= 8'h32;
parameter[7:0] UCMD_BSRN		= 8'h33;
parameter[7:0] UCMD_BTS			= 8'h34;
parameter[7:0] UCMD_BFS			= 8'h35;
parameter[7:0] UCMD_BT			= 8'h36;
parameter[7:0] UCMD_BF			= 8'h37;



parameter[6:0] UREG_R0			= 7'h00;	//
parameter[6:0] UREG_R1			= 7'h01;	//
parameter[6:0] UREG_R2			= 7'h02;	//
parameter[6:0] UREG_R3			= 7'h03;	//
parameter[6:0] UREG_R4			= 7'h04;	//
parameter[6:0] UREG_R5			= 7'h05;	//
parameter[6:0] UREG_R6			= 7'h06;	//
parameter[6:0] UREG_R7			= 7'h07;	//
parameter[6:0] UREG_R8			= 7'h08;	//
parameter[6:0] UREG_R9			= 7'h09;	//
parameter[6:0] UREG_R10			= 7'h0A;	//
parameter[6:0] UREG_R11			= 7'h0B;	//
parameter[6:0] UREG_R12			= 7'h0C;	//
parameter[6:0] UREG_R13			= 7'h0D;	//
parameter[6:0] UREG_R14			= 7'h0E;	//
parameter[6:0] UREG_R15			= 7'h0F;	//

parameter[6:0] UREG_R16			= 7'h10;	//
parameter[6:0] UREG_R31			= 7'h1F;	//

parameter[6:0] UREG_R0B			= 7'h20;	//
parameter[6:0] UREG_R1B			= 7'h21;	//
parameter[6:0] UREG_R2B			= 7'h22;	//
parameter[6:0] UREG_R3B			= 7'h23;	//
parameter[6:0] UREG_R4B			= 7'h24;	//
parameter[6:0] UREG_R5B			= 7'h25;	//
parameter[6:0] UREG_R6B			= 7'h26;	//
parameter[6:0] UREG_R7B			= 7'h27;	//

parameter[6:0] UREG_FR0			= 7'h40;	//
parameter[6:0] UREG_XF0			= 7'h50;	//

parameter[6:0] UREG_SR0			= 7'h60;	//

parameter[6:0] UREG_MACH		= 7'h60;	//
parameter[6:0] UREG_MACL		= 7'h61;	//
parameter[6:0] UREG_PR			= 7'h62;	//
parameter[6:0] UREG_SGR			= 7'h63;	//
parameter[6:0] UREG_FPUL		= 7'h65;	//
parameter[6:0] UREG_FPSCR		= 7'h66;	//
parameter[6:0] UREG_DBR			= 7'h6F;	//

parameter[6:0] UREG_CR0			= 7'h70;	//

parameter[6:0] UREG_SR			= 7'h70;	//
parameter[6:0] UREG_GBR			= 7'h71;	//
parameter[6:0] UREG_VBR			= 7'h72;	//
parameter[6:0] UREG_SSR			= 7'h73;	//
parameter[6:0] UREG_SPC			= 7'h74;	//
parameter[6:0] UREG_PC			= 7'h77;	//

// 78..7F are only accessible as registers in certain contexts.
parameter[6:0] UREG_MMUCR		= 7'h78;	//
parameter[6:0] UREG_PTEH		= 7'h79;	//
parameter[6:0] UREG_PTEL		= 7'h7A;	//
parameter[6:0] UREG_TTB			= 7'h7B;	//
parameter[6:0] UREG_TEA			= 7'h7C;	//
parameter[6:0] UREG_TRAEVT		= 7'h7D;	//
parameter[6:0] UREG_EXPEVT		= 7'h7E;	//
parameter[6:0] UREG_INTEVT		= 7'h7F;	//


parameter[6:0] UREG_PCW			= 7'h7A;	//PC+4+2*disp
parameter[6:0] UREG_PCL			= 7'h7B;	//((PC+4)&(~3))+4*disp
parameter[6:0] UREG_MR_IMM		= 7'h7C;	//Immediate
parameter[6:0] UREG_MR_MEMDEC	= 7'h7D;	//Mem Register Dec
parameter[6:0] UREG_MR_MEMINC	= 7'h7E;	//Mem Register Inc
parameter[6:0] UREG_ZZR			= 7'h7F;	//No Register
