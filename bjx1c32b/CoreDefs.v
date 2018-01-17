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

`ifndef HAS_COREDEFS
`define HAS_COREDEFS

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
parameter[7:0] UCMD_ALU_ADDC	= 8'h18;	//ADDC
parameter[7:0] UCMD_ALU_SUBC	= 8'h19;	//SUBC
parameter[7:0] UCMD_ALU_ADDV	= 8'h1A;	//ADDV
parameter[7:0] UCMD_ALU_SUBV	= 8'h1B;	//SUBV
parameter[7:0] UCMD_ALU_MULUW	= 8'h1C;	//MULUW
parameter[7:0] UCMD_ALU_MULSW	= 8'h1D;	//MULSW
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
parameter[7:0] UCMD_CMP_EQ		= 8'h38;	//Rs==Rt
parameter[7:0] UCMD_CMP_GT		= 8'h39;	//Rs>Rt
parameter[7:0] UCMD_CMP_HI		= 8'h3A;	//Rs>Rt
parameter[7:0] UCMD_CMP_GE		= 8'h3B;	//Rs>=Rt
parameter[7:0] UCMD_CMP_HS		= 8'h3C;	//Rs>=Rt
parameter[7:0] UCMD_CMP_TST		= 8'h3D;	//!(Rs&Rt)

parameter[7:0] UCMD_BRAx		= 8'b001100z0;
parameter[7:0] UCMD_BSRx		= 8'b001100z1;

parameter[7:0] UCMD_RTS			= 8'h40;
parameter[7:0] UCMD_RTSN		= 8'h41;
parameter[7:0] UCMD_RTE			= 8'h42;
parameter[7:0] UCMD_RTEN		= 8'h43;
parameter[7:0] UCMD_JSR			= 8'h44;
parameter[7:0] UCMD_JSRN		= 8'h45;
parameter[7:0] UCMD_JMP			= 8'h46;
parameter[7:0] UCMD_JMPN		= 8'h47;
parameter[7:0] UCMD_ALU_MOVT	= 8'h48;
parameter[7:0] UCMD_ALU_MOVRT	= 8'h49;
// parameter[7:0] UCMD_ALU_SETT	= 8'h4A;
// parameter[7:0] UCMD_ALU_CLRT	= 8'h4B;
parameter[7:0] UCMD_MOVUB_MR	= 8'h4C;	//MOV.B @(Rs, Rt, Imm), Rn
parameter[7:0] UCMD_MOVUW_MR	= 8'h4D;	//MOV.W @(Rs, Rt, Imm), Rn
parameter[7:0] UCMD_MOVUL_MR	= 8'h4E;	//MOV.L @(Rs, Rt, Imm), Rn
// parameter[7:0] UCMD_MOVUQ_MR	= 8'h4F;	//MOV.Q @(Rs, Rt, Imm), Rn
parameter[7:0] UCMD_CASL		= 8'h4F;	//CAS.L Rm, Rn, @R0

parameter[7:0] UCMD_RTSx		= 8'b0100000z;
parameter[7:0] UCMD_RTEx		= 8'b0100001z;
parameter[7:0] UCMD_JSRx		= 8'b0100010z;
parameter[7:0] UCMD_JMPx		= 8'b0100011z;

parameter[7:0] UCMD_ALU_LDSH16	= 8'h50;	//LDSH16
parameter[7:0] UCMD_ALU_NOT		= 8'h51;	//
parameter[7:0] UCMD_ALU_SWAPB	= 8'h52;	//
parameter[7:0] UCMD_ALU_SWAPW	= 8'h53;	//
parameter[7:0] UCMD_ALU_EXTUB	= 8'h54;	//
parameter[7:0] UCMD_ALU_EXTUW	= 8'h55;	//
parameter[7:0] UCMD_ALU_EXTSB	= 8'h56;	//
parameter[7:0] UCMD_ALU_EXTSW	= 8'h57;	//
parameter[7:0] UCMD_ALU_NEG		= 8'h58;	//
parameter[7:0] UCMD_ALU_NEGC	= 8'h59;	//
parameter[7:0] UCMD_ALU_DIV0S	= 8'h5A;	//
parameter[7:0] UCMD_ALU_DIV1	= 8'h5B;	//

parameter[7:0] UCMD_ALU_CMPSTR	= 8'h5C;	//
parameter[7:0] UCMD_ALU_XTRCT	= 8'h5D;	//

parameter[7:0] UCMD_ALU_SPOP	= 8'h5E;	//

