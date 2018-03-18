/*
Instruction Word
 15: 0, First Word
 31:16, Second Word
 */

`include "CoreDefs.v"
`include "DecOp4_XE.v"

module DecOp4(
	/* verilator lint_off UNUSED */
	clk,
	istrWord,
	regCsFl,
	idRegN,
	idRegS,
	idRegT,
	idImm,
	idStepPc,
	idStepPc2,
	idUCmd
	);

parameter		decEnable64 = 0;		//Enable BJX1-64 ISA
parameter		decEnable64A = 0;		//Enable BJX1-64A ISA
parameter		decEnableBJX1 = 1;		//Enable BJX1 extensions

input			clk;		//clock
input[47:0]		istrWord;	//source instruction word
input[15:0]		regCsFl;	//current SR/FPSCR

output[6:0]		idRegN;
output[6:0]		idRegS;
output[6:0]		idRegT;
output[31:0]	idImm;
output[3:0]		idStepPc;
output[3:0]		idStepPc2;

output[7:0]		idUCmd;


reg			isOp32;		//opcode is 32-bit
reg			isOp8E;		//8Ezz_zzzz
reg			isOpCE;		//CEzz_zzzz
reg			isOpXE;		//8Ezz_zzzz || CEzz_zzzz

reg			opPsDQ;
reg			opPwDQ;
reg			opPlDQ;
reg			opJQ;
reg			opUseBase16;	//op uses basic 16-bit decoder

reg[15:0]		opCmdWord;

reg[6:0]		opRegN;
reg[6:0]		opRegS;
reg[6:0]		opRegT;	//Index for mem ops
reg[31:0]		opImm;	//Disp for mem ops
reg[7:0]		opUCmd;
reg[3:0]		opStepPc;
reg[3:0]		opStepPc2;

reg[3:0]		opStepPc2A;
reg[3:0]		opStepPc2B;

assign	idRegN = opRegN;
assign	idRegS = opRegS;
assign	idRegT = opRegT;
assign	idImm = opImm;
assign	idUCmd = opUCmd;
assign	idStepPc = opStepPc;
assign	idStepPc2 = opStepPc2;


reg[4:0]	tOpDecXfrm;
reg[2:0]	tOpDecXfrmZx;

// reg[7:0]	tOpW2;


reg[6:0]	opRegN_Dfl;
reg[6:0]	opRegM_Dfl;
reg[6:0]	opRegO_Dfl;

reg[6:0]	opRegM_CR;
reg[6:0]	opRegM_SR;

reg[6:0]	opRegN_FR;
reg[6:0]	opRegM_FR;
reg[6:0]	opRegO_FR;
reg[6:0]	opRegS_FR;
reg[6:0]	opRegT_FR;

reg[6:0]	opRegN_N3;
reg[6:0]	opRegM_N3;

reg[31:0]	opImm_Zx4;
reg[31:0]	opImm_Zx8;
reg[31:0]	opImm_Sx8;
reg[31:0]	opImm_Sx12;

//reg			opIsRegN_FR;
//reg			opIsRegM_FR;

reg			opIsRegM_CR;
reg			opIsRegM_SR;

// reg			opIsXe;
wire[6:0]	opRegXeN;
wire[6:0]	opRegXeS;
wire[6:0]	opRegXeT;
wire[31:0]	opImmXe;
wire[7:0]	opUCmdXe;

DecOp4_XE decXe(istrWord[31:0],
	opRegXeN, opRegXeS, opRegXeT,
	opImmXe, opUCmdXe);

always @*
begin

	opStepPc = 2;
	
//	opPfxImm=0;
//	opCmdWord=0;

	opCmdWord=0;

	opUCmd=UCMD_UDBRK;
	opImm=0;


	isOp32=0;
	isOp8E=0;	isOpCE=0;	isOpXE=0;
//	isOpCC0=0;	isOpCC3=0;	opCCe=0;
	opUseBase16=1;

//	opIsXe = 0;


	opRegN=UREG_ZZR;
	opRegS=UREG_ZZR;
	opRegT=UREG_ZZR;

//	opIsRegN_FR=0;	opIsRegM_FR=0;
//	opIsRegS_FR=0;	opIsRegT_FR=0;
//	opIsRegM_CR=0;	opIsRegM_SR=0;

	tOpDecXfrm=UXFORM_INVALID;
	tOpDecXfrmZx=UXFORMZX_SX;

	if(decEnable64 && regCsFl[5])
	begin
		opJQ=1;			opPsDQ=regCsFl[6];
		opPwDQ=opPsDQ;	opPlDQ=0;
	end else begin
		opJQ=0;			opPsDQ=0;
		opPwDQ=0;		opPlDQ=0;
	end

	opCmdWord=istrWord[15:0];
