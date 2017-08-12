#include "VMemTile2.h"
#include "verilated.h"

VMemTile2* top = new VMemTile2;

vluint64_t main_time = 0;

uint32_t ram[65536];

int main(int argc, char **argv, char **env)
{
	Verilated::commandArgs(argc, argv);
	int probe, nextprobe, pric;
	int p0, p1, p2, lexh;
	int i, j, k;
	
	for(i=0; i<65536; i++)
	{
		ram[i]=(uint16_t)(~i);
	}
	

	probe=0x1234;
	pric=0;

	while (!Verilated::gotFinish())
	{
		top->clk = (main_time>>3)&1;
//		top->mode = 3;
		
//		top->baseAddr=0xDECAB00;
//		top->idxAddr=0x100;
//		top->idxDisp=3;

		top->eval();

		main_time++;
		
		if(!(main_time&15))
		{
			if(top->extOE || top->extWR)
			{
//				printf("ext: Addr=%lX Hold=%d OE=%d WR=%d Cyc=%d\n",
//					top->extAddr, top->extHold, top->extOE, top->extWR,
//					(int)(main_time>>4));
			}
		}

		if(1)
		{
			if(top->extOE)
			{
				k=top->extAddr>>2;
				k=k^(k>>16);
				k=(uint16_t)k;
				top->extData=ram[k];
//				printf("extData=%08X\n", ram[k]);
			}

			if(top->extWR)
			{
				k=top->extAddr>>2;
				k=k^(k>>16);
				k=(uint16_t)k;
				ram[k]=top->extData;
			}
		}
		
		if(main_time>64)
		{
			if(!top->extHold)
			{
				if(pric)
				{
					top->iopRd=1;
					top->imemAddr=probe;
//					top->iopMode = 3;

					p0=(uint32_t)(top->irdValue);
				}else
				{
					top->opRd=1;
	//				top->memAddr=0x1234;
					top->memAddr=probe;
					top->opMode = 3;

					p0=(uint32_t)(top->rdValue);
				}

//				k=top->memAddr>>2;
				k=probe>>2;
				k=k^(k>>16);
				k=(uint16_t)k;
				
				p1=ram[k];

				if(!(main_time&15))
				{
					printf("Addr=%08X %c TiIx=%02X.%01X "
						"Got=%08X Expect=%08X %s\n", 
						probe, pric?'I':'D',
						(probe>>6)&255, (probe>>2)&15,
						p0, p1, (p0==p1)?"OK":"Fail");
//					if(p0!=p1)
//					{
//						printf("Tile=%02X Idx=%02X\n",
//							(probe>>6)&255,
//							(probe>>2)&15);
//					}

					probe=rand()&0xFFFC;
//					probe=(rand()*rand())&0x3FFFFFFC;
					pric=rand()&1;
				}
			}
		}
		
//		if(main_time>(1024*16))
		if(main_time>(2048*16))
		{
//			printf("%llX\n", (long long)(top->outAddr));
			break;
		}
	}
	
#if 1
	probe=0x1234; pric=probe;
	for(i=0; i<256; i++)
//	for(i=0; i<16; i++)
	{
		top->opRd=0;
		top->opWr=1;
		top->memAddr = probe;
		top->opMode = 3;
		top->wrValue = probe;
		
		do
		{
			lexh = top->extHold;
			for(j=0; j<16; j++)
			{
				top->opRd=0;
				top->opWr=1;
				top->memAddr = probe;
				top->opMode = 3;
				top->wrValue = probe;

				top->clk = (main_time>>3)&1;
				top->eval();
				main_time++;

				if(top->extWR && !j)
				{
//					printf("ext: Addr=%lX Hold=%d OE=%d WR=%d Cyc=%d\n",
//						top->extAddr, top->extHold, top->extOE, top->extWR,
//						(int)(main_time>>4));
				}

				if(top->extOE)
				{
					k=top->extAddr>>2;
					k=k^(k>>16);
					k=(uint16_t)k;
					top->extData=ram[k];
	//				printf("extData=%08X\n", ram[k]);
				}

				if(top->extWR)
				{
					k=top->extAddr>>2;
					k=k^(k>>16);
					k=(uint16_t)k;
					p0=ram[k];
					p1=top->extData;
					ram[k]=p1;
					if(p0!=p1)
						printf("WR A=%lX %08X->%08X clk=%d\n",
							top->extAddr, p0, p1, top->clk);
				}
			}
		} while(top->extHold);
//		} while(lexh || top->extHold);

		pric=pric*251+1;
		probe=(pric>>8)&0xFFFC;
	}
#endif

	probe=0x1234;
//	probe=rand();
	pric=probe;
	for(i=0; i<64; i++)
	{
		top->iopRd=0;
		top->opRd=1;
		top->opWr=0;
		top->memAddr = probe;
		top->opMode = 3;
//		top->wrValue = probe;

//		probe=((probe*251+1)>>8)&65535;

//		while(top->extHold)
		do
		{
			for(j=0; j<16; j++)
			if(1)
			{
				top->opRd=1;
				top->opWr=0;
				top->memAddr = probe;
				top->opMode = 3;

				top->clk = (main_time>>3)&1;
				top->eval();
				main_time++;

//				if((top->extOE || top->extWR) && !j)
				if(top->extWR && !j)
				{
//					printf("ext: Addr=%lX Hold=%d OE=%d WR=%d Cyc=%d\n",
//						top->extAddr, top->extHold, top->extOE, top->extWR,
//						(int)(main_time>>4));
				}

				if(top->extOE)
				{
					k=top->extAddr>>2;
					k=k^(k>>16);
					k=(uint16_t)k;
					top->extData=ram[k];
	//				printf("extData=%08X\n", ram[k]);
				}

				if(top->extWR)
				{
					k=top->extAddr>>2;
					k=k^(k>>16);
					k=(uint16_t)k;
					p0=ram[k];
					p1=top->extData;
					ram[k]=p1;
					if(p0!=p1)
						printf("WR A=%lX %08X->%08X clk=%d\n",
							top->extAddr, p0, p1, top->clk);
				}
			}
		} while(top->extHold);
		
		p0=top->rdValue;
		p1=probe;
		
		printf("%08X %08X %08X %s\n", probe, p0, p1,
			(p0==p1)?"OK":"Fail");

		pric=pric*251+1;
		probe=(pric>>8)&0xFFFC;
	}

	delete top;
	exit(0);
}

// verilator -Wall --cc our.v --exe sim_main.cpp
