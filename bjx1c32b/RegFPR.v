/*

Floating Point Registers

Registers implement the conversion process.

 */

`include "CoreDefs.v"

`include "FpuFp32To64.v"
`include "FpuFp64To32.v"

module RegFPR(
	/* verilator lint_off UNUSED */
	clock, reset,
	regIdRs, regValRs,
	regIdRt, regValRt,
	regIdRm, regValRm,
	regIdRn, regValRn,
	regMode, regCsFl,
	regStMode,
	ctlInFpul,	ctlOutFpul
	);

input clock;
input reset;

input[6:0]		regIdRs;
input[6:0]		regIdRt;
input[6:0]		regIdRm;
input[6:0]		regIdRn;

output[63:0]	regValRs;
output[63:0]	regValRt;
output[63:0]	regValRm;
input[63:0]		regValRn;

input[1:0]		regMode;			//get mode
input[15:0]		regCsFl;
input[1:0]		regStMode;			//set mode

input[31:0]		ctlInFpul;		//FPUL in
output[31:0]	ctlOutFpul;		//FPUL out


reg[31:0]		regFprH[15:0];		//FR0, FR2, FR4, ...
reg[31:0]		regFprL[15:0];		//FR1, FR3, FR5, ...

reg[31:0]		tRegValRsF;
reg[31:0]		tRegValRtF;
reg[31:0]		tRegValRmF;

reg[63:0]		tRegValRsD;
reg[63:0]		tRegValRtD;
reg[63:0]		tRegValRmD;

// reg[63:0]		tRegValRnD;
reg[31:0]		tRegValRnF;
reg[31:0]		tRegValRnF2;

reg[63:0]		tRegValRs;
reg[63:0]		tRegValRt;
reg[63:0]		tRegValRm;

reg[31:0]	tFpul;


reg		cvtF32To64;
reg		accF32Raw;

reg		cvtStF32To64;
reg		accStF32Raw;

FpuFp32To64 fpCvtRs(clock, cvtF32To64, tRegValRsF, tRegValRsD);
FpuFp32To64 fpCvtRt(clock, cvtF32To64, tRegValRtF, tRegValRtD);
FpuFp32To64 fpCvtRm(clock, cvtF32To64, tRegValRmF, tRegValRmD);

//FpuFp64To32 fpCvtRn(clock, cvtF32To64, tRegValRnD, tRegValRnF);
FpuFp64To32 fpCvtRn(clock, cvtF32To64, regValRn, tRegValRnF);


assign regValRs = tRegValRs;
assign regValRt = tRegValRt;
assign regValRm = tRegValRm;

assign	ctlOutFpul = tFpul;

// always @ (clock)
always @*
begin
	tRegValRs=0;
	tRegValRt=0;
	tRegValRm=0;

	tRegValRsF=0;
	tRegValRsD=0;
	tRegValRtF=0;
	tRegValRtD=0;
	tRegValRmF=0;
	tRegValRmD=0;
	
	tFpul = ctlInFpul;
//	tRegValRnD = regValRn;

	case(regMode)
		2'b00: begin		//Float
			cvtF32To64=1;
			accF32Raw=0;
		end
		2'b01: begin		//Double
			cvtF32To64=0;
			accF32Raw=0;
		end
		2'b10: begin		//Raw Float
			cvtF32To64=0;
			accF32Raw=1;
		end
		2'b11: begin		//Raw Double?
			cvtF32To64=0;
			accF32Raw=0;
		end
	endcase

	case(regStMode)
		2'b00: begin		//Float
			cvtStF32To64=1;
			accStF32Raw=0;
		end
		2'b01: begin		//Double
			cvtStF32To64=0;
			accStF32Raw=0;
		end
		2'b10: begin		//Raw Float
			cvtStF32To64=0;
			accStF32Raw=1;
		end
		2'b11: begin		//Raw Double?
			cvtStF32To64=0;
			accStF32Raw=0;
		end
	endcase

	if(regIdRs[6:5]==2'b10)
	begin
		if(cvtF32To64 || accF32Raw)
		begin
			tRegValRsF=regIdRs[0]?
				regFprL[regIdRs[4:1]]:
				regFprH[regIdRs[4:1]];
			if(accF32Raw)
				tRegValRs[31:0]=tRegValRsF;
			else
				tRegValRs=tRegValRsD;
		end
		else
		begin
			tRegValRs[31: 0]=regFprL[regIdRs[4:1]];
			tRegValRs[63:32]=regFprH[regIdRs[4:1]];
		end
	end

	if(regIdRt[6:5]==2'b10)
	begin
		if(cvtF32To64 || accF32Raw)
		begin
			tRegValRtF=regIdRt[0]?
				regFprL[regIdRt[4:1]]:
				regFprH[regIdRt[4:1]];
			if(accF32Raw)
				tRegValRt[31:0]=tRegValRtF;
			else
				tRegValRt=tRegValRtD;
		end
		else
		begin
			tRegValRt[31: 0]=regFprL[regIdRt[4:1]];
			tRegValRt[63:32]=regFprH[regIdRt[4:1]];
		end
	end
	else if(regIdRt==UREG_FPUL)
	begin
		tRegValRtF = ctlInFpul;
		tRegValRt = tRegValRtD;
		if(accF32Raw)
			tRegValRt[31:0]=ctlInFpul[31:0];
	end

	if(regIdRm[6:5]==2'b10)
	begin
		if(cvtF32To64 || accF32Raw)
		begin
			tRegValRmF=regIdRs[0]?
				regFprL[regIdRm[4:1]]:
				regFprH[regIdRm[4:1]];
			if(accF32Raw)
				tRegValRm[31:0]=tRegValRmF;
			else
				tRegValRm=tRegValRmD;
		end
		else
		begin
			tRegValRm[31: 0]=regFprL[regIdRm[4:1]];
			tRegValRm[63:32]=regFprH[regIdRm[4:1]];
		end
	end

	if(regIdRn==UREG_FPUL)
	begin
		case(regStMode)
			2'b00:	tFpul = tRegValRnF;
			2'b01:	tFpul = tRegValRnF;
			2'b10:	tFpul = regValRn[31:0];
			2'b11:	tFpul = regValRn[31:0];
		endcase
	end

	if(cvtStF32To64 || accStF32Raw)
	begin
		tRegValRnF2 = accStF32Raw ?
			regValRn[31:0] :
			tRegValRnF;
	end

end

always @ (posedge clock)
begin
	if(regIdRn[6:5]==2'b10)
	begin
		if(cvtStF32To64 || accStF32Raw)
		begin
			if(regIdRn[0])
				regFprL[regIdRn[4:1]] <= tRegValRnF2;
			else
				regFprH[regIdRn[4:1]] <= tRegValRnF2;
		end
		else
		begin
			regFprL[regIdRn[4:1]] <= regValRn[31: 0];
			regFprH[regIdRn[4:1]] <= regValRn[63:32];
		end
	end
end


endmodule
