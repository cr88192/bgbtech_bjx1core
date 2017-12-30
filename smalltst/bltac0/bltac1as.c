/*
16 samples in 32 bits:
  [31:24]=max-min
  [23:16]=(max+min)/2
  [15: 0]=sample bits

Here, the block is unpacked into a high and low value, and each bit selects either max(1) or min(0).
This is tuned more for decoder simplicity than goodness.


16 samples in 64 bits:
  [63:54]=predictor sample (high 10 bits of 16-bit sample)
  [53:48]=step bits
  [47: 0]=sample bits (16x 3b)

Each sample is a delta relative to a predictor scaled according to the a step.
The step is adjusted based on the sample bits, and is essentially a 4.2 microfloat.

Each sample has 3 bits:
  2: sign
  1: diff+=step>>1
  0: diff+=step>>2

*/


#include "tfau_multi.c"

// #define TFAU_TRANSZ	256
// #define TFAU_TRANSZ	128
#define TFAU_TRANSZ	64

// #define TFAU_NBAND	32
#define TFAU_NBAND	16
// #define TFAU_NBAND	8
#define TFAU_BANSZ	(TFAU_TRANSZ/TFAU_NBAND)

int clamp255(int clr)
{
	if(clr<0)return(0);
	if(clr>255)return(255);
	return(clr);
}

int clamp(int clr, int min, int max)
{
	if(clr<min)return(min);
	if(clr>max)return(max);
	return(clr);
}

#if 1
int bltac_encblock2(s16 *iblk, u64 *oblk, int str)
{
	static int la=0;
	static int ls=0;
	static s16 *lpn=NULL;
	static s16 *lpc=NULL;
	u64 blk;
	int m, n, a, b, c, d, s;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;
	
//	if(iblk==lpn)
	if((iblk==lpn) || (iblk==lpc))
	{
//		a=la;
		la=(iblk[0*str]+la)/2;
		s0=(la&0xFFC0)|ls;
		s1=ls;
	}else
	{
		la=(iblk[0*str]+iblk[1*str])/2;
		ls=8;
		s0=(la&0xFFC0)|ls;
		s1=ls;
	}

	a=(s16)(s0&0xFFC0);
	s=s0&63;
//	blk=((u64)s0)<<48;
	blk=s0;

	for(i=0; i<16; i++)
	{
//		k=iblk[i];
//		k=(s16)(iblk[i]&0xFFC0);
		k=(iblk[i*str]+31)&(~63);
		c0=k-a;
		c1=(c0>=0)?c0:(-c0);

		d=(4|(s&3))<<(s>>2);
		b=(4*c1)/d;
		b=clamp(b, 0, 3);
		if(c0<0)b|=4;

		d1=(d*((b&3)*2+1))/8;
		if(b&4)d1=-d1;
		if(((a+d1)>32767) || ((a+d1)<(-32768)))
		{
			if(b&3)		b--;
			else		b^=4;
		}

		s1=s+((b&3)==3)?3:((b&3)-1);
		if(s1<0)
			{ b|=1; }
		while((s1>63) && (b&3))
			{ b--; s1=s+((b&3)==3)?3:((b&3)-1); }

		if(!i && ((b&3)==3))
			b&=~1;

//		blk|=((u64)b)<<(i*3);
		blk|=((u64)b)<<((i*3)+16);

//		d1=d>>3;
//		if(b&1)d1+=d>>2;
//		if(b&2)d1+=d>>1;
		d1=(d*((b&3)*2+1))/8;
		if(b&4)d1=-d1;
		
		s+=((b&3)==3)?3:((b&3)-1);
		a+=d1;
		a=clamp(a, -32768, 32767);
		s=clamp(s, 0, 63);
	}
	la=a;
	ls=s;
	lpc=iblk;
	lpn=iblk+16*str;
	
	*oblk=blk;
	return(0);
}
	
