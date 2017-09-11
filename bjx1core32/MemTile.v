module MemTile(
	clk,
	opRd,
	opWr,
	opMode,
	memAddr,
	rdValue,
	wrValue
	);

input clk;			//clock
input opRd;			//read value
input opWr;			//write value
input[2:0] opMode;
input[47:0] memAddr;
input[63:0] wrValue;

output[63:0] rdValue;

reg[11:0] tileIdx;
reg[31:0] tile[4096];

// reg[47:0] rdAddr;
// reg[63:0] rdValue;

// reg[47:0] wrAddr;
// reg[63:0] wrValue;

reg[63:0] rdtTBlock;
reg[63:0] rdtValue;
reg[63:0] rdtValue2;
reg[63:0] rdtTBlock2;

reg[63:0] rdtMask;
reg[63:0] rdtMask2;
reg[4:0] rdtShl;

parameter[2:0]  MD_NONE  = 3'b000;
parameter[2:0]  MD_BYTE  = 3'b001;
parameter[2:0]  MD_WORD  = 3'b010;
parameter[2:0]  MD_DWORD = 3'b011;
parameter[2:0]  MD_QWORD = 3'b100;
parameter[2:0]  MD_OWORD = 3'b101;
parameter[2:0]  MD_UBYTE = 3'b110;
parameter[2:0]  MD_UWORD = 3'b111;

always @ (opRd or opWr)
begin
	tileIdx = memAddr[13:2];
	rdtShl[4:3]=memAddr[1:0];
	rdtShl[2:0]=3'b000;
end

always @ (opRd)
begin
	if(opRd)
	begin
//		rdtValue=tile[tileIdx]>>rdtShl;

		rdtTBlock[31: 0]=tile[tileIdx  ];
		rdtTBlock[63:32]=tile[tileIdx+1];
		rdtValue=rdtTBlock>>rdtShl;

		case(opMode)
			MD_BYTE:
			begin
				rdValue[7:0]=rdtValue[7:0];
				rdValue[63:8]=rdtValue[7]?
					56'hFFFF_FFFF_FFFF_FF :
					56'h0000_0000_0000_00 ;
			end

			MD_WORD:
			begin
				rdValue[15:0]=rdtValue[15:0];
				rdValue[63:16]=rdtValue[15]?
					48'hFFFF_FFFF_FFFF :
					48'h0000_0000_0000 ;
			end

			MD_DWORD:
			begin
				rdValue[31:0]=rdtValue[31:0];
				rdValue[63:32]=rdtValue[31]?
					32'hFFFF_FFFF :
					32'h0000_0000 ;
			end

			MD_QWORD:
			begin
				rdValue=rdtValue;
			end

			MD_UBYTE:
			begin
				rdValue[7:0]=rdtValue[7:0];
				rdValue[63:8]=56'h0000_0000_0000_00 ;
			end

			MD_UWORD:
			begin
				rdValue[15:0]=rdtValue[15:0];
				rdValue[63:16]=48'h0000_0000_0000 ;
			end

			default:
			begin
				rdValue=rdtValue;
			end

		endcase
	end
end

always @ (opWr)
begin
	if(opWr)
	begin
		case(opMode)
			MD_BYTE:
			begin
				rdtValue2[7:0]=wrValue[7:0];
				rdtValue2[63:8]=56'h0000_0000_0000_00 ;
				rdtMask2=64'h0000_0000_0000_00FF ;
			end

			MD_WORD:
			begin
				rdtValue2[15:0]=wrValue[15:0];
				rdtValue2[63:16]=48'h0000_0000_0000 ;
				rdtMask2=64'h0000_0000_0000_FFFF ;
			end

			MD_DWORD:
			begin
				rdtValue2[31:0]=wrValue[31:0];
				rdtValue2[63:32]=32'h0000_0000 ;
				rdtMask2=64'h0000_0000_FFFF_FFFF ;
			end

			MD_QWORD:
			begin
				rdtValue2[63:0]=wrValue[63:0];
				rdtMask2=64'hFFFF_FFFF_FFFF_FFFF ;
			end

			default:
			begin
				rdtValue2=64'h0000_0000_0000_0000 ;
				rdtMask2=64'h0000_0000_0000_0000 ;
			end
		endcase

		rdtValue=rdtValue2<<rdtShl;
		rdtMask=rdtMask2<<rdtShl;

		rdtTBlock[31: 0]=tile[tileIdx  ];
		rdtTBlock[63:32]=tile[tileIdx+1];
		rdtTBlock2=(rdtTBlock&(~rdtMask))|rdtValue;
		tile[tileIdx  ]=rdtTBlock[31: 0];
		tile[tileIdx+1]=rdtTBlock[63:32];
	end
end

always @ (posedge clk)
begin
end

endmodule