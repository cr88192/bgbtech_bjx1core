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

#if 0
static const u32 clrtab[16]={
	0xFF000000,	0xFF0000AA,	0xFF00AA00,	0xFF00AAAA,
	0xFFAA0000,	0xFFAA00AA,	0xFFAA5500,	0xFFAAAAAA,
	0xFF555555,	0xFF5555FF,	0xFF55FF55,	0xFF55FFFF,
	0xFFFF5555,	0xFFFF55FF,	0xFFFFFF55,	0xFFFFFFFF};

int vqenc_rgb2p16(int cr, int cg, int cb)
{
	int dr, dg, db, d, bd, bi;
	int i, j, k;
	
	bd=999999999; bi=0;
	for(i=0; i<16; i++)
	{
//		dr=cr-((clrtab[i]>>16)&255);
		dr=cr-((clrtab[i]    )&255);
		dg=cg-((clrtab[i]>> 8)&255);
//		db=cb-((clrtab[i]    )&255);
		db=cb-((clrtab[i]>>16)&255);
		d=dr*dr+dg*dg+db*db;
		
		if(d<bd)
			{ bi=i; bd=d; }
	}
	return(bi);
}
#endif

int vqberr(byte *blka, byte *blkb)
{
	double e;
	int dr, dg, db;
	int i;
	
	e=0;
	for(i=0; i<16; i++)
	{
		dr=blka[i*4+0]-blkb[i*4+0];
		dg=blka[i*4+1]-blkb[i*4+1];
		db=blka[i*4+2]-blkb[i*4+2];
		e+=dr*dr+2*dg*dg+(db*db/2);
	}
	
	e=sqrt(e/(3*16));
	return(e);
}

double vqierr(byte *blka, byte *blkb, int xs, int ys)
{
	double e;
	int dr, dg, db;
	int n;
	int i;
	
	e=0; n=xs*ys;
	for(i=0; i<n; i++)
	{
		dr=blka[i*4+0]-blkb[i*4+0];
		dg=blka[i*4+1]-blkb[i*4+1];
		db=blka[i*4+2]-blkb[i*4+2];
		e+=dr*dr+2*dg*dg+(db*db/2);
	}
	
	e=sqrt(e/(3*n));
	return(e);
}

