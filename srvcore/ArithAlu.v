module ArithAlu(
	/* verilator lint_off UNUSED */
	clk,
	opMode,
	srca,
	srcb,
	dst,
	sri,
	sro
);

input			clk;
input[3:0] 		opMode;
input[63:0]		srca;
input[63:0]		srcb;
output[63:0]	dst;

input[3:0] 		sri;
output[3:0] 	sro;

parameter[3:0] UOP_NONE		= 4'h00;
parameter[3:0] UOP_ADD		= 4'h01;
parameter[3:0] UOP_SUB		= 4'h02;
parameter[3:0] UOP_MUL		= 4'h03;
parameter[3:0] UOP_AND		= 4'h04;
parameter[3:0] UOP_OR		= 4'h05;
parameter[3:0] UOP_XOR		= 4'h06;
parameter[3:0] UOP_SHL		= 4'h07;
parameter[3:0] UOP_SHR		= 4'h08;
parameter[3:0] UOP_SAR		= 4'h09;
parameter[3:0] UOP_ADDC		= 4'h0A;
parameter[3:0] UOP_CMPEQ	= 4'h0B;
parameter[3:0] UOP_CMPGT	= 4'h0C;
parameter[3:0] UOP_CMPGE	= 4'h0D;
parameter[3:0] UOP_CMPHS	= 4'h0E;
parameter[3:0] UOP_CMPHI	= 4'h0F;

// reg[63:0]	tSrcaQ;
// reg[63:0]	tSrcbQ;

/* verilator lint_off UNOPTFLAT */
reg[63:0]	tDstQ;

// reg[31:0]	tDst;
reg[5:0]	tShl;
reg[3:0] 	tSr;

assign	dst=tDstQ;
assign	sro=tSr;


always @ (opMode) begin
	case(opMode)
		UOP_ADD: begin
			tDstQ = srca+srcb;
			tSr=sri;
		end
		UOP_SUB: begin
			tDstQ = srca-srcb;
			tSr=sri;
		end
		UOP_MUL: begin
			tDstQ = srca*srcb;
			tSr=sri;
		end
		UOP_AND: begin
			tDstQ = srca&srcb;
			tSr=sri;
		end
		UOP_OR: begin
			tDstQ = srca|srcb;
			tSr=sri;
		end
		UOP_XOR: begin
			tDstQ = srca^srcb;
			tSr=sri;
		end

		UOP_SHL: begin
			tShl = srcb[5:0];
			tDstQ = srca<<tShl;
			tSr=sri;
		end

		UOP_SHR: begin
			tShl = srcb[5:0];
			tDstQ = srca>>tShl;
			tSr=sri;
		end

		UOP_SAR: begin
			tShl = srcb[5:0];
			tDstQ = srca>>>tShl;
			tSr=sri;
		end

		UOP_ADDC: begin
			if(sri[0])
				tDstQ = srca+srcb+1;
			else
				tDstQ = srca+srcb;
			tSr[3:2]=sri[3:2];
			tSr[0]=tDstQ[31]^srca[31];
			tSr[1]=tDstQ[63]^srca[63];
		end

		UOP_CMPEQ: begin
			tDstQ = srca;
			tSr[3:2]=sri[3:2];
			tSr[0]=(srca[31:0]==srcb[31:0]);
			tSr[1]=(srca[63:0]==srcb[63:0]);
		end

		UOP_CMPGT: begin
			tDstQ = srca;
			tSr[3:2]=sri[3:2];
			tSr[0]=(srca[31:0]>srcb[31:0]);
			tSr[1]=(srca[63:0]>srcb[63:0]);
		end

		UOP_CMPGE: begin
			tDstQ = srca;
			tSr[3:2]=sri[3:2];
			tSr[0]=(srca[31:0]>=srcb[31:0]);
			tSr[1]=(srca[63:0]>=srcb[63:0]);
		end

		UOP_CMPHS: begin
			tDstQ = srca;
			tSr[3:2]=sri[3:2];
			tSr[0]=(srca[31:0]>srcb[31:0]);
			tSr[1]=(srca[63:0]>srcb[63:0]);
		end

		UOP_CMPHI: begin
			tDstQ = srca;
			tSr[3:2]=sri[3:2];
			tSr[0]=(srca[31:0]>=srcb[31:0]);
			tSr[1]=(srca[63:0]>=srcb[63:0]);
		end

		default: begin
			tDstQ = 64'h0000_0000_0000_0000;
			tSr=sri;
		end
	endcase

//	dst=tDstQ;
//	sro=tSr;
end

endmodule
