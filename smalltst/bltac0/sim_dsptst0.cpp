#include <stdio.h>
#include <stdlib.h>

#include "VBltDspMod.h"
#include "verilated.h"

#define CONGFXB_NOMAIN
#include "bltac1as.c"


VBltDspMod *top = new VBltDspMod;

vluint64_t main_time = 0;

int main(int argc, char **argv, char **env)
{
	FILE *ofd;

	char *ifn, *ofn;
	u64 dste, blk64;
	u32 blk;
	int bpos, bplim;
	int imgba;
	int xs, ys, cxs, cys, ystr;
	int y, x, z, irq;
	int lcy, ldy, lcu, lcv;
	int cy, dy, cu, cv;
	int pcy, pdy, pcu, pcv;

	char tb[256];
	int btcnt[64];
	int l4cnt[8];
	s16 *ibuf;
	s16 *obuf;
	u64 *bbuf;

	u32 *bsbufl;
	u32 *bsbufr;

	byte *hibuf;
	double e, ts0, ts1;
	double f, g, h;
	int len, len2;
	int nb, nb1, nbx, nby;
	int i, j, k, l, l1;
	int stclk;

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

	printf("init\n");
//	tfau_init();
	printf("init ok\n");

	bsbufl=(uint32_t *)malloc(1<<26);
	bsbufr=(uint32_t *)malloc(1<<26);
	memset(bsbufl, 0, 1<<26);
	memset(bsbufr, 0, 1<<26);
	bpos=32;
	bplim=(1<<26)*8;
//	bplim=(1<<26)*2;
	bsbufl[0]=0x55AA1010;
	bsbufr[0]=0x55AA1010;

//	ibuf=BGBMID_LoadWAV_32Stereo16("sound_dev/02_Rise.wav", &len);
	ibuf=BGBMID_LoadWAV_32Stereo16("sound_dev/Skrillex_Reptile.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Stereo16(
//		"sound_dev/Skrillex_FirstOfTheYear.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Stereo16("sound_dev/Skrillex_BreaknASweat.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Stereo16(
//		"sound_dev/Skrillex_KillEverybody.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Stereo16("sound_dev/Skrillex_Cinema.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Stereo16("sound_dev/Skrillex_Bangarang.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Stereo16(
//		"sound_dev/OwenWasHer_Touhou6_PCM16M_22.wav", &len);

	nb=len/16;
	
	bbuf=(u64 *)malloc(nb*sizeof(u64));
	obuf=(s16 *)malloc(len*2*sizeof(s16));
	
	memset(bbuf, 0, nb*sizeof(u64));
	
	for(i=0; i<64; i++)
		btcnt[i]=0;

	for(i=0; i<8; i++)
		l4cnt[i]=0;
	
	for(i=0; i<nb; i++)
	{
//		bltac_encblock(ibuf+(i*16), bbuf+i);
//		bltac_decblock(bbuf[i], obuf+(i*16));

//		bltac_encblock2(ibuf+(i*16), bbuf+i);
//		bltac_decblock2(bbuf[i], obuf+(i*16));

		bltac_encblock3s(ibuf+(i*16)*2, bbuf+i);
//		bltac_decblock3s(bbuf[i], obuf+(i*16)*2);
		
//		j=(bbuf[i]>>48)&63;
		j=(bbuf[i])&63;
		btcnt[j]++;

		j=(bbuf[i]>>16)&7;
		l4cnt[j]++;
	}
	
	for(i=0; i<8; i++)
	{
		l=0;
		for(j=0; j<8; j++)
		{
			k=btcnt[i*8+j];
			l+=k;
			printf("%6d ", k);
		}
		printf("  %.2f%%\n", (100.0*l)/nb);
	}

//	imgbuf=(uint32_t *)malloc(16384*4);
//	imgba=0;

//	ibuf=BTIC1H_Img_LoadTGA(ifn, &xs, &ys);
//	dbuf=(byte *)malloc(xs*ys*4);

	dste=0;
	x=0; y=0; z=0;
	irq=0;

	printf("Start Sim:\n");

	top->busIRQ = 0;

//	stclk=20;
	stclk=15;
	while (!Verilated::gotFinish())
	{
//		top->busIRQ = 0;
//		i=20-(main_time%20);
//		if(i>=19)i=1;
		i=stclk;

		if(!irq && (i>2) && !(top->busIRQ))
//		if(0)
		{
			i--;
			while(i--)
			{
				top->clock = main_time&1;
				top->eval();
				main_time++;
				stclk--;

				if(top->busIRQ&0x0100)
					break;
			}
		}else
		{
			top->clock = main_time&1;
			top->eval();
			main_time++;
			stclk--;
		}

//		if(!(main_time&15))
//		if(!(main_time%1600))
//		if(!(main_time%20))
		if(stclk<=0)
		{
			if(top->pwmOut&1)
				bsbufl[bpos>>5]|=(1<<(bpos&31));
			if(top->pwmOut&2)
				bsbufr[bpos>>5]|=(1<<(bpos&31));

//			j=top->pwmOut&15;
//			obuf[bpos>>3]|=(j<<((bpos&7)*4));

			stclk=20;

			bpos++;
			if(bpos>=bplim)
			{
				printf("Bitstream Limit\n");
				break;
			}
		}
		
		if(top->busIRQ&0x0100)
		{
//			if(!irq)
//				printf("irq\n");
			irq=1;
//			if(z>=4)
//				irq=0;
		}
			
		if(irq)
		{
			if(x>=nb)
			{
				printf("End Of Input\n");
				break;
			}

			if(z<4)
			{
				top->busAddr=0xABCDE000+(z*4);
				blk64=bbuf[x+(z>>1)];
//				printf("%016lX %d.%d\n", blk64, x, z);
				top->busData=blk64>>((z&1)*32);
				top->busWR=1;
			}

//			if(!(main_time&15))
//			if(!(main_time&63))
			if(!(main_time&7))
			{
				z++;
			}
			if(z>=4)
				irq=0;
			y=x+2;
		}else
		{
//			if(x!=y)
			if((x&(~15))!=(y&(~15)))
			{
				ts0=FRGL_TimeMS()/1000.0;
				g=main_time/200000000.0;
				k=y*16;
				f=k/32000.0;
				sprintf(tb, "%d/%d (s=%d,t=%f,tt=%f,tr=%f) r=%ds(%.1f)\r",
					x, nb, k, f, g, f/g, (int)ts0, ts0/f);
				printf("%-.78s\r", tb);
				fflush(stdout);
				
//				if(f>=10.0)
				if(f>=30.0)
					break;
			}
		
			x=y;
			z=0;
			top->busWR=0;
		}
	}
	printf("\nEnd Sim\n");
	
	nb1=x;
	
	ofd=fopen("sim_dsptst0_pwml.dat", "wb");
	fwrite(bsbufl, 1, bpos/8, ofd);
	fclose(ofd);

	ofd=fopen("sim_dsptst0_pwmr.dat", "wb");
	fwrite(bsbufr, 1, bpos/8, ofd);
	fclose(ofd);
	
	len2=nb1*16; lcu=0; lcv=0;
	for(i=0; i<len2; i++)
	{
		if(i>len)
		{
			printf("Lim: i>len\n");
			break;
		}
	
		cu=0; cv=0;
//		for(j=0; j<32; j++)
		for(j=0; j<480; j++)
		{
//			k=i*31.25+j;
			k=i*312.5+j-160;
//			k=i*31+j;
//			if(k>=bpos)
//			{
//				printf("Lim: k>bpos %d>%d, i=%d j=%d\n", k, bpos, i, j);
//				break;
//			}

			if((k<0) || (k>bpos))
				continue;
			
			if(bsbufl[k>>5]&(1<<(k&31)))
				cu++;
			if(bsbufr[k>>5]&(1<<(k&31)))
				cv++;
		}

//		cu=(cu*(65536.0/31.25))-32768;
//		cv=(cv*(65536.0/31.25))-32768;
//		cu=(cu*(65536.0/312.5))-32768;
//		cv=(cv*(65536.0/312.5))-32768;

		cu=(cu*(65536.0/480.0))-32768;
		cv=(cv*(65536.0/480.0))-32768;
		cu=clamp(cu, -32768, 32767);
		cv=clamp(cv, -32768, 32767);
		
//		cu=(3*lcu+cu)/4;
//		cv=(3*lcv+cv)/4;
//		cu=(lcu+cu)/2;
//		cv=(lcv+cv)/2;
		lcu=cu;
		lcv=cv;
		
		obuf[i*2+0]=cu;
		obuf[i*2+1]=cv;
	}

	printf("Write Out\n");

	len2=nb1*16;
	BGBMID_StoreWAV("sim_dsptst0_out.wav", (byte *)obuf, 2, 32000, 16, len2);

	delete top;
	exit(0);
}

// verilator -Wall --cc our.v --exe sim_main.cpp
