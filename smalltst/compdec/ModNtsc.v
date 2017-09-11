/*
NTSC Module
 */

module ModNtsc(clock, reset, pixCy, pixCu, pixCv,
	pwmOut, pixPosX, pixPosY);

/* verilator lint_off UNUSED */

input clock;
input reset;

input[7:0] pixCy;
input[7:0] pixCu;
input[7:0] pixCv;

output[3:0] pwmOut;

output[9:0] pixPosX;
output[9:0] pixPosY;


reg[7:0]	cbPwmTab[31:0];

reg[3:0]	tPwmOut;			//PWM output bits
reg[3:0]	tPwmSt;				//PWM State
reg[3:0]	tPwmNextSt;			//Next PWM State
reg[7:0]	tPwmVal;			//PWM Value
reg[7:0]	tPwmNextVal;		//Next PWM Value
reg			tPwmCarry;

reg[21:0]	tCbAcc;				//Colorburst Accumulator
reg[21:0]	tCbNextAcc;			//Next Colorburst Accumulator

reg[12:0]	tScanPixClk;		//Scan Pixel Clock
reg[12:0]	tScanNextPixClk;	//Next Scan Pixel Clock

reg[10:0]	tScanRowClk;		//Scan Row Clock
reg[10:0]	tScanNextRowClk;	//Next Scan Row Clock

reg[2:0]	tVSyncClk;
reg[2:0]	tVSyncNextClk;

reg[2:0]	tVEqPulseClk;
reg[2:0]	tVEqPulseNextClk;

reg[1:0]	tVFieldCnt;
reg[1:0]	tVFieldNextCnt;

reg[4:0]	tPhaseCb;
reg[4:0]	tPhaseCu;
reg[4:0]	tPhaseCv;

reg[15:0]	tModCu;
reg[15:0]	tModCv;
reg[15:0]	tModNextCu;
reg[15:0]	tModNextCv;

reg[15:0]	tBaseCy;
reg[15:0]	tBaseCu;
reg[15:0]	tBaseCv;

reg[15:0]	tBaseNextCy;
reg[15:0]	tBaseNextCu;
reg[15:0]	tBaseNextCv;

reg[17:0]	tScPwmCy;
reg[15:0]	tScPwmCu;
reg[15:0]	tScPwmCv;

reg[9:0]	tScPwmCt;

reg[9:0]	tPixPosX;
reg[9:0]	tPixPosY;
reg[9:0]	tPixNextPosX;
reg[9:0]	tPixNextPosY;

reg[7:0]	tPixCy;
reg[7:0]	tPixCu;
reg[7:0]	tPixCv;

assign pwmOut = tPwmOut;
assign pixPosX = tPixPosX;
assign pixPosY = tPixPosY;


initial
begin
	cbPwmTab[ 0]=8'h80;		cbPwmTab[ 1]=8'h87;
	cbPwmTab[ 2]=8'h8E;		cbPwmTab[ 3]=8'h94;
	cbPwmTab[ 4]=8'h9A;		cbPwmTab[ 5]=8'h9E;
	cbPwmTab[ 6]=8'hA2;		cbPwmTab[ 7]=8'hA4;
	cbPwmTab[ 8]=8'hA5;		cbPwmTab[ 9]=8'hA4;
	cbPwmTab[10]=8'hA2;		cbPwmTab[11]=8'h9E;
	cbPwmTab[12]=8'h9A;		cbPwmTab[13]=8'h94;
	cbPwmTab[14]=8'h8E;		cbPwmTab[15]=8'h87;
	cbPwmTab[16]=8'h80;		cbPwmTab[17]=8'h79;
	cbPwmTab[18]=8'h72;		cbPwmTab[19]=8'h6C;
	cbPwmTab[20]=8'h66;		cbPwmTab[21]=8'h62;
	cbPwmTab[22]=8'h5E;		cbPwmTab[23]=8'h5C;
	cbPwmTab[24]=8'h5B;		cbPwmTab[25]=8'h5C;
	cbPwmTab[26]=8'h5E;		cbPwmTab[27]=8'h62;
	cbPwmTab[28]=8'h66;		cbPwmTab[29]=8'h6C;
	cbPwmTab[30]=8'h72;		cbPwmTab[31]=8'h79;
end

reg[3:0]	tPwmOutA;
reg[3:0]	tPwmOutB;
reg			tPwmOutCarry;

always @ (clock)
begin
//	tPwmNextSt = tPwmSt + tPwmVal;
//	tPwmNextSt = tPwmSt + ((tPwmVal<<4)&255);
	{tPwmCarry, tPwmNextSt} = {1'b0, tPwmSt} + {1'b0, tPwmVal[3:0]};

	tCbNextAcc = tCbAcc + 150137;
