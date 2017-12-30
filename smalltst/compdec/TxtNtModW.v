`include "ModNtsc.v"
`include "ModTxtMemW.v"
`include "ModFbTxtW.v"


module TxtNtModW(clock, reset, pwmOut,
	busAddr, busData, busOE, busWR, busOK);

/* verilator lint_off UNUSED */

input clock;
input reset;

output[3:0] pwmOut;

input[31:0] busAddr;
inout[31:0] busData;
input busOE;
input busWR;
output busOK;

wire[7:0] pixCy;
wire[7:0] pixCu;
wire[7:0] pixCv;

wire[9:0] pixPosX;
wire[9:0] pixPosY;

wire[13:0] pixCellIx;
wire[127:0] cellData1;
// wire[31:0] cellData2;

wire[15:0] fontGlyph;
wire[63:0] fontData1;

ModNtsc ntsc(clock, reset,
	pixCy, pixCu, pixCv,
	pwmOut, pixPosX, pixPosY);

ModTxtMemW fbmem(clock, reset,
	pixCellIx, cellData1,
	fontGlyph, fontData1,
	busAddr, busData, busOE, busWR, busOK);

ModFbTxtW fbcc(clock, reset,
	pixPosX, pixPosY,
	pixCy, pixCu, pixCv,
	pixCellIx, cellData1,
	fontGlyph, fontData1);

endmodule
