`include "CoreDefs.v"
`include "FpuFpD_Add.v"
`include "FpuFpD_Mul.v"
`include "FpuFp64ToInt.v"
`include "FpuFp64FromInt.v"

`include "FpuFp32To64.v"
`include "FpuFp64To32.v"

module FpuFpD(
	/* verilator lint_off UNUSED */
	clock,
	opMode, idMode,
	idRegA, idValA,
	idRegB, idValB,
	idRegC, idValC,
	idRegD, idValD, idModeD,
	ctlInSr,	ctlOutSr,
	ctlInFpul,	ctlOutFpul,
	ctlInFpScr,	ctlOutFpScr
);

input			clock;
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


wire[63:0] fcSrcA;
wire[63:0] fcSrcB;
wire[63:0] fcSrcC;

reg[63:0]		tIdValA;
reg[63:0]		tIdValB;
reg[63:0]		tIdValC;


wire		fcCnvSrc;
wire[63:0]	fcCnvOA;
wire[63:0]	fcCnvOB;
wire[63:0]	fcCnvOC;

FpuFp32To64 fpCvtRa(clock, fcCnvSrc, tIdValA[31:0], fcCnvOA);
FpuFp32To64 fpCvtRb(clock, fcCnvSrc, tIdValB[31:0], fcCnvOB);
FpuFp32To64 fpCvtRc(clock, fcCnvSrc, tIdValC[31:0], fcCnvOC);

wire		fcCnvDst;
wire[63:0]	fcCnvOD;
// wire[63:0]	fcCnvID;
FpuFp64To32 fpCvtRd(clock, fcCnvDst, tDst, fcCnvOD[31:0]);
assign		fcCnvOD[63:32] = 32'hXXXXXXXX;

reg fpaIsEn;

wire fpaIsSub;
wire[63:0] fpaSrcA;
wire[63:0] fpaSrcB;
wire[63:0] fpaDst;
FpuFpD_Add fpadd(clock, fpaIsEn, fpaIsSub, fpaSrcA, fpaSrcB, fpaDst);

// assign fpaSrcA = ((opMode==UCMD_FPU_MAC) || (opMode==UCMD_FPU_MSC)) ? fcSrcC : fcSrcA;
// assign fpaSrcB = ((opMode==UCMD_FPU_MAC) || (opMode==UCMD_FPU_MSC)) ? fpmDst : fcSrcB;

assign fpaSrcA = fcSrcA;
assign fpaSrcB = fcSrcB;

wire[63:0] fpmSrcB;
wire[63:0] fpmDst;
FpuFpD_Mul fpmul(clock, fpaIsEn, fcSrcA, fpmSrcB, fpmDst);

// wire[63:0] fpRcpDst;
// FpuFp64_Rcp fprcp(clk, fcSrcB, fpRcpDst);

assign fpaIsSub = ((opMode==UCMD_FPU_SUB) || (opMode==UCMD_FPU_MSC));
assign fpmSrcB = fcSrcB;


// wire tOpFp32i;
// wire tOpFp32o;

reg fpCnvifEn;
wire[63:0] fpCnvbDstI;
wire[63:0] fpCnvbDstF;
FpuFp64ToInt cnv2si1(clock, fpCnvifEn, 1, tIdValB, fpCnvbDstI);
// FpuFp64FromInt cnv2is1(clk, fpCnvifEn, 1, {32'h0, ctlInFpul}, fpCnvbDstF);
FpuFp64FromInt cnv2is1(clock, fpCnvifEn, 1, tIdValB, fpCnvbDstF);

reg[63:0]	tDst;
/* verilator lint_off UNOPTFLAT */
wire[63:0]	tDst2;
reg[6:0]	tIdRegD;
reg[1:0]	tIdModeD;

reg[31:0]	tSro;
reg[31:0]	tFpul;
reg[31:0]	tFpScr;

wire		isOpF32;
assign		isOpF32 = (idMode==0);

assign fcCnvSrc = (isOpF32 || (opMode==UCMD_FPU_CNVSD)) && 
	(opMode!=UCMD_FPU_CNVIS);
assign fcCnvDst = (isOpF32 || (opMode==UCMD_FPU_CNVDS)) && 
	(opMode!=UCMD_FPU_CNVSI);

//assign	fcSrcA = idValA;
//assign	fcSrcB = idValB;
//assign	fcSrcC = idValC;
//assign	tDst2 = tDst;

assign	fcSrcA = fcCnvSrc ? fcCnvOA : tIdValA;
assign	fcSrcB = fcCnvSrc ? fcCnvOB : tIdValB;
assign	fcSrcC = fcCnvSrc ? fcCnvOC : tIdValC;
assign	tDst2  = fcCnvDst ? fcCnvOD : tDst;

//assign	idValD = tDst2;
//assign	idRegD = tIdRegD;
//assign	idModeD = tIdModeD;

//assign	ctlOutSr = tSro;
//assign	ctlOutFpul = tFpul;
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

 /*
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
//			fpaIsEn = 1;
//			tDst = fpaDst;
//			tIdRegD = idRegC;
		end

		UCMD_FPU_MSC: begin
//			fpaIsEn = 1;
//			tDst = fpaDst;
//			tIdRegD = idRegC;
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
			tIdModeD = 2;
		end
		UCMD_FPU_CNVIS: begin
			fpCnvifEn = 1;
			tDst = fpCnvbDstF;
			tIdRegD = idRegC;
		end
 */

		default: begin
//			tDst = fcSrcB;
		end
	endcase
	
//	idValD = tDst2;
end


// assign	idValD = tDst2;
assign	idRegD = tIdRegD;
assign	idModeD = tIdModeD;

//assign	ctlOutSr = tSro;
// assign	ctlOutFpul = tFpul;

reg[63:0]	tDst_B0;
reg[63:0]	tDst_B1;
reg[63:0]	tDst_B2;
reg[63:0]	tDst_B3;

reg[63:0]	nxtDst_B0;
reg[63:0]	nxtDst_B1;
reg[63:0]	nxtDst_B2;
reg[63:0]	nxtDst_B3;


reg[31:0]	tFpul_B0;
reg[31:0]	tFpul_B1;
reg[31:0]	tFpul_B2;
reg[31:0]	tFpul_B3;

reg[31:0]	nxtFpul_B0;
reg[31:0]	nxtFpul_B1;
reg[31:0]	nxtFpul_B2;
reg[31:0]	nxtFpul_B3;

reg[31:0]	tSro_B0;
reg[31:0]	tSro_B1;
reg[31:0]	tSro_B2;
reg[31:0]	tSro_B3;

reg[31:0]	nxtSro_B0;
reg[31:0]	nxtSro_B1;
reg[31:0]	nxtSro_B2;
reg[31:0]	nxtSro_B3;

assign	idValD = tDst_B3;
assign	ctlOutFpul = nxtFpul_B3;
assign	ctlOutSr = nxtSro_B3;


always @*
begin
	nxtDst_B0 = tDst2;		nxtDst_B1 = tDst_B0;
	nxtDst_B2 = tDst_B1;	nxtDst_B3 = tDst_B2;

	nxtFpul_B0 = tFpul;		nxtFpul_B1 = tFpul_B0;
	nxtFpul_B2 = tFpul_B1;	nxtFpul_B3 = tFpul_B2;

	nxtSro_B0 = tSro;		nxtSro_B1 = tSro_B0;
	nxtSro_B2 = tSro_B1;	nxtSro_B3 = tSro_B2;
end

always @ (posedge clock)
begin
	tIdValA	<= idValA;
	tIdValB	<= idValB;
	tIdValC	<= idValC;

	tDst_B0 <= nxtDst_B0;	tDst_B1 <= nxtDst_B1;
	tDst_B2 <= nxtDst_B2;	tDst_B3 <= nxtDst_B3;

	tFpul_B0 <= nxtFpul_B0;	tFpul_B1 <= nxtFpul_B1;
	tFpul_B2 <= nxtFpul_B2;	tFpul_B3 <= nxtFpul_B3;

	tSro_B0 <= nxtSro_B0;	tSro_B1 <= nxtSro_B1;
	tSro_B2 <= nxtSro_B2;	tSro_B3 <= nxtSro_B3;
end

endmodule
