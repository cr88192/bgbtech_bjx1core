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
assign  tBusCSel = (busAddr[39:16]==24'hA0_A000);

wire[13:0]	tReadAddr;
assign	tReadAddr = (busOE && tBusCSel) ? busAddr[15:2] : pixCellIx;

reg[13:0]	tPixCellIx;			//base cell index
// reg[13:0]	tPixCellNextIx;		//base cell index

//reg[31:0]	scrCell1A[0:4095];	//Screen Memory (1/2 32kB)
//reg[31:0]	scrCell1B[0:4095];	//Screen Memory (1/2 32kB)
//reg[31:0]	scrCell2A[0:1023];	//Screen Memory (1/2 8kB)
//reg[31:0]	scrCell2B[0:1023];	//Screen Memory (1/2 8kB)

(* ram_style="block" *) reg[31:0]	scrCell1A[0:2047];	//Screen Memory (1/2 32kB)
(* ram_style="block" *) reg[31:0]	scrCell1B[0:2047];	//Screen Memory (1/2 32kB)
(* ram_style="block" *) reg[31:0]	scrCell2A[0:511];	//Screen Memory (1/2 8kB)
(* ram_style="block" *) reg[31:0]	scrCell2B[0:511];	//Screen Memory (1/2 8kB)

/*
(* ram_style="block" *) reg[15:0]	scrCell1A[0:2047];	//Screen Memory (1/2 32kB)
(* ram_style="block" *) reg[15:0]	scrCell1B[0:2047];	//Screen Memory (1/2 32kB)
(* ram_style="block" *) reg[15:0]	scrCell1C[0:2047];	//Screen Memory (1/2 32kB)
(* ram_style="block" *) reg[15:0]	scrCell1D[0:2047];	//Screen Memory (1/2 32kB)
(* ram_style="block" *) reg[15:0]	scrCell2A[0:511];	//Screen Memory (1/2 8kB)
(* ram_style="block" *) reg[15:0]	scrCell2B[0:511];	//Screen Memory (1/2 8kB)
(* ram_style="block" *) reg[15:0]	scrCell2C[0:511];	//Screen Memory (1/2 8kB)
(* ram_style="block" *) reg[15:0]	scrCell2D[0:511];	//Screen Memory (1/2 8kB)
*/

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
//		tPixCellNextIx = busAddr[15:2];
//		tBusHold = tPixCellIx != tPixCellNextIx;
		tBusHold = tPixCellIx != busAddr[15:2];
		tBusData = busAddr[2] ? tCell2 : tCell1;
	end

/*
	if(scrCellNoRead)
	begin
		tNextCell1 = tCell1;
		tNextCell2 = tCell2;
	end
	else
	begin
		if(tPixCellIx[13])
		begin
			tNextCell1 = scrCell2A[tPixCellIx[10:1]];
			tNextCell2 = scrCell2B[tPixCellIx[10:1]];
		end
		else
		begin
			tNextCell1 = scrCell1A[tPixCellIx[12:1]];
			tNextCell2 = scrCell1B[tPixCellIx[12:1]];
		end
	end
*/

end

always @ (posedge clock)
begin

//	tPixCellIx		<= pixCellIx;
	tCell1			<= tNextCell1;
	tCell2			<= tNextCell2;

	if(tBusCSel && busOE && !busWR)
	begin
		tPixCellIx		<= busAddr[15:2];
	end
	else
	begin
		tPixCellIx		<= pixCellIx;
	end

	if(tBusCSel && busWR && !busOE)
	begin
		scrCellNoRead <= 1;

		if(busAddr[15:8]==255)
		begin
			scrRegCtrl[busAddr[4:2]] <= busData;
		end
//		else if(busAddr[15])
		else if(busAddr[14])
		begin
//			if(busAddr[2])
//				scrCell2B[busAddr[12:3]] <= busData;
//			else
//				scrCell2A[busAddr[12:3]] <= busData;

			if(busAddr[2])
			begin
				scrCell2B[busAddr[11:3]] <= busData;
//				scrCell2C[busAddr[11:3]] <= busData[15: 0];
//				scrCell2D[busAddr[11:3]] <= busData[31:16];
			end
			else
			begin
				scrCell2A[busAddr[11:3]] <= busData;
//				scrCell2A[busAddr[11:3]] <= busData[15: 0];
//				scrCell2B[busAddr[11:3]] <= busData[31:16];
			end
		end
		else
		begin
//			if(busAddr[2])
//				scrCell1B[busAddr[14:3]] <= busData;
//			else
//				scrCell1A[busAddr[14:3]] <= busData;

			if(busAddr[2])
			begin
				scrCell1B[busAddr[13:3]] <= busData;
//				scrCell1C[busAddr[13:3]] <= busData[15: 0];
//				scrCell1D[busAddr[13:3]] <= busData[31:16];
			end
			else
			begin
				scrCell1A[busAddr[13:3]] <= busData;
//				scrCell1A[busAddr[13:3]] <= busData[15: 0];
//				scrCell1B[busAddr[13:3]] <= busData[31:16];
			end
		end
	end
end

always @ (posedge clock)
begin
	if(!busWR)
	begin
		scrCellNoRead <= 0;

/*
		if(tReadAddr[13])
		begin
			tNextCell1 <= scrCell2A[tReadAddr[10:1]];
			tNextCell2 <= scrCell2B[tReadAddr[10:1]];
		end
		else
		begin
			tNextCell1 <= scrCell1A[tReadAddr[12:1]];
			tNextCell2 <= scrCell1B[tReadAddr[12:1]];
		end
*/

		if(tReadAddr[12])
		begin
			tNextCell1 <= scrCell2A[tReadAddr[9:1]];
			tNextCell2 <= scrCell2B[tReadAddr[9:1]];

//			tNextCell1[15: 0] <= scrCell2A[tReadAddr[9:1]];
//			tNextCell1[31:16] <= scrCell2B[tReadAddr[9:1]];
//			tNextCell2[15: 0] <= scrCell2C[tReadAddr[9:1]];
//			tNextCell2[31:16] <= scrCell2D[tReadAddr[9:1]];
		end
		else
		begin
			tNextCell1 <= scrCell1A[tReadAddr[11:1]];
			tNextCell2 <= scrCell1B[tReadAddr[11:1]];

//			tNextCell1[15: 0] <= scrCell1A[tReadAddr[11:1]];
//			tNextCell1[31:16] <= scrCell1B[tReadAddr[11:1]];
//			tNextCell2[15: 0] <= scrCell1C[tReadAddr[11:1]];
//			tNextCell2[31:16] <= scrCell1D[tReadAddr[11:1]];
		end

	end

end


endmodule