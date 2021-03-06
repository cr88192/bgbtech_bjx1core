/*
Quick and dirty approximate reciprocal.
TODO: try to make it "about right"
 */
module FpuFp64_Rcp(
	clk,
	src,
	dst
);

input			clk;
input[63:0]		src;
output[63:0]	dst;

reg[12:0]		exa;
reg[12:0]		exb;
reg[52:0]		fra;
reg[52:0]		frb;

reg[52:0]		tFr2;
reg[52:0]		tFr3;

reg[63:0]		tDst;

assign dst = tDst;

reg[15:0]	rcpLut[255:0];

initial begin
	$readmemh("rcplut0.txt", rcpLut);
end

/*
reg[15:0]	rcpLut[256]= '{
16'h8000, 16'h7F80, 16'h7F01, 16'h7E84,
16'h7E07, 16'h7D8C, 16'h7D11, 16'h7C97,
16'h7C1F, 16'h7BA7, 16'h7B30, 16'h7ABA,
16'h7A44, 16'h79D0, 16'h795C, 16'h78EA,
16'h7878, 16'h7807, 16'h7797, 16'h7728,
16'h76B9, 16'h764B, 16'h75DE, 16'h7572,
16'h7507, 16'h749C, 16'h7432, 16'h73C9,
16'h7361, 16'h72F9, 16'h7292, 16'h722C,
16'h71C7, 16'h7162, 16'h70FE, 16'h709A,
16'h7038, 16'h6FD6, 16'h6F74, 16'h6F13,
16'h6EB3, 16'h6E54, 16'h6DF5, 16'h6D97,
16'h6D3A, 16'h6CDD, 16'h6C80, 16'h6C25,
16'h6BCA, 16'h6B6F, 16'h6B15, 16'h6ABC,
16'h6A63, 16'h6A0B, 16'h69B4, 16'h695D,
16'h6906, 16'h68B0, 16'h685B, 16'h6806,
16'h67B2, 16'h675E, 16'h670B, 16'h66B8,
16'h6666, 16'h6614, 16'h65C3, 16'h6572,
16'h6522, 16'h64D3, 16'h6483, 16'h6435,
16'h63E7, 16'h6399, 16'h634C, 16'h62FF,
16'h62B2, 16'h6267, 16'h621B, 16'h61D0,
16'h6186, 16'h613C, 16'h60F2, 16'h60A9,
16'h6060, 16'h6018, 16'h5FD0, 16'h5F88,
16'h5F41, 16'h5EFA, 16'h5EB4, 16'h5E6E,
16'h5E29, 16'h5DE4, 16'h5D9F, 16'h5D5B,
16'h5D17, 16'h5CD3, 16'h5C90, 16'h5C4D,
16'h5C0B, 16'h5BC9, 16'h5B87, 16'h5B46,
16'h5B05, 16'h5AC5, 16'h5A84, 16'h5A45,
16'h5A05, 16'h59C6, 16'h5987, 16'h5949,
16'h590B, 16'h58CD, 16'h588F, 16'h5852,
16'h5816, 16'h57D9, 16'h579D, 16'h5761,
16'h5726, 16'h56EA, 16'h56B0, 16'h5675,
16'h563B, 16'h5601, 16'h55C7, 16'h558E,
16'h5555, 16'h551C, 16'h54E4, 16'h54AB,
16'h5474, 16'h543C, 16'h5405, 16'h53CE,
16'h5397, 16'h5361, 16'h532A, 16'h52F4,
16'h52BF, 16'h5289, 16'h5254, 16'h5220,
16'h51EB, 16'h51B7, 16'h5183, 16'h514F,
16'h511B, 16'h50E8, 16'h50B5, 16'h5082,
16'h5050, 16'h501E, 16'h4FEC, 16'h4FBA,
16'h4F88, 16'h4F57, 16'h4F26, 16'h4EF5,
16'h4EC4, 16'h4E94, 16'h4E64, 16'h4E34,
16'h4E04, 16'h4DD5, 16'h4DA6, 16'h4D77,
16'h4D48, 16'h4D19, 16'h4CEB, 16'h4CBD,
16'h4C8F, 16'h4C61, 16'h4C34, 16'h4C07,
16'h4BDA, 16'h4BAD, 16'h4B80, 16'h4B54,
16'h4B27, 16'h4AFB, 16'h4AD0, 16'h4AA4,
16'h4A79, 16'h4A4D, 16'h4A22, 16'h49F7,
16'h49CD, 16'h49A2, 16'h4978, 16'h494E,
16'h4924, 16'h48FA, 16'h48D1, 16'h48A8,
16'h487E, 16'h4855, 16'h482D, 16'h4804,
16'h47DC, 16'h47B3, 16'h478B, 16'h4763,
16'h473C, 16'h4714, 16'h46ED, 16'h46C5,
16'h469E, 16'h4678, 16'h4651, 16'h462A,
16'h4604, 16'h45DE, 16'h45B8, 16'h4592,
16'h456C, 16'h4546, 16'h4521, 16'h44FC,
16'h44D7, 16'h44B2, 16'h448D, 16'h4468,
16'h4444, 16'h441F, 16'h43FB, 16'h43D7,
16'h43B3, 16'h4390, 16'h436C, 16'h4349,
16'h4325, 16'h4302, 16'h42DF, 16'h42BC,
16'h429A, 16'h4277, 16'h4254, 16'h4232,
16'h4210, 16'h41EE, 16'h41CC, 16'h41AA,
16'h4189, 16'h4167, 16'h4146, 16'h4125,
16'h4104, 16'h40E3, 16'h40C2, 16'h40A1,
16'h4081, 16'h4060, 16'h4040, 16'h4020
};
*/

always @ (clk)
begin
	exa[12:11]=0;
	exa[10:0]=src[62:52];

	fra[52]=0;
	fra[51:0]=src[51:0];

	tDst = 0;

//	tFr2=(fra>>26)*(fra>>26);

//	frb=53'h0010_0000_0000_0000 -
//		(fra>>1)-(fra>>4)-(fra>>6);

//	frb=53'h0010_0000_0000_0000 -
//		(fra>>1)-(fra>>2)-(fra>>3)+(tFr2>>1)+(tFr2>>2);

	tFr2[52:37]=rcpLut[fra[51:44]];
	tFr2[36:0]=0;
	
	tFr3[52:44]=0;
	tFr3[43:0]=(fra[43:0]>>1)-(fra[43:0]>>6);

	case(tFr2[52:49])
		4'h8: frb=tFr2-(tFr3<<1);
		4'h7: frb=tFr2-(tFr3<<1);
		4'h6: frb=tFr2-(tFr3   );
		4'h5: frb=tFr2-(tFr3   );
		4'h4: frb=tFr2-(tFr3>>1);
		default:	frb=tFr2;
	endcase

	if(frb[52])
	begin
		exb=2046-exa;
		tDst[63]=src[63];
		tDst[62:52]=exb[10:0];
		tDst[51:0]=frb[51:0];
	end
	else
	begin
		exb=2045-exa;
		tDst[63]=src[63];
		tDst[62:52]=exb[10:0];
		tDst[51:1]=frb[50:0];
	end
end

endmodule