int bltac_decblock2(u64 blk, s16 *oblk, int str)
{
	static int la;
	int m, n, a, b, c, d, s;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;
	
//	s0=(s16)(blk>>48);
	s0=(s16)(blk);
	a=(s16)(s0&0xFFC0);
	s=s0&63;
	
//	if(a==(la&0xFFC0))
//		a|=la&63;
	
	for(i=0; i<16; i++)
	{
//		b=(blk>>(i*3))&7;
		b=(blk>>((i*3)+16))&7;
		
//		b=(b&4)|1;
		
		d=(4|(s&3))<<(s>>2);
//		d1=d>>3;
//		if(b&1)d1+=d>>2;
//		if(b&2)d1+=d>>1;
		d1=(d*((b&3)*2+1))/8;
		if(b&4)d1=-d1;

		s+=((b&3)==3)?3:((b&3)-1);
		a+=d1;
//		a=clamp(a, -32768, 32767);
//		s=clamp(s, 0, 63);
		oblk[i*str]=a;
	}
	la=a;
	return(0);
}
#endif


int bltac_encblock2js(s16 *iblk, u64 *oblk)
{
	static int la=0;
	static int ls=0;
	static int lsa=0;
	static int lss=0;
	static s16 *lpn=NULL;
	static s16 *lpc=NULL;
	int cblk[16], sblk[16];
	u64 blk;
	int m, n, a, b, c, d, s;
	int sa, ss;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;
	
	for(i=0; i<16; i++)
	{
		a=iblk[i*2+0];
		b=iblk[i*2+1];
		c=(a+b)/2;
		d=a-b;
		cblk[i]=c;
		sblk[i]=d;
	}

	for(i=0; i<4; i++)
	{
		a=(sblk[i*4+0]+sblk[i*4+1]+sblk[i*4+2]+sblk[i*4+3])/4;
		sblk[i]=a;
	}
	
//	if(iblk==lpn)
	if((iblk==lpn) || (iblk==lpc))
//	if(1)
	{
//		a=la;
		la=(cblk[0]+la)/2;
		sa=(sblk[0]+lsa)/2;
		
//		la=clamp(la+0x01FF, -32768, 32767);
//		sa=clamp(sa+0x01FF, -32768, 32767);
		
		ss=(lss>>1)-12;
		ss=clamp(ss, 0, 15);
		s0=(la&0xFC00)|ls|((sa&0xFC00)<<8)|(ss<<6)|0x00030000;
		s1=ls;
	}else
	{
		la=(cblk[0]+cblk[1])/2;
		sa=(sblk[0]+sblk[1])/2;
		ls=32;
//		s0=(la&0xFFC0)|ls;
		ss=0;
		ss=clamp(ss, 0, 15);
//		s0=(la&0xFFC0)|ls|((sa&0xF000)<<8)|(ss<<16);
		s0=(la&0xFC00)|ls|((sa&0xFC00)<<8)|(ss<<6)|0x00030000;
		s1=ls;
	}

//	a=(s16)(s0&0xFFC0);
	a=(s16)(s0&0xFC00);
	s=s0&63;
//	blk=((u64)s0)<<48;
	blk=s0;
	for(i=0; i<16; i++)
	{
//		k=iblk[i];
//		k=(s16)(iblk[i]&0xFFC0);
		k=(cblk[i]+31)&(~63);
		c0=k-a;
		c1=(c0>=0)?c0:(-c0);

		d=(4|(s&3))<<(s>>2);
		b=(4*c1)/d;
		b=clamp(b, 0, 3);
		if(c0<0)b|=4;

//		d1=(d*((b&3)*2+1))/8;
//		if(b&4)d1=-d1;
//		if(((a+d1)>32767) || ((a+d1)<(-32768)))
//		{
//			if(b&3)		b--;
//			else		b^=4;
//		}

		b=b>>1;

		d1=(d*((b&1)*4+1))/8;
		if(b&2)d1=-d1;
		if(((a+d1)>32767) || ((a+d1)<(-32768)))
		{
			if(b&1)		b--;
			else		b^=2;
		}

		s1=s+((b&1)*2-1);
		if(s1<0)
			{ b|=1; }
//		while((s1>63) && (b&1))
//			{ b--; s1=s+((b&1)*2-1); }
		blk|=((u64)b)<<((i*2)+32);

		d1=(d*((b&1)*4+1))/8;
		if(b&2)d1=-d1;
		
		s=s+((b&1)*2-1);
		a+=d1;
//		a=clamp(a, -32768, 32767);
		s=clamp(s, 0, 63);
	}

	la=a;
	ls=s;
	lpc=iblk;
	lpn=iblk+16*2;


	a=(s16)((s0>>8)&0xFC00);
	s=((((s0>>6)&15)+12)<<1);
//	blk=s0;
	for(i=0; i<4; i++)
	{
		k=sblk[i];
		c0=k-a;
		c1=(c0>=0)?c0:(-c0);

		d=(4|(s&3))<<(s>>2);
		b=(4*c1)/d;
		b=clamp(b, 0, 3);
		if(c0<0)b|=4;

//		d1=(d*((b&3)*2+1))/8;
//		if(b&4)d1=-d1;
//		if(((a+d1)>32767) || ((a+d1)<(-32768)))
//		{
//			if(b&3)		b--;
//			else		b^=4;
//		}

		b=b>>1;

		d1=(d*((b&1)*4+1))/8;
		if(b&2)d1=-d1;
		if(((a+d1)>32767) || ((a+d1)<(-32768)))
		{
			if(b&1)		b--;
			else		b^=2;
		}

		s1=s+((b&1)*2-1);
//		if(s1<0)
		if(s1<24)
			{ b|=1; }
//		while((s1>63) && (b&1))
//			{ b--; s1=s+((b&1)*2-1); }

		blk|=((u64)b)<<((i*2)+24);

		d1=(d*((b&1)*4+1))/8;
		if(b&2)d1=-d1;
		
		s=s+((b&1)*2-1);
		a+=d1;
//		a=clamp(a, -32768, 32767);
		s=clamp(s, 0, 63);
	}
	
	lsa=a;
	lss=s;
	
	*oblk=blk;
	return(0);
}
	
