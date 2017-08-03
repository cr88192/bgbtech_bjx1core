module MemAlu(
	/* verilator lint_off UNUSED */
	clk,
	mode,
	baseAddr,
	idxAddr,
	idxDisp,
	outAddr
);

input clk;
input[2:0] mode;
input[63:0] baseAddr;
input[31:0] idxAddr;
input[31:0] idxDisp;

output[63:0] outAddr;

reg[31:0] tIdxAddr;
reg[63:0] tIdxAddr2;
reg[63:0] tOutAddr;

parameter[2:0]  MD_NONE  = 3'b000;
parameter[2:0]  MD_BYTE  = 3'b001;
parameter[2:0]  MD_WORD  = 3'b010;
parameter[2:0]  MD_DWORD = 3'b011;
parameter[2:0]  MD_QWORD = 3'b100;
parameter[2:0]  MD_OWORD = 3'b101;

parameter[2:0]  MD_MOV   = 3'b111;

parameter[63:0] NULL_ADDR = 64'h0000_0000_0000_0000;
parameter[63:0] NEG_ADDR = 64'hFFFF_FFFF_0000_0000;

always @ (mode) begin
	tIdxAddr = idxAddr+idxDisp;
//	tIdxAddr2 = tIdxAddr[31] ?
//		(tIdxAddr|NEG_ADDR) :
//		(tIdxAddr|NULL_ADDR);
	tIdxAddr2[31:0] = tIdxAddr;
	tIdxAddr2[63:32] = tIdxAddr[31] ?
		32'hFFFF_FFFF :
		32'h0000_0000 ;

	case(mode)
		MD_BYTE: begin
			tOutAddr = baseAddr+tIdxAddr2;
		end
		MD_WORD: begin
			tOutAddr = baseAddr+tIdxAddr2*2;
		end
		MD_DWORD: begin
			tOutAddr = baseAddr+tIdxAddr2*4;
		end
		MD_QWORD: begin
			tOutAddr = baseAddr+tIdxAddr2*8;
		end
		MD_OWORD: begin
			tOutAddr = baseAddr+tIdxAddr2*16;
		end

		MD_MOV: begin
			tOutAddr = baseAddr;
		end

		default: begin
			tOutAddr = NULL_ADDR;
		end
	endcase
	outAddr = tOutAddr;
end

//always @ (posedge clk) begin
//	outAddr <= tOutAddr;
//end

endmodule
