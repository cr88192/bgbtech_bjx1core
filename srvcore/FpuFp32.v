`include "FpuFp32_Add.v"
`include "FpuFp32_Mul.v"
`include "FpuFp32_Rcp.v"

module FpuFp32(
	/* verilator lint_off UNUSED */
	clk,
	opMode,
	srca,
	srcb,
	dst
);

input			clk;
input[3:0] 		opMode;
input[31:0]		srca;
input[31:0]		srcb;
output[31:0]	dst;

parameter[3:0] OP_NONE		= 4'h00;
parameter[3:0] OP_ADD		= 4'h01;
parameter[3:0] OP_SUB		= 4'h02;
parameter[3:0] OP_MUL		= 4'h03;
parameter[3:0] OP_DIV		= 4'h04;
parameter[3:0] OP_ABS		= 4'h05;
parameter[3:0] OP_NEG		= 4'h06;
parameter[3:0] OP_RCP		= 4'h07;
parameter[3:0] OP_SQRT		= 4'h08;

reg fpaIsSub;
reg[31:0] fpaDst;
FpuFp32_Add fpadd(clk, fpaIsSub, srca, srcb, fpaDst);

reg[31:0] fpmSrcB;
reg[31:0] fpmDst;
FpuFp32_Mul fpmul(clk, srca, fpmSrcB, fpmDst);
// FpuFp32_Mul fpmul(clk, srca, srcb, fpmDst);

reg[31:0] fpRcpDst;
FpuFp32_Rcp fprcp(clk, srcb, fpRcpDst);

// reg[31:0] fpdDst;
// FpuFp32_Mul fpdiv(clk, srca, fpRcpDst, fpdDst);

assign fpaIsSub = (opMode==OP_SUB);
assign fpmSrcB = (opMode==OP_DIV) ? fpRcpDst : srcb;

reg[31:0]	tDst;

always @ (opMode) begin
//	fpmSrcB = srcb;

	case(opMode)
		OP_ADD: begin
			tDst = fpaDst;
		end
		OP_SUB: begin
			tDst = fpaDst;
		end
		OP_MUL: begin
//			fpmSrcB = srcb;
			tDst = fpmDst;
		end
		OP_DIV: begin
//			fpmSrcB = fpRcpDst;
//			fpmSrcB = srcb;
			tDst = fpmDst;
		end

		OP_ABS: begin
			tDst[31] = 0;
			tDst[30:0] = srcb[30:0];
		end
		OP_NEG: begin
			tDst[31] = !srcb[31];
			tDst[30:0] = srcb[30:0];
		end
		OP_RCP: begin
			tDst = fpRcpDst;
		end

		OP_SQRT: begin
			tDst = ((srcb-32'h3F80_0000)>>>1)+32'h3F80_0000;
		end

		default: begin
			tDst = srcb;
		end
	endcase
	
	dst = tDst;
end

endmodule
