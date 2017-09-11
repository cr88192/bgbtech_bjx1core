/*
Quick and dirty approximate reciprocal.
TODO: try to make it "about right"
 */
module FpuFp32_Rcp(
	clk,
	src,
	dst
);

input			clk;
input[31:0]		src;
output[31:0]	dst;

reg[7:0]		exa;
reg[7:0]		exb;
reg[23:0]		fra;
reg[23:0]		frb;

reg[23:0]		tFr2;

always @ (clk)
begin
	exa[7:0]=src[30:23];

	fra[23]=0;
	fra[22:0]=src[22:0];

//	frb=24'h800000 -
//		(fra   )+(fra>>1)-(fra>>2)+(fra>>3)-
//		(fra>>4)+(fra>>5)-(fra>>6)+(fra>>7);

//	frb=24'h800000 -
//		(fra   )+(fra>>1)-(fra>> 4)+(fra>> 6)-
//		(fra>>4)+(fra>>5)-(fra>> 6)+(fra>> 7)-
//		(fra>>8)+(fra>>9)-(fra>>10)+(fra>>11);

	tFr2=(fra>>12)*(fra>>12);

//	frb=24'h800000 -
//		(fra>>1)-(fra>>4)-(fra>>6);

	frb=24'h800000 -
		(fra>>1)-(fra>>2)-(fra>>3)+(tFr2>>1)+(tFr2>>2);

//	frb=24'hF311C1 -
//		fra;

	if(frb[23])
	begin
		exb=254-exa;
//		exb=253-exa;
		dst[31]=src[31];
		dst[30:23]=exb[7:0];
		dst[22:0]=frb[22:0];
	end
	else
	begin
		exb=253-exa;
//		exb=252-exa;
		dst[31]=src[31];
		dst[30:23]=exb[7:0];
		dst[22:1]=frb[21:0];
	end
end

endmodule