/*

Blocky Audio DSP

Interface:
Will be driven by a 128 bit MMIO register, updated on a 1kHz timer.
The register will be fed with a pair of 64-bit audio blocks, giving 32 samples.

ABCDE000: DSP
      00: Sound Block 0, Word 0
      04: Sound Block 0, Word 1
      08: Sound Block 1, Word 0
      0C: Sound Block 1, Word 1
      10: Sound Block 2, Word 0 (Resv)
      14: Sound Block 2, Word 1 (Resv)
      18: Sound Block 3, Word 0 (Resv)
      1C: Sound Block 3, Word 1 (Resv)
      20: Sound Block 4, Word 0 (Resv)
      24: Sound Block 4, Word 1 (Resv)
      28: Sound Block 5, Word 0 (Resv)
      2C: Sound Block 5, Word 1 (Resv)
      30: Sound Block 6, Word 0 (Resv)
      34: Sound Block 6, Word 1 (Resv)
      38: Sound Block 7, Word 0 (Resv)
      3C: Sound Block 7, Word 1 (Resv)

*/

module BltDspMod(clock, reset, pwmOut,
	busAddr, busData, busOE, busWR, busHold, busIRQ);

/* verilator lint_off UNUSED */

input clock;
input reset;

output[1:0] pwmOut;

input[31:0] busAddr;
inout[31:0] busData;
input busOE;
input busWR;
output busHold;
inout[31:0] busIRQ;

reg tBusHold;
reg oBusIrqLive;
reg oNextBusIrqLive;

assign busHold = tBusHold;
assign busIRQ = oBusIrqLive ?
	32'bZZZZ_ZZZZ_ZZZZ_ZZZZ_ZZZZ_ZZZ0_ZZZZ_ZZZZ :
	32'bZZZZ_ZZZZ_ZZZZ_ZZZZ_ZZZZ_ZZZ1_ZZZZ_ZZZZ ;

