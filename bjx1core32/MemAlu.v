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
input[31:0] baseAddr;
input[31:0] idxAddr;
input[31:0] idxDisp;

output[31:0] outAddr;

reg[31:0] tIdxAddr;
reg[31:0] tOutAddr;

parameter[2:0]  MD_NONE  = 3'b000;
parameter[2:0]  MD_BYTE  = 3'b001;
parameter[2:0]  MD_WORD  = 3'b010;
parameter[2:0]  MD_DWORD = 3'b011;
parameter[2:0]  MD_QWORD = 3'b100;
parameter[2:0]  MD_OWORD = 3'b101;

parameter[2:0]  MD_MOV   = 3'b111;

parameter[31:0] NULL_ADDR = 32'h0000_0000;
parameter[31:0] NEG_ADDR = 32'h0000_0000;

always @ (mode) begin
	tIdxAddr = idxAddr+idxDisp;

	case(mode)
		MD_BYTE: begin
			tOutAddr = baseAddr+tIdxAddr;
		end
		MD_WORD: begin
			tOutAddr = baseAddr+tIdxAddr*2;
		end
		MD_DWORD: begin
			tOutAddr = baseAddr+tIdxAddr*4;
		end
		MD_QWORD: begin
			tOutAddr = baseAddr+tIdxAddr*8;
		end
		MD_OWORD: begin
			tOutAddr = baseAddr+tIdxAddr*16;
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

endmodule
