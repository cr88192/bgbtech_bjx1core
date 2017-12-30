/*
Data Cache Tiles

Fetch 64 or 48 bits from the data cache.

Support misaligned access up to 32 bits.
Require 32-bit alignment for 64-bit access.

D-Cache Tiles are 4 DWORDs, or 16 bytes.

This cache operates inside the virtual address space.

*/

module DcTile2(clock, reset,
	regInAddr,		regInData,
	regOutData,		regOutOK,
	regInOE,		regInWR,
	regInOp,
	memPcData,
	memPcAddr, memPcOE, memPcOK
	);

input[31:0]		regInAddr;		//input PC address
input[63:0]		regInData;		//input data (store)
input			regInOE;		//Load
input			regInWR;		//Store
input[1:0]		regInOp;		//Operation Size/Type

output[63:0]	regOutData;		//output data (load)
output			regOutOK;		//set if operation suceeds

input[31:0]		memPcData;		//memory PC data
input			memPcOK;		//memory PC OK
output[31:0]	memPcAddr;		//memory PC address
output			memPcOE;		//memory PC output-enable
input[31:0]		memOutData;		//memory PC data


reg[31:0]	icBlkLo[511:0];		//Block Low DWord
reg[31:0]	icBlkHi[511:0];		//Block High DWord
reg[27:0]	icBlkAd[255:0];		//Block Addresses
reg[3:0]	icBlkFl[255:0];		//Block Addresses

reg[31:0]	tRegInPc1;
reg[31:0]	tRegInPc2;
reg[27:0]	tBlkNeedAd1;
reg[27:0]	tBlkNeedAd2;

reg[31:0]	tRegInPc3;
reg[31:0]	tRegInPc4;

reg[63:0]	tBlkData1;
reg[63:0]	tBlkData2;
reg[63:0]	tBlkData3;
reg[63:0]	tBlkData4;

reg[63:0]	tRegOutData;
reg			tRegOutOK;

reg[31:0]	tMemPcAddr;		//memory PC address
reg			tMemPcOE;		//memory PC output-enable
reg[31:0]	tMemOutData;	//memory PC data

reg[27:0]	reqNeedAd;
reg[27:0]	nReqNeedAd;

assign		regOutData = tRegOutData;
assign		regOutOK = tRegOutOK;


assign		memPcAddr = tMemPcAddr;
assign		memPcOE = tMemPcOE;

reg[3:0]	isReqTileSt;
reg[27:0]	isReqNeedAd;
reg[3:0]	nxtReqTileSt;
reg[27:0]	nxtReqNeedAd;

