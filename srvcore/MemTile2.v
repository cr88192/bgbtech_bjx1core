/*
Memory Tile Interface

Keeps a Code and Data buffer.
May attempt to perform external IO if address isn't in cache.
*/

module MemTile2(
	/* verilator lint_off UNUSED */
	clk,
	reset,

	opRd,
	opWr,
	opMode,
	memAddr,
	rdValue,
	wrValue,

	iopRd,
	imemAddr,
	irdValue,

	extAddr,
	extData,
	extOE,
	extWR,
	extHold,
	extNotReady
	);

input clk;			//clock
input reset;		//reset

/* Normal Memory */
input opRd;			//read value
input opWr;			//write value
input[2:0] opMode;
input[47:0] memAddr;
input[63:0] wrValue;

output[63:0] rdValue;

/* Instruction Memory */
input iopRd;			//read value
input[47:0] imemAddr;
output[31:0] irdValue;

/* External Memory */
output[47:0] extAddr;			//external memory address
inout[31:0] extData;			//external memory data (read/write)
output extOE;					//external output enable
output extWR;					//external write
output extHold;					//busy with external memory access
input extNotReady;				//external access is not ready



reg[31:0] dTile[4095:0];		//data for data tiles
reg[31:0] dTileBase[255:0];		//base address of memory tile
reg[15:0] dTileBaseHi[255:0];	//base address of memory tile

reg[31:0] iTile[4095:0];		//data for instruction tiles
reg[31:0] iTileBase[255:0];		//base address of memory tile
reg[15:0] iTileBaseHi[255:0];	//base address of memory tile

reg[11:0] dTileIdx;
reg[11:0] iTileIdx;
reg[11:0] dTileLimIdx;
reg[11:0] iTileLimIdx;
reg dTileMiss;
reg iTileMiss;
reg dTileMiss2;
reg iTileMiss2;

reg[47:0] dMemAddr;
reg[47:0] dMemAddrLim;
reg[47:0] iMemAddr;
reg[47:0] iMemAddrLim;

reg[63:0] rdtTBlock;
reg[63:0] rdtValue;
reg[63:0] rdtValue2;
reg[63:0] rdtTBlock2;

reg[63:0] rdtMask;
reg[63:0] rdtMask2;
reg[4:0] rdtShl;

reg[63:0] irdtTBlock;
reg[63:0] irdtValue;
reg[4:0] irdtShl;

parameter[2:0]  MD_NONE  = 3'b000;
parameter[2:0]  MD_BYTE  = 3'b001;
parameter[2:0]  MD_WORD  = 3'b010;
parameter[2:0]  MD_DWORD = 3'b011;
parameter[2:0]  MD_QWORD = 3'b100;
parameter[2:0]  MD_OWORD = 3'b101;
parameter[2:0]  MD_UBYTE = 3'b110;
parameter[2:0]  MD_UWORD = 3'b111;

reg[31:0] reqLdTileBaseLo;	//base address for requested tile load
reg[15:0] reqLdTileBaseHi;	//base address for requested tile load
reg[7:0] reqLdTileIdx;		//requested tile to be read into
reg reqLdTile;				//loading a tile requested
reg reqLdITile;				//request is for an instruction tile

assign extHold = reqLdTile || ldTileAct || resetAct;

always @ (opRd or opWr or iopRd)
begin
	dTileMiss  = 0;
	iTileMiss  = 0;
	dTileMiss2 = 0;
	iTileMiss2 = 0;

	reqLdTile = 0;
	
	if(opRd || opWr)
	begin
		dMemAddr    = memAddr;
		dMemAddrLim = dMemAddr+7;
		dTileIdx    = dMemAddr[13:2];
		dTileLimIdx = dMemAddrLim[13:2];

		dTileMiss  = (dTileBase[dTileIdx[11:4]]!=dMemAddr[37:6]);
		dTileMiss2 = (dTileBase[dTileLimIdx[11:4]]!=dMemAddrLim[37:6]);

		rdtShl[4:3] = memAddr[1:0];
		rdtShl[2:0] = 3'b000;

		if(dTileMiss)
		begin
//			$display("dTileMiss");
			reqLdTile            = 1;
			reqLdTileBaseLo      = dMemAddr[37: 6];
			reqLdTileBaseHi[9:0] = dMemAddr[47:38];
			reqLdTileIdx         = dTileIdx[11: 4];
			reqLdITile           = 0;
		end
		else
		if(dTileMiss2)
		begin
