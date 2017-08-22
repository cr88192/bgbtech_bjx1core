module FbNtMod(clock, reset, pwmOut,
	busAddr, busData, busOE, busWR, busHold);

input clock;
input reset;

output pwmOut;

input[39:0] busAddr;
inout[31:0] busData;
input busOE;
input busWR;
output busHold;

reg[7:0]	cbPwmTab[32];

reg tPwmOut;
reg[8:0]	tPwmSt;			//PWM State
reg[8:0]	tPwmNextSt;		//Next PWM State
reg[8:0]	tPwmVal;		//PWM Value
reg[7:0]	tPwmNextVal;	//Next PWM Value

reg[31:0]	tCbAcc;			//Colorburst Accumulator
reg[31:0]	tCbNextAcc;		//Next Colorburst Accumulator

reg[12:0]	tScanPixClk;		//Scan Pixel Clock
reg[12:0]	tScanNextPixClk;	//Next Scan Pixel Clock

reg[10:0]	tScanRowClk;		//Scan Row Clock
reg[10:0]	tScanNextRowClk;	//Next Scan Row Clock

reg[2:0]	tVSyncClk;
reg[2:0]	tVSyncNextClk;

reg[2:0]	tVEqPulseClk;
reg[2:0]	tVEqPulseNextClk;

reg[4:0]	tPhaseCu;
reg[4:0]	tPhaseCv;

reg[15:0]	tModCu;
reg[15:0]	tModCv;

reg[15:0]	tBaseCy;
reg[15:0]	tBaseCu;
reg[15:0]	tBaseCv;

reg[15:0]	tScPwmCy;
reg[15:0]	tScPwmCu;
reg[15:0]	tScPwmCv;

reg[9:0]	tPixPosX;
reg[9:0]	tPixPosY;
reg[9:0]	tPixNextPosX;
reg[9:0]	tPixNextPosY;

reg[7:0]	tPixCy;
reg[7:0]	tPixCu;
reg[7:0]	tPixCv;

assign pwmOut = tPwmOut;


reg[12:0]	tPixCellX;		//base cell X
reg[12:0]	tPixCellY;		//base cell Y
reg[12:0]	tPixCellIx;		//base cell index

reg[3:0]	tPixCellFx;		//base cell index

reg[31:0]	scrCell[8191:0];
reg[31:0]	tCell;

reg[7:0]	tCellCy;
reg[7:0]	tCellDy;
reg[7:0]	tCellCu;
reg[7:0]	tCellCv;

/*
reg[3:0]	tCellPCy;
reg[3:0]	tCellPDy;
reg[3:0]	tCellPCu;
reg[3:0]	tCellPCv;

reg[7:0]	tCellPIxCy;
reg[7:0]	tCellPIxDy;
reg[7:0]	tCellPIxCu;
reg[7:0]	tCellPIxCv;

reg[7:0]	tCellLastCy;
reg[7:0]	tCellLastDy;
reg[7:0]	tCellLastCu;
reg[7:0]	tCellLastCv;
*/

reg[7:0]	tCellCAr;
reg[7:0]	tCellCAg;
reg[7:0]	tCellCAb;
reg[7:0]	tCellCBr;
reg[7:0]	tCellCBg;
reg[7:0]	tCellCBb;

reg[7:0]	tCellMCy;
reg[7:0]	tCellNCy;
reg[7:0]	tCellMCu;
reg[7:0]	tCellNCu;
reg[7:0]	tCellMCv;
reg[7:0]	tCellNCv;

reg			tCellBit;
reg			tBusCSel;

reg[15:0]	tCellBit16;

// reg[7:0]	pStepTab[255:0];

