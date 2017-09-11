/*
Map input Virtual Address to output address.
VA's are 48-bit (high 16 bits unused).
Output ("hardware") address space is 40 bits.

80xx_xxxx_xxxx maps exactly from input->output.

Input and Output is 64 bits mostly to facilitate get/set registers.

Page size is 12 bits.
 */

parameter[2:0] TLB_OPMODE_NONE		= 3'h00;	//do nothing
parameter[2:0] TLB_OPMODE_LOOKUP	= 3'h01;	//lookup memory address
parameter[2:0] TLB_OPMODE_GETREG	= 3'h02;	//get MMU register
parameter[2:0] TLB_OPMODE_SETREG	= 3'h03;	//set MMU register
parameter[2:0] TLB_OPMODE_LDTLB		= 3'h04;	//load TLB entry

module MemTLB(
	/* verilator lint_off UNUSED */
	clk,
	reset,
	opMode,
	opReg,
	inAddr,
	outAddr,
	outTlbSr
);

input clk;
input reset;
input[2:0] opMode;
input[2:0] opReg;
input[63:0] inAddr;
output[63:0] outAddr;
output[7:0] outTlbSr;

reg[63:0]	tOutAddr;
reg[7:0]	tHashIdx0;
reg[5:0]	tHashIdx;

reg[35:0]	tlbPageSrcA[63:0];		//source addresses 
reg[35:0]	tlbPageSrcB[63:0];
reg[35:0]	tlbPageSrcC[63:0];
reg[35:0]	tlbPageSrcD[63:0];

reg[27:0]	tlbPageDstA[63:0];		//dest addresses 
reg[27:0]	tlbPageDstB[63:0];
reg[27:0]	tlbPageDstC[63:0];
reg[27:0]	tlbPageDstD[63:0];

reg[63:0]	regPTEH;
reg[63:0]	regPTEL;
reg[63:0]	regTTB;
reg[63:0]	regTEA;
reg[63:0]	regMMUCR;

reg[63:0]	regNextPTEH;
reg[63:0]	regNextPTEL;
reg[63:0]	regNextTTB;
reg[63:0]	regNextTEA;
reg[63:0]	regNextMMUCR;

reg[7:0] tTlbSr;
reg tlbMiss;
reg[2:0] tlbSwap;

reg[35:0]	tlbSwapSrcA;		//source addresses 
reg[35:0]	tlbSwapSrcB;
reg[35:0]	tlbSwapSrcC;
reg[35:0]	tlbSwapSrcD;

reg[27:0]	tlbSwapDstA;		//dest addresses 
reg[27:0]	tlbSwapDstB;
reg[27:0]	tlbSwapDstC;
reg[27:0]	tlbSwapDstD;

reg[35:0]	tlbSwapSrcE;
reg[27:0]	tlbSwapDstE;

assign outAddr = tOutAddr;
assign outTlbSr = tTlbSr;