//	tPwmOut = tPwmNextSt[8];
//	tPwmOut = tPwmNextSt[8] ? (tPwmVal[7:4]+1) : tPwmVal[7:4];

	tPwmOutA = tPwmVal[7:4];
	{tPwmOutCarry, tPwmOutB} = {1'b0, tPwmOutA} + 1;
	tPwmOut = (tPwmCarry && !tPwmOutCarry) ?
		tPwmOutB : tPwmOutA;

//	tPwmOut = (tPwmNextSt[4] && (tPwmVal[7:4]!=15)) ?
//		(tPwmVal[7:4]+1) : tPwmVal[7:4];


	tScanNextPixClk = tScanPixClk + 1;
	tScanNextRowClk = tScanRowClk;

	tVSyncNextClk = tVSyncClk;
	tVFieldNextCnt = tVFieldCnt;
	tVEqPulseNextClk = tVEqPulseClk;
	
	tPixNextPosX = 0;
	tPixNextPosY = 0;

	tModNextCu=0;
	tModNextCv=0;
	tBaseNextCu=0;
	tBaseNextCv=0;

	tPwmNextVal = 76;

	if(tVSyncClk>0)		/* VSync */
	begin
		tScanNextRowClk = 0;
		if(tScanPixClk>=3176)
		begin
			tVSyncNextClk = tVSyncClk - 1;
			tScanNextPixClk = 0;
		end
		else if(tScanPixClk>=472)
			tPwmNextVal = 0;
	end
	else if(tVEqPulseClk>0)		/* Equalizing Pulse */
	begin
		tScanNextRowClk = 0;
		if(tScanPixClk>=3176)
		begin
			tVEqPulseNextClk = tVEqPulseClk - 1;
			tScanNextPixClk = 0;
		end
		else if(tScanPixClk>=2944)
			tPwmNextVal = 0;
	end
	else		/* VBlank or Scanline */
	begin
		tPhaseCb = tCbAcc[21:17];

//		tPhaseCu = tCbAcc[21:17]+10;
//		tPhaseCv = tCbAcc[21:17]+2;

		tPhaseCu = tCbAcc[21:17]+11;
		tPhaseCv = tCbAcc[21:17]+3;

		tModNextCu[15:0] = {8'h00, cbPwmTab[tPhaseCu]} - 128;
		tModNextCv[15:0] = {8'h00, cbPwmTab[tPhaseCv]} - 128;

		if(tScanPixClk>=6352)
		begin
			tScanNextRowClk = tScanRowClk + 1;
			tScanNextPixClk = 0;
			
			if(tScanNextRowClk>=262)
			begin
				tVFieldNextCnt = tVFieldCnt + 1;
				tVSyncNextClk = 5;
				tVEqPulseNextClk = tVFieldCnt[0] ? 5 : 6;

				case(tVFieldCnt[1:0])
					0: tCbNextAcc = ( 0*131072);
					1: tCbNextAcc = ( 8*131072);
					2: tCbNextAcc = (16*131072);
					3: tCbNextAcc = (24*131072);
				endcase
			end
		end
		else if(tScanPixClk>=5880)
			tPwmNextVal = 0;
		else if((tScanPixClk>=112) && (tScanPixClk<360))
		begin
			tPwmNextVal = cbPwmTab[tPhaseCb]-32;
		end
		else if((tScanPixClk>=472) && (tScanPixClk<5592))
		begin
			tPixNextPosX = tScanPixClk[12:3] - 59;
			tPixNextPosY = tScanNextRowClk[9:0] - 20;

			tBaseNextCy[15:8] = 0;
			tBaseNextCy[7:0] = tPixCy;

			tBaseNextCu = {8'h0, tPixCu} - 128;
			tBaseNextCv = {8'h0, tPixCv} - 128;
			
			tScPwmCy[17:16] = 0;
//			tScPwmCy[15:0] = 153 * tBaseCy + 19456;
			tScPwmCy[15:0] = 144 * tBaseCy + 19456;
			tScPwmCu = tModCu * tBaseCu;
			tScPwmCv = tModCv * tBaseCv;
			tScPwmCt = tScPwmCy[17:8] + tScPwmCu[15:6] + tScPwmCv[15:6];

			tPwmNextVal = tScPwmCt[7:0];
		end
	end
end

always @ (posedge clock)
begin

	tPwmSt			<= tPwmNextSt;

	tPwmVal			<= tPwmNextVal;
	tCbAcc			<= tCbNextAcc;

	tScanPixClk		<= tScanNextPixClk;
	tScanRowClk		<= tScanNextRowClk;

	tVSyncClk		<= tVSyncNextClk;
	tVEqPulseClk	<= tVEqPulseNextClk;
	tVFieldCnt		<= tVFieldNextCnt;

	tPixPosX		<= tPixNextPosX;
	tPixPosY		<= tPixNextPosY;

	tPixCy			<= pixCy;
	tPixCu			<= pixCu;
	tPixCv			<= pixCv;

	tBaseCy			<= tBaseNextCy;
	tBaseCu			<= tBaseNextCu;
	tBaseCv			<= tBaseNextCv;
	tModCu			<= tModNextCu;
	tModCv			<= tModNextCv;

end

endmodule
