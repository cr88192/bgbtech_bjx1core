/*
Instruction Word
 15: 0, First Word
 31:16, Second Word
 */

module DecOp(
	clk,
	istrWord,
	regCurSr,
	idRegD,
	idRegS,
	idRegT,
	idImm,
	idStepPc,
	idUopPc,
	idUopWord
	);

input clk;				//clock
input[31:0] istrWord;	//source instruction word
input[31:0] regCurSr;	//current SR

output[6:0] idRegD;
output[6:0] idRegS;
output[6:0] idRegT;
output[31:0] idImm;
output[1:0] idStepPc;

output[11:0] idUopPc;
output[31:0] idUopWord;

reg[11:0] uopPcIdx[256];
reg[31:0] uopPgm[4096];

reg[7:0] uopUseIdx;

reg srIsDq;

initial begin
	$readmemh("uopidx.txt", uopPcIdx);
	$readmemh("uoppgm.txt", uopPgm);
end

reg opIs32p;

reg[6:0] tIdRegD;
reg[6:0] tIdRegS;
reg[6:0] tIdRegT;
reg[31:0] tIdImm;

always @ (clk)
begin

	opIs32p =
		((istrWord[15:12]==0) && (istrWord[3:1]==0)) ||
		((istrWord[15:12]==3) && ((istrWord[3:0]==1) || (istrWord[3:0]==9))) ||
		((istrWord[15:12]==15) && (istrWord[3:0]==15)) ||
		((istrWord[15:12]==8)&& ((istrWord[3:0]==10) ||
			(istrWord[3:0]==12) || (istrWord[3:0]==14))) ;

	uopUseIdx=0;

	tIdRegD[6:0]=0;
	tIdRegS[6:0]=0;
	tIdRegT[6:0]=0;
	tIdImm[31:0]=32'h0;
	idStepPc=opIs32p ? 2'h2 : 2'h1;

	idUopPc[11:0]=12'h0;
	idUopWord[31:0]=32'h0;
	idUopWord[23]=1;

	srIsDq = regCurSr[12];

	case(istrWord[15:12])
	4'h0:
	begin
//		tIdRegD[3:0]=istrWord[7:4];
//		tIdRegS[3:0]=istrWord[7:4];
//		tIdRegT[3:0]=istrWord[3:0];

		case(istrWord[3:0])
			4'h8:
			begin
				idUopWord[31:24]=UOP_FWOP;
				idUopWord[23:16]=8'b1010_0001;
				idUopWord[15: 0]=istrWord[15: 0];
			end

			4'h9:
			begin
				tIdRegD[3:0]=istrWord[11:8];
				tIdRegS[3:0]=istrWord[11:8];
				tIdRegT[3:0]=istrWord[11:8];
				idUopWord[31:24]=UOP_FWOP;
				idUopWord[23:16]=8'b1010_0001;
				idUopWord[15: 0]=istrWord[15: 0];
			end

			4'hB:
			begin
				tIdRegD[3:0]=istrWord[11:8];
				tIdRegS[3:0]=istrWord[11:8];
				tIdRegT[3:0]=istrWord[11:8];
				idUopWord[31:24]=UOP_FWOP;
				idUopWord[23:16]=8'b1010_0001;
				idUopWord[15: 0]=istrWord[15: 0];
			end

			4'hC:
			begin
				tIdRegD[3:0]=istrWord[11:8];
				tIdRegS[3:0]=istrWord[ 7:4];
				tIdRegT=REG_R0;
				idUopWord[31:24]=UOP_MOVLDB;
			end

			4'hD:
			begin
				tIdRegD[3:0]=istrWord[11:8];
				tIdRegS[3:0]=istrWord[ 7:4];
				tIdRegT=REG_R0;
				idUopWord[31:24]=srIsDq ? UOP_MOVLDQ : UOP_MOVLDW;
			end

			4'hE:
			begin
				tIdRegD[3:0]=istrWord[11:8];
				tIdRegS[3:0]=istrWord[ 7:4];
				tIdRegT=REG_R0;
				idUopWord[31:24]=UOP_MOVLDI;
			end

			default:
			begin
			end
		endcase
	end

	4'h1:
	begin
		tIdRegD[3:0]=istrWord[ 7:4];
		tIdRegS[3:0]=istrWord[11:8];
		tIdRegT=REG_ZZR;
		tIdImm[3:0]=istrWord[3:0];
		idUopWord[31:24]=UOP_MOVSTI;
	end
	
	4'h2:
	begin
		tIdRegD[3:0]=istrWord[11:8];
		tIdRegS[3:0]=istrWord[11:8];
		tIdRegT[3:0]=istrWord[ 7:4];

		case(istrWord[3:0])
			4'h0:	idUopWord[31:24]=UOP_MOVSTB;
			4'h1:	idUopWord[31:24]=UOP_MOVSTW;
			4'h2:	idUopWord[31:24]=UOP_MOVSTI;
//			4'h3:	idUopWord[31:24]=
//			4'h4:	idUopWord[31:24]=
//			4'h5:	idUopWord[31:24]=
//			4'h6:	idUopWord[31:24]=
//			4'h7:	idUopWord[31:24]=
//			4'h8:	idUopWord[31:24]=
//			4'hC:	idUopWord[31:24]=srIsDq?UOP_ADDQ:UOP_ADDI;
//			4'hE:	idUopWord[31:24]=srIsDq?UOP_ADDCQ:UOP_ADDCI;

			default:
			begin
			end
		endcase
	end

	4'h3:
	begin
		tIdRegD[3:0]=istrWord[11:8];
		tIdRegS[3:0]=istrWord[11:8];
		tIdRegT[3:0]=istrWord[ 7:4];

		case(istrWord[3:0])
			4'h0:	idUopWord[31:24]=srIsDq?UOP_CMPEQQ:UOP_CMPEQI;