//			$display("dTileMiss2");
			reqLdTile            = 1;
			reqLdTileBaseLo      = dMemAddrLim[37: 6];
			reqLdTileBaseHi[9:0] = dMemAddrLim[47:38];
			reqLdTileIdx         = dTileLimIdx[11: 4];
			reqLdITile           = 0;
		end
	end

	if(iopRd)
	begin
		iMemAddr    = imemAddr;
		iMemAddrLim = iMemAddr+3;
		iTileIdx    = iMemAddr[13:2];
		iTileLimIdx = iMemAddrLim[13:2];

		iTileMiss  = (iTileBase[iTileIdx[11:4]]!=iMemAddr[37:6]);
		iTileMiss2 = (iTileBase[iTileLimIdx[11:4]]!=iMemAddrLim[37:6]);

		irdtShl[4:3] = imemAddr[1:0];
		irdtShl[2:0] = 3'b000;

		if(iTileMiss)
		begin
//			$display("iTileMiss");
			reqLdTile            = 1;
			reqLdTileBaseLo      = imemAddr[37: 6];
			reqLdTileBaseHi[9:0] = imemAddr[47:38];
			reqLdTileIdx         = iTileIdx[11: 4];
			reqLdITile           = 1;
		end
		else
		if(iTileMiss2)
		begin
//			$display("iTileMiss2");
			reqLdTile            = 1;
			reqLdTileBaseLo      = iMemAddrLim[37: 6];
			reqLdTileBaseHi[9:0] = iMemAddrLim[47:38];
			reqLdTileIdx         = iTileLimIdx[11: 4];
			reqLdITile           = 1;
		end
	end
end

reg[ 3:0] ldTileWIdx;
reg[ 3:0] ldTileNextWIdx;
reg[47:0] ldTileExtAddr;	//external memory address

reg[11:0] ldTileIdx;

reg ldTileAct;
reg ldTileNextAct;

reg ldTileDn;
reg ldTileNextDn;

reg ldTileExtOE;
reg ldTileNextExtOE;

reg ldTileExtWR;
reg ldTileNextExtWR;

assign extOE   = ldTileExtOE;
assign extWR   = ldTileExtWR;
assign extAddr = ldTileExtAddr;

always @ (reqLdTile)
begin
	if(reqLdTile || ldTileAct)
	begin	
		if(ldTileAct==0)
		begin
//			ldTileWIdx    =0;
			ldTileNextWIdx=0;

//			ldTileDn      = 0;
			ldTileNextDn  = 0;
			ldTileNextAct = 1;

			ldTileExtAddr[47:38] = reqLdTileBaseHi[9:0];
			ldTileExtAddr[37: 6] = reqLdTileBaseLo[31:0];
			ldTileExtAddr[ 5: 0] = 0;
			ldTileNextExtOE = 1;
			ldTileNextExtWR = 0;
		end
		else
		begin
			ldTileNextDn  = 0;
			ldTileNextAct = 1;

			if(extNotReady)
			begin
				ldTileNextWIdx=ldTileWIdx;
			end
			else
			begin
				ldTileNextWIdx=ldTileWIdx+1;
				if(ldTileNextWIdx==0)
				begin
//					$display("ldTileNextWIdx: Done");
					ldTileNextAct = 0;
					ldTileNextDn = 1;
					ldTileNextExtOE = 0;
					ldTileNextExtWR = 0;
				end
			end
			
			ldTileExtAddr[5:2]=ldTileWIdx;

			ldTileIdx[11:4]=reqLdTileIdx[7:0];
			ldTileIdx[ 3:0]=ldTileWIdx;
		end
	end
end

reg dTileOpWrOK;
reg resetAct;
reg resetNextAct;
reg[ 7:0] resetCurTile;
reg[ 7:0] resetNextTile;
reg[15:0] resetTOK;