int bltac_decblock2js(u64 blk, s16 *oblk)
{
	int cblk[16], sblk[4];
	int m, n, a, a0, a1, b, c, d, s;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;
	
	s0=(s16)(blk);
//	a=(s16)(s0&0xFFC0);
	a0=(s16)(s0&0xFC00);
	a1=(s16)((s0>>8)&0xFC00);
//	a1=(s16)((s0&0x03C0)<<6);
	s=s0&63;
	
	a=a0;
	for(i=0; i<16; i++)
	{
//		b=(blk>>((i*3)+16))&7;
		b=(blk>>((i*2)+32))&3;
		b=b<<1;
		
		d=(4|(s&3))<<(s>>2);
		d1=(d*((b&3)*2+1))/8;
		if(b&4)d1=-d1;

		s+=(b&3)-1;
		a+=d1;
		cblk[i]=a;
	}

	a=a1;
//	s=(blk>>18)&63;
	s=((((s0>>6)&15)+12)<<1);
	for(i=0; i<4; i++)
	{
		b=(blk>>((i*2)+24))&3;
		b=b<<1;
		
		d=(4|(s&3))<<(s>>2);
		d1=(d*((b&3)*2+1))/8;
		if(b&4)d1=-d1;

		s+=(b&3)-1;
		a+=d1;
		sblk[i]=a;
	}

	for(i=0; i<16; i++)
	{
		a=cblk[i];
		b=sblk[i>>2];

//		b=0;

		m=a-(b>>1);
		n=m+b;
		oblk[i*2+0]=n;
		oblk[i*2+1]=m;
	}

	return(0);
}

int bltac_decblock3(u64 blk, s16 *oblk, int str);
int bltac_decblock3s(u64 blk, s16 *oblk);

int bltac_encblock3_63(s16 *iblk, u64 *oblk, int str)
{
	u64 blk;
	int m, n, a, b, c, d, s;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;

//	blk=(63LL<<48);
	blk=63;
	for(i=0; i<16; i++)
	{
		k=iblk[i*str];
		b=(k+32768)>>13;
//		blk|=((u64)b)<<(i*3);
		blk|=((u64)b)<<((i*3)+16);
	}

	*oblk=blk;
	return(0);
}

