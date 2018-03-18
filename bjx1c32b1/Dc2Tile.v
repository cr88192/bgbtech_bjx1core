/*
L2 Data Cache

This version will use the Cache as RAM,
0C00_0000 .. 0C00_FFFF

0000_0000 .. 0000_3FFF: Boot ROM
0000_4000 .. 0000_4FFF: Boot SRAM

May be accessed either as 128 bit tiles, or as 32 or 64 bit words.
MMIO may only be accessed as 32-bits.

Boot SRAM is reserved for use by the Boot ROM / Firmware.
A program running in main RAM should not use it.
 */

`include "CoreDefs.v"

module Dc2Tile(
	/* verilator lint_off UNUSED */
	clock,			reset,
	regInAddr,		regInData,
	regOutData,		regOutOK,
	regInOE,		regInWR,
	regInOp,

	memInData,		memOutData,		memAddr,
	memOE,			memWR,			memOK,

	mmioInData,		mmioOutData,	mmioAddr,		
	mmioOE,			mmioWR,			mmioOK
	);

input			clock;			//clock
input			reset;			//reset
input[31:0]		regInAddr;		//input PC address
input[127:0]	regInData;		//input data (store)
input			regInOE;		//Load
input			regInWR;		//Store
input[4:0]		regInOp;		//Operation Size/Type

output[127:0]	regOutData;		//output data (load)
output[1:0]		regOutOK;		//set if operation suceeds

input[127:0]	memInData;	//memory PC data
output[127:0]	memOutData;	//memory PC data
output[31:0]	memAddr;	//memory PC address
output			memOE;		//memory PC output-enable
output			memWR;		//memory PC output-enable
input[1:0]		memOK;		//memory PC OK

reg[127:0]		tMemOutData;	//memory PC data
reg[31:0]		tMemAddr;		//memory PC address
reg				tMemOE;			//memory PC output-enable
reg				tMemWR;			//memory PC output-enable

assign			memOutData	= tMemOutData;
assign			memAddr		= tMemAddr;
assign			memOE		= tMemOE;
assign			memWR		= tMemWR;


input[31:0]		mmioInData;		//mmio data in
output[31:0]	mmioOutData;	//mmio data out
output[31:0]	mmioAddr;		//mmio address
output			mmioOE;			//mmio read
output			mmioWR;			//mmio write
input[1:0]		mmioOK;			//mmio OK


reg[31:0]		tMmioOutData;	//mmio data out
reg[31:0]		tMmioAddr;		//mmio address
reg				tMmioOE;		//mmio read
reg				tMmioWR;		//mmio write

assign			mmioOutData	= tMmioOutData;
assign			mmioAddr	= tMmioAddr;
assign			mmioOE		= tMmioOE;
assign			mmioWR		= tMmioWR;



// (* ram_style="block" *) reg[127:0]		memTile[2047:0];	//memory
(* ram_style="block" *) reg[31:0]		memTileA[0:4095];	//memory
(* ram_style="block" *) reg[31:0]		memTileB[0:4095];	//memory
(* ram_style="block" *) reg[31:0]		memTileC[0:4095];	//memory
(* ram_style="block" *) reg[31:0]		memTileD[0:4095];	//memory

// (* ram_style="block" *) reg[127:0]		romTile[255:0];		//ROM
(* ram_style="block" *) reg[31:0]		romTileA[1023:0];		//ROM
(* ram_style="block" *) reg[31:0]		romTileB[1023:0];		//ROM
(* ram_style="block" *) reg[31:0]		romTileC[1023:0];		//ROM
(* ram_style="block" *) reg[31:0]		romTileD[1023:0];		//ROM

(* ram_style="block" *) reg[31:0]		sramTileA[255:0];		//SRAM
(* ram_style="block" *) reg[31:0]		sramTileB[255:0];		//SRAM
(* ram_style="block" *) reg[31:0]		sramTileC[255:0];		//SRAM
(* ram_style="block" *) reg[31:0]		sramTileD[255:0];		//SRAM

reg[127:0]		tRomTile;
reg[127:0]		tRamTile;
reg[127:0]		tSRamTile;
reg[11:0]		tAccTileIx;


reg[127:0]		tMemTile;
reg[127:0]		tOutData;

reg[127:0]		tNextTile;

reg[11:0]		tRegTileIx;
reg[11:0]		tNextTileIx;
reg				tNextTileSt;
reg				tNextTileSrSt;
reg[1:0]		tRegOutOK;


wire		addrIsRam;
assign		addrIsRam =
	(regInAddr[28:0] >= 29'h0C00_0000) &&
	(regInAddr[28:0] <= 29'h1E00_0000) ;

wire			addrIsRom;
assign		addrIsRom =
	(regInAddr[28:0] <= 29'h0010_0000) &&
	(regInAddr[14] == 0);

wire			addrIsSRam;
assign		addrIsSRam =
	(regInAddr[28:0] <= 29'h0010_0000) &&
	(regInAddr[14] == 1);

assign		regOutData = tOutData;
assign		regOutOK = tRegOutOK;

initial begin
//	$readmemh("bootrom.txt", romTile);
	$readmemh("bootrom_1a.txt", romTileA);
	$readmemh("bootrom_1b.txt", romTileB);
	$readmemh("bootrom_1c.txt", romTileC);
	$readmemh("bootrom_1d.txt", romTileD);
end

always @*
begin
	tMemTile		= 0;
	tOutData		= 0;
	tNextTile		= 0;
	tRegTileIx		= regInAddr[15:4];
	tNextTileIx		= tRegTileIx;
	tNextTileSt		= 0;
	tNextTileSrSt	= 0;
	tRegOutOK		= 0;

	tMemOutData		= 0;	//memory PC data
	tMemAddr		= 0;	//memory PC address
	tMemOE			= 0;	//memory PC output-enable
	tMemWR			= 0;	//memory PC output-enable

	tMmioOutData	= 0;	//mmio data out
	tMmioAddr		= 0;	//mmio address
	tMmioOE			= 0;	//mmio read
	tMmioWR			= 0;	//mmio write

	if(regInOE || regInWR)
	begin

		$display("DcTile2 %X %d %d", regInAddr, addrIsRom, addrIsRam);

		if(addrIsRom)
		begin
//			tMemTile = romTile[tRegTileIx[7:0]];
			tMemTile = tRomTile;
			tNextTile = tMemTile;
//			tRegOutOK = 1;
			tRegOutOK = (tAccTileIx == tRegTileIx) ?
				UMEM_OK_OK : UMEM_OK_HOLD;
			
			$display("Rom: %X", tMemTile);

			case(regInOp[1:0])
				2'b00:
					tOutData=tMemTile;
				2'b01:
					tOutData=tMemTile;
				2'b10: case(regInAddr[3:2])
					2'b00: tOutData={96'h0, tMemTile[ 31: 0]};
					2'b01: tOutData={96'h0, tMemTile[ 63:32]};
					2'b10: tOutData={96'h0, tMemTile[ 95:64]};
					2'b11: tOutData={96'h0, tMemTile[127:96]};
				endcase
				2'b11: begin
					if(regInAddr[3])
						tOutData={64'h0, tMemTile[127:64]};
					else
						tOutData={64'h0, tMemTile[ 63: 0]};
				end
			endcase

			$display("Rom: Out=%X", tOutData);
		end
		else
		if(addrIsRam || addrIsSRam)
		begin
//			tMemTile = memTile[tRegTileIx];
//			tMemTile[ 31: 0] = memTileA[tRegTileIx];
//			tMemTile[ 63:32] = memTileB[tRegTileIx];
//			tMemTile[ 95:64] = memTileC[tRegTileIx];
//			tMemTile[127:96] = memTileD[tRegTileIx];
//			tMemTile = tRamTile;
			tMemTile = addrIsSRam ? tSRamTile : tRamTile;
			tNextTile = tMemTile;
//			tRegOutOK = 1;
			tRegOutOK = (tAccTileIx == tRegTileIx) ?
				UMEM_OK_OK : UMEM_OK_HOLD;

			case(regInOp[1:0])
				2'b00:
					tOutData=tMemTile;
				2'b01:
					tOutData=tMemTile;
				2'b10: case(regInAddr[3:2])
					2'b00: tOutData={96'h0, tMemTile[ 31: 0]};
					2'b01: tOutData={96'h0, tMemTile[ 63:32]};
					2'b10: tOutData={96'h0, tMemTile[ 95:64]};
					2'b11: tOutData={96'h0, tMemTile[127:96]};
				endcase
				2'b11: begin
					if(regInAddr[3])
						tOutData={64'h0, tMemTile[127:64]};
					else
						tOutData={64'h0, tMemTile[ 63: 0]};
				end
			endcase
		
			if(regInWR)
			begin
				tNextTileIx = tRegTileIx;
//				tNextTileSt = 1;
				tNextTileSt = addrIsRam;
				tNextTileSrSt = addrIsSRam;
				case(regInOp[1:0])
					2'b00:
						tNextTile=regInData;
					2'b01:
						tNextTile=regInData;
					2'b10: case(regInAddr[3:2])
						2'b00: tNextTile[ 31: 0] = regInData[31:0];
						2'b01: tNextTile[ 63:32] = regInData[31:0];
						2'b10: tNextTile[ 95:64] = regInData[31:0];
						2'b11: tNextTile[127:96] = regInData[31:0];
					endcase
					2'b11: begin
						if(regInAddr[3])
							tNextTile[127:64] = regInData[63:0];
						else
							tNextTile[ 63: 0] = regInData[63:0];
					end
				endcase
			end
		end
		else
		begin
			tMmioOutData	= regInData[31:0];
			tMmioAddr		= regInAddr;
			tMmioOE			= regInOE;
			tMmioWR			= regInWR;
			tRegOutOK		= mmioOK;
			tOutData		= { 96'h0, mmioInData[31:0] };
		end

	end
end

always @ (posedge clock)
begin
//	tRomTile <= romTile[tRegTileIx[7:0]];
//	tRamTile <= memTile[tRegTileIx];

	tRomTile[ 31: 0] <= romTileA[tRegTileIx[9:0]];
	tRomTile[ 63:32] <= romTileB[tRegTileIx[9:0]];
	tRomTile[ 95:64] <= romTileC[tRegTileIx[9:0]];
	tRomTile[127:96] <= romTileD[tRegTileIx[9:0]];

	tSRamTile[ 31: 0] <= sramTileA[tRegTileIx[7:0]];
	tSRamTile[ 63:32] <= sramTileB[tRegTileIx[7:0]];
	tSRamTile[ 95:64] <= sramTileC[tRegTileIx[7:0]];
	tSRamTile[127:96] <= sramTileD[tRegTileIx[7:0]];

	tRamTile[ 31: 0] <= memTileA[tRegTileIx];
	tRamTile[ 63:32] <= memTileB[tRegTileIx];
	tRamTile[ 95:64] <= memTileC[tRegTileIx];
	tRamTile[127:96] <= memTileD[tRegTileIx];
	tAccTileIx <= tRegTileIx;

	if(tNextTileSt)
	begin
//		memTile[tNextTileIx] <= tNextTile;
		memTileA[tNextTileIx] <= tNextTile[ 31: 0];
		memTileB[tNextTileIx] <= tNextTile[ 63:32];
		memTileC[tNextTileIx] <= tNextTile[ 95:64];
		memTileD[tNextTileIx] <= tNextTile[127:96];
	end

	if(tNextTileSrSt)
	begin
		sramTileA[tRegTileIx[7:0]] <= tNextTile[ 31: 0];
		sramTileB[tRegTileIx[7:0]] <= tNextTile[ 63:32];
		sramTileC[tRegTileIx[7:0]] <= tNextTile[ 95:64];
		sramTileD[tRegTileIx[7:0]] <= tNextTile[127:96];
	end
end


endmodule