parameter[7:0] UCMD_ALU_SHLL	= 8'h60;	//1 bit
parameter[7:0] UCMD_ALU_SHAL	= 8'h61;	//1 bit
parameter[7:0] UCMD_ALU_SHLR	= 8'h62;	//1 bit
parameter[7:0] UCMD_ALU_SHAR	= 8'h63;	//
parameter[7:0] UCMD_ALU_ROTL	= 8'h64;	//
parameter[7:0] UCMD_ALU_ROTCL	= 8'h65;	//
parameter[7:0] UCMD_ALU_ROTR	= 8'h66;	//
parameter[7:0] UCMD_ALU_ROTCR	= 8'h67;	//

parameter[7:0] UCMD_ALU_DT		= 8'h68;	//

parameter[7:0] UCMD_ALU_SHLDR	= 8'h6C;	//N bit
parameter[7:0] UCMD_ALU_SHADR	= 8'h6D;	//N bit

parameter[7:0] UCMD_ALU_SHADRQ	= 8'h74;	//SHADRQ
parameter[7:0] UCMD_ALU_SHLDRQ	= 8'h75;	//SHLDRQ
parameter[7:0] UCMD_ALU_SHADQ	= 8'h76;	//SHADQ
parameter[7:0] UCMD_ALU_SHLDQ	= 8'h77;	//SHLDQ
parameter[7:0] UCMD_CMPQ_EQ		= 8'h78;	//Rs==Rt
parameter[7:0] UCMD_CMPQ_GT		= 8'h79;	//Rs>Rt
parameter[7:0] UCMD_CMPQ_HI		= 8'h7A;	//Rs>Rt
parameter[7:0] UCMD_CMPQ_GE		= 8'h7B;	//Rs>=Rt
parameter[7:0] UCMD_CMPQ_HS		= 8'h7C;	//Rs>=Rt
parameter[7:0] UCMD_CMPQ_TST	= 8'h7D;	//!(Rs&Rt)


parameter[7:0] UCMDP_ALU_DIV0U	= 8'h01;	//
parameter[7:0] UCMDP_ALU_CLRMAC	= 8'h02;	//
parameter[7:0] UCMDP_ALU_SETT	= 8'h03;
parameter[7:0] UCMDP_ALU_CLRT	= 8'h04;
parameter[7:0] UCMDP_ALU_NOTT	= 8'h05;
parameter[7:0] UCMDP_ALU_SETS	= 8'h06;
parameter[7:0] UCMDP_ALU_CLRS	= 8'h07;
parameter[7:0] UCMDP_ALU_LDTLB	= 8'h08;
parameter[7:0] UCMDP_ALU_SLEEP	= 8'h09;


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

parameter[1:0] UMEM_OK_READY	= 2'h0;		//Ready (Awaiting Request)
parameter[1:0] UMEM_OK_OK		= 2'h1;		//OK (Request Successful)
parameter[1:0] UMEM_OK_HOLD		= 2'h2;		//Hold (IO Not Ready)
parameter[1:0] UMEM_OK_FAULT	= 2'h3;		//FAULT (Request Failed)




/* Custom */
parameter[4:0]		UXFORM_CST		= 5'h0;		//custom

/* No Arg */
// parameter[4:0]		UXFORM_Z		= 5'h1;
parameter[4:0]		UXFORM_Z		= 5'h0;

/* OP XnXX */
parameter[4:0]		UXFORM_N		= 5'h2;

/* OP XmXX */
// parameter[4:0]		UXFORM_M		= 5'h3;
parameter[4:0]		UXFORM_M		= 5'h2;


/*
	XnmX       MOV.x Rm, @Rn
	XnmX       MOV.x @Rm, Rn
	8Edd_XnmX  MOV.x Rm, @(Rn, disp8s)
	8Edd_XnmX  MOV.x @(Rm, disp8s), Rn
	CEfd_XnmX  MOV.x Rm, @(Rn, disp6)
	CEfd_XnmX  MOV.x @(Rm, disp6), Rn
*/
parameter[4:0]		UXFORM_MOV_NS	= 5'h4;


/*
	XnmX       MOV.x Rm, @(Rn, R0)
	XnmX       MOV.x @(Rm, R0), Rn
	8Eod_XnmX  MOV.x Rm, @(Rn, Ro, disp4)
	8Eod_XnmX  MOV.x @(Rm, Ro, disp4), Rn
	CEeo_XnmX  MOV.x Rm, @(Rn, Ro)
	CEeo_XnmX  MOV.x @(Rm, Ro), Rn
*/
parameter[4:0]		UXFORM_MOV_NSO	= 5'h5;


/*
	Xnmd       MOV.x Rm, @(Rn, disp4)
	Xnmd       MOV.x @(Rm, disp4), Rn
	8Edd_Xnmo  MOV.x Rm, @(Rn, Ro, disp8s)
	8Edd_Xnmo  MOV.x @(Rm, Ro, disp8s), Rn
	CEed_Xnmo  MOV.x Rm, @(Rn, Ro, disp4)
	CEed_Xnmo  MOV.x @(Rm, Ro, disp4), Rn
*/
parameter[4:0]		UXFORM_MOV_NSJ	= 5'h6;


