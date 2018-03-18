/*
Partial Decoder, handles 8Exx_xxx and CExx_xxxx blocks.

This will be speculative, and the main decoder will integrate the results
of the various decoder paths, selecting the one which matches.

Results of this decoder are to be ignored if the block doesn't match.

I-Forms
  XEst_OnmO
  XEst_Onmo
  XEii_OnmO
  XEii_Onii
  
8Exx will be [15:0], and opcode word will be [31:16].

 */

`include "CoreDefs.v"

module DecOp4_XE(
	/* verilator lint_off UNUSED */
	istrWord,
	idRegN,
	idRegS,
	idRegT,
	idImm,
	idUCmd
	);

input[31:0]		istrWord;	//source instruction word

output[6:0]		idRegN;
output[6:0]		idRegS;
output[6:0]		idRegT;
output[31:0]	idImm;
output[7:0]		idUCmd;

reg[6:0]		opRegN;
reg[6:0]		opRegS;
reg[6:0]		opRegT;	//Index for mem ops
reg[31:0]		opImm;	//Disp for mem ops
reg[7:0]		opUCmd;

assign	idRegN = opRegN;
assign	idRegS = opRegS;
assign	idRegT = opRegT;
assign	idImm = opImm;
assign	idUCmd = opUCmd;


reg[6:0]		opRegN_Dfl;
reg[6:0]		opRegM_Dfl;
reg[6:0]		opRegO_Dfl;
reg[6:0]		opRegS_Dfl;
reg[6:0]		opRegT_Dfl;

reg[6:0]		opRegN_FR;
reg[6:0]		opRegM_FR;
reg[6:0]		opRegS_FR;
reg[6:0]		opRegT_FR;

reg[31:0]		opImm8_Sx8E;
reg[31:0]		opImm8_Zx8E;
reg[31:0]		opImm8_Nx8E;

reg[31:0]		opImm16_Sx8E;
reg[31:0]		opImm20_Sx8E;
reg[31:0]		opImmM12_Sx8E;
reg[31:0]		opImmO12_Sx8E;

// reg[31:0]		opImmO12_Zx8E;

reg[31:0]		opImm4_ZxXE;

reg[15:0]		opPfxWord;
reg[15:0]		opCmdWord;

reg[4:0]	tOpDecXfrm;
reg[2:0]	tOpDecXfrmZx;

always @*
begin

	opCmdWord=istrWord[31:16];
	opPfxWord=istrWord[15: 0];
//	opIsCE = (istrWord[15:14]==2'b11);
//	opIsCE = 0;

	opRegN_Dfl = {3'h0, opCmdWord[11: 8]};
	opRegM_Dfl = {3'h0, opCmdWord[ 7: 4]};
	opRegO_Dfl = {3'h0, opCmdWord[ 3: 0]};
	opRegS_Dfl = {3'h0, opPfxWord[ 7: 4]};
	opRegT_Dfl = {3'h0, opPfxWord[ 3: 0]};

	opRegN_FR  = {3'h4, opCmdWord[11: 8]};
	opRegM_FR  = {3'h4, opCmdWord[ 7: 4]};
	opRegS_FR  = {3'h4, opPfxWord[ 7: 4]};
	opRegT_FR  = {3'h4, opPfxWord[ 3: 0]};

	opImm8_Sx8E	= {opPfxWord[7] ? 24'hFFFFFF : 24'h0, opPfxWord[ 7:0]};
	opImm8_Zx8E	= {24'h000000, opPfxWord[ 7:0]};
	opImm8_Nx8E	= {24'hFFFFFF, opPfxWord[ 7:0]};

	opImmM12_Sx8E	= {opPfxWord[7] ? 20'hFFFFF : 20'h0,
		opPfxWord[ 7:0], opCmdWord[ 7:4]};
	opImmO12_Sx8E	= {opPfxWord[7] ? 20'hFFFFF : 20'h0,
		opPfxWord[ 7:0], opCmdWord[ 3:0]};

//	opImmO12_Zx8E	= { 20'h0, opPfxWord[ 7:0], opCmdWord[ 3:0] };

	opImm16_Sx8E	= {opPfxWord[7] ? 16'hFFFF : 16'h0000,
		opPfxWord[ 7:0], opCmdWord[ 7:0]};
	opImm20_Sx8E	= {opPfxWord[7] ? 12'hFFF : 12'h000,
		opPfxWord[ 7:0], opCmdWord[11:0]};

	opImm4_ZxXE = {28'h000000, opPfxWord[ 3:0]};

	opUCmd=UCMD_UDBRK;
	opImm=0;

	opRegN=UREG_ZZR;
	opRegS=UREG_ZZR;
	opRegT=UREG_ZZR;

	tOpDecXfrm=UXFORM_INVALID;
	tOpDecXfrmZx=UXFORMZX_SX;

	casez(opCmdWord[15:12])

		4'h0: case(opCmdWord[3:0])
			4'h4: begin		//0xx4
				opUCmd = UCMD_MOVB_RM;
				tOpDecXfrm=UXFORM_MOV_NSO;
			end

			4'h5: begin		//0xx5
				opUCmd = UCMD_MOVW_RM;
				tOpDecXfrm=UXFORM_MOV_NSO;
			end

			4'h6: begin		//0xx6
				opUCmd = UCMD_MOVL_RM;
				tOpDecXfrm=UXFORM_MOV_NSO;
			end

			4'h7: begin		//0xx7
				opUCmd = UCMD_MOVQ_RM;
				tOpDecXfrm=UXFORM_MOV_NSO;
			end

			4'hC: begin		//0xxC
				opUCmd = UCMD_MOVB_MR;
				tOpDecXfrm=UXFORM_MOV_NSO;
			end

			4'hD: begin		//0xxD
				opUCmd = UCMD_MOVW_MR;
				tOpDecXfrm=UXFORM_MOV_NSO;
			end

			4'hE: begin		//0xxE
				opUCmd = UCMD_MOVL_MR;
				tOpDecXfrm=UXFORM_MOV_NSO;
			end

			4'hF: begin		//0xxF
				opUCmd = UCMD_MOVQ_MR;
				tOpDecXfrm=UXFORM_MOV_NSO;
			end
			default: begin end
		endcase

		4'h1: begin		//1nmd, MOV.L Rm, @(Rn, disp4)
			opUCmd = UCMD_MOVL_RM;
			tOpDecXfrm=UXFORM_MOV_NSJ;
		end

		4'h2: case(opCmdWord[3:0])
		
			4'h0: begin		//2xx0, MOV.B Rm, @Rn
				opUCmd = UCMD_MOVB_RM;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'h1: begin		//2xx1, MOV.W Rm, @Rn
				opUCmd = UCMD_MOVW_RM;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'h2: begin		//2xx2, MOV.L Rm, @Rn
				opUCmd = UCMD_MOVL_RM;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'h3: begin		//2xx3, MOV.Q Rm, @Rn
				opUCmd = UCMD_MOVQ_RM;
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

			4'hE: begin		//2xxE, MUL Rm, Rn
				opUCmd=UCMD_ALU_MUL;	tOpDecXfrm=UXFORM_ARI_NST;
				tOpDecXfrmZx=UXFORMZX_ZX;
			end
			4'hF: begin		//2xxF, MUL Rm, Rn
				opUCmd=UCMD_ALU_MUL;	tOpDecXfrm=UXFORM_ARI_NST;
				tOpDecXfrmZx=UXFORMZX_NX;
			end
			default: begin end
		endcase

		4'h3: case(opCmdWord[3:0])
			4'h0: begin		//3xx0, CMP/EQ Rm, Rn
				opUCmd=UCMD_CMP_EQ;
				tOpDecXfrm=UXFORM_CMP_ST;
			end

			4'h2: begin		//3xx2, CMP/HS Rm, Rn
				opUCmd=UCMD_CMP_HS;
				tOpDecXfrm=UXFORM_CMP_ST;
			end
			4'h3: begin		//3xx3, CMP/GE Rm, Rn
				opUCmd=UCMD_CMP_GE;
				tOpDecXfrm=UXFORM_CMP_ST;
			end

			4'h6: begin		//3xx6, CMP/HI Rm, Rn
				opUCmd=UCMD_CMP_HI;
				tOpDecXfrm=UXFORM_CMP_ST;
			end
			4'h7: begin		//3xx7, CMP/GT Rm, Rn
				opUCmd=UCMD_CMP_GT;
				tOpDecXfrm=UXFORM_CMP_ST;
			end
			4'h8: begin		//3xx8, SUB Rm, Rn
				opUCmd=UCMD_ALU_SUB;
				tOpDecXfrm=UXFORM_ARI_NST;
				tOpDecXfrmZx=UXFORMZX_ZX;
			end

			4'hC: begin		//3xxC, ADD Rm, Rn
				opUCmd=UCMD_ALU_ADD;
				tOpDecXfrm=UXFORM_ARI_NST;
				tOpDecXfrmZx=UXFORMZX_ZX;
			end
			default: begin end
		endcase

		4'h4: case(opCmdWord[3:0])
			4'h3: begin		//4xx3
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
					opUCmd=UCMD_FPU_ADD;
					tOpDecXfrm=UXFORM_FPARI_NST_8E;
//					tOpDecXfrm=UXFORM_NST_8E;	tOpDecXfrmZx=UXFORMZX_FF;
				end
				4'hD: begin
					opUCmd=UCMD_FPU_SUB;
					tOpDecXfrm=UXFORM_FPARI_NST_8E;
//					tOpDecXfrm=UXFORM_NST_8E;	tOpDecXfrmZx=UXFORMZX_FF;
				end
				4'hE: begin
					opUCmd=UCMD_FPU_MUL;
					tOpDecXfrm=UXFORM_FPARI_NST_8E;
//					tOpDecXfrm=UXFORM_NST_8E;	tOpDecXfrmZx=UXFORMZX_FF;
				end

				default: begin end

				endcase
			end

			4'hC: begin		//4xxC
				opUCmd=UCMD_ALU_SHAD;
				tOpDecXfrm=UXFORM_ARI_NST;
				tOpDecXfrmZx=UXFORMZX_SX;
			end
			4'hD: begin		//4xxD
				opUCmd=UCMD_ALU_SHLD;
				tOpDecXfrm=UXFORM_ARI_NST;
				tOpDecXfrmZx=UXFORMZX_SX;
			end
			4'hE: begin		//4xxE, LDC
				case(opCmdWord[7:4])
				4'h0: begin
					opUCmd=UCMD_MOVUB_MR;
					tOpDecXfrm=UXFORM_NST_8E;
				end
				4'h1: begin
					opUCmd=UCMD_MOVUW_MR;
					tOpDecXfrm=UXFORM_NST_8E;
				end

				default: begin end
				endcase
			end
			default: begin end
		endcase

		4'h5: begin		//5xxx
			opUCmd = UCMD_MOVL_MR;
			tOpDecXfrm=UXFORM_MOV_NSJ;
		end

		4'h6: case(opCmdWord[3:0])
			4'h0: begin		//6xx0
				opUCmd=UCMD_MOVB_MR;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'h1: begin		//6xx1
				opUCmd = UCMD_MOVW_MR;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'h2: begin		//6xx2
				opUCmd = UCMD_MOVL_MR;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'h3: begin		//6xx3
				opUCmd=UCMD_MOVQ_MR;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'h4: begin		//6xx4
				opUCmd=UCMD_LEAB_MR;
				tOpDecXfrm=UXFORM_MOV_NSO;
			end
			4'h5: begin		//6xx5
				opUCmd=UCMD_LEAW_MR;
				tOpDecXfrm=UXFORM_MOV_NSO;
			end
			4'h6: begin		//6xx6
				opUCmd=UCMD_LEAL_MR;
				tOpDecXfrm=UXFORM_MOV_NSO;
			end
			4'h7: begin
				opUCmd=UCMD_LEAQ_MR;
				tOpDecXfrm=UXFORM_MOV_NSO;
			end
			4'h8: begin
				opUCmd=UCMD_LEAB_MR;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'h9: begin
				opUCmd=UCMD_LEAW_MR;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'hA: begin
				opUCmd=UCMD_LEAL_MR;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'hB: begin
				opUCmd=UCMD_LEAQ_MR;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'hC: begin
				opUCmd=UCMD_MOVUB_MR;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'hD: begin
				opUCmd=UCMD_MOVUW_MR;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'hE: begin
				opUCmd=UCMD_MOVUL_MR;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			4'hF: begin
				opUCmd=UCMD_MOVQ_MR;
				tOpDecXfrm=UXFORM_MOV_NS;
			end
			default: begin end
		endcase

		4'h7: begin		//7xxx
			opUCmd=UCMD_ALU_ADD;
			tOpDecXfrm=UXFORM_ARI_NNI;
		end

		4'h8: case(opCmdWord[11:8])
			4'h2: begin		//82xx
				opUCmd=UCMD_BRAN;		tOpDecXfrm=UXFORM_BR_D8;
			end
			4'h3: begin		//83xx
				opUCmd=UCMD_BSRN;	tOpDecXfrm=UXFORM_BR_D8;
			end

			4'h8: begin		//88xx
				opUCmd=UCMD_CMP_EQ;
				tOpDecXfrm=UXFORM_ARI_I8R0;
			end
			4'h9: begin		//89xx
				opUCmd=UCMD_BT;		tOpDecXfrm=UXFORM_BR_D8;
			end
			4'hA: begin		//8Axx-xxxx
			end
			4'hB: begin		//8Bxx, BF disp
				opUCmd=UCMD_BF;		tOpDecXfrm=UXFORM_BR_D8;
			end
			4'hC: begin		//8Cxx
			end
			4'hD: begin		//8Dxx, BTS disp
				opUCmd=UCMD_BTS;		tOpDecXfrm=UXFORM_BR_D8;
			end

			4'hF: begin		//8Fxx, BFS disp
				opUCmd=UCMD_BFS;		tOpDecXfrm=UXFORM_BR_D8;
			end
			default: begin end
		endcase

		4'h9: begin		//9xxx
			opUCmd=UCMD_ALU_LDSH16;
			tOpDecXfrm=UXFORM_ARI_NNI;
		end

		4'hA: begin		//Axxx
			opUCmd=UCMD_BRA;		tOpDecXfrm=UXFORM_BR_D12;
		end

		4'hB: begin		//Bxxx
			opUCmd=UCMD_BSR;		tOpDecXfrm=UXFORM_BR_D12;
		end

		4'hC: case(opCmdWord[11:8])
			4'h0: begin
				opUCmd=UCMD_MOVB_RM;
//				tOpDecXfrm=UXFORM_MOV_GD8R0;
//				tOpDecXfrmZx=UXFORMZX_RM;
				tOpDecXfrm=UXFORM_MOV_GD8R0_RM;
			end

			4'h1: begin
				opUCmd=UCMD_MOVW_RM;
//				tOpDecXfrm=UXFORM_MOV_GD8R0;
//				tOpDecXfrmZx=UXFORMZX_RM;
				tOpDecXfrm=UXFORM_MOV_GD8R0_RM;
			end

			4'h2: begin
				opUCmd=UCMD_MOVL_RM;
//				tOpDecXfrm=UXFORM_MOV_GD8R0;
//				tOpDecXfrmZx=UXFORMZX_RM;
				tOpDecXfrm=UXFORM_MOV_GD8R0_RM;
			end

			4'h4: begin
				opUCmd=UCMD_MOVB_MR;
//				tOpDecXfrm=UXFORM_MOV_GD8R0;
//				tOpDecXfrmZx=UXFORMZX_MR;
				tOpDecXfrm=UXFORM_MOV_GD8R0_MR;
			end

			4'h5: begin
				opUCmd=UCMD_MOVW_MR;
//				tOpDecXfrm=UXFORM_MOV_GD8R0;
//				tOpDecXfrmZx=UXFORMZX_MR;
				tOpDecXfrm=UXFORM_MOV_GD8R0_MR;
			end

			4'h6: begin
				opUCmd=UCMD_MOVL_MR;
//				tOpDecXfrm=UXFORM_MOV_GD8R0;
//				tOpDecXfrmZx=UXFORMZX_MR;
				tOpDecXfrm=UXFORM_MOV_GD8R0_MR;
			end

			4'h8: begin		//CMP/EQ #imm, R0
				opUCmd=UCMD_CMP_TST;
				tOpDecXfrm=UXFORM_CMP_I8R0;
			end
			4'h9: begin		//AND #imm, R0
				opUCmd=UCMD_ALU_AND;
				tOpDecXfrm=UXFORM_ARI_I8R0;
			end
			4'hA: begin		//XOR #imm, R0
				opUCmd=UCMD_ALU_XOR;
				tOpDecXfrm=UXFORM_ARI_I8R0;
			end
			4'hB: begin		//OR #imm, R0
				opUCmd=UCMD_ALU_OR;
				tOpDecXfrm=UXFORM_ARI_I8R0;
			end

			default: begin end
		endcase

//		4'hD: begin		//Dxxx, MOV @(PC,disp), Rn
//		end

		4'hE: begin		//Exxx, MOV #imm, Rn
			opUCmd=UCMD_MOV_RI;
			tOpDecXfrm=UXFORM_ARI_NNI;
		end

		default: begin end

	endcase

	case(tOpDecXfrm)

		UXFORM_CST: begin
		end

		UXFORM_N: begin
			opRegN=opRegN_Dfl;
			opRegS=opRegN;
		end

		UXFORM_MOV_NS: begin
			opRegN	= opRegN_Dfl;	opRegS	= opRegM_Dfl;
			opImm	= opImm8_Sx8E;
		end

		UXFORM_MOV_NSO: begin
			opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
			opRegT=opRegS_Dfl;	opImm=opImm4_ZxXE;
		end

		UXFORM_MOV_NSJ: begin
			opRegN = opRegN_Dfl;	opRegS = opRegM_Dfl;
			opRegT = opRegO_Dfl;	opImm  = opImm8_Sx8E;
		end

//		UXFORM_FPARI_NS: begin
//			opRegN=opRegN_FR;
//			opRegS=opRegM_FR;
//		end

//		UXFORM_ARI_NS: begin
//			opRegN=opRegN_Dfl;
//			opRegS=opRegM_Dfl;
//		end

		UXFORM_ARI_NST: begin
			opRegN=opRegN_Dfl;	opRegS=opRegM_Dfl;
			opRegT=UREG_MR_IMM;
			case(tOpDecXfrmZx)
				UXFORMZX_SX: opImm=opImm8_Sx8E;
				UXFORMZX_ZX: opImm=opImm8_Zx8E;
				UXFORMZX_NX: opImm=opImm8_Nx8E;
				default: begin opImm=UV32_XX; end
			endcase
		end

		UXFORM_CMP_ST: begin
			opRegS=opRegN_Dfl;
			opRegT=UREG_MR_IMM;
			opImm=opImmM12_Sx8E;
		end

		UXFORM_ARI_ST: begin
			opRegN=opRegN_Dfl;
			opRegS=opRegM_Dfl;
		end

		UXFORM_ARI_NNI: begin
//			opRegN={2'h0, opIsCE, opCmdWord[11:8]};
			opRegN={3'h0, opCmdWord[11:8]};
			opRegS=opRegN;
			opRegT=UREG_MR_IMM;	opImm=opImm16_Sx8E;
		end
		
		UXFORM_BR_D8: begin
			opImm = opImm16_Sx8E;
		end
		UXFORM_BR_D12: begin
			opImm = opImm20_Sx8E;
		end

		UXFORM_ARI_I8R0: begin
			opRegN=opRegM_Dfl;	opRegS=opRegM_Dfl;
			opRegT=UREG_MR_IMM;	opImm=opImmO12_Sx8E;
		end

		UXFORM_N_C: begin
			opRegN=opRegN_Dfl;	opRegS=opRegN_Dfl;
			opRegT=UREG_MR_IMM;
		end
		
/*
		UXFORM_MOV_GD8R0: begin
			case(tOpDecXfrmZx)
				UXFORMZX_RM: begin
					opRegN=UREG_GBR;	opRegS=opRegM_Dfl;
					opRegT=UREG_MR_IMM;	opImm=opImmO12_Sx8E;
				end
				UXFORMZX_MR: begin
					opRegN=opRegM_Dfl;	opRegS=UREG_GBR;
					opRegT=UREG_MR_IMM;	opImm=opImmO12_Sx8E;
				end

				default: begin
					opRegN=UREG_XX;		opRegS=UREG_XX;
					opRegT=UREG_XX;		opImm=32'hXXXXXXXX;
				end
			endcase
		end
*/

		UXFORM_MOV_GD8R0_RM: begin
			opRegN=UREG_GBR;	opRegS=opRegM_Dfl;
			opRegT=UREG_MR_IMM;	opImm=opImmO12_Sx8E;
		end

		UXFORM_MOV_GD8R0_MR: begin
			opRegN=opRegM_Dfl;	opRegS=UREG_GBR;
			opRegT=UREG_MR_IMM;	opImm=opImmO12_Sx8E;
		end
		
		UXFORM_FPARI_NST_8E: begin
//			opRegN=opRegN_FR;
//			opRegS=opRegM_FR;
			opRegN=opRegN_FR;
			opRegS=opRegS_FR;
			opRegT=opRegT_FR;
		end

		UXFORM_NST_8E: begin
			opRegN=opRegN_Dfl;
			opRegS=opRegS_Dfl;
			opRegT=opRegT_Dfl;

/*
			case(tOpDecXfrmZx)
				UXFORMZX_RR: begin
					opRegN=opRegN_Dfl;
					opRegS=opRegS_Dfl;
					opRegT=opRegT_Dfl;
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
*/
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

end

endmodule
