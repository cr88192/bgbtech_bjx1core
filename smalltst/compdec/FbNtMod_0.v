/*
Framebuffer Format

scrIs320=0		//640x240, 4x4x1 in 32 bits
scrIs320=1		//320x240, 4x4x2 in 64 bits
	
32-bit blocks:
 00pp-pppp pppp-pppp pppp-pppp pppp-pppp
   4x4x2, prior colors, UL pixel is ColorA
 01pp-pppp pppp-pppp pppp-pppp pppp-pppp
   4x4x2, prior colors, UL pixel is ColorB
 10yy-yzzz uuvv-wwxx pppp-pppp pppp-pppp
   4x4x1, YUV pair, ColorA=yuv, ColorB=zwx
 11yy-yydd dduu-uvvv pppp-pppp pppp-pppp
   4x4x1, YUVD centroid

64-bit blocks:
 00pp-pppp pppp-pppp pppp-pppp pppp-pppp
   Reserved
 01pp-pppp pppp-pppp pppp-pppp pppp-pppp
   Reserved
 10yy-yyyy yzzz-zzzz uuuu-vvvv wwww-xxxx
   4x4x2, YUV pair, ColorA=yuv, ColorB=zwx
 11uu-uuuu uvvv-vvvv yyyy-yyyy dddd-dddd
   4x4x2, YUVD centroid
   
 A0_A000_XXXX: VRAM/Ctrl
   0000..7FFF: First 32kB
   8000..9FFF: Last 8kB
   FF00..FFFF: Registers
 */

module FbNtMod(clock, reset, pwmOut,
	busAddr, busData, busOE, busWR, busHold);

/* verilator lint_off UNUSED */

input clock;
input reset;

output[3:0] pwmOut;

input[39:0] busAddr;
inout[31:0] busData;
input busOE;
input busWR;
output busHold;

reg[7:0]	cbPwmTab[31:0];

reg			tBusHold;			//IO Hold State
reg[31:0] 	tBusData;			//Output Data
wire		tBusCSel;			//Bus Chip-Select (Addr Matches)

