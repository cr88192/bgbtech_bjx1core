#include <stdio.h>

int main()
{
	int cr, cg, cb;
	int cy, cu, cv;
	int i, j, k;
	
	for(i=0; i<64; i++)
	{
		cr=((i>>4)&3)*85;
		cg=((i>>2)&3)*85;
		cb=((i>>0)&3)*85;
		
		cy=(cr+2*cg+cb)/4;
		cu=(cb-cg)/2+128;
		cv=(cr-cg)/2+128;
		
		k=((cy/16)<<8) | ((cu/16)<<4) | ((cv/16)<<0);
		printf("cbClrTab[%d]=12'h%03X;\n", i, k);
	}
}