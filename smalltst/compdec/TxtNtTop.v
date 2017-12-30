`include "TxtNtModW.v"

module TxtNtTop(clock, reset, pwmOut);

/* verilator lint_off UNUSED */

input clock;
input reset;
output pwmOut;

TxtNtModW txtntmod(clock, reset, tPwmOut,
	tBusAddr, tBusData, tBusOE, tBusWR, tBusOK);

wire[3:0] tPwmOut;
wire tBusOK;
wire[31:0] tBusData;

reg[31:0] tBusAddr;
reg tBusOE;
reg tBusWR;

assign pwmOut = tPwmOut[3];

always @ (clock)
begin
	tBusAddr = 0;
//	tBusData = 0;
	tBusOE = 0;
	tBusWR = 0;
end

endmodule

