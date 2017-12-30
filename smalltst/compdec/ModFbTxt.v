/*
Extended Text Mode display model.

Has 4|8kB of display memory, organized as 32-bit cells.
* 15:0,	Char or Pixel Bits
* 29:16, Color or Effect Bits
* 31:30, Cell Mode
** 00, Text Cell, 8x8, uses Font Memory
** 01, Graphics Cell, 4x4x1

Mode 0/1:
* 21,16: ColorA
* 27,22: ColorB
** Colors: rrggbb
** 0, 85, 170, 255

Text Cell:
*  7:0, Glyph
* 11:8, Font
* 15:12, Effect
** Strike, Underline

 */

module ModFbTxt(clock, reset,
	pixPosX, pixPosY, pixCy, pixCu, pixCv,
	pixCellIx, cellData,
	fontGlyph, fontData);

/* verilator lint_off UNUSED */

input clock;
input reset;

input[9:0] pixPosX;
input[9:0] pixPosY;

output[7:0] pixCy;
output[7:0] pixCu;
output[7:0] pixCv;

output[13:0] pixCellIx;
input[31:0] cellData;

output[15:0] fontGlyph;
input[63:0] fontData;

reg[9:0]	tPixPosX;
reg[9:0]	tPixPosY;

reg[13:0]	tPixCellX;			//base cell X
reg[13:0]	tPixCellY;			//base cell Y

reg[13:0]	tPixCellIx;			//base cell index
reg[3:0]	tPixCellFx;			//base cell index

reg[13:0]	tPixCellNextIx;		//base cell index
reg[3:0]	tPixCellNextFx;		//pixel index (4x4)
reg[5:0]	tPixCellNextGx;		//glyph pix index (8x8)

reg[31:0]	tCellData;

reg[15:0]	tFontGlyph;
reg[63:0]	tFontData;

reg[5:0]	tClrA;
reg[5:0]	tClrB;
reg[8:0]	tClr9A;
reg[8:0]	tClr9B;

reg[11:0]	tClrRgbA;
reg[11:0]	tClrRgbB;

reg[11:0]	tClrYuvA;
reg[11:0]	tClrYuvB;
reg[11:0]	tClrYuvC;

reg[7:0]	tPixCy;
reg[7:0]	tPixCu;
reg[7:0]	tPixCv;

reg[11:0]	cbClrTab[63:0];

reg		useCol80;

assign	pixCellIx = tPixCellIx;
assign	fontGlyph = tFontGlyph;

assign	pixCy = tPixCy;
assign	pixCu = tPixCu;
assign	pixCv = tPixCv;

initial
begin
	cbClrTab[ 0]=12'h088;	cbClrTab[ 1]=12'h1A8;
	cbClrTab[ 2]=12'h2D8;	cbClrTab[ 3]=12'h3F8;
	cbClrTab[ 4]=12'h255;	cbClrTab[ 5]=12'h385;
	cbClrTab[ 6]=12'h5A5;	cbClrTab[ 7]=12'h6D5;
	cbClrTab[ 8]=12'h522;	cbClrTab[ 9]=12'h652;
	cbClrTab[10]=12'h782;	cbClrTab[11]=12'h9A2;
	cbClrTab[12]=12'h700;	cbClrTab[13]=12'h920;
	cbClrTab[14]=12'hA50;	cbClrTab[15]=12'hB80;
	cbClrTab[16]=12'h18A;	cbClrTab[17]=12'h2AA;
	cbClrTab[18]=12'h3DA;	cbClrTab[19]=12'h5FA;
	cbClrTab[20]=12'h358;	cbClrTab[21]=12'h588;
	cbClrTab[22]=12'h6A8;	cbClrTab[23]=12'h7D8;
	cbClrTab[24]=12'h625;	cbClrTab[25]=12'h755;
	cbClrTab[26]=12'h985;	cbClrTab[27]=12'hAA5;
	cbClrTab[28]=12'h902;	cbClrTab[29]=12'hA22;
	cbClrTab[30]=12'hB52;	cbClrTab[31]=12'hD82;
	cbClrTab[32]=12'h28D;	cbClrTab[33]=12'h3AD;
	cbClrTab[34]=12'h5DD;	cbClrTab[35]=12'h6FD;
	cbClrTab[36]=12'h55A;	cbClrTab[37]=12'h68A;
	cbClrTab[38]=12'h7AA;	cbClrTab[39]=12'h9DA;
	cbClrTab[40]=12'h728;	cbClrTab[41]=12'h958;
	cbClrTab[42]=12'hA88;	cbClrTab[43]=12'hBA8;
	cbClrTab[44]=12'hA05;	cbClrTab[45]=12'hB25;
	cbClrTab[46]=12'hD55;	cbClrTab[47]=12'hE85;
	cbClrTab[48]=12'h38F;	cbClrTab[49]=12'h5AF;
	cbClrTab[50]=12'h6DF;	cbClrTab[51]=12'h7FF;
	cbClrTab[52]=12'h65D;	cbClrTab[53]=12'h78D;
	cbClrTab[54]=12'h9AD;	cbClrTab[55]=12'hADD;
	cbClrTab[56]=12'h92A;	cbClrTab[57]=12'hA5A;
	cbClrTab[58]=12'hB8A;	cbClrTab[59]=12'hDAA;
	cbClrTab[60]=12'hB08;	cbClrTab[61]=12'hD28;
	cbClrTab[62]=12'hE58;	cbClrTab[63]=12'hF88;
end

// always @ (clock)
always @*
begin
	tPixCellX = 0;
	tPixCellY = 0;
	
