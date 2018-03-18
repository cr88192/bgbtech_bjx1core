/*
Instruction Cache Tiles

Fetch 48 bits from the instruction cache.

Instructions are 16 or 32 bits, but is 48 bits for pipeline reasons.

I-Cache Tiles are 4 DWORDs, or 16 bytes.

This cache operates inside the virtual address space.

*/

module IcTile2(
	/* verilator lint_off UNUSED */
	clock, reset,
	regInPc,
	regOutPcVal, regOutPcOK,
	memPcData,
	memPcAddr, memPcOE, memPcOK
	);

input			clock;
input			reset;

input[31:0]		regInPc;		//input PC address
output[47:0]	regOutPcVal;	//output PC value
output[1:0]		regOutPcOK;		//set if we have a valid value.

input[127:0]	memPcData;		//memory PC data
input[1:0]		memPcOK;		//memory PC OK
output[31:0]	memPcAddr;		//memory PC address
output			memPcOE;		//memory PC output-enable


// reg[31:0]	icBlkLo[511:0];		//Block Low DWord
// reg[31:0]	icBlkHi[511:0];		//Block High DWord

(* ram_style="block" *) reg[31:0]	icBlkA[255:0];		//Block DWord A
(* ram_style="block" *) reg[31:0]	icBlkB[255:0];		//Block DWord B
(* ram_style="block" *) reg[31:0]	icBlkC[255:0];		//Block DWord C
(* ram_style="block" *) reg[31:0]	icBlkD[255:0];		//Block DWord D
(* ram_style="block" *) reg[31:0]	icBlkE[255:0];		//Block DWord E (So Single Port)
(* ram_style="block" *) reg[27:0]	icBlkAd[255:0];		//Block Addresses

reg[31:0]	tRegInPc1;
reg[31:0]	tRegInPc2;
reg[27:0]	tBlkNeedAd1;
reg[27:0]	tBlkNeedAd2;

reg[31:0]	tRegInPc3;
reg[31:0]	tRegInPc4;

reg[63:0]	tBlkData1;
reg[63:0]	tBlkData2;

reg[47:0]	tRegOutPcVal;
reg[1:0]	tRegOutPcOK;

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

reg			doReqNeedAd;
reg			nxtDoReqNeedAd;

reg			nxtReqCommit;
reg[27:0]	nxtReqCommitAd1;
reg[27:0]	nxtReqCommitAd2;

reg[159:0]	reqTempBlk;
reg[159:0]	nxtReqTempBlk;

reg[159:0]	accTempBlk;

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
	nxtDoReqNeedAd=0;
	
	if((tBlkNeedAd1==icBlkAd[tBlkNeedAd1[7:0]]) &&
		(tBlkNeedAd2==icBlkAd[tBlkNeedAd2[7:0]]))
	begin
		accTempBlk[ 31:  0]=icBlkA[tBlkNeedAd1[7:0]];
		accTempBlk[ 63: 32]=icBlkB[tBlkNeedAd1[7:0]];
		accTempBlk[ 95: 64]=icBlkC[tBlkNeedAd1[7:0]];
		accTempBlk[127: 96]=icBlkD[tBlkNeedAd1[7:0]];
		accTempBlk[159:128]=icBlkE[tBlkNeedAd2[7:0]];
