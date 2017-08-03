`include "FpuFp64_Add.v"
`include "FpuFp64_Mul.v"
`include "FpuFp64_Rcp.v"
`include "FpuFp32To64.v"
`include "FpuFp64To32.v"

`include "FpuFp64ToInt.v"
`include "FpuFp64FromInt.v"

module FpuFp64(
	/* verilator lint_off UNUSED */
	clk,
	opf32,
	opMode,
	srca,
	srcb,
	dst,
	sri,
	sro
);

input			clk;
input			opf32;		//are we operating on float32?
input[3:0] 		opMode;
input[63:0]		srca;
input[63:0]		srcb;
output[63:0]	dst;

input[3:0] 		sri;
output[3:0] 	sro;

parameter[3:0] OP_NONE		= 4'h00;
parameter[3:0] OP_ADD		= 4'h01;
parameter[3:0] OP_SUB		= 4'h02;
parameter[3:0] OP_MUL		= 4'h03;
parameter[3:0] OP_DIV		= 4'h04;
parameter[3:0] OP_ABS		= 4'h05;
parameter[3:0] OP_NEG		= 4'h06;
parameter[3:0] OP_RCP		= 4'h07;
parameter[3:0] OP_SQRT		= 4'h08;

parameter[3:0] OP_CMPEQ		= 4'h0A;
parameter[3:0] OP_CMPGT		= 4'h0B;
parameter[3:0] OP_CNVSD		= 4'h0C;
parameter[3:0] OP_CNVDS		= 4'h0D;
parameter[3:0] OP_CNVSI		= 4'h0E;
parameter[3:0] OP_CNVIS		= 4'h0F;

reg fpaIsEn;

reg fpaIsSub;
reg[63:0] fpaDst;
FpuFp64_Add fpadd(clk, fpaIsEn, fpaIsSub, fcSrcA, fcSrcB, fpaDst);

reg[63:0] fpmSrcB;
reg[63:0] fpmDst;
FpuFp64_Mul fpmul(clk, fpaIsEn, fcSrcA, fpmSrcB, fpmDst);

reg[63:0] fpRcpDst;
FpuFp64_Rcp fprcp(clk, fcSrcB, fpRcpDst);

assign fpaIsSub = (opMode==OP_SUB);
assign fpmSrcB = (opMode==OP_DIV) ? fpRcpDst : fcSrcB;


reg tOpFp32i;
reg tOpFp32o;

reg[63:0] fcSrcA;
reg[63:0] fcSrcB;

reg fpCnvEn;
reg[63:0] fpCnvaDst;
reg[63:0] fpCnvbDst;
FpuFp32To64 fpcnva(clk, fpCnvEn, srca[31:0], fpCnvaDst);
FpuFp32To64 fpcnvb(clk, fpCnvEn, srcb[31:0], fpCnvbDst);

reg fpCnvifEn;
reg[63:0] fpCnvbDstI;
reg[63:0] fpCnvbDstF;
FpuFp64ToInt cnv2si1(clk, fpCnvifEn, opf32, fcSrcB, fpCnvbDstI);
FpuFp64FromInt cnv2is1(clk, fpCnvifEn, opf32, srcb, fpCnvbDstF);

reg[63:0]	tDst;
reg[63:0]	tDst2;

reg[63:0] fpCnvcDst;
FpuFp64To32 fpcnvc(clk, fpCnvEn, tDst, fpCnvcDst[31:0]);
assign 	fpCnvcDst[63:32]=0;

assign tOpFp32i = (opf32 || (opMode==OP_CNVSD)) && (opMode!=OP_CNVIS);
assign tOpFp32o = (opf32 || (opMode==OP_CNVDS)) && (opMode!=OP_CNVSI);
assign fcSrcA = tOpFp32i ? fpCnvaDst : srca;
assign fcSrcB = tOpFp32i ? fpCnvbDst : srcb;

assign	tDst2 = tOpFp32o ? fpCnvcDst : tDst;
assign	dst = tDst2;

// always @ (opMode) begin
always_ff begin

//	fpCnvcDst[63:32]=0;
//	fpmSrcB = srcb;

	fpCnvEn = opf32;
	fpCnvifEn = 0;
	fpaIsEn = 0;
	sro = sri;

	case(opMode)
		OP_NONE: begin
			tDst = 0;
			fpCnvEn = 0;
			fpCnvifEn = 0;
			fpaIsEn = 0;
		end

		OP_ADD: begin
			fpaIsEn = 1;
			tDst = fpaDst;
		end
		OP_SUB: begin
			fpaIsEn = 1;
			tDst = fpaDst;
		end
		OP_MUL: begin
			fpaIsEn = 1;
			tDst = fpmDst;
		end
		OP_DIV: begin
			fpaIsEn = 1;
			tDst = fpmDst;
		end

		OP_ABS: begin
			tDst[63] = 0;
			tDst[62:0] = fcSrcB[62:0];
		end
		OP_NEG: begin
			tDst[63] = !fcSrcB[63];
			tDst[62:0] = fcSrcB[62:0];
		end
		OP_RCP: begin
			fpaIsEn = 1;
			tDst = fpRcpDst;
		end

		OP_SQRT: begin
			tDst = ((fcSrcB-64'h3FF0_0000_0000_0000)>>>1)+
				64'h3FF0_0000_0000_0000;
		end

		OP_CMPEQ: begin
			sro[0] = (fcSrcA == fcSrcB);
		end

		OP_CMPGT: begin
			if(fcSrcA[63])
			begin
				if(fcSrcB[63])
				begin
					sro[0] = (fcSrcA[62:0] < fcSrcB[62:0]);
				end
				else
				begin
					sro[0] = 0;
				end
			end
			else
			begin
				if(!fcSrcB[63])
				begin
					sro[0] = (fcSrcA[62:0] > fcSrcB[62:0]);
				end
				else
				begin
					sro[0] = 1;
				end
			end
		end

		OP_CNVDS: begin
			fpCnvEn = 1;
			tDst = fcSrcB;
		end
		OP_CNVSD: begin
			fpCnvEn = 1;
			tDst = fcSrcB;
		end

		OP_CNVSI: begin
			fpCnvifEn = 1;
			tDst = fpCnvbDstI;
		end
		OP_CNVIS: begin
			fpCnvifEn = 1;
			tDst = fpCnvbDstF;
		end

		default: begin
			tDst = fcSrcB;
		end
	endcase
	
//	dst = tDst2;
end

endmodule
