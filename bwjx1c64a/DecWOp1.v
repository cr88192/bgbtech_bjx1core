/*
Partial Decoder, 24-bit WJX1 xx_xxxx opcodes.

Main decoder will integrate results from the other units.
 */

`include "CoreDefs.v"

module DecWOp1(
	/* verilator lint_off UNUSED */
	clock,
	istrWord,
	idRegN,
	idRegS,
	idRegT,
	idImm,
	idUCmd
	);

/* Specifies whether this should use two stages. */
parameter		decTwoStage = 1;

input			clock;
input[23:0]		istrWord;	//source instruction word

output[6:0]		idRegN;
output[6:0]		idRegS;
output[6:0]		idRegT;
output[31:0]	idImm;
output[7:0]		idUCmd;

reg[6:0]		opRegN;
reg[6:0]		opRegS;
reg[6:0]		opRegT;	//Index for mem ops
reg[31:0]		opImm;	//Disp for mem ops
reg[7:0]		opUCmdA;
reg[7:0]		opUCmd;

assign	idRegN = opRegN;
assign	idRegS = opRegS;
assign	idRegT = opRegT;
assign	idImm = opImm;
assign	idUCmd = opUCmd;


reg[6:0]		opRegN_Ce;
reg[6:0]		opRegM_Ce;
reg[6:0]		opRegO_Ce;
reg[6:0]		opRegT_Ce;

reg[6:0]		opRegN_Cf;
reg[6:0]		opRegM_Cf;

reg[6:0]		opRegN_FR;
reg[6:0]		opRegM_FR;
// reg[6:0]		opRegS_FR;
reg[6:0]		opRegT_FR;

reg[31:0]		opImm6_SxCE;
reg[31:0]		opImm6_ZxCE;
reg[31:0]		opImm6_NxCE;

reg[31:0]		opImm15_SxCE;
reg[31:0]		opImmM10_SxCE;
reg[31:0]		opImmO10_SxCE;

reg[31:0]		opImm4_ZxXE;

reg[31:0]		opImm20_Sx8E;

reg[7:0]		opPfxWordA;
reg[15:0]		opCmdWordA;

reg[4:0]	tOpDecXfrmA;
reg[2:0]	tOpDecXfrmZxA;


reg[ 7:0]	opPfxWordB;
reg[15:0]	opCmdWordB;
reg[4:0]	tOpDecXfrmB;
reg[2:0]	tOpDecXfrmZxB;

always @*
begin

	opPfxWordA = istrWord[23:16];
	opCmdWordA = istrWord[15: 0];
//	opIsCE = (istrWord[15:14]==2'b11);
//	opIsCE = 0;

	/* Stage A */

	opUCmdA = UCMD_UDBRK;
	opImm=0;

	tOpDecXfrmA = UXFORM_INVALID;
	tOpDecXfrmZxA = UXFORMZX_SX;

	casez(opCmdWordA[15:12])

		4'h0: case(opCmdWordA[3:0])
			4'h4: begin		//0xx4
				opUCmdA = UCMD_MOVB_RM;
				tOpDecXfrmA = UXFORM_MOV_NSO;
			end

			4'h5: begin		//0xx5
				opUCmdA = UCMD_MOVW_RM;
				tOpDecXfrmA = UXFORM_MOV_NSO;
			end

			4'h6: begin		//0xx6
				opUCmdA = UCMD_MOVL_RM;
				tOpDecXfrmA = UXFORM_MOV_NSO;
			end

			4'h7: begin		//0xx7
				opUCmdA = UCMD_MOVQ_RM;
				tOpDecXfrmA = UXFORM_MOV_NSO;
			end

			4'hC: begin		//0xxC
				opUCmdA = UCMD_MOVB_MR;
				tOpDecXfrmA = UXFORM_MOV_NSO;
			end

			4'hD: begin		//0xxD
				opUCmdA = UCMD_MOVW_MR;
				tOpDecXfrmA = UXFORM_MOV_NSO;
			end

			4'hE: begin		//0xxE
				opUCmdA = UCMD_MOVL_MR;
				tOpDecXfrmA = UXFORM_MOV_NSO;
			end

			4'hF: begin		//0xxF
				opUCmdA = UCMD_MOVQ_MR;
				tOpDecXfrmA = UXFORM_MOV_NSO;
			end
			default: begin end
		endcase

		4'h1: begin		//1nmd, MOV.L Rm, @(Rn, disp4)
			opUCmdA = UCMD_MOVL_RM;
			tOpDecXfrmA = UXFORM_MOV_NSJ;
		end

		4'h2: case(opCmdWordA[3:0])
		
			4'h0: begin		//2xx0, MOV.B Rm, @Rn
				opUCmdA = UCMD_MOVB_RM;
				tOpDecXfrmA = UXFORM_MOV_NS;
			end
			4'h1: begin		//2xx1, MOV.W Rm, @Rn
				opUCmdA = UCMD_MOVW_RM;
				tOpDecXfrmA = UXFORM_MOV_NS;
			end
			4'h2: begin		//2xx2, MOV.L Rm, @Rn
				opUCmdA = UCMD_MOVL_RM;
				tOpDecXfrmA = UXFORM_MOV_NS;
			end
			4'h3: begin		//2xx3, MOV.Q Rm, @Rn
				opUCmdA = UCMD_MOVQ_RM;
			end

			4'h9: begin		//2xx9, AND Rm, Rn
				opUCmdA = UCMD_ALU_AND;	tOpDecXfrmA = UXFORM_ARI_NST;
				tOpDecXfrmZxA = UXFORMZX_ZX;
			end
			4'hA: begin		//2xxA, XOR Rm, Rn
				opUCmdA = UCMD_ALU_XOR;	tOpDecXfrmA = UXFORM_ARI_NST;
				tOpDecXfrmZxA = UXFORMZX_ZX;
			end
			4'hB: begin		//2xxB, OR Rm, Rn
				opUCmdA = UCMD_ALU_OR;		tOpDecXfrmA = UXFORM_ARI_NST;
				tOpDecXfrmZxA = UXFORMZX_ZX;
			end

			4'hE: begin		//2xxE, MUL Rm, Rn
				opUCmdA = UCMD_ALU_MUL;	tOpDecXfrmA = UXFORM_ARI_NST;
				tOpDecXfrmZxA = UXFORMZX_ZX;
			end
			4'hF: begin		//2xxF, MUL Rm, Rn
				opUCmdA = UCMD_ALU_MUL;	tOpDecXfrmA = UXFORM_ARI_NST;
				tOpDecXfrmZxA = UXFORMZX_NX;
			end
			default: begin end
		endcase

		4'h3: case(opCmdWordA[3:0])
			4'h0: begin		//3xx0, CMP/EQ Rm, Rn
				opUCmdA = UCMD_CMP_EQ;
				tOpDecXfrmA = UXFORM_CMP_ST;
			end

			4'h2: begin		//3xx2, CMP/HS Rm, Rn
				opUCmdA = UCMD_CMP_HS;
				tOpDecXfrmA = UXFORM_CMP_ST;
			end
			4'h3: begin		//3xx3, CMP/GE Rm, Rn
				opUCmdA = UCMD_CMP_GE;
				tOpDecXfrmA = UXFORM_CMP_ST;
			end

			4'h6: begin		//3xx6, CMP/HI Rm, Rn
				opUCmdA = UCMD_CMP_HI;
				tOpDecXfrmA = UXFORM_CMP_ST;
			end
			4'h7: begin		//3xx7, CMP/GT Rm, Rn
				opUCmdA = UCMD_CMP_GT;
				tOpDecXfrmA = UXFORM_CMP_ST;
			end
			4'h8: begin		//3xx8, SUB Rm, Rn
				opUCmdA = UCMD_ALU_SUB;
				tOpDecXfrmA = UXFORM_ARI_NST;
				tOpDecXfrmZxA = UXFORMZX_ZX;
			end

			4'hC: begin		//3xxC, ADD Rm, Rn
				opUCmdA = UCMD_ALU_ADD;
				tOpDecXfrmA = UXFORM_ARI_NST;
				tOpDecXfrmZxA = UXFORMZX_ZX;
			end
			default: begin end
		endcase

		4'h4: case(opCmdWordA[3:0])
			4'h3: begin		//4xx3
				case(opCmdWordA[7:4])
				4'h0: begin
					opUCmdA = UCMD_ALU_ADD;	tOpDecXfrmA = UXFORM_NST_8E;
				end
				4'h1: begin
					opUCmdA = UCMD_ALU_SUB;	tOpDecXfrmA = UXFORM_NST_8E;
				end
				4'h2: begin
					opUCmdA = UCMD_ALU_MUL;	tOpDecXfrmA = UXFORM_NST_8E;
				end
				4'h3: begin
					opUCmdA = UCMD_ALU_AND;	tOpDecXfrmA = UXFORM_NST_8E;
				end
				4'h4: begin
					opUCmdA = UCMD_ALU_OR;		tOpDecXfrmA = UXFORM_NST_8E;
				end
				4'h5: begin
					opUCmdA = UCMD_ALU_XOR;	tOpDecXfrmA = UXFORM_NST_8E;
				end
				4'h6: begin
					opUCmdA = UCMD_ALU_SHLD;	tOpDecXfrmA = UXFORM_NST_8E;
				end
				4'h7: begin
					opUCmdA = UCMD_ALU_SHLDR;	tOpDecXfrmA = UXFORM_NST_8E;
				end
				4'h8: begin
					opUCmdA = UCMD_ALU_SHAD;	tOpDecXfrmA = UXFORM_NST_8E;
				end
				4'h9: begin
					opUCmdA = UCMD_ALU_SHADR;	tOpDecXfrmA = UXFORM_NST_8E;
				end

				4'hC: begin
					opUCmdA = UCMD_FPU_ADD;
					tOpDecXfrmA = UXFORM_FPARI_NST_8E;
//					tOpDecXfrmA = UXFORM_NST_8E;	tOpDecXfrmZxA = UXFORMZX_FF;
				end
				4'hD: begin
					opUCmdA = UCMD_FPU_SUB;
					tOpDecXfrmA = UXFORM_FPARI_NST_8E;
//					tOpDecXfrmA = UXFORM_NST_8E;	tOpDecXfrmZxA = UXFORMZX_FF;
				end
				4'hE: begin
					opUCmdA = UCMD_FPU_MUL;
					tOpDecXfrmA = UXFORM_FPARI_NST_8E;
//					tOpDecXfrmA = UXFORM_NST_8E;	tOpDecXfrmZxA = UXFORMZX_FF;
				end

				default: begin end

				endcase
			end

			4'hC: begin		//4xxC
				opUCmdA = UCMD_ALU_SHAD;
				tOpDecXfrmA = UXFORM_ARI_NST;
				tOpDecXfrmZxA = UXFORMZX_SX;
			end
			4'hD: begin		//4xxD
				opUCmdA = UCMD_ALU_SHLD;
				tOpDecXfrmA = UXFORM_ARI_NST;
				tOpDecXfrmZxA = UXFORMZX_SX;
			end
			4'hE: begin		//4xxE, LDC
				case(opCmdWordA[7:4])
				4'h0: begin
					opUCmdA = UCMD_MOVUB_MR;
					tOpDecXfrmA = UXFORM_NST_8E;
				end
				4'h1: begin
					opUCmdA = UCMD_MOVUW_MR;
					tOpDecXfrmA = UXFORM_NST_8E;
				end

				default: begin end
				endcase
			end
			default: begin end
		endcase

		4'h5: begin		//5xxx
			opUCmdA = UCMD_MOVL_MR;
			tOpDecXfrmA = UXFORM_MOV_NSJ;
		end

		4'h6: case(opCmdWordA[3:0])
			4'h0: begin		//6xx0
				opUCmdA = UCMD_MOVB_MR;
				tOpDecXfrmA = UXFORM_MOV_NS;
			end
			4'h1: begin		//6xx1
				opUCmdA = UCMD_MOVW_MR;
				tOpDecXfrmA = UXFORM_MOV_NS;
			end
			4'h2: begin		//6xx2
				opUCmdA = UCMD_MOVL_MR;
				tOpDecXfrmA = UXFORM_MOV_NS;
			end
			4'h3: begin		//6xx3
				opUCmdA = UCMD_MOVQ_MR;
				tOpDecXfrmA = UXFORM_MOV_NS;
			end
			4'h4: begin		//6xx4
				opUCmdA = UCMD_LEAB_MR;
				tOpDecXfrmA = UXFORM_MOV_NSO;
			end
			4'h5: begin		//6xx5
				opUCmdA = UCMD_LEAW_MR;
				tOpDecXfrmA = UXFORM_MOV_NSO;
			end
			4'h6: begin		//6xx6
				opUCmdA = UCMD_LEAL_MR;
				tOpDecXfrmA = UXFORM_MOV_NSO;
			end
			4'h7: begin
				opUCmdA = UCMD_LEAQ_MR;
				tOpDecXfrmA = UXFORM_MOV_NSO;
			end
			4'h8: begin
				opUCmdA = UCMD_LEAB_MR;
				tOpDecXfrmA = UXFORM_MOV_NS;
			end
			4'h9: begin
				opUCmdA = UCMD_LEAW_MR;
				tOpDecXfrmA = UXFORM_MOV_NS;
			end
			4'hA: begin
				opUCmdA = UCMD_LEAL_MR;
				tOpDecXfrmA = UXFORM_MOV_NS;
			end
			4'hB: begin
				opUCmdA = UCMD_LEAQ_MR;
				tOpDecXfrmA = UXFORM_MOV_NS;
			end
			4'hC: begin
				opUCmdA = UCMD_MOVUB_MR;
				tOpDecXfrmA = UXFORM_MOV_NS;
			end
			4'hD: begin
				opUCmdA = UCMD_MOVUW_MR;
				tOpDecXfrmA = UXFORM_MOV_NS;
			end
			4'hE: begin
				opUCmdA = UCMD_MOVUL_MR;
				tOpDecXfrmA = UXFORM_MOV_NS;
			end
			4'hF: begin
				opUCmdA = UCMD_MOVQ_MR;
				tOpDecXfrmA = UXFORM_MOV_NS;
			end
			default: begin end
		endcase

		4'h7: begin		//7xxx
			opUCmdA = UCMD_ALU_ADD;
			tOpDecXfrmA = UXFORM_ARI_NNI;
		end

		4'h8: case(opCmdWordA[11:8])
			4'h2: begin		//82xx
				opUCmdA = UCMD_BRAN;		tOpDecXfrmA = UXFORM_BR_D8;
			end
			4'h3: begin		//83xx
				opUCmdA = UCMD_BSRN;	tOpDecXfrmA = UXFORM_BR_D8;
			end

			4'h6: begin		//86xx
				opUCmdA = UCMD_BRA;	tOpDecXfrmA = UXFORM_BR_D8;
			end
			4'h7: begin		//87xx
				opUCmdA = UCMD_BSR;	tOpDecXfrmA = UXFORM_BR_D8;
			end

			4'h8: begin		//88xx
				opUCmdA = UCMD_CMP_EQ;
				tOpDecXfrmA = UXFORM_ARI_I8R0;
			end
			4'h9: begin		//89xx
				opUCmdA = UCMD_BT;		tOpDecXfrmA = UXFORM_BR_D8;
			end
			4'hA: begin		//8Axx-xxxx
			end
			4'hB: begin		//8Bxx, BF disp
				opUCmdA = UCMD_BF;		tOpDecXfrmA = UXFORM_BR_D8;
			end
			4'hC: begin		//8Cxx
			end
			4'hD: begin		//8Dxx, BTS disp
				opUCmdA = UCMD_BTS;		tOpDecXfrmA = UXFORM_BR_D8;
			end

			4'hF: begin		//8Fxx, BFS disp
				opUCmdA = UCMD_BFS;		tOpDecXfrmA = UXFORM_BR_D8;
			end
			default: begin end
		endcase

		4'h9: begin		//9xxx
			opUCmdA = UCMD_ALU_LDSH16;
			tOpDecXfrmA = UXFORM_ARI_NNI;
		end

		4'hA: begin		//Axxx
			case(opCmdWordA[3:0])
				4'h0: begin
					opUCmdA = UCMD_ALU_ADD;
					tOpDecXfrmA = UXFORM_MOV_NSO;
				end
				4'h1: begin
					opUCmdA = UCMD_ALU_SUB;
					tOpDecXfrmA = UXFORM_MOV_NSO;
				end
				4'h2: begin
					opUCmdA = UCMD_ALU_MUL;
					tOpDecXfrmA = UXFORM_MOV_NSO;
				end
				4'h3: begin
					opUCmdA = UCMD_ALU_AND;
					tOpDecXfrmA = UXFORM_MOV_NSO;
				end
				4'h4: begin
					opUCmdA = UCMD_ALU_OR;
					tOpDecXfrmA = UXFORM_MOV_NSO;
				end
				4'h5: begin
					opUCmdA = UCMD_ALU_XOR;
					tOpDecXfrmA = UXFORM_MOV_NSO;
				end

				4'h6: begin
					opUCmdA = UCMD_ALU_SHAD;
					tOpDecXfrmA = UXFORM_MOV_NSO;
				end
				4'h7: begin
					opUCmdA = UCMD_ALU_SHLD;
					tOpDecXfrmA = UXFORM_MOV_NSO;
				end
				
				default: begin end
			endcase
		end

		4'hB: begin		//Bxxx
			opUCmdA = UCMD_MOV_RI;
			tOpDecXfrmA = UXFORM_I20R0_XE;
		end

		4'hC: case(opCmdWordA[11:8])
			4'h0: begin
				opUCmdA = UCMD_MOVB_RM;
//				tOpDecXfrmA = UXFORM_MOV_GD8R0;
//				tOpDecXfrmZxA = UXFORMZX_RM;
				tOpDecXfrmA = UXFORM_MOV_GD8R0_RM;
			end

			4'h1: begin
				opUCmdA = UCMD_MOVW_RM;
//				tOpDecXfrmA = UXFORM_MOV_GD8R0;
//				tOpDecXfrmZxA = UXFORMZX_RM;
				tOpDecXfrmA = UXFORM_MOV_GD8R0_RM;
			end

			4'h2: begin
				opUCmdA = UCMD_MOVL_RM;
//				tOpDecXfrmA = UXFORM_MOV_GD8R0;
//				tOpDecXfrmZxA = UXFORMZX_RM;
				tOpDecXfrmA = UXFORM_MOV_GD8R0_RM;
			end

			4'h4: begin
				opUCmdA = UCMD_MOVB_MR;
//				tOpDecXfrmA = UXFORM_MOV_GD8R0;
//				tOpDecXfrmZxA = UXFORMZX_MR;
				tOpDecXfrmA = UXFORM_MOV_GD8R0_MR;
			end

			4'h5: begin
				opUCmdA = UCMD_MOVW_MR;
//				tOpDecXfrmA = UXFORM_MOV_GD8R0;
//				tOpDecXfrmZxA = UXFORMZX_MR;
				tOpDecXfrmA = UXFORM_MOV_GD8R0_MR;
			end

			4'h6: begin
				opUCmdA = UCMD_MOVL_MR;
//				tOpDecXfrmA = UXFORM_MOV_GD8R0;
//				tOpDecXfrmZxA = UXFORMZX_MR;
				tOpDecXfrmA = UXFORM_MOV_GD8R0_MR;
			end

			4'h8: begin		//CMP/EQ #imm, R0
				opUCmdA = UCMD_CMP_TST;
				tOpDecXfrmA = UXFORM_CMP_I8R0;
			end
			4'h9: begin		//AND #imm, R0
				opUCmdA = UCMD_ALU_AND;
				tOpDecXfrmA = UXFORM_ARI_I8R0;
			end
			4'hA: begin		//XOR #imm, R0
				opUCmdA = UCMD_ALU_XOR;
				tOpDecXfrmA = UXFORM_ARI_I8R0;
			end
			4'hB: begin		//OR #imm, R0
				opUCmdA = UCMD_ALU_OR;
				tOpDecXfrmA = UXFORM_ARI_I8R0;
			end

			default: begin end
		endcase

//		4'hD: begin		//Dxxx, MOV @(PC,disp), Rn
//		end

		4'hE: begin		//Exxx, MOV #imm, Rn
			opUCmdA = UCMD_MOV_RI;
			tOpDecXfrmA = UXFORM_ARI_NNI;
		end

		default: begin end

	endcase


	if(!decTwoStage)
	begin
		/* Single Stage Decode */
		opPfxWordB		= opPfxWordA;
		opCmdWordB		= opCmdWordA;
		tOpDecXfrmB		= tOpDecXfrmA;
		tOpDecXfrmZxB	= tOpDecXfrmZxA;
		opUCmd			= opUCmdA;
	end

	/* Stage B */

	opRegN_Ce = {2'b00, opPfxWordB[6], opCmdWordB[11: 8]};
	opRegM_Ce = {2'b00, opPfxWordB[5], opCmdWordB[ 7: 4]};
	opRegO_Ce = {2'b00, opPfxWordB[4], opCmdWordB[ 3: 0]};
	opRegT_Ce = {2'b00, opPfxWordB[4], opPfxWordB[ 3: 0]};

	opRegN_Cf = {2'b00, opPfxWordB[7], opCmdWordB[11: 8]};
	opRegM_Cf = {2'b00, opPfxWordB[6], opCmdWordB[ 7: 4]};

	opRegN_FR  = {2'b10, opPfxWordB[6], opCmdWordB[11: 8]};
	opRegM_FR  = {2'b10, opPfxWordB[5], opCmdWordB[ 7: 4]};
	opRegT_FR  = {2'b10, opPfxWordB[4], opPfxWordB[ 3: 0]};

	opImm6_SxCE	= {opPfxWordB[5] ? 26'h3FFFFFF : 26'h0, opPfxWordB[ 5:0]};
	opImm6_ZxCE	= {26'h0000000, opPfxWordB[ 5:0]};
	opImm6_NxCE	= {26'h3FFFFFF, opPfxWordB[ 5:0]};

	opImmM10_SxCE	= {opPfxWordB[5] ? 22'h3FFFFF : 22'h0,
		opPfxWordB[ 5:0], opCmdWordB[ 7:4]};
	opImmO10_SxCE	= {opPfxWordB[5] ? 22'h3FFFFF : 22'h0,
		opPfxWordB[ 5:0], opCmdWordB[ 3:0]};

//	opImm16_Sx8E	= {opPfxWordB[7] ? 16'hFFFF : 16'h0000,
//		opPfxWordB[ 7:0], opCmdWordB[ 7:0]};
	opImm20_Sx8E	= {opPfxWordB[7] ? 12'hFFF : 12'h000,
		opPfxWordB[ 7:0], opCmdWordB[11:0]};

	opImm15_SxCE	= {opPfxWordB[6] ? 17'h1FFFF : 17'h00000,
		opPfxWordB[ 6:0], opCmdWordB[ 7:0]};

	opImm4_ZxXE = {28'h000000, opPfxWordB[ 3:0]};

	opRegN=UREG_ZZR;
	opRegS=UREG_ZZR;
	opRegT=UREG_ZZR;

	case(tOpDecXfrmB)

		UXFORM_CST: begin
		end

		UXFORM_N: begin
			opRegN=opRegN_Ce;
			opRegS=opRegN;
		end

		UXFORM_MOV_NS: begin
			opRegN	= opRegN_Cf;	opRegS	= opRegM_Cf;
			opImm	= opImm6_ZxCE;
		end

		UXFORM_MOV_NSO: begin
			opRegN=opRegN_Ce;	opRegS=opRegM_Ce;
			opRegT=opRegT_Ce;	opImm=0;
		end

		UXFORM_MOV_NSJ: begin
			opRegN = opRegN_Ce;	opRegS = opRegM_Ce;
			opRegT = opRegO_Ce;	opImm  = opImm4_ZxXE;
		end

//		UXFORM_FPARI_NS: begin
//			opRegN=opRegN_FR;
//			opRegS=opRegM_FR;
//		end

		UXFORM_ARI_NS: begin
			opRegN=opRegN_Ce;
			opRegS=opRegM_Ce;
		end

		UXFORM_ARI_NST: begin
			opRegN=opRegN_Cf;	opRegS=opRegM_Cf;
			opRegT=UREG_MR_IMM;
			case(tOpDecXfrmZxB)
				UXFORMZX_SX: opImm=opImm6_SxCE;
				UXFORMZX_ZX: opImm=opImm6_ZxCE;
				UXFORMZX_NX: opImm=opImm6_NxCE;
				default: begin opImm=UV32_XX; end
			endcase
		end

		UXFORM_CMP_ST: begin
			opRegS=opRegN_Cf;
			opRegT=UREG_MR_IMM;
			opImm=opImmM10_SxCE;
		end

		UXFORM_ARI_ST: begin
			opRegN=opRegN_Ce;
			opRegS=opRegM_Ce;
		end

		UXFORM_ARI_NNI: begin
			opRegN=opRegN_Cf;
			opRegS=opRegN_Cf;
			opRegT=UREG_MR_IMM;	opImm=opImm15_SxCE;
		end
		
		UXFORM_BR_D8: begin
			opImm = opImm15_SxCE;
		end
//		UXFORM_BR_D12: begin
//			opImm = opImm20_Sx8E;
//		end

		UXFORM_ARI_I8R0: begin
			opRegN=opRegM_Ce;	opRegS=opRegM_Ce;
			opRegT=UREG_MR_IMM;	opImm=opImmO10_SxCE;
		end

		UXFORM_N_C: begin
			opRegN=opRegN_Ce;	opRegS=opRegN_Ce;
			opRegT=UREG_MR_IMM;
		end
		
		UXFORM_MOV_GD8R0_RM: begin
			opRegN=UREG_GBR;	opRegS=opRegM_Cf;
			opRegT=UREG_MR_IMM;	opImm=opImmO10_SxCE;
		end

		UXFORM_MOV_GD8R0_MR: begin
			opRegN=opRegM_Cf;	opRegS=UREG_GBR;
			opRegT=UREG_MR_IMM;	opImm=opImmO10_SxCE;
		end
		
		UXFORM_FPARI_NST_8E: begin
			opRegN=opRegN_FR;
			opRegS=opRegM_FR;
			opRegT=opRegT_FR;
		end

		UXFORM_NST_8E: begin
			opRegN=opRegN_Ce;
			opRegS=opRegM_Ce;
			opRegT=opRegT_Ce;
			opImm=0;
		end
		
		UXFORM_I20R0_XE: begin
			opRegN=UREG_R0;		opRegS=UREG_R0;
			opRegT=UREG_MR_IMM;	opImm=opImm15_SxCE;
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


always @(posedge clock)
begin

	if(decTwoStage)
	begin
		/* Two Stage Decode */
		opPfxWordB		<= opPfxWordA;
		opCmdWordB		<= opCmdWordA;
		tOpDecXfrmB		<= tOpDecXfrmA;
		tOpDecXfrmZxB	<= tOpDecXfrmZxA;
		opUCmd			<= opUCmdA;
	end

end

endmodule
