/*
Instruction Word
 15: 0, First Word
 31:16, Second Word
 */

`include "CoreDefs.v"

module DecOp3(
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

reg			isOpCC0;	//CC0e_zzzz
reg			isOpCC3;	//CC3e_zzzz
reg[3:0]	opCCe;
reg			opPsDQ;
reg			opPwDQ;
reg			opPlDQ;
reg			opJQ;
// reg		opMovFpr;
reg			opUseBase16;	//op uses basic 16-bit decoder

reg[7:0] opPfxImm;
reg[15:0] opCmdWord;

reg[6:0]		opRegN;
reg[6:0]		opRegS;
reg[6:0]		opRegT;	//Index for mem ops
reg[31:0]		opImm;	//Disp for mem ops
reg[7:0]		opUCmd;
reg[3:0]		opStepPc;
reg[3:0]		opStepPc2;

assign	idRegN = opRegN;
assign	idRegS = opRegS;
assign	idRegT = opRegT;
assign	idImm = opImm;
assign	idUCmd = opUCmd;
assign	idStepPc = opStepPc;
assign	idStepPc2 = opStepPc2;


// reg[6:0]	tOpRegDflN;
// reg[6:0]	tOpRegDflM;

// reg			tOpDflRns;
// reg			tOpDflRnst;

reg[4:0]	tOpDecXfrm;
reg[3:0]	tOpDecXfrmZx;

reg[7:0]	tOpW2;


reg[6:0]	opRegN_Dfl;
reg[6:0]	opRegM_Dfl;
reg[6:0]	opRegO_Dfl;
reg[6:0]	opRegS_8E;
reg[6:0]	opRegT_8E;
reg[6:0]	opRegN_CEf;
reg[6:0]	opRegM_CEf;

reg[6:0]	opRegN_CEe;
reg[6:0]	opRegM_CEe;
reg[6:0]	opRegO_CEe;
reg[6:0]	opRegT_CEe;

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
reg[31:0]	opImm_Zx4_8E;
reg[31:0]	opImm_Zx8;
reg[31:0]	opImm_Sx8;
reg[31:0]	opImm_Sx12;
reg[31:0]	opImm_Sx8E;
reg[31:0]	opImm_Zx8E;
reg[31:0]	opImm_Nx8E;
reg[31:0]	opImm_Sx16_8E;
reg[31:0]	opImm_Sx20_8E;
reg[31:0]	opImmM_Sx12_8E;
reg[31:0]	opImmO_Sx12_8E;

reg[31:0]	opImm6_SxCE;
reg[31:0]	opImm6_ZxCE;
reg[31:0]	opImm6_NxCE;

reg			opIsRegN_FR;
reg			opIsRegM_FR;
reg			opIsRegS_FR;
reg			opIsRegT_FR;

reg			opIsRegM_CR;
reg			opIsRegM_SR;


always @*
begin

	opStepPc = 2;
	
//	opPfxImm=0;
//	opCmdWord=0;

	opPfxImm=8'hXX;
	opCmdWord=0;

//	opRegN=0;
//	opRegS=0;
//	opRegT=0;
	opUCmd=UCMD_UDBRK;
	opImm=0;


	isOp32=0;
	isOp8E=0;	isOpCE=0;	isOpXE=0;
	isOpCC0=0;	isOpCC3=0;	opCCe=0;
//	opMovFpr=0;
	opUseBase16=1;


	opRegN=UREG_ZZR;
	opRegS=UREG_ZZR;
	opRegT=UREG_ZZR;

	opIsRegN_FR=0;	opIsRegM_FR=0;
	opIsRegS_FR=0;	opIsRegT_FR=0;
	opIsRegM_CR=0;	opIsRegM_SR=0;

	tOpDecXfrm=UXFORM_CST;
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
	tOpW2=istrWord[31:24];

	if(decEnableBJX1)
	begin
		case(istrWord[15:8])
			8'h8A: begin
				isOp32=1;
				opCmdWord=istrWord[15:0];
				tOpW2=istrWord[47:40];
				
				opImm[31:24]=istrWord[7]?8'hFF:8'h00;
				opImm[23:16]=istrWord[7:0];
				opImm[15: 0]=istrWord[31:16];

				opRegN=UREG_R0;
				opUCmd=UCMD_MOV_RI;
				tOpDecXfrm=UXFORM_CST;
				opUseBase16=0;
			end

			8'h8E: begin
				isOp32=1;
				isOp8E=1;
				isOpXE=1;
				opPfxImm=istrWord[7:0];
				opCmdWord=istrWord[31:16];
				tOpW2=istrWord[47:40];
			end

			8'hCC: begin
				if(decEnable64A && opJQ)
				begin
					isOp32=1;
					isOpCE=0;
					isOpXE=0;
					isOpCC0 = (istrWord[7:4]==4'h0);
					isOpCC3 = (istrWord[7:4]==4'h3);
					opCCe=istrWord[3:0];
					opPsDQ=istrWord[3];
					opPwDQ=0;
					opPlDQ=opPsDQ;
					opPfxImm=0;
					opCmdWord=istrWord[31:16];
					tOpW2=istrWord[47:40];
				end
			end

			8'hCE: begin
				if(decEnable64A && opJQ)
				begin
					isOp32=1;
					isOpCE=1;
					isOpXE=1;
					opPfxImm=istrWord[7:0];
					opCmdWord=istrWord[31:16];
					tOpW2=istrWord[47:40];
					opPsDQ=istrWord[7];
					opPwDQ=0;
					opPlDQ=0;
				end
			end

			default: begin
			end
		endcase

		if(isOp32)
			opStepPc = 4;
	end

	opStepPc2 = 2;
	if(decEnableBJX1)
	begin
		case(tOpW2)
			8'h8A:		opStepPc2 = 4;
			8'h8C:		opStepPc2 = 4;
			8'h8E:		opStepPc2 = 4;

			8'hCC:		opStepPc2 = (opJQ && decEnable64A) ? 4 : 2;
			8'hCE:		opStepPc2 = (opJQ && decEnable64A) ? 4 : 2;

			default:	opStepPc2 = 2;
		endcase
	end

	if(decEnable64A)
	begin
		if(isOpCC3)		/* BJX1-64A */
		begin
			opUseBase16=0;
			casez(opCmdWord[15:12])
				4'h0: opUCmd=UCMD_ALU_ADD;
				4'h1: opUCmd=UCMD_ALU_SUB;
				4'h2: opUCmd=UCMD_ALU_MUL;
				4'h3: opUCmd=UCMD_ALU_AND;
				4'h4: opUCmd=UCMD_ALU_OR;
				4'h5: opUCmd=UCMD_ALU_XOR;

				4'h6: opUCmd=opCCe[3] ? UCMD_ALU_SHLDQ  : UCMD_ALU_SHLD;
				4'h7: opUCmd=opCCe[3] ? UCMD_ALU_SHLDRQ : UCMD_ALU_SHLDR;
				4'h8: opUCmd=opCCe[3] ? UCMD_ALU_SHADQ  : UCMD_ALU_SHAD;
				4'h9: opUCmd=opCCe[3] ? UCMD_ALU_SHADRQ : UCMD_ALU_SHADR;

				4'hC: opUCmd=UCMD_FPU_ADD;
				4'hD: opUCmd=UCMD_FPU_SUB;
				4'hE: opUCmd=UCMD_FPU_MUL;
				
				default: begin end
			endcase

			if(opCmdWord[15:14]==2'h3)
			begin
				opRegN={2'h2, opCCe[2], opCmdWord[11:8]};
				opRegS={2'h2, opCCe[1], opCmdWord[ 7:4]};
				opRegT={2'h2, opCCe[0], opCmdWord[ 3:0]};
			end
			else
			begin
				opRegN={2'h0, opCCe[2], opCmdWord[11:8]};
				opRegS={2'h0, opCCe[1], opCmdWord[ 7:4]};
				opRegT={2'h0, opCCe[0], opCmdWord[ 3:0]};
			end
			tOpDecXfrm=UXFORM_CST;
		end
	end

	if(opUseBase16)
		casez(opCmdWord[15:0])

		16'h0zz0: begin
			/* Unimplemented, 2A */
		end

		16'h0zz1: begin
			/* Unimplemented, 2A */
		end
			
		16'h0zz2: begin		//0xx2, STC
			opUCmd=UCMD_MOV_RR;		tOpDecXfrm=UXFORM_ARI_NS;
			tOpDecXfrmZx=UXFORMZX_CR;
		end

		16'h0zz4: begin		//0xx4
			opUCmd=UCMD_MOVB_RM;	tOpDecXfrm=UXFORM_MOV_NSO;
		end

		16'h0zz5: begin		//0xx5
			opUCmd = opPwDQ ? UCMD_MOVQ_RM : UCMD_MOVW_RM;
			tOpDecXfrm=UXFORM_MOV_NSO;
		end

		16'h0zz6: begin		//0xx6
			opUCmd = opPlDQ ? UCMD_MOVQ_RM : UCMD_MOVL_RM;
			tOpDecXfrm=UXFORM_MOV_NSO;
		end

		16'h0zz7: begin		//0xx7
			if(isOpXE)
			begin
				opUCmd=UCMD_MOVQ_RM;	tOpDecXfrm=UXFORM_MOV_NSO;
			end
			else
			begin
				opUCmd=UCMD_ALU_DMULS;	tOpDecXfrm=UXFORM_ARI_ST;
			end
		end

		/* 0xx8 */
			16'h0z08: begin		//0x08
				opUCmd=UCMD_ALU_SPOP;
				opImm[7:0]=UCMDP_ALU_CLRT;
				tOpDecXfrm=UXFORM_CST;
			end
			16'h0z18: begin		//0x18
				opUCmd=UCMD_ALU_SPOP;
				opImm[7:0]=UCMDP_ALU_SETT;
				tOpDecXfrm=UXFORM_CST;
			end
			16'h0z28: begin		//0x28
				opUCmd=UCMD_ALU_SPOP;
				opImm[7:0]=UCMDP_ALU_CLRMAC;
				tOpDecXfrm=UXFORM_CST;
			end
			16'h0z38: begin		//0x38
				opUCmd=UCMD_ALU_SPOP;
				opImm[7:0]=UCMDP_ALU_LDTLB;
				tOpDecXfrm=UXFORM_CST;
			end
			16'h0z48: begin		//0x48
				opUCmd=UCMD_ALU_SPOP;
				opImm[7:0]=UCMDP_ALU_CLRS;
				tOpDecXfrm=UXFORM_CST;
			end
			16'h0z58: begin		//0x58
				opUCmd=UCMD_ALU_SPOP;
				opImm[7:0]=UCMDP_ALU_SETS;
				tOpDecXfrm=UXFORM_CST;
			end
			16'h0z68: begin		//0x68
				opUCmd=UCMD_ALU_SPOP;
				opImm[7:0]=UCMDP_ALU_NOTT;
				tOpDecXfrm=UXFORM_CST;
			end

		/* 0xx9 */
			16'h0z09: begin		//0x09
				opUCmd=UCMD_NONE;		tOpDecXfrm=UXFORM_Z;
			end
			16'h0z19: begin		//0x19
				opUCmd=UCMD_ALU_SPOP;
				opImm[7:0]=UCMDP_ALU_DIV0U;
				tOpDecXfrm=UXFORM_CST;
			end
			16'h0z29: begin		//0x29
				opUCmd=UCMD_ALU_MOVT;	tOpDecXfrm=UXFORM_N;
			end
			16'h0z39: begin		//0x39
				opUCmd=UCMD_ALU_MOVRT;	tOpDecXfrm=UXFORM_N;
			end

		16'h0zzA: begin		//0xxA
			opUCmd=UCMD_MOV_RR;		tOpDecXfrm=UXFORM_ARI_NS;
			tOpDecXfrmZx=UXFORMZX_SR;
		end

		/* 0xxB */
			16'h0z0B: begin		//0z0B
				opUCmd=UCMD_RTS;		tOpDecXfrm=UXFORM_Z;
			end

			16'h0z1B: begin		//0x1B
				opUCmd=UCMD_ALU_SPOP;
				opImm[7:0]=UCMDP_ALU_SLEEP;
				tOpDecXfrm=UXFORM_CST;
			end

			16'h0z2B: begin		//0z2B
				opUCmd=UCMD_RTE;		tOpDecXfrm=UXFORM_Z;
			end

			16'h0z3B: begin		//0z3B
				opUCmd=UCMD_UDBRK;		tOpDecXfrm=UXFORM_Z;
				opImm=1;
				if(opCmdWord[11:8]==4'hF)
				begin
					opUCmd=UCMD_NONE;
					opStepPc=0;
				end
			end

			16'h0z6B: begin		//0z6B
				opUCmd=UCMD_RTSN;		tOpDecXfrm=UXFORM_Z;
			end

		16'h0zzC: begin		//0xxC
			opUCmd=UCMD_MOVB_MR;	tOpDecXfrm=UXFORM_MOV_NSO;
		end

		16'h0zzD: begin		//0xxD
			opUCmd = opPwDQ ? UCMD_MOVQ_MR : UCMD_MOVW_MR;
			tOpDecXfrm=UXFORM_MOV_NSO;
		end

		16'h0zzE: begin		//0xxE
			opUCmd = opPlDQ ? UCMD_MOVQ_MR : UCMD_MOVL_MR;
			tOpDecXfrm=UXFORM_MOV_NSO;
		end

		16'h0zzF: begin		//0xxF
			//MAC.L
		end

		16'h1zzz: begin		//1nmd, MOV.L Rm, @(Rn, disp4)
			opUCmd =  opPlDQ ? UCMD_MOVQ_RM : UCMD_MOVL_RM;
			tOpDecXfrm=UXFORM_MOV_NSJ;
		end

		16'h2zz0: begin		//2xx0, MOV.B Rm, @Rn
			opUCmd=UCMD_MOVB_RM;	tOpDecXfrm=UXFORM_MOV_NS;
		end
		16'h2zz1: begin		//2xx1, MOV.W Rm, @Rn
			opUCmd = opPwDQ ? UCMD_MOVQ_RM : UCMD_MOVW_RM;
			tOpDecXfrm=UXFORM_MOV_NS;
		end
		16'h2zz2: begin		//2xx2, MOV.L Rm, @Rn
			opUCmd = opPlDQ ? UCMD_MOVQ_RM : UCMD_MOVL_RM;
			tOpDecXfrm=UXFORM_MOV_NS;
		end
		16'h2zz3: begin		//2xx3, CAS.L Rm, Rn, @R0
			opUCmd=UCMD_CASL;		tOpDecXfrm=UXFORM_MOV_NSO;
		end
		16'h2zz4: begin		//2xx4, MOV.B @Rm, Rn
			opUCmd=UCMD_MOVB_RM;	tOpDecXfrm=UXFORM_MOV_NSDEC;
			tOpDecXfrmZx=UXFORMZX_PDEC;
		end
		16'h2zz5: begin		//2xx5, MOV.W @Rm, Rn
			opUCmd = opPwDQ ? UCMD_MOVQ_RM : UCMD_MOVW_RM;
			tOpDecXfrm=UXFORM_MOV_NSDEC;
			tOpDecXfrmZx=UXFORMZX_PDEC;
		end
		16'h2zz6: begin		//2xx6, MOV.L @Rm, Rn
			opUCmd = opPlDQ ? UCMD_MOVQ_RM : UCMD_MOVL_RM;
			tOpDecXfrm=UXFORM_MOV_NSDEC;
			tOpDecXfrmZx=UXFORMZX_PDEC;
		end
		16'h2zz7: begin		//2xx7, DIV0S Rm, Rn
			opUCmd=UCMD_ALU_DIV0S;	tOpDecXfrm=UXFORM_ARI_ST;
		end
		16'h2zz8: begin		//2xx8, TST Rm, Rn
			opUCmd=UCMD_CMP_TST;	tOpDecXfrm=UXFORM_CMP_ST;
			tOpDecXfrmZx=UXFORMZX_ZX;
		end
		16'h2zz9: begin		//2xx9, AND Rm, Rn
			opUCmd=UCMD_ALU_AND;	tOpDecXfrm=UXFORM_ARI_NST;
			tOpDecXfrmZx=UXFORMZX_ZX;
		end
		16'h2zzA: begin		//2xxA, XOR Rm, Rn
			opUCmd=UCMD_ALU_XOR;	tOpDecXfrm=UXFORM_ARI_NST;
			tOpDecXfrmZx=UXFORMZX_ZX;
		end
		16'h2zzB: begin		//2xxB, OR Rm, Rn
			opUCmd=UCMD_ALU_OR;		tOpDecXfrm=UXFORM_ARI_NST;
			tOpDecXfrmZx=UXFORMZX_ZX;
		end
		16'h2zzC: begin		//2xxC, CMPSTR Rm, Rn
			opUCmd=UCMD_ALU_CMPSTR;	tOpDecXfrm=UXFORM_ARI_NST;
		end
		16'h2zzD: begin		//2xxD, XTRCT Rm, Rn
			opUCmd=UCMD_ALU_XTRCT;	tOpDecXfrm=UXFORM_ARI_NST;
		end
		16'h2zzE: begin		//2xxE, MULU.W Rm, Rn
			opUCmd=UCMD_ALU_MULUW;	tOpDecXfrm=UXFORM_ARI_ST;
		end
		16'h2zzF: begin		//2xxF, MULS.W Rm, Rn
			opUCmd=UCMD_ALU_MULSW;	tOpDecXfrm=UXFORM_ARI_ST;
		end

		16'h3zz0: begin		//3xx0, CMP/EQ Rm, Rn
			opUCmd=opPsDQ ? UCMD_CMPQ_EQ : UCMD_CMP_EQ;
			tOpDecXfrm=UXFORM_CMP_ST;
		end
		16'h3zz1: begin		//3xx1
		end
		16'h3zz2: begin		//3xx2, CMP/HS Rm, Rn
			opUCmd=opPsDQ ? UCMD_CMPQ_HS : UCMD_CMP_HS;
			tOpDecXfrm=UXFORM_CMP_ST;
		end
		16'h3zz3: begin		//3xx3, CMP/GE Rm, Rn
			opUCmd=opPsDQ ? UCMD_CMPQ_GE : UCMD_CMP_GE;
			tOpDecXfrm=UXFORM_CMP_ST;
		end
		16'h3zz4: begin		//3xx4, DIV1 Rm, Rn
			opUCmd=UCMD_ALU_DIV1;		tOpDecXfrm=UXFORM_ARI_NST;
		end
		16'h3zz5: begin		//3xx5, DMULU.L Rm, Rn
			opUCmd=UCMD_ALU_DMULU;	tOpDecXfrm=UXFORM_ARI_ST;
		end
		16'h3zz6: begin		//3xx6, CMP/HI Rm, Rn
			opUCmd=opPsDQ ? UCMD_CMPQ_HI : UCMD_CMP_HI;
			tOpDecXfrm=UXFORM_CMP_ST;
		end
		16'h3zz7: begin		//3xx7, CMP/GT Rm, Rn
			opUCmd=opPsDQ ? UCMD_CMPQ_GT : UCMD_CMP_GT;
			tOpDecXfrm=UXFORM_CMP_ST;
		end
		16'h3zz8: begin		//3xx8, SUB Rm, Rn
			opUCmd=UCMD_ALU_SUB;	tOpDecXfrm=UXFORM_ARI_NST;
			tOpDecXfrmZx=UXFORMZX_ZX;
		end
		16'h3zz9: begin		//3xx9
		end
		16'h3zzA: begin		//3xxA, SUBC Rm, Rn
			opUCmd=UCMD_ALU_SUBC;	tOpDecXfrm=UXFORM_ARI_NST;
			tOpDecXfrmZx=UXFORMZX_ZX;
		end
		16'h3zzB: begin		//3xxB, SUBV Rm, Rn
			opUCmd=UCMD_ALU_SUBV;	tOpDecXfrm=UXFORM_ARI_NST;
			tOpDecXfrmZx=UXFORMZX_ZX;
		end
		16'h3zzC: begin		//3xxC, ADD Rm, Rn
			opUCmd=UCMD_ALU_ADD;	tOpDecXfrm=UXFORM_ARI_NST;
			tOpDecXfrmZx=UXFORMZX_ZX;
		end
		16'h3zzD: begin		//3xxD, DMULS.L Rm, Rn
			opUCmd=UCMD_ALU_DMULS;	tOpDecXfrm=UXFORM_ARI_ST;
		end
		16'h3zzE: begin		//3xxE, ADDC Rm, Rn
			opUCmd=UCMD_ALU_ADDC;	tOpDecXfrm=UXFORM_ARI_NST;
		end
		16'h3zzF: begin		//3xxF, ADDV Rm, Rn
			opUCmd=UCMD_ALU_ADDV;	tOpDecXfrm=UXFORM_ARI_NST;
		end

		/* 4xx0 */
			16'h4z00: begin		//4x00
				opUCmd=UCMD_ALU_SHLL;	tOpDecXfrm=UXFORM_N;
			end
			16'h4z10: begin		//4x10
				opUCmd=UCMD_ALU_DT;		tOpDecXfrm=UXFORM_N;
			end
			16'h4z20: begin		//4x20
				opUCmd=UCMD_ALU_SHAL;	tOpDecXfrm=UXFORM_N;
			end

		/* 4xx1 */
			16'h4z01: begin		//4x01
				opUCmd=UCMD_ALU_SHLR;	tOpDecXfrm=UXFORM_N;
			end
			16'h4z11: begin		//4x11
				opUCmd=opPsDQ ? UCMD_CMPQ_GE : UCMD_CMP_GE;
				tOpDecXfrm=UXFORM_M;
			end
			16'h4z21: begin		//4x21
				opUCmd=UCMD_ALU_SHAR;	tOpDecXfrm=UXFORM_N;
			end

		16'h4zz2: begin		//4xx2
			opUCmd = opJQ ? UCMD_MOVQ_RM : UCMD_MOVL_RM;
			tOpDecXfrm=UXFORM_MOV_NSDEC;
			tOpDecXfrmZx=UXFORMZX_SR;
		end
		16'h4zz3: begin		//4xx3
			if(isOpXE)	begin
				case(opCmdWord[7:4])
				4'h0: begin
					opUCmd=UCMD_ALU_ADD;	tOpDecXfrm=UXFORM_NST_8E;
				end
				4'h1: begin
					opUCmd=UCMD_ALU_SUB;	tOpDecXfrm=UXFORM_NST_8E;
				end
				4'h2: begin
					opUCmd=UCMD_ALU_MUL;	tOpDecXfrm=UXFORM_NST_8E;
				end
				4'h3: begin
					opUCmd=UCMD_ALU_AND;	tOpDecXfrm=UXFORM_NST_8E;
				end
				4'h4: begin
					opUCmd=UCMD_ALU_OR;		tOpDecXfrm=UXFORM_NST_8E;
				end
				4'h5: begin
					opUCmd=UCMD_ALU_XOR;	tOpDecXfrm=UXFORM_NST_8E;
				end
				4'h6: begin
					opUCmd=UCMD_ALU_SHLD;	tOpDecXfrm=UXFORM_NST_8E;
				end
				4'h7: begin
					opUCmd=UCMD_ALU_SHLDR;	tOpDecXfrm=UXFORM_NST_8E;
				end
				4'h8: begin
					opUCmd=UCMD_ALU_SHAD;	tOpDecXfrm=UXFORM_NST_8E;
				end
				4'h9: begin
					opUCmd=UCMD_ALU_SHADR;	tOpDecXfrm=UXFORM_NST_8E;
				end

				4'hC: begin
					opUCmd=UCMD_FPU_ADD;	tOpDecXfrm=UXFORM_NST_8E;
//					opIsRegN_FR=1;	opIsRegS_FR=1;	opIsRegT_FR=1;
					tOpDecXfrmZx=UXFORMZX_FF;
				end
				4'hD: begin
					opUCmd=UCMD_FPU_SUB;	tOpDecXfrm=UXFORM_NST_8E;
//					opIsRegN_FR=1;	opIsRegS_FR=1;	opIsRegT_FR=1;
					tOpDecXfrmZx=UXFORMZX_FF;
				end
				4'hE: begin
					opUCmd=UCMD_FPU_MUL;	tOpDecXfrm=UXFORM_NST_8E;
//					opIsRegN_FR=1;	opIsRegS_FR=1;	opIsRegT_FR=1;
					tOpDecXfrmZx=UXFORMZX_FF;
				end

				default: begin end

				endcase
			end
			else
			begin
				opUCmd = opJQ ? UCMD_MOVQ_RM : UCMD_MOVL_RM;
				tOpDecXfrm=UXFORM_MOV_NSDEC;
				tOpDecXfrmZx=UXFORMZX_CR;
			end
		end

		/* 4xx4 */
			16'h4z04: begin		//4x00
				opUCmd=UCMD_ALU_ROTL;	tOpDecXfrm=UXFORM_N;
			end
			16'h4z14: begin		//4x10
//				opUCmd=UCMD_ALU_DT;		tOpDecXfrm=UXFORM_N;
			end
			16'h4z24: begin		//4x20
				opUCmd=UCMD_ALU_ROTCL;	tOpDecXfrm=UXFORM_N;
			end

		/* 4xx5 */
			16'h4z05: begin		//4x01
				opUCmd=UCMD_ALU_ROTR;	tOpDecXfrm=UXFORM_N;
			end
			16'h4z15: begin		//4x11
				opUCmd=opPsDQ ? UCMD_CMPQ_GT : UCMD_CMP_GT;
				tOpDecXfrm=UXFORM_M;
			end
			16'h4z25: begin		//4x21
				opUCmd=UCMD_ALU_ROTCR;	tOpDecXfrm=UXFORM_N;
			end

		16'h4zz6: begin		//4xx6
			opUCmd = opJQ ? UCMD_MOVQ_MR : UCMD_MOVL_MR;
			tOpDecXfrm=UXFORM_MOV_NSDEC;
			tOpDecXfrmZx=UXFORMZX_RS;
		end
		16'h4zz7: begin		//4xx7
			opUCmd = opJQ ? UCMD_MOVQ_RM : UCMD_MOVL_MR;
			tOpDecXfrm=UXFORM_MOV_NSDEC;
			tOpDecXfrmZx=UXFORMZX_RC;
		end

		/* 4xx8 */
			16'h4z08: begin		//4x08
				opUCmd=UCMD_ALU_SHLD;	tOpDecXfrm=UXFORM_N_C;
				opImm=2;
			end
			16'h4z18: begin		//4x18
				opUCmd=UCMD_ALU_SHLD;	tOpDecXfrm=UXFORM_N_C;
				opImm=8;
			end
			16'h4z28: begin		//4x28
				opUCmd=UCMD_ALU_SHLD;	tOpDecXfrm=UXFORM_N_C;
				opImm=16;
			end

		/* 4xx9 */
			16'h4z09: begin		//4x09
				opUCmd=UCMD_ALU_SHLD;	tOpDecXfrm=UXFORM_N_C;
				opImm=-2;
			end
			16'h4z19: begin		//4x19
				opUCmd=UCMD_ALU_SHLD;	tOpDecXfrm=UXFORM_N_C;
				opImm=-8;
			end
			16'h4z29: begin		//4x29
				opUCmd=UCMD_ALU_SHLD;	tOpDecXfrm=UXFORM_N_C;
				opImm=-16;
			end

		16'h4zzA: begin		//4xxA, LDS
			opUCmd=UCMD_MOV_RR;		tOpDecXfrm=UXFORM_ARI_NS;
			tOpDecXfrmZx=UXFORMZX_RS;
		end

		/* 4xxB */
			16'h4z0B: begin
				opUCmd=UCMD_JSR;	tOpDecXfrm=UXFORM_M;
			end

			16'h4z2B: begin
				opUCmd=UCMD_JMP;	tOpDecXfrm=UXFORM_M;
			end
			16'h4z3B: begin
			end
			16'h4z4B: begin
				opUCmd=UCMD_JSRN;	tOpDecXfrm=UXFORM_M;
			end

		16'h4zzC: begin		//4xxC
			opUCmd=opPsDQ ? UCMD_ALU_SHADQ : UCMD_ALU_SHAD;
			tOpDecXfrm=UXFORM_ARI_NST;
			tOpDecXfrmZx=UXFORMZX_SX;
		end
		16'h4zzD: begin		//4xxD
			opUCmd=opPsDQ ? UCMD_ALU_SHLDQ : UCMD_ALU_SHLD;
			tOpDecXfrm=UXFORM_ARI_NST;
			tOpDecXfrmZx=UXFORMZX_SX;
		end
		16'h4zzE: begin		//4xxE, LDC
			if(isOpXE)	begin
				case(opCmdWord[7:4])
				4'h0: begin
					opUCmd=UCMD_MOVUB_MR;	tOpDecXfrm=UXFORM_NST_8E;
				end
				4'h1: begin
					opUCmd=UCMD_MOVUW_MR;	tOpDecXfrm=UXFORM_NST_8E;
				end

				default: begin end
				endcase
			end
			else
			begin
				opUCmd=UCMD_MOV_RR;		tOpDecXfrm=UXFORM_ARI_NS;
				tOpDecXfrmZx=UXFORMZX_RC;
			end
		end

		16'h5zzz: begin		//5xxx
			opUCmd = opPlDQ ? UCMD_MOVQ_MR : UCMD_MOVL_MR;
			tOpDecXfrm=UXFORM_MOV_NSJ;
		end

		16'h6zz0: begin		//6xx0
			opUCmd=UCMD_MOVB_MR;	tOpDecXfrm=UXFORM_MOV_NS;
		end
		16'h6zz1: begin		//6xx1
			opUCmd = opPwDQ ? UCMD_MOVQ_MR : UCMD_MOVW_MR;
			tOpDecXfrm=UXFORM_MOV_NS;
		end
		16'h6zz2: begin		//6xx2
			opUCmd = opPlDQ ? UCMD_MOVQ_MR : UCMD_MOVL_MR;
			tOpDecXfrm=UXFORM_MOV_NS;
		end
		16'h6zz3: begin		//6xx3
			if(isOpXE)	begin
				opUCmd=UCMD_MOVQ_MR;	tOpDecXfrm=UXFORM_MOV_NS;
			end else begin
				opUCmd=UCMD_MOV_RR;		tOpDecXfrm=UXFORM_ARI_NS;
			end
		end
		16'h6zz4: begin		//6xx4
			if(isOpXE) begin
				opUCmd=UCMD_LEAB_MR;	tOpDecXfrm=UXFORM_MOV_NSO;
			end else begin
				opUCmd=UCMD_MOVB_MR;	tOpDecXfrm=UXFORM_MOV_NSDEC;
				tOpDecXfrmZx=UXFORMZX_PINC;
			end
		end
		16'h6zz5: begin		//6xx5
			if(isOpXE)	begin
				opUCmd=UCMD_LEAW_MR;	tOpDecXfrm=UXFORM_MOV_NSO;
			end else begin
				opUCmd = opPwDQ ? UCMD_MOVQ_MR : UCMD_MOVW_MR;
				tOpDecXfrm=UXFORM_MOV_NSDEC;
				tOpDecXfrmZx=UXFORMZX_PINC;
			end
		end
		16'h6zz6: begin		//6xx6
			if(isOpXE)	begin
				opUCmd=UCMD_LEAL_MR;	tOpDecXfrm=UXFORM_MOV_NSO;
			end else begin
				opUCmd =  opPlDQ ? UCMD_MOVQ_MR : UCMD_MOVL_MR;
				tOpDecXfrm=UXFORM_MOV_NSDEC;
				tOpDecXfrmZx=UXFORMZX_PINC;
			end
		end
		16'h6zz7: begin
			if(isOpXE)	begin
				opUCmd=UCMD_LEAQ_MR;	tOpDecXfrm=UXFORM_MOV_NSO;
			end else begin
				opUCmd=UCMD_ALU_NOT;	tOpDecXfrm=UXFORM_ARI_NS;
			end
		end
		16'h6zz8: begin
			if(isOpXE)	begin
				opUCmd=UCMD_LEAB_MR;	tOpDecXfrm=UXFORM_MOV_NS;
			end	else begin
				opUCmd=UCMD_ALU_SWAPB;	tOpDecXfrm=UXFORM_ARI_NS;
			end
		end
		16'h6zz9: begin
			if(isOpXE)	begin
				opUCmd=UCMD_LEAW_MR;	tOpDecXfrm=UXFORM_MOV_NS;
			end	else begin
				opUCmd=UCMD_ALU_SWAPW;	tOpDecXfrm=UXFORM_ARI_NS;
			end
		end
		16'h6zzA: begin
			if(isOpXE)	begin
				opUCmd=UCMD_LEAL_MR;	tOpDecXfrm=UXFORM_MOV_NS;
			end	else begin
				opUCmd=UCMD_ALU_NEGC;	tOpDecXfrm=UXFORM_ARI_NS;
			end
		end
		16'h6zzB: begin
			if(isOpXE)	begin
				opUCmd=UCMD_LEAQ_MR;	tOpDecXfrm=UXFORM_MOV_NS;
			end	else begin
				opUCmd=UCMD_ALU_NEG;	tOpDecXfrm=UXFORM_ARI_NS;
			end
		end
		16'h6zzC: begin
			if(isOpXE)	begin
				opUCmd=UCMD_MOVUB_MR;	tOpDecXfrm=UXFORM_MOV_NS;
			end else begin
				opUCmd=UCMD_ALU_EXTUB;	tOpDecXfrm=UXFORM_ARI_NS;
			end
		end
		16'h6zzD: begin
			if(isOpXE)	begin
				opUCmd=UCMD_MOVUW_MR;	tOpDecXfrm=UXFORM_MOV_NS;
			end else begin
				opUCmd=UCMD_ALU_EXTUW;	tOpDecXfrm=UXFORM_ARI_NS;
			end
		end
		16'h6zzE: begin
			if(isOpXE)	begin
				opUCmd=UCMD_MOVUL_MR;	tOpDecXfrm=UXFORM_MOV_NS;
			end else begin
				opUCmd=UCMD_ALU_EXTSB;	tOpDecXfrm=UXFORM_ARI_NS;
			end
		end
		16'h6zzF: begin
			if(isOpXE)	begin
				opUCmd=UCMD_MOVQ_MR;	tOpDecXfrm=UXFORM_MOV_NS;
			end else begin
				opUCmd=UCMD_ALU_EXTSW;	tOpDecXfrm=UXFORM_ARI_NS;
			end
		end

		16'h7zzz: begin		//7xxx
			opUCmd=UCMD_ALU_ADD;	tOpDecXfrm=UXFORM_ARI_NNI;
		end

		16'h80zz: begin		//80xx
			opUCmd=UCMD_MOVB_RM;
			tOpDecXfrm=UXFORM_MOV_SP4RN;
			tOpDecXfrmZx=UXFORMZX_RM0;
		end
		16'h81zz: begin		//81xx
			opUCmd=UCMD_MOVW_RM;
			tOpDecXfrm=UXFORM_MOV_SP4RN;
			tOpDecXfrmZx=UXFORMZX_RM0;
		end

		16'h82zz: begin		//82xx
			opUCmd=UCMD_BRAN;		tOpDecXfrm=UXFORM_BR_D8;
		end
		16'h83zz: begin		//83xx
			if(isOpXE)	begin
				opUCmd=UCMD_BSRN;	tOpDecXfrm=UXFORM_BR_D8;
			end else begin
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
		end

		16'h84zz: begin		//84xx
			opUCmd=UCMD_MOVB_MR;
			tOpDecXfrm=UXFORM_MOV_SP4RN;
			tOpDecXfrmZx=UXFORMZX_MR0;
		end
		16'h85zz: begin		//85xx
			opUCmd=UCMD_MOVW_MR;
			tOpDecXfrm=UXFORM_MOV_SP4RN;
			tOpDecXfrmZx=UXFORMZX_MR0;
		end

		16'h86zz: begin		//86xx
			if(isOpXE)	begin
//				opUCmd=UCMD_BSRN;	tOpDecXfrm=UXFORM_BR_D8;
			end else begin
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
		end

		16'h87zz: begin		//87xx
		end

		16'h88zz: begin		//88xx
			opUCmd=UCMD_CMP_EQ;
			tOpDecXfrm=UXFORM_ARI_I8R0;
		end
		16'h89zz: begin		//89xx
			opUCmd=UCMD_BT;		tOpDecXfrm=UXFORM_BR_D8;
		end
		16'h8Azz: begin		//8Axx-xxxx
			if(isOpXE)	begin
	//			opUCmd=UCMD_BSRN;	tOpDecXfrm=UXFORM_BR_D8;
			end else begin
				opRegN=UREG_R0;
				opUCmd=UCMD_MOV_RI;
				tOpDecXfrm=UXFORM_CST;
			end
		end
		16'h8Bzz: begin		//8Bxx, BF disp
			opUCmd=UCMD_BF;		tOpDecXfrm=UXFORM_BR_D8;
		end
		16'h8Czz: begin		//8Cxx
			/* Escape */
		end
		16'h8Dzz: begin		//8Dxx, BTS disp
			opUCmd=UCMD_BTS;		tOpDecXfrm=UXFORM_BR_D8;
		end
		16'h8Ezz: begin		//8Exx
			/* Escape */
		end
		16'h8Fzz: begin		//8Fxx, BFS disp
			opUCmd=UCMD_BFS;		tOpDecXfrm=UXFORM_BR_D8;
		end

		16'h9zzz: begin		//9xxx
			if(isOpXE)
			begin			//LDSH16 #imm, Rn
				opUCmd=UCMD_ALU_LDSH16;
				tOpDecXfrm=UXFORM_ARI_NNI;
			end else begin	//MOV.W @(PC, disp), Rn
				opRegN[3:0]=opCmdWord[11:8];
				opRegS=UREG_PCW;
				opRegT=UREG_ZZR;
				opImm[7:0]=opCmdWord[ 7:0];
				opUCmd=UCMD_MOVW_MR;
				tOpDecXfrm=UXFORM_CST;
			end
		end

		16'hAzzz: begin		//Axxx
			opUCmd=UCMD_BRA;		tOpDecXfrm=UXFORM_BR_D12;
		end

		16'hBzzz: begin		//Bxxx
			opUCmd=UCMD_BSR;		tOpDecXfrm=UXFORM_BR_D12;
		end

		16'hC0zz: begin
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

		16'hC1zz: begin
			if(opJQ)
			begin
			end else begin
				opUCmd=UCMD_MOVW_RM;
				tOpDecXfrm=UXFORM_MOV_GD8R0;
				tOpDecXfrmZx=UXFORMZX_RM;
			end
		end

		16'hC2zz: begin
			if(opJQ)
			begin
			end else begin
				opUCmd=UCMD_MOVL_RM;
				tOpDecXfrm=UXFORM_MOV_GD8R0;
				tOpDecXfrmZx=UXFORMZX_RM;
			end
		end

		16'hC4zz: begin
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

		16'hC5zz: begin
			if(opJQ)
			begin
			end else begin
				opUCmd=UCMD_MOVW_MR;
				tOpDecXfrm=UXFORM_MOV_GD8R0;
				tOpDecXfrmZx=UXFORMZX_MR;
			end
		end

		16'hC6zz: begin
			if(opJQ)
			begin
			end else begin
				opUCmd=UCMD_MOVL_MR;
				tOpDecXfrm=UXFORM_MOV_GD8R0;
				tOpDecXfrmZx=UXFORMZX_MR;
			end
		end

		16'hC8zz: begin		//CMP/EQ #imm, R0
			opUCmd=opPsDQ ? UCMD_CMPQ_TST : UCMD_CMP_TST;
			tOpDecXfrm=UXFORM_CMP_I8R0;
		end
		16'hC9zz: begin		//AND #imm, R0
			opUCmd=UCMD_ALU_AND;	tOpDecXfrm=UXFORM_ARI_I8R0;
		end
		16'hCAzz: begin		//XOR #imm, R0
			opUCmd=UCMD_ALU_XOR;	tOpDecXfrm=UXFORM_ARI_I8R0;
		end
		16'hCBzz: begin		//OR #imm, R0
			opUCmd=UCMD_ALU_OR;		tOpDecXfrm=UXFORM_ARI_I8R0;
		end

		16'hDzzz: begin		//Dxxx, MOV @(PC,disp), Rn
			opRegN[3:0]=opCmdWord[11:8];
			opRegS=UREG_PCL;
			opRegT=UREG_ZZR;
			opImm[7:0]=opCmdWord[ 7:0];
			opUCmd=UCMD_MOVL_MR;
			tOpDecXfrm=UXFORM_CST;
		end

		16'hEzzz: begin		//Exxx, MOV #imm, Rn
			opUCmd=UCMD_MOV_RI;
			tOpDecXfrm=UXFORM_ARI_NNI;
		end

		16'hFzz0: begin
			opUCmd=UCMD_FPU_ADD;
			tOpDecXfrm=UXFORM_FPARI_NS;
//			tOpDecXfrmZx=UXFORMZX_FF;
		end
		16'hFzz1: begin
			opUCmd=UCMD_FPU_SUB;
			tOpDecXfrm=UXFORM_FPARI_NS;
//			tOpDecXfrmZx=UXFORMZX_FF;
		end
		16'hFzz2: begin
			opUCmd=UCMD_FPU_MUL;
			tOpDecXfrm=UXFORM_FPARI_NS;
//			tOpDecXfrmZx=UXFORMZX_FF;
		end

		16'hFzz4: begin
			opUCmd=UCMD_FPU_CMPEQ;
			tOpDecXfrm=UXFORM_FPARI_NS;
//			tOpDecXfrmZx=UXFORMZX_FF;
		end
		16'hFzz5: begin
			opUCmd=UCMD_FPU_CMPGT;
			tOpDecXfrm=UXFORM_FPARI_NS;
//			tOpDecXfrmZx=UXFORMZX_FF;
		end

		16'hFzz6: begin
			opUCmd=UCMD_MOVL_MR;	tOpDecXfrm=UXFORM_MOV_NSO;
			tOpDecXfrmZx=UXFORMZX_RF;
		end
		16'hFzz7: begin
			opUCmd=UCMD_MOVL_RM;	tOpDecXfrm=UXFORM_MOV_NSO;
			tOpDecXfrmZx=UXFORMZX_FR;
		end

		16'hFzz8: begin
			opUCmd=UCMD_MOVL_MR;	tOpDecXfrm=UXFORM_MOV_NS;
//			opIsRegN_FR=1;
			tOpDecXfrmZx=UXFORMZX_RF;
		end
		16'hFzz9: begin
			opUCmd=UCMD_MOVL_MR;	tOpDecXfrm=UXFORM_MOV_NSDEC;
//			opIsRegN_FR=1;
			tOpDecXfrmZx=UXFORMZX_RFI;
		end

		16'hFzzA: begin
			opUCmd=UCMD_MOVL_RM;	tOpDecXfrm=UXFORM_MOV_NS;
//			opIsRegM_FR=1;
			tOpDecXfrmZx=UXFORMZX_FR;
		end
		16'hFzzB: begin
//			opUCmd=UCMD_MOVL_RM;	tOpDecXfrm=UXFORM_MOV_NSDEC;
			opIsRegM_FR=1;
			tOpDecXfrmZx=UXFORMZX_FRD;
		end

		default: begin end

	endcase

//	opIsRegN_FR=0;
//	opIsRegM_FR=0;
//	opIsRegS_FR=0;
//	opIsRegT_FR=0;
//	opIsRegM_CR=0;
//	opIsRegM_SR=0;


	if(decEnable64A)
	begin
/*
		opRegN_Dfl	= {opIsRegN_FR?2'b10:2'b00, opCCe[2],    opCmdWord[11:8]};
		opRegN_CEf	= {opIsRegN_FR?2'b10:2'b00, opPfxImm[7], opCmdWord[11:8]};
		opRegN_CEe	= {opIsRegN_FR?2'b10:2'b00, opPfxImm[6], opCmdWord[11:8]};

		opRegM_Dfl	= {opIsRegM_FR?2'b10:2'b00, opCCe[1],    opCmdWord[ 7:4]};
		opRegM_CEf	= {opIsRegM_FR?2'b10:2'b00, opPfxImm[6], opCmdWord[ 7:4]};
		opRegS_CEe	= {opIsRegM_FR?2'b10:2'b00, opPfxImm[5], opCmdWord[ 7:4]};

		opRegT_CEe	= {opIsRegT_FR?2'b10:2'b00, opPfxImm[4], opPfxImm [ 3:0]};
*/

		opRegN_Dfl	= {2'b00, opCCe[2],    opCmdWord[11:8]};
		opRegN_CEf	= {2'b00, opPfxImm[7], opCmdWord[11:8]};
		opRegN_CEe	= {2'b00, opPfxImm[6], opCmdWord[11:8]};

		opRegM_Dfl	= {2'b00, opCCe[1],    opCmdWord[ 7:4]};
		opRegM_CEf	= {2'b00, opPfxImm[6], opCmdWord[ 7:4]};
		opRegM_CEe	= {2'b00, opPfxImm[5], opCmdWord[ 7:4]};

		opRegO_CEe	= {2'b00, opPfxImm[4], opCmdWord[ 3:0]};

		opRegT_CEe	= {2'b00, opPfxImm[4], opPfxImm [ 3:0]};

		opRegO_Dfl	= {2'b00, opCCe[0],    opCmdWord[ 3:0]};

		opImm6_SxCE	= {opPfxImm[5] ? 26'h3FFFFFF : 26'h0, opPfxImm [ 5:0]};
		opImm6_ZxCE	= {26'h000000, opPfxImm [ 5:0]};
		opImm6_NxCE	= {26'hFFFFFF, opPfxImm [ 5:0]};

	end
	else
	begin
//		opRegN_Dfl	= {opIsRegN_FR?3'b100:3'b000, opCmdWord[11:8]};
//		opRegM_Dfl	= {opIsRegM_FR?3'b100:3'b000, opCmdWord[ 7:4]};

		opRegN_Dfl	= {3'b000, opCmdWord[11:8]};
		opRegM_Dfl	= {3'b000, opCmdWord[ 7:4]};
		opRegO_Dfl	= {3'b000, opCmdWord[ 3:0]};

//		opRegN_CEf	= 7'hXX;
//		opRegM_CEf	= 7'hXX;
		opRegN_CEf	= opRegN_Dfl;
		opRegM_CEf	= opRegM_Dfl;

		opRegN_CEe	= 7'hXX;
		opRegM_CEe	= 7'hXX;
		opRegO_CEe	= 7'hXX;
		opRegT_CEe	= 7'hXX;
	end

/*
	if(opIsRegM_CR)
	begin
		if(opCmdWord[11])	//RmB
			opRegM_Dfl={3'h2, 1'b0, opCmdWord[6:4]};
		else
			opRegM_Dfl={3'h7, opCmdWord[7:4]};
	end else if(opIsRegM_SR)
	begin
		opRegM_Dfl={3'h6, opCmdWord[7:4]};
	end
*/

// /*
	if(opCmdWord[11])	//RmB
		opRegM_CR={3'h2, 1'b0, opCmdWord[6:4]};
	else
		opRegM_CR={3'h7, opCmdWord[7:4]};

	opRegM_SR={3'h6, opCmdWord[7:4]};
// */

	opRegN_FR	= {3'h4, opCmdWord[11:8]};
	opRegM_FR	= {3'h4, opCmdWord[ 7:4]};
	opRegO_FR	= {3'h4, opCmdWord[ 3:0]};

	if(decEnableBJX1)
	begin
//		opRegS_8E		= {opIsRegS_FR?3'b100:3'b000, opPfxImm [ 7:4]};
//		opRegT_8E		= {opIsRegT_FR?3'b100:3'b000, opPfxImm [ 3:0]};
		opRegS_8E		= {3'b000, opPfxImm [ 7:4]};
		opRegT_8E		= {3'b000, opPfxImm [ 3:0]};

		opRegS_FR	= {3'h4, opPfxImm [ 7:4]};
		opRegT_FR	= {3'h4, opPfxImm [ 3:0]};

		opImm_Zx4_8E	= {28'h0, opPfxImm [ 3:0]};

		opImm_Sx8E	= {opPfxImm[7] ? 24'hFFFFFF : 24'h0, opPfxImm [ 7:0]};
		opImm_Zx8E	= {24'h000000, opPfxImm [ 7:0]};
		opImm_Nx8E	= {24'hFFFFFF, opPfxImm [ 7:0]};

		opImmM_Sx12_8E	= {opPfxImm[7] ? 20'hFFFFF : 20'h0,
			opPfxImm [ 7:0], opCmdWord [ 7:4]};
		opImmO_Sx12_8E	= {opPfxImm[7] ? 20'hFFFFF : 20'h0,
			opPfxImm [ 7:0], opCmdWord [ 3:0]};

		opImm_Sx16_8E	= {opPfxImm[7] ? 16'hFFFF : 16'h0000,
			opPfxImm [ 7:0], opCmdWord [ 7:0]};
		opImm_Sx20_8E	= {opPfxImm[7] ? 12'hFFF : 12'h000,
			opPfxImm [ 7:0], opCmdWord [11:0]};

		opRegN_N3 = (opCmdWord[6:4]==3'b111) ? UREG_R0 :
			{3'h0, 1'b1, opCmdWord[6:4]};
		opRegM_N3 = (opCmdWord[2:0]==3'b111) ? UREG_R0 :
			{3'h0, 1'b1, opCmdWord[2:0]};
	end
	else
	begin
		opRegS_8E		= 7'hXX;			opRegT_8E		= 7'hXX;
		opRegS_FR		= 7'hXX;			opRegT_FR		= 7'hXX;
		opImm_Zx4_8E	= 32'hXXXXXXXX;		opImm_Sx8E		= 32'hXXXXXXXX;
		opImm_Zx8E		= 32'hXXXXXXXX;		opImm_Nx8E		= 32'hXXXXXXXX;
		opImm_Sx16_8E	= 32'hXXXXXXXX;		opImm_Sx20_8E	= 32'hXXXXXXXX;
		opImmM_Sx12_8E	= 32'hXXXXXXXX;		opImmO_Sx12_8E	= 32'hXXXXXXXX;

		opRegN_N3=UREG_XX;		opRegM_N3=UREG_XX;
	end

	opImm_Zx4	= {28'h0, opCmdWord[ 3:0]};
	opImm_Zx8	= {24'h0, opCmdWord[ 7:0]};
	opImm_Sx8	= {opCmdWord[ 7] ? 24'hFFFFFF : 24'h000000, opCmdWord [ 7:0]};
	opImm_Sx12	= {opCmdWord[11] ? 20'hFFFFF  : 20'h00000 , opCmdWord [11:0]};

	case(tOpDecXfrm)

		UXFORM_CST: begin
		end

		UXFORM_N: begin
			opRegN=opRegN_Dfl;
			opRegS=opRegN;
		end

		UXFORM_MOV_NS: begin
			if(isOpCE)
			begin
				opRegN = opRegN_CEf;	opRegS = opRegM_CEf;
				opImm  = opImm6_ZxCE;
			end else if(isOp8E)
			begin
				opRegN	= opRegN_Dfl;	opRegS	= opRegM_Dfl;
				opImm	= opImm_Sx8E;
			end else begin
				opRegN=opRegN_Dfl;		opRegS=opRegM_Dfl;
			end
//			if(tOpDecXfrmZx==UXFORMZX_RF)	opRegN[6:5]=2'b10;
//			if(tOpDecXfrmZx==UXFORMZX_FR)	opRegS[6:5]=2'b10;
		end

		UXFORM_MOV_NSO: begin
			if(isOpCE)
			begin
				opRegN=opRegN_CEe;	opRegS=opRegM_CEe;
				opRegT=opRegT_CEe;	opImm=0;
			end else if(isOp8E)
			begin
				opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
				opRegT=opRegS_8E;	opImm=opImm_Zx4_8E;
			end else begin
				opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
				opRegT=UREG_R0;		opImm=0;
			end
//			if(tOpDecXfrmZx==UXFORMZX_RF)	opRegN[6:5]=2'b10;
//			if(tOpDecXfrmZx==UXFORMZX_FR)	opRegS[6:5]=2'b10;
		end

		UXFORM_MOV_NSJ: begin
			if(isOpCE)
			begin
				opRegN = opRegN_CEe;
				opRegS = opRegM_CEe;
				opRegT = opRegO_CEe;
				opImm  = opImm_Zx4_8E;
			end else if(isOp8E)
			begin
				opRegN = opRegN_Dfl;	opRegS = opRegM_Dfl;
				opRegT = opRegO_Dfl;	opImm  = opImm_Sx8E;
			end else begin
				opRegN=opRegN_Dfl;		opRegS=opRegM_Dfl;
				opImm  = opImm_Zx4;
			end
//			if(tOpDecXfrmZx==UXFORMZX_RF)	opRegN[6:5]=2'b10;
//			if(tOpDecXfrmZx==UXFORMZX_FR)	opRegS[6:5]=2'b10;
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

// /*
				UXFORMZX_FRD: begin
					opRegN=opRegN_Dfl;	opRegS=opRegM_FR;
					opRegT=UREG_MR_MEMDEC;
				end
				UXFORMZX_RFI: begin
					opRegN=opRegN_FR;	opRegS=opRegM_Dfl;
					opRegT=UREG_MR_MEMINC;
				end

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
// */

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
//			opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;

//			/*
			case(tOpDecXfrmZx)
				UXFORMZX_RR: begin
					opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
				end
				
				UXFORMZX_FF: begin
					opRegN=opRegN_FR;	opRegS=opRegM_FR;
				end

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
//			*/
		end

		UXFORM_ARI_NST: begin
			if(isOpCE)
			begin
				opRegN=opRegN_CEf;	opRegS=opRegM_CEf;
				opRegT=UREG_MR_IMM;
				case(tOpDecXfrmZx)
					UXFORMZX_SX: opImm=opImm6_SxCE;
					UXFORMZX_ZX: opImm=opImm6_ZxCE;
					UXFORMZX_NX: opImm=opImm6_NxCE;
					default: begin end
				endcase

			end else if(isOp8E)
			begin
				opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
				opRegT=UREG_MR_IMM;
				case(tOpDecXfrmZx)
					UXFORMZX_SX: opImm=opImm_Sx8E;
					UXFORMZX_ZX: opImm=opImm_Zx8E;
					UXFORMZX_NX: opImm=opImm_Nx8E;
					default: begin end
				endcase
			end else begin
				opRegN=opRegN_Dfl;	opRegS=opRegN_Dfl;	opRegT=opRegM_Dfl;
			end
		end

		UXFORM_CMP_ST: begin
			if(isOp8E)
			begin
				opRegS=opRegN_Dfl;	opRegT=UREG_MR_IMM;
				opImm=opImmM_Sx12_8E;
			end else begin
				opRegS=opRegN_Dfl;	opRegT=opRegM_Dfl;
			end
		end

		UXFORM_ARI_ST: begin
			opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
		end

		UXFORM_ARI_NNI: begin
			if(isOpXE)
			begin
				opRegN={2'h0, isOpCE, opCmdWord[11:8]};
				opRegS=opRegN;
				opRegT=UREG_MR_IMM;	opImm=opImm_Sx16_8E;
			end else begin
				opRegN=opRegN_Dfl;	opRegS=opRegN_Dfl;
				opRegT=UREG_MR_IMM;	opImm=opImm_Sx8;
			end
		end
		
		UXFORM_BR_D8: begin
			opImm = isOpXE ? opImm_Sx16_8E : opImm_Sx8;
		end
		UXFORM_BR_D12: begin
			opImm = isOpXE ? opImm_Sx20_8E : opImm_Sx12;
		end

		UXFORM_ARI_I8R0: begin
			if(isOpXE)
			begin
				opRegN=opRegM_Dfl;	opRegS=opRegN;
				opRegT=UREG_MR_IMM;	opImm=opImmO_Sx12_8E;
			end else begin
				opRegN=UREG_R0;		opRegS=UREG_R0;
				opRegT=UREG_MR_IMM;	opImm=opImm_Zx8;
			end
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

// /*
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
// */

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
		
		UXFORM_NST_8E: begin
//			opRegN=opRegN_Dfl;
//			opRegS=opRegS_8E;
//			opRegT=opRegT_8E;

// /*
			case(tOpDecXfrmZx)
				UXFORMZX_RR: begin
					opRegN=opRegN_Dfl;
					opRegS=opRegS_8E;
					opRegT=opRegT_8E;
				end
				
				UXFORMZX_FF: begin
					opRegN=opRegN_FR;
					opRegS=opRegS_FR;
					opRegT=opRegT_FR;
				end

				default: begin
					opRegN=UREG_XX;		opRegS=UREG_XX;
					opRegT=UREG_XX;		opImm=32'hXXXXXXXX;
				end
			endcase
// */
		end

		default: begin
			opRegN=UREG_XX;		opRegS=UREG_XX;
			opRegT=UREG_XX;		opImm=32'hXXXXXXXX;
		end
	endcase

//	if(opIsRegN_FR)
//		opRegN[6:5]=2'b10;
//	if(opIsRegM_FR || opIsRegS_FR)
//		opRegS[6:5]=2'b10;
//	if(opIsRegT_FR)
//		opRegT[6:5]=2'b10;

end

endmodule
