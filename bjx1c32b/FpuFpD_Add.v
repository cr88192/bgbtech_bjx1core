module FpuFpD_Add(
	/* verilator lint_off UNUSED */
	clk,
	enable,
	doSub,
	srca,
	srcb,
	dst
);

input			clk;
input			enable;
input			doSub;
input[63:0]		srca;
input[63:0]		srcb;
output[63:0]	dst;

reg sgna;
reg sgnb;
reg sgnc;

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

reg[63:0]		tDst;

assign dst = tDst;


always @ (clk && enable)
begin
	sgna=srca[63];
	sgnb=srcb[63];

	exa[10:0]=srca[62:52];
	exb[10:0]=srcb[62:52];
	exa[12:11]=0;
	exb[12:11]=0;

	exm=(exa>=exb)?exa:exb;

	if(sgna)
	begin
		tFracA[63:52]=~(12'h1);
		tFracA[51:0]=~(srca[51:0]);
	end
	else
	begin
		tFracA[63:52]=12'h1;
		tFracA[51:0]=srca[51:0];
	end

	if(sgnb^doSub)
	begin
		tFracB[63:52]=~(12'h1);
		tFracB[51:0]=~(srcb[51:0]);
	end
	else
	begin
		tFracB[63:52]=12'h1;
		tFracB[51:0]=srcb[51:0];
	end

	tFracA1=tFracA>>>(exm-exa);
	tFracB1=tFracB>>>(exm-exb);
	tFracC1=tFracA1+tFracB1;
	
	if(tFracC1[63])
	begin
		sgnc=1;
		tFracC2=~tFracC1;
	end
	else
	begin
		sgnc=0;
		tFracC2=tFracC1;
	end
	
	if(tFracC2[52:0]==0)
	begin
		sgnc=0;
		tFracC=0;
		exc=0;
	end
	else
		if(tFracC2[53:52]==0)
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
		if(tFracC2[53])
		begin
			tFracC=tFracC2>>1;
			exc=exm+1;
		end
		else
		begin
			tFracC=tFracC2;
			exc=exm;
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
end

endmodule