/*
	XnmX       MOV.x Rm, @-Rn
	XnmX       MOV.x @Rm+, Rn
	8Edd_XnmX  ?
	8Edd_XnmX  ?
*/
parameter[4:0]		UXFORM_MOV_NSDEC	= 5'h7;


/*
	XnmX   OP Rm, Rn
*/
parameter[4:0]		UXFORM_ARI_NS	= 5'h8;


/*
	XnmX       OP Rm, Rn
	8Ezz_XnmX  OP Rm, #Imm, Rn
*/
parameter[4:0]		UXFORM_ARI_NST	= 5'h9;


/*
	XnmX		CMP Rm, Rn
	8Eii_XniX	OP #Imm, Rn
*/
parameter[4:0]		UXFORM_CMP_ST	= 5'hA;


/*
	XstX		ARI Rt, Rs
*/
parameter[4:0]		UXFORM_ARI_ST	= 5'hB;


/*
	Xnii       OP #imm8, Rn
	8Eii_Xnii  OP #Imm16, Rn
*/
parameter[4:0]		UXFORM_ARI_NNI	= 5'hC;


/*
	Xnii       LD #imm8, Rn
	8Eii_Xnii  LD #Imm16, Rn
*/
parameter[4:0]		UXFORM_ARI_LD8	= 5'hD;


/*
	XXii       BR #disp8
	8Eii_XXii  BR #disp16
*/
parameter[4:0]		UXFORM_BR_D8	= 5'hE;


/*
	Xiii       BR #disp12
	8Eii_Xiii  BR #disp20
*/
parameter[4:0]		UXFORM_BR_D12	= 5'hF;

/*
	XXii       OP #imm8, R0
	8Eii_XXni  OP #imm12, Rn
*/
parameter[4:0]		UXFORM_ARI_I8R0	= 5'h10;
parameter[4:0]		UXFORM_CMP_I8R0	= 5'h11;

/* OP XnXX; Imm=Constant */
parameter[4:0]		UXFORM_N_C		= 5'h12;

/*
	XXii       OP @(GBR, disp8), R0
*/
parameter[4:0]		UXFORM_MOV_GD8R0	= 5'h13;


/* OP Rm, Rn */
parameter[4:0]		UXFORM_FPARI_NS	= 5'h14;

/*
	8Emo_XnXX  MOV.x Rm, @(Rn, Ro)
	8Emo_XnXX  MOV.x @(Rm, Ro), Rn
	8Est_XnXX  AROP Rs, Rt, Rn
*/
parameter[4:0]		UXFORM_NST_8E	= 5'h15;

/*
	XXnd       OP @(SP, disp4), Rn
*/
parameter[4:0]		UXFORM_MOV_SP4RN	= 5'h16;


parameter[3:0]		UXFORMZX_SX		= 4'h0;
parameter[3:0]		UXFORMZX_ZX		= 4'h1;
parameter[3:0]		UXFORMZX_NX		= 4'h2;

parameter[3:0]		UXFORMZX_PDEC	= 4'h0;
parameter[3:0]		UXFORMZX_PINC	= 4'h1;

parameter[3:0]		UXFORMZX_RR		= 4'h0;

parameter[3:0]		UXFORMZX_RM		= 4'h0;
parameter[3:0]		UXFORMZX_MR		= 4'h1;
parameter[3:0]		UXFORMZX_RM3	= 4'h2;
parameter[3:0]		UXFORMZX_MR3	= 4'h3;
parameter[3:0]		UXFORMZX_FM3	= 4'h4;
parameter[3:0]		UXFORMZX_MF3	= 4'h5;

parameter[3:0]		UXFORMZX_RM0	= 4'h6;
parameter[3:0]		UXFORMZX_MR0	= 4'h7;


parameter[3:0]		UXFORMZX_RF		= 4'h4;
parameter[3:0]		UXFORMZX_FR		= 4'h5;

parameter[3:0]		UXFORMZX_RFI	= 4'h4;
parameter[3:0]		UXFORMZX_FRD	= 4'h5;
parameter[3:0]		UXFORMZX_FF		= 4'h6;


parameter[3:0]		UXFORMZX_RS		= 4'h8;
parameter[3:0]		UXFORMZX_RC		= 4'h9;
parameter[3:0]		UXFORMZX_SR		= 4'hA;
parameter[3:0]		UXFORMZX_CR		= 4'hB;
parameter[3:0]		UXFORMZX_RSD	= 4'hC;
parameter[3:0]		UXFORMZX_RCD	= 4'hD;
parameter[3:0]		UXFORMZX_SRI	= 4'hE;
parameter[3:0]		UXFORMZX_CRI	= 4'hF;


`endif