int vqenc(byte *iblk, int ystr, u32 *oblk, u64 *rsta)
{
	byte pxa[16*4];
	byte pxb[16*4];
	byte pxc[16*4];
	short pxy[16];
	
	u64 sta, stb, stc, std;
	int min, max;
	u32 blk, blka, blkb, blkc;

	int acr, acg, acb, acy;

	int cr, cg, cb, cy;
	int mr, mg, mb, my, mdy;
	int nr, ng, nb, ny, ndy;
	int cu, cv;

	int mr2, mg2, mb2, my2;
	int nr2, ng2, nb2, ny2;

	int cy_c, cy_m, cy_y;
	int my_c, my_m, my_y;
	int ny_c, ny_m, ny_y;
	int ax, dy;
	int e0, e1;

	int cya, cyb, ctsp;
	int acu, acv, ady;
	int ia, ib, ix, px;
	int ixa, ixb, ixc;
	int i, j, k, l;
	
	my=256; ny=-1;
	my_c=256; ny_c=-1;
	my_m=256; ny_m=-1;
	my_y=256; ny_y=-1;
	acr=0; acg=0; acb=0; acy=0;
	acu=0; acv=0;
	for(i=0; i<4; i++)
		for(j=0; j<4; j++)
	{
		cr=iblk[i*ystr+j*4+0];
		cg=iblk[i*ystr+j*4+1];
		cb=iblk[i*ystr+j*4+2];
		cy=(cr+2*cg+cb)/4;

		k=i*4+j;
//		k=(3-i)*4+j;
		pxc[k*4+0]=cr;
		pxc[k*4+1]=cg;
		pxc[k*4+2]=cb;
		pxc[k*4+3]=255;

		cy_c=(1*cr+4*cg+3*cb)/8;
		cy_m=(4*cr+1*cg+3*cb)/8;
		cy_y=(3*cr+4*cg+1*cb)/8;

		cu=((cb-cg)/2)+128;
		cv=((cr-cg)/2)+128;

		if(cy<my) { my=cy; }
		if(cy>ny) { ny=cy; }
		if(cy_c<my_c) { my_c=cy_c; }
		if(cy_c>ny_c) { ny_c=cy_c; }
		if(cy_m<my_m) { my_m=cy_m; }
		if(cy_m>ny_m) { ny_m=cy_m; }
		if(cy_y<my_y) { my_y=cy_y; }
		if(cy_y>ny_y) { ny_y=cy_y; }
		
		acr+=cr;	acg+=cg;
		acb+=cb;	acy+=cy;
		acu+=cu;	acv+=cv;
	}
	
	acr=acr/16;	acg=acg/16;
	acb=acb/16;	acy=acy/16;
	acu=acu/16;	acv=acv/16;

	acy=(2*acy+my+ny)/4;

	ax=0; dy=ny-my;
	
	dy=2*(ny-acy);
	
//	i=ny_c-my_c; if(i>dy) { ax=1; dy=i; }
//	i=ny_m-my_m; if(i>dy) { ax=2; dy=i; }
//	i=ny_y-my_y; if(i>dy) { ax=3; dy=i; }

	mr=0; mg=0; mb=0; my=0; cya=0;
	nr=0; ng=0; nb=0; ny=0; cyb=0;
	mdy=0; ndy=0;
	for(i=0; i<4; i++)
		for(j=0; j<4; j++)
	{
		cr=iblk[i*ystr+j*4+0];
		cg=iblk[i*ystr+j*4+1];
		cb=iblk[i*ystr+j*4+2];
//		cy=(cr+2*cg+cb)/4;

		switch(ax)
		{
		case 0: cy=(cr+2*cg+cb)/4; break;
		case 1: cy=(1*cr+4*cg+3*cb)/8; break;
		case 2: cy=(4*cr+1*cg+3*cb)/8; break;
		case 3: cy=(3*cr+4*cg+1*cb)/8; break;
		}

		pxy[i*4+j]=cy;
		
		if(cy<acy)
			{ mr+=cr; mg+=cg; mb+=cb; my+=cy; cya++; mdy+=acy-cy; }
		else
			{ nr+=cr; ng+=cg; nb+=cb; ny+=cy; cyb++; ndy+=cy-acy; }
	}
	
	if(!cya)cya++;
	if(!cyb)cyb++;

	mr=mr/cya; mg=mg/cya;
	mb=mb/cya; my=my/cya;

	nr=nr/cyb; ng=ng/cyb;
	nb=nb/cyb; ny=ny/cyb;

	mdy=mdy/cya;
	ndy=ndy/cya;
	ady=(mdy+ndy)/2;

#if 1
	my2=256; ny2=-1;
	for(i=0; i<4; i++)
		for(j=0; j<4; j++)
	{
		cr=iblk[i*ystr+j*4+0];
		cg=iblk[i*ystr+j*4+1];
		cb=iblk[i*ystr+j*4+2];

		switch(ax)
		{
		case 0: cy=(cr+2*cg+cb)/4; break;
		case 1: cy=(1*cr+4*cg+3*cb)/8; break;
		case 2: cy=(4*cr+1*cg+3*cb)/8; break;
		case 3: cy=(3*cr+4*cg+1*cb)/8; break;
		}
		
		pxy[i*4+j]=cy;
		if(cy<my2)
			{ my2=cy; mr2=cr; mg2=cg; mb2=cb; }
		if(cy>ny2)
			{ ny2=cy; nr2=cr; ng2=cg; nb2=cb; }
	}
	
	mr=(mr+mr2)/2;
	mg=(mg+mg2)/2;
	mb=(mb+mb2)/2;
	my=(my+my2)/2;

	nr=(nr+nr2)/2;
	ng=(ng+ng2)/2;
	nb=(nb+nb2)/2;
	ny=(ny+ny2)/2;
#endif
	
	ctsp=0;
	ia=vqenc_rgb2p64(mr, mg, mb, ctsp);
	ib=vqenc_rgb2p64(nr, ng, nb, ctsp);
	ixa=0x4000|(ctsp<<12)|(ia<<6)|ib;

	ctsp=1;
	ia=vqenc_rgb2p64(mr, mg, mb, ctsp);
	ib=vqenc_rgb2p64(nr, ng, nb, ctsp);
	ixc=0x4000|(ctsp<<12)|(ia<<6)|ib;

//	acu=128;
//	acv=128;

//	dy=dy*0.75;
//	ady=(ady+3*dy)/4;
	ady=(ady+dy)/2;

	acy=clamp255(acy);
	acu=clamp255(acu);
	acv=clamp255(acv);
	ady=clamp255(ady);

#if 1
	sta=*rsta;
	stb=sta;

	stc=sta;
	ixb=vqenc_dyuvd(acy, ady, acu, acv, &stc);
#endif

#if 0
//	i=acy>>4; j=dy>>4;
	i=(acy+7)>>4; j=(dy+7)>>4;
	if(i<0)i=0;
	if(j<0)j=0;
	if(i>15)i=15;
	if(j>15)j=15;

//	k=acu>>5;
//	l=acv>>5;
	k=(acu+15)>>5;
	l=(acv+15)>>5;
//	k=(acu+7)>>5;
//	l=(acv+7)>>5;

#if 0
//	k=sqrt(acu-128)*0.333+4;
//	l=sqrt(acv-128)*0.333+4;
	k=sqrt(acu-128)*0.26+4+0.5;
	l=sqrt(acv-128)*0.26+4+0.5;
#endif

	if(k<1)k=1;
	if(l<1)l=1;
	if(k>7)k=7;
	if(l>7)l=7;

	ixb=0xC000|(i<<10)|(j<<6)|(k<<3)|l;
#endif

	
//	cya=(3*my+1*ny)/4;
//	cyb=(1*my+3*ny)/4;
//	cya=(7*my+1*ny)/8;
//	cyb=(1*my+7*ny)/8;
	cya=(5*my+3*ny)/8;
	cyb=(3*my+5*ny)/8;

	px=0;
	if(pxy[ 0]>cya)px|=0x0008;
	if(pxy[ 1]>cyb)px|=0x0004;
	if(pxy[ 2]>cya)px|=0x0002;
	if(pxy[ 3]>cyb)px|=0x0001;

	if(pxy[ 4]>cyb)px|=0x0080;
	if(pxy[ 5]>cya)px|=0x0040;
	if(pxy[ 6]>cyb)px|=0x0020;
	if(pxy[ 7]>cya)px|=0x0010;

	if(pxy[ 8]>cya)px|=0x0800;
	if(pxy[ 9]>cyb)px|=0x0400;
	if(pxy[10]>cya)px|=0x0200;
	if(pxy[11]>cyb)px|=0x0100;

	if(pxy[12]>cyb)px|=0x8000;
	if(pxy[13]>cya)px|=0x4000;
	if(pxy[14]>cyb)px|=0x2000;
	if(pxy[15]>cya)px|=0x1000;

	blka=px|(ixa<<16);
	blkb=px|(ixb<<16);
	blkc=px|(ixc<<16);

	std=sta;
	vqdec(pxa, 16, blka, &std);
	std=sta;
	vqdec(pxb, 16, blkc, &std);

#if 1
	e0=vqberr(pxa, pxc);
	e1=vqberr(pxb, pxc);
	if(e1<e0)
		blka=blkc;
//	blka=blkc;

#endif

	std=sta;
	vqdec(pxa, 16, blka, &std);
	std=sta;
	vqdec(pxb, 16, blkb, &std);
	
	e0=vqberr(pxa, pxc);
	e1=vqberr(pxb, pxc);

	blk=blka;
	if(e1<e0)
//	if(1)
	{
		blk=blkb;
		stb=stc;
	}
	
//	blk=(e0<e1)?blka:blkb;
//	blk=blka;

	*oblk=blk;
	*rsta=stb;
	return(0);
}

