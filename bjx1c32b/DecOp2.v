/*
Instruction Word
 15: 0, First Word
 31:16, Second Word
 */

`include "CoreDefs.v"

module DecOp2(
	/* verilator lint_off UNUSED */
	clk,
	istrWord,
	regCsFl,
	idRegN,
	idRegS,
	idRegT,
	idImm,
	idStepPc,
	idUCmd
	);

input clk;				//clock
input[31:0] istrWord;	//source instruction word
input[15:0] regCsFl;	//current SR/FPSCR

output[6:0] idRegN;
output[6:0] idRegS;
output[6:0] idRegT;
output[31:0] idImm;
output[3:0] idStepPc;

output[7:0] idUCmd;

reg isOp32;
reg isOp8E;
reg[7:0] opPfxImm;
reg[15:0] opCmdWord;

reg[6:0] opRegN;
reg[6:0] opRegS;
reg[6:0] opRegT;	//Index for mem ops
reg[31:0] opImm;	//Disp for mem ops
reg[7:0] opUCmd;

assign	idRegN = opRegN;
assign	idRegS = opRegS;
assign	idRegT = opRegT;
assign	idImm = opImm;
assign	idUCmd = opUCmd;

always @ (clk)
begin

	idStepPc = 2;
	
	opPfxImm=0;
	opCmdWord=0;

	opRegN=0;
	opRegS=0;
	opRegT=0;
	opUCmd=UCMD_UDBRK;
	opImm=0;


	isOp32=0;
	isOp8E=0;
	case(istrWord[15:8])
		8'h8A: begin
			isOp32=1;
			opCmdWord=istrWord[15:0];
			
			opImm[31:24]=istrWord[7]?8'hFF:8'h00;
			opImm[23:16]=istrWord[7:0];
			opImm[15: 0]=istrWord[31:16];
		end

		8'h8E: begin
			isOp32=1;
			isOp8E=1;
			opPfxImm=istrWord[7:0];
			opCmdWord=istrWord[31:16];
		end

		default: begin
			opCmdWord=istrWord[15:0];
		end
	endcase

	if(isOp32)
		idStepPc = 4;

	case(opCmdWord[15:12])
	4'h0: begin		//0xxx
		opRegN={3'h0, opCmdWord[11:8]};
		opRegS={3'h0, opCmdWord[ 7:4]};
		opRegT=UREG_R0;

		case(opCmdWord[3:0])
			4'h0: begin		//0xx0
				/* Unimplemented, 2A */
			end

			4'h1: begin		//0xx1
				/* Unimplemented, 2A */
			end
		
			4'h2: begin		//0xx2, STC
				opUCmd=UCMD_MOV_RR;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h5, opCmdWord[ 7:4]};
			end

			4'h3: begin		//0xx3
				case(opCmdWord[7:4])

				4'h3: begin
				end

				default: begin end

				endcase
			end

			4'h4: begin		//0xx4
				opUCmd=UCMD_MOVB_RM;
			end
			4'h5: begin		//0xx5
				opUCmd=UCMD_MOVW_RM;
			end
			4'h6: begin		//0xx6
				opUCmd=UCMD_MOVL_RM;
			end

			4'h7: begin		//0xx7
				opUCmd=UCMD_ALU_DMULS;
				opRegN[6:4]=3'h0;
				opRegS[6:4]=3'h4;
			end

			4'h8: begin		//0xx8
				case(opCmdWord[7:4])

				4'h3: begin
				end

				default: begin end

				endcase
			end

			4'h9: begin		//0xx9
				case(opCmdWord[7:4])

				4'h0: begin
					opUCmd=UCMD_NONE;
				end

				4'h3: begin
				end

				default: begin end

				endcase
			end

			4'hA: begin		//0xxA
				opUCmd=UCMD_MOV_RR;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h4, opCmdWord[ 7:4]};
			end

			4'hB: begin		//0zzB
				case(opCmdWord[7:4])

				4'h0: begin		//0z0B
					opUCmd=UCMD_RTS;
				end

				4'h2: begin		//0z2B
					opUCmd=UCMD_RTE;
				end

				4'h3: begin		//0z3B
					opUCmd=UCMD_UDBRK;
					opImm=1;
					if(opCmdWord[11:8]==4'hF)
					begin
						opUCmd=UCMD_NONE;
						idStepPc=0;
					end
				end

				4'h6: begin		//0z6B
					opUCmd=UCMD_RTSN;
				end

				default: begin end

				endcase
			end

			4'hC: begin		//0xxC
				opUCmd=UCMD_MOVB_MR;
			end

			4'hD: begin		//0xxD
				opUCmd=UCMD_MOVW_MR;
			end

			4'hE: begin		//0xxE
				opUCmd=UCMD_MOVL_MR;
			end

			4'hF: begin		//0xxF
				//MAC.L
			end

			default: begin end
		endcase
	end

	4'h1: begin		//1xxx
		opRegN={3'h0, opCmdWord[11:8]};
		opRegS={3'h0, opCmdWord[ 7:4]};
		opRegT=UREG_ZZR;
		opImm[3:0]=opCmdWord[ 3:0];
		opUCmd=UCMD_MOVL_RM;
	end

	4'h2: begin		//2xxx
		case(opCmdWord[3:0])
			4'h0: begin		//2xx0
				opUCmd=UCMD_MOVB_RM;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[ 7:4]};
				opRegT=UREG_ZZR;
			end
			4'h1: begin		//2xx1
				opUCmd=UCMD_MOVW_RM;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[ 7:4]};
				opRegT=UREG_ZZR;
			end
			4'h2: begin		//2xx2
				opUCmd=UCMD_MOVL_RM;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[ 7:4]};
				opRegT=UREG_ZZR;
			end

			4'h4: begin		//2xx4
				opUCmd=UCMD_MOVB_RM;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[ 7:4]};
				opRegT=UREG_MR_MEMDEC;
			end
			4'h5: begin		//2xx5
				opUCmd=UCMD_MOVW_RM;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[ 7:4]};
				opRegT=UREG_MR_MEMDEC;
			end
			4'h6: begin		//2xx6
				opUCmd=UCMD_MOVL_RM;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[ 7:4]};
				opRegT=UREG_MR_MEMDEC;
			end

			4'h8: begin		//2xx8
				opUCmd=UCMD_CMP_TST;
				opRegT={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[ 7:4]};
			end

			4'h9: begin		//2xx9
				opUCmd=UCMD_ALU_AND;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[ 7:4]};
				opRegT={3'h0, opCmdWord[11:8]};
			end

			4'hA: begin		//2xxA
				opUCmd=UCMD_ALU_XOR;
				opRegT=opRegN;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[ 7:4]};
				opRegT={3'h0, opCmdWord[11:8]};
			end

			4'hB: begin		//2xxB
				opUCmd=UCMD_ALU_OR;
				opRegT=opRegN;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[ 7:4]};
				opRegT={3'h0, opCmdWord[11:8]};
			end


			4'hE: begin		//2xxE
				opUCmd=UCMD_ALU_MULUW;
				opRegT={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[ 7:4]};
			end

			4'hF: begin		//2xxF
				opUCmd=UCMD_ALU_MULSW;
				opRegT={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[ 7:4]};
			end

			default: begin end
		endcase
	end

	4'h3: begin		//3xxx
		opRegN[3:0]=opCmdWord[11:8];
		opRegS[3:0]=opCmdWord[ 7:4];
		opRegT=UREG_ZZR;

		case(opCmdWord[3:0])
			4'h0: begin		//3xx0
				opUCmd=UCMD_CMP_EQ;
				opRegS={3'h0, opCmdWord[11:8]};
				opRegT={3'h0, opCmdWord[ 7:4]};
			end

			4'h2: begin		//3xx2
				opUCmd=UCMD_CMP_HS;
				opRegS={3'h0, opCmdWord[11:8]};
				opRegT={3'h0, opCmdWord[ 7:4]};
			end
			4'h3: begin		//3xx3
				opUCmd=UCMD_CMP_GE;
				opRegS={3'h0, opCmdWord[11:8]};
				opRegT={3'h0, opCmdWord[ 7:4]};
			end


			4'h5: begin		//3xx5
				opUCmd=UCMD_ALU_DMULU;
				opRegS={3'h0, opCmdWord[11:8]};
				opRegT={3'h0, opCmdWord[ 7:4]};
			end

			4'h6: begin		//3xx6
				opUCmd=UCMD_CMP_HI;
				opRegS={3'h0, opCmdWord[11:8]};
				opRegT={3'h0, opCmdWord[ 7:4]};
			end
			4'h7: begin		//3xx7
				opUCmd=UCMD_CMP_GT;
				opRegS={3'h0, opCmdWord[11:8]};
				opRegT={3'h0, opCmdWord[ 7:4]};
			end

			4'h8: begin		//3xx8
				opUCmd=UCMD_ALU_SUB;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[11:8]};
				opRegT={3'h0, opCmdWord[ 7:4]};
			end


			4'hA: begin		//3xxA
				opUCmd=UCMD_ALU_SUBC;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[11:8]};
				opRegT={3'h0, opCmdWord[ 7:4]};
			end

			4'hB: begin		//3xxB
				opUCmd=UCMD_ALU_SUBV;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[11:8]};
				opRegT={3'h0, opCmdWord[ 7:4]};
			end

			4'hC: begin		//3xxC
				opUCmd=UCMD_ALU_ADD;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[11:8]};
				opRegT={3'h0, opCmdWord[ 7:4]};
			end

			4'hD: begin		//3xxD
				opUCmd=UCMD_ALU_DMULS;
				opRegS={3'h0, opCmdWord[11:8]};
				opRegT={3'h0, opCmdWord[ 7:4]};
			end

			4'hE: begin		//3xxE
				opUCmd=UCMD_ALU_ADDC;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[11:8]};
				opRegT={3'h0, opCmdWord[ 7:4]};
			end

			4'hF: begin		//3xxF
				opUCmd=UCMD_ALU_ADDV;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[11:8]};
				opRegT={3'h0, opCmdWord[ 7:4]};
			end

			default: begin end

		endcase
	end

	4'h4: begin		//4xxx
		opRegN={3'h0, opCmdWord[11:8]};
		opRegS={3'h0, opCmdWord[ 7:4]};
		opRegT=UREG_ZZR;

		case(opCmdWord[3:0])
			4'h0: begin		//4xx0
			end

			4'hB: begin		//4xxB
				opRegS={3'h0, opCmdWord[11:8]};
				
				case(opCmdWord[7:4])

				4'h0: begin
					opUCmd=UCMD_JSR;
				end

				4'h2: begin
					opUCmd=UCMD_JMP;
				end

				4'h3: begin
				end

				4'h4: begin
					opUCmd=UCMD_JSRN;
				end

				default: begin end

				endcase
			end

			4'hC: begin		//4xxC
				opUCmd=UCMD_ALU_SHAD;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[11:8]};
				opRegT={3'h0, opCmdWord[ 7:4]};
			end

			4'hD: begin		//4xxD
				opUCmd=UCMD_ALU_SHLD;
				opRegN={3'h0, opCmdWord[11:8]};
				opRegS={3'h0, opCmdWord[11:8]};
				opRegT={3'h0, opCmdWord[ 7:4]};
			end

			default: begin end
		endcase
	end

	4'h5: begin		//5xxx
		opRegN={3'h0, opCmdWord[11:8]};
		opRegS={3'h0, opCmdWord[ 7:4]};
		opRegT=UREG_ZZR;
		opImm[3:0]=opCmdWord[ 3:0];
		opUCmd=UCMD_MOVL_MR;
	end

	4'h6: begin		//6xxx
		opRegN={3'h0, opCmdWord[11:8]};
		opRegS={3'h0, opCmdWord[ 7:4]};
		opRegT=UREG_ZZR;

		case(opCmdWord[3:0])
			4'h0: begin		//4xx0
			end

			default: begin end
		endcase
	end

	4'h7: begin		//7xxx
		opRegN={3'h0, opCmdWord[11:8]};
		opRegS={3'h0, opCmdWord[11:8]};
		opRegT=UREG_MR_IMM;
		opImm[7:0]=opCmdWord[ 7:0];
		opImm[31:8]=opCmdWord[7]?24'hFFFFFF:24'h000000;
		opUCmd=UCMD_ALU_ADD;
	end

	4'h8: begin		//8xxx
//		opRegN[3:0]=opCmdWord[11:8];
//		opRegS[3:0]=opCmdWord[ 7:4];
//		opRegT=UREG_ZZR;

		opRegN=UREG_ZZR;
		opRegS=UREG_ZZR;
		opRegT=UREG_ZZR;

		case(opCmdWord[11:8])
			4'h0: begin		//80xx
			end

			4'h2: begin		//82xx
				opImm[7:0]=opCmdWord[7:0];
				opImm[31:8]=opCmdWord[7]?24'hFFFFFF:24'h000000;
				opUCmd=UCMD_BRAN;
			end

			4'h9: begin		//89xx
				opImm[7:0]=opCmdWord[7:0];
				opImm[31:8]=opCmdWord[7]?24'hFFFFFF:24'h000000;
				opUCmd=UCMD_BT;
			end

			4'hA: begin		//8Axx-xxxx
				opRegN=UREG_R0;
//				opRegS=UREG_MR_IMM;
//				opRegT=UREG_MR_IMM;
				opUCmd=UCMD_MOV_RI;
			end

			4'hB: begin		//8Bxx
				opImm[7:0]=opCmdWord[7:0];
				opImm[31:8]=opCmdWord[7]?24'hFFFFFF:24'h000000;
				opUCmd=UCMD_BF;
			end

			4'hD: begin		//89xx
				opImm[7:0]=opCmdWord[7:0];
				opImm[31:8]=opCmdWord[7]?24'hFFFFFF:24'h000000;
				opUCmd=UCMD_BTS;
			end

			4'hF: begin		//8Bxx
				opImm[7:0]=opCmdWord[7:0];
				opImm[31:8]=opCmdWord[7]?24'hFFFFFF:24'h000000;
				opUCmd=UCMD_BFS;
			end

			default: begin end
		endcase
	end

	4'h9: begin		//9xxx
		opRegN[3:0]=opCmdWord[11:8];
		opRegS=UREG_PCW;
		opRegT=UREG_ZZR;
		opImm[7:0]=opCmdWord[ 7:0];
		opUCmd=UCMD_MOVW_MR;
	end

	4'hA: begin		//Axxx
		opImm[11:0]=opCmdWord[11:0];
		opImm[31:12]=opCmdWord[11]?20'hFFFFF:20'h00000;
		opUCmd=UCMD_BRA;
	end

	4'hB: begin		//Bxxx
		opImm[11:0]=opCmdWord[11:0];
		opImm[31:12]=opCmdWord[11]?20'hFFFFF:20'h00000;
		opUCmd=UCMD_BSR;
	end

	4'hC: begin		//Cxxx
//		opRegN[3:0]=opCmdWord[11:8];
//		opRegS[3:0]=opCmdWord[ 7:4];
//		opRegT=UREG_ZZR;

		case(opCmdWord[11:8])
			4'h0: begin		//C0xx
			end

			default: begin end
		endcase
	end

	4'hD: begin		//Dxxx
		opRegN[3:0]=opCmdWord[11:8];
		opRegS=UREG_PCL;
		opRegT=UREG_ZZR;
		opImm[7:0]=opCmdWord[ 7:0];
		opUCmd=UCMD_MOVL_MR;
	end


	4'hE: begin		//Exxx
		opRegN[3:0]=opCmdWord[11:8];
		opRegS[3:0]=opCmdWord[11:8];
		opRegT=UREG_MR_IMM;
		opImm[7:0]=opCmdWord[ 7:0];
		opImm[31:8]=opCmdWord[7]?24'hFFFFFF:24'h000000;
		opUCmd=UCMD_MOV_RI;
	end


	4'hF: begin		//Fxxx
		opRegN[3:0]=opCmdWord[11:8];
		opRegS[3:0]=opCmdWord[ 7:4];
		opRegT=UREG_ZZR;

		case(opCmdWord[3:0])
			4'h0: begin		//4xx0
			end

			default: begin end
		endcase
	end


	default: begin end

	endcase
end

endmodule