initial
begin
	cbPwmTab[ 0]=8'h00;		cbPwmTab[ 1]=8'h07;
	cbPwmTab[ 2]=8'h0E;		cbPwmTab[ 3]=8'h14;
	cbPwmTab[ 4]=8'h1A;		cbPwmTab[ 5]=8'h1E;
	cbPwmTab[ 6]=8'h22;		cbPwmTab[ 7]=8'h24;
	cbPwmTab[ 8]=8'h25;		cbPwmTab[ 9]=8'h24;
	cbPwmTab[10]=8'h22;		cbPwmTab[11]=8'h1E;
	cbPwmTab[12]=8'h1A;		cbPwmTab[13]=8'h14;
	cbPwmTab[14]=8'h0E;		cbPwmTab[15]=8'h07;
	cbPwmTab[16]=8'h00;		cbPwmTab[17]=8'hF9;
	cbPwmTab[18]=8'hF2;		cbPwmTab[19]=8'hEC;
	cbPwmTab[20]=8'hE6;		cbPwmTab[21]=8'hE2;
	cbPwmTab[22]=8'hDE;		cbPwmTab[23]=8'hDC;
	cbPwmTab[24]=8'hDB;		cbPwmTab[25]=8'hDC;
	cbPwmTab[26]=8'hDE;		cbPwmTab[27]=8'hE2;
	cbPwmTab[28]=8'hE6;		cbPwmTab[29]=8'hEC;
	cbPwmTab[30]=8'hF2;		cbPwmTab[31]=8'hF9;
end

always @ (clock)
begin
	
	tBusCSel = 0;