#if 0
int vqdec(byte *iblk, int ystr, u32 blk)
{
	u32 *ct0, *ct1, *ct2, *ct3;
	u32 clra, clrb;

	clra=clrtab[(blk>>20)&15];
	clrb=clrtab[(blk>>16)&15];
	
	ct0=(u32 *)(iblk+0*ystr);
	ct1=(u32 *)(iblk+1*ystr);
	ct2=(u32 *)(iblk+2*ystr);
	ct3=(u32 *)(iblk+3*ystr);
	
	ct0[0]=(blk&0x0008)?clrb:clra;
	ct0[1]=(blk&0x0004)?clrb:clra;
	ct0[2]=(blk&0x0002)?clrb:clra;
	ct0[3]=(blk&0x0001)?clrb:clra;
	ct1[0]=(blk&0x0080)?clrb:clra;
	ct1[1]=(blk&0x0040)?clrb:clra;
	ct1[2]=(blk&0x0020)?clrb:clra;
	ct1[3]=(blk&0x0010)?clrb:clra;
	ct2[0]=(blk&0x0800)?clrb:clra;
	ct2[1]=(blk&0x0400)?clrb:clra;
	ct2[2]=(blk&0x0200)?clrb:clra;
	ct2[3]=(blk&0x0100)?clrb:clra;
	ct3[0]=(blk&0x8000)?clrb:clra;
	ct3[1]=(blk&0x4000)?clrb:clra;
	ct3[2]=(blk&0x2000)?clrb:clra;
	ct3[3]=(blk&0x1000)?clrb:clra;
}
#endif


#if 1
int clamp255(int clr)
{
	if(clr<0)return(0);
	if(clr>255)return(255);
	return(clr);
}

u32 vqdec_fromyuv(int cy, int cu, int cv)
{
	int cr, cg, cb;
	int cc;

//	cg=cy;
//	cg=(4*cy-(cu+cv-256))/2;
	cg=cy-(cu+cv-256)/2;
	cr=cg+(cv-128)*2;
	cb=cg+(cu-128)*2;
	cr=clamp255(cr);
	cg=clamp255(cg);
	cb=clamp255(cb);
	cc=0xFF000000|(cb<<16)|(cg<<8)|cr;
	return(cc);
}

