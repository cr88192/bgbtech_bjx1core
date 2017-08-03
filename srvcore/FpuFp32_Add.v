module FpuFp32_Add(
	/* verilator lint_off UNUSED */
	clk,
	doSub,
	srca,
	srcb,
	dst
);

input			clk;
input			doSub;
input[31:0]		srca;
input[31:0]		srcb;
output[31:0]	dst;

reg sgna;
reg sgnb;
reg sgnc;

reg[9:0] exa;
reg[9:0] exb;
reg[9:0] exc;
reg[9:0] exm;

reg[31:0] tFracA;
reg[31:0] tFracB;
reg[31:0] tFracC;
// reg[22:0] tFracC;
reg[31:0] tFracA1;
reg[31:0] tFracB1;
reg[31:0] tFracC1;

// reg[31:0] tFracA2;
// reg[31:0] tFracB2;
reg[31:0] tFracC2;

reg[31:0] tFracC2_A;	//16
reg[31:0] tFracC2_B;	//8
reg[31:0] tFracC2_C;	//4
reg[31:0] tFracC2_D;	//2

reg[9:0] tExc_A;
reg[9:0] tExc_B;
reg[9:0] tExc_C;
reg[9:0] tExc_D;

always @ (clk) begin
	sgna=srca[31];
	sgnb=srcb[31];

	exa[7:0]=srca[30:23];
	exb[7:0]=srcb[30:23];
	exa[9:8]=0;
	exb[9:8]=0;

	exm=(exa>=exb)?exa:exb;

	if(sgna)
	begin
		tFracA[31:23]=~(9'h1);
		tFracA[22:0]=~(srca[22:0]);
	end
	else
	begin
		tFracA[31:23]=9'h1;
		tFracA[22:0]=srca[22:0];
	end

	if(sgnb^doSub)
	begin
		tFracB[31:23]=~(9'h1);
		tFracB[22:0]=~(srcb[22:0]);
	end
	else
	begin
		tFracB[31:23]=9'h1;
		tFracB[22:0]=srcb[22:0];
	end

	tFracA1=tFracA>>>(exm-exa);
	tFracB1=tFracB>>>(exm-exb);
	tFracC1=tFracA1+tFracB1;
	
	if(tFracC1[31])
	begin
		sgnc=1;
		tFracC2=~tFracC1;
	end
	else
	begin
		sgnc=0;
		tFracC2=tFracC1;
	end
	
	if(tFracC2[23:0]==0)
	begin
		sgnc=0;
		tFracC=0;
		exc=0;
	end
	else
		if(tFracC2[24:23]==0)
	begin
		if(tFracC2[23:8]==0)
		begin
			tFracC2_A=tFracC2<<16;
			tExc_A=exm-16;
		end
		else
		begin
			tFracC2_A=tFracC2;
			tExc_A=exm;
		end

		if(tFracC2_A[23:16]==0)
		begin
			tFracC2_B=tFracC2_A<<8;
			tExc_B=tExc_A-8;
		end
		else
		begin
			tFracC2_B=tFracC2_A;
			tExc_B=tExc_A;
		end
		
		if(tFracC2_B[23:20]==0)
		begin
			tFracC2_C=tFracC2_B<<4;
			tExc_C=tExc_B-4;
		end
		else
		begin
			tFracC2_C=tFracC2_B;
			tExc_C=tExc_B;
		end
		
		if(tFracC2_C[23:22]==0)
		begin
			tFracC2_D=tFracC2_C<<2;
			tExc_D=tExc_C-2;
		end
		else
		begin
			tFracC2_D=tFracC2_C;
			tExc_D=tExc_C;
		end

		if(tFracC2_D[23]==0)
		begin
			tFracC=tFracC2_D<<1;
			exc=tExc_D-1;
		end
		else
		begin
			tFracC=tFracC2_D;
			exc=tExc_D;
		end
	end
	else
	begin
		if(tFracC2[24])
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
	
	if(exc[9])
	begin
		dst[31:0]=32'h0;
	end
	else if(exc[8])
	begin
		dst[31]=sgnc;
		dst[30:0]=31'h7F80_0000;
	end
	else
	begin
		dst[31]=sgnc;
		dst[30:23]=exc[7:0];
		dst[22:0]=tFracC[22:0];
	end
end

endmodule