//			4'h1:	idUopWord[31:24]=
			4'h2:	idUopWord[31:24]=srIsDq?UOP_CMPHSQ:UOP_CMPHSI;
			4'h3:	idUopWord[31:24]=srIsDq?UOP_CMPGEQ:UOP_CMPGEI;
//			4'h4:	idUopWord[31:24]=
//			4'h5:	idUopWord[31:24]=
			4'h6:	idUopWord[31:24]=srIsDq?UOP_CMPHIQ:UOP_CMPHII;
			4'h7:	idUopWord[31:24]=srIsDq?UOP_CMPGTQ:UOP_CMPGTI;
			4'h8:	idUopWord[31:24]=srIsDq?UOP_SUBQ:UOP_SUBI;
//			4'h9:	idUopWord[31:24]=
//			4'hA:	idUopWord[31:24]=
//			4'hB:	idUopWord[31:24]=
			4'hC:	idUopWord[31:24]=srIsDq?UOP_ADDQ:UOP_ADDI;
//			4'hD:	idUopWord[31:24]=
			4'hE:	idUopWord[31:24]=srIsDq?UOP_ADDCQ:UOP_ADDCI;
//			4'hF:	idUopWord[31:24]=
			default:
			begin
			end
		endcase
	end

	4'h5:
	begin
		tIdRegD[3:0]=istrWord[11:8];
		tIdRegS[3:0]=istrWord[ 7:4];
		tIdRegT=REG_ZZR;
		tIdImm[3:0]=istrWord[3:0];
		idUopWord[31:24]=UOP_MOVLDI;
	end

	4'h6:
	begin
		tIdRegD[3:0]=istrWord[11:8];
		tIdRegS[3:0]=istrWord[11:8];
		tIdRegT[3:0]=istrWord[ 7:4];

		case(istrWord[3:0])
			4'h0:	idUopWord[31:24]=UOP_MOVLDB;
			4'h1:	idUopWord[31:24]=UOP_MOVLDW;
			4'h2:	idUopWord[31:24]=UOP_MOVLDI;
			4'h3:	idUopWord[31:24]=srIsDq?UOP_MOVQ:UOP_MOVI;
//			4'h4:	idUopWord[31:24]=
//			4'h5:	idUopWord[31:24]=
//			4'h6:	idUopWord[31:24]=
//			4'h7:	idUopWord[31:24]=
//			4'h8:	idUopWord[31:24]=
//			4'hC:	idUopWord[31:24]=srIsDq?UOP_ADDQ:UOP_ADDI;
//			4'hE:	idUopWord[31:24]=srIsDq?UOP_ADDCQ:UOP_ADDCI;
//			4'hF:	idUopWord[31:24]=

			default:
			begin
			end
		endcase
	end

	4'h7:
	begin
		tIdRegD[3:0]=istrWord[11:8];
		tIdRegS[3:0]=istrWord[11:8];
		tIdRegT[6:0]=REG_IMM;
		tIdImm[31:8]=istrWord[7] ? 24'hFFFFFF : 24'h000000 ;
		tIdImm[ 7:0]=istrWord[7:0];
		idUopWord[31:24]=srIsDq?UOP_ADDQ:UOP_ADDI;
	end
	
	4'hA:
	begin
		tIdRegD=REG_ZZR;
		tIdRegS=REG_ZZR;
		tIdRegT=REG_IMM;
		tIdImm[31:12]=istrWord[7] ? 20'hFFFFF : 20'h00000 ;
		tIdImm[11:0]=istrWord[11:0];
		idUopWord[31:24]=UOP_JMP;
	end

	4'hB:
	begin
		tIdRegD=REG_ZZR;
		tIdRegS=REG_ZZR;
		tIdRegT=REG_IMM;
		tIdImm[31:12]=istrWord[7] ? 20'hFFFFF : 20'h00000 ;
		tIdImm[11:0]=istrWord[11:0];
		idUopWord[31:24]=UOP_JSR;
	end


	4'hE:
	begin
		tIdRegD[3:0]=istrWord[11:8];
		tIdRegS=REG_IMM;
		tIdRegT=REG_IMM;
		tIdImm[31:8]=istrWord[7] ? 24'hFFFFFF : 24'h000000 ;
		tIdImm[ 7:0]=istrWord[7:0];
		idUopWord[31:24]=srIsDq?UOP_MOVQ:UOP_MOVI;
	end
	

	default:
	begin
		tIdRegD[6:0]=7'h7F;
		tIdRegS[6:0]=7'h7F;
		tIdRegT[6:0]=7'h7F;
		tIdImm[31:0]=32'h0;
		idStepPc=2'h1;
	end
	endcase
	
	if(uopUseIdx!=0)
	begin
		idUopPc=uopPcIdx[uopUseIdx];
		idUopWord=uopPgm[idUopPc];
	end
	
	idRegD=tIdRegD ^
		((regCurSr[29] && (tIdRegD[6:3]==4'h0)) ? 7'h58 : 7'h00);
	idRegS=tIdRegS ^
		((regCurSr[29] && (tIdRegS[6:3]==4'h0)) ? 7'h58 : 7'h00);
	idRegT=tIdRegT ^
		((regCurSr[29] && (tIdRegT[6:3]==4'h0)) ? 7'h58 : 7'h00);
	idImm=tIdImm;

//	idRegD=tIdRegD;
//	idRegS=tIdRegS;
//	idRegT=tIdRegT;
end

endmodule