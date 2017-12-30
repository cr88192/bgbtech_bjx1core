#include <stdio.h>

char *text=
"+--------------------------------------+"
"| Screen Test                          |"
"|                                      |"
"|  !\"#$%&'()*+,-./                     |"
"| 0123456789:;<=>?                     |"
"| @ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_     |"
"| `abcdefghijklmnopqrstuvwxyz{|}~      |"
"|                                      |"
"\b0C"
"| @ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_     |"
"\b00\b4C"
"| `abcdefghijklmnopqrstuvwxyz{|}~      |"
"\b40\b3F"
"+--------------------------------------+"
"\r5A5A\rA5A5\r9696\r6969"
;

int hexci(char c)
{
	if((c>='0') && (c<='9'))
		return(c-'0');
	if((c>='A') && (c<='F'))
		return(10+(c-'A'));
	if((c>='a') && (c<='f'))
		return(10+(c-'a'));
	return(-1);
}

int hex2i(char *s0)
{
	return(hexci(s0[0])*16+hexci(s0[1]));
}

int hex4i(char *s0)
{
	return(hex2i(s0+0)*256+hex2i(s0+2));
}

int main()
{
	char *s;
	FILE *fd;
	int ch, clr;
	int i,j,k;
	
	fd=fopen("scrmem.txt", "wt");
	
	clr=0x003F;
	s=text;
//	for(i=0; i<1000; i++)
	for(i=0; i<25; i++)
	{
		for(j=0; j<40; j++)
		{
			if(!(*s) || (*s=='\n'))
				break;
			if(*s=='\b')
			{
				k=hex2i(s+1);
				if((k>=0x00) && k<=0x3F)
					{ clr=(clr&(~0x003F))|(k&0x3F); }
				if((k>=0x40) && k<=0x7F)
					{ clr=(clr&(~0x0FC0))|((k&0x3F)<<6); }
				
				s+=3;
				j--;
				continue;
			}

			if(*s=='\r')
			{
				k=hex4i(s+1);
				fprintf(fd, "%04X_%04X\n", clr|0x4000, k);
				s+=5;
				continue;
			}

			ch=*s++;
			fprintf(fd, "%04X_%04X\n", clr, ch);
		}
		for(; j<40; j++)
		{
			fprintf(fd, "%04X_%04X\n", clr, ' ');
		}

		if(*s=='\n')
			s++;
	}
	
	fclose(fd);
}
