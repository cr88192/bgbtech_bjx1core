/*
FPU, Low Precision

Operates on Single Precision values, with mantissa shaved to 16 bits.
*/

module FpuFpL_Mul(
	/* verilator lint_off UNUSED */
	clk,
	enable,
	srca,
	srcb,
	dst
);

input			clk;
input			enable;
input[31:0]		srca;
input[31:0]		srcb;
output[31:0]	dst;

reg sgna;
reg sgnb;
reg sgnc;

reg[9:0] exa;
reg[9:0] exb;
reg[9:0] exc;

reg[35:0] tFracC;

reg[22:0] tFracC2;

reg[31:0]	tDst;

assign dst = tDst;

always @*
begin
	sgna = srca[31];
	sgnb = srcb[31];

	exa = { 2'b00, srca[30:23] };
	exb = { 2'b00, srcb[30:23] };

	sgnc = sgna^sgnb;

	tFracC =
		{20'h1, srca[22:7]} *
		{20'h1, srcb[22:7]};

	if(tFracC[35])
	begin
		tFracC2[22:0]=tFracC[34:12];
		exc=exa+exb-126;
	end
	else
	begin
		tFracC2[22:0]=tFracC[33:11];
		exc=exa+exb-127;
	end
	
	if(exc[9])
	begin
		tDst=0;
	end
	else
	if(exc[8])
	begin
		tDst[31]=sgnc;
		tDst[30:0]=31'h7F80_0000;
	end
	else
	begin
		tDst[31]=sgnc;
		tDst[30:23]=exc[7:0];
		tDst[22: 0]=tFracC2[22:0];
	end
end

endmodule