int bltac_encblock3_6n(s16 *iblk, u64 *oblk, int str, int bt)
{
	u64 blk;
	int m, n, a, b, c, d, s;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;

	m=65536; n=-65536;
	for(i=0; i<16; i++)
	{
		k=iblk[i*str];
		if(k<m)m=k;
		if(k>n)n=k;
	}

	c=(m+n)/2;
	d=n-m;
	
	switch(bt)
	{
	case 0:
//		c=(c>>11)+16; d=(d>>11);
		c0=(c>>11)+16;
		c=((c+1023)>>11)+16; d=((d+1023)>>11);
		c=clamp(c, 0, 31);
		d=clamp(d, 1, 31);
		s0=62|(c<<6)|(d<<11);
		c1=((c-16)<<11); d1=(d<<11);
		break;
	case 1:
//		c=(c>>10)+32; d=(d>>10);
		c0=(c>>10)+32;
		c=((c+511)>>10)+32; d=((d+511)>>10);
		c=clamp(c, 0, 63);
		d=clamp(d, 1, 15);
		s0=61|(c<<6)|(d<<12);
		c1=((c-32)<<10); d1=(d<<10);
		break;
	case 2:
//		c=(c>>9)+64; d=(d>>9);
		c0=(c>>9)+64;
		c=((c+255)>>9)+64; d=((d+255)>>9);
		c=clamp(c, 0, 127);
		d=clamp(d, 1, 7);
		s0=60|(c<<6)|(d<<13);
		c1=((c-64)<<9); d1=(d<<9);
		break;
	case 3:
//		c=(c>>9)+64; d=(d>>9);
		c0=(c>>8)+128;
		c=((c+127)>>8)+128; d=((d+127)>>8);
		c=clamp(c, 0, 255);
		d=clamp(d, 1, 3);
		s0=59|(c<<6)|(d<<14);
		c1=((c-128)<<8); d1=(d<<8);
		break;
	}

	m=c1-(d1>>1);		n=m+d1;

	while((m<(-32768)) || (n>32767))
	{
		if(c0!=c)
			{ c=c0; }
		else if(d>0)
			{ d--; }
		else
			{ break; }

		switch(bt)
		{
		case 0:
			s0=62|(c<<6)|(d<<11);
			c1=((c-16)<<11); d1=(d<<11);
			break;
		case 1:
			s0=61|(c<<6)|(d<<12);
			c1=((c-32)<<10); d1=(d<<10);
			break;
		case 2:
			s0=60|(c<<6)|(d<<13);
			c1=((c-64)<<9); d1=(d<<9);
			break;
		case 3:
			s0=59|(c<<6)|(d<<14);
			c1=((c-128)<<8); d1=(d<<8);
			break;
		}
		m=c1-(d1>>1);		n=m+d1;
	}

//	m=c-(d>>1);			n=m+d;

	c=(m+n)/2;
	d=n-m;

	
//	l=(7*4096)/(n-c+1);
	l=(4.75*4096)/(n-c+1);

//	blk=(((u64)s0)<<48);
	blk=s0;
	for(i=0; i<16; i++)
	{
		k=iblk[i*str];
		
		b=(((k-c)*l)>>12)+4;
		b=clamp(b, 0, 7);
		
//		b=(k+32768)>>13;
//		blk|=((u64)b)<<(i*3);
		blk|=((u64)b)<<((i*3)+16);
	}

	*oblk=blk;
	return(0);
}

int bltac_encblock3_err(s16 *iblk, s16 *oblk, int istr, int ostr)
{
	double e;
	int i, j, k;
	
	e=0;
	for(i=0; i<16; i++)
	{
		j=iblk[i*istr]-oblk[i*ostr];
		e+=((double)j)*j;
	}

	for(i=1; i<16; i++)
	{
		j=(iblk[i*istr]-iblk[(i-1)*istr])-
			(oblk[i*ostr]-oblk[(i-1)*ostr]);
		e+=((double)j)*j;
	}

	return(sqrt(e/16));
}

int bltac_encblock3s_err(s16 *iblk, s16 *oblk)
{
	int el, er;
	el=bltac_encblock3_err(iblk+0, oblk+0, 2, 2);
	er=bltac_encblock3_err(iblk+1, oblk+1, 2, 2);
	return(el+er);
}

