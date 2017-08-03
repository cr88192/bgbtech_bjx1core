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

initial begin
	$readmemh("uopidx.txt", uopPcIdx);
	$readmemh("uoppgm.txt", uopPgm);
end

reg[6:0] tIdRegD;
reg[6:0] tIdRegS;
reg[6:0] tIdRegT;

always @ (clk)
begin

	uopUseIdx=0;

	tIdRegD[6:0]=0;
	tIdRegS[6:0]=0;
	tIdRegT[6:0]=0;
	idImm[31:0]=32'h0;
	idStepPc=2'h1;

	idUopPc[11:0]=12'h0;
	idUopWord[31:0]=32'h0;

	case(istrWord[15:12])
	4'h0:
	begin
		tIdRegD[3:0]=istrWord[7:4];
		tIdRegS[3:0]=istrWord[7:4];
		tIdRegT[3:0]=istrWord[3:0];

		case(istrWord[11:8])
			4'h0:	idUopWord[31:24]=UOP_ADDI;
			4'h1:	idUopWord[31:24]=UOP_SUBI;
			4'h2:	idUopWord[31:24]=UOP_MULI;
			4'h3:	idUopWord[31:24]=UOP_ANDI;
			4'h4:	idUopWord[31:24]=UOP_ORI;
			4'h5:	idUopWord[31:24]=UOP_XORI;
			4'h6:	idUopWord[31:24]=UOP_SHLI;
			4'h7:	idUopWord[31:24]=UOP_SARI;

			4'hE:
			begin
				idRegD[5:4]=2'b11;
				idRegS[6:0]=7'h7F;
				idUopWord[31:24]=UOP_ADDI;
			end

			4'hF:
			begin
				idRegT[5:4]=2'b11;
				idRegS[6:0]=7'h7F;
				idUopWord[31:24]=UOP_ADDI;
			end

			default:
			begin
			end
		endcase
	end
	default:
	begin
		idRegD[6:0]=7'h7F;
		idRegS[6:0]=7'h7F;
		idRegT[6:0]=7'h7F;
		idImm[31:0]=32'h0;
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

//	idRegD=tIdRegD;
//	idRegS=tIdRegS;
//	idRegT=tIdRegT;
end

endmodule