always @ (clock)
begin
	tRegInPc1=regInAddr;
	tRegInPc2=regInAddr+4;
	tBlkNeedAd1=tRegInPc1[31:4];
	tBlkNeedAd2=tRegInPc2[31:4];
	
	tRegOutData=0;
	tRegOutOK=0;

	nReqNeedAd=0;
	
	if((regInOE || regInWR) &&
		(isReqTileSt==0))
	begin
		if((tBlkNeedAd1==icBlkAd[tBlkNeedAd1[7:0]]) &&
			(tBlkNeedAd2==icBlkAd[tBlkNeedAd2[7:0]]))
		begin
			tRegInPc3 = regInPc[2] ? tRegInPc2 : tRegInPc1;
			tRegInPc4 = regInPc[2] ? tRegInPc1 : tRegInPc2;

			tBlkData1[31: 0]=icBlkLo[tRegInPc3[11:3]];
			tBlkData1[63:32]=icBlkHi[tRegInPc4[11:3]];

			tBlkData2[31: 0]=regInPc[2]?tBlkData1[63:32]:tBlkData1[31: 0];
			tBlkData2[63:32]=regInPc[2]?tBlkData1[31: 0]:tBlkData1[63:32];

			case(regInAddr[1:0])
			begin
				2'b00: tRegOutPcVal=        tBlkData2[63: 0] ;
				2'b01: tRegOutPcVal={ 8'h0, tBlkData2[63: 8]};
				2'b10: tRegOutPcVal={16'h0, tBlkData2[63:16]};
				2'b11: tRegOutPcVal={24'h0, tBlkData2[63:24]};
			end
			tRegOutOK=1;
			
			case(regInOp)
			begin
				2'b00: begin
					case(regInAddr[1:0])
					begin
						2'b00: begin
							tBlkData3[ 7:0]=regInData[ 7:0];
							tBlkData3[63:8]=tBlkData2[63:8];
						end
						2'b01: begin
							tBlkData3[ 7: 0]=tBlkData2[ 7: 0];
							tBlkData3[15: 8]=regInData[ 7: 0];
							tBlkData3[63:16]=tBlkData2[63:16];
						end 
						2'b10: begin
							tBlkData3[15: 0]=tBlkData2[15: 0];
							tBlkData3[23:16]=regInData[ 7: 0];
							tBlkData3[63:24]=tBlkData2[63:24];
						end 
						2'b11: begin
							tBlkData3[23: 0]=tBlkData2[23: 0];
							tBlkData3[31:24]=regInData[ 7: 0];
							tBlkData3[63:32]=tBlkData2[63:32];
						end
					end
				end

				2'b01: begin
					case(regInAddr[1:0])
					begin
						2'b00: begin
							tBlkData3[15: 0]=regInData[15: 0];
							tBlkData3[63:16]=tBlkData2[63:16];
						end
						2'b01: begin
							tBlkData3[ 7: 0]=tBlkData2[ 7: 0];
							tBlkData3[23: 8]=regInData[15: 0];
							tBlkData3[63:24]=tBlkData2[63:24];
						end 
						2'b10: begin
							tBlkData3[15: 0]=tBlkData2[15: 0];
							tBlkData3[31:16]=regInData[15: 0];
							tBlkData3[63:32]=tBlkData2[63:32];
						end 
						2'b11: begin
							tBlkData3[23: 0]=tBlkData2[23: 0];
							tBlkData3[39:24]=regInData[15: 0];
							tBlkData3[63:40]=tBlkData2[63:40];
						end
					end
				end

				2'b10: begin
					case(regInAddr[1:0])
					begin
						2'b00: begin
							tBlkData3[31: 0]=regInData[31: 0];
							tBlkData3[63:32]=tBlkData2[63:32];
						end
						2'b01: begin
							tBlkData3[ 7: 0]=tBlkData2[ 7: 0];
							tBlkData3[39: 8]=regInData[31: 0];
							tBlkData3[63:40]=tBlkData2[63:40];
						end 
						2'b10: begin
							tBlkData3[15: 0]=tBlkData2[15: 0];
							tBlkData3[47:16]=regInData[31: 0];
							tBlkData3[63:48]=tBlkData2[63:48];
						end 
						2'b11: begin
							tBlkData3[23: 0]=tBlkData2[23: 0];
							tBlkData3[55:24]=regInData[31: 0];
							tBlkData3[63:56]=tBlkData2[63:56];
						end
					end
				end

				2'b11: begin
					tBlkData3[63: 0]=regInData[63: 0];
				end
			end

			tBlkData4[31: 0]=regInPc[2]?tBlkData3[63:32]:tBlkData3[31: 0];
			tBlkData4[63:32]=regInPc[2]?tBlkData3[31: 0]:tBlkData3[63:32];

		end
		else if(tBlkNeedAd1==icBlkAd[tBlkNeedAd1[7:0]])
		begin
			nReqNeedAd=tBlkNeedAd2;
		end
		else
		begin
			nReqNeedAd=tBlkNeedAd1;
		end
	end

	tMemPcAddr=0;
	tMemPcOE=0;
	nxtReqTileSt=isReqTileSt;
	
	case(isReqTileSt)
	begin

		4'h0: begin
			if(reqNeedAd)
			begin
				nxtReqNeedAd=reqNeedAd;
				nxtReqTileSt=4;
				if(icBlkFl[reqNeedAd[7:0]][0])
					nxtReqTileSt=8;
			end
		end

		4'h4: begin
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcOE=1;
			nxtReqTileSt=5;
		end

		4'h5: begin
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcOE=1;
			nxtReqTileSt=6;
		end

		4'h6: begin
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcOE=1;
			nxtReqTileSt=7;
		end

		4'h7: begin
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcOE=1;
			nxtReqTileSt=0;
		end


		4'h8: begin
			tMemPcAddr[31:4]=icBlkAd[reqNeedAd[7:0]];
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcWR=1;
			nxtReqTileSt=4'h9;
		end

		4'h9: begin
			tMemPcAddr[31:4]=icBlkAd[reqNeedAd[7:0]];
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcWR=1;
			nxtReqTileSt=4'hA;
		end

		4'hA: begin
			tMemPcAddr[31:4]=icBlkAd[reqNeedAd[7:0]];
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcWR=1;
			nxtReqTileSt=4'hB;
		end

		4'hB: begin
			tMemPcAddr[31:4]=icBlkAd[reqNeedAd[7:0]];
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcWR=1;
			nxtReqTileSt=4'h4;
		end

	end
end

always @ (posedge clock)
begin
	reqNeedAd <= nReqNeedAd;
	isReqNeedAd <= nxtReqNeedAd;

	if(regInWR && tRegOutOK)
	begin
		icBlkLo[tRegInPc3[11:3]]	<= tBlkData4[31: 0];
		icBlkHi[tRegInPc4[11:3]]	<= tBlkData4[63:32];
		icBlkFl[tRegInPc3[11:4]][0]	<= 1;
	end
	else
	if(memPcOK)
	begin
		if((isReqTileSt>=4'h4) && (isReqTileSt<=4'h7))
		begin
			if(isReqTileSt[0])
				icBlkHi[tMemPcAddr[11:3]] <= memPcData;
			else
				icBlkLo[tMemPcAddr[11:3]] <= memPcData;
			isReqTileSt <= nxtReqTileSt;
			if(isReqTileSt==3'h7)
				icBlkAd[tMemPcAddr[11:4]] <= tMemPcAddr[31:4];
		end

		if((isReqTileSt>=4'h8) && (isReqTileSt<=4'hB))
		begin
			if(isReqTileSt[0])
				tMemOutData <= icBlkHi[tMemPcAddr[11:3]];
			else
				tMemOutData <= icBlkLo[tMemPcAddr[11:3]];
			isReqTileSt <= nxtReqTileSt;
		end
	end
	else
	begin
		case(isReqTileSt)
		begin
			4'h0: begin
				isReqTileSt <= nxtReqTileSt;
			end
			
			default: begin end
		end
	end
end

endmodule