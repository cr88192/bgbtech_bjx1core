/*
Instruction Cache Tiles

Fetch 48 bits from the instruction cache.

Instructions are 16 or 32 bits, but is 48 bits for pipeline reasons.

I-Cache Tiles are 4 DWORDs, or 16 bytes.

This cache operates inside the virtual address space.

*/

module IcTile2(clock, reset,
	regInPc,
	regOutPcVal, regOutPcOK,
	memPcData,
	memPcAddr, memPcOE, memPcOK
	);

input[31:0]		regInPc;		//input PC address
output[47:0]	regOutPcVal;	//output PC value
output			regOutPcOK;		//set if we have a valid value.

input[31:0]		memPcData;		//memory PC data
input			memPcOK;		//memory PC OK
output[31:0]	memPcAddr;		//memory PC address
output			memPcOE;		//memory PC output-enable


reg[31:0]	icBlkLo[511:0];		//Block Low DWord
reg[31:0]	icBlkHi[511:0];		//Block High DWord
reg[27:0]	icBlkAd[255:0];		//Block Addresses

reg[31:0]	tRegInPc1;
reg[31:0]	tRegInPc2;
reg[27:0]	tBlkNeedAd1;
reg[27:0]	tBlkNeedAd2;

reg[31:0]	tRegInPc3;
reg[31:0]	tRegInPc4;

reg[63:0]	tBlkData1;
reg[27:0]	tBlkData2;

reg[47:0]	tRegOutPcVal;
reg			tRegOutPcOK;

reg[31:0]	tMemPcAddr;		//memory PC address
reg			tMemPcOE;		//memory PC output-enable

reg[27:0]	reqNeedAd;
reg[27:0]	nReqNeedAd;

assign		regOutPcVal = tRegOutPcVal;
assign		regOutPcOK = tRegOutPcOK;

assign		memPcAddr = tMemPcAddr;
assign		memPcOE = tMemPcOE;

reg[2:0]	isReqTileSt;
reg[27:0]	isReqNeedAd;
reg[2:0]	nxtReqTileSt;
reg[27:0]	nxtReqNeedAd;

always @ (clock)
begin
	tRegInPc1=regInPc;
	tRegInPc2=regInPc+4;
	tBlkNeedAd1=tRegInPc1[31:4];
	tBlkNeedAd2=tRegInPc2[31:4];

	tRegOutPcVal=48'h0F3B_0F3B_0F3B;
	
//	tRegOutPcVal=0;
	tRegOutPcOK=0;

	nReqNeedAd=0;
	
	if((tBlkNeedAd1==icBlkAd[tBlkNeedAd1[7:0]]) &&
		(tBlkNeedAd2==icBlkAd[tBlkNeedAd2[7:0]]))
	begin
		tRegInPc3 = regInPc[2]?tRegInPc2:tRegInPc1;
		tRegInPc4 = regInPc[2]?tRegInPc1:tRegInPc2;

		tBlkData1[31: 0]=icBlkLo[tRegInPc3[11:3]];
		tBlkData1[63:32]=icBlkHi[tRegInPc4[11:3]];

		tBlkData2[31: 0]=regInPc[2]?tBlkData1[63:32]:tBlkData1[31: 0];
		tBlkData2[63:32]=regInPc[2]?tBlkData1[31: 0]:tBlkData1[63:32];

		if(regInPc[1])
			tRegOutPcVal=tBlkData2[63:16];
		else
			tRegOutPcVal=tBlkData2[47: 0];
		tRegOutPcOK=1;
	end
	else if(tBlkNeedAd1==icBlkAd[tBlkNeedAd1[7:0]])
	begin
		nReqNeedAd=tBlkNeedAd2;
	end
	else
	begin
		nReqNeedAd=tBlkNeedAd1;
	end

	tMemPcAddr=0;
	tMemPcOE=0;
	nxtReqTileSt=isReqTileSt;
	
	case(isReqTileSt)
	begin

		3'h0: begin
			if(reqNeedAd)
			begin
				nxtReqNeedAd=reqNeedAd;
				nxtReqTileSt=4;
			end
		end

		3'h4: begin
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcOE=1;
			nxtReqTileSt=5;
		end

		3'h5: begin
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcOE=1;
			nxtReqTileSt=6;
		end

		3'h6: begin
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcOE=1;
			nxtReqTileSt=7;
		end

		3'h7: begin
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcOE=1;
			nxtReqTileSt=0;
		end

	end
end

always @ (posedge clock)
begin
	reqNeedAd <= nReqNeedAd;
	isReqNeedAd <= nxtReqNeedAd;

	if(memPcOK)
	begin
		case(isReqTileSt)
		begin
			3'h4: begin
				icBlkLo[tMemPcAddr[11:3]] <= memPcData;
				isReqTileSt <= nxtReqTileSt;
			end

			3'h5: begin
				icBlkLo[tMemPcAddr[11:3]] <= memPcData;
				isReqTileSt <= nxtReqTileSt;
			end

			3'h6: begin
				icBlkLo[tMemPcAddr[11:3]] <= memPcData;
				isReqTileSt <= nxtReqTileSt;
			end

			3'h7: begin
				icBlkLo[tMemPcAddr[11:3]] <= memPcData;
				icBlkAd[tMemPcAddr[11:4]] <= tMemPcAddr[31:4];
				isReqTileSt <= nxtReqTileSt;
			end
		end
	end
	else
	begin
		case(isReqTileSt)
		begin
			3'h0: begin
				isReqTileSt <= nxtReqTileSt;
			end
		end
	end
end

endmodule