module FpuFp64_Mul(
	/* verilator lint_off UNUSED */
	clk,
	enable,
	srca,
	srcb,
	dst
);

input			clk;
input			enable;
input[63:0]		srca;
input[63:0]		srcb;
output[63:0]	dst;

reg sgna;
reg sgnb;
reg sgnc;

reg[12:0] exa;
reg[12:0] exb;
reg[12:0] exc;

reg[63:0] tFracA;
reg[63:0] tFracB;
reg[63:0] tFracC;
reg[51:0] tFracC2;

reg[63:0]	tDst;

always @ (clk && enable)
begin
	sgna=srca[63];
	sgnb=srcb[63];

	exa[10:0]=srca[62:52];
	exb[10:0]=srcb[62:52];
	exa[12:11]=0;
	exb[12:11]=0;

	sgnc=sgna^sgnb;

	tFracA[63:52]=1;
	tFracB[63:52]=1;
	tFracA[51:0]=srca[51:0];
	tFracB[51:0]=srcb[51:0];
	tFracC=(tFracA>>21)*(tFracB>>21);
	if(tFracC[63])
	begin
		tFracC2[51:0]=tFracC[62:11];
		exc=exa+exb-1022;
	end
	begin
		tFracC2[51:0]=tFracC[61:10];
		exc=exa+exb-1023;
	end
	
	if(exc[12])
	begin
		tDst=0;
	end
	else
	if(exc[11])
	begin
		tDst[63]=sgnc;
		tDst[62:0]=63'h7FF0_0000_0000_0000;
	end
	else
	begin
		tDst[63]=sgnc;
		tDst[62:52]=exc[10:0];
		tDst[51: 0]=tFracC2[51:0];
	end
	
	dst=tDst;
end

endmodule
