#include "VMemTile2.h"
#include "verilated.h"

VMemTile2* top = new VMemTile2;

vluint64_t main_time = 0;

uint32_t ram[65536];

int main(int argc, char **argv, char **env)
{
	Verilated::commandArgs(argc, argv);
	int i, j, k;
	
	for(i=0; i<65536; i++)
	{
		ram[i]=(uint16_t)(~i);
	}
	

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
			printf("ext: Addr=%lX Hold=%d OE=%d WR=%d Cyc=%d\n",
				top->extAddr, top->extHold, top->extOE, top->extWR,
				(int)(main_time>>4));
				
			if(top->extOE)
			{
				k=top->extAddr>>2;
				k=(uint16_t)k;
				top->extData=ram[k];
				printf("%08X\n", ram[k]);
			}

			if(top->extWR)
			{
				k=top->extAddr>>2;
				k=(uint16_t)k;
				ram[k]=top->extData;
			}
		}
		
		if(main_time>64)
		{
			if(!top->extHold)
			{
				top->opRd=1;
				top->memAddr=0x1234;
				top->opMode = 3;

				if(!(main_time&15))
				{
					printf("%08X\n", (uint32_t)(top->rdValue));
				}
			}
		}
		
		if(main_time>(1024*16))
		{
//			printf("%llX\n", (long long)(top->outAddr));
			break;
		}
	}
	delete top;
	exit(0);
}

// verilator -Wall --cc our.v --exe sim_main.cpp
