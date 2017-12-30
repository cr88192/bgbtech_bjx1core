`include "CoreDefs.v"
`include "FpuFpD_Add.v"
`include "FpuFpD_Mul.v"
`include "FpuFp64ToInt.v"
`include "FpuFp64FromInt.v"

module FpuFpD(
	/* verilator lint_off UNUSED */
	clk,
	opMode, idMode,
	idRegA, idValA,
	idRegB, idValB,
	idRegC, idValC,
	idRegD, idValD, idModeD,
	ctlInSr,	ctlOutSr,
	ctlInFpul,	ctlOutFpul,
	ctlInFpScr,	ctlOutFpScr
);

input			clk;
input[7:0] 		opMode;
input[1:0] 		idMode;
input[63:0]		idValA;
input[63:0]		idValB;
input[63:0]		idValC;
output[63:0]	idValD;

input[6:0]		idRegA;
input[6:0]		idRegB;
input[6:0]		idRegC;
output[6:0]		idRegD;
output[1:0]		idModeD;

input[31:0]		ctlInSr;		//SR in
output[31:0]	ctlOutSr;		//SR out

input[31:0]		ctlInFpul;		//FPUL in
output[31:0]	ctlOutFpul;		//FPUL out

input[31:0]		ctlInFpScr;		//FPSCR in
output[31:0]	ctlOutFpScr;	//FPSCR out

reg fpaIsEn;

wire[63:0] fcSrcA;
wire[63:0] fcSrcB;
wire[63:0] fcSrcC;

wire fpaIsSub;
wire[63:0] fpaSrcA;
wire[63:0] fpaSrcB;
wire[63:0] fpaDst;
FpuFpD_Add fpadd(clk, fpaIsEn, fpaIsSub, fpaSrcA, fpaSrcB, fpaDst);

assign fpaSrcA = ((opMode==UCMD_FPU_MAC) || (opMode==UCMD_FPU_MSC)) ? fcSrcC : fcSrcA;
assign fpaSrcB = ((opMode==UCMD_FPU_MAC) || (opMode==UCMD_FPU_MSC)) ? fpmDst : fcSrcB;

wire[63:0] fpmSrcB;
wire[63:0] fpmDst;
FpuFpD_Mul fpmul(clk, fpaIsEn, fcSrcA, fpmSrcB, fpmDst);

// wire[63:0] fpRcpDst;
// FpuFp64_Rcp fprcp(clk, fcSrcB, fpRcpDst);

assign fpaIsSub = ((opMode==UCMD_FPU_SUB) || (opMode==UCMD_FPU_MSC));
assign fpmSrcB = fcSrcB;


// wire tOpFp32i;
// wire tOpFp32o;

reg fpCnvifEn;
wire[63:0] fpCnvbDstI;
wire[63:0] fpCnvbDstF;
FpuFp64ToInt cnv2si1(clk, fpCnvifEn, 1, idValB, fpCnvbDstI);
// FpuFp64FromInt cnv2is1(clk, fpCnvifEn, 1, {32'h0, ctlInFpul}, fpCnvbDstF);
FpuFp64FromInt cnv2is1(clk, fpCnvifEn, 1, idValB, fpCnvbDstF);

reg[63:0]	tDst;
/* verilator lint_off UNOPTFLAT */
wire[63:0]	tDst2;
reg[6:0]	tIdRegD;
reg[1:0]	tIdModeD;

reg[31:0]	tSro;
reg[31:0]	tFpul;
reg[31:0]	tFpScr;

// assign tOpFp32i = (opf32 || (opMode==UCMD_FPU_CNVSD)) && (opMode!=UCMD_FPU_CNVIS);
// assign tOpFp32o = (opf32 || (opMode==UCMD_FPU_CNVDS)) && (opMode!=UCMD_FPU_CNVSI);
assign	fcSrcA = idValA;
assign	fcSrcB = idValB;
assign	fcSrcC = idValC;
assign	tDst2 = tDst;
assign	idValD = tDst2;
assign	idRegD = tIdRegD;
assign	idModeD = tIdModeD;

assign	ctlOutSr = tSro;
assign	ctlOutFpul = tFpul;
assign	ctlOutFpScr = tFpScr;

// always @ (opMode) begin
always @*
begin
	fpCnvifEn = 0;
	fpaIsEn = 0;
	tSro = ctlInSr;
	tDst = fcSrcB;
	tIdRegD = UREG_ZZR;
	tIdModeD = idMode;
	tFpul = ctlInFpul;
	tFpScr = ctlInFpScr;

	case(opMode)
		UCMD_FPU_NONE: begin
			tDst = 0;
		end

		UCMD_FPU_ADD: begin
			fpaIsEn = 1;
			tDst = fpaDst;
			tIdRegD = idRegC;
		end
		UCMD_FPU_SUB: begin
			fpaIsEn = 1;
			tDst = fpaDst;
			tIdRegD = idRegC;
		end
		UCMD_FPU_MUL: begin
			fpaIsEn = 1;
			tDst = fpmDst;
			tIdRegD = idRegC;
		end

		UCMD_FPU_ABS: begin
			tDst[63] = 0;
			tDst[62:0] = fcSrcB[62:0];
			tIdRegD = idRegC;
		end
		UCMD_FPU_NEG: begin
			tDst[63] = !fcSrcB[63];
			tDst[62:0] = fcSrcB[62:0];
			tIdRegD = idRegC;
		end

		UCMD_FPU_RCP: begin
			tDst[63] = fcSrcB[63];
			tDst[62:0] = (0-(fcSrcB[62:0]-63'h3FF0_0000_0000_0000))+
				63'h3FF0_0000_0000_0000;
			tIdRegD = idRegC;
		end

		UCMD_FPU_SQRT: begin
			tDst[63] = fcSrcB[63];
			tDst[62:0] = ((fcSrcB[62:0]-63'h3FF0_0000_0000_0000)>>>1)+
				63'h3FF0_0000_0000_0000;
			tIdRegD = idRegC;
		end

		UCMD_FPU_MAC: begin
			fpaIsEn = 1;
			tDst = fpaDst;
			tIdRegD = idRegC;
		end

		UCMD_FPU_MSC: begin
			fpaIsEn = 1;
			tDst = fpaDst;
			tIdRegD = idRegC;
		end

		UCMD_FPU_CMPEQ: begin
			tSro[0] = (fcSrcA == fcSrcB);
		end

		UCMD_FPU_CMPGT: begin
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

		UCMD_FPU_CNVSD: begin
			tDst = fcSrcB;
			tIdRegD = idRegC;
			tIdModeD = 1;
		end

		UCMD_FPU_CNVSI: begin
			fpCnvifEn = 1;
//			tFpul = fpCnvbDstI[31:0];
			tDst = fpCnvbDstI;
			tIdRegD = idRegC;
		end
		UCMD_FPU_CNVIS: begin
			fpCnvifEn = 1;
			tDst = fpCnvbDstF;
			tIdRegD = idRegC;
		end

		default: begin
//			tDst = fcSrcB;
		end
	endcase
	
//	idValD = tDst2;
end

endmodule
