#include "VMemAlu.h"
#include "verilated.h"

VMemAlu* top = new VMemAlu;

vluint64_t main_time = 0;

int main(int argc, char **argv, char **env)
{
	Verilated::commandArgs(argc, argv);

	while (!Verilated::gotFinish())
	{
		top->clk = (main_time>>4)&1;
		top->mode = 3;
		
		top->baseAddr=0xDECAB00;
		top->idxAddr=0x100;
		top->idxDisp=3;

		top->eval();

		main_time++;
		
		if(main_time>64)
		{
			printf("%llX\n", (long long)(top->outAddr));
			break;
		}
	}
	delete top;
	exit(0);
}

// verilator -Wall --cc our.v --exe sim_main.cpp