int bltac_encblock3(s16 *iblk, u64 *oblk, int str)
{
	s16 tblk[16];
	u64 blk0, blk1;
	u64 blk2, blk3;
	u64 blk;
	int e, e0, e1, e2, e3;
	int i, j, k;
	
	bltac_encblock2(iblk, &blk0, str);
	bltac_encblock3_63(iblk, &blk1, str);

	blk2=0; e2=999999;
	for(i=0; i<3; i++)
	{
		bltac_encblock3_6n(iblk, &blk3, str, i);

		bltac_decblock3(blk3, tblk, 1);
		e3=bltac_encblock3_err(iblk, tblk, str, 1);
		if(e3<e2)
			{ blk2=blk3; e2=e3; }
	}

//	bltac_encblock2js(iblk, &blk3);
	
	bltac_decblock3(blk0, tblk, 1);
	e0=bltac_encblock3_err(iblk, tblk, str, 1);
	bltac_decblock3(blk1, tblk, 1);
	e1=bltac_encblock3_err(iblk, tblk, str, 1);

//	bltac_decblock3(blk3, tblk, 1);
//	e3=bltac_encblock3_err(iblk, tblk, str, 1);
	
	blk=blk0; e=e0;
	if(e1<e) { blk=blk1; e=e1; }
	if(e2<e) { blk=blk2; e=e2; }
	
//	blk=blk0;
//	blk=blk1;
//	blk=blk2;
	
	*oblk=blk;

	return(0);
}

int bltac_decblock3(u64 blk, s16 *oblk, int str)
{
	int m, n, a, b, c, d, s;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;
	
//	s0=(s16)(blk>>48);
	s0=(s16)(blk);
	a=(s16)(s0&0xFFC0);
	s=s0&63;
	
	if(s<58)
	{
		bltac_decblock2(blk, oblk, str);
		return(0);
	}
	
	switch(s)
	{
	case 63:
//		m=-32768;
//		n= 32767;
		c=0; d=65535;
		break;
	case 62:
		c=((s0>> 6)&31)-16;		d=(s0>>11)&31;
		c=(s16)(c<<11);			d=(u16)(d<<11);
		break;
	case 61:
		c=((s0>> 6)&63)-32;		d=(s0>>12)&15;
		c=(s16)(c<<10);			d=(u16)(d<<10);
		break;
	case 60:
		c=((s0>> 6)&127)-64;	d=(s0>>13)&7;
		c=(s16)(c<<9);			d=(u16)(d<<9);
		break;
	case 59:
		c=((s0>> 6)&255)-128;	d=(s0>>14)&3;
		c=(s16)(c<<8);			d=(u16)(d<<8);
		break;
	}

	m=c-(d>>1);
	n=m+d;

	for(i=0; i<16; i++)
	{
//		b=(blk>>(i*3))&7;
		b=(blk>>((i*3)+16))&7;
		a=((m*(15-b*2))+(n*(1+b*2)))/16;
		oblk[i*str]=a;
	}
	return(0);
}


