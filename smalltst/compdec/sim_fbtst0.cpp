#include <stdio.h>
#include <stdlib.h>

#include "VFbNtMod.h"
#include "verilated.h"

VFbNtMod *top = new VFbNtMod;

vluint64_t main_time = 0;

int main(int argc, char **argv, char **env)
{
	FILE *ofd;
	uint32_t *obuf;
	uint32_t *imgbuf;
	int bpos, bplim;
	int imgba;
	int y, x;
	int cy, dy, cu, cv;
	int pcy, pdy, pcu, pcv;
	int i, j, k;
	
	Verilated::commandArgs(argc, argv);

	obuf=(uint32_t *)malloc(1<<22);
	memset(obuf, 0, 1<<22);
	bpos=0;
	bplim=(1<<22)*8;

	imgbuf=(uint32_t *)malloc(8192*4);
	imgba=0;

	for(y=0; y<50; y++)
		for(x=0; x<80; x++)
	{
		pcy=128;
		pdy=64;
		pcu=((x^y)&1)?192:64;
		pcv=!((x^y)&1)?192:64;
	
		pcy=cy>>4; pdy=dy>>4; pcu=cu>>5; pcv=cv>>5;
		k=0xC0005A5A|(pcy<<26)|(pdy<<22)|(pcu<<19)|(pcv<<16);
		
		j=y*80+x;
		imgbuf[j]=k;
	}

	while (!Verilated::gotFinish())
	{
		top->clock = (main_time>>3)&1;
//		top->mode = 3;
		
//		top->baseAddr=0xDECAB00;
//		top->idxAddr=0x100;
//		top->idxDisp=3;

		top->busAddr=0x00A0A0000000LL+(imgba*4);
		top->busData=imgbuf[imgba];
		top->busWR=1;

		top->eval();

		main_time++;

		if(!(main_time&15))
		{
			if(top->pwmOut)
				obuf[bpos>>5]|=(1<<(bpos&31));
			bpos++;
			
			imgba=(imgba+1)&8191;
		}
		
		if(bpos>=bplim)
		{
			break;
		}
	}
	
	ofd=fopen("sim_fbtst0_pwm.dat", "wb");
	fwrite(obuf, 1, bpos/8, ofd);
	fclose(ofd);
	
	delete top;
	exit(0);
}

// verilator -Wall --cc our.v --exe sim_main.cpp
