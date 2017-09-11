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
input[4:0] 		opMode;
input[31:0]		srca;
input[31:0]		srcb;
output[31:0]	dst;

input[3:0] 		sri;
output[3:0] 	sro;

parameter[4:0] UOP_NONE		= 5'h00;
parameter[4:0] UOP_ADD		= 5'h01;
parameter[4:0] UOP_SUB		= 5'h02;
parameter[4:0] UOP_MUL		= 5'h03;
parameter[4:0] UOP_AND		= 5'h04;
parameter[4:0] UOP_OR		= 5'h05;
parameter[4:0] UOP_XOR		= 5'h06;
parameter[4:0] UOP_SHL		= 5'h07;
parameter[4:0] UOP_SHR		= 5'h08;
parameter[4:0] UOP_SAR		= 5'h09;

parameter[4:0] UOP_ADDC		= 5'h14;
parameter[4:0] UOP_ADDV		= 5'h15;
parameter[4:0] UOP_SUBC		= 5'h16;
parameter[4:0] UOP_SUBV		= 5'h17;
parameter[4:0] UOP_TEST		= 5'h18;

parameter[4:0] UOP_CMPEQ	= 5'h1B;
parameter[4:0] UOP_CMPGT	= 5'h1C;
parameter[4:0] UOP_CMPGE	= 5'h1D;
parameter[4:0] UOP_CMPHS	= 5'h1E;
parameter[4:0] UOP_CMPHI	= 5'h1F;

/* verilator lint_off UNOPTFLAT */
reg[31:0]	tDst;
reg[5:0]	tShl;
reg[3:0] 	tSr;
reg			tCvo;

assign	dst=tDst;
assign	sro=tSr;


always @ (opMode) begin
	tSr=sri;

	case(opMode)
		UOP_ADD: begin
			tDst = srca+srcb;
		end
		UOP_SUB: begin
			tDst = srca-srcb;
		end
		UOP_MUL: begin
			tDst = srca*srcb;
		end
		UOP_AND: begin
			tDst = srca&srcb;
		end
		UOP_OR: begin
			tDst = srca|srcb;
		end
		UOP_XOR: begin
			tDst = srca^srcb;
		end

		UOP_SHL: begin
			tShl = srcb[5:0];
			tDst = srca<<tShl;
		end

		UOP_SHR: begin
			tShl = srcb[5:0];
			tDst = srca>>tShl;
		end

		UOP_SAR: begin
			tShl = srcb[5:0];
			tDst = srca>>>tShl;
		end

		UOP_ADDC: begin
			if(sri[0])
				tDst = srca+srcb+1;
			else
				tDst = srca+srcb;
			tSr[0]=tDst[31]^srca[31];
		end

		UOP_ADDV: begin
			{tCvo, tDst} = {srca[31], srca} + {srcb[31], srcb};
			tSr[0]=tDst[31]^tCvo;
		end

		UOP_SUBC: begin
			if(sri[0])
				tDst = srca-srcb-1;
			else
				tDst = srca-srcb;
			tSr[0]=tDst[31]^srca[31];
		end

		UOP_SUBV: begin
			{tCvo, tDst} = {srca[31], srca} - {srcb[31], srcb};
			tSr[0]=tDst[31]^tCvo;
		end

		UOP_TEST: begin
			tDst = srca&srcb;
			tSr[3:2]=sri[3:2];
			tSr[0]=(tDst==0);
		end

		UOP_CMPEQ: begin
			tDst = srca;
			tSr[3:2]=sri[3:2];
			tSr[0]=(srca[31:0]==srcb[31:0]);
		end

		UOP_CMPGT: begin
			tDst = srca;
			tSr[3:2]=sri[3:2];
			tSr[0]=(srca[31:0]>srcb[31:0]);
		end

		UOP_CMPGE: begin
			tDst = srca;
			tSr[3:2]=sri[3:2];
			tSr[0]=(srca[31:0]>=srcb[31:0]);
		end

		UOP_CMPHS: begin
			tDst = srca;
			tSr[3:2]=sri[3:2];
			tSr[0]=(srca[31:0]>srcb[31:0]);
		end

		UOP_CMPHI: begin
			tDst = srca;
			tSr[3:2]=sri[3:2];
			tSr[0]=(srca[31:0]>=srcb[31:0]);
		end

		default: begin
			tDst = 32'h0000_0000;
			tSr=sri;
		end
	endcase
end

endmodule
