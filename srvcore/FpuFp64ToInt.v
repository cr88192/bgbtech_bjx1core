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
		tDst=fra>>>tShl;
	end
	else
	begin
		tShl[5:0]=-exb[5:0];
		tDst=fra<<tShl;
	end
	
	if(is32)
	begin
		if(tDst[63:31]==33'h1_FFFF_FFFF)
			dst=tDst;
		else if(tDst[63:31]==33'h0_0000_0000)
			dst=tDst;
		else
			dst=64'h0000_00000_8000_0000;
	end
	else
		dst=tDst;
end

endmodule
