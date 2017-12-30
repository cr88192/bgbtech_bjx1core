/*
Text Mode Memory

Screen Memory is 4kB, and is organized into 32-bit cells.

Also has a 2kB fixed font.
 */

module ModTxtMem(clock, reset,
	pixCellIx, cellData,
	fontGlyph, fontData,
	busAddr, busData, busOE, busWR, busOK);

/* verilator lint_off UNUSED */

input clock;
input reset;

input[13:0] pixCellIx;
output[31:0] cellData;

input[15:0] fontGlyph;
output[63:0] fontData;

input[31:0] busAddr;
inout[31:0] busData;
input busOE;
input busWR;
output busOK;

reg			tBusOK;				//Read OK State
reg[31:0] 	tBusData;			//Output Data
wire		tBusCSel;			//Bus Chip-Select (Addr Matches)

assign	busOK = (busOE && tBusCSel) ? tBusOK : 1'bZ;
assign	busData = (busOE && tBusCSel) ? tBusData : 32'hZZZZ_ZZZZ;
assign  tBusCSel = (busAddr[31:16]==16'h0080);

reg[13:0]	tPixCellIx;			//base cell index
reg[13:0]	nxtPixCellIx;			//base cell index

(* ram_style="block" *) reg[31:0]	scrCell1[0:1023];

reg[63:0]	fontMem[255:0];
reg[63:0]	fontGfx1Mem[127:0];
reg[63:0]	fontGfx2Mem[127:0];

reg[31:0]	scrRegCtrl[7:0];	//Control Registers

reg[31:0]	tCell1;
reg[31:0]	tNextCell1;

reg[15:0]	tFontGlyph;
reg[63:0]	tFontData1;
reg[63:0]	tFontData2;
reg[63:0]	tFontDataAsc1;
reg[63:0]	tFontDataGfx1;
reg[63:0]	tFontDataGfx2;


assign cellData = tCell1;
assign fontData = tFontData1;

initial begin
	$readmemh("fontmem.txt", fontMem);
	$readmemh("gfxfont0.txt", fontGfx1Mem);
	$readmemh("gfxfont1.txt", fontGfx2Mem);
	$readmemh("scrmem.txt", scrCell1);
end

always @ (clock)
begin
	nxtPixCellIx	= pixCellIx;

	tBusOK = 0;
	tBusData = 0;
	if(busOE && tBusCSel)
	begin
		nxtPixCellIx	= busAddr[15:2];

		if(busAddr[15:8]==255)
		begin
			tBusOK=1;
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
			tBusOK = tPixCellIx == busAddr[15:2];
			tBusData = tCell1;
		end
	end

	tFontDataAsc1 = fontMem[tFontGlyph[7:0]];
	tFontDataGfx1 = fontGfx1Mem[tFontGlyph[6:0]];
	tFontDataGfx2 = fontGfx2Mem[tFontGlyph[6:0]];
	case(tFontGlyph[9:7])
	3'b000:	tFontData2 = tFontDataAsc1;
	3'b001:	tFontData2 = tFontDataAsc1;
	3'b010:	tFontData2 = tFontDataGfx2;
	3'b011:	tFontData2 = tFontDataGfx1;
//	3'b100:	tFontData2 = tFontDataAsc1;
//	3'b101:	tFontData2 = tFontDataGfx2;
	default: tFontData2 = tFontDataAsc1;
	endcase

end

always @ (posedge clock)
begin
//	tCell1			<= tNextCell1;
//	tPixCellIx		<= pixCellIx;

	tPixCellIx		<= nxtPixCellIx;
	tCell1			<= scrCell1[tPixCellIx[9:0]];
	
	tFontGlyph		<= fontGlyph;
	tFontData1		<= tFontData2;

//	case(tFontGlyph[9:8])
//	2'b00:	tFontData1		<= fontMem[tFontGlyph[7:0]];
//	2'b01:	tFontData1		<= fontGfxMem[tFontGlyph[7:0]];
//	endcase

	if(tBusCSel && busOE)
		tPixCellIx		<= busAddr[15:2];
	else
		tPixCellIx		<= pixCellIx;

	if(tBusCSel && busWR && !busOE)
	begin
		if(busAddr[15:8]==255)
		begin
			scrRegCtrl[busAddr[4:2]] <= busData;
		end
		else
		begin
			scrCell1[busAddr[11:2]] <= busData;
		end
	end
end

endmodule
