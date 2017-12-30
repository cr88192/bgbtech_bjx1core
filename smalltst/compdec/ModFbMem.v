/*
Screen Memory is 4kB
It is expected that an ISR will be used to update the screen memory during output.
 */

module ModFbMem(clock, reset,
	pixCellIx, cellData1, cellData2,
	busAddr, busData, busOE, busWR, busHold);

/* verilator lint_off UNUSED */

input clock;
input reset;

input[13:0] pixCellIx;
output[31:0] cellData1;
output[31:0] cellData2;

input[39:0] busAddr;
inout[31:0] busData;
input busOE;
input busWR;
output busHold;

reg			tBusHold;			//IO Hold State
reg[31:0] 	tBusData;			//Output Data
wire		tBusCSel;			//Bus Chip-Select (Addr Matches)

assign	busHold = (busOE && tBusCSel) ? tBusHold : 1'bZ;
assign	busData = (busOE && tBusCSel) ? tBusData : 32'hZZZZ_ZZZZ;
// assign	busHold = 1'bZ;
// assign	busData = 32'hZZZZ_ZZZZ;
assign  tBusCSel = (busAddr[39:16]==24'hA0_A000) ||
	(busAddr[39:16]==24'h00_ACA0) ||
	(busAddr[39:16]==24'h00_ACA1);

// wire[13:0]	tReadAddr;
// assign	tReadAddr = (busOE && tBusCSel) ? busAddr[15:2] : pixCellIx;
// assign	tReadAddr = pixCellIx;

reg[13:0]	tPixCellIx;			//base cell index
// reg[13:0]	tPixCellNextIx;		//base cell index

//reg[31:0]	scrCell1A[0:4095];	//Screen Memory (1/2 32kB)
//reg[31:0]	scrCell1B[0:4095];	//Screen Memory (1/2 32kB)
//reg[31:0]	scrCell2A[0:1023];	//Screen Memory (1/2 8kB)
//reg[31:0]	scrCell2B[0:1023];	//Screen Memory (1/2 8kB)

// (* ram_style="block" *) reg[31:0]	scrCell1A[0:2047];	//Screen Memory (1/2 32kB)
// (* ram_style="block" *) reg[31:0]	scrCell1B[0:2047];	//Screen Memory (1/2 32kB)
// (* ram_style="block" *) reg[31:0]	scrCell2A[0:511];	//Screen Memory (1/2 8kB)
// (* ram_style="block" *) reg[31:0]	scrCell2B[0:511];	//Screen Memory (1/2 8kB)

// (* ram_style="block" *) reg[31:0]	scrCell1A[0:1023];
// (* ram_style="block" *) reg[31:0]	scrCell1B[0:1023];
(* ram_style="block" *) reg[31:0]	scrCell1A[0:511];
(* ram_style="block" *) reg[31:0]	scrCell1B[0:511];

reg[31:0]	scrRegCtrl[7:0];	//Control Registers
reg			scrIs320;			//use 320x240 64 bit cells

reg			scrCellNoRead;

reg[31:0]	tCell1;
reg[31:0]	tCell2;
reg[31:0]	tNextCell1;
reg[31:0]	tNextCell2;

assign cellData1 = tCell1;
assign cellData2 = tCell2;

always @ (clock)
begin

	tBusHold = 1;
	tBusData = 0;
	if(busOE && tBusCSel)
	begin
		if(busAddr[15:8]==255)
		begin
//			scrRegCtrl[busAddr[4:2]] <= busData;
			tBusHold=0;
			case(busAddr[6:2])
			0: tBusData = scrRegCtrl[0];
			1: tBusData = scrRegCtrl[1];
			2: tBusData = scrRegCtrl[2];
			3: tBusData = scrRegCtrl[3];

			8: tBusData = {18'h0, pixCellIx};

			endcase
		end
		else
		begin
//			tPixCellNextIx = busAddr[15:2];
//			tBusHold = tPixCellIx != tPixCellNextIx;
			tBusHold = tPixCellIx != busAddr[15:2];
			tBusData = busAddr[2] ? tCell2 : tCell1;
		end
	end
end

always @ (posedge clock)
begin

//	tPixCellIx		<= pixCellIx;
	tCell1			<= tNextCell1;
	tCell2			<= tNextCell2;
	tPixCellIx		<= pixCellIx;

	if(tBusCSel && busWR && !busOE)
	begin
//		scrCellNoRead <= 1;
		scrCellNoRead <= 0;

		if(busAddr[15:8]==255)
		begin
			scrRegCtrl[busAddr[4:2]] <= busData;
		end
		else
		begin
//			$display("%X %X", busAddr, busData);
		
			if(busAddr[2])
				scrCell1B[busAddr[11:3]] <= busData;
			else
				scrCell1A[busAddr[11:3]] <= busData;
		end
	end
end

always @ (posedge clock)
begin
//	if(!busWR)
//	begin
//		scrCellNoRead <= 0;
//		tNextCell1 <= scrCell1A[tReadAddr[10:1]];
//		tNextCell2 <= scrCell1B[tReadAddr[10:1]];
//	end

	tNextCell1 <= scrCell1A[pixCellIx[9:1]];
	tNextCell2 <= scrCell1B[pixCellIx[9:1]];
end


endmodule
