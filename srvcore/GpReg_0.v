/*
Bank of GPRs.
*/

module GpReg(
	clk,

	isRd1,
	isWr1,
	isQw1,
	idReg1,
	dataLo1,
	dataHi1,

	isRd2,
	isWr2,
	isQw2,
	idReg2,
	dataLo2,
	dataHi2,

	isRd3,
	isWr3,
	isQw3,
	idReg3,
	dataLo3,
	dataHi3
	);

input clk;			//clock

input isRd1;		//Is Read
input isRd2;		//Is Read
input isRd3;		//Is Read

input isWr1;		//Is Write
input isWr2;		//Is Write
input isWr3;		//Is Write

input isQw1;		//Is QuadWord
input isQw2;		//Is QuadWord
input isQw3;		//Is QuadWord

input[6:0] idReg1;
input[6:0] idReg2;
input[6:0] idReg3;

inout[31:0] dataLo1;
inout[31:0] dataHi1;

inout[31:0] dataLo2;
inout[31:0] dataHi2;

inout[31:0] dataLo3;
inout[31:0] dataHi3;

reg[31:0] regs[0:127];

reg[6:0] tIdReg1Lo;
reg[6:0] tIdReg1Hi;
reg[6:0] tIdReg2Lo;
reg[6:0] tIdReg2Hi;
reg[6:0] tIdReg3Lo;
reg[6:0] tIdReg3Hi;

//reg[31:0] tDataLo1;
//reg[31:0] tDataHi1;
//reg[31:0] tDataLo2;
//reg[31:0] tDataHi2;
//reg[31:0] tDataLo3;
//reg[31:0] tDataHi3;

//assign	tIdReg1Lo[5:0] = idReg1;
//assign	tIdReg1Hi[5:0] = idReg1;
//assign	tIdReg1Lo[6] = 1'b0;
//assign	tIdReg1Hi[6] = 1'b1;

always @ (isRd1 or isWr1) begin
//	tIdReg1Lo[5:0] = idReg1;
//	tIdReg1Hi[5:0] = idReg1;
//	tIdReg1Lo[6] = 1'b0;
//	tIdReg1Hi[6] = 1'b1;

	tIdReg1Lo = idReg1;
	tIdReg1Hi = idReg1 | (7'h40);

	if(isRd1==1'b1)
	begin
		dataLo1 = regs[tIdReg1Lo];
		if(isQw1==1'b1)
			dataHi1 = regs[tIdReg1Hi];
	end

//	dataLo1 = tDataLo1;
//	dataHi1 = tDataHi1;

end

always @ (isRd2 or isWr2) begin
//	tIdReg2Lo[5:0] = idReg2;
//	tIdReg2Hi[5:0] = idReg2;
//	tIdReg2Lo[6] = 1'b0;
//	tIdReg2Hi[6] = 1'b1;

	tIdReg2Lo = idReg2;
	tIdReg2Hi = idReg2 | (7'h40);

	if(isRd2==1'b1)
	begin
		dataLo2 = regs[tIdReg2Lo];
		if(isQw2==1'b1)
			dataHi2 = regs[tIdReg2Hi];
	end
end

always @ (isRd3 or isWr3) begin
//	tIdReg3Lo[5:0] = idReg3;
//	tIdReg3Hi[5:0] = idReg3;
//	tIdReg3Lo[6] = 1'b0;
//	tIdReg3Hi[6] = 1'b1;

	tIdReg3Lo = idReg3;
	tIdReg3Hi = idReg3 | (7'h40);

	if(isRd3==1'b1)
	begin
		dataLo3 = regs[tIdReg3Lo];
		if(isQw3==1'b1)
			dataHi3 = regs[tIdReg3Hi];
	end
end

//always @ (posedge clk) begin
//end

always @ (negedge clk) begin
	if(isWr1==1'b1)
	begin
		regs[tIdReg1Lo] <= dataLo1;
		if(isQw1==1'b1)
			regs[tIdReg1Hi] <= dataHi1;
	end

	if(isWr2==1'b1)
	begin
		regs[tIdReg2Lo] <= dataLo2;
		if(isQw2==1'b1)
			regs[tIdReg2Hi] <= dataHi2;
	end

	if(isWr3==1'b1)
	begin
		regs[tIdReg3Lo] <= dataLo3;
		if(isQw3==1'b1)
			regs[tIdReg3Hi] <= dataHi3;
	end
end

endmodule
