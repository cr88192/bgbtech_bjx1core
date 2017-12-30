#include "VExUop.h"
#include "verilated.h"

VExUop* top = new VExUop;

vluint64_t main_time = 0;

uint16_t rom[65536] = 
{
0xE21F,		//0, NOP
0x312C,		//2, NOP
0x0209,		//4, NOP
0x0309,		//6, NOP
0x0409,		//8, NOP
0x0509,		//A, NOP
0xAFF8,		//C, BRA $-16
0x0609		//E, NOP
};

uint32_t ram[65536];

uint32_t SRV_GetDWord(uint64_t addr)
{
	uint32_t tv;
	int i, j, k;
	
	if((addr>=0x00000000) && (addr<0x00040000))
	{
		i=(addr>>1);
		i=i&65535;
		tv=rom[i+0] | (rom[i+1]<<16);
		return(tv);
	}

	if((addr>=0x0C000000) && (addr<0x0C040000))
	{
		i=addr>>2;
		i=i&65535;
		tv=ram[i];
		return(tv);
	}
	
	tv=(uint32_t)(-1);
	return(tv);
}

int SRV_SetDWord(uint64_t addr, uint32_t val)
{
	int i, j, k;

	if((addr>=0x0C000000) && (addr<0x0C040000))
	{
		i=addr>>2;
		i=i&65535;
		ram[i]=val;
		return(0);
	}

	return(-1);
}

int main(int argc, char **argv, char **env)
{
	uint32_t dat;
	int clk, clk1;
	int i, j, k;

	Verilated::commandArgs(argc, argv);
	
	main_time = 0;

	while (!Verilated::gotFinish())
	{
		clk1=(main_time)&1;
		if(clk1!=clk)
		{
			if(clk1)
				printf("Clock: ->\n");
			else
				printf("Clock: <-\n");
		}
		clk=clk1;
	
//		top->clk = (main_time>>3)&1;
//		top->clk = (main_time)&1;
		top->clk = clk;
		top->reset = 0;

//		top->mode = 3;
		
//		top->baseAddr=0xDECAB00;
//		top->idxAddr=0x100;
//		top->idxDisp=3;

		top->eval();

		main_time++;

		if(1)
		{
			if(top->extOE)
			{
				dat=SRV_GetDWord(top->extAddr);
				top->extData=dat;
//				if((main_time&15)==0)
				if((main_time&1)==0)
					printf("Read addr=%012lX data=%08X\n",
						(uint64_t)(top->extAddr), dat);
			}

			if(top->extWR)
			{
				dat=top->extData;
				SRV_SetDWord(top->extAddr, dat);

//				if((main_time&15)==0)
				if((main_time&1)==0)
				{
					printf("Write addr=%012lX data=%08X\n",
						(uint64_t)(top->extAddr), (uint32_t)(dat));
				}
			}
		}

//		if(main_time>(65536*16))
//		if(main_time>(4096*16))
		if(main_time>(4096))
		{
//			printf("%llX\n", (long long)(top->outAddr));
			break;
		}
	}
	
	fflush(stdout);
	
	delete top;
	exit(0);
}

// verilator -Wall --cc our.v --exe sim_main.cpp
