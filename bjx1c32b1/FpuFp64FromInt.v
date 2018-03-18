module FpuFp64FromInt(
	clk,
	enable,
	is32,
	src,
	dst
);

input			clk;
input			enable;
input			is32;

input[63:0]		src;
output[63:0]	dst;

reg		sgn;
reg		sgnc;

reg[12:0] exa;
reg[12:0] exb;
reg[12:0] exc;
reg[12:0] exm;

reg[63:0] tFracA;
reg[63:0] tFracB;
reg[63:0] tFracC;
reg[63:0] tFracA1;
reg[63:0] tFracB1;
reg[63:0] tFracC1;

reg[63:0] tFracC2;

reg[63:0] tFracC2_A;	//32
reg[63:0] tFracC2_B;	//16
reg[63:0] tFracC2_C;	//8
reg[63:0] tFracC2_D;	//4
reg[63:0] tFracC2_E;	//2

reg[12:0] tExc_A;
reg[12:0] tExc_B;
reg[12:0] tExc_C;
reg[12:0] tExc_D;
reg[12:0] tExc_E;

reg[63:0] tDst;

assign dst = tDst;

always @ (clk && enable)
begin
	sgnc = 0;

	if(is32)
	begin
		if(src[31])
		begin
			sgn = 1;
			tFracC2[63:32] = 0;
			tFracC2[31:0] = ~(src[31:0]);
			exm = 1023 + 52;
		end
		else
		begin
			sgn = 0;
			tFracC2[63:32] = 0;
			tFracC2[31:0] = src[31:0];
			exm = 1023 + 52;
		end
	end
	else
	begin
		if(src[63])
		begin
			sgn = 1;
			tFracC2[63:0] = ~(src[63:0]);
			exm = 1023 + 52;
		end
		else
		begin
			sgn = 0;
			tFracC2[63:0] = src[63:0];
			exm = 1023 + 52;
		end
	end

	if(tFracC2[52:0]==0)
	begin
		sgnc=0;
		tFracC=0;
		exc=0;
	end
	else
		if(tFracC2[63:52]==0)
	begin

		if(tFracC2[52:21]==0)
		begin
			tFracC2_A=tFracC2<<32;
			tExc_A=exm-32;
		end
		else
		begin
			tFracC2_A=tFracC2;
			tExc_A=exm;
		end

		if(tFracC2_A[52:37]==0)
		begin
			tFracC2_B=tFracC2_A<<16;
			tExc_B=tExc_A-16;
		end
		else
		begin
			tFracC2_B=tFracC2_A;
			tExc_B=tExc_A;
		end

		if(tFracC2_B[52:45]==0)
		begin
			tFracC2_C=tFracC2_B<<8;
			tExc_C=tExc_B-8;
		end
		else
		begin
			tFracC2_C=tFracC2_B;
			tExc_C=tExc_B;
		end
		
		if(tFracC2_C[52:49]==0)
		begin
			tFracC2_D=tFracC2_C<<4;
			tExc_D=tExc_C-4;
		end
		else
		begin
			tFracC2_D=tFracC2_C;
			tExc_D=tExc_C;
		end
		
		if(tFracC2_D[52:51]==0)
		begin
			tFracC2_E=tFracC2_D<<2;
			tExc_E=tExc_D-2;
		end
		else
		begin
			tFracC2_E=tFracC2_D;
			tExc_E=tExc_D;
		end

		if(tFracC2_E[52]==0)
		begin
			tFracC=tFracC2_E<<1;
			exc=tExc_E-1;
		end
		else
		begin
			tFracC=tFracC2_E;
			exc=tExc_E;
		end
	end
	else
	begin
		tFracC2_B=tFracC2;
		tExc_B=exm;

		if(tFracC2_B[63:60]!=0)
		begin
			tFracC2_C=tFracC2_B>>8;
			tExc_C=tExc_B+8;
		end
		else
		begin
			tFracC2_C=tFracC2_B;
			tExc_C=tExc_B;
		end
		
		if(tFracC2_C[59:56]!=0)
		begin
			tFracC2_D=tFracC2_C>>4;
			tExc_D=tExc_C+4;
		end
		else
		begin
			tFracC2_D=tFracC2_C;
			tExc_D=tExc_C;
		end
		
		if(tFracC2_D[55:54]==0)
		begin
			tFracC2_E=tFracC2_D>>2;
			tExc_E=tExc_D+2;
		end
		else
		begin
			tFracC2_E=tFracC2_D;
			tExc_E=tExc_D;
		end

		if(tFracC2_E[53])
		begin
			tFracC=tFracC2_E>>1;
			exc=tExc_E+1;
		end
		else
		begin
			tFracC=tFracC2_E;
			exc=tExc_E;
		end
	end
	
	if(exc[12])
	begin
		tDst[63:0]=64'h0;
	end
	else if(exc[11])
	begin
		tDst[63]=sgnc;
		tDst[62:0]=63'h7FF0_0000_0000_0000;
	end
	else
	begin
		tDst[63]=sgnc;
		tDst[62:52]=exc[10:0];
		tDst[51:0]=tFracC[51:0];
	end
	
//	dst=tDst;
end

always @ (posedge clk)
begin
//	dst <= tDst;
end

endmodule