u32 vqdec_clr6(int clr, int ctsp)
{
	int mod4[4]={0, 85, 170, 255};
//	int mod3[4]={64, 128, 192, 0};
//	int mod7u[8]={255, 192, 64, 128,  128, 192,  64, 128};
//	int mod7v[8]={255, 128, 64,  64,  192, 192, 128, 128};
	int mod7u[8]={255, 170, 85, 128,  128, 170,  85, 128};
	int mod7v[8]={255, 128, 85,  85,  170, 170, 128, 128};
	int cr, cg, cb;
	int cc, cy, cu, cv;

	switch(ctsp)
	{
	case 0:
		cr=mod4[(clr>>4)&3];
		cg=mod4[(clr>>2)&3];
		cb=mod4[(clr>>0)&3];
		cc=0xFF000000|(cb<<16)|(cg<<8)|cr;
		break;
	case 1:
//		cy=((clr&63)/9)*36;
//		cv=mod3[(clr/3)%3];
//		cu=mod3[(clr  )%3];

		cy=(clr&63)>>3;
		cy=(cy<<5)|(cy<<2)|(cy>>2);
//		cv=mod3[(clr/3)%3];
//		cu=mod3[(clr  )%3];
		cu=mod7u[clr&7];
		cv=mod7v[clr&7];
	
		cc=vqdec_fromyuv(cy, cu, cv);
		break;
	default:
		cc=0;
		break;
	}
	return(cc);
}

int vqenc_rgb2p64(int cr, int cg, int cb, int ctsp)
{
	u32 p0;
	int pr, pg, pb;
	int dr, dg, db, d, bd, bi;
	int i, j, k;

	bd=999999999; bi=0;
	for(i=0; i<64; i++)
	{
		p0=vqdec_clr6(i, ctsp);
		pr=(p0    )&255;
		pg=(p0>> 8)&255;
		pb=(p0>>16)&255;
		
		dr=cr-pr;
		dg=cg-pg;
		db=cb-pb;
//		d=dr*dr+dg*dg+db*db;
		d=dr*dr+(2*dg*dg)+(db*db/2);
		
		if(d<bd)
			{ bi=i; bd=d; }
	}
	return(bi);
}

#if 1
int cgfxb_dcstep[10*8]={
	 -15,   -7,  -3,  -1,  1,  3,   7,  15,
	 -23,  -11,  -5,  -2,  2,  5,  11,  23,
	 -31,  -15,  -7,  -3,  3,  7,  15,  31,
	 -47,  -23, -11,  -5,  5, 11,  23,  47,
	 -63,  -31, -15,  -7,  7, 15,  31,  63,
	 -95,  -47, -23, -11, 11, 23,  47,  95,
	-127,  -63, -31, -15, 15, 31,  63, 127,
	-191,  -95, -47, -23, 23, 47,  95, 191,
	-255, -127, -63, -31, 31, 63, 127, 255,
	-255, -191, -95, -47, 47, 95, 191, 255
};
#endif

//1, 3, 5, 7, 11, 15, 23, 31, 47, 63, 95, 127, 191, 255

#if 0
int cgfxb_dcstep[10*8]={
	 -11,   -5,  -3,  -1,  1,  3,   5,  11,
	 -13,   -6,  -4,  -2,  2,  4,   6,  13,
	 -15,   -7,  -5,  -3,  3,  5,   7,  15,
	 -23,  -11,  -7,  -5,  5,  7,  11,  23,
	 -31,  -15, -11,  -7,  7, 11,  15,  31,
	 -47,  -23, -15, -11, 11, 15,  23,  47,
	 -63,  -31, -23, -15, 15, 23,  31,  63,
	 -95,  -47, -31, -23, 23, 31,  47,  95,
	-127,  -63, -47, -31, 31, 47,  63, 127
	-191,  -95, -63, -47, 47, 63,  95, 191
};
#endif

int cgfxb_dcenext[10*8]={
	2, 1, 0, 0, 0, 0, 1, 2,
	3, 2, 1, 0, 0, 1, 2, 3,
	4, 3, 2, 1, 1, 2, 3, 4,
	5, 4, 3, 2, 2, 3, 4, 5,
	6, 5, 4, 3, 3, 4, 5, 6,
	7, 6, 5, 4, 4, 5, 6, 7,
	8, 7, 6, 5, 5, 6, 7, 8,
	9, 8, 7, 6, 6, 7, 8, 8,
	9, 9, 8, 7, 7, 8, 9, 9,
	9, 9, 9, 8, 8, 9, 9, 9
};


#if 1
int cgfxb_dcstepy[10*16]={
	 -15, -11,   -7,  -5,  -3, -2,  -1,   0,  0,  1, 2,  3,  5,   7, 11,  15,
	 -23, -15,  -11,  -7,  -5, -3,  -2,  -1,  1,  2, 3,  5,  7,  11, 15,  23,
	 -31, -23,  -15, -11,  -7, -5,  -3,  -2,  2,  3, 5,  7, 11,  15, 23,  31,
	 -47, -31,  -23, -15, -11, -7,  -5,  -3,  3,  5, 7, 11, 15,  23, 31,  47,
	 -63, -47,  -31, -23, -15,-11,  -7,  -5,  5,  7,11, 15, 23,  31, 47,  63,
	 -95, -63,  -47, -31, -23,-15, -11,  -7,  7, 11,15, 23, 31,  47, 63,  95,
	-127, -95,  -63, -47, -31,-23, -15, -11, 11, 15,23, 31, 47,  63, 95, 127,
	-191,-127,  -95, -63, -47,-31, -23, -15, 15, 23,31, 47, 63,  95,127, 191,
	-255,-191, -127, -95, -63,-47, -31, -23, 23, 31,47, 63, 95, 127,191, 255,
	-255,-223, -191,-127, -95,-63, -47, -31, 31, 47,63, 95,127, 191,223, 255
};
#endif

