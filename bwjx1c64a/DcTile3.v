/*
Data Cache Tiles

Fetch 64 or 48 bits from the data cache.

Support misaligned access up to 32 bits.
Require 32-bit alignment for 64-bit access.

D-Cache Tiles are 4 DWORDs, or 16 bytes.

This cache operates inside the virtual address space.

(WR, OE):
  0, 0: Neither read nor write.
  0, 1: Read.
  1, 0: Write.
  1, 1: Read Modify Write.

states:
	0: Ready
	1: Cool Down
	2: Load Tile (Direct 128-bit)
	3: Store Tile (Direct 128-bit)
	4..7: Load Tile (4x DWORD)
	8..B: Store Tile (4x DWORD)

*/

`include "CoreDefs.v"

module DcTile3(
	/* verilator lint_off UNUSED */
	clock, reset,
	regInData,		regOutData,
	regInAddr,		regOutOK,
	regInOE,		regInWR,
	regInOp,
	memPcData,		memOutData,
	memPcAddr,		memPcOK,
	memPcOE,		memPcWR,
	memPcOp
	);

input			clock;
input			reset;

input[63:0]		regInAddr;		//input PC address
input[63:0]		regInData;		//input data (store)
input			regInOE;		//Load
input			regInWR;		//Store
input[4:0]		regInOp;		//Operation Size/Type

output[63:0]	regOutData;		//output data (load)
output[1:0]		regOutOK;		//set if operation suceeds

input[127:0]	memPcData;		//memory data in
output[127:0]	memOutData;		//memory data out
output[63:0]	memPcAddr;		//memory address
output			memPcOE;		//memory load
output			memPcWR;		//memory store
input[1:0]		memPcOK;		//memory OK
output[4:0]		memPcOp;		//memory PC operation


// reg[31:0]	icBlkLo[511:0];		//Block Low DWord
// reg[31:0]	icBlkHi[511:0];		//Block High DWord
(* ram_style="block" *) reg[31:0]	icBlkA[255:0];		//Block DWord A
(* ram_style="block" *) reg[31:0]	icBlkB[255:0];		//Block DWord B
(* ram_style="block" *) reg[31:0]	icBlkC[255:0];		//Block DWord C
(* ram_style="block" *) reg[31:0]	icBlkD[255:0];		//Block DWord D
(* ram_style="block" *) reg[31:0]	icBlkE[255:0];		//Block DWord E
(* ram_style="block" *) reg[27:0]	icBlkAd[255:0];		//Block Addresses
(* ram_style="block" *) reg[3:0]	icBlkFl[255:0];		//Block Addresses

reg[31:0]	tRegInPc1;
reg[31:0]	tRegInPc2;
reg[27:0]	tBlkNeedAd1;
reg[27:0]	tBlkNeedAd2;

reg[27:0]	tBlkNeedAd3;
reg[27:0]	tBlkNeedAd4;

reg[31:0]	tRegInPc3;
reg[31:0]	tRegInPc4;

reg[63:0]	tBlkData1;
reg[63:0]	tBlkData2;
reg[63:0]	tBlkData2B;
reg[63:0]	tBlkData3;
reg[63:0]	tBlkData4;

reg[63:0]	tRegOutData;
reg[1:0]	tRegOutOK;

reg			tRdZx;

reg[63:0]	tRegInData;

reg[63:0]	tMemPcAddr;		//memory address
reg			tMemPcOE;		//memory load
reg			tMemPcWR;		//memory store
reg[127:0]	tMemOutData;	//memory data
reg[4:0]	tMemPcOp;		//memory operation

assign		memPcAddr = tMemPcAddr;
assign		memOutData = tMemOutData;
assign		memPcOE = tMemPcOE;
assign		memPcWR = tMemPcWR;
assign		memPcOp = tMemPcOp;

reg[27:0]	reqNeedAd;
reg[27:0]	nReqNeedAd;

assign		regOutData = tRegOutData;
assign		regOutOK = tRegOutOK;


assign		memPcAddr = tMemPcAddr;
assign		memPcOE = tMemPcOE;

reg[63:0]	tRegOutDataB;

reg[3:0]	isReqTileSt;
reg[27:0]	isReqNeedAd;
reg[3:0]	nxtReqTileSt;
reg[27:0]	nxtReqNeedAd;

reg			nxtReqCommit;
reg[27:0]	nxtReqCommitAd1;
reg[27:0]	nxtReqCommitAd2;
reg[3:0]	nxtReqCommitFl;

reg[159:0]	reqTempBlk;
reg[159:0]	nxtReqTempBlk;
reg[159:0]	accTempBlk;
reg			accHit;
reg			accNoCache;
reg			nxtAccHit;

reg			accCommitOK;
reg			nxtAccCommitOK;

always @*
begin
	tRegInPc1=regInAddr[31:0];
	tRegInPc2=regInAddr[31:0]+4;
	tBlkNeedAd1=tRegInPc1[31:4];
	tBlkNeedAd2=tRegInPc2[31:4];
	
	tRegOutData=0;
	tRegOutOK=0;

	nReqNeedAd=0;

	tBlkNeedAd3=tBlkNeedAd1;
	tBlkNeedAd4=tBlkNeedAd2;

	nxtReqTempBlk=reqTempBlk;
	
	nxtReqCommitFl=0;
	tBlkData2=UV64_XX;
	nxtReqCommitAd1=28'hXXXXXXX;
	nxtReqCommitAd2=28'hXXXXXXX;
	nxtAccCommitOK=0;
	nxtReqNeedAd=0;

//	tMemPcAddr=32'hX;
	tMemPcAddr=0;
	tMemOutData=128'hX;
	tMemPcOE=0;
	tMemPcWR=0;
	tMemPcOp=0;

	nxtAccHit=0;
//	accHit=0;
	accNoCache=0;

	if(regInAddr[31:29]==3'b101)
		accNoCache=1;
	if(regInAddr[31:29]==3'b110)
		accNoCache=1;
	if(regInAddr[31:29]==3'b111)
		accNoCache=1;

	if((regInOE || regInWR) &&
		(isReqTileSt==0))
	begin
		if(accNoCache)
		begin
			nxtAccHit=0;
//			accTempBlk=160'hX;

			tMemPcAddr[29:2]=regInAddr[29:2];
			tMemOutData={96'h0, regInData[31:0]};
			tMemPcOE=regInOE;
			tMemPcWR=regInWR;
			tMemPcOp=1;
			tRegOutOK=memPcOK;
		end
		else
		begin
			if((tBlkNeedAd1==icBlkAd[tBlkNeedAd1[7:0]]) &&
				(tBlkNeedAd2==icBlkAd[tBlkNeedAd2[7:0]]))
			begin
				nxtAccHit=1;
			end
			else if(tBlkNeedAd1==icBlkAd[tBlkNeedAd1[7:0]])
			begin
				nReqNeedAd=tBlkNeedAd2;
				tBlkNeedAd3=tBlkNeedAd2;
			end
			else
			begin
				nReqNeedAd=tBlkNeedAd1;
				tBlkNeedAd3=tBlkNeedAd1;
			end
		end

		if(nxtAccHit)
		begin
			/* Read Stage */
			case(regInAddr[3:2])
			2'b00: tBlkData2=accTempBlk[ 63:  0];
			2'b01: tBlkData2=accTempBlk[ 95: 32];
			2'b10: tBlkData2=accTempBlk[127: 64];
			2'b11: tBlkData2=accTempBlk[159: 96];
			endcase

			tRdZx = (regInOp[4:2]==3'b011);
			case(regInOp[1:0])
				2'b00: begin
					case(regInAddr[1:0])
						2'b00: tRegOutData={
							(tBlkData2[ 7] && !tRdZx) ? 56'hF : 56'h0,
							tBlkData2[ 7: 0] };
						2'b01: tRegOutData={
							(tBlkData2[15] && !tRdZx) ? 56'hF : 56'h0,
							tBlkData2[15: 8]};
						2'b10: tRegOutData={
							(tBlkData2[23] && !tRdZx) ? 56'hF : 56'h0,
							tBlkData2[23:16]};
						2'b11: tRegOutData={
							(tBlkData2[31] && !tRdZx) ? 56'hF : 56'h0,
							tBlkData2[31:24]};
					endcase
				end

				2'b01: begin
					case(regInAddr[1:0])
						2'b00: tRegOutData={
							(tBlkData2[15] && !tRdZx) ? 48'hF : 48'h0,
							tBlkData2[ 15: 0] };
						2'b01: tRegOutData={
							(tBlkData2[23] && !tRdZx) ? 48'hF : 48'h0,
							tBlkData2[23: 8]};
						2'b10: tRegOutData={
							(tBlkData2[31] && !tRdZx) ? 48'hF : 48'h0,
							tBlkData2[31:16]};
						2'b11: tRegOutData={
							(tBlkData2[39] && !tRdZx) ? 48'hF : 48'h0,
							tBlkData2[39:24]};
					endcase
				end

				2'b10: begin
					case(regInAddr[1:0])
						2'b00: tRegOutData={
							(tBlkData2[31] && !tRdZx) ? 32'hF : 32'h0,
							tBlkData2[ 31: 0] };
						2'b01: tRegOutData={
							(tBlkData2[39] && !tRdZx) ? 32'hF : 32'h0,
							tBlkData2[39: 8]};
						2'b10: tRegOutData={
							(tBlkData2[47] && !tRdZx) ? 32'hF : 32'h0,
							tBlkData2[47:16]};
						2'b11: tRegOutData={
							(tBlkData2[55] && !tRdZx) ? 32'hF : 32'h0,
							tBlkData2[55:24]};
					endcase
				end

				2'b11: tRegOutData=        tBlkData2[63: 0] ;
			endcase


			/* Write Stage */

			tRegInData = regInData;
			case(regInOp[4:2])
				3'b000:	tRegInData = regInData;
				3'b001:	tRegInData = tRegOutDataB + regInData;
				3'b010:	tRegInData = tRegOutDataB - regInData;
				3'b011:	tRegInData = regInData;
				3'b100:	tRegInData = tRegOutDataB & regInData;
				3'b101:	tRegInData = tRegOutDataB | regInData;
				3'b110:	tRegInData = tRegOutDataB ^ regInData;
				3'b111:	tRegInData = regInData;
			endcase

			case(regInOp[1:0])
				2'b00: begin
					case(regInAddr[1:0])
						2'b00: begin
							tBlkData3[ 7:0]=tRegInData[ 7:0];
							tBlkData3[63:8]=tBlkData2B[63:8];
						end
						2'b01: begin
							tBlkData3[ 7: 0]=tBlkData2B[ 7: 0];
							tBlkData3[15: 8]=tRegInData[ 7: 0];
							tBlkData3[63:16]=tBlkData2B[63:16];
						end 
						2'b10: begin
							tBlkData3[15: 0]=tBlkData2B[15: 0];
							tBlkData3[23:16]=tRegInData[ 7: 0];
							tBlkData3[63:24]=tBlkData2B[63:24];
						end 
						2'b11: begin
							tBlkData3[23: 0]=tBlkData2B[23: 0];
							tBlkData3[31:24]=tRegInData[ 7: 0];
							tBlkData3[63:32]=tBlkData2B[63:32];
						end
					endcase
				end

				2'b01: begin
					case(regInAddr[1:0])
						2'b00: begin
							tBlkData3[15: 0]=tRegInData[15: 0];
							tBlkData3[63:16]=tBlkData2B[63:16];
						end
						2'b01: begin
							tBlkData3[ 7: 0]=tBlkData2B[ 7: 0];
							tBlkData3[23: 8]=tRegInData[15: 0];
							tBlkData3[63:24]=tBlkData2B[63:24];
						end 
						2'b10: begin
							tBlkData3[15: 0]=tBlkData2B[15: 0];
							tBlkData3[31:16]=tRegInData[15: 0];
							tBlkData3[63:32]=tBlkData2B[63:32];
						end 
						2'b11: begin
							tBlkData3[23: 0]=tBlkData2B[23: 0];
							tBlkData3[39:24]=tRegInData[15: 0];
							tBlkData3[63:40]=tBlkData2B[63:40];
						end
					endcase
				end

				2'b10: begin
					case(regInAddr[1:0])
						2'b00: begin
							tBlkData3[31: 0]=tRegInData[31: 0];
							tBlkData3[63:32]=tBlkData2B[63:32];
						end
						2'b01: begin
							tBlkData3[ 7: 0]=tBlkData2B[ 7: 0];
							tBlkData3[39: 8]=tRegInData[31: 0];
							tBlkData3[63:40]=tBlkData2B[63:40];
						end 
						2'b10: begin
							tBlkData3[15: 0]=tBlkData2B[15: 0];
							tBlkData3[47:16]=tRegInData[31: 0];
							tBlkData3[63:48]=tBlkData2B[63:48];
						end 
						2'b11: begin
							tBlkData3[23: 0]=tBlkData2B[23: 0];
							tBlkData3[55:24]=tRegInData[31: 0];
							tBlkData3[63:56]=tBlkData2B[63:56];
						end
					endcase
				end

				2'b11: begin
					tBlkData3[63: 0]=tRegInData[63: 0];
				end
			endcase

//			tBlkData4[31: 0]=regInPc[2]?tBlkData3[63:32]:tBlkData3[31: 0];
//			tBlkData4[63:32]=regInPc[2]?tBlkData3[31: 0]:tBlkData3[63:32];

			nxtReqTempBlk=accTempBlk;

			case(regInAddr[3:2])
				2'b00: nxtReqTempBlk[ 63:  0]=tBlkData3;
				2'b01: nxtReqTempBlk[ 95: 32]=tBlkData3;
				2'b10: nxtReqTempBlk[127: 64]=tBlkData3;
				2'b11: nxtReqTempBlk[159: 96]=tBlkData3;
			endcase

			nxtReqCommit=regInWR && accHit;
			nxtReqCommitAd1=tBlkNeedAd3;
			nxtReqCommitAd2=tBlkNeedAd4;
			nxtReqCommitFl=1;
			nxtAccCommitOK = regInWR && accHit;

			/* Output */
			tRegOutOK=((accHit && !regInWR) || accCommitOK) ?
				UMEM_OK_OK : UMEM_OK_HOLD;

		end
	end

	nxtReqTileSt=isReqTileSt;
	nxtReqCommit=0;
	
	case(isReqTileSt)
		4'h0: begin
			if(reqNeedAd!=0)
			begin
				nxtReqNeedAd=reqNeedAd;
				nxtReqTileSt=4;
				if(icBlkFl[reqNeedAd[7:0]][0])
				begin
					nxtReqTempBlk=accTempBlk;
					nxtReqTileSt=8;
				end
			end
		end

		4'h1: begin
			nxtReqTileSt=0;
		end

		4'h2: begin
			nxtReqTempBlk[127:  0]=memPcData[127:0];
			nxtReqTempBlk[159:128]=memPcData[ 31:0];
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=0;
			tMemPcOE=1;
			tMemPcWR=0;
			tMemPcOp=1;
			nxtReqTileSt=4'h1;
			nxtReqCommit=1;
			nxtReqCommitAd1=isReqNeedAd;
			nxtReqCommitAd2=isReqNeedAd;
			nxtReqCommitFl=0;
		end

		4'h3: begin
			tMemPcAddr[31:4]=icBlkAd[reqNeedAd[7:0]];
			tMemPcAddr[3:2]=0;
			tMemOutData[127:0] = nxtReqTempBlk[127: 0];
			tMemPcOE=0;
			tMemPcWR=1;
			tMemPcOp=1;
			nxtReqTileSt=4'h1;
		end

		4'h4: begin
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcOE=1;
			tMemPcOp=2;
			nxtReqTileSt=5;
			nxtReqTempBlk[ 31:  0]=memPcData[31:0];
			nxtReqTempBlk[159:128]=memPcData[31:0];
		end

		4'h5: begin
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcOE=1;
			tMemPcOp=2;
			nxtReqTileSt=6;
			nxtReqTempBlk[63:32]=memPcData[31:0];
		end

		4'h6: begin
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcOE=1;
			tMemPcOp=2;
			nxtReqTileSt=7;
			nxtReqTempBlk[95:64]=memPcData[31:0];
		end

		4'h7: begin
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcOE=1;
			tMemPcOp=2;
			nxtReqTileSt=1;
			nxtReqTempBlk[127:96]=memPcData[31:0];
			nxtReqCommit=1;
			nxtReqCommitAd1=isReqNeedAd;
			nxtReqCommitAd2=isReqNeedAd;
			nxtReqCommitFl=0;
		end

		4'h8: begin
			tMemPcAddr[31:4]=icBlkAd[reqNeedAd[7:0]];
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemOutData[31:0] = nxtReqTempBlk[ 31:  0];
			tMemPcWR=1;
			tMemPcOp=2;
			nxtReqTileSt=4'h9;
		end

		4'h9: begin
			tMemPcAddr[31:4]=icBlkAd[reqNeedAd[7:0]];
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemOutData[31:0] = nxtReqTempBlk[ 63: 32];
			tMemPcWR=1;
			tMemPcOp=2;
			nxtReqTileSt=4'hA;
		end

		4'hA: begin
			tMemPcAddr[31:4]=icBlkAd[reqNeedAd[7:0]];
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemOutData[31:0] = nxtReqTempBlk[ 95: 64];
			tMemPcWR=1;
			tMemPcOp=2;
			nxtReqTileSt=4'hB;
		end

		4'hB: begin
			tMemPcAddr[31:4]=icBlkAd[reqNeedAd[7:0]];
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemOutData[31:0] = nxtReqTempBlk[127: 96];
			tMemPcWR=1;
			tMemPcOp=2;
			nxtReqTileSt=4'h1;
		end
		
		default: begin end
	endcase
end

always @ (posedge clock)
begin
	reqNeedAd			<= nReqNeedAd;
	isReqNeedAd			<= nxtReqNeedAd;
	reqTempBlk			<= nxtReqTempBlk;

	accTempBlk[ 31:  0]	<= icBlkA[tBlkNeedAd3[7:0]];
	accTempBlk[ 63: 32]	<= icBlkB[tBlkNeedAd3[7:0]];
	accTempBlk[ 95: 64]	<= icBlkC[tBlkNeedAd3[7:0]];
	accTempBlk[127: 96]	<= icBlkD[tBlkNeedAd3[7:0]];
	accTempBlk[159:128]	<= icBlkE[tBlkNeedAd4[7:0]];
	accHit				<= nxtAccHit;
	accCommitOK			<= nxtAccCommitOK;
	tBlkData2B			<= tBlkData2;
	tRegOutDataB		<= tRegOutData;

	if(nxtReqCommit)
	begin
		icBlkA[nxtReqCommitAd1[7:0]]	<= nxtReqTempBlk[ 31:  0];
		icBlkB[nxtReqCommitAd1[7:0]]	<= nxtReqTempBlk[ 63: 32];
		icBlkC[nxtReqCommitAd1[7:0]]	<= nxtReqTempBlk[ 95: 64];
		icBlkD[nxtReqCommitAd1[7:0]]	<= nxtReqTempBlk[127: 96];
		icBlkE[nxtReqCommitAd2[7:0]]	<= nxtReqTempBlk[159:128];
		icBlkAd[nxtReqCommitAd1[7:0]]	<= nxtReqCommitAd1;
		icBlkFl[nxtReqCommitAd1[7:0]]	<= nxtReqCommitFl;
	end

	if(memPcOK==UMEM_OK_OK)
	begin
		isReqTileSt <= nxtReqTileSt;
	end
	else if(memPcOK==UMEM_OK_READY)
	begin
		case(isReqTileSt)
			4'h0: begin
				isReqTileSt <= nxtReqTileSt;
			end

			4'h1: begin
				isReqTileSt <= nxtReqTileSt;
			end
			
			default: begin end
		endcase
	end
end

endmodule
