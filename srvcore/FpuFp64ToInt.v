module FpuFp64ToInt(
	clk,
	enable,
	is32,
	src,
	dst
);

input			clk;
input			enable;
input			is32;

input[63:0]		src;
output[63:0]	dst;

reg[11:0]		exa;
reg[11:0]		exb;
reg[63:0]		fra;
reg[63:0]		frb;

reg			sgn;
reg[5:0]	tShl;
reg[63:0]	tDst;
reg[63:0]	tDst2;

assign dst = tDst2;

always @ (clk && enable)
// always_ff
begin
	sgn=src[63];

	exa[11]=0;
	exa[10:0]=src[62:52];
	
	exb=exa-1075;

	if(sgn)
	begin
		fra[63:52]=~(12'h1);
		fra[51:0]=~(src[51:0]);
	end
	else
	begin
		fra[63:52]=12'h1;
		fra[51:0]=src[51:0];
	end
	
	if(exa>=1075)
	begin
		tShl[5:0]=exb[5:0];
		tDst=fra<<tShl;
	end
	else
	begin
		tShl[5:0]=-exb[5:0];
		tDst=fra>>>tShl;
	end
	
	if(is32)
	begin
		if(tDst[63:31]==33'h1_FFFF_FFFF)
			tDst2=tDst;
		else if(tDst[63:31]==33'h0_0000_0000)
			tDst2=tDst;
		else
			tDst2=64'h0000_00000_8000_0000;
	end
	else
		tDst2=tDst;
end

endmodule