always @ (opMode)
begin
	tlbMiss = 0;
	tlbSwap = 0;
	tTlbSr = 0;

	regNextPTEH  = regPTEH;
	regNextPTEL  = regPTEL;
	regNextTTB   = regTTB;
	regNextTEA   = regTEA;
	regNextMMUCR = regMMUCR;

	if(opMode==TLB_OPMODE_NONE)
	begin
		tlbMiss = 0;
	end
	else
	if(opMode==TLB_OPMODE_LOOKUP)
	begin
		tHashIdx0=
			inAddr[19:12]+inAddr[26:19]+
			inAddr[33:26]+inAddr[40:33]+
			inAddr[47:40]+3;
		tHashIdx=tHashIdx0[7:2];
		tlbMiss = 1;


		tlbSwapSrcA=tlbPageSrcA[tHashIdx];
		tlbSwapDstA=tlbPageDstA[tHashIdx];
		tlbSwapSrcB=tlbPageSrcB[tHashIdx];
		tlbSwapDstB=tlbPageDstB[tHashIdx];
		tlbSwapSrcC=tlbPageSrcC[tHashIdx];
		tlbSwapDstC=tlbPageDstC[tHashIdx];
		tlbSwapSrcD=tlbPageSrcD[tHashIdx];
		tlbSwapDstD=tlbPageDstD[tHashIdx];

		if((inAddr[47:40]==8'h80) ||
			(regMMUCR[0]==0) ||
			(inAddr[61]!=inAddr[63]))
		begin
			tOutAddr[63:40] = 0;
			tOutAddr[39: 0] = inAddr[39:0];
			tlbMiss = 0;
		end
		else
		begin
			if(inAddr[47:12]==tlbSwapSrcA[35: 0])
			begin
				tOutAddr[63:40] = 0;
				tOutAddr[39:12] = tlbSwapDstA[27: 0];
				tOutAddr[11: 0] = inAddr     [11: 0];
				tlbMiss = 0;
				tlbSwap = 0;
			end
			else if(inAddr[47:12]==tlbSwapSrcB[35: 0])
			begin
				tOutAddr[63:40] = 0;
				tOutAddr[39:12] = tlbSwapDstB[27: 0];
				tOutAddr[11: 0] = inAddr     [11: 0];
				tlbMiss = 0;
				tlbSwap = 1;
			end
			else if(inAddr[47:12]==tlbSwapSrcC[35: 0])
			begin
				tOutAddr[63:40] = 0;
				tOutAddr[39:12] = tlbSwapDstC[27: 0];
				tOutAddr[11: 0] = inAddr     [11: 0];
				tlbMiss = 0;
				tlbSwap = 2;
			end
			else if(inAddr[47:12]==tlbSwapSrcD[35: 0])
			begin
				tOutAddr[63:40] = 0;
				tOutAddr[39:12] = tlbSwapDstD[27: 0];
				tOutAddr[11: 0] = inAddr     [11: 0];
				tlbMiss = 0;
				tlbSwap = 3;
			end
		end
	end
	else
	if(opMode==TLB_OPMODE_GETREG)
	begin
		case(opReg)

		3'h0:
		begin
			tOutAddr = 0;
			tlbMiss = 0;
		end

		3'h1:
		begin
			tOutAddr = regPTEH;
			tlbMiss = 0;
		end

		3'h2:
		begin
			tOutAddr = regPTEL;
			tlbMiss = 0;
		end

		3'h3:
		begin
			tOutAddr = regTTB;
			tlbMiss = 0;
		end

		3'h4:
		begin
			tOutAddr = regTEA;
			tlbMiss = 0;
		end

		3'h5:
		begin
			tOutAddr = regMMUCR;
			tlbMiss = 0;
		end

		default:
		begin
			tOutAddr = 0;
			tlbMiss = 1;
		end
		endcase
	end
	else
	if(opMode==TLB_OPMODE_SETREG)
	begin
		case(opReg)

		3'h0:
		begin
			tOutAddr = 0;
			tlbMiss = 0;
		end

		3'h1:
		begin
			regNextPTEH = inAddr;
			tOutAddr = 0;
			tlbMiss = 0;
		end

		3'h2:
		begin
			regNextPTEL = inAddr;
			tOutAddr = 0;
			tlbMiss = 0;
		end

		3'h3:
		begin
			regNextTTB = inAddr;
			tOutAddr = 0;
			tlbMiss = 0;
		end

		3'h4:
		begin
			regNextTEA = inAddr;
			tOutAddr = 0;
			tlbMiss = 0;
		end

		3'h5:
		begin
			regNextMMUCR = inAddr;
			tOutAddr = 0;
			tlbMiss = 0;
		end

		default:
		begin
			tOutAddr = 0;
			tlbMiss = 1;
		end
		endcase
	end
	else
	if(opMode==TLB_OPMODE_LDTLB)
	begin
		tHashIdx0=
			regPTEH[19:12]+regPTEH[26:19]+
			regPTEH[33:26]+regPTEH[40:33]+
			regPTEH[47:40]+3;
		tHashIdx=tHashIdx0[7:2];
		
		tlbSwapSrcE[35:0] = regPTEH[47:12];
		tlbSwapDstE[27:0] = regPTEL[39:12];
		tlbSwap = 4;
	end
	
	tTlbSr[0] = tlbMiss;
end

always @ (posedge clk)
begin
	regPTEH  <= regNextPTEH;
	regPTEL  <= regNextPTEL;
	regTTB   <= regNextTTB;
	regTEA   <= regNextTEA;
	regMMUCR <= regNextMMUCR;
	
	case(tlbSwap)
	0: begin end
	1: begin
		tlbPageSrcA[tHashIdx] <= tlbSwapSrcB;
		tlbPageDstA[tHashIdx] <= tlbSwapDstB;
		tlbPageSrcB[tHashIdx] <= tlbSwapSrcA;
		tlbPageDstB[tHashIdx] <= tlbSwapDstA;
		end
	2: begin
		tlbPageSrcB[tHashIdx] <= tlbSwapSrcC;
		tlbPageDstB[tHashIdx] <= tlbSwapDstC;
		tlbPageSrcC[tHashIdx] <= tlbSwapSrcB;
		tlbPageDstC[tHashIdx] <= tlbSwapDstB;
		end
	3: begin
		tlbPageSrcC[tHashIdx] <= tlbSwapSrcD;
		tlbPageDstC[tHashIdx] <= tlbSwapDstD;
		tlbPageSrcD[tHashIdx] <= tlbSwapSrcC;
		tlbPageDstD[tHashIdx] <= tlbSwapDstC;
		end
	4: begin
		tlbPageSrcD[tHashIdx] <= tlbSwapSrcE;
		tlbPageDstD[tHashIdx] <= tlbSwapDstE;
		end
	default: begin end
	endcase
end

endmodule
