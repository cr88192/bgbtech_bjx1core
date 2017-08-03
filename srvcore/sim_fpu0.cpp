#include "VFpuFp32.h"
#include "verilated.h"

struct Fpu32Test_s {
int opr;
float a, b, c;
}Fpu32_Tests[] = {
{ 1, 3.0,  4.0,  7.0},
{ 1, 3.0, -4.0, -1.0},
{ 2, 3.0,  4.0, -1.0},
{ 2, 3.0, -4.0,  7.0},

{ 3, 3.0,  4.0,  12.0},
{ 3, 3.0, -4.0, -12.0},

{ 4, 3.0,  4.0,  0.750},
{ 4, 3.0, -4.0, -0.750},


{ 5, 3.0,  4.0,  4.0},
{ 5, 3.0, -4.0,  4.0},

{ 6, 3.0,  4.0,  -4.0},
{ 6, 3.0, -4.0,   4.0},

{ 7, 3.0,  4.0,   0.250},
{ 7, 3.0, -4.0,  -0.250},

{ 7, 3.0,  1.5,   0.666667},
{ 7, 3.0,  3.0,   0.333333},
{ 7, 3.0,  5.0,   0.200000},
{ 7, 3.0,  7.0,   0.142857},

{ 1, 3.0,  0.0,  3.0},
{ 1, 0.0,  3.0,  3.0},

{ 1, 3.0, -3.0,  0.0},

{ 3, 3.0,  0.0,  0.0},
{ 3, 0.0,  3.0,  0.0},

{ 8, 3.0,  2.0,   1.414213},

{ 0, 0, 0, 0}
};

VFpuFp32* top = new VFpuFp32;

vluint64_t main_time = 0;

int main(int argc, char **argv, char **env)
{
	Verilated::commandArgs(argc, argv);
	struct Fpu32Test_s *test;
	unsigned int ta, tb, tc, td;
	int op;

	while (!Verilated::gotFinish())
	{
		top->clk = (main_time>>4)&1;
//		top->mode = 3;
		
//		top->baseAddr=0xDECAB00;
//		top->idxAddr=0x100;
//		top->idxDisp=3;

		test=&(Fpu32_Tests[main_time>>6]);

		op=test->opr;
		if(!op)
			break;
		
		ta=*(unsigned int *)(&(test->a));
		tb=*(unsigned int *)(&(test->b));
		tc=*(unsigned int *)(&(test->c));

		top->opMode=op;
		top->srca=ta;	top->srcb=tb;

		top->eval();
		
		td=top->dst;

		if((main_time&63)==63)
		{
			printf("%d %X %X %X %X\n", op, ta, tb, tc, td);
			printf("%d %f %f %f %f\n", op,
				*(float *)(&ta), *(float *)(&tb),
				*(float *)(&tc), *(float *)(&td));
			printf("\n");
		}

		main_time++;
		
//		if(main_time>64)
//		{
//			printf("%llX\n", (long long)(top->outAddr));
//			break;
//		}
	}
	delete top;
	exit(0);
}

// verilator -Wall --cc our.v --exe sim_main.cpp