int bltac_encblock3js_6n(s16 *iblk, u64 *oblk, int bt)
{
	int cblk[16], sblk[16];
	u64 blk;
	int m, n, a, b, c, d, s;
	int n2, m2, c0, c1, d1;
	int ms, ns, cs, ds, cs1, ds1;
	int s0, s1, ss0;
	int i, j, k, l;

	for(i=0; i<16; i++)
	{
		n=iblk[i*2+0];
		m=iblk[i*2+1];
		c=(m+n)/2;
		d=n-m;
		cblk[i]=c;
		sblk[i]=d;
	}

	for(i=0; i<4; i++)
	{
		a=(sblk[i*4+0]+sblk[i*4+1]+sblk[i*4+2]+sblk[i*4+3])/4;
		sblk[i]=a;
	}

	m=65536; n=-65536;
	for(i=0; i<16; i++)
	{
		k=cblk[i];
		if(k<m)m=k;
		if(k>n)n=k;
	}

	ms=65536; ns=-65536;
	for(i=0; i<4; i++)
	{
		k=sblk[i];
		if(k<ms)ms=k;
		if(k>ns)ns=k;
	}

	c=(m+n)/2;
	d=n-m;

	cs=(ms+ns)/2;
	ds=ns-ms;
	
	switch(bt)
	{
	case 0:
//		c=(c>>11)+16; d=(d>>11);
		c0=(c>>11)+16;
		c=((c+1023)>>11)+16; d=((d+1023)>>11);
		c=clamp(c, 0, 31);
		d=clamp(d, 1, 31);
		s0=59|(c<<6)|(d<<11);
		c1=((c-16)<<11); d1=(d<<11);

#if 0
		cs=(cs>>11)+8;
		ds=(ds>>11);
		cs=clamp(cs, 0, 15);
		ds=clamp(ds, 0, 15);
		cs1=(cs-8)<<11;
		ds1=ds<<11;
		ss0=(cs<<16)|(ds<<20);
#endif
		break;
	case 1:
//		c=(c>>10)+32; d=(d>>10);
		c0=(c>>10)+32;
		c=((c+511)>>10)+32; d=((d+511)>>10);
		c=clamp(c, 0, 63);
		d=clamp(d, 1, 15);
		s0=58|(c<<6)|(d<<12);
		c1=((c-32)<<10); d1=(d<<10);

#if 0
		cs=(cs>>11)+16;
		ds=(ds>>11);
		cs=clamp(cs, 0, 31);
		ds=clamp(ds, 0, 7);
		cs1=(cs-16)<<11;
		ds1=ds<<11;
		ss0=(cs<<16)|(ds<<21);
#endif
		break;
	}

#if 1
#if 0
	cs=(cs>>11)+8;
	ds=(ds>>11);
	cs=clamp(cs, 0, 15);
	ds=clamp(ds, 0, 15);
	cs1=(cs-8)<<11;
	ds1=ds<<11;
	ss0=(cs<<16)|(ds<<20);
#else
	cs=(cs>>11)+16;
	ds=(ds>>11);
	cs=clamp(cs, 0, 31);
	ds=clamp(ds, 0, 7);
	cs1=(cs-16)<<11;
	ds1=ds<<11;
	ss0=(cs<<16)|(ds<<21);
#endif
#endif

	ms=cs1-(ds1>>1);	ns=ms+ds1;

	m=c1-(d1>>1);		n=m+d1;

	while((ms<(-32768)) || (ns>32767))
	{
		if(ds>0)
			{ ds--; }
		else
			{ break; }
		cs1=(cs-8)<<11;		ds1=ds<<11;
		ms=cs1-(ds1>>1);	ns=ms+ds1;
	}

	while((m<(-32768)) || (n>32767))
	{
		if(c0!=c)
			{ c=c0; }
		else if(d>0)
			{ d--; }
		else
			{ break; }

		switch(bt)
		{
		case 0:
			s0=59|(c<<6)|(d<<11);
			c1=((c-16)<<11); d1=(d<<11);
			break;
		case 1:
			s0=58|(c<<6)|(d<<12);
			c1=((c-32)<<10); d1=(d<<10);
			break;
		}
		m=c1-(d1>>1);		n=m+d1;
	}

//	s0|=(cs<<16)|(ds<<20);
//	s0|=(cs<<16)|(ds<<21);
	s0|=ss0;

//	m=c-(d>>1);			n=m+d;

	c=(m+n)/2;
	d=n-m;

	cs=(ms+ns)/2;
	ds=ns-ms;

//	l=(7*4096)/(n-c+1);
	l=(2.375*4096)/(n-c+1);

//	blk=(((u64)s0)<<48);
	blk=s0;
	for(i=0; i<16; i++)
	{
		k=cblk[i];		
		b=(((k-c)*l)>>12)+2;
		b=clamp(b, 0, 3);
		blk|=((u64)b)<<((i*2)+32);
	}

	l=(2.375*4096)/(ns-cs+1);
	for(i=0; i<4; i++)
	{
		k=sblk[i];		
		b=(((k-cs)*l)>>12)+2;
		b=clamp(b, 0, 3);
		blk|=((u64)b)<<((i*2)+24);
	}

	*oblk=blk;
	return(0);
}

