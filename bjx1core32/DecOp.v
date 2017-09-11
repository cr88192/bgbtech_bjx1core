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
output[3:0] idStepPc;

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
reg op2Is32p;

reg[6:0] tIdRegD;
reg[6:0] tIdRegS;
reg[6:0] tIdRegT;
reg[31:0] tIdImm;

reg[3:0] tIdStepPc;
assign idStepPc = tIdStepPc;

reg[15:0]	tInstWord1;
reg[15:0]	tInstWord2;
reg[7:0]	tInstPfxOp;

reg opIs8Ep;

always @ (clk)
begin

	opIs32p =
		((istrWord[15:12]==0) && (istrWord[3:1]==0)) ||
		((istrWord[15:12]==3) && ((istrWord[3:0]==1) || (istrWord[3:0]==9))) ||
		((istrWord[15:12]==15) && (istrWord[3:0]==15)) ||
		((istrWord[15:12]==8)&& ((istrWord[3:0]==10) ||
			(istrWord[3:0]==12) || (istrWord[3:0]==14))) ;

	if(istrWord[15:8]==8'h8E)
	begin
		tInstWord1=istrWord[31:16];
		tInstPfxOp=istrWord[ 7: 0];
		opIs8Ep=1;
	end
	else
	begin
		tInstWord1=istrWord[15:0];
		tInstPfxOp=0;
		opIs8Ep=0;
	end

	if(opIs32p)
		tInstWord2=istrWord[47:32];
	else
		tInstWord2=istrWord[31:16];

	op2Is32p =
		((tInstWord2[15:12]==0) && (tInstWord2[3:1]==0)) ||
		((tInstWord2[15:12]==3) && ((tInstWord2[3:0]==1) ||
			(tInstWord2[3:0]==9))) ||
		((tInstWord2[15:12]==15) && (tInstWord2[3:0]==15)) ||
		((tInstWord2[15:12]==8)&& ((tInstWord2[3:0]==10) ||
			(tInstWord2[3:0]==12) || (tInstWord2[3:0]==14))) ;

	uopUseIdx=0;

	tIdRegD[6:0]=0;
	tIdRegS[6:0]=0;
	tIdRegT[6:0]=0;
	tIdImm[31:0]=32'h0;
	tIdStepPc[1:0]=opIs32p ? 2'h2 : 2'h1;
	tIdStepPc[3:2]=op2Is32p ? 2'h2 : 2'h1;
//	if(istrWord==0)
//		tIdStepPc[1:0] = 1;

	idUopPc[11:0]=12'h0;
	idUopWord[31:0]=32'h0;
//	idUopWord[23]=1;
	idUopWord[23]=0;

	idUopWord[31:24]=UOP_FWOP;

	srIsDq = regCurSr[12];

	case(tInstWord1[15:12])
	4'h0:
	begin
//		tIdRegD[3:0]=istrWord[7:4];
//		tIdRegS[3:0]=istrWord[7:4];
//		tIdRegT[3:0]=istrWord[3:0];

		case(tInstWord1[3:0])
			4'h2:
			begin
				tIdRegS=REG_CC0;
				tIdRegD[3:0]=tInstWord1[11:8];
				tIdRegS[3:0]=tInstWord1[ 7:4];
				tIdRegT=REG_ZZR;
				idUopWord[31:24]=UOP_MOVI;
			end

			4'h8:
			begin
				idUopWord[31:24]=UOP_FWOP;
				idUopWord[23:16]=8'b0010_0001;
				idUopWord[15: 0]=tInstWord1[15: 0];
			end

			4'h9:
			begin
				tIdRegD[3:0]=tInstWord1[11:8];
				tIdRegS[3:0]=tInstWord1[11:8];
				tIdRegT[3:0]=tInstWord1[11:8];
				idUopWord[31:24]=UOP_FWOP;
				idUopWord[23:16]=8'b0010_0001;
				idUopWord[15: 0]=tInstWord1[15: 0];
			end

			4'hA:
			begin
				tIdRegS=REG_CS0;
				tIdRegD[3:0]=tInstWord1[11:8];
				tIdRegS[3:0]=tInstWord1[ 7:4];
				tIdRegT=REG_ZZR;
				idUopWord[31:24]=UOP_MOVI;
			end

			4'hB:
			begin
				tIdRegD[3:0]=tInstWord1[11:8];
				tIdRegS[3:0]=tInstWord1[11:8];
				tIdRegT[3:0]=tInstWord1[11:8];
				idUopWord[31:24]=UOP_FWOP;
				idUopWord[23:16]=8'b0010_0001;
				idUopWord[15: 0]=tInstWord1[15: 0];
			end

			4'hC:
			begin
				tIdRegD[3:0]=tInstWord1[11:8];
				tIdRegS[3:0]=tInstWord1[ 7:4];
				tIdRegT=REG_R0;
				idUopWord[31:24]=UOP_MOVLDB;
			end

			4'hD:
			begin
				tIdRegD[3:0]=tInstWord1[11:8];
				tIdRegS[3:0]=tInstWord1[ 7:4];
				tIdRegT=REG_R0;
				idUopWord[31:24]=UOP_MOVLDW;
			end

			4'hE:
			begin
				tIdRegD[3:0]=tInstWord1[11:8];
				tIdRegS[3:0]=tInstWord1[ 7:4];
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
		tIdRegD[3:0]=tInstWord1[ 7:4];
		tIdRegS[3:0]=tInstWord1[11:8];
		tIdRegT=REG_ZZR;
		tIdImm[3:0]=tInstWord1[3:0];
		idUopWord[31:24]=UOP_MOVSTI;
	end
	
	4'h2:
	begin
		tIdRegD[3:0]=tInstWord1[11:8];
		tIdRegS[3:0]=tInstWord1[11:8];
		tIdRegT[3:0]=tInstWord1[ 7:4];

		case(istrWord[3:0])
			4'h0:	idUopWord[31:24]=UOP_MOVSTB;
			4'h1:	idUopWord[31:24]=UOP_MOVSTW;
			4'h2:	idUopWord[31:24]=UOP_MOVSTI;

			4'h8:	idUopWord[31:24]=UOP_TESTI;
			4'h9:	idUopWord[31:24]=UOP_ANDI;
			4'hA:	idUopWord[31:24]=UOP_XORI;
			4'hB:	idUopWord[31:24]=UOP_ORI;

			default:
			begin
			end
		endcase
	end

	4'h3:
	begin
		tIdRegD[3:0]=tInstWord1[11:8];
		tIdRegS[3:0]=tInstWord1[11:8];
		tIdRegT[3:0]=tInstWord1[ 7:4];

		case(istrWord[3:0])
			4'h0:	idUopWord[31:24]=UOP_CMPEQI;
//			4'h1:	idUopWord[31:24]=
			4'h2:	idUopWord[31:24]=UOP_CMPHSI;
			4'h3:	idUopWord[31:24]=UOP_CMPGEI;
//			4'h4:	idUopWord[31:24]=
//			4'h5:	idUopWord[31:24]=
			4'h6:	idUopWord[31:24]=UOP_CMPHII;
			4'h7:	idUopWord[31:24]=UOP_CMPGTI;
			4'h8:	idUopWord[31:24]=UOP_SUBI;
//			4'h9:	idUopWord[31:24]=
			4'hA:	idUopWord[31:24]=UOP_SUBCI;
			4'hB:	idUopWord[31:24]=UOP_SUBVI;
			4'hC:	idUopWord[31:24]=UOP_ADDI;
//			4'hD:	idUopWord[31:24]=
			4'hE:	idUopWord[31:24]=UOP_ADDCI;
			4'hF:	idUopWord[31:24]=UOP_ADDVI;
			default:
			begin
			end
		endcase
	end

	4'h4:
	begin
//		tIdRegD[3:0]=tInstWord1[11:8];
//		tIdRegS[3:0]=tInstWord1[11:8];
//		tIdRegT[3:0]=tInstWord1[ 7:4];

		case(istrWord[3:0])
			4'hA:
			begin
				tIdRegD=REG_CS0;
				tIdRegD[3:0]=tInstWord1[ 7:4];
				tIdRegS[3:0]=tInstWord1[11:8];
				tIdRegT=REG_ZZR;
				idUopWord[31:24]=UOP_MOVI;
			end

			4'hE:
			begin
				tIdRegD=REG_CC0;
				tIdRegD[3:0]=tInstWord1[ 7:4];
				tIdRegS[3:0]=tInstWord1[11:8];
				tIdRegT=REG_ZZR;
				idUopWord[31:24]=UOP_MOVI;
			end

			default:
			begin
			end
		endcase
	end

	4'h5:
	begin
		tIdRegD[3:0]=tInstWord1[11:8];
		tIdRegS[3:0]=tInstWord1[ 7:4];
		tIdRegT=REG_ZZR;
		tIdImm[3:0]=tInstWord1[3:0];
		idUopWord[31:24]=UOP_MOVLDI;
	end

	4'h6:
	begin
		tIdRegD[3:0]=tInstWord1[11:8];
		tIdRegS[3:0]=tInstWord1[11:8];
		tIdRegT[3:0]=tInstWord1[ 7:4];

		case(istrWord[3:0])
			4'h0:	idUopWord[31:24]=UOP_MOVLDB;
			4'h1:	idUopWord[31:24]=UOP_MOVLDW;
			4'h2:	idUopWord[31:24]=UOP_MOVLDI;
			4'h3:
			begin
				tIdRegD[3:0]=tInstWord1[11:8];
				tIdRegS[3:0]=tInstWord1[ 7:4];
				tIdRegT[3:0]=REG_ZZR;
				idUopWord[31:24]=UOP_MOVI;
			end

			4'h7:
			begin
				tIdRegD[3:0]=tInstWord1[11:8];
				tIdRegS[3:0]=tInstWord1[ 7:4];
				tIdRegT[3:0]=REG_IMM;
				tIdImm[31:0]=32'hFFFF_FFFF;
				idUopWord[31:24]=UOP_XOR;
			end

			4'hA:
			begin
				tIdRegD[3:0]=tInstWord1[11:8];
				tIdRegS[3:0]=REG_ZZR;
				tIdRegT[3:0]=tInstWord1[ 7:4];
				idUopWord[31:24]=UOP_SUBI;
			end
			4'hB:
			begin
				tIdRegD[3:0]=tInstWord1[11:8];
				tIdRegS[3:0]=REG_ZZR;
				tIdRegT[3:0]=tInstWord1[ 7:4];
				idUopWord[31:24]=UOP_SUBCI;
			end

			4'hC:
			begin
				tIdRegD[3:0]=tInstWord1[11:8];
				tIdRegS[3:0]=tInstWord1[ 7:4];
				tIdRegT[3:0]=REG_IMM;
				tIdImm[31:0]=32'h0000_00FF;
				idUopWord[31:24]=UOP_AND;
			end
			4'hD:
			begin
				tIdRegD[3:0]=tInstWord1[11:8];
				tIdRegS[3:0]=tInstWord1[ 7:4];
				tIdRegT[3:0]=REG_IMM;
				tIdImm[31:0]=32'h0000_FFFF;
				idUopWord[31:24]=UOP_AND;
			end

//			4'h4:	idUopWord[31:24]=
//			4'h5:	idUopWord[31:24]=
//			4'h6:	idUopWord[31:24]=
//			4'h7:	idUopWord[31:24]=
//			4'h8:	idUopWord[31:24]=
//			4'hC:	idUopWord[31:24]=UOP_ADDI;
//			4'hE:	idUopWord[31:24]=UOP_ADDCI;
//			4'hF:	idUopWord[31:24]=

			default:
			begin
			end
		endcase
	end

	4'h7:
	begin
		tIdRegD[3:0]=tInstWord1[11:8];
		tIdRegS[3:0]=tInstWord1[11:8];
		tIdRegT[6:0]=REG_IMM;
//		tIdImm[31:8]=tInstWord1[7] ? 24'hFFFFFF : 24'h000000 ;
//		tIdImm[ 7:0]=tInstWord1[7:0];
		idUopWord[31:24]=UOP_ADDI;

		if(opIs8Ep)
		begin
			tIdImm[31:16]=tInstPfxOp[7] ? 16'hFFFF : 16'h0000 ;
			tIdImm[15:8]=tInstPfxOp[7:0];
			tIdImm[ 7:0]=tInstWord1[7:0];
		end
		else
		begin
			tIdImm[31:8]=tInstWord1[7] ? 24'hFFFFFF : 24'h000000 ;
			tIdImm[7:0]=tInstWord1[7:0];
		end
	end

	4'h8:
	begin
		case(istrWord[11:8])

		4'h9:	//BT
		begin
			tIdRegD=REG_ZZR;
			tIdRegS=REG_ZZR;
			tIdRegT=REG_IMM;
			idUopWord[31:24]=UOP_BRTF;
			idUopWord[16]=1;	//T/F	(T)
			idUopWord[17]=1;	//No DS (DS=False)

			if(opIs8Ep)
			begin
				tIdImm[31:16]=tInstPfxOp[7] ? 16'hFFFF : 16'h0000 ;
				tIdImm[15:8]=tInstPfxOp[7:0];
				tIdImm[ 7:0]=tInstWord1[7:0];
			end
			else
			begin
				tIdImm[31:8]=tInstWord1[7] ? 24'hFFFFFF : 24'h000000 ;
				tIdImm[7:0]=tInstWord1[7:0];
			end
		end

		4'hB:	//BF
		begin
			tIdRegD=REG_ZZR;
			tIdRegS=REG_ZZR;
			tIdRegT=REG_IMM;
			idUopWord[31:24]=UOP_BRTF;
			idUopWord[16]=0;	//T/F	(F)
			idUopWord[17]=1;	//No DS (DS=False)

			if(opIs8Ep)
			begin
				tIdImm[31:16]=tInstPfxOp[7] ? 16'hFFFF : 16'h0000 ;
				tIdImm[15:8]=tInstPfxOp[7:0];
				tIdImm[ 7:0]=tInstWord1[7:0];
			end
			else
			begin
				tIdImm[31:8]=tInstWord1[7] ? 24'hFFFFFF : 24'h000000 ;
				tIdImm[7:0]=tInstWord1[7:0];
			end
		end
		
		4'hD:	//BTS
		begin
			tIdRegD=REG_ZZR;
			tIdRegS=REG_ZZR;
			tIdRegT=REG_IMM;
			idUopWord[31:24]=UOP_BRTF;
			idUopWord[16]=1;	//T/F	(T)
			idUopWord[17]=0;	//No DS (DS=True)

			if(opIs8Ep)
			begin
				tIdImm[31:16]=tInstPfxOp[7] ? 16'hFFFF : 16'h0000 ;
				tIdImm[15:8]=tInstPfxOp[7:0];
				tIdImm[ 7:0]=tInstWord1[7:0];
			end
			else
			begin
				tIdImm[31:8]=tInstWord1[7] ? 24'hFFFFFF : 24'h000000 ;
				tIdImm[7:0]=tInstWord1[7:0];
			end
		end

		4'hF:	//BFS
		begin
			tIdRegD=REG_ZZR;
			tIdRegS=REG_ZZR;
			tIdRegT=REG_IMM;
			idUopWord[31:24]=UOP_BRTF;
			idUopWord[16]=0;	//T/F	(F)
			idUopWord[17]=0;	//No DS (DS=True)

			if(opIs8Ep)
			begin
				tIdImm[31:16]=tInstPfxOp[7] ? 16'hFFFF : 16'h0000 ;
				tIdImm[15:8]=tInstPfxOp[7:0];
				tIdImm[ 7:0]=tInstWord1[7:0];
			end
			else
			begin
				tIdImm[31:8]=tInstWord1[7] ? 24'hFFFFFF : 24'h000000 ;
				tIdImm[7:0]=tInstWord1[7:0];
			end
		end
		

		default:
		begin
		end
		endcase
	end

	4'h9:
	begin
		tIdRegD[3:0]=tInstWord1[11:8];
		tIdRegS=REG_PC4A2;
		tIdRegT=REG_ZZR;
		tIdImm[7:0]=tInstWord1[7:0];
		idUopWord[31:24]=UOP_MOVLDW;
	end
	
	4'hA:
	begin
		tIdRegD=REG_ZZR;
		tIdRegS=REG_ZZR;
		tIdRegT=REG_IMM;
		idUopWord[31:24]=UOP_JMP;

		if(opIs8Ep)
		begin
			tIdImm[31:20]=tInstPfxOp[7] ? 12'hFFF : 12'h000 ;
			tIdImm[19:12]=tInstPfxOp[7:0];
			tIdImm[11: 0]=tInstWord1[11:0];
		end
		else
		begin
			tIdImm[31:12]=tInstWord1[7] ? 20'hFFFFF : 20'h00000 ;
			tIdImm[11:0]=tInstWord1[11:0];
		end
	end

	4'hB:
	begin
		tIdRegD=REG_ZZR;
		tIdRegS=REG_ZZR;
		tIdRegT=REG_IMM;
		idUopWord[31:24]=UOP_JSR;

		if(opIs8Ep)
		begin
			tIdImm[31:20]=tInstPfxOp[7] ? 12'hFFF : 12'h000 ;
			tIdImm[19:12]=tInstPfxOp[7:0];
			tIdImm[11: 0]=tInstWord1[11:0];
		end
		else
		begin
			tIdImm[31:12]=tInstWord1[7] ? 20'hFFFFF : 20'h00000 ;
			tIdImm[11:0]=tInstWord1[11:0];
		end
	end

	4'hC:
	begin
		case(tInstWord1[11:8])
		default:
			begin
			end
		endcase
	end

	4'hD:
	begin
		tIdRegD[3:0]=tInstWord1[11:8];
		tIdRegS=REG_PC4A4;
		tIdRegT=REG_ZZR;
		tIdImm[7:0]=tInstWord1[7:0];
		idUopWord[31:24]=UOP_MOVLDI;
	end

	4'hE:
	begin
		tIdRegD[3:0]=tInstWord1[11:8];
//		tIdRegS=REG_IMM;
		tIdRegS=REG_ZZR;
		tIdRegT=REG_IMM;
//		tIdImm[31:8]=tInstWord1[7] ? 24'hFFFFFF : 24'h000000 ;
//		tIdImm[ 7:0]=tInstWord1[7:0];
//		idUopWord[31:24]=UOP_MOVI;
		idUopWord[31:24]=UOP_ADDI;

		if(opIs8Ep)
		begin
			tIdImm[31:16]=tInstPfxOp[7] ? 16'hFFFF : 16'h0000 ;
			tIdImm[15:8]=tInstPfxOp[7:0];
			tIdImm[ 7:0]=tInstWord1[7:0];
		end
		else
		begin
			tIdImm[31:8]=tInstWord1[7] ? 24'hFFFFFF : 24'h000000 ;
			tIdImm[7:0]=tInstWord1[7:0];
		end
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
		((regCurSr[29] && (tIdRegD[6:3]==4'h0)) ? 7'h40 : 7'h00);
	idRegS=tIdRegS ^
		((regCurSr[29] && (tIdRegS[6:3]==4'h0)) ? 7'h40 : 7'h00);
	idRegT=tIdRegT ^
		((regCurSr[29] && (tIdRegT[6:3]==4'h0)) ? 7'h40 : 7'h00);
	idImm=tIdImm;

//	idRegD=tIdRegD;
//	idRegS=tIdRegS;
//	idRegT=tIdRegT;
end

endmodule