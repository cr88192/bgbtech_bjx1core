module FpuFp32_Mul(
	/* verilator lint_off UNUSED */
	clk,
	srca,
	srcb,
	dst
);

input			clk;
input[31:0]		srca;
input[31:0]		srcb;
output[31:0]	dst;

reg sgna;
reg sgnb;
reg sgnc;

reg[9:0] exa;
reg[9:0] exb;
reg[9:0] exc;

reg[47:0] tFracA;
reg[47:0] tFracB;
reg[47:0] tFracC;
reg[22:0] tFracC2;

reg[31:0]	tDst;

always @ (clk) begin
	sgna=srca[31];
	sgnb=srcb[31];

	exa[7:0]=srca[30:23];
	exb[7:0]=srcb[30:23];
	exa[9:8]=0;
	exb[9:8]=0;

	sgnc=sgna^sgnb;

	tFracA[47:23]=25'h1;
	tFracB[47:23]=25'h1;
	tFracA[22:0]=srca[22:0];
	tFracB[22:0]=srcb[22:0];
	tFracC=tFracA*tFracB;
	if(tFracC[47])
	begin
		tFracC2[22:0]=tFracC[46:24];
		exc=exa+exb-126;
	end
	begin
		tFracC2[22:0]=tFracC[45:23];
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
	
	dst=tDst;
end

endmodule