int bltac_decblock3js(u64 blk, s16 *oblk)
{
	int cblk[16], sblk[4];
	int m, n, a, b, c, d, s;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;
	
//	s0=(s16)(blk>>48);
	s0=(s16)(blk);
	a=(s16)(s0&0xFFC0);
	s=s0&63;
	
	switch(s)
	{
	case 59:
		c=((s0>> 6)&31)-16;		d=(s0>>11)&31;
		c=(s16)(c<<11);			d=(u16)(d<<11);

//		c1=((blk>>16)&15)-8;	d1=((blk>>20)&15);
		c1=((blk>>16)&31)-16;	d1=((blk>>21)&7);
		c1=(s16)(c1<<11);		d1=(u16)(d1<<11);
		break;
	case 58:
		c=((s0>> 6)&63)-32;		d=(s0>>12)&15;
		c=(s16)(c<<10);			d=(u16)(d<<10);

		c1=((blk>>16)&31)-16;	d1=((blk>>21)&7);
		c1=(s16)(c1<<11);		d1=(u16)(d1<<11);
		break;
	}

#if 0
//	c1=((blk>>16)&15)-8;	d1=((blk>>20)&15);
	c1=((blk>>16)&31)-16;	d1=((blk>>21)&7);
//	c1=(s16)(c1<<12);		d1=(u16)(d1<<12);
	c1=(s16)(c1<<11);		d1=(u16)(d1<<11);
//	c1=(s16)(c1<<10);		d1=(u16)(d1<<10);
#endif

	m=c-(d>>1);
	n=m+d;

	m2=c1-(d1>>1);
	n2=m2+d1;


	for(i=0; i<16; i++)
	{
//		b=(blk>>(i*3))&7;
//		b=(blk>>((i*3)+16))&7;
		b=(blk>>((i*2)+32))&3;
		a=((m*(15-b*5))+(n*(1+b*5)))/16;
		cblk[i]=a;
	}

	for(i=0; i<4; i++)
	{
		b=(blk>>((i*2)+24))&3;
		a=((m2*(15-b*5))+(n2*(1+b*5)))/16;
		sblk[i]=a;
	}

	for(i=0; i<16; i++)
	{
		a=cblk[i];
		b=sblk[i>>2];
//		b=0;
		m=a-(b>>1);
		n=m+b;
		
//		m=clamp(m, -32768, 32767);
//		n=clamp(n, -32768, 32767);
		
		oblk[i*2+0]=n;
		oblk[i*2+1]=m;
	}

	return(0);
}


int bltac_encblock3s(s16 *iblk, u64 *oblk)
{
	s16 cblk[16];
	s16 tblk[16*2];
	u64 blk, blk1, blk2, blk3;
	int e, e1, e2, e3;
	int s;
	int i, j, k;
	
	for(i=0; i<16; i++)
		{ cblk[i]=(iblk[i*2+0]+iblk[i*2+1])/2; }

//	bltac_encblock3(iblk, &blk1, 2);
	bltac_encblock3(cblk, &blk1, 1);
//	bltac_encblock3js_6n(iblk, &blk2, 0);

//	blk1=0x7F7F7F;

	blk2=0; e2=999999;
	for(i=0; i<2; i++)
	{
		bltac_encblock3js_6n(iblk, &blk3, i);

		bltac_decblock3(blk3, tblk, 1);
		e3=bltac_encblock3s_err(iblk, tblk);
		if(e3<e2)
			{ blk2=blk3; e2=e3; }
	}

//	bltac_encblock2js(iblk, &blk3);
//	bltac_encblock2js(iblk, &blk3);

	bltac_decblock3s(blk1, tblk);
	e1=bltac_encblock3s_err(iblk, tblk);

	bltac_decblock3s(blk2, tblk);
	e2=bltac_encblock3s_err(iblk, tblk);

//	bltac_decblock3s(blk3, tblk);
//	e3=bltac_encblock3s_err(iblk, tblk);

	blk=blk1; e=e1;
	if(e2<e)
//	if(1)
//	if(0)
		{ blk=blk2; e=e2; }

//	if(e3<e)
//	if(1)
	if(0)
		{ blk=blk3; e=e3; }

//	bltac_encblock3(iblk, &blk, 2);
//	bltac_encblock3js_6n(iblk, &blk, 0);

//	s=blk&63;
//	if(s<58)
//	{
//		if(((blk>>16)&3)==3)
//			{ blk&=~0x10000ULL; }
//	}

//	blk=0x7F7F7F;

	*oblk=blk;
}

