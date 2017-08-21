/*
Color Frequency
  3.579545

Color Amplitude
	0.175, 45

100/ClrFreq=27.93650794
ClrFreq/100=0.03579545454

2346/65536

1172.94545436672 (15)
150137.01815894016 (22)
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned char byte;
typedef signed char sbyte;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;

#include "bt1h_targa.c"

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif


byte *loadfile(char *path, int *rsz)
{
	byte *buf;
	FILE *fd;
	int sz, i;
	
	fd=fopen(path, "rb");
	if(!fd)
		return(NULL);

	fseek(fd, 0, 2);
	sz=ftell(fd);
	fseek(fd, 0, 0);
	buf=malloc(sz);
	i=fread(buf, 1, sz, fd);
	fclose(fd);
	
	*rsz=sz;
	return(buf);
}

int storefile(char *name, byte *ibuf, int isz)
{
	byte *tbuf;
	FILE *fd;
	int sz;

	fd=fopen(name, "wb");
	if(!fd)
	{
		printf("Fail Open Write %s\n", name);
		return(-1);
	}

	fwrite(ibuf, 1, isz, fd);
	fclose(fd);
	return(0);
}

int CEnc_WriteBits(u32 *bits, int pos, int val, int nb)
{
	u64 w;
	int i, j, k;
	
	i=pos>>5;
	j=pos&31;
	
	w=bits[i]|(((u64)(bits[i+1]))<<32);
	w&=~(((1LL<<nb)-1)<<j);
	w|=(val&((1<<nb)-1))<<j;
	bits[i+0]=w;
	bits[i+1]=w>>32;
	return(0);
}

typedef struct CEnc_Context_s CEnc_Context;

struct CEnc_Context_s
{
u32 *bits;
int bpos;

byte pwmst;
byte fodd;
};

int CEnc_WriteBitsCtx(CEnc_Context *ctx, int val, int nb)
{
	CEnc_WriteBits(ctx->bits, ctx->bpos, val, nb);
	ctx->bpos+=nb;
	return(0);
}

int CEnc_WriteBitPwm(CEnc_Context *ctx, int val)
{
	int i;
	
	if(val>>8)
	{
		if(val<0)val=0;
		if(val>255)val=255;
	}

	i=ctx->pwmst;
	i+=val;
	ctx->pwmst=i;
	
	CEnc_WriteBitsCtx(ctx, i>>8, 1);
	return(0);
}

int CEnc_WriteBitsPwm(CEnc_Context *ctx, int val, int cnt)
{
	int i;

	for(i=0; i<cnt; i++)
		CEnc_WriteBitPwm(ctx, val);
	return(0);
}

// byte cbspwm[512];
// byte cbcpwm[512];

byte cbspwm2[32];
byte cbcpwm2[32];

int CEnc_EncImage(CEnc_Context *ctx, byte *ibuf)
{
	double f, g;
	int cr, cg, cb;
	int cy, cu, cv;
	int py, pu, pv;
	int bp, bp1, odd;
	int i, j, k, l;

#if 0
	for(i=0; i<512; i++)
	{
//		f=(i/512.0)*(73.0*(2*M_PI));
//		f=(i/512.0)*(73.0*(2*M_PI));
		f=(i/100.0)*(3.579545454*(2*M_PI));
//		j=45*sin(f);
//		k=45*cos(f);
		j=37*sin(f);
		k=37*cos(f);
//		j=22*sin(f);
//		k=22*cos(f);
		cbspwm[i]=j+128;
		cbcpwm[i]=k+128;
	}
#endif

	for(i=0; i<32; i++)
	{
		f=(i/32.0)*(2*M_PI);
//		j=45*sin(f);
//		k=45*cos(f);
		j=37*sin(f);
		k=37*cos(f);
		cbspwm2[i]=j+128;
		cbcpwm2[i]=k+128;
	}

	/* VSync Pulse */
	for(i=0; i<5; i++)
	{
		CEnc_WriteBitsPwm(ctx, 76,  472);
		CEnc_WriteBitsPwm(ctx,  0, 2704);
	}

	odd=ctx->fodd;

	/* Equalizing Pulse */
	for(i=0; i<(odd?6:5); i++)
	{
		CEnc_WriteBitsPwm(ctx, 76, 2944);
		CEnc_WriteBitsPwm(ctx,  0,  232);
	}

	/* Vertical Blank */

	for(i=0; i<20; i++)
	{
		CEnc_WriteBitsPwm(ctx, 76, 112);
		for(j=0; j<248; j++)
		{
//			k=ctx->bpos&511;
//			CEnc_WriteBitPwm(ctx, 76+(cbspwm[k]-128));

			bp=(ctx->bpos*150137)>>17;
			l=76+(cbspwm2[bp&31]-128);
			CEnc_WriteBitPwm(ctx, l);
		}
		CEnc_WriteBitsPwm(ctx, 76, 112);
		/* 472 Ticks */

		CEnc_WriteBitsPwm(ctx, 76, 5392);

		CEnc_WriteBitsPwm(ctx,  0, 472);
	}
	for(i=0; i<240; i++)
	{
//		ctx->bpos&=~7;

		CEnc_WriteBitsPwm(ctx, 76, 112);
		for(j=0; j<248; j++)
		{
			bp=(ctx->bpos*150137)>>17;
			l=76+(cbspwm2[bp&31]-128);
			CEnc_WriteBitPwm(ctx, l);
		}
		CEnc_WriteBitsPwm(ctx, 76, 112);
		/* 472 Ticks */
		
		for(j=0; j<640; j++)
		{
			k=479-(i*2+odd);
			cr=ibuf[(k*640+j)*4+0];
			cg=ibuf[(k*640+j)*4+1];
			cb=ibuf[(k*640+j)*4+2];
			
			cy=(cr+2*cg+cb)/4;
			cu=(cb-cg)/2+128;
			cv=(cr-cg)/2+128;
			
//			cu=128;
//			cu=0;
//			cv=0;
			
			py=76+((cy*153)>>8);
			for(k=0; k<8; k++)
			{
				bp=(ctx->bpos*150137)>>17;
				bp1=(bp+3)&31;
				pu=((cbcpwm2[bp1]-128)*(cu-128))>>6;
				pv=((cbspwm2[bp1]-128)*(cv-128))>>6;
				l=py+pu+pv;
				if(l<50)l=50;
				CEnc_WriteBitPwm(ctx, l);
			}
		}
		/* Scan 5120, 5592 ticks */
		/* Tgt=6356, 6352 */
		
//		if(!(i&3))
//			CEnc_WriteBitsPwm(ctx, 76, 274);
//		else
//			CEnc_WriteBitsPwm(ctx, 76, 290);

		if((i&3))
			CEnc_WriteBitsPwm(ctx, 76, 224);
		else
			CEnc_WriteBitsPwm(ctx, 76, 232);

//		CEnc_WriteBitsPwm(ctx, 76, 256);
//		CEnc_WriteBitsPwm(ctx, 76, 274);
//		CEnc_WriteBitsPwm(ctx, 76, 282);
		
		CEnc_WriteBitsPwm(ctx,  0, 472);
//		ctx->pwmst=0;
//		ctx->pwmst=255;
//		ctx->pwmst=180;
	}

	return(0);
}

int main(int argc, char *argv[])
{
	CEnc_Context *ctx;
	byte *ibuf, *dbuf;
	byte *obuf;
	char *ifn, *ofn;
	int isz, xs, ys;
	int i, j, k;
	
//	pwmtab_init();
	
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

//	if(!ifn || !ofn)
	if(!ifn)
	{
		return(-1);
	}

	ibuf=BTIC1H_Img_LoadTGA(ifn, &xs, &ys);

	if(!ibuf)
	{
		printf("Failed load image\n");
		return(0);
	}

	if((xs!=640) || (ys!=480))
	{
		printf("Image not 640x480\n");
		return(0);
	}

	obuf=malloc(512*1024);
	memset(obuf, 0, 512*1024);

	ctx=malloc(sizeof(CEnc_Context));
	memset(ctx, 0, sizeof(CEnc_Context));
	
	ctx->bits=(u32 *)obuf;
//	ctx->bpsz=isz/4;

	CEnc_EncImage(ctx, ibuf);
	CEnc_EncImage(ctx, ibuf);

	if(ofn)
	{
		storefile(ofn, obuf, (ctx->bpos+7)/8);
	}
	
	return(0);
}