//	useCol80 = 1;
	useCol80 = 0;
	tClrYuvC = 0;
	
	if(useCol80)
	begin
		tPixCellX[6:0] = tPixPosX[9:3];
		tPixCellY[6:0] = tPixPosY[9:3];
	//	tPixCellNextIx = tPixCellY*80 + tPixCellX;
		tPixCellNextIx = tPixCellY*80 + tPixCellX - 160;

		tPixCellNextFx[1:0] = 2'h2 - tPixPosX[2:1];
		tPixCellNextFx[3:2] = 2'h2 - tPixPosY[2:1];
		
		tPixCellNextGx[2:0]	= 3'h7 - tPixPosX[2:0];
		tPixCellNextGx[5:3]	= 3'h7 - tPixPosY[2:0];
	end
	else
	begin
		tPixCellX[5:0] = tPixPosX[9:4];
		tPixCellY[6:0] = tPixPosY[9:3];
		tPixCellNextIx = tPixCellY*40 + tPixCellX - 80;

		tPixCellNextFx[1:0] = 2'h3 - tPixPosX[3:2];
		tPixCellNextFx[3:2] = 2'h3 - tPixPosY[2:1];
		
		tPixCellNextGx[2:0]	= 3'h7 - tPixPosX[3:1];
		tPixCellNextGx[5:3]	= 3'h7 - tPixPosY[2:0];
	end
	
	tCellData = cellData;
	
//	tCellData = 32'h003F_0041;
//	tCellData = 32'h000C_0041;
//	tCellData[7:0]=tPixCellNextIx[7:0];

//	tCellData[17] = !tPixCellY[0];
//	tCellData[19] = !tPixCellY[1];
//	tCellData[21] = !tPixCellY[2];
//	tCellData[23] = tPixCellY[0];
//	tCellData[25] = tPixCellY[1];
//	tCellData[27] = tPixCellY[2];

	if(tPixCellIx >= 2000)
		tCellData = 0;
	if(!useCol80 && (tPixCellIx>=1000))
		tCellData = 0;

	tFontGlyph = tCellData[15:0];
	tClrA = tCellData[21:16];
	tClrB = tCellData[27:22];
	
	tClr9A = tCellData[18:10];
	tClr9B = tCellData[27:19];
	
	tClrRgbA = 0;
	tClrRgbB = 0;
	
	case(tCellData[29:28])
		2'b00: begin
			tClrRgbA[11:10]=tClrA[5:4];
			tClrRgbA[ 9: 8]=tClrA[5:4];
			tClrRgbA[ 7: 6]=tClrA[3:2];
			tClrRgbA[ 5: 4]=tClrA[3:2];
			tClrRgbA[ 3: 2]=tClrA[1:0];
			tClrRgbA[ 1: 0]=tClrA[1:0];

			tClrRgbB[11:10]=tClrB[5:4];
			tClrRgbB[ 9: 8]=tClrB[5:4];
			tClrRgbB[ 7: 6]=tClrB[3:2];
			tClrRgbB[ 5: 4]=tClrB[3:2];
			tClrRgbB[ 3: 2]=tClrB[1:0];
			tClrRgbB[ 1: 0]=tClrB[1:0];
		end

		2'b10: begin
			tClrRgbA[11: 9]=tClr9A[8:6];
			tClrRgbA[ 7: 5]=tClr9A[5:3];
			tClrRgbA[ 3: 1]=tClr9A[2:0];

			tClrRgbB[11: 9]=tClr9B[8:6];
			tClrRgbB[ 7: 5]=tClr9B[5:3];
			tClrRgbB[ 3: 1]=tClr9B[2:0];
		end
		
		default: begin end
	endcase
	
	tClrYuvA[11:8]=
		{1'b0, tClrRgbA[ 7: 5]}+
		{2'b0, tClrRgbA[11:10]}+
		{2'b0, tClrRgbA[ 3: 2]};
	tClrYuvB[11:8]=
		{1'b0, tClrRgbB[ 7: 5]}+
		{2'b0, tClrRgbB[11:10]}+
		{2'b0, tClrRgbB[ 3: 2]};
	tClrYuvA[7:4]=4'h8+(tClrRgbA[ 3: 1]-tClrRgbA[ 7: 5]);
	tClrYuvB[7:4]=4'h8+(tClrRgbB[ 3: 1]-tClrRgbB[ 7: 5]);
	tClrYuvA[3:0]=4'h8+(tClrRgbA[11: 9]-tClrRgbA[ 7: 5]);
	tClrYuvB[3:0]=4'h8+(tClrRgbB[11: 9]-tClrRgbB[ 7: 5]);
	
//	tClrYuvA = cbClrTab[tClrA];
//	tClrYuvB = cbClrTab[tClrB];
	tFontData = fontData;

//	tFontData = 64'h0010_3844_7C44_4400;
//	tClrYuvA = 12'hF88;

	if(cellData[31:30]==2'b00)
		tClrYuvC = (tFontData[tPixCellNextGx]) ? tClrYuvA : tClrYuvB;
	else if(cellData[31:30]==2'b01)
		tClrYuvC = (tFontGlyph[tPixCellNextFx]) ? tClrYuvA : tClrYuvB;
	
	tPixCy[7:4] = tClrYuvC[11:8];	tPixCy[3:0] = tClrYuvC[11:8];
	tPixCu[7:4] = tClrYuvC[7:4];	tPixCu[3:0] = tClrYuvC[7:4];
	tPixCv[7:4] = tClrYuvC[3:0];	tPixCv[3:0] = tClrYuvC[3:0];
	
//	tPixCy=128;
//	tPixCu=255;
//	tPixCv=255;
end


always @ (posedge clock)
begin

	tPixPosX		<= pixPosX;
	tPixPosY		<= pixPosY;

	tPixCellIx		<= tPixCellNextIx;
	tPixCellFx		<= tPixCellNextFx;

end

endmodule
