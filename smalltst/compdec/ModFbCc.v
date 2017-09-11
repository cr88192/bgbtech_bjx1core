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

module ModFbCc(clock, reset,
	pixPosX, pixPosY, pixCy, pixCu, pixCv,
	pixCellIx, cellData1, cellData2);

//	busAddr, busData, busOE, busWR, busHold);

/* verilator lint_off UNUSED */

input clock;
input reset;

input[9:0] pixPosX;
input[9:0] pixPosY;

output[7:0] pixCy;
output[7:0] pixCu;
output[7:0] pixCv;

output[13:0] pixCellIx;
input[31:0] cellData1;
input[31:0] cellData2;


reg[9:0]	tPixPosX;
reg[9:0]	tPixPosY;

reg[7:0]	tPixCy;
reg[7:0]	tPixCu;
reg[7:0]	tPixCv;

reg[7:0]	tPixNextCy;
reg[7:0]	tPixNextCu;
reg[7:0]	tPixNextCv;

reg[13:0]	tPixCellX;			//base cell X
reg[13:0]	tPixCellY;			//base cell Y

reg[13:0]	tPixCellIx;			//base cell index
reg[3:0]	tPixCellFx;			//base cell index

reg[13:0]	tPixCellNextIx;		//base cell index
reg[3:0]	tPixCellNextFx;		//base cell index

reg			scrIs320;			//use 320x240 (vs 640x240)
reg			scrIsCell64;		//cells are 64-bit

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

assign pixCellIx = tPixCellIx;

assign pixCy = tPixCy;
assign pixCu = tPixCu;
assign pixCv = tPixCv;

always @ (clock)
begin
	
	scrIs320 = 1;
	scrIsCell64 = 0;
//	scrIs320 = scrCell2[2047][0];
//	scrIs320 = scrCell2[11'h7C0][0];

	tCellCy=0;
	tCellDy=0;
	tCellCu=0;
	tCellCv=0;
	
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
		if(scrIsCell64)
			tPixCellNextIx = tPixCellY*160 + tPixCellX*2;
		else	
			tPixCellNextIx = tPixCellY*80 + tPixCellX;
	end
	else
	begin
		tPixCellX[7:0] = tPixPosX[9:2];
		tPixCellY[6:0] = tPixPosY[8:2];

		tPixCellNextFx[1:0] = tPixPosX[1:0];
		tPixCellNextFx[3:2] = tPixPosY[1:0];
		tPixCellNextIx = tPixCellY*160 + tPixCellX;
	end

//	if(scrIs320)
	if(scrIsCell64)
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

always @ (posedge clock)
begin

	tPixPosX		<= pixPosX;
	tPixPosY		<= pixPosY;

	tPixCellIx		<= tPixCellNextIx;
	tPixCellFx		<= tPixCellNextFx;

	tCell1			<= cellData1;
	tCell2			<= cellData2;

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

end

endmodule