int cgfxb_dcenexty[10*16]={
	2,2,  1,1, 0,0, 0,0,  0,0, 0,0, 1,1, 2,2,
	3,3,  2,2, 1,1, 0,0,  0,0, 1,1, 2,2, 3,3,
	4,4,  3,3, 2,2, 1,1,  1,1, 2,2, 3,3, 4,4,
	5,5,  4,4, 3,3, 2,2,  2,2, 3,3, 4,4, 5,5,
	6,6,  5,5, 4,4, 3,3,  3,3, 4,4, 5,5, 6,6,
	7,7,  6,6, 5,5, 4,4,  4,4, 5,5, 6,6, 7,7,
	8,8,  7,7, 6,6, 5,5,  5,5, 6,6, 7,7, 8,8,
	9,9,  8,8, 7,7, 6,6,  6,6, 7,7, 8,8, 8,8,
	9,9,  9,9, 8,8, 7,7,  7,7, 8,8, 9,9, 9,9,
	9,9,  9,9, 9,9, 8,8,  8,8, 9,9, 9,9, 9,9
};


//	int uvmod8[8]={0, 32, 84, 116, 128, 140, 172, 224};
	int uvmod8[8]={0, 32, 74, 106, 128, 150, 182, 224};


int vqenc_dyuvd(int cy, int dy, int cu, int cv, u64 *rst)
{
	u64 sta, stb;

	int dcy, ddy, dcu, dcv;			//deltas
	int ecy, edy, ecu, ecv;			//exps
	int pcy, pdy, pcu, pcv;			//preds
	int dcy2, ddy2, dcu2, dcv2;		//deltas
	int pcy2, pdy2, pcu2, pcv2;		//preds
	int bdcy, bddy, bdcu, bdcv;		//deltas
	int edcy, eddy, edcu, edcv;		//delta error
	int ixa, ixb, ixc;
	int i, j, k;
	
//	cu=128;
//	cv=128;

	if(rst)
		sta=*rst;
	else
		sta=0;
	stb=sta;

	pcy=(sta    )&255;	pdy=(sta>> 8)&255;
	pcu=(sta>>16)&255;	pcv=(sta>>24)&255;
	ecy=(sta>>32)&15;	edy=(sta>>36)&15;
	ecu=(sta>>40)&15;	ecv=(sta>>44)&15;

	edcy=999999;	eddy=999999;
	edcu=999999;	edcv=999999;
	for(i=0; i<8; i++)
	{
//		pcy2=pcy+cgfxb_dcstep[ecy*8+i];
//		pdy2=pdy+cgfxb_dcstep[edy*8+i];
		pcu2=pcu+cgfxb_dcstep[ecu*8+i];
		pcv2=pcv+cgfxb_dcstep[ecv*8+i];
		
//		j=pcy2-cy; j=j^(j>>31);
//		if(j<edcy) { bdcy=i; edcy=j; }
//		j=pdy2-dy; j=j^(j>>31);
//		if(j<eddy) { bddy=i; eddy=j; }
		j=pcu2-cu; j=j^(j>>31);
		if(j<edcu) { bdcu=i; edcu=j; }
		j=pcv2-cv; j=j^(j>>31);
		if(j<edcv) { bdcv=i; edcv=j; }
	}

	for(i=0; i<16; i++)
	{
		pcy2=pcy+cgfxb_dcstepy[ecy*16+i];
		pdy2=pdy+cgfxb_dcstepy[edy*16+i];
		
		j=pcy2-cy; j=j^(j>>31);
		if(j<edcy) { bdcy=i; edcy=j; }
		j=pdy2-dy; j=j^(j>>31);
		if(j<eddy) { bddy=i; eddy=j; }
	}
	
	dcy=bdcy;	ddy=bddy;
	dcu=bdcu;	dcv=bdcv;

//	pcy=pcy+cgfxb_dcstep[ecy*8+dcy];
//	pdy=pdy+cgfxb_dcstep[edy*8+ddy];
	pcy=pcy+cgfxb_dcstepy[ecy*16+dcy];
	pdy=pdy+cgfxb_dcstepy[edy*16+ddy];
	pcu=pcu+cgfxb_dcstep[ecu*8+dcu];
	pcv=pcv+cgfxb_dcstep[ecv*8+dcv];
//	ecy=cgfxb_dcenext[ecy*8+dcy];
//	edy=cgfxb_dcenext[edy*8+ddy];
	ecy=cgfxb_dcenexty[ecy*16+dcy];
	edy=cgfxb_dcenexty[edy*16+ddy];
	ecu=cgfxb_dcenext[ecu*8+dcu];
	ecv=cgfxb_dcenext[ecv*8+dcv];

	pcy=clamp255(pcy);
	pdy=clamp255(pdy);
	pcu=clamp255(pcu);
	pcv=clamp255(pcv);

	i=pcy|(pdy<<8)|(pcu<<16)|(pcv<<24);
	j=(ecy<<0)|(edy<<4)|(ecu<<8)|(ecv<<12);
	stb=((u32)i)|(((u64)j)<<32);

//	ixa=0xE000|(dcy<<9)|(ddy<<6)|(dcu<<3)|(dcv<<0);
	ixa=0x8000|(dcy<<10)|(ddy<<6)|(dcu<<3)|(dcv<<0);

//	dcy2=cy>>5;	pcy2=(dcy2<<5)|(dcy2<<2)|(dcy2>>1);
//	ddy2=dy>>5;	pdy2=(ddy2<<5)|(ddy2<<2)|(ddy2>>1);
//	dcy2=cy>>4;	pcy2=(dcy2<<4)|dcy2;
//	ddy2=dy>>4;	pdy2=(ddy2<<4)|ddy2;

	dcy2=(cy+7)>>4;	pcy2=(dcy2<<4)|dcy2;
	ddy2=(dy+7)>>4;	pdy2=(ddy2<<4)|ddy2;
//	ddy2=(dy)>>4;	pdy2=(ddy2<<4)|ddy2;
	if(dcy2>15)dcy2=15;
	if(ddy2>15)ddy2=15;

//	dcu2=cu>>5;	pcu2=(dcu2<<5)|(dcu2<<2)|(dcu2>>1);
//	dcv2=cv>>5;	pcv2=(dcv2<<5)|(dcv2<<2)|(dcv2>>1);

	dcu2=(cu+15)>>5;	pcu2=dcu2<<5;
	dcv2=(cv+15)>>5;	pcv2=dcv2<<5;
	if(dcu2>7)dcu2=7;
	if(dcv2>7)dcv2=7;

//	dcu2=cu>>5;	pcu2=(dcu2<<5);
//	dcv2=cv>>5;	pcv2=(dcv2<<5);

//	dcu2=cu>>5;
//	dcv2=cv>>5;
//	pcu2=uvmod8[dcu2];
//	pcv2=uvmod8[dcv2];

	k=0;
	j=pcy2-cy; j=j^(j>>31);
	if(j<edcy) k++;
	j=pdy2-dy; j=j^(j>>31);
	if(j<eddy) k++;
	j=pcu2-cu; j=j^(j>>31);
	if(j<edcu) k++;
	j=pcv2-cv; j=j^(j>>31);
	if(j<edcv) k++;
	
//	if(k>2)
	if((k>1) || !sta)
//	if(0)
//	if(1)
//	if(!sta)
	{
//		ixa=0xF000|(dcy2<<9)|(ddy2<<6)|(dcu2<<3)|(dcv2<<0);
		ixa=0xC000|(dcy2<<10)|(ddy2<<6)|(dcu2<<3)|(dcv2<<0);

		k=5;
		i=pcy2|(pdy2<<8)|(pcu2<<16)|(pcv2<<24);
		j=(k<<0)|(k<<4)|(k<<8)|(k<<12);
		stb=((u32)i)|(((u64)j)<<32);
	}
	

	if(rst)
		*rst=stb;
	
	return(ixa);
}

