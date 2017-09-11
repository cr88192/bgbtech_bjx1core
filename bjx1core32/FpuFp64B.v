`include "FpuFp64_Add.v"
`include "FpuFp64_Mul.v"
// `include "FpuFp64_Rcp.v"
`include "FpuFp32To64.v"
`include "FpuFp64To32.v"

`include "FpuFp64ToInt.v"
`include "FpuFp64FromInt.v"

module FpuFp64B(
	/* verilator lint_off UNUSED */
	clk,
	opf32,
	opMode,
	srca,
	srcb,
	srcc,
	dst,
	sri,
	sro
);

input			clk;
input			opf32;		//are we operating on float32?
input[3:0] 		opMode;
input[63:0]		srca;
input[63:0]		srcb;
input[63:0]		srcc;
output[63:0]	dst;

input[3:0] 		sri;
output[3:0] 	sro;

parameter[3:0] OP_NONE		= 4'h00;
parameter[3:0] OP_ADD		= 4'h01;	//srca+srcb
parameter[3:0] OP_SUB		= 4'h02;	//srca-srcb
parameter[3:0] OP_MUL		= 4'h03;	//srca*srcb
// parameter[3:0] OP_DIV	= 4'h04;
parameter[3:0] OP_MSC		= 4'h04;	//srcc-(srca*srcb)
parameter[3:0] OP_ABS		= 4'h05;	//|srcb|
parameter[3:0] OP_NEG		= 4'h06;	//-srcb
parameter[3:0] OP_RCP		= 4'h07;	//(1/x), rough approx
parameter[3:0] OP_SQRT		= 4'h08;	//sqrt(x), rough approx
parameter[3:0] OP_MAC		= 4'h09;	//srcc+(srca*srcb)
parameter[3:0] OP_CMPEQ		= 4'h0A;	//srca==srcb
parameter[3:0] OP_CMPGT		= 4'h0B;	//srca>srcb
parameter[3:0] OP_CNVSD		= 4'h0C;	//single to double
parameter[3:0] OP_CNVDS		= 4'h0D;	//double to single
parameter[3:0] OP_CNVSI		= 4'h0E;	//float to int
parameter[3:0] OP_CNVIS		= 4'h0F;	//int to float

reg fpaIsEn;

wire[63:0] fcSrcA;
wire[63:0] fcSrcB;
wire[63:0] fcSrcC;

wire fpaIsSub;
wire[63:0] fpaSrcA;
wire[63:0] fpaSrcB;
wire[63:0] fpaDst;
FpuFp64_Add fpadd(clk, fpaIsEn, fpaIsSub, fpaSrcA, fpaSrcB, fpaDst);

assign fpaSrcA = ((opMode==OP_MAC) || (opMode==OP_MSC)) ? fcSrcC : fcSrcA;
assign fpaSrcB = ((opMode==OP_MAC) || (opMode==OP_MSC)) ? fpmDst : fcSrcB;

wire[63:0] fpmSrcB;
wire[63:0] fpmDst;
FpuFp64_Mul fpmul(clk, fpaIsEn, fcSrcA, fpmSrcB, fpmDst);

// wire[63:0] fpRcpDst;
// FpuFp64_Rcp fprcp(clk, fcSrcB, fpRcpDst);

//assign fpaIsSub = (opMode==OP_SUB);
assign fpaIsSub = ((opMode==OP_SUB) || (opMode==OP_MSC));
// assign fpmSrcB = (opMode==OP_DIV) ? fpRcpDst : fcSrcB;
assign fpmSrcB = fcSrcB;


wire tOpFp32i;
wire tOpFp32o;

reg fpCnvEn;
wire[63:0] fpCnvaDst;
wire[63:0] fpCnvbDst;
wire[63:0] fpCnvcDst;
FpuFp32To64 fpcnva(clk, fpCnvEn, srca[31:0], fpCnvaDst);
FpuFp32To64 fpcnvb(clk, fpCnvEn, srcb[31:0], fpCnvbDst);
FpuFp32To64 fpcnvc(clk, fpCnvEn, srcc[31:0], fpCnvcDst);

reg fpCnvifEn;
wire[63:0] fpCnvbDstI;
wire[63:0] fpCnvbDstF;
FpuFp64ToInt cnv2si1(clk, fpCnvifEn, opf32, fcSrcB, fpCnvbDstI);
FpuFp64FromInt cnv2is1(clk, fpCnvifEn, opf32, srcb, fpCnvbDstF);

reg[63:0]	tDst;
/* verilator lint_off UNOPTFLAT */
wire[63:0]	tDst2;
reg[3:0]	tSro;

wire[63:0] fpCnvdDst;
FpuFp64To32 fpcnvd(clk, fpCnvEn, tDst, fpCnvdDst[31:0]);
assign 	fpCnvdDst[63:32]=0;

assign tOpFp32i = (opf32 || (opMode==OP_CNVSD)) && (opMode!=OP_CNVIS);
assign tOpFp32o = (opf32 || (opMode==OP_CNVDS)) && (opMode!=OP_CNVSI);
assign fcSrcA = tOpFp32i ? fpCnvaDst : srca;
assign fcSrcB = tOpFp32i ? fpCnvbDst : srcb;
assign fcSrcC = tOpFp32i ? fpCnvcDst : srcc;
assign	tDst2 = tOpFp32o ? fpCnvdDst : tDst;
assign	dst = tDst2;
assign	sro = tSro;

always @ (opMode) begin
// always_ff begin

//	fpCnvdDst[63:32]=0;
//	fpmSrcB = srcb;

	fpCnvEn = opf32;
	fpCnvifEn = 0;
	fpaIsEn = 0;
	tSro = sri;
	tDst = fcSrcB;
end

always @ (opMode) begin
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
//		OP_DIV: begin
//			fpaIsEn = 1;
//			tDst = fpmDst;
//		end

		OP_ABS: begin
			tDst[63] = 0;
			tDst[62:0] = fcSrcB[62:0];
		end
		OP_NEG: begin
			tDst[63] = !fcSrcB[63];
			tDst[62:0] = fcSrcB[62:0];
		end
//		OP_RCP: begin
//			fpaIsEn = 1;
//			tDst = fpRcpDst;
//		end

		OP_RCP: begin
			tDst[63] = fcSrcB[63];
			tDst[62:0] = (0-(fcSrcB[62:0]-63'h3FF0_0000_0000_0000))+
				63'h3FF0_0000_0000_0000;
		end

		OP_SQRT: begin
			tDst[63] = fcSrcB[63];
			tDst[62:0] = ((fcSrcB[62:0]-63'h3FF0_0000_0000_0000)>>>1)+
				63'h3FF0_0000_0000_0000;
		end

		OP_MAC: begin
			fpaIsEn = 1;
			tDst = fpaDst;
		end

		OP_MSC: begin
			fpaIsEn = 1;
			tDst = fpaDst;
		end

		OP_CMPEQ: begin
			tSro[0] = (fcSrcA == fcSrcB);
		end

		OP_CMPGT: begin
			if(fcSrcA[63])
			begin
				if(fcSrcB[63])
				begin
					tSro[0] = (fcSrcA[62:0] < fcSrcB[62:0]);
				end
				else
				begin
					tSro[0] = 0;
				end
			end
			else
			begin
				if(!fcSrcB[63])
				begin
					tSro[0] = (fcSrcA[62:0] > fcSrcB[62:0]);
				end
				else
				begin
					tSro[0] = 1;
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
