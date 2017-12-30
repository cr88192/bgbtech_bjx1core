#include <stdio.h>
#include <stdlib.h>

#include "VFbNtMod.h"
#include "verilated.h"

#define CONGFXB_NOMAIN
#include "congfxbe.c"


VFbNtMod *top = new VFbNtMod;

vluint64_t main_time = 0;

int main(int argc, char **argv, char **env)
{
	FILE *ofd;

	byte *ibuf, *dbuf;
	char *ifn, *ofn;
	u64 dste, blk64;
	u32 blk;

	uint32_t *obuf;
	uint32_t *imgbuf;
	int bpos, bplim;
	int imgba;
	int xs, ys, cxs, cys, ystr;
	int y, x;
	int cy, dy, cu, cv;
	int pcy, pdy, pcu, pcv;
	int i, j, k;
	
	Verilated::commandArgs(argc, argv);

	
	ifn=NULL;
	ofn=NULL;

	for(i=1; i<argc; i++)
	{
		if(argv[i][0]=='-')
		{
			continue;
		}
		if(!ifn)
			{ ifn=argv[i]; continue; }
		if(!ofn)
			{ ofn=argv[i]; continue; }
	}

	obuf=(uint32_t *)malloc(1<<23);
	memset(obuf, 0, 1<<23);
	bpos=8;
//	bplim=(1<<22)*8;
	bplim=(1<<23)*2;
	obuf[0]=0x55AA4100;

	imgbuf=(uint32_t *)malloc(16384*4);
	imgba=0;

	ibuf=BTIC1H_Img_LoadTGA(ifn, &xs, &ys);

	dbuf=(byte *)malloc(xs*ys*4);

	dste=0;

	if(xs==320)
	{
		cxs=xs/4;
		cys=ys/4;
		ystr=xs*4;

		for(y=0; y<60; y++)
	//		for(x=0; x<80; x++)
			for(x=0; x<80; x++)
		{
			k=((((cys-y-1)*4)*xs)+(x*4))*4;
			dste=0;
			if(0)
			{
				vqenc64(ibuf+k, ystr, &blk64, &dste);
				j=y*160+(x*2);
				imgbuf[j+0]=blk64>>32;
				imgbuf[j+1]=blk64;
			}
			else
			{
				vqenc(ibuf+k, ystr, &blk, &dste);
				j=y*80+x;
				imgbuf[j]=blk;
			}
		}

//		imgbuf[8192+2047]=1;
		imgbuf[0x9F00/4]=1;
	}

	if(xs==640)
	{
		cxs=xs/4;
		cys=ys/8;
		ystr=xs*8;

		for(y=0; y<60; y++)
	//		for(x=0; x<80; x++)
			for(x=0; x<160; x++)
		{
			k=((((cys-y-1)*8)*xs)+(x*4))*4;
			dste=0;
			vqenc(ibuf+k, ystr, &blk, &dste);
//			vqenc(ibuf+k, ystr, &blk, NULL);

			j=y*160+x;
			imgbuf[j]=blk;
		}
//		imgbuf[8192+2047]=0;
		imgbuf[0x9F00/4]=0;
	}

	while (!Verilated::gotFinish())
	{
		top->clock = (main_time>>3)&1;
//		top->mode = 3;
		
//		top->baseAddr=0xDECAB00;
//		top->idxAddr=0x100;
//		top->idxDisp=3;

//		if(imgba<(8192+2048))
		if(imgba<(4096+1024))
		{
			top->busAddr=0x00A0A0000000LL+(imgba*4);
			top->busData=imgbuf[imgba];
			top->busWR=1;
		}else
		{
			top->busWR=0;
		}

		top->eval();

		main_time++;

		if(!(main_time&15))
		{
//			if(top->pwmOut)
//				obuf[bpos>>5]|=(1<<(bpos&31));

			j=top->pwmOut&15;
			obuf[bpos>>3]|=(j<<((bpos&7)*4));

			bpos++;
			
//			imgba=(imgba+1)&8191;
//			if(imgba<(8192+2048))
			if(imgba<(4096+1024))
				imgba=(imgba+1)&16383;
//			if(imgba>=(8192+2048))
//				imgba=0;
		}
		
		if(bpos>=bplim)
		{
			break;
		}
	}
	
	ofd=fopen("sim_fbtst0_pwm.dat", "wb");
//	fwrite(obuf, 1, bpos/8, ofd);
	fwrite(obuf, 1, (bpos/8)*4, ofd);
	fclose(ofd);
	
	delete top;
	exit(0);
}

// verilator -Wall --cc our.v --exe sim_main.cpp
