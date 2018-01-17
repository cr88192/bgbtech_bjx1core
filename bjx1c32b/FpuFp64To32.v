module FpuFp64To32(
	clk,
	enable,
	src,
	dst
);

input			clk;
input			enable;
input[63:0]		src;
output[31:0]	dst;

reg[11:0]		exa;
reg[11:0]		exb;
// reg[23:0]		fra;
// reg[52:0]		frb;

reg[31:0]	tDst;
assign dst = tDst;

//always @ (clk && enable)
always @*
// always_ff
begin
	exa[11]=0;
	exa[10:0]=src[62:52];
	
/*
	exb=exa-(1023-127);
	
	if(exb[11:8]==0)
	begin
		tDst[31]=src[63];
		tDst[30:23]=exb[7:0];
		tDst[22:0]=src[51:29];
	end
	else
	if(exb[11])
	begin
		tDst[31:0]=0;
	end
	else
	begin
		tDst[31]=src[63];
		tDst[30:23]=8'hFF;
		tDst[22:0]=23'h80_0000;
	end
*/

	casez(exa[10:7])
	4'b0111: begin
		tDst[31]=src[63];
		tDst[30:29]=2'b01;
		tDst[28:23]=exa[5:0];
		tDst[22:0]=src[51:29];
	end
	4'b1000: begin
		tDst[31]=src[63];
		tDst[30:29]=2'b10;
		tDst[28:23]=exa[5:0];
		tDst[22:0]=src[51:29];
	end

	default: begin
		tDst[31:0]=exa[10] ?
			{src[63], 31'h7F80_0000} :
			32'h0000_0000;
	end

	endcase
	
end

endmodule