int vqdec(byte *iblk, int ystr, u32 blk, u64 *rst)
{
	u32 *ct0, *ct1, *ct2, *ct3;
	u32 clra, clrb;
	u64 sta, stb;
	int dcy, ddy, dcu, dcv;		//deltas
	int ecy, edy, ecu, ecv;		//exps
	int pcy, pdy, pcu, pcv;		//preds
	int mcy, ncy;
	int cta, ctb, ctsp;
//	int cy, cu, cv;
//	int mcy, ncy, acy, dcy, cu, cv;
	int i, j, k;

	if(rst)
		sta=*rst;
	else
		sta=0;
	stb=sta;

	switch((blk>>30)&3)
	{
	case 1:
		ctsp=(blk>>28)&3;
		cta=(blk>>22)&63;
		ctb=(blk>>16)&63;
		clra=vqdec_clr6(cta, ctsp);
		clrb=vqdec_clr6(ctb, ctsp);
		break;

	case 2:
		pcy=(sta    )&255;	pdy=(sta>> 8)&255;
		pcu=(sta>>16)&255;	pcv=(sta>>24)&255;
		ecy=(sta>>32)&15;	edy=(sta>>36)&15;
		ecu=(sta>>40)&15;	ecv=(sta>>44)&15;

		dcy=(blk>>26)&15;	ddy=(blk>>22)&15;
		dcu=(blk>>19)&7;	dcv=(blk>>16)&7;
		
		pcy=pcy+cgfxb_dcstepy[ecy*16+dcy];
		pdy=pdy+cgfxb_dcstepy[edy*16+ddy];
		pcu=pcu+cgfxb_dcstep[ecu*8+dcu];
		pcv=pcv+cgfxb_dcstep[ecv*8+dcv];
		ecy=cgfxb_dcenexty[ecy*16+dcy];
		edy=cgfxb_dcenexty[edy*16+ddy];
		ecu=cgfxb_dcenext[ecu*8+dcu];
		ecv=cgfxb_dcenext[ecv*8+dcv];

		pcy=clamp255(pcy);
		pdy=clamp255(pdy);
		pcu=clamp255(pcu);
		pcv=clamp255(pcv);
		
		mcy=pcy-(pdy>>1);
		ncy=mcy+pdy;
		clra=vqdec_fromyuv(mcy, pcu, pcv);
		clrb=vqdec_fromyuv(ncy, pcu, pcv);

		i=pcy|(pdy<<8)|(pcu<<16)|(pcv<<24);
		j=(ecy<<0)|(edy<<4)|(ecu<<8)|(ecv<<12);
		stb=((u32)i)|(((u64)j)<<32);

		break;

	case 3:
		pcy=(sta    )&255;	pdy=(sta>> 8)&255;
		pcu=(sta>>16)&255;	pcv=(sta>>24)&255;
		ecy=(sta>>32)&15;	edy=(sta>>36)&15;
		ecu=(sta>>40)&15;	ecv=(sta>>44)&15;

		dcy=(blk>>26)&15;	ddy=(blk>>22)&15;
		dcu=(blk>>19)&7;	dcv=(blk>>16)&7;
		
		pcy=(dcy<<4)|dcy;
		pdy=(ddy<<4)|ddy;
//		pcu=(dcu<<5)|(dcu<<2)|(dcu>>1);
//		pcv=(dcv<<5)|(dcv<<2)|(dcv>>1);
		pcu=dcu<<5;
		pcv=dcv<<5;

		k=5;
		ecy=k;	edy=k;	ecu=k;	ecv=k;

		mcy=pcy-(pdy>>1);
		ncy=mcy+pdy;
		clra=vqdec_fromyuv(mcy, pcu, pcv);
		clrb=vqdec_fromyuv(ncy, pcu, pcv);

		i=pcy|(pdy<<8)|(pcu<<16)|(pcv<<24);
		j=(ecy<<0)|(edy<<4)|(ecu<<8)|(ecv<<12);
		stb=((u32)i)|(((u64)j)<<32);

		break;

#if 0
	case 3:
		pcy=(sta    )&255;	pdy=(sta>> 8)&255;
		pcu=(sta>>16)&255;	pcv=(sta>>24)&255;
		ecy=(sta>>32)&15;	edy=(sta>>36)&15;
		ecu=(sta>>40)&15;	ecv=(sta>>44)&15;

		ctsp=(blk>>28)&3;
		dcy=(blk>>25)&7;	ddy=(blk>>22)&7;
		dcu=(blk>>19)&7;	dcv=(blk>>16)&7;
		
		if(ctsp==2)
		{
			pcy=pcy+cgfxb_dcstep[ecy*8+dcy];
			pdy=pdy+cgfxb_dcstep[edy*8+ddy];
			pcu=pcu+cgfxb_dcstep[ecu*8+dcu];
			pcv=pcv+cgfxb_dcstep[ecv*8+dcv];
			ecy=cgfxb_dcenext[ecy*8+dcy];
			edy=cgfxb_dcenext[edy*8+ddy];
			ecu=cgfxb_dcenext[ecu*8+dcu];
			ecv=cgfxb_dcenext[ecv*8+dcv];

			pcy=clamp255(pcy);
			pdy=clamp255(pdy);
			pcu=clamp255(pcu);
			pcv=clamp255(pcv);
			
			mcy=pcy-(pdy>>1);
			ncy=mcy+pdy;
			clra=vqdec_fromyuv(mcy, pcu, pcv);
			clrb=vqdec_fromyuv(ncy, pcu, pcv);

			i=pcy|(pdy<<8)|(pcu<<16)|(pcv<<24);
			j=(ecy<<0)|(edy<<4)|(ecu<<8)|(ecv<<12);
			stb=((u32)i)|(((u64)j)<<32);
		}

		if(ctsp==3)
		{
			pcy=(dcy<<5)|(dcy<<2)|(dcy>>1);
			pdy=(ddy<<5)|(ddy<<2)|(ddy>>1);
			pcu=(dcu<<5)|(dcu<<2)|(dcu>>1);
			pcv=(dcv<<5)|(dcv<<2)|(dcv>>1);
//			pcu=(dcu<<5);
//			pcv=(dcv<<5);
//			pcu=uvmod8[dcu];
//			pcv=uvmod8[dcv];

//			ecy=6;	edy=6;	ecu=6;	ecv=6;
			k=5;
			ecy=k;	edy=k;	ecu=k;	ecv=k;

			mcy=pcy-(pdy>>1);
			ncy=mcy+pdy;
			clra=vqdec_fromyuv(mcy, pcu, pcv);
			clrb=vqdec_fromyuv(ncy, pcu, pcv);

			i=pcy|(pdy<<8)|(pcu<<16)|(pcv<<24);
			j=(ecy<<0)|(edy<<4)|(ecu<<8)|(ecv<<12);
			stb=((u32)i)|(((u64)j)<<32);
		}	

#if 0
		acy=(blk>>26)&15;
		dcy=(blk>>22)&15;
		cu=(blk>>19)&7;
		cv=(blk>>16)&7;
		acy=(acy<<4)|acy;
		dcy=(dcy<<4)|dcy;
		mcy=acy-(dcy>>1);
		ncy=mcy+dcy;
		cu=uvmod8[cu];
		cv=uvmod8[cv];
//		cu=cu<<5;
//		cv=cv<<5;
//		cu=(cu<<5)|(cu<<2);
//		cv=(cv<<5)|(cv<<2);
		clra=vqdec_fromyuv(mcy, cu, cv);
		clrb=vqdec_fromyuv(ncy, cu, cv);
#endif

		break;
#endif

	}

	if(rst)
		*rst=stb;

	ct0=(u32 *)(iblk+0*ystr);
	ct1=(u32 *)(iblk+1*ystr);
	ct2=(u32 *)(iblk+2*ystr);
	ct3=(u32 *)(iblk+3*ystr);

	ct0[0]=(blk&0x0008)?clrb:clra;
	ct0[1]=(blk&0x0004)?clrb:clra;
	ct0[2]=(blk&0x0002)?clrb:clra;
	ct0[3]=(blk&0x0001)?clrb:clra;
	ct1[0]=(blk&0x0080)?clrb:clra;
	ct1[1]=(blk&0x0040)?clrb:clra;
	ct1[2]=(blk&0x0020)?clrb:clra;
	ct1[3]=(blk&0x0010)?clrb:clra;
	ct2[0]=(blk&0x0800)?clrb:clra;
	ct2[1]=(blk&0x0400)?clrb:clra;
	ct2[2]=(blk&0x0200)?clrb:clra;
	ct2[3]=(blk&0x0100)?clrb:clra;
	ct3[0]=(blk&0x8000)?clrb:clra;
	ct3[1]=(blk&0x4000)?clrb:clra;
	ct3[2]=(blk&0x2000)?clrb:clra;
	ct3[3]=(blk&0x1000)?clrb:clra;
}
#endif

