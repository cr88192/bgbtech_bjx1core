module FpuFp32To64(
	/* verilator lint_off UNUSED */
	clk,
	enable,
	src,
	dst
);

input			clk;
input			enable;
input[31:0]		src;
output[63:0]	dst;

reg[11:0]		exa;
reg[11:0]		exb;
// reg[23:0]		fra;
// reg[52:0]		frb;

reg[63:0]	tDst;
assign dst = tDst;

// always @ (clk && enable)
always @*
begin
	exa[11:8]=0;
	exa[ 7:0]=src[30:23];

	tDst=0;

	if(exa[7:0]==8'h00)
	begin
		tDst[63:0]=0;
	end
	else
	if(exa[7:0]==8'hFF)
	begin
		tDst[63]=src[31];
		tDst[62:52]=11'h7FF;
		tDst[51:29]=src[22:0];
		tDst[28:0]=0;
	end
	else
	begin
		exb=exa+(1023-127);
		tDst[63]=src[31];
		tDst[62:52]=exb[10:0];
		tDst[51:29]=src[22:0];
		tDst[28:0]=0;
	end
end

endmodule
