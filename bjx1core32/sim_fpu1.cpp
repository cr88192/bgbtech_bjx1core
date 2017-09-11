#include "VFpuFp64.h"
#include "verilated.h"

#include <stdint.h>
#include <math.h>

struct Fpu64Test_s {
int opr;
double a, b, c;
}Fpu32_Tests[] = {
{ 0x41, 3.0,  4.0,  7.0},
{ 0x41, 3.0, -4.0, -1.0},
{ 0x42, 3.0,  4.0, -1.0},
{ 0x42, 3.0, -4.0,  7.0},

{ 0x43, 3.0,  4.0,  12.0},
{ 0x43, 3.0, -4.0, -12.0},

{ 0x44, 3.0,  4.0,  0.750},
{ 0x44, 3.0, -4.0, -0.750},


{ 0x45, 3.0,  4.0,  4.0},
{ 0x45, 3.0, -4.0,  4.0},

{ 0x46, 3.0,  4.0,  -4.0},
{ 0x46, 3.0, -4.0,   4.0},

{ 0x47, 3.0,  4.0,   0.250},
{ 0x47, 3.0, -4.0,  -0.250},

{ 0x47, 3.0,  1.5,   0.666667},
{ 0x47, 3.0,  3.0,   0.333333},
{ 0x47, 3.0,  5.0,   0.200000},
{ 0x47, 3.0,  7.0,   0.142857},

{ 0x41, 3.0,  0.0,  3.0},
{ 0x41, 0.0,  3.0,  3.0},

{ 0x41, 3.0, -3.0,  0.0},

{ 0x43, 3.0,  0.0,  0.0},
{ 0x43, 0.0,  3.0,  0.0},

{ 0x48, 3.0,  2.0,   1.414213},

{ 0x01, 3.0,  4.0,  7.0},
{ 0x01, 3.0, -4.0, -1.0},
{ 0x02, 3.0,  4.0, -1.0},
{ 0x02, 3.0, -4.0,  7.0},

{ 0, 0, 0, 0}
};

VFpuFp64* top = new VFpuFp64;

vluint64_t main_time = 0;

int main(int argc, char **argv, char **env)
{
	Verilated::commandArgs(argc, argv);
	struct Fpu64Test_s *test;
	float tsf, tsg, tsh;
	double tdf, tdg, tdh, tdi;
	uint64_t ta, tb, tc, td;
	int op, ok, inex;

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
		
		top->opMode=op&0x3F;

		if(op&0x40)
		{
			tdf=test->a; tdg=test->b; tdh=test->c;

			ta=*(uint64_t *)(&tdf);
			tb=*(uint64_t *)(&tdg);
			tc=*(uint64_t *)(&tdh);

			top->opf32=0;
			top->srca=ta;	top->srcb=tb;
		}else
		{
			tsf=test->a; tsg=test->b; tsh=test->c;
			ta=*(uint32_t *)(&tsf);
			tb=*(uint32_t *)(&tsg);
			tc=*(uint32_t *)(&tsh);

			top->opf32=1;
			top->srca=ta;	top->srcb=tb;
		}

		top->eval();
		
		td=top->dst;

		if((main_time&63)==63)
		{
			if(op&0x40)
			{

				tdf=*(double *)(&ta);
				tdg=*(double *)(&tb);
				tdh=*(double *)(&tc);
				tdi=*(double *)(&td);
				
				ok=fabs(tdh-tdi)<0.000001;
				inex=fabs(tdh-tdi)<0.001;

				printf("%02X %016lX %016lX %016lX %016lX\n",
					op, ta, tb, tc, td);
				printf("  %02X %f %f %f %f %s\n",
					op, tdf, tdg, tdh, tdi,
					ok?"OK":inex?"Inexact":"Bad");
//				printf("\n");
			}else
			{
				tdf=*(float *)(&ta);
				tdg=*(float *)(&tb);
				tdh=*(float *)(&tc);
				tdi=*(float *)(&td);

				ok=fabs(tdh-tdi)<0.000001;

				printf("%02X %08lX %08lX %08lX %08lX\n", op, ta, tb, tc, td);
				printf("  %02X %f %f %f %f %s\n",
					op, tdf, tdg, tdh, tdi, ok?"OK":"Bad");
//				printf("\n");
			}
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