assign	busHold = (busOE && tBusCSel) ? tBusHold : 1'bZ;
assign	busData = (busOE && tBusCSel) ? tBusData : 32'hZZZZ_ZZZZ;
// assign	busHold = 1'bZ;
// assign	busData = 32'hZZZZ_ZZZZ;
assign  tBusCSel = (busAddr[39:16]==24'hA0_A000);

reg[3:0]	tPwmOut;			//PWM output bits
reg[3:0]	tPwmSt;				//PWM State
reg[3:0]	tPwmNextSt;			//Next PWM State
reg[7:0]	tPwmVal;			//PWM Value
reg[7:0]	tPwmNextVal;		//Next PWM Value
reg			tPwmCarry;

// reg[31:0]	tCbAcc;				//Colorburst Accumulator
// reg[31:0]	tCbNextAcc;			//Next Colorburst Accumulator
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

reg[7:0]	tPixNextCy;
reg[7:0]	tPixNextCu;
reg[7:0]	tPixNextCv;

assign pwmOut = tPwmOut;


reg[13:0]	tPixCellX;			//base cell X
reg[13:0]	tPixCellY;			//base cell Y

reg[13:0]	tPixCellIx;			//base cell index
reg[3:0]	tPixCellFx;			//base cell index

reg[13:0]	tPixCellNextIx;		//base cell index
reg[3:0]	tPixCellNextFx;		//base cell index

reg[31:0]	scrCell1A[0:4095];	//Screen Memory (1/2 32kB)
reg[31:0]	scrCell1B[0:4095];	//Screen Memory (1/2 32kB)
reg[31:0]	scrCell2A[0:1023];	//Screen Memory (1/2 8kB)
reg[31:0]	scrCell2B[0:1023];	//Screen Memory (1/2 8kB)

reg[31:0]	scrRegCtrl[7:0];	//Control Registers
reg			scrIs320;			//use 320x240 64 bit cells

reg			scrCellNoRead;

reg[31:0]	tCell;
reg[31:0]	tCell1;
reg[31:0]	tCell2;
reg[31:0]	tNextCell1;
reg[31:0]	tNextCell2;

reg[9:0]	tCellCy;
reg[9:0]	tCellDy;
reg[9:0]	tCellCu;
reg[9:0]	tCellCv;

reg[9:0]	tCellMCy;
reg[9:0]	tCellNCy;
reg[9:0]	tCellMCu;
reg[9:0]	tCellNCu;
reg[9:0]	tCellMCv;
reg[9:0]	tCellNCv;

reg[9:0]	tCellNextMCy;
reg[9:0]	tCellNextNCy;
reg[9:0]	tCellNextMCu;
reg[9:0]	tCellNextNCu;
reg[9:0]	tCellNextMCv;
reg[9:0]	tCellNextNCv;

//reg[9:0]	tCellLastMCy;
//reg[9:0]	tCellLastNCy;
//reg[9:0]	tCellLastMCu;
//reg[9:0]	tCellLastNCu;
//reg[9:0]	tCellLastMCv;
//reg[9:0]	tCellLastNCv;

reg[7:0]	tCellCy0;
reg[7:0]	tCellCu0;
reg[7:0]	tCellCv0;
reg[7:0]	tCellCy1;
reg[7:0]	tCellCu1;
reg[7:0]	tCellCv1;
reg[7:0]	tCellCy2;
reg[7:0]	tCellCu2;
reg[7:0]	tCellCv2;
reg[7:0]	tCellCy3;
reg[7:0]	tCellCu3;
reg[7:0]	tCellCv3;


reg[1:0]	tCellBit;
reg[1:0]	tCellNextBit;

reg[31:0]	tCellBits;
reg[31:0]	tCellNextBits;
reg			tCellUse32;
reg			tCellNextUse32;

initial
begin
/*
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
*/

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

always @ (clock)
begin
	
/*
	tBusHold = 0;
	if(busAddr[15])
		tBusData = busAddr[2]?
			scrCell2B[busAddr[12:3]]:
			scrCell2A[busAddr[12:3]];
	else
		tBusData = busAddr[2]?
			scrCell1B[busAddr[14:3]]:
			scrCell1A[busAddr[14:3]];
*/
	
	scrIs320 = 1;
//	scrIs320 = scrCell2[2047][0];
//	scrIs320 = scrCell2[11'h7C0][0];

	tCellCy=0;
	tCellDy=0;
	tCellCu=0;
	tCellCv=0;

//	tCellNextMCy=0;
//	tCellNextNCy=0;
//	tCellNextMCu=0;
//	tCellNextNCu=0;
//	tCellNextMCv=0;
//	tCellNextNCv=0;
	
	tCellNextMCy=tCellMCy;
	tCellNextNCy=tCellNCy;
	tCellNextMCu=tCellMCu;
	tCellNextNCu=tCellNCy;
	tCellNextMCv=tCellMCv;
	tCellNextNCv=tCellNCv;
	tCellNextBits=0;
	tCellNextBit=0;
	tCellNextUse32=0;

	tPixCellX=0;
	tPixCellY=0;

	if(scrIs320)
	begin
		tPixCellX[6:0] = tPixPosX[9:3];
		tPixCellY[6:0] = tPixPosY[8:2];

		tPixCellNextFx[1:0] = tPixPosX[2:1];
		tPixCellNextFx[3:2] = tPixPosY[1:0];
		tPixCellNextIx = tPixCellY*160 + tPixCellX*2;			
	end
	else
	begin
		tPixCellX[7:0] = tPixPosX[9:2];
		tPixCellY[6:0] = tPixPosY[8:2];

		tPixCellNextFx[1:0] = tPixPosX[1:0];
		tPixCellNextFx[3:2] = tPixPosY[1:0];
		tPixCellNextIx = tPixCellY*160 + tPixCellX;
	end

	tBusHold = 1;
	tBusData = 0;
	if(busOE && tBusCSel)
	begin
		tPixCellNextIx = busAddr[15:2];
		tBusHold = tPixCellIx != tPixCellNextIx;
		tBusData = busAddr[2] ? tCell2 : tCell1;
	end

	if(scrCellNoRead)
//	if(0)
	begin
		tNextCell1 = tCell1;
		tNextCell2 = tCell2;
	end
	else
	begin
		if(tPixCellIx[13])
		begin
			tNextCell1 = scrCell2A[tPixCellIx[10:1]];
			tNextCell2 = scrCell2B[tPixCellIx[10:1]];
		end
		else
		begin
			tNextCell1 = scrCell1A[tPixCellIx[12:1]];
			tNextCell2 = scrCell1B[tPixCellIx[12:1]];
		end
	end

	if(scrIs320)
	begin
		case(tCell1[31:30])
		2: begin
			tCellNextMCy[7:1]=tCell1[29:23];
			tCellNextNCy[7:1]=tCell1[22:16];
			tCellNextMCy[0]=tCell1[29];
			tCellNextNCy[0]=tCell1[22];

			tCellNextMCu[7:4]=tCell1[15:12];
			tCellNextMCv[7:4]=tCell1[11: 8];
			tCellNextNCu[7:4]=tCell1[ 7: 4];
			tCellNextNCv[7:4]=tCell1[ 3: 0];
			tCellNextMCu[3:0]=0;
			tCellNextMCv[3:0]=0;
			tCellNextNCu[3:0]=0;
			tCellNextNCv[3:0]=0;

			tCellNextBits = tCell2;
			tCellNextUse32 = 1;
			end

		3: begin
			tCellCy[7:0]=tCell1[15: 8];
			tCellDy[7:0]=tCell1[ 7: 0];
			tCellCu[7:1]=tCell1[29:23];
			tCellCv[7:1]=tCell1[22:16];
			tCellCu[0]=0;
			tCellCv[0]=0;

			tCellNextMCy=tCellCy-(tCellDy>>1);
			tCellNextNCy=tCellMCy+tCellDy;
			tCellNextMCu=tCellCu;
			tCellNextNCu=tCellCu;
			tCellNextMCv=tCellCv;
			tCellNextNCv=tCellCv;
			tCellNextBits = tCell2;
			tCellNextUse32 = 1;
		end

		endcase
	end
	else
	begin
		tCell = tPixCellIx[0] ? tCell2 : tCell1;
	
		case(tCell[31:30])
		
		0: begin
			tCellNextBits[31:0] = tCell[31:0];
			tCellNextUse32=1;
		end

		1: begin
			tCellNextBits[31:0] = tCell[31:0];
			tCellNextUse32=1;
		end

		2: begin
			tCellNextMCy[7:5]=tCell[29:27];
			tCellNextNCy[7:5]=tCell[26:24];
			tCellNextMCy[4:2]=tCell[29:27];
			tCellNextNCy[4:2]=tCell[26:24];
			tCellNextMCy[1:0]=tCell[29:28];
			tCellNextNCy[1:0]=tCell[26:25];

			tCellNextMCu[7:6]=tCell[23:22];
			tCellNextMCv[7:6]=tCell[21:20];
			tCellNextNCu[7:6]=tCell[19:18];
			tCellNextNCv[7:6]=tCell[17:16];
			tCellNextMCu[5:0]=0;
			tCellNextMCv[5:0]=0;
			tCellNextNCu[5:0]=0;
			tCellNextNCv[5:0]=0;
			
			tCellNextBits[15:0] = tCell[15:0];
			end
		
		3: begin
			tCellCy[7:4]=tCell[29:26];
			tCellCy[3:0]=tCell[29:26];
			tCellDy[7:4]=tCell[25:22];
			tCellDy[3:0]=tCell[25:22];

			tCellCu[7:5]=tCell[21:19];
			tCellCv[7:5]=tCell[18:16];
			tCellCu[4:0]=0;
			tCellCv[4:0]=0;

			tCellNextMCy=tCellCy-(tCellDy>>1);
			tCellNextNCy=tCellMCy+tCellDy;
			tCellNextMCu=tCellCu;
			tCellNextNCu=tCellCu;
			tCellNextMCv=tCellCv;
			tCellNextNCv=tCellCv;
			tCellNextBits[15:0] = tCell[15:0];
		end
		endcase
	end

//	tCellNextMCy=128;
//	tCellNextNCy=128;
//	tCellNextMCu=0;
//	tCellNextNCu=255;
//	tCellNextMCv=0;
//	tCellNextNCv=255;


	if(tCellUse32)
	begin
		case(tPixCellFx)
			 0: tCellNextBit=tCellBits[31:30];
			 1: tCellNextBit=tCellBits[29:28];
			 2: tCellNextBit=tCellBits[27:26];
			 3: tCellNextBit=tCellBits[25:24];
			 4: tCellNextBit=tCellBits[23:22];
			 5: tCellNextBit=tCellBits[21:20];
			 6: tCellNextBit=tCellBits[19:18];
			 7: tCellNextBit=tCellBits[17:16];
			 8: tCellNextBit=tCellBits[15:14];
			 9: tCellNextBit=tCellBits[13:12];
			10: tCellNextBit=tCellBits[11:10];
			11: tCellNextBit=tCellBits[ 9: 8];
			12: tCellNextBit=tCellBits[ 7: 6];
			13: tCellNextBit=tCellBits[ 5: 4];
			14: tCellNextBit=tCellBits[ 3: 2];
			15: tCellNextBit=tCellBits[ 1: 0];
		endcase
	end
	else
	begin
		tCellNextBit[1]=0;
		case(tPixCellFx)
			 0: tCellNextBit[0]=tCellBits[15];
			 1: tCellNextBit[0]=tCellBits[14];
			 2: tCellNextBit[0]=tCellBits[13];
			 3: tCellNextBit[0]=tCellBits[12];
			 4: tCellNextBit[0]=tCellBits[11];
			 5: tCellNextBit[0]=tCellBits[10];
			 6: tCellNextBit[0]=tCellBits[ 9];
			 7: tCellNextBit[0]=tCellBits[ 8];
			 8: tCellNextBit[0]=tCellBits[ 7];
			 9: tCellNextBit[0]=tCellBits[ 6];
			10: tCellNextBit[0]=tCellBits[ 5];
			11: tCellNextBit[0]=tCellBits[ 5];
			12: tCellNextBit[0]=tCellBits[ 3];
			13: tCellNextBit[0]=tCellBits[ 2];
			14: tCellNextBit[0]=tCellBits[ 1];
			15: tCellNextBit[0]=tCellBits[ 0];
		endcase
	end


	tPixNextCy = 0;
	tPixNextCu = 0;
	tPixNextCv = 0;

//	tCellCy0 = tCellLastNCy[7:0];
//	tCellCu0 = tCellLastNCu[7:0];
//	tCellCv0 = tCellLastNCv[7:0];

//	tCellCy1 = tCellLastMCy[7:0];
//	tCellCu1 = tCellLastMCu[7:0];
//	tCellCv1 = tCellLastMCv[7:0];


	if(tCellNCy[9])
		tCellCy0 = 0;
	else if(tCellNCy[8])
		tCellCy0 = 255;
	else
		tCellCy0 = tCellNCy[7:0];

	if(tCellNCu[9])
		tCellCu0 = 0;
	else if(tCellNCu[8])
		tCellCu0 = 255;
	else
		tCellCu0 = tCellNCu[7:0];

	if(tCellNCv[9])
		tCellCv0 = 0;
	else if(tCellNCv[8])
		tCellCv0 = 255;
	else
		tCellCv0 = tCellNCv[7:0];


	if(tCellMCy[9])
		tCellCy1 = 0;
	else if(tCellMCy[8])
		tCellCy1 = 255;
	else
		tCellCy1 = tCellMCy[7:0];

	if(tCellMCu[9])
		tCellCu1 = 0;
	else if(tCellMCu[8])
		tCellCu1 = 255;
	else
		tCellCu1 = tCellMCu[7:0];

	if(tCellMCv[9])
		tCellCv1 = 0;
	else if(tCellMCv[8])
		tCellCv1 = 255;
	else
		tCellCv1 = tCellMCv[7:0];


	tCellCy2=(tCellCy0>>1)+(tCellCy0>>2)+(tCellCy1>>2);
	tCellCu2=(tCellCu0>>1)+(tCellCu0>>2)+(tCellCu1>>2);
	tCellCv2=(tCellCv0>>1)+(tCellCv0>>2)+(tCellCv1>>2);

	tCellCy3=(tCellCy1>>1)+(tCellCy1>>2)+(tCellCy0>>2);
	tCellCu3=(tCellCu1>>1)+(tCellCu1>>2)+(tCellCu0>>2);
	tCellCv3=(tCellCv1>>1)+(tCellCv1>>2)+(tCellCv0>>2);

	if(tCellBit[1])
	begin
		if(tCellBit[0])
		begin
			tPixNextCy = tCellCy2;
			tPixNextCu = tCellCu2;
			tPixNextCv = tCellCv2;
		end
		else
		begin
			tPixNextCy = tCellCy3;
			tPixNextCu = tCellCu3;
			tPixNextCv = tCellCv3;
		end
	end
	else
	begin
		if(tCellBit[0])
		begin
			tPixNextCy = tCellCy0;
			tPixNextCu = tCellCu0;
			tPixNextCv = tCellCv0;
		end
		else
		begin
			tPixNextCy = tCellCy1;
			tPixNextCu = tCellCu1;
			tPixNextCv = tCellCv1;
		end
	end

//	tPixNextCy = 128;
//	tPixNextCu = 0;
//	tPixNextCv = 0;

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

	tPwmNextVal = 76;
//	tPwmNextVal=0;
	tVSyncNextClk = tVSyncClk;
	tVFieldNextCnt = tVFieldCnt;
	tVEqPulseNextClk = tVEqPulseClk;
	
	tPixNextPosX = 0;
	tPixNextPosY = 0;

//	tModCu=0;
//	tModCv=0;
//	tBaseCu=0;
//	tBaseCv=0;

	tModNextCu=0;
	tModNextCv=0;
	tBaseNextCu=0;
	tBaseNextCv=0;

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
//		tPwmNextVal = 76;
		tPhaseCb = tCbAcc[21:17];

//		tPhaseCu = tCbAcc[21:17]+10;
//		tPhaseCv = tCbAcc[21:17]+2;

		tPhaseCu = tCbAcc[21:17]+11;
		tPhaseCv = tCbAcc[21:17]+3;

//		tModCu[7:0] = cbPwmTab[tPhaseCu];
//		tModCv[7:0] = cbPwmTab[tPhaseCv];
//		tModCu[15:8] = tModCu[7] ? (-1) : 0;
//		tModCv[15:8] = tModCv[7] ? (-1) : 0;

//		tModCu[15:0] = {8'h00, cbPwmTab[tPhaseCu]} - 128;
//		tModCv[15:0] = {8'h00, cbPwmTab[tPhaseCv]} - 128;

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
//			tPwmNextVal = 76+cbPwmTab[tPhaseCb];
//			tPwmNextVal = 96+cbPwmTab[tPhaseCb];
			tPwmNextVal = cbPwmTab[tPhaseCb]-32;
		end
		else if((tScanPixClk>=472) && (tScanPixClk<5592))
		begin
//			tPwmNextVal = 76;

			tPixNextPosX = tScanPixClk[12:3] - 59;
			tPixNextPosY = tScanNextRowClk[9:0] - 20;

//			tBaseCy[15:8] = 0;
//			tBaseCy[7:0] = tPixCy;

//			tBaseCu = {8'h0, tPixCu} - 128;
//			tBaseCv = {8'h0, tPixCv} - 128;

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

//	tCellLastMCy	<= tCellMCy;
//	tCellLastNCy	<= tCellNCy;
//	tCellLastMCu	<= tCellMCu;
//	tCellLastNCu	<= tCellNCu;
//	tCellLastMCv	<= tCellMCv;
//	tCellLastNCv	<= tCellNCv;

	tPixCellIx		<= tPixCellNextIx;
	tPixCellFx		<= tPixCellNextFx;

	tCell1			<= tNextCell1;
	tCell2			<= tNextCell2;

	tCellMCy		<= tCellNextMCy;
	tCellNCy		<= tCellNextNCy;
	tCellMCu		<= tCellNextMCu;
	tCellNCu		<= tCellNextNCu;
	tCellMCv		<= tCellNextMCv;
	tCellNCv		<= tCellNextNCv;
	tCellBits		<= tCellNextBits;
	tCellBit		<= tCellNextBit;
	tCellUse32		<= tCellNextUse32;

	tPixCy			<= tPixNextCy;
	tPixCu			<= tPixNextCu;
	tPixCv			<= tPixNextCv;

	tBaseCy			<= tBaseNextCy;
	tBaseCu			<= tBaseNextCu;
	tBaseCv			<= tBaseNextCv;
	tModCu			<= tModNextCu;
	tModCv			<= tModNextCv;

// end

// always @ (posedge clock)
// begin

	if(tBusCSel && busWR && !busOE)
	begin
		scrCellNoRead <= 1;

		if(busAddr[15:8]==255)
		begin
			scrRegCtrl[busAddr[4:2]] <= busData;
		end
		else if(busAddr[15])
		begin
			if(busAddr[2])
				scrCell2B[busAddr[12:3]] <= busData;
			else
				scrCell2A[busAddr[12:3]] <= busData;
		end
		else
		begin
			if(busAddr[2])
				scrCell1B[busAddr[14:3]] <= busData;
			else
				scrCell1A[busAddr[14:3]] <= busData;
		end
	end
	else
	begin
		scrCellNoRead <= 0;

/*
		if(tPixCellNextIx[13])
		begin
			tNextCell1 <= scrCell2A[tPixCellNextIx[10:1]];
			tNextCell2 <= scrCell2B[tPixCellNextIx[10:1]];
		end
		else
		begin
			tNextCell1 <= scrCell1A[tPixCellNextIx[12:1]];
			tNextCell2 <= scrCell1B[tPixCellNextIx[12:1]];
		end
*/

	end

end

endmodule
