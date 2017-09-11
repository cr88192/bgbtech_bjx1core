`include "ModNtsc.v"
`include "ModFbMem.v"
`include "ModFbCc.v"


module FbNtMod(clock, reset, pwmOut,
	busAddr, busData, busOE, busWR, busHold);

/* verilator lint_off UNUSED */

input clock;
input reset;

output[3:0] pwmOut;

input[39:0] busAddr;
inout[31:0] busData;
input busOE;
input busWR;
output busHold;

wire[7:0] pixCy;
wire[7:0] pixCu;
wire[7:0] pixCv;

wire[9:0] pixPosX;
wire[9:0] pixPosY;

wire[13:0] pixCellIx;
wire[31:0] cellData1;
wire[31:0] cellData2;

ModNtsc ntsc(clock, reset,
	pixCy, pixCu, pixCv,
	pwmOut, pixPosX, pixPosY);

ModFbMem fbmem(clock, reset,
	pixCellIx, cellData1, cellData2,
	busAddr, busData, busOE, busWR, busHold);

ModFbCc fbcc(clock, reset,
	pixPosX, pixPosY,
	pixCy, pixCu, pixCv,
	pixCellIx, cellData1, cellData2);

endmodule