int bltac_decblock3s(u64 blk, s16 *oblk)
{
	int m, n, a, b, c, d, s;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;
	
//	s0=(s16)(blk>>48);
	s0=(s16)(blk);
	a=(s16)(s0&0xFFC0);
	s=s0&63;
	
	if(s<58)
	{
		i=(blk>>16)&3;
//		if((i==0)||(i==2))
		if(i!=3)
//		if(1)
		{
			bltac_decblock2(blk, oblk+0, 2);
			bltac_decblock2(blk, oblk+1, 2);
			return(0);
		}
		
		bltac_decblock2js(blk, oblk);
		return(0);
	}

	if(s>=60)
	{
		i=(blk>>16)&3;
//		if((i==0)||(i==2))
		if(1)
		{
			bltac_decblock3(blk, oblk+0, 2);
			bltac_decblock3(blk, oblk+1, 2);
			return(0);
		}
	}

	if(s>=58)
	{
		bltac_decblock3js(blk, oblk);
		return(0);
	}
}

#ifndef CONGFXB_NOMAIN
int main()
{
	int btcnt[64];
	int l4cnt[8];
	u16 *ibuf;
	u16 *obuf;
	u64 *bbuf;
	byte *hibuf;
	double e;
	int len, len2;
	int nb, nbx, nby;
	int i, j, k, l, l1;
	
	printf("init\n");
//	tfau_init();
	printf("init ok\n");
	
//	ibuf=BGBMID_LoadWAV_32Stereo16("sound_dev/02_Rise.wav", &len);
	ibuf=BGBMID_LoadWAV_32Stereo16("sound_dev/Skrillex_Reptile.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Stereo16(
//		"sound_dev/Skrillex_FirstOfTheYear.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Stereo16("sound_dev/Skrillex_BreaknASweat.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Stereo16(
//		"sound_dev/Skrillex_KillEverybody.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Stereo16("sound_dev/Skrillex_Cinema.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Stereo16("sound_dev/Skrillex_Bangarang.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Stereo16(
//		"sound_dev/OwenWasHer_Touhou6_PCM16M_22.wav", &len);
	
	bbuf=malloc((len/16)*2*sizeof(u64));
	obuf=malloc(len*2*sizeof(u16));
	
	for(i=0; i<64; i++)
		btcnt[i]=0;

	for(i=0; i<8; i++)
		l4cnt[i]=0;
	
	nb=len/16;
	for(i=0; i<nb; i++)
	{
//		bltac_encblock(ibuf+(i*16), bbuf+i);
//		bltac_decblock(bbuf[i], obuf+(i*16));

//		bltac_encblock2(ibuf+(i*16), bbuf+i);
//		bltac_decblock2(bbuf[i], obuf+(i*16));

		bltac_encblock3s(ibuf+(i*16)*2, bbuf+i);
		bltac_decblock3s(bbuf[i], obuf+(i*16)*2);
		
//		j=(bbuf[i]>>48)&63;
		j=(bbuf[i])&63;
		btcnt[j]++;

		j=(bbuf[i]>>16)&7;
		l4cnt[j]++;
	}
	
	for(i=0; i<8; i++)
	{
		l=0;
		for(j=0; j<8; j++)
		{
			k=btcnt[i*8+j];
			l+=k;
			printf("%6d ", k);
		}
		printf("  %.2f%%\n", (100.0*l)/nb);
	}

	printf("L4: ");
	for(j=0; j<8; j++)
	{
		k=l4cnt[j];
		l+=k;
		printf("%6d ", k);
	}
	printf("\n");
	
	e=0;
	for(i=0; i<len; i++)
	{
		k=((s16 *)obuf)[i]-((s16 *)ibuf)[i];
		e+=k*k;
	}
	printf("e=%f\n", sqrt(e/len));
	
	len2=len;
	BGBMID_StoreWAV("filt0s.wav", obuf, 2, 32000, 16, len2);
}
#endif
