/*
Memory Tile Interface

Keeps a Code and Data buffer.
May attempt to perform external IO if address isn't in cache.

Address Bits
  47: 0, Memory Address
  59:48, Reserved
     60, Disable Caching
*/

module MemTile2(
	/* verilator lint_off UNUSED */
	clock,
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

input clock;		//clock
input reset;		//reset

/* Normal Memory */
input opRd;			//read value
input opWr;			//write value
input[2:0] opMode;
input[31:0] memAddr;
input[63:0] wrValue;

output[63:0] rdValue;

/* Instruction Memory */
input iopRd;			//read value
input[31:0] imemAddr;
output[63:0] irdValue;

/* External Memory */
output[31:0] extAddr;			//external memory address
inout[31:0] extData;			//external memory data (read/write)
output extOE;					//external output enable
output extWR;					//external write
output extHold;					//busy with external memory access
input extNotReady;				//external access is not ready



reg[31:0] dTile[2047:0];		//data for data tiles
reg[25:0] dTileBase[127:0];		//base address of memory tile
//reg[ 9:0] dTileBaseHi[127:0];	//base address of memory tile
reg       dTileBaseDty[127:0];	//base address of memory tile

reg[31:0] iTile[2047:0];		//data for instruction tiles
reg[25:0] iTileBase[127:0];		//base address of memory tile
//reg[ 9:0] iTileBaseHi[127:0];	//base address of memory tile

reg[10:0] dTileIdx;
reg[10:0] iTileIdx;
reg[10:0] dTileLimIdx;
reg[10:0] iTileLimIdx;
reg dTileMiss;
reg iTileMiss;
reg dTileMiss2;
reg iTileMiss2;

reg[31:0] dMemAddr;
reg[31:0] dMemAddrLim;
reg[31:0] iMemAddr;
reg[31:0] iMemAddrLim;

reg[95:0] rdtTBlock;
reg[95:0] rdtTBlock2;
reg[95:0] rdtValue;
reg[95:0] rdtValue2;

reg[95:0] rdtMask;
reg[95:0] rdtMask2;
reg[4:0] rdtShl;

reg[95:0] irdtTBlock;
reg[95:0] irdtValue;
reg[4:0] irdtShl;

reg[63:0] tDrdValue;
reg[63:0] tIrdValue;

parameter[2:0]  MD_NONE  = 3'b000;
parameter[2:0]  MD_BYTE  = 3'b001;
parameter[2:0]  MD_WORD  = 3'b010;
parameter[2:0]  MD_DWORD = 3'b011;
parameter[2:0]  MD_QWORD = 3'b100;
parameter[2:0]  MD_OWORD = 3'b101;
parameter[2:0]  MD_UBYTE = 3'b110;
parameter[2:0]  MD_UWORD = 3'b111;

reg[25:0] reqLdTileBaseLo;	//base address for requested tile load
reg[9:0] reqLdTileBaseHi;	//base address for requested tile load
reg[6:0] reqLdTileIdx;		//requested tile to be read into
reg reqLdTile;				//loading a tile requested
reg reqLdITile;				//request is for an instruction tile
reg reqLdSTile;				//request save old tile
reg reqStTile;				//store a tile requested

reg reqSyncTile;
reg reqNextSyncTile;
reg[6:0] reqSyncTileIdx;		//requested tile to be read into
reg[6:0] reqNextSyncTileIdx;	//requested tile to be read into

//assign extHold = reqLdTile || ldTileAct || resetAct;
assign extHold = reqLdTile || ldTileAct || ldTileDlyAct || resetAct;

assign rdValue = tDrdValue;
assign irdValue = tIrdValue;

reg[ 3:0] ldTileWIdx;
reg[ 3:0] ldTileNextWIdx;
reg[31:0] ldTileExtAddr;	//external memory address

reg[10:0] ldTileIdx;

reg ldTileAct;
reg ldTileNextAct;

reg ldTileStAct;
reg ldTileNextStAct;

reg ldTileDlyAct;
reg ldTileNextDlyAct;

reg ldTileLastAct;
reg ldTileNextLastAct;

reg ldTileDn;
reg ldTileNextDn;

reg ldTileExtOE;
reg ldTileNextExtOE;

reg ldTileExtWR;
reg ldTileNextExtWR;

assign extOE   = ldTileExtOE;
assign extWR   = ldTileExtWR;
assign extAddr = ldTileExtAddr;

reg dTileOpWrOK;
reg resetAct;
reg resetNextAct;
reg[ 6:0] resetCurTile;
reg[ 6:0] resetNextTile;
reg[15:0] resetTOK;



always @ (opRd or opWr or iopRd)
// always @ (clock)
begin
	dTileMiss  = 0;
	iTileMiss  = 0;
	dTileMiss2 = 0;
	iTileMiss2 = 0;

	reqLdTile = 0;
	reqStTile = 0;
	reqNextSyncTile = 0;
	reqNextSyncTileIdx = 0;
	
	if(opRd || opWr)
	begin
		dMemAddr    = memAddr[31:0];
		dMemAddrLim = dMemAddr+15;
		dTileIdx    = dMemAddr[12:2];
		dTileLimIdx = dMemAddrLim[12:2];

		dTileMiss  = (dTileBase[dTileIdx[10:4]]!=dMemAddr[31:6]);
		dTileMiss2 = (dTileBase[dTileLimIdx[10:4]]!=dMemAddrLim[31:6]);
//		dTileMiss2 = 0;

//		if(opRd && memAddr[60] && !ldTileDlyAct && !ldTileLastAct)
		if(opRd && memAddr[29] && !ldTileDlyAct && !ldTileLastAct)
		begin
			dTileMiss  = 1;
//			dTileMiss2 = (dTileBase[dTileLimIdx[10:4]]!=dMemAddrLim[31:6]);
		end

		rdtShl[4:3] = memAddr[1:0];
		rdtShl[2:0] = 3'b000;

		rdtTBlock[31: 0]=dTile[dTileIdx  ];
		rdtTBlock[63:32]=dTile[dTileIdx+1];
		rdtTBlock[95:64]=dTile[dTileIdx+2];

		if(dTileMiss)
		begin
//			$display("dTileMiss");
			reqLdTile              = 1;
			reqLdTileBaseLo        = dMemAddr[31: 6];
			reqLdTileIdx           = dTileIdx[10: 4];
			reqLdITile             = 0;
			reqLdSTile             = dTileBaseDty[dTileIdx[10:4]];
		end
		else
		if(dTileMiss2)
		begin
//			$display("dTileMiss2");
			reqLdTile              = 1;
			reqLdTileBaseLo        = dMemAddrLim[31: 6];
			reqLdTileIdx           = dTileLimIdx[10: 4];
			reqLdITile             = 0;
			reqLdSTile             = dTileBaseDty[dTileLimIdx[10:4]];
		end
		
		if(!dTileMiss && !dTileMiss2)
		begin
			if(reqSyncTile)
			begin
				reqStTile              = 1;
				reqLdTileBaseLo        = dTileBase[reqSyncTileIdx];
				reqLdTileIdx           = reqSyncTileIdx;
				reqLdITile             = 0;
			end
			
//			if(opWr && (memAddr[60]!=memAddr[63]))
			if(opWr && (memAddr[29]!=0))
			begin
				reqNextSyncTile = 1;
				reqNextSyncTileIdx = dTileIdx[10: 4];
			end
		end
		
	end
	
	if(iopRd)
	begin
		iMemAddr    = imemAddr[31:0];
		iMemAddrLim = iMemAddr+7;
		iTileIdx    = iMemAddr[12:2];
		iTileLimIdx = iMemAddrLim[12:2];

		iTileMiss  = (iTileBase[iTileIdx[10:4]]!=iMemAddr[31:6]);
		iTileMiss2 = (iTileBase[iTileLimIdx[10:4]]!=iMemAddrLim[31:6]);

		irdtShl[4:3] = imemAddr[1:0];
		irdtShl[2:0] = 3'b000;

		if(iTileMiss)
		begin
//			$display("iTileMiss");
			reqLdTile              = 1;
			reqLdTileBaseLo        = imemAddr[31: 6];
			reqLdTileIdx           = iTileIdx[10: 4];
			reqLdITile             = 1;
			reqLdSTile             = 0;
		end
		else
		if(iTileMiss2)
		begin
//			$display("iTileMiss2");
			reqLdTile              = 1;
			reqLdTileBaseLo        = iMemAddrLim[31: 6];
			reqLdTileIdx           = iTileLimIdx[10: 4];
			reqLdITile             = 1;
			reqLdSTile             = 0;
		end
		else
		begin
			irdtTBlock[31: 0] = iTile[iTileIdx  ];
			irdtTBlock[63:32] = iTile[iTileIdx+1];
			irdtTBlock[95:64] = iTile[iTileIdx+2];
			irdtValue         = irdtTBlock>>irdtShl;
			tIrdValue[63:0]   = irdtValue[63:0];

			$display("iTileRd A=%X Ix=%X,Sh=%X Val=%X", imemAddr,
				iTileIdx, irdtShl, tIrdValue);
		end
	end

	ldTileNextDlyAct = ldTileAct;
	ldTileNextLastAct = ldTileDlyAct;

	if(reqLdTile || reqStTile || ldTileAct)
	begin	
		if(ldTileAct==0)
		begin
//			ldTileWIdx    =0;
			ldTileNextWIdx=0;

//			ldTileDn      = 0;
			ldTileNextDn  = 0;
			ldTileNextAct = 1;

			ldTileIdx[10:4]=reqLdTileIdx[6:0];
			ldTileIdx[ 3:0]=ldTileWIdx;
			
			if(reqLdSTile || reqStTile)
			begin
//				$display("ldTileNextWIdx: Store");
				ldTileNextStAct = 1;
				ldTileNextExtOE = 0;
				ldTileNextExtWR = 1;
				ldTileExtAddr[31: 6] = dTileBase[ldTileIdx[10:4]][25:0];
				ldTileExtAddr[ 5: 0] = 0;
			end
			else
			begin
//				$display("ldTileNextWIdx: Load");
				ldTileNextStAct = 0;
				ldTileNextExtOE = 1;
				ldTileNextExtWR = 0;
				ldTileExtAddr[31: 6] = reqLdTileBaseLo[25:0];
				ldTileExtAddr[ 5: 0] = 0;
			end
		end
		else
		begin
			ldTileNextDn    = 0;
			ldTileNextAct   = 1;
			ldTileNextStAct = ldTileStAct;

			ldTileExtAddr[5:2]=ldTileWIdx;
			ldTileIdx[10:4]=reqLdTileIdx[6:0];
			ldTileIdx[ 3:0]=ldTileWIdx;

			if(ldTileStAct)
				extData = dTile[ldTileIdx];

			if(ldTileDn)
			begin
				ldTileNextDn    = 0;
				ldTileNextAct   = 0;
			end

			if(extNotReady)
			begin
				ldTileNextWIdx=ldTileWIdx;
			end
			else
			begin
				ldTileNextWIdx=ldTileWIdx+1;
				if(ldTileNextWIdx==0)
				begin
					if(ldTileStAct)
					begin
						if(reqLdTile)
						begin
	//						$display("ldTileNextWIdx: Store->Load");
							ldTileNextAct   = 1;
							ldTileNextStAct = 0;
							ldTileNextDn    = 0;
							ldTileNextExtOE = 1;
							ldTileNextExtWR = 0;

//							ldTileExtAddr[47:38] = reqLdTileBaseHi[9:0];
							ldTileExtAddr[31: 6] = reqLdTileBaseLo[25:0];
						end
						else
						begin
	//						$display("ldTileNextWIdx: Done");
							ldTileNextAct   = 1;
							ldTileNextStAct = 0;
							ldTileNextDn    = 1;
							ldTileNextExtOE = 0;
							ldTileNextExtWR = 0;
						end
					end
					else
					begin
//						$display("ldTileNextWIdx: Done");
						ldTileNextAct   = 1;
						ldTileNextDn    = 1;
						ldTileNextExtOE = 0;
						ldTileNextExtWR = 0;
					end
				end
			end
		end
	end

// end

// always @ (clk)
// begin

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

	if(opRd)
	begin
		rdtValue=rdtTBlock>>rdtShl;

		case(opMode)
			MD_BYTE:
			begin
				tDrdValue[ 7:0]=rdtValue[7:0];
				tDrdValue[63:8]=rdtValue[7]?
					56'hFFFF_FFFF_FFFF_FF :
					56'h0000_0000_0000_00 ;
			end

			MD_WORD:
			begin
				tDrdValue[15: 0]=rdtValue[15:0];
				tDrdValue[63:16]=rdtValue[15]?
					48'hFFFF_FFFF_FFFF :
					48'h0000_0000_0000 ;
			end

			MD_DWORD:
			begin
				tDrdValue[31: 0]=rdtValue[31:0];
				tDrdValue[63:32]=rdtValue[31]?
					32'hFFFF_FFFF :
					32'h0000_0000 ;
			end

			MD_QWORD:
			begin
				tDrdValue=rdtValue[63:0];
			end

			MD_UBYTE:
			begin
				tDrdValue[ 7:0]=rdtValue[7:0];
				tDrdValue[63:8]=56'h0000_0000_0000_00 ;
			end

			MD_UWORD:
			begin
				tDrdValue[15: 0]=rdtValue[15:0];
				tDrdValue[63:16]=48'h0000_0000_0000 ;
			end

			default:
			begin
				tDrdValue=rdtValue[63:0];
			end
		endcase
	end

	dTileOpWrOK = 0;
	if(opWr && !reqLdTile && !ldTileAct)
	begin
		rdtTBlock2 = rdtTBlock;
		case(opMode)
			MD_BYTE:
				case(memAddr[1:0])
				0:	rdtTBlock2[ 7: 0] = wrValue[7:0];
				1:	rdtTBlock2[15: 8] = wrValue[7:0];
				2:	rdtTBlock2[23:16] = wrValue[7:0];
				3:	rdtTBlock2[31:24] = wrValue[7:0];
				endcase

			MD_WORD:
				case(memAddr[1:0])
				0:	rdtTBlock2[15: 0] = wrValue[15:0];
				1:	rdtTBlock2[23: 8] = wrValue[15:0];
				2:	rdtTBlock2[31:16] = wrValue[15:0];
				3:	rdtTBlock2[39:24] = wrValue[15:0];
				endcase

			MD_DWORD:
				case(memAddr[1:0])
				0:	rdtTBlock2[31: 0] = wrValue[31:0];
				1:	rdtTBlock2[39: 8] = wrValue[31:0];
				2:	rdtTBlock2[47:16] = wrValue[31:0];
				3:	rdtTBlock2[55:24] = wrValue[31:0];
				endcase

			MD_QWORD:
				case(memAddr[1:0])
				0:	rdtTBlock2[63: 0] = wrValue[63:0];
				1:	rdtTBlock2[71: 8] = wrValue[63:0];
				2:	rdtTBlock2[79:16] = wrValue[63:0];
				3:	rdtTBlock2[87:24] = wrValue[63:0];
				endcase

			default:	begin			end
		endcase

		dTileOpWrOK = 1;
	end
end

always @ (posedge clock)
begin
	resetAct <= resetNextAct;
	resetCurTile <= resetNextTile;

	if(resetAct)
	begin
		iTileBase[resetCurTile] <= 26'h3FF_FFFF;
		dTileBase[resetCurTile] <= 26'h3FF_FFFF;
		resetTOK <= 16'h1234;
	end
	else
	begin
		ldTileWIdx    <= ldTileNextWIdx;
		ldTileAct     <= ldTileNextAct;
		ldTileStAct   <= ldTileNextStAct;
		ldTileDlyAct  <= ldTileNextDlyAct;
		ldTileDn      <= ldTileNextDn;
		ldTileExtOE   <= ldTileNextExtOE;
		ldTileExtWR   <= ldTileNextExtWR;

		reqSyncTile    <= reqNextSyncTile;
		reqSyncTileIdx <= reqNextSyncTileIdx;

		ldTileLastAct <= ldTileNextLastAct;

		if(dTileOpWrOK && (!ldTileAct || ldTileDn))
		begin
			$display("Posedge Write CA=%03X CB=%04X BH=%08X BL=%08X",
				dTileIdx, dTileIdx*4,
				rdtTBlock2[63:32], rdtTBlock2[31: 0]);
			dTile[dTileIdx  ] <= rdtTBlock2[31: 0];
			dTile[dTileIdx+1] <= rdtTBlock2[63:32];
			dTile[dTileIdx+2] <= rdtTBlock2[95:64];
			dTileBaseDty[dTileIdx[10:4]] <= 1;
			dTileBaseDty[dTileLimIdx[10:4]] <= 1;
			
		end

		if(ldTileAct && !ldTileDn && !ldTileStAct)
		begin
			if(reqLdITile)
				iTile[ldTileIdx] <= extData;
			else
				dTile[ldTileIdx] <= extData;
		end

		if(ldTileDn)
		begin			
			if(reqLdITile)
			begin
				iTileBase[reqLdTileIdx[6:0]] <= reqLdTileBaseLo;
			end
			else
			begin
				dTileBase[reqLdTileIdx[6:0]] <= reqLdTileBaseLo;
				dTileBaseDty[reqLdTileIdx[6:0]] <= 0;
			end
		end
	end
end

endmodule