char *emit_chesc(char *t, int v)
{
	if(v=='\"')
	{
		*t++='w';
		return(t);
	}

	if(v=='\\')
	{
		*t++='x';
		return(t);
	}

	*t++=v;
	return(t);
}

int main(int argc, char *argv[])
{
	byte *ibuf, *dbuf;
	char *obuf;
	u32 blk;
	char *ifn, *ofn;
	char *t, *t0;
	int xs, ys, cxs, cys;
	int ystr, x, y;
	double e;
	int i, j, k, l;
	u64 dste, dstd;
	
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

	cxs=xs/4;
	cys=ys/4;
	ystr=xs*4;

	dbuf=malloc(xs*ys*4);

#if 1
	obuf=malloc(cxs*cys*8);
	t=obuf;
	
#if 0
	*t++='\n';
	*t++='\n';
#endif
	
	dste=0;
	dstd=0;
	
	for(i=0; i<cys; i++)
	{
#if 0
		t0=t;
		*t++='\"';
//		*t++='\x1B';
		*t++='\\';	*t++='x';
		*t++='1';	*t++='B';
		*t++='!';
#endif

		dste=0;
		dstd=0;

		for(j=0; j<cxs; j++)
		{
			k=((((cys-i-1)*4)*xs)+(j*4))*4;

//			k=(((i*4)*xs)+(j*4))*4;
			vqenc(ibuf+k, ystr, &blk, &dste);
			vqdec(dbuf+k, ystr, blk, &dstd);
			
			((u32 *)obuf)[i*cxs+j]=blk;

#if 0
			blk=blk&0xFFFFFF;
			if((j+1)<cxs)
				blk|=0x1000000;
//			t=emit_chesc(t, (blk>>21)&127);
//			t=emit_chesc(t, (blk>>14)&127);
//			t=emit_chesc(t, (blk>> 7)&127);
//			t=emit_chesc(t, (blk    )&127);

			t=emit_chesc(t, '!'+(blk/614125)%85);
			t=emit_chesc(t, '!'+(blk/  7225)%85);
			t=emit_chesc(t, '!'+(blk/    85)%85);
			t=emit_chesc(t, '!'+(blk       )%85);
			
			if((t-t0)>=72)
			{
				*t++='\"';
				*t++='\n';
				t0=t;
				*t++='\"';
			}
#endif
		}

#if 0		
		*t++='\\';
		*t++='n';
		*t++='\"';
		*t++='\n';
#endif
	}

//	*t++=0;
//	storefile(ofn, obuf, t-obuf);

	if(ofn)
	{
		storefile(ofn, obuf, cxs*cys*4);
	}
#endif

	e=vqierr(ibuf, dbuf, xs, ys);
	printf("err=%f\n", e);

	BTIC1H_Img_SaveTGA("tga2asc0.tga", dbuf, xs, ys);
}