//		accTempBlk[159:128]=icBlkA[tBlkNeedAd2[7:0]];

		case(regInPc[3:1])
		3'b000: tRegOutPcVal=accTempBlk[ 47:  0];
		3'b001: tRegOutPcVal=accTempBlk[ 63: 16];
		3'b010: tRegOutPcVal=accTempBlk[ 79: 32];
		3'b011: tRegOutPcVal=accTempBlk[ 95: 48];
		3'b100: tRegOutPcVal=accTempBlk[111: 64];
		3'b101: tRegOutPcVal=accTempBlk[127: 80];
		3'b110: tRegOutPcVal=accTempBlk[143: 96];
		3'b111: tRegOutPcVal=accTempBlk[159:112];
		endcase
		tRegOutPcOK=1;
	end
	else if(isReqTileSt==3'h0)
	begin
		if(tBlkNeedAd1==icBlkAd[tBlkNeedAd1[7:0]])
		begin
			$display("IcMiss2 %X", tBlkNeedAd2);
			nReqNeedAd=tBlkNeedAd2;
			nxtDoReqNeedAd=1;
		end
		else
		begin
			$display("IcMiss1 %X", tBlkNeedAd1);
			nReqNeedAd=tBlkNeedAd1;
			nxtDoReqNeedAd=1;
		end
	end

	tMemPcAddr=0;
	tMemPcOE=0;
	nxtReqTileSt=isReqTileSt;
	nxtReqTempBlk = reqTempBlk;
	nxtReqCommit = 0;
	nxtReqCommitAd1 = 0;
	nxtReqCommitAd2 = 0;
	
	case(isReqTileSt)
		3'h0: begin
//			if(reqNeedAd!=0)
			if(doReqNeedAd)
			begin
				nxtReqNeedAd=reqNeedAd;
//				nxtReqTileSt=4;
				nxtReqTileSt=2;
			end
		end

		3'h1: begin
		end

		3'h2: begin
			$display("IcTile2: Get2 %X", memPcData);
		
			nxtReqTempBlk[127:  0]=memPcData[127:0];
			nxtReqTempBlk[159:128]=memPcData[ 31:0];
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=0;
			tMemPcOE=1;
			nxtReqTileSt=0;
//			nxtReqCommit=1;
			nxtReqCommit=(memPcOK==UMEM_OK_OK);
			nxtReqCommitAd1=isReqNeedAd;
			nxtReqCommitAd2=isReqNeedAd;
		end

		3'h3: begin
		end

		3'h4: begin
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcOE=1;
			nxtReqTileSt=5;
			nxtReqTempBlk[ 31:  0]=memPcData[31:0];
			nxtReqTempBlk[159:128]=memPcData[31:0];
		end

		3'h5: begin
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcOE=1;
			nxtReqTileSt=6;
			nxtReqTempBlk[63:32]=memPcData[31:0];
		end

		3'h6: begin
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcOE=1;
			nxtReqTileSt=7;
			nxtReqTempBlk[95:64]=memPcData[31:0];
		end

		3'h7: begin
			tMemPcAddr[31:4]=isReqNeedAd;
			tMemPcAddr[3:2]=isReqTileSt[1:0];
			tMemPcOE=1;
			nxtReqTileSt=0;
			nxtReqTempBlk[127:96]=memPcData[31:0];
			nxtReqCommit=1;
			nxtReqCommitAd1=isReqNeedAd;
			nxtReqCommitAd2=isReqNeedAd;
		end
	endcase
end

always @ (posedge clock)
begin
	reqNeedAd		<= nReqNeedAd;
	isReqNeedAd		<= nxtReqNeedAd;
	reqTempBlk		<= nxtReqTempBlk;
	doReqNeedAd 	<= nxtDoReqNeedAd;

	if(nxtReqCommit)
	begin
		$display("IcTile: Commit %X %X", nxtReqCommitAd1, nxtReqTempBlk);
		icBlkA[nxtReqCommitAd1[7:0]]	<= nxtReqTempBlk[ 31:  0];
		icBlkB[nxtReqCommitAd1[7:0]]	<= nxtReqTempBlk[ 63: 32];
		icBlkC[nxtReqCommitAd1[7:0]]	<= nxtReqTempBlk[ 95: 64];
		icBlkD[nxtReqCommitAd1[7:0]]	<= nxtReqTempBlk[127: 96];
		icBlkE[nxtReqCommitAd2[7:0]]	<= nxtReqTempBlk[159:128];
		icBlkAd[nxtReqCommitAd1[7:0]]	<= nxtReqCommitAd1;
	end

	if(memPcOK==UMEM_OK_OK)
	begin
		$display("IcTile: MemOK %X->%X",
			isReqTileSt, nxtReqTileSt);
		isReqTileSt <= nxtReqTileSt;
	end
	else if(memPcOK==UMEM_OK_READY)
	begin
//		$display("IcTile: MemReady");

		case(isReqTileSt)
			3'h0: begin
				isReqTileSt <= nxtReqTileSt;
			end
			
			default: begin end
		endcase
	end
	else if(memPcOK==UMEM_OK_HOLD)
	begin
		$display("IcTile: MemHold");
	end
	else if(memPcOK==UMEM_OK_FAULT)
	begin
		$display("IcTile: MemFault");
	end
end

endmodule