reg tDspCSel;
assign tDspCSel = (busAddr[31:8]==24'hABCDE0);


reg[31:0] curTick10MHz;
reg[31:0] curTick1MHz;
reg[31:0] curTick32kHz;
reg[31:0] curTick1kHz;

reg[31:0] nextTick10MHz;
reg[31:0] nextTick1MHz;
reg[31:0] nextTick32kHz;
reg[31:0] nextTick1kHz;

reg[ 7:0] curCnt10MHz;
reg[ 7:0] curCnt1MHz;
reg[11:0] curCnt32kHz;
reg[17:0] curCnt1kHz;

reg[ 7:0] nextCnt10MHz;
reg[ 7:0] nextCnt1MHz;
reg[11:0] nextCnt32kHz;
reg[17:0] nextCnt1kHz;

reg[31:0] curDspBlockA0;
reg[31:0] curDspBlockB0;
reg[31:0] curDspBlockC0;
reg[31:0] curDspBlockD0;
reg[31:0] nextDspBlockA0;
reg[31:0] nextDspBlockB0;
reg[31:0] nextDspBlockC0;
reg[31:0] nextDspBlockD0;

reg[31:0] curDspBlockA1;
reg[31:0] curDspBlockB1;
reg[31:0] curDspBlockC1;
reg[31:0] curDspBlockD1;
reg[31:0] nextDspBlockA1;
reg[31:0] nextDspBlockB1;
reg[31:0] nextDspBlockC1;
reg[31:0] nextDspBlockD1;

reg[31:0] curDspBlockA2;
reg[31:0] curDspBlockB2;
reg[31:0] nextDspBlockA2;
reg[31:0] nextDspBlockB2;

reg[47:0] curSampCentIx3;
reg[47:0] nextSampCentIx3;
reg[31:0] curSampCentIx2;
reg[31:0] nextSampCentIx2;
reg[7:0] curSampSideIx2;
reg[7:0] nextSampSideIx2;

reg[1:0] curPwmOut;
reg[1:0] nextPwmOut;
assign pwmOut = curPwmOut;

reg[15:0]	curPwmStateL;
reg[15:0]	nextPwmStateL;
reg[15:0]	curPwmStateR;
reg[15:0]	nextPwmStateR;
reg[15:0]	curPwmValueL;
reg[15:0]	nextPwmValueL;
reg[15:0]	curPwmValueR;
reg[15:0]	nextPwmValueR;
reg			curPwmCarryL;
reg			nextPwmCarryL;
reg			curPwmCarryR;
reg			nextPwmCarryR;

reg[15:0]	pcmRangeCentMin;
reg[15:0]	pcmRangeCentMax;
reg[15:0]	pcmRangeSideMin;
reg[15:0]	pcmRangeSideMax;
reg[15:0]	pcmRangeCenter3;
reg[15:0]	pcmRangeCenter2;
reg[15:0]	pcmRangeSide2;
reg[19:0]	tPcmRangeCenter3;
reg[19:0]	tPcmRangeCenter2;
reg[19:0]	tPcmRangeSide2;

reg[15:0]	pcmRangeCentAvg;
reg[15:0]	pcmRangeCentOfs;
reg[15:0]	pcmRangeSideAvg;
reg[15:0]	pcmRangeSideOfs;

reg[15:0]	nextPcmRangeCentMin;
reg[15:0]	nextPcmRangeCentMax;
reg[15:0]	nextPcmRangeSideMin;
reg[15:0]	nextPcmRangeSideMax;
reg[15:0]	nextPcmRangeCenter3;
reg[15:0]	nextPcmRangeCenter2;
reg[15:0]	nextPcmRangeSide2;

reg[15:0]	curAdpcmPred;
reg[15:0]	nextAdpcmPred;
reg[5:0]	curAdpcmStep;
reg[5:0]	nextAdpcmStep;
reg[15:0]	curAdpcmStepVal;
reg[15:0]	nextAdpcmStepVal;
reg[15:0]	tAdpcmStepOfs;

reg[3:0]	pcmMode;
reg[3:0]	nextPcmMode;

always @ (clock)
begin

	tBusHold			= 0;

	nextDspBlockA0		= curDspBlockA0;
	nextDspBlockB0		= curDspBlockB0;
	nextDspBlockC0		= curDspBlockC0;
	nextDspBlockD0		= curDspBlockD0;

	nextDspBlockA1		= curDspBlockA1;
	nextDspBlockB1		= curDspBlockB1;
	nextDspBlockC1		= curDspBlockC1;
	nextDspBlockD1		= curDspBlockD1;

//	nextDspBlockA2		= (curCnt1kHz>=512)?curDspBlockA1:curDspBlockC1;
//	nextDspBlockB2		= (curCnt1kHz>=512)?curDspBlockB1:curDspBlockD1;

	nextDspBlockA2		= (curCnt1kHz>=51200)?curDspBlockA1:curDspBlockC1;
	nextDspBlockB2		= (curCnt1kHz>=51200)?curDspBlockB1:curDspBlockD1;

	if(tDspCSel!=0)
	begin
		if(busWR!=0)
		begin
//			$display("WR %X", busData);

			case(busAddr[7:2])
				0: nextDspBlockA0 = busData;
				1: nextDspBlockB0 = busData;
				2: nextDspBlockC0 = busData;
				3: nextDspBlockD0 = busData;
				default: begin end
			endcase
		end
	end

	nextTick10MHz		= curTick10MHz;
	nextTick1MHz		= curTick1MHz;
	nextTick32kHz		= curTick32kHz;
	nextTick1kHz		= curTick1kHz;

	nextCnt10MHz		= curCnt10MHz - 1;
	nextCnt1MHz			= curCnt1MHz - 1;
	nextCnt32kHz		= curCnt32kHz - 1;
	nextCnt1kHz			= curCnt1kHz - 1;
	nextPwmOut			= curPwmOut;

	nextPwmStateL		= curPwmStateL;
	nextPwmStateR		= curPwmStateR;
	nextPwmValueL		= curPwmValueL;
	nextPwmValueR		= curPwmValueR;
	nextPwmCarryL		= curPwmCarryL;
	nextPwmCarryR		= curPwmCarryR;

	nextSampCentIx3		= curSampCentIx3;
	nextSampCentIx2		= curSampCentIx2;

	nextPcmRangeCentMin	= pcmRangeCentMin;
	nextPcmRangeCentMax	= pcmRangeCentMax;
	nextPcmRangeSideMin	= pcmRangeSideMin;
	nextPcmRangeSideMax	= pcmRangeSideMax;

	nextPcmRangeCenter3	= pcmRangeCenter3;
	nextPcmRangeCenter2	= pcmRangeCenter2;
	nextPcmRangeSide2	= pcmRangeSide2;
	nextPcmMode			= pcmMode;

	nextAdpcmPred		= curAdpcmPred;
	nextAdpcmStep		= curAdpcmStep;
	nextAdpcmStepVal	= curAdpcmStepVal;

	if(curCnt10MHz==0)
	begin
		nextCnt10MHz	= 10;
		nextTick10MHz	= curTick10MHz + 1;

		{nextPwmCarryL, nextPwmStateL} =
			{1'b0, curPwmStateL} +
			{1'b0, curPwmValueL};
		{nextPwmCarryR, nextPwmStateR} =
			{1'b0, curPwmStateR} +
			{1'b0, curPwmValueR};
		nextPwmOut[0]=curPwmCarryL;
		nextPwmOut[1]=curPwmCarryR;
	end

	if(curCnt1MHz==0)
	begin
//		nextCnt1MHz		= 101;
		nextCnt1MHz		= 100;
		nextTick1MHz	= curTick1MHz + 1;
				
		case(pcmMode)
		4'h0: begin
			nextPwmValueL = pcmRangeCenter3;
			nextPwmValueR = pcmRangeCenter3;
		end
		4'h1: begin
//			nextPwmValueL = pcmRangeCenter2;
//			nextPwmValueR = pcmRangeCenter2;
//			nextPwmValueL = pcmRangeCenter2+(nextPcmRangeSide2>>>1);
//			nextPwmValueR = pcmRangeCenter2-(nextPcmRangeSide2>>>1);
			nextPwmValueL = pcmRangeCenter2+((nextPcmRangeSide2-32768)>>>1);
			nextPwmValueR = pcmRangeCenter2-((nextPcmRangeSide2-32768)>>>1);
		end

		4'h2: begin
			nextPwmValueL = curTick1kHz[0] ? 48000 : 16384;
			nextPwmValueR = curTick1kHz[1] ? 48000 : 16384;
		end

		4'h3: begin
			nextPwmValueL = curAdpcmPred;
			nextPwmValueR = curAdpcmPred;
		end
		
		default:
		begin
			nextPwmValueL = 32768;
			nextPwmValueR = 32768;
		end
		endcase

		nextAdpcmStepVal =
			{14'h0001, curAdpcmStep[1:0]}<<curAdpcmStep[5:2];
			
//		nextPcmMode=2;
	end

	oNextBusIrqLive		= 0;
	if(curCnt1kHz==0)
	begin
		nextCnt1kHz		= 100000;
		nextTick1kHz	= curTick1kHz + 1;
		nextDspBlockA1	= curDspBlockA0;
		nextDspBlockB1	= curDspBlockB0;
		nextDspBlockC1	= curDspBlockC0;
		nextDspBlockD1	= curDspBlockD0;

//		$display("DSP1 %X %X %X %X",
//			nextDspBlockA1, nextDspBlockB1,
//			nextDspBlockC1, nextDspBlockD1);

		oNextBusIrqLive	= 1;
	end

	if(curCnt32kHz==0)
	begin
		nextCnt32kHz			= 3125;
		nextTick32kHz			= curTick32kHz + 1;
		nextCnt1kHz				= curCnt1kHz - 1;

		nextSampCentIx3			= curSampCentIx3>>3;
		nextSampCentIx2			= curSampCentIx2>>2;

//		nextSampCentIx3[44:0]	= curSampCentIx3[47:3];
//		nextSampCentIx2[29:0]	= curSampCentIx2[31:2];
		if(curTick32kHz[1:0]==3)
		begin
//			nextSampSideIx2[5:0]	= curSampSideIx2[7:2];
			nextSampSideIx2			= curSampSideIx2>>2;
		end
			
		case(curSampCentIx3[2:0])
			3'h0: tPcmRangeCenter3=
				{pcmRangeCentMin, 4'h0};
			3'h1: tPcmRangeCenter3=
				{4'h0, pcmRangeCentMin}*14+
				{4'h0, pcmRangeCentMax}* 2;
			3'h2: tPcmRangeCenter3=
				{4'h0, pcmRangeCentMin}*11+
				{4'h0, pcmRangeCentMax}* 5;
			3'h3: tPcmRangeCenter3=
				{4'h0, pcmRangeCentMin}* 9+
				{4'h0, pcmRangeCentMax}* 7;
			3'h4: tPcmRangeCenter3=
				{4'h0, pcmRangeCentMin}* 7+
				{4'h0, pcmRangeCentMax}* 9;
			3'h5: tPcmRangeCenter3=
				{4'h0, pcmRangeCentMin}* 5+
				{4'h0, pcmRangeCentMax}*11;
			3'h6: tPcmRangeCenter3=
				{4'h0, pcmRangeCentMin}* 2+
				{4'h0, pcmRangeCentMax}*14;
			3'h7: tPcmRangeCenter3=
				{pcmRangeCentMax, 4'h0};
		endcase

		case(curSampCentIx2[1:0])
			2'h0: tPcmRangeCenter2=
				{pcmRangeCentMin, 4'h0};
			2'h1: tPcmRangeCenter2=
				{4'h0, pcmRangeCentMin}*11+
				{4'h0, pcmRangeCentMax}* 5;
			2'h2: tPcmRangeCenter2=
				{4'h0, pcmRangeCentMin}* 5+
				{4'h0, pcmRangeCentMax}*11;
			2'h3: tPcmRangeCenter2=
				{pcmRangeCentMax, 4'h0};
		endcase

		case(curSampSideIx2[1:0])
			2'h0: tPcmRangeSide2=
				{pcmRangeSideMin, 4'h0};
			2'h1: tPcmRangeSide2=
				{4'h0, pcmRangeSideMin}*11+
				{4'h0, pcmRangeSideMax}* 5;
			2'h2: tPcmRangeSide2=
				{4'h0, pcmRangeSideMin}* 5+
				{4'h0, pcmRangeSideMax}*11;
			2'h3: tPcmRangeSide2=
				{pcmRangeSideMax, 4'h0};
		endcase

		nextPcmRangeCenter3=tPcmRangeCenter3[19:4];
		nextPcmRangeCenter2=tPcmRangeCenter2[19:4];
		nextPcmRangeSide2=tPcmRangeSide2[19:4];

//		$display("%X: %X %X %X", curTick32kHz, 
//			curSampCentIx3, curSampCentIx3[2:0], nextPcmRangeCenter3);

		case(curSampCentIx3[1:0])
			2'h0: begin
				if(curAdpcmStep>0)
					nextAdpcmStep = curAdpcmStep-1;
				tAdpcmStepOfs =
					(curAdpcmStepVal>>3);
			end
			2'h1: begin
				nextAdpcmStep = curAdpcmStep;
				tAdpcmStepOfs =
					(curAdpcmStepVal>>2)+
					(curAdpcmStepVal>>3);
			end
			2'h2: begin
				nextAdpcmStep = curAdpcmStep+1;
				tAdpcmStepOfs =
					(curAdpcmStepVal>>1)+
					(curAdpcmStepVal>>3);
			end
			2'h3: begin
				nextAdpcmStep = curAdpcmStep+3;
				tAdpcmStepOfs =
					(curAdpcmStepVal>>1)+
					(curAdpcmStepVal>>2)+
					(curAdpcmStepVal>>3);
			end
		endcase
		if(curSampCentIx3[2])
			nextAdpcmPred = curAdpcmPred - tAdpcmStepOfs;
		else
			nextAdpcmPred = curAdpcmPred + tAdpcmStepOfs;

		if(curTick32kHz[3:0]==0)
		begin
//			$display("B %X_%X",
//				curDspBlockB2[31: 0],
//				curDspBlockA2[31: 0]);
		
			nextSampCentIx3[47:16] = curDspBlockB2[31: 0];
			nextSampCentIx3[15: 0] = curDspBlockA2[31:16];
			nextSampCentIx2[31: 0] = curDspBlockB2[31: 0];
			nextSampSideIx2[ 7: 0] = curDspBlockA2[31:24];
			if(curDspBlockA2[5:0]<=56)
			begin
				nextPcmMode = 3;
//				nextAdpcmPred = { curDspBlockA2[15: 6], 6'h00 };
				nextAdpcmPred = { curDspBlockA2[15: 6], 6'h00 }^16'h8000;
				nextAdpcmStep = curDspBlockA2[5: 0];
			end
			else
			begin
				case(curDspBlockA2[2:0])

				2: begin
//					pcmRangeCentAvg = { curDspBlockA2[11: 6], 10'h0}^16'h8000;
					pcmRangeCentAvg = { curDspBlockA2[11: 6], 10'h0};
					pcmRangeCentOfs = { 2'h0, curDspBlockA2[15:12], 10'h0};
//					pcmRangeSideAvg = { curDspBlockA2[20:16], 11'h0}^16'h8000;
					pcmRangeSideAvg = { curDspBlockA2[20:16], 11'h0};
					pcmRangeSideOfs = { 2'h0, curDspBlockA2[23:21], 11'h0};
					nextPcmMode = 1;
				end
				3: begin
//					pcmRangeCentAvg = { curDspBlockA2[10: 6], 11'h0}^16'h8000;
					pcmRangeCentAvg = { curDspBlockA2[10: 6], 11'h0};
					pcmRangeCentOfs = { curDspBlockA2[15:11], 11'h0};
//					pcmRangeSideAvg = { curDspBlockA2[20:16], 11'h0}^16'h8000;
					pcmRangeSideAvg = { curDspBlockA2[20:16], 11'h0};
					pcmRangeSideOfs = { 2'h0, curDspBlockA2[23:21], 11'h0};
					nextPcmMode = 1;
				end

				4: begin
//					pcmRangeCentAvg = { curDspBlockA2[12: 6], 9'h0}^16'h8000;
					pcmRangeCentAvg = { curDspBlockA2[12: 6], 9'h0};
					pcmRangeCentOfs = { 4'h0, curDspBlockA2[15:13], 9'h0};
					pcmRangeSideAvg = 32768;
					pcmRangeSideOfs = 0;
					nextPcmMode = 0;
				end
				5: begin
//					pcmRangeCentAvg = { curDspBlockA2[11: 6], 10'h0}^16'h8000;
					pcmRangeCentAvg = { curDspBlockA2[11: 6], 10'h0};
					pcmRangeCentOfs = { 2'h0, curDspBlockA2[15:12], 10'h0};
					pcmRangeSideAvg = 32768;
					pcmRangeSideOfs = 0;
					nextPcmMode = 0;
				end
				6: begin
//					pcmRangeCentAvg = { curDspBlockA2[10: 6], 11'h0}^16'h8000;
					pcmRangeCentAvg = { curDspBlockA2[10: 6], 11'h0};
					pcmRangeCentOfs = { curDspBlockA2[15:11], 11'h0};
					pcmRangeSideAvg = 32768;
					pcmRangeSideOfs = 0;
					nextPcmMode = 0;
				end

				7: begin
					pcmRangeCentAvg = 32768;
					pcmRangeCentOfs = 65535;
					pcmRangeSideAvg = 32768;
					pcmRangeSideOfs = 0;
					nextPcmMode = 0;
				end
				
				default: begin end
				endcase

				nextPcmRangeCentMin = pcmRangeCentAvg-(pcmRangeCentOfs>>1);
				nextPcmRangeCentMax = pcmRangeCentAvg+(pcmRangeCentOfs>>1);
				nextPcmRangeSideMin = pcmRangeSideAvg-(pcmRangeSideOfs>>1);
				nextPcmRangeSideMax = pcmRangeSideAvg+(pcmRangeSideOfs>>1);
				
//				$display("LB %X %X %X",
//					nextPcmRangeCentMin, nextPcmRangeCentMax,
//					nextSampCentIx3);
			end
		end
	end
	
//	nextPwmValueL = curTick1kHz[0] ? 48000 : 16384;
//	nextPwmValueR = curTick1kHz[1] ? 48000 : 16384;
end

always @ (posedge clock)
begin
	oBusIrqLive		<= oNextBusIrqLive;

	curTick10MHz	<= nextTick10MHz;
	curTick1MHz		<= nextTick1MHz;
	curTick32kHz	<= nextTick32kHz;
	curTick1kHz		<= nextTick1kHz;

	curCnt10MHz		<= nextCnt10MHz;
	curCnt1MHz		<= nextCnt1MHz;
	curCnt32kHz		<= nextCnt32kHz;
	curCnt1kHz		<= nextCnt1kHz;

	curPwmOut		<= nextPwmOut;

	curPwmStateL	<= nextPwmStateL;
	curPwmStateR	<= nextPwmStateR;
	curPwmValueL	<= nextPwmValueL;
	curPwmValueR	<= nextPwmValueR;
	curPwmCarryL	<= nextPwmCarryL;
	curPwmCarryR	<= nextPwmCarryR;

	curDspBlockA0	<= nextDspBlockA0;
	curDspBlockB0	<= nextDspBlockB0;
	curDspBlockC0	<= nextDspBlockC0;
	curDspBlockD0	<= nextDspBlockD0;
	curDspBlockA1	<= nextDspBlockA1;
	curDspBlockB1	<= nextDspBlockB1;
	curDspBlockC1	<= nextDspBlockC1;
	curDspBlockD1	<= nextDspBlockD1;
	curDspBlockA2	<= nextDspBlockA2;
	curDspBlockB2	<= nextDspBlockB2;

	curSampCentIx3	<= nextSampCentIx3;
	curSampCentIx2	<= nextSampCentIx2;
	curSampSideIx2	<= nextSampSideIx2;

	pcmRangeCentMin	<= nextPcmRangeCentMin;
	pcmRangeCentMax	<= nextPcmRangeCentMax;
	pcmRangeSideMin	<= nextPcmRangeSideMin;
	pcmRangeSideMax	<= nextPcmRangeSideMax;
	pcmRangeCenter3	<= nextPcmRangeCenter3;
	pcmRangeCenter2	<= nextPcmRangeCenter2;
	pcmRangeSide2	<= nextPcmRangeSide2;
	pcmMode			<= nextPcmMode;

	curAdpcmPred	<= nextAdpcmPred;
	curAdpcmStep	<= nextAdpcmStep;
	curAdpcmStepVal	<= nextAdpcmStepVal;
end

endmodule