//	tOpW2=istrWord[31:24];

	opStepPc2 = 2;

	opStepPc2A=2;
	opStepPc2B=2;

	if(decEnableBJX1)
	begin

		if(istrWord[47:44]==4'h8)
		begin
			if(	(istrWord[43:40]==4'hA) ||
				(istrWord[43:40]==4'hC) ||
				(istrWord[43:40]==4'hE))
					opStepPc2A=4;
		end

		if(istrWord[31:28]==4'h8)
		begin
			if(	(istrWord[27:24]==4'hA) ||
				(istrWord[27:24]==4'hC) ||
				(istrWord[27:24]==4'hE))
					opStepPc2B=4;
		end

	end

	casez(opCmdWord[15:12])

		4'h0: case(opCmdWord[3:0])
			4'h2: begin		//0xx2, STC
				opUCmd=UCMD_MOV_RR;		tOpDecXfrm=UXFORM_ARIC_NS;
				tOpDecXfrmZx=UXFORMZX_CR;
			end

			4'h4: begin		//0xx4
				opUCmd=UCMD_MOVB_RM;	tOpDecXfrm=UXFORM_MOV_NSO;
			end

			4'h5: begin		//0xx5
				opUCmd = opPwDQ ? UCMD_MOVQ_RM : UCMD_MOVW_RM;
				tOpDecXfrm=UXFORM_MOV_NSO;
			end

			4'h6: begin		//0xx6
				opUCmd = opPlDQ ? UCMD_MOVQ_RM : UCMD_MOVL_RM;
				tOpDecXfrm=UXFORM_MOV_NSO;
			end

			4'h7: begin		//0xx7
				opUCmd=UCMD_ALU_DMULS;	tOpDecXfrm=UXFORM_ARI_ST;
			end

			4'h8: case(opCmdWord[7:4])
				4'h0: begin		//0x08
					opUCmd=UCMD_ALU_SPOP;
					opImm[7:0]=UCMDP_ALU_CLRT;
					tOpDecXfrm=UXFORM_CST;
				end
				4'h1: begin		//0x18
					opUCmd=UCMD_ALU_SPOP;
					opImm[7:0]=UCMDP_ALU_SETT;
					tOpDecXfrm=UXFORM_CST;
				end
				4'h2: begin		//0x28
					opUCmd=UCMD_ALU_SPOP;
					opImm[7:0]=UCMDP_ALU_CLRMAC;
					tOpDecXfrm=UXFORM_CST;
				end
				4'h3: begin		//0x38
					opUCmd=UCMD_ALU_SPOP;
					opImm[7:0]=UCMDP_ALU_LDTLB;
					tOpDecXfrm=UXFORM_CST;
				end
				4'h4: begin		//0x48
					opUCmd=UCMD_ALU_SPOP;
					opImm[7:0]=UCMDP_ALU_CLRS;
					tOpDecXfrm=UXFORM_CST;
				end
				4'h5: begin		//0x58
					opUCmd=UCMD_ALU_SPOP;
					opImm[7:0]=UCMDP_ALU_SETS;
					tOpDecXfrm=UXFORM_CST;
				end
				4'h6: begin		//0x68
					opUCmd=UCMD_ALU_SPOP;
					opImm[7:0]=UCMDP_ALU_NOTT;
					tOpDecXfrm=UXFORM_CST;
				end
				default: begin end
			endcase

			4'h9: case(opCmdWord[7:4])
				4'h0: begin		//0x09
					opUCmd=UCMD_NONE;		tOpDecXfrm=UXFORM_Z;
				end
				4'h1: begin		//0x19
					opUCmd=UCMD_ALU_SPOP;
					opImm[7:0]=UCMDP_ALU_DIV0U;
					tOpDecXfrm=UXFORM_CST;
				end
				4'h2: begin		//0x29
					opUCmd=UCMD_ALU_MOVT;	tOpDecXfrm=UXFORM_N;
				end
				4'h3: begin		//0x39
					opUCmd=UCMD_ALU_MOVRT;	tOpDecXfrm=UXFORM_N;
				end
				default: begin end
			endcase

			4'hA: begin		//0xxA
				opUCmd=UCMD_MOV_RR;		tOpDecXfrm=UXFORM_ARIC_NS;
				tOpDecXfrmZx=UXFORMZX_SR;
			end

			4'hB: case(opCmdWord[7:4])
				4'h0: begin		//0z0B
					opUCmd=UCMD_RTS;		tOpDecXfrm=UXFORM_Z;
				end

				4'h1: begin		//0x1B
					opUCmd=UCMD_ALU_SPOP;
					opImm[7:0]=UCMDP_ALU_SLEEP;
					tOpDecXfrm=UXFORM_CST;
				end

				4'h2: begin		//0z2B
					opUCmd=UCMD_RTE;		tOpDecXfrm=UXFORM_Z;
				end

				4'h3: begin		//0z3B
					opUCmd=UCMD_UDBRK;		tOpDecXfrm=UXFORM_Z;
					opImm=1;
					if(opCmdWord[11:8]==4'hF)
					begin
						opUCmd=UCMD_NONE;
						opStepPc=0;
					end
				end

				4'h6: begin		//0z6B
					opUCmd=UCMD_RTSN;		tOpDecXfrm=UXFORM_Z;
				end
				default: begin end
			endcase

			4'hC: begin		//0xxC
				opUCmd=UCMD_MOVB_MR;	tOpDecXfrm=UXFORM_MOV_NSO;
			end

			4'hD: begin		//0xxD
				opUCmd = opPwDQ ? UCMD_MOVQ_MR : UCMD_MOVW_MR;
				tOpDecXfrm=UXFORM_MOV_NSO;
			end

			4'hE: begin		//0xxE
				opUCmd = UCMD_MOVL_MR;
				tOpDecXfrm=UXFORM_MOV_NSO;
			end

			default: begin end
		endcase

		4'h1: begin		//1nmd, MOV.L Rm, @(Rn, disp4)
			opUCmd =  opPlDQ ? UCMD_MOVQ_RM : UCMD_MOVL_RM;
			tOpDecXfrm=UXFORM_MOV_NSJ;
		end

		4'h2: case(opCmdWord[3:0])
			4'h0: begin		//2xx0, MOV.B Rm, @Rn
				opUCmd=UCMD_MOVB_RM;	tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'h1: begin		//2xx1, MOV.W Rm, @Rn
				opUCmd = opPwDQ ? UCMD_MOVQ_RM : UCMD_MOVW_RM;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'h2: begin		//2xx2, MOV.L Rm, @Rn
				opUCmd = opPlDQ ? UCMD_MOVQ_RM : UCMD_MOVL_RM;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'h3: begin		//2xx3, CAS.L Rm, Rn, @R0
				opUCmd=UCMD_CASL;		tOpDecXfrm=UXFORM_MOV_NSO;
			end
			4'h4: begin		//2xx4, MOV.B @Rm, Rn
				opUCmd=UCMD_MOVB_RM;	tOpDecXfrm=UXFORM_MOV_NSDEC;
				tOpDecXfrmZx=UXFORMZX_PDEC;
			end
			4'h5: begin		//2xx5, MOV.W @Rm, Rn
				opUCmd = opPwDQ ? UCMD_MOVQ_RM : UCMD_MOVW_RM;
				tOpDecXfrm=UXFORM_MOV_NSDEC;
				tOpDecXfrmZx=UXFORMZX_PDEC;
			end
			4'h6: begin		//2xx6, MOV.L @Rm, Rn
				opUCmd = opPlDQ ? UCMD_MOVQ_RM : UCMD_MOVL_RM;
				tOpDecXfrm=UXFORM_MOV_NSDEC;
				tOpDecXfrmZx=UXFORMZX_PDEC;
			end
			4'h7: begin		//2xx7, DIV0S Rm, Rn
				opUCmd=UCMD_ALU_DIV0S;	tOpDecXfrm=UXFORM_ARI_ST;
			end
			4'h8: begin		//2xx8, TST Rm, Rn
				opUCmd=UCMD_CMP_TST;	tOpDecXfrm=UXFORM_CMP_ST;
				tOpDecXfrmZx=UXFORMZX_ZX;
			end
			4'h9: begin		//2xx9, AND Rm, Rn
				opUCmd=UCMD_ALU_AND;	tOpDecXfrm=UXFORM_ARI_NST;
				tOpDecXfrmZx=UXFORMZX_ZX;
			end
			4'hA: begin		//2xxA, XOR Rm, Rn
				opUCmd=UCMD_ALU_XOR;	tOpDecXfrm=UXFORM_ARI_NST;
				tOpDecXfrmZx=UXFORMZX_ZX;
			end
			4'hB: begin		//2xxB, OR Rm, Rn
				opUCmd=UCMD_ALU_OR;		tOpDecXfrm=UXFORM_ARI_NST;
				tOpDecXfrmZx=UXFORMZX_ZX;
			end
			4'hC: begin		//2xxC, CMPSTR Rm, Rn
				opUCmd=UCMD_ALU_CMPSTR;	tOpDecXfrm=UXFORM_ARI_NST;
			end
			4'hD: begin		//2xxD, XTRCT Rm, Rn
				opUCmd=UCMD_ALU_XTRCT;	tOpDecXfrm=UXFORM_ARI_NST;
			end
			4'hE: begin		//2xxE, MULU.W Rm, Rn
				opUCmd=UCMD_ALU_MULUW;	tOpDecXfrm=UXFORM_ARI_ST;
			end
			4'hF: begin		//2xxF, MULS.W Rm, Rn
				opUCmd=UCMD_ALU_MULSW;	tOpDecXfrm=UXFORM_ARI_ST;
			end
			default: begin end
		endcase

		4'h3: case(opCmdWord[3:0])
			4'h0: begin		//3xx0, CMP/EQ Rm, Rn
				opUCmd=opPsDQ ? UCMD_CMPQ_EQ : UCMD_CMP_EQ;
				tOpDecXfrm=UXFORM_CMP_ST;
			end

			4'h2: begin		//3xx2, CMP/HS Rm, Rn
				opUCmd=opPsDQ ? UCMD_CMPQ_HS : UCMD_CMP_HS;
				tOpDecXfrm=UXFORM_CMP_ST;
			end
			4'h3: begin		//3xx3, CMP/GE Rm, Rn
				opUCmd=opPsDQ ? UCMD_CMPQ_GE : UCMD_CMP_GE;
				tOpDecXfrm=UXFORM_CMP_ST;
			end
			4'h4: begin		//3xx4, DIV1 Rm, Rn
				opUCmd=UCMD_ALU_DIV1;		tOpDecXfrm=UXFORM_ARI_NST;
			end
			4'h5: begin		//3xx5, DMULU.L Rm, Rn
				opUCmd=UCMD_ALU_DMULU;	tOpDecXfrm=UXFORM_ARI_ST;
			end
			4'h6: begin		//3xx6, CMP/HI Rm, Rn
				opUCmd=opPsDQ ? UCMD_CMPQ_HI : UCMD_CMP_HI;
				tOpDecXfrm=UXFORM_CMP_ST;
			end
			4'h7: begin		//3xx7, CMP/GT Rm, Rn
				opUCmd=opPsDQ ? UCMD_CMPQ_GT : UCMD_CMP_GT;
				tOpDecXfrm=UXFORM_CMP_ST;
			end
			4'h8: begin		//3xx8, SUB Rm, Rn
				opUCmd=UCMD_ALU_SUB;	tOpDecXfrm=UXFORM_ARI_NST;
				tOpDecXfrmZx=UXFORMZX_ZX;
			end

			4'hA: begin		//3xxA, SUBC Rm, Rn
				opUCmd=UCMD_ALU_SUBC;	tOpDecXfrm=UXFORM_ARI_NST;
				tOpDecXfrmZx=UXFORMZX_ZX;
			end
			4'hB: begin		//3xxB, SUBV Rm, Rn
				opUCmd=UCMD_ALU_SUBV;	tOpDecXfrm=UXFORM_ARI_NST;
				tOpDecXfrmZx=UXFORMZX_ZX;
			end
			4'hC: begin		//3xxC, ADD Rm, Rn
				opUCmd=UCMD_ALU_ADD;	tOpDecXfrm=UXFORM_ARI_NST;
				tOpDecXfrmZx=UXFORMZX_ZX;
			end
			4'hD: begin		//3xxD, DMULS.L Rm, Rn
				opUCmd=UCMD_ALU_DMULS;	tOpDecXfrm=UXFORM_ARI_ST;
			end
			4'hE: begin		//3xxE, ADDC Rm, Rn
				opUCmd=UCMD_ALU_ADDC;	tOpDecXfrm=UXFORM_ARI_NST;
			end
			4'hF: begin		//3xxF, ADDV Rm, Rn
				opUCmd=UCMD_ALU_ADDV;	tOpDecXfrm=UXFORM_ARI_NST;
			end
			default: begin end
		endcase

		4'h4: case(opCmdWord[3:0])
			4'h0: case(opCmdWord[7:4])
				4'h0: begin		//4x00
					opUCmd=UCMD_ALU_SHLL;	tOpDecXfrm=UXFORM_N;
				end
				4'h1: begin		//4x10
					opUCmd=UCMD_ALU_DT;		tOpDecXfrm=UXFORM_N;
				end
				4'h2: begin		//4x20
					opUCmd=UCMD_ALU_SHAL;	tOpDecXfrm=UXFORM_N;
				end
				default: begin end
			endcase

			4'h1: case(opCmdWord[7:4])
				4'h0: begin		//4x01
					opUCmd=UCMD_ALU_SHLR;	tOpDecXfrm=UXFORM_N;
				end
				4'h1: begin		//4x11
					opUCmd=opPsDQ ? UCMD_CMPQ_GE : UCMD_CMP_GE;
					tOpDecXfrm=UXFORM_M;
				end
				4'h2: begin		//4x21
					opUCmd=UCMD_ALU_SHAR;	tOpDecXfrm=UXFORM_N;
				end
				default: begin end
			endcase

			4'h2: begin		//4xx2
				opUCmd = opJQ ? UCMD_MOVQ_RM : UCMD_MOVL_RM;
				tOpDecXfrm=UXFORM_MOVC_NSDEC;
				tOpDecXfrmZx=UXFORMZX_SR;
			end
			4'h3: begin		//4xx3
				opUCmd = opJQ ? UCMD_MOVQ_RM : UCMD_MOVL_RM;
				tOpDecXfrm=UXFORM_MOVC_NSDEC;
				tOpDecXfrmZx=UXFORMZX_CR;
			end

			4'h4: case(opCmdWord[7:4])
				4'h0: begin		//4x00
					opUCmd=UCMD_ALU_ROTL;	tOpDecXfrm=UXFORM_N;
				end
	//			4'h1: begin		//4x10
	//				opUCmd=UCMD_ALU_DT;		tOpDecXfrm=UXFORM_N;
	//			end
				4'h2: begin		//4x20
					opUCmd=UCMD_ALU_ROTCL;	tOpDecXfrm=UXFORM_N;
				end
				default: begin end
			endcase

			4'h5: case(opCmdWord[7:4])
				4'h0: begin		//4x01
					opUCmd=UCMD_ALU_ROTR;	tOpDecXfrm=UXFORM_N;
				end
				4'h1: begin		//4x11
					opUCmd=opPsDQ ? UCMD_CMPQ_GT : UCMD_CMP_GT;
					tOpDecXfrm=UXFORM_M;
				end
				4'h2: begin		//4x21
					opUCmd=UCMD_ALU_ROTCR;	tOpDecXfrm=UXFORM_N;
				end
				default: begin end
			endcase

			4'h6: begin		//4xx6
				opUCmd = opJQ ? UCMD_MOVQ_MR : UCMD_MOVL_MR;
				tOpDecXfrm=UXFORM_MOVC_NSDEC;
				tOpDecXfrmZx=UXFORMZX_RS;
			end
			4'h7: begin		//4xx7
				opUCmd = opJQ ? UCMD_MOVQ_RM : UCMD_MOVL_MR;
				tOpDecXfrm=UXFORM_MOVC_NSDEC;
				tOpDecXfrmZx=UXFORMZX_RC;
			end

			4'h8: case(opCmdWord[7:4])
				4'h0: begin		//4x08
					opUCmd=UCMD_ALU_SHLD;	tOpDecXfrm=UXFORM_N_C;
					opImm=2;
				end
				4'h1: begin		//4x18
					opUCmd=UCMD_ALU_SHLD;	tOpDecXfrm=UXFORM_N_C;
					opImm=8;
				end
				4'h2: begin		//4x28
					opUCmd=UCMD_ALU_SHLD;	tOpDecXfrm=UXFORM_N_C;
					opImm=16;
				end
				default: begin end
			endcase

			4'h9: case(opCmdWord[7:4])
				4'h0: begin		//4x09
					opUCmd=UCMD_ALU_SHLD;	tOpDecXfrm=UXFORM_N_C;
					opImm=-2;
				end
				4'h1: begin		//4x19
					opUCmd=UCMD_ALU_SHLD;	tOpDecXfrm=UXFORM_N_C;
					opImm=-8;
				end
				4'h2: begin		//4x29
					opUCmd=UCMD_ALU_SHLD;	tOpDecXfrm=UXFORM_N_C;
					opImm=-16;
				end
				default: begin end
			endcase

			4'hA: begin		//4xxA, LDS
				opUCmd=UCMD_MOV_RR;		tOpDecXfrm=UXFORM_ARIC_NS;
				tOpDecXfrmZx=UXFORMZX_RS;
			end

			4'hB: case(opCmdWord[7:4])
				4'h0: begin
					opUCmd=UCMD_JSR;	tOpDecXfrm=UXFORM_M;
				end

				4'h2: begin
					opUCmd=UCMD_JMP;	tOpDecXfrm=UXFORM_M;
				end
				4'h3: begin
				end
				4'h4: begin
					opUCmd=UCMD_JSRN;	tOpDecXfrm=UXFORM_M;
				end
				default: begin end
			endcase

			4'hC: begin		//4xxC
				opUCmd=opPsDQ ? UCMD_ALU_SHADQ : UCMD_ALU_SHAD;
				tOpDecXfrm=UXFORM_ARI_NST;
				tOpDecXfrmZx=UXFORMZX_SX;
			end
			4'hD: begin		//4xxD
				opUCmd=opPsDQ ? UCMD_ALU_SHLDQ : UCMD_ALU_SHLD;
				tOpDecXfrm=UXFORM_ARI_NST;
				tOpDecXfrmZx=UXFORMZX_SX;
			end
			4'hE: begin		//4xxE, LDC
				opUCmd=UCMD_MOV_RR;		tOpDecXfrm=UXFORM_ARIC_NS;
				tOpDecXfrmZx=UXFORMZX_RC;
			end
			default: begin end
		endcase

		4'h5: begin		//5xxx
			opUCmd = UCMD_MOVL_MR;
			tOpDecXfrm=UXFORM_MOV_NSJ;
		end

		4'h6: case(opCmdWord[3:0])
			4'h0: begin		//6xx0
				opUCmd=UCMD_MOVB_MR;	tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'h1: begin		//6xx1
				opUCmd = opPwDQ ? UCMD_MOVQ_MR : UCMD_MOVW_MR;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'h2: begin		//6xx2
				opUCmd = UCMD_MOVL_MR;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'h3: begin		//6xx3
				opUCmd=UCMD_MOV_RR;		tOpDecXfrm=UXFORM_ARI_NS;
			end
			4'h4: begin		//6xx4
				opUCmd=UCMD_MOVB_MR;	tOpDecXfrm=UXFORM_MOV_NSDEC;
				tOpDecXfrmZx=UXFORMZX_PINC;
			end
			4'h5: begin		//6xx5
				opUCmd = opPwDQ ? UCMD_MOVQ_MR : UCMD_MOVW_MR;
				tOpDecXfrm=UXFORM_MOV_NSDEC;
				tOpDecXfrmZx=UXFORMZX_PINC;
			end
			4'h6: begin		//6xx6
				opUCmd = UCMD_MOVL_MR;
				tOpDecXfrm=UXFORM_MOV_NSDEC;
				tOpDecXfrmZx=UXFORMZX_PINC;
			end
			4'h7: begin
				opUCmd=UCMD_ALU_NOT;	tOpDecXfrm=UXFORM_ARI_NS;
			end
			4'h8: begin
				opUCmd=UCMD_ALU_SWAPB;	tOpDecXfrm=UXFORM_ARI_NS;
			end
			4'h9: begin
				opUCmd=UCMD_ALU_SWAPW;	tOpDecXfrm=UXFORM_ARI_NS;
			end
			4'hA: begin
				opUCmd=UCMD_ALU_NEGC;	tOpDecXfrm=UXFORM_ARI_NS;
			end
			4'hB: begin
				opUCmd=UCMD_ALU_NEG;	tOpDecXfrm=UXFORM_ARI_NS;
			end
			4'hC: begin
				opUCmd=UCMD_ALU_EXTUB;	tOpDecXfrm=UXFORM_ARI_NS;
			end
			4'hD: begin
				opUCmd=UCMD_ALU_EXTUW;	tOpDecXfrm=UXFORM_ARI_NS;
			end
			4'hE: begin
				opUCmd=UCMD_ALU_EXTSB;	tOpDecXfrm=UXFORM_ARI_NS;
			end
			4'hF: begin
				opUCmd=UCMD_ALU_EXTSW;	tOpDecXfrm=UXFORM_ARI_NS;
			end
			default: begin end
		endcase

		4'h7: begin		//7xxx
			opUCmd=UCMD_ALU_ADD;	tOpDecXfrm=UXFORM_ARI_NNI;
		end

		4'h8: case(opCmdWord[11:8])
			4'h0: begin		//80xx
				opUCmd=UCMD_MOVB_RM;
				tOpDecXfrm=UXFORM_MOV_SP4RN;
				tOpDecXfrmZx=UXFORMZX_RM0;
			end
			4'h1: begin		//81xx
				opUCmd=UCMD_MOVW_RM;
				tOpDecXfrm=UXFORM_MOV_SP4RN;
				tOpDecXfrmZx=UXFORMZX_RM0;
			end

			4'h2: begin		//82xx
				opUCmd=UCMD_BRAN;		tOpDecXfrm=UXFORM_BR_D8;
			end
			4'h3: begin		//83xx
				tOpDecXfrm=UXFORM_MOV_SP4RN;
				if(opCmdWord[7])
				begin
					opUCmd=UCMD_MOVL_MR;
					tOpDecXfrmZx=UXFORMZX_MR3;
				end else begin
					opUCmd=UCMD_MOVL_RM;
					tOpDecXfrmZx=UXFORMZX_RM3;
				end
			end

			4'h4: begin		//84xx
				opUCmd=UCMD_MOVB_MR;
				tOpDecXfrm=UXFORM_MOV_SP4RN;
				tOpDecXfrmZx=UXFORMZX_MR0;
			end
			4'h5: begin		//85xx
				opUCmd=UCMD_MOVW_MR;
				tOpDecXfrm=UXFORM_MOV_SP4RN;
				tOpDecXfrmZx=UXFORMZX_MR0;
			end

			4'h6: begin		//86xx
				tOpDecXfrm=UXFORM_MOV_SP4RN;
				if(opCmdWord[7])
				begin
					opUCmd=UCMD_MOVL_MR;
					tOpDecXfrmZx=UXFORMZX_MF3;
				end else begin
					opUCmd=UCMD_MOVL_RM;
					tOpDecXfrmZx=UXFORMZX_FM3;
				end
			end

			4'h7: begin		//87xx
			end

			4'h8: begin		//88xx
				opUCmd=UCMD_CMP_EQ;
				tOpDecXfrm=UXFORM_ARI_I8R0;
			end
			4'h9: begin		//89xx
				opUCmd=UCMD_BT;		tOpDecXfrm=UXFORM_BR_D8;
			end
			4'hA: begin		//8Axx-xxxx
				if(decEnableBJX1)
				begin
					opRegN=UREG_R0;
					opUCmd=UCMD_MOV_RI;
					opImm={istrWord[7] ? 8'hFF : 8'h00,
						istrWord[7:0], istrWord[31:16]};
					tOpDecXfrm=UXFORM_CST;
				end
			end
			4'hB: begin		//8Bxx, BF disp
				opUCmd=UCMD_BF;		tOpDecXfrm=UXFORM_BR_D8;
			end
			4'hC: begin		//8Cxx
				/* Escape */
			end
			4'hD: begin		//8Dxx, BTS disp
				opUCmd=UCMD_BTS;		tOpDecXfrm=UXFORM_BR_D8;
			end
			4'hE: begin		//8Exx
				/* Escape */
				if(decEnableBJX1)
				begin
					isOpXE = 1;
					opStepPc = 4;
				end
			end
			4'hF: begin		//8Fxx, BFS disp
				opUCmd=UCMD_BFS;		tOpDecXfrm=UXFORM_BR_D8;
			end
			default: begin end
		endcase

		4'h9: begin		//9xxx
			opRegN[3:0]=opCmdWord[11:8];
			opRegS=UREG_PCW;
			opRegT=UREG_ZZR;
			opImm[7:0]=opCmdWord[ 7:0];
			opUCmd=UCMD_MOVW_MR;
			tOpDecXfrm=UXFORM_CST;
		end

		4'hA: begin		//Axxx
			opUCmd=UCMD_BRA;		tOpDecXfrm=UXFORM_BR_D12;
		end

		4'hB: begin		//Bxxx
			opUCmd=UCMD_BSR;		tOpDecXfrm=UXFORM_BR_D12;
		end

		4'hC: case(opCmdWord[11:8])
			4'h0: begin
				if(opJQ)
				begin
					opUCmd=UCMD_MOVQ_RM;
					tOpDecXfrm=UXFORM_MOV_SP4RN;
					tOpDecXfrmZx=UXFORMZX_RM;
				end else begin
					opUCmd=UCMD_MOVB_RM;
					tOpDecXfrm=UXFORM_MOV_GD8R0;
					tOpDecXfrmZx=UXFORMZX_RM;
				end
			end

			4'h1: begin
				if(opJQ)
				begin
				end else begin
					opUCmd=UCMD_MOVW_RM;
					tOpDecXfrm=UXFORM_MOV_GD8R0;
					tOpDecXfrmZx=UXFORMZX_RM;
				end
			end

			4'h2: begin
				if(opJQ)
				begin
				end else begin
					opUCmd=UCMD_MOVL_RM;
					tOpDecXfrm=UXFORM_MOV_GD8R0;
					tOpDecXfrmZx=UXFORMZX_RM;
				end
			end

			4'h4: begin
				if(opJQ)
				begin
					opUCmd=UCMD_MOVQ_MR;
					tOpDecXfrm=UXFORM_MOV_SP4RN;
					tOpDecXfrmZx=UXFORMZX_MR;
				end else begin
					opUCmd=UCMD_MOVB_MR;
					tOpDecXfrm=UXFORM_MOV_GD8R0;
					tOpDecXfrmZx=UXFORMZX_MR;
				end
			end

			4'h5: begin
				if(opJQ)
				begin
				end else begin
					opUCmd=UCMD_MOVW_MR;
					tOpDecXfrm=UXFORM_MOV_GD8R0;
					tOpDecXfrmZx=UXFORMZX_MR;
				end
			end

			4'h6: begin
				if(opJQ)
				begin
				end else begin
					opUCmd=UCMD_MOVL_MR;
					tOpDecXfrm=UXFORM_MOV_GD8R0;
					tOpDecXfrmZx=UXFORMZX_MR;
				end
			end

			4'h8: begin		//CMP/EQ #imm, R0
				opUCmd=opPsDQ ? UCMD_CMPQ_TST : UCMD_CMP_TST;
				tOpDecXfrm=UXFORM_CMP_I8R0;
			end
			4'h9: begin		//AND #imm, R0
				opUCmd=UCMD_ALU_AND;	tOpDecXfrm=UXFORM_ARI_I8R0;
			end
			4'hA: begin		//XOR #imm, R0
				opUCmd=UCMD_ALU_XOR;	tOpDecXfrm=UXFORM_ARI_I8R0;
			end
			4'hB: begin		//OR #imm, R0
				opUCmd=UCMD_ALU_OR;		tOpDecXfrm=UXFORM_ARI_I8R0;
			end
			default: begin end
		endcase

		4'hD: begin		//Dxxx, MOV @(PC,disp), Rn
			opRegN[3:0]=opCmdWord[11:8];
			opRegS=UREG_PCL;
			opRegT=UREG_ZZR;
			opImm[7:0]=opCmdWord[ 7:0];
			opUCmd=UCMD_MOVL_MR;
			tOpDecXfrm=UXFORM_CST;
		end

		4'hE: begin		//Exxx, MOV #imm, Rn
			opUCmd=UCMD_MOV_RI;
			tOpDecXfrm=UXFORM_ARI_NNI;
		end

		4'hF: case(opCmdWord[3:0])
			4'h0: begin
				opUCmd=UCMD_FPU_ADD;
				tOpDecXfrm=UXFORM_FPARI_NS;
			end
			4'h1: begin
				opUCmd=UCMD_FPU_SUB;
				tOpDecXfrm=UXFORM_FPARI_NS;
			end
			4'h2: begin
				opUCmd=UCMD_FPU_MUL;
				tOpDecXfrm=UXFORM_FPARI_NS;
			end

			4'h4: begin
				opUCmd=UCMD_FPU_CMPEQ;
				tOpDecXfrm=UXFORM_FPARI_NS;
			end
			4'h5: begin
				opUCmd=UCMD_FPU_CMPGT;
				tOpDecXfrm=UXFORM_FPARI_NS;
			end

			4'h6: begin
				opUCmd=UCMD_MOVL_MR;	tOpDecXfrm=UXFORM_MOV_NSO;
				tOpDecXfrmZx=UXFORMZX_RF;
			end
			4'h7: begin
				opUCmd=UCMD_MOVL_RM;	tOpDecXfrm=UXFORM_MOV_NSO;
				tOpDecXfrmZx=UXFORMZX_FR;
			end

			4'h8: begin
				opUCmd=UCMD_MOVL_MR;	tOpDecXfrm=UXFORM_MOV_NS;
				tOpDecXfrmZx=UXFORMZX_RF;
			end
			4'h9: begin
				opUCmd=UCMD_MOVL_MR;	tOpDecXfrm=UXFORM_MOV_NSDEC;
				tOpDecXfrmZx=UXFORMZX_RFI;
			end

			4'hA: begin
				opUCmd=UCMD_MOVL_RM;	tOpDecXfrm=UXFORM_MOV_NS;
				tOpDecXfrmZx=UXFORMZX_FR;
			end
	//		4'hB: begin
	//			opUCmd=UCMD_MOVL_RM;	tOpDecXfrm=UXFORM_MOV_NSDEC;
	//			opIsRegM_FR=1;
	//			tOpDecXfrmZx=UXFORMZX_FRD;
	//		end
			default: begin end

		endcase

		default: begin end

	endcase

	opRegN_Dfl	= {3'b000, opCmdWord[11:8]};
	opRegM_Dfl	= {3'b000, opCmdWord[ 7:4]};
	opRegO_Dfl	= {3'b000, opCmdWord[ 3:0]};

	if(opCmdWord[11])	//RmB
		opRegM_CR={3'h2, 1'b0, opCmdWord[6:4]};
	else
		opRegM_CR={3'h7, opCmdWord[7:4]};

	opRegM_SR={3'h6, opCmdWord[7:4]};

	opRegN_FR	= {3'h4, opCmdWord[11:8]};
	opRegM_FR	= {3'h4, opCmdWord[ 7:4]};
	opRegO_FR	= {3'h4, opCmdWord[ 3:0]};

	opRegN_N3 = (opCmdWord[6:4]==3'b111) ? UREG_R0 :
		{3'h0, 1'b1, opCmdWord[6:4]};
	opRegM_N3 = (opCmdWord[2:0]==3'b111) ? UREG_R0 :
		{3'h0, 1'b1, opCmdWord[2:0]};

	opImm_Zx4	= {28'h0, opCmdWord[ 3:0]};
	opImm_Zx8	= {24'h0, opCmdWord[ 7:0]};
	opImm_Sx8	= {opCmdWord[ 7] ? 24'hFFFFFF : 24'h000000, opCmdWord [ 7:0]};
	opImm_Sx12	= {opCmdWord[11] ? 20'hFFFFF  : 20'h00000 , opCmdWord [11:0]};

// /*
	case(tOpDecXfrm)

		UXFORM_CST: begin
		end

		UXFORM_N: begin
			opRegN=opRegN_Dfl;
			opRegS=opRegN;
		end

		UXFORM_MOV_NS: begin
			opRegN=opRegN_Dfl;		opRegS=opRegM_Dfl;
		end

		UXFORM_MOV_NSO: begin
			opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
			opRegT=UREG_R0;		opImm=0;
		end

		UXFORM_MOV_NSJ: begin
			opRegN=opRegN_Dfl;		opRegS=opRegM_Dfl;
			opImm  = opImm_Zx4;
		end

		UXFORM_MOV_NSDEC: begin
			case(tOpDecXfrmZx)
				UXFORMZX_PDEC: begin
					opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
					opRegT=UREG_MR_MEMDEC;
				end

				UXFORMZX_PINC: begin
					opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
					opRegT=UREG_MR_MEMINC;
				end

				UXFORMZX_FRD: begin
					opRegN=opRegN_Dfl;	opRegS=opRegM_FR;
					opRegT=UREG_MR_MEMDEC;
				end
				UXFORMZX_RFI: begin
					opRegN=opRegN_FR;	opRegS=opRegM_Dfl;
					opRegT=UREG_MR_MEMINC;
				end
				
				default: begin
					opRegN=UREG_XX;		opRegS=UREG_XX;
					opRegT=UREG_XX;		opImm=32'hXXXXXXXX;
				end
			endcase
		end

		UXFORM_MOVC_NSDEC: begin
			case(tOpDecXfrmZx)
				UXFORMZX_RS: begin
					opRegN=opRegM_SR;	opRegS=opRegN_Dfl;
					opRegT=UREG_MR_MEMINC;
				end
				UXFORMZX_RC: begin
					opRegN=opRegM_CR;	opRegS=opRegN_Dfl;
					opRegT=UREG_MR_MEMINC;
				end

				UXFORMZX_SR: begin
					opRegN=opRegN_Dfl;	opRegS=opRegM_SR;
					opRegT=UREG_MR_MEMDEC;
				end
				UXFORMZX_CR: begin
					opRegN=opRegN_Dfl;	opRegS=opRegM_CR;
					opRegT=UREG_MR_MEMDEC;
				end

				default: begin
					opRegN=UREG_XX;		opRegS=UREG_XX;
					opRegT=UREG_XX;		opImm=32'hXXXXXXXX;
				end

			endcase

		end

		UXFORM_FPARI_NS: begin
			opRegN=opRegN_FR;
			opRegS=opRegM_FR;
		end

		UXFORM_ARI_NS: begin
			case(tOpDecXfrmZx)
				UXFORMZX_RR: begin
					opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
				end
				
				UXFORMZX_FF: begin
					opRegN=opRegN_FR;	opRegS=opRegM_FR;
				end

				default: begin
					opRegN=UREG_XX;		opRegS=UREG_XX;
					opRegT=UREG_XX;		opImm=32'hXXXXXXXX;
				end
			endcase
		end

		UXFORM_ARIC_NS: begin
			case(tOpDecXfrmZx)
				UXFORMZX_RS: begin
					opRegN=opRegM_SR;	opRegS=opRegN_Dfl;
				end
				UXFORMZX_RC: begin
					opRegN=opRegM_CR;	opRegS=opRegN_Dfl;
				end

				UXFORMZX_SR: begin
					opRegN=opRegN_Dfl;	opRegS=opRegM_SR;
				end
				UXFORMZX_CR: begin
					opRegN=opRegN_Dfl;	opRegS=opRegM_CR;
				end

				default: begin
					opRegN=UREG_XX;		opRegS=UREG_XX;
					opRegT=UREG_XX;		opImm=32'hXXXXXXXX;
				end

			endcase
		end

		UXFORM_ARI_NST: begin
			opRegN=opRegN_Dfl;	opRegS=opRegN_Dfl;	opRegT=opRegM_Dfl;
		end

		UXFORM_CMP_ST: begin
			opRegS=opRegN_Dfl;	opRegT=opRegM_Dfl;
		end

		UXFORM_ARI_ST: begin
			opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
		end

		UXFORM_ARI_NNI: begin
			opRegN=opRegN_Dfl;	opRegS=opRegN_Dfl;
			opRegT=UREG_MR_IMM;	opImm=opImm_Sx8;
		end
		
		UXFORM_BR_D8: begin
			opImm = opImm_Sx8;
		end
		UXFORM_BR_D12: begin
			opImm = opImm_Sx12;
		end

		UXFORM_ARI_I8R0: begin
			opRegN=UREG_R0;		opRegS=UREG_R0;
			opRegT=UREG_MR_IMM;	opImm=opImm_Zx8;
		end

		UXFORM_N_C: begin
			opRegN=opRegN_Dfl;	opRegS=opRegN_Dfl;
			opRegT=UREG_MR_IMM;
		end
		
		UXFORM_MOV_GD8R0: begin
			case(tOpDecXfrmZx)
				UXFORMZX_RM: begin
					opRegN=UREG_GBR;	opRegS=UREG_R0;
					opRegT=UREG_MR_IMM;	opImm=opImm_Zx8;
				end
				UXFORMZX_MR: begin
					opRegN=UREG_R0;		opRegS=UREG_GBR;
					opRegT=UREG_MR_IMM;	opImm=opImm_Zx8;
				end

				default: begin
					opRegN=UREG_XX;		opRegS=UREG_XX;
					opRegT=UREG_XX;		opImm=32'hXXXXXXXX;
				end
			endcase
		end

		UXFORM_MOV_SP4RN: begin
			case(tOpDecXfrmZx)
				UXFORMZX_RM: begin
					opRegN=UREG_R15;	opRegS=opRegM_Dfl;
					opRegT=UREG_MR_IMM;	opImm=opImm_Zx4;
				end
				UXFORMZX_MR: begin
					opRegN=opRegM_Dfl;	opRegS=UREG_R15;
					opRegT=UREG_MR_IMM;	opImm=opImm_Zx4;
				end

				UXFORMZX_RM3: begin
					opRegN=UREG_R15;	opRegS=opRegN_N3;
					opRegT=UREG_MR_IMM;
					opImm[3:0]=opCmdWord[3:0];
					opImm[31:4]=1;					
				end
				UXFORMZX_MR3: begin
					opRegN=opRegN_N3;	opRegS=UREG_R15;
					opRegT=UREG_MR_IMM;
					opImm[3:0]=opCmdWord[3:0];
					opImm[31:4]=1;					
				end

				UXFORMZX_FM3: begin
					opRegN=UREG_R15;
					opRegS={3'h4, 1'b1, opCmdWord[6:4]};
					opRegT=UREG_MR_IMM;	opImm=opImm_Zx4;
				end
				UXFORMZX_MF3: begin
					opRegN={3'h4, 1'b1, opCmdWord[6:4]};
					opRegS=UREG_R15;
					opRegT=UREG_MR_IMM;	opImm=opImm_Zx4;
				end

				UXFORMZX_RM0: begin
					opRegN=opRegM_Dfl;	opRegS=UREG_R0;
					opRegT=UREG_MR_IMM;	opImm=opImm_Zx4;
				end
				UXFORMZX_MR0: begin
					opRegN=UREG_R0;		opRegS=opRegM_Dfl;
					opRegT=UREG_MR_IMM;	opImm=opImm_Zx4;
				end

				default: begin
					opRegN=UREG_XX;		opRegS=UREG_XX;
					opRegT=UREG_XX;		opImm=32'hXXXXXXXX;
				end
			endcase
		end

		UXFORM_INVALID: begin
			opRegN=UREG_XX;		opRegS=UREG_XX;
			opRegT=UREG_XX;		opImm=32'hXXXXXXXX;
		end

		default: begin
			opRegN=UREG_XX;		opRegS=UREG_XX;
			opRegT=UREG_XX;		opImm=32'hXXXXXXXX;
		end
	endcase
// */



/*
	casez({tOpDecXfrm, tOpDecXfrmZx})

		{UXFORM_CST, UXFORMZX_X}: begin
		end

		{UXFORM_N, UXFORMZX_X}: begin
			opRegN=opRegN_Dfl;
			opRegS=opRegN;
		end

		{UXFORM_MOV_NS, UXFORMZX_X}: begin
			opRegN=opRegN_Dfl;		opRegS=opRegM_Dfl;
		end

		{UXFORM_MOV_NSO, UXFORMZX_X}: begin
			opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
			opRegT=UREG_R0;		opImm=0;
		end

		{UXFORM_MOV_NSJ, UXFORMZX_X}: begin
			opRegN=opRegN_Dfl;		opRegS=opRegM_Dfl;
			opImm  = opImm_Zx4;
		end

		{UXFORM_MOV_NSDEC, UXFORMZX_PDEC}: begin
			opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
			opRegT=UREG_MR_MEMDEC;
		end

		{UXFORM_MOV_NSDEC, UXFORMZX_PINC}: begin
			opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
			opRegT=UREG_MR_MEMINC;
		end

		{UXFORM_MOV_NSDEC, UXFORMZX_FRD}: begin
			opRegN=opRegN_Dfl;	opRegS=opRegM_FR;
			opRegT=UREG_MR_MEMDEC;
		end
		{UXFORM_MOV_NSDEC, UXFORMZX_RFI}: begin
			opRegN=opRegN_FR;	opRegS=opRegM_Dfl;
			opRegT=UREG_MR_MEMINC;
		end
				
		{UXFORM_MOVC_NSDEC, UXFORMZX_RS}: begin
			opRegN=opRegM_SR;	opRegS=opRegN_Dfl;
			opRegT=UREG_MR_MEMINC;
		end
		{UXFORM_MOVC_NSDEC, UXFORMZX_RC}: begin
			opRegN=opRegM_CR;	opRegS=opRegN_Dfl;
			opRegT=UREG_MR_MEMINC;
		end

		{UXFORM_MOVC_NSDEC, UXFORMZX_SR}: begin
			opRegN=opRegN_Dfl;	opRegS=opRegM_SR;
			opRegT=UREG_MR_MEMDEC;
		end
		{UXFORM_MOVC_NSDEC, UXFORMZX_CR}: begin
			opRegN=opRegN_Dfl;	opRegS=opRegM_CR;
			opRegT=UREG_MR_MEMDEC;
		end

		{UXFORM_FPARI_NS, UXFORMZX_X}: begin
			opRegN=opRegN_FR;	opRegS=opRegM_FR;
		end

		{UXFORM_ARI_NS, UXFORMZX_RR}: begin
			opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
		end
		
		{UXFORM_ARI_NS, UXFORMZX_FF}: begin
			opRegN=opRegN_FR;	opRegS=opRegM_FR;
		end

		{UXFORM_ARIC_NS, UXFORMZX_RS}: begin
			opRegN=opRegM_SR;	opRegS=opRegN_Dfl;
		end
		{UXFORM_ARIC_NS, UXFORMZX_RC}: begin
			opRegN=opRegM_CR;	opRegS=opRegN_Dfl;
		end

		{UXFORM_ARIC_NS, UXFORMZX_SR}: begin
			opRegN=opRegN_Dfl;	opRegS=opRegM_SR;
		end
		{UXFORM_ARIC_NS, UXFORMZX_CR}: begin
			opRegN=opRegN_Dfl;	opRegS=opRegM_CR;
		end

		{UXFORM_ARI_NST, UXFORMZX_X}: begin
			opRegN=opRegN_Dfl;	opRegS=opRegN_Dfl;	opRegT=opRegM_Dfl;
		end

		{UXFORM_CMP_ST, UXFORMZX_X}: begin
			opRegS=opRegN_Dfl;	opRegT=opRegM_Dfl;
		end

		{UXFORM_ARI_ST, UXFORMZX_X}: begin
			opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
		end

		{UXFORM_ARI_NNI, UXFORMZX_X}: begin
			opRegN=opRegN_Dfl;	opRegS=opRegN_Dfl;
			opRegT=UREG_MR_IMM;	opImm=opImm_Sx8;
		end
		
		{UXFORM_BR_D8, UXFORMZX_X}: begin
			opImm = opImm_Sx8;
		end
		{UXFORM_BR_D12, UXFORMZX_X}: begin
			opImm = opImm_Sx12;
		end

		{UXFORM_ARI_I8R0, UXFORMZX_X}: begin
			opRegN=UREG_R0;		opRegS=UREG_R0;
			opRegT=UREG_MR_IMM;	opImm=opImm_Zx8;
		end

		{UXFORM_N_C, UXFORMZX_X}: begin
			opRegN=opRegN_Dfl;	opRegS=opRegN_Dfl;
			opRegT=UREG_MR_IMM;
		end
		
		{UXFORM_MOV_GD8R0, UXFORMZX_RM}: begin
			opRegN=UREG_GBR;	opRegS=UREG_R0;
			opRegT=UREG_MR_IMM;	opImm=opImm_Zx8;
		end
		{UXFORM_MOV_GD8R0, UXFORMZX_MR}: begin
			opRegN=UREG_R0;		opRegS=UREG_GBR;
			opRegT=UREG_MR_IMM;	opImm=opImm_Zx8;
		end

		{UXFORM_MOV_SP4RN, UXFORMZX_RM}: begin
			opRegN=UREG_R15;	opRegS=opRegM_Dfl;
			opRegT=UREG_MR_IMM;	opImm=opImm_Zx4;
		end
		{UXFORM_MOV_SP4RN, UXFORMZX_MR}: begin
			opRegN=opRegM_Dfl;	opRegS=UREG_R15;
			opRegT=UREG_MR_IMM;	opImm=opImm_Zx4;
		end

		{UXFORM_MOV_SP4RN, UXFORMZX_RM3}: begin
			opRegN=UREG_R15;	opRegS=opRegN_N3;
			opRegT=UREG_MR_IMM;
			opImm[3:0]=opCmdWord[3:0];
			opImm[31:4]=1;					
		end
		{UXFORM_MOV_SP4RN, UXFORMZX_MR3}: begin
			opRegN=opRegN_N3;	opRegS=UREG_R15;
			opRegT=UREG_MR_IMM;
			opImm[3:0]=opCmdWord[3:0];
			opImm[31:4]=1;					
		end

		{UXFORM_MOV_SP4RN, UXFORMZX_FM3}: begin
			opRegN=UREG_R15;
			opRegS={3'h4, 1'b1, opCmdWord[6:4]};
			opRegT=UREG_MR_IMM;	opImm=opImm_Zx4;
		end
		{UXFORM_MOV_SP4RN, UXFORMZX_MF3}: begin
			opRegN={3'h4, 1'b1, opCmdWord[6:4]};
			opRegS=UREG_R15;
			opRegT=UREG_MR_IMM;	opImm=opImm_Zx4;
		end

		{UXFORM_MOV_SP4RN, UXFORMZX_RM0}: begin
			opRegN=opRegM_Dfl;	opRegS=UREG_R0;
			opRegT=UREG_MR_IMM;	opImm=opImm_Zx4;
		end
		{UXFORM_MOV_SP4RN, UXFORMZX_MR0}: begin
			opRegN=UREG_R0;		opRegS=opRegM_Dfl;
			opRegT=UREG_MR_IMM;	opImm=opImm_Zx4;
		end

		{UXFORM_INVALID, UXFORMZX_X}: begin
			opRegN=UREG_XX;		opRegS=UREG_XX;
			opRegT=UREG_XX;		opImm=32'hXXXXXXXX;
		end

		default: begin
			opRegN=UREG_XX;		opRegS=UREG_XX;
			opRegT=UREG_XX;		opImm=32'hXXXXXXXX;
		end
	endcase
*/

//	if(isOpXE)
	if(0)
	begin
		opRegN=opRegXeN;	opRegS=opRegXeS;
		opRegT=opRegXeT;	opImm=opImmXe;
		opUCmd=opUCmdXe;
		opStepPc2=opStepPc2A;
	end
	else
	begin
		opStepPc2=opStepPc2B;

	end

end

endmodule
