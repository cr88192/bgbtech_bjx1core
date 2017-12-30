/*
GPR Bank

Reads from Rs, Rt, and Rm.
Writes to Rn.
 */

module RegGPR(
	/* verilator lint_off UNUSED */
	clock, reset,
	regIdRs, regValRs,
	regIdRt, regValRt,
	regIdRm, regValRm,
	regIdRn, regValRn,
	regSrVal);

input clock;
input reset;

input[6:0]		regIdRs;
input[6:0]		regIdRt;
input[6:0]		regIdRm;
input[6:0]		regIdRn;

output[31:0]	regValRs;
output[31:0]	regValRt;
output[31:0]	regValRm;
input[31:0]		regValRn;

input[31:0]		regSrVal;

reg			regSrRB;
reg[31:0]	tRegValRs;
reg[31:0]	tRegValRt;
reg[31:0]	tRegValRm;

reg[31:0]	regGprLA[7:0];
reg[31:0]	regGprLB[7:0];
reg[31:0]	regGprH[7:0];

assign regValRs = tRegValRs;
assign regValRt = tRegValRt;
assign regValRm = tRegValRm;

always @ (clock)
begin
	tRegValRs=0;
	tRegValRt=0;
	tRegValRm=0;

	regSrRB=regSrVal[29];

	if(regIdRs[6:3]==4'h0)
	begin
		tRegValRs=regSrRB?
			regGprLB[regIdRs[2:0]]:
			regGprLA[regIdRs[2:0]];
	end
	else if(regIdRs[6:3]==4'h1)
	begin
		tRegValRs=regGprH[regIdRs[2:0]];
	end
	else if(regIdRs[6:3]==4'h4)
	begin
		tRegValRs=regSrRB?
			regGprLB[regIdRs[2:0]]:
			regGprLA[regIdRs[2:0]];
	end

	if(regIdRt[6:3]==4'h0)
	begin
		tRegValRt=regSrRB?
			regGprLB[regIdRt[2:0]]:
			regGprLA[regIdRt[2:0]];
	end
	else if(regIdRt[6:3]==4'h1)
	begin
		tRegValRt=regGprH[regIdRt[2:0]];
	end
	else if(regIdRt[6:3]==4'h4)
	begin
		tRegValRt=regSrRB?
			regGprLB[regIdRt[2:0]]:
			regGprLA[regIdRt[2:0]];
	end

	if(regIdRm[6:3]==4'h0)
	begin
		tRegValRm=regSrRB?
			regGprLB[regIdRm[2:0]]:
			regGprLA[regIdRm[2:0]];
	end
	else if(regIdRm[6:3]==4'h1)
	begin
		tRegValRm=regGprH[regIdRm[2:0]];
	end
	else if(regIdRm[6:3]==4'h4)
	begin
		tRegValRm=regSrRB?
			regGprLB[regIdRm[2:0]]:
			regGprLA[regIdRm[2:0]];
	end
end

always @ (posedge clock)
begin
	if(regIdRn[6:3]==4'h0)
	begin
		if(regSrRB)
			regGprLB[regIdRn[2:0]] <= regValRn;
		else
			regGprLA[regIdRn[2:0]] <= regValRn;
	end
	else if(regIdRn[6:3]==4'h1)
	begin
		regGprH[regIdRn[2:0]] <= regValRn;
	end
	else if(regIdRn[6:3]==4'h4)
	begin
		if(regSrRB)
			regGprLA[regIdRn[2:0]] <= regValRn;
		else
			regGprLB[regIdRn[2:0]] <= regValRn;
	end
end

endmodule