//	if(busAddr[39:28]==12'hA0_A)
	if(busAddr[39:16]==24'hA0_A000)
		tBusCSel=1;

	if(tBusCSel && busOE)
	begin
		busHold = 0;
		busData = scrCell[busAddr[14:2]];
	end
	
	tPixCellX=0;
	tPixCellY=0;
	tPixCellX[6:0] = tPixPosX[9:3];
	tPixCellY[6:0] = tPixPosY[8:2];

	tPixCellFx[1:0] = tPixPosX[2:1];
	tPixCellFx[3:2] = tPixPosY[1:0];

	tPixCellIx = tPixCellY*80 + tPixCellX;
//	tPixCellIx = tPixPosY[8:2]*80 + tPixPosX[9:3];
	tCell = scrCell[tPixCellIx];
	
	case(tCell[31:30])
	1: begin
		tCellCAr[7:6]=tCell[27:26];
		tCellCAg[7:6]=tCell[25:24];
		tCellCAb[7:6]=tCell[23:22];
		tCellCBr[7:6]=tCell[21:20];
		tCellCBg[7:6]=tCell[19:18];
		tCellCBb[7:6]=tCell[17:16];
		tCellCAr[5:4]=tCellCAr[7:6];
		tCellCAr[3:2]=tCellCAr[7:6];
		tCellCAg[5:4]=tCellCAg[7:6];
		tCellCAg[3:2]=tCellCAg[7:6];
		tCellCAb[5:4]=tCellCAb[7:6];
		tCellCAb[3:2]=tCellCAb[7:6];
		tCellCBr[5:4]=tCellCBr[7:6];
		tCellCBr[3:2]=tCellCBr[7:6];
		tCellCBg[5:4]=tCellCBg[7:6];
		tCellCBg[3:2]=tCellCBg[7:6];
		tCellCBb[5:4]=tCellCBb[7:6];
		tCellCBb[3:2]=tCellCBb[7:6];

		tCellMCy = tCellCAg;
		tCellNCy = tCellCBg;
		tCellMCu = ((tCellCAb - tCellCAg) >>> 1) + 128;
		tCellMCv = ((tCellCAr - tCellCAg) >>> 1) + 128;
		tCellNCu = ((tCellCBb - tCellCBg) >>> 1) + 128;
		tCellNCv = ((tCellCBr - tCellCBg) >>> 1) + 128;
	end

/*
	2: begin
		tCellPCy[3:0]=tCell[29:26];		tCellPDy[3:0]=tCell[25:22];
		tCellPCu[2:0]=tCell[21:19];		tCellPCv[2:0]=tCell[18:16];
		tCellPIxCy[3:0]=tCellPCy;		tCellPIxDy[3:0]=tCellPDy;
		tCellPIxCu[3:1]=tCellPCu;		tCellPIxCv[3:1]=tCellPDu;
		tCellPIxCu[0]=tCellPCu[3];		tCellPIxCv[0]=tCellPCv[3];
		tCellPIxCy[7:4]=tCellLastPIxCy[7:4];
		tCellPIxDy[7:4]=tCellLastPIxDy[7:4];
		tCellPIxCu[7:4]=tCellLastPIxCu[7:4];
		tCellPIxCv[7:4]=tCellLastPIxCv[7:4];
		tCellCy=tCellLastCy+pStepTab[tCellPIxCy];
		tCellDy=tCellLastDy+pStepTab[tCellPIxDy];
		tCellCu=tCellLastCu+pStepTab[tCellPIxCu];
		tCellCv=tCellLastCv+pStepTab[tCellPIxCv];
	end
*/

	3: begin
		tCellCy[7:4]=tCell[29:26];		tCellCy[3:0]=tCell[29:26];
		tCellDy[7:4]=tCell[25:22];		tCellDy[3:0]=tCell[25:22];
		tCellCu[7:5]=tCell[21:19];		tCellCv[7:5]=tCell[18:16];
		tCellCu[4:2]=tCellCu[7:5];		tCellCv[4:2]=tCellCv[7:5];
		tCellCu[1:0]=tCellCu[7:6];		tCellCv[1:0]=tCellCv[7:6];
		tCellMCy=tCellCy-(tCellDy>>1);	tCellNCy=tCellMCy+tCellDy;
		tCellMCu=tCellCu;				tCellNCu=tCellCu;
		tCellMCv=tCellCv;				tCellNCv=tCellCv;
		tCellBit16 = tCell[15:0];
	end
	default:
	begin
		tCellMCy=128;
		tCellNCy=128;
		tCellNCu=192;
		tCellNCv=192;
		tCellMCu=64;
		tCellMCv=64;
		tCellBit16 = tPixCellIx[0] ? 16'hFF00 : 16'h00FF;
//		tCellBit16 = tPixPosX[3] ? 16'hFF00 : 16'h00FF;
		
	end
	endcase
	
	case(tPixCellFx)
		 0: tCellBit=tCellBit16[ 3];		 1: tCellBit=tCellBit16[ 2];
		 2: tCellBit=tCellBit16[ 1];		 3: tCellBit=tCellBit16[ 0];
		 4: tCellBit=tCellBit16[ 7];		 5: tCellBit=tCellBit16[ 6];
		 6: tCellBit=tCellBit16[ 5];		 7: tCellBit=tCellBit16[ 4];
		 8: tCellBit=tCellBit16[11];		 9: tCellBit=tCellBit16[10];
		10: tCellBit=tCellBit16[ 9];		11: tCellBit=tCellBit16[ 8];
		12: tCellBit=tCellBit16[15];		13: tCellBit=tCellBit16[14];
		14: tCellBit=tCellBit16[13];		15: tCellBit=tCellBit16[12];
	endcase
	
	if(tCellBit)
	begin
		tPixCy = tCellNCy;
		tPixCu = tCellNCu;
		tPixCv = tCellNCv;
	end
	else
	begin
		tPixCy = tCellMCy;
		tPixCu = tCellMCu;
		tPixCv = tCellMCv;
	end

end

always @ (clock)
begin
	tPwmNextSt = tPwmSt + tPwmVal;
	tCbNextAcc = tCbAcc + 150137;
	tScanNextPixClk = tScanPixClk + 1;
	tScanNextRowClk = tScanRowClk;
	tPwmOut = tPwmNextSt[8];

	tPwmNextVal=0;
	tVSyncNextClk = tVSyncClk;
	
	tPixNextPosX = 0;
	tPixNextPosY = 0;
	
	if(tVSyncClk>0)		/* VSync */
	begin
		tScanNextRowClk = 0;
		if(tScanPixClk>3176)
		begin
			tVSyncNextClk = tVSyncClk - 1;
			tScanNextPixClk = 0;
		end
		else if(tScanPixClk<472)
		begin
			tPwmNextVal = 76;
		end
		else
		begin
			tPwmNextVal = 0;
		end
	end
	else if(tVEqPulseClk>0)		/* Equalizing Pulse */
	begin
		tScanNextRowClk = 0;
		if(tScanPixClk>3176)
		begin
			tVEqPulseNextClk = tVEqPulseClk - 1;
			tScanNextPixClk = 0;
		end
		else if(tScanPixClk<2944)
		begin
			tPwmNextVal = 76;
		end
		else
		begin
			tPwmNextVal = 0;
		end
	end
	else		/* VBlank or Scanline */
	begin
		tPwmNextVal = 76;

		if(tScanPixClk>6352)
		begin
			tScanNextRowClk = tScanRowClk + 1;
			tScanNextPixClk = 0;
			
			if(tScanNextRowClk>=262)
			begin
				tVSyncNextClk = 5;
				tVEqPulseNextClk = 5;
			end
		end
		else if(tScanPixClk>5880)
		begin
			tPwmNextVal = 0;
		end
		else if((tScanPixClk>112) && (tScanPixClk<360))
		begin
			tPhaseCv = tCbAcc[21:17];
			tPwmNextVal = 76+cbPwmTab[tPhaseCv];
		end
		else if((tScanPixClk<472) || (tScanRowClk<20))
		begin
			tPwmNextVal = 76;
		end
		else if((tScanPixClk>=472) && (tScanPixClk<5592))
		begin
			tPwmNextVal = 76;
			tPhaseCu = tCbAcc[21:17]+10;
			tPhaseCv = tCbAcc[21:17]+2;

			tPixNextPosX = tScanPixClk[12:3] - 59;
			tPixNextPosY = tScanNextRowClk[9:0] - 20;

			tModCu[7:0] = cbPwmTab[tPhaseCu];
			tModCv[7:0] = cbPwmTab[tPhaseCv];
			tModCu[15:8] = tModCu[7] ? (-1) : 0;
			tModCv[15:8] = tModCv[7] ? (-1) : 0;
			tBaseCu[7:0] = tPixCu - 128;
			tBaseCv[7:0] = tPixCv - 128;
			tBaseCu[15:8] = tBaseCu[7] ? (-1) : 0;
			tBaseCv[15:8] = tBaseCv[7] ? (-1) : 0;

			tBaseCy[15:8] = 0;
			tBaseCy[7:0] = tPixCy;
			
			tScPwmCy = 153 * tBaseCy + 19456;
			tScPwmCu = tModCu * tBaseCu;
			tScPwmCv = tModCv * tBaseCv;
			tPwmNextVal = tScPwmCy[15:8] + tScPwmCu[13:6] + tScPwmCv[13:6];
		end
	end
end

always @ (posedge clock)
begin
	tPwmSt[8]		<= 0;
	tPwmSt[7:0]		<= tPwmNextSt[7:0];
	tPwmVal[7:0]	<= tPwmNextVal;
	tCbAcc			<= tCbNextAcc;

	tScanPixClk		<= tScanNextPixClk;
	tScanRowClk		<= tScanNextRowClk;

	tVSyncClk		<= tVSyncNextClk;
	tVEqPulseClk	<= tVEqPulseNextClk;

	tPixPosX		<= tPixNextPosX;
	tPixPosY		<= tPixNextPosY;
	
//	tCellLastCy		<= tCellCy;
//	tCellLastDy		<= tCellDy;
//	tCellLastCu		<= tCellCu;
//	tCellLastCv		<= tCellCv;

	if(tBusCSel && busWR)
	begin
		scrCell[busAddr[14:2]] <= busData;
	end
end


endmodule