always @ (clk)
begin
	if(resetAct)
	begin
		resetNextTile = resetCurTile+1;
		if(resetNextTile==0)
			resetNextAct=0;
	end
	else
	if(reset || (resetTOK!=16'h1234))
	begin
		resetNextAct=1;
		resetNextTile=0;
	end
end

always @ (posedge clk)
begin
	resetAct <= resetNextAct;
	resetCurTile <= resetNextTile;

	if(resetAct)
	begin
		iTileBase[resetCurTile] <= 32'hFFFF_FFFF;
		dTileBase[resetCurTile] <= 32'hFFFF_FFFF;
		resetTOK <= 16'h1234;
	end
	else
	begin
		ldTileWIdx  <= ldTileNextWIdx;
		ldTileAct   <= ldTileNextAct;
		ldTileDn    <= ldTileNextDn;
		ldTileExtOE <= ldTileNextExtOE;
		ldTileExtWR <= ldTileNextExtWR;

		if(dTileOpWrOK && !ldTileAct)
		begin
			dTile[dTileIdx  ] <= rdtTBlock[31: 0];
			dTile[dTileIdx+1] <= rdtTBlock[63:32];
			dTileBaseHi[dTileIdx[11:4]][10] <= 1;
		end

		if(ldTileAct)
		begin
			if(reqLdITile)
				iTile[ldTileIdx] <= extData;
			else
				dTile[ldTileIdx] <= extData;
		end

		if(ldTileDn)
		begin
	//		ldTileDn  <= 0;
			ldTileAct <= 0;
			
			if(reqLdITile)
			begin
				iTileBase[reqLdTileIdx[7:0]] <= reqLdTileBaseLo;
				iTileBaseHi[reqLdTileIdx[7:0]] <= reqLdTileBaseHi;
			end
			else
			begin
				dTileBase[reqLdTileIdx[7:0]] <= reqLdTileBaseLo;
				dTileBaseHi[reqLdTileIdx[7:0]] <= reqLdTileBaseHi;
			end
		end
	end
end

always @ (opRd)
begin
	if(opRd)
	begin
//		rdtValue=tile[tileIdx]>>rdtShl;

		rdtTBlock[31: 0]=dTile[dTileIdx  ];
		rdtTBlock[63:32]=dTile[dTileIdx+1];
		rdtValue=rdtTBlock>>rdtShl;

		case(opMode)
			MD_BYTE:
			begin
				rdValue[ 7:0]=rdtValue[7:0];
				rdValue[63:8]=rdtValue[7]?
					56'hFFFF_FFFF_FFFF_FF :
					56'h0000_0000_0000_00 ;
			end

			MD_WORD:
			begin
				rdValue[15: 0]=rdtValue[15:0];
				rdValue[63:16]=rdtValue[15]?
					48'hFFFF_FFFF_FFFF :
					48'h0000_0000_0000 ;
			end

			MD_DWORD:
			begin
				rdValue[31: 0]=rdtValue[31:0];
				rdValue[63:32]=rdtValue[31]?
					32'hFFFF_FFFF :
					32'h0000_0000 ;
			end

			MD_QWORD:
			begin
				rdValue=rdtValue;
			end

			MD_UBYTE:
			begin
				rdValue[ 7:0]=rdtValue[7:0];
				rdValue[63:8]=56'h0000_0000_0000_00 ;
			end

			MD_UWORD:
			begin
				rdValue[15: 0]=rdtValue[15:0];
				rdValue[63:16]=48'h0000_0000_0000 ;
			end

			default:
			begin
				rdValue=rdtValue;
			end

		endcase
	end
end

always @ (opWr)
begin
	dTileOpWrOK = 0;

	if(opWr)
	begin
		case(opMode)
			MD_BYTE:
			begin
				rdtValue2[ 7:0] = wrValue[7:0];
				rdtValue2[63:8] = 56'h0000_0000_0000_00 ;
				rdtMask2 = 64'h0000_0000_0000_00FF ;
			end

			MD_WORD:
			begin
				rdtValue2[15: 0] = wrValue[15:0];
				rdtValue2[63:16] = 48'h0000_0000_0000 ;
				rdtMask2 = 64'h0000_0000_0000_FFFF ;
			end

			MD_DWORD:
			begin
				rdtValue2[31: 0] = wrValue[31:0];
				rdtValue2[63:32] = 32'h0000_0000 ;
				rdtMask2 = 64'h0000_0000_FFFF_FFFF ;
			end

			MD_QWORD:
			begin
				rdtValue2[63:0] = wrValue[63:0];
				rdtMask2 = 64'hFFFF_FFFF_FFFF_FFFF ;
			end

			default:
			begin
				rdtValue2 = 64'h0000_0000_0000_0000 ;
				rdtMask2  = 64'h0000_0000_0000_0000 ;
			end
		endcase

		rdtValue = rdtValue2<<rdtShl;
		rdtMask  = rdtMask2<<rdtShl;

		if(!reqLdTile && !ldTileAct)
		begin
			rdtTBlock[31: 0]=dTile[dTileIdx  ];
			rdtTBlock[63:32]=dTile[dTileIdx+1];
			rdtTBlock2=(rdtTBlock&(~rdtMask))|rdtValue;
//			dTile[dTileIdx  ]=rdtTBlock[31: 0];
//			dTile[dTileIdx+1]=rdtTBlock[63:32];
			dTileOpWrOK = 1;
		end
	end
end


always @ (iopRd)
begin
	if(iopRd)
	begin
		irdtTBlock[31: 0] = iTile[iTileIdx  ];
		irdtTBlock[63:32] = iTile[iTileIdx+1];
		irdtValue      = irdtTBlock>>irdtShl;
		irdValue[31:0] = irdtValue[31:0];
	end
end

endmodule
