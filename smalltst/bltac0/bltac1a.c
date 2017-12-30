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
int bltac_encblock(s16 *iblk, u32 *oblk)
{
	u32 blk;
	int m, n, a, b, c, d;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k;
	
	m=65536;
	n=-65536;
	for(i=0; i<16; i++)
	{
		k=iblk[i];
		if(k<m)m=k;
		if(k>n)n=k;
	}

	a=(m+n)/2;
	m=(m+a)/2;
	n=(n+a)/2;

	m=(3*m+a)/4;
	n=(3*n+a)/4;
	
	c=(m+n)/2;
	d=n-m;

	c0=(c>>8)+128;
	c=clamp255(((c+127)>>8)+128);
	d=clamp255(d>>8);

	c1=(c-128)<<8;
	d1=d<<8;
	
	m=c1-(d1>>1);
	n=c1+d1;
	
	if(((n<m) || (n>32767) || (m<-32767)) && (c!=c0))
	{
		c=c0;
		c1=(c-128)<<8;	d1=d<<8;
		m=c1-(d1>>1);	n=c1+d1;
	}
		
	
	while(((n<m) || (n>32767) || (m<-32767)) && (d>0))
	{
		d--;
		c1=(c-128)<<8;	d1=d<<8;
		m=c1-(d1>>1);	n=c1+d1;
	}
	
	b=0; a=c1;
	for(i=0; i<16; i++)
	{
		k=iblk[i];

		if(k>a)
//		if(k>c)
		{
			b|=1<<i;
			a=(3*a+n)/4;
//			a=(a+n)/2;
		}else
		{
			a=(3*a+m)/4;
//			a=(a+m)/2;
		}
	}
	
	blk=b|(c<<16)|(d<<24);
	*oblk=blk;

	return(0);
}

int bltac_decblock(u32 blk, s16 *oblk)
{
	int m, n, a, b, c, d;
	int i, j, k;
	
	a=(blk>>16)&255;
	b=(blk>>24)&255;
	c=(a-128)<<8;
	d=b<<8;
	m=c-(d>>1);
	n=c+d;

	b=blk&65535;
	for(i=0; i<16; i++)
		{ oblk[i]=(b&(1<<i))?n:m; }

	return(0);
}
#endif


#if 0
int bltac_encblock(s16 *iblk, u32 *oblk)
{
	u32 blk;
	int m, n, a, b, c, d;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k;
	
	m=65536;
	n=-65536;
	for(i=0; i<16; i++)
	{
		k=iblk[i];
//		k=clamp(k, -32255, 32255);

		if(k<m)m=k;
		if(k>n)n=k;
	}

	a=(m+n)/2;
	m=(m+a)/2;
	n=(n+a)/2;

#if 0
	m2=m; c0=1;
	n2=n; c1=1;
	for(i=0; i<16; i++)
	{
		k=iblk[i];
		if(k<a) { m2+=k; c0++; }
		if(k>a) { n2+=k; c1++; }
	}

	m2/=c0;
	n2/=c1;

//	m=(m+m2)/2;
//	n=(n+n2)/2;
//	m=m2;
//	n=n2;
#endif

	m=(3*m+a)/4;
	n=(3*n+a)/4;
	
	c=(m+n)/2;
	d=n-m;

	c0=(c>>8)+128;
	c=clamp255(((c+127)>>8)+128);
//	d=clamp255(((d+127)>>8)+128);
//	d=clamp255((d+127)>>8);
	d=clamp255(d>>8);

	c1=(c-128)<<8;
//	d1=(d-128)<<8;
	d1=d<<8;
	
	m=c1-(d1>>1);
	n=c1+d1;
	
	if(((n<m) || (n>32767) || (m<-32767)) && (c!=c0))
	{
		c=c0;
		c1=(c-128)<<8;	d1=d<<8;
		m=c1-(d1>>1);	n=c1+d1;
	}
		
	
	while(((n<m) || (n>32767) || (m<-32767)) && (d>0))
	{
		d--;
		c1=(c-128)<<8;	d1=d<<8;
		m=c1-(d1>>1);	n=c1+d1;
	}
	
//	m=clamp(m, -32767, 32767);
//	n=clamp(n, -32767, 32767);


	b=0; a=c1;
	for(i=0; i<16; i++)
	{
		k=iblk[i];
//		if(k>c)
//			b|=1<<i;

		if(k>a)
//		if(k>c)
		{
			b|=1<<i;
			a=(3*a+n)/4;
//			a=(a+n)/2;
		}else
		{
			a=(3*a+m)/4;
//			a=(a+m)/2;
		}
	}
	
//	c=clamp255(((c+127)>>8)+128);
//	d=clamp255(((d+127)>>8)+128);
	
	blk=b|(c<<16)|(d<<24);
	*oblk=blk;

	return(0);
}

int bltac_decblock(u32 blk, s16 *oblk)
{
	static int la;
	int m, n, a, b, c, d;
	int i, j, k;
	
	b=blk&65535;
	c=(blk>>16)&255;
	d=(blk>>24)&255;
	
	c=(c-128)<<8;
//	d=(d-128)<<8;
	d=d<<8;
	
	m=c-(d>>1);
	n=c+d;
//	m=clamp(m, -32767, 32767);
//	n=clamp(n, -32767, 32767);
	
//	a=la;
	a=c;
	for(i=0; i<16; i++)
	{
		if(b&(1<<i))
		{
//			a=(3*a+n)/4;
			a=(a+n)/2;
		}else
		{
//			a=(3*a+m)/4;
			a=(a+m)/2;
		}

//		oblk[i]=a;
		oblk[i]=(b&(1<<i))?n:m;
//		oblk[i]=c;
	}
	la=a;

	return(0);
}
#endif

#if 0
int bltac_encblock(s16 *iblk, u32 *oblk)
{
	static int la=0;
	u32 blk;
	int m, n, a, b, c, d;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;
	
//	s0=(iblk[0]+iblk[1])/2;
	s0=(2*la+iblk[0]+iblk[1])/4;
	l=s0;
	m=65536; n=-65536;
	for(i=0; i<16; i++)
	{
		k=iblk[i];
//		if(k<m)m=k;
//		if(k>n)n=k;
		
		j=k-l;
		j=j^(j>>31);
		if(j<m)m=j;
		if(j>n)n=j;

		l=k;
	}
//	la=(la+l)/2;
	
	c=s0;
	d=(m+n)/2;
//	d=d/2;

	c=clamp255(((c+127)>>8)+128);
	d=clamp255(((d+127)>>8)+128);

	c1=(c-128)<<8;
	d1=(d-128)<<8;

	b=0; a=c1;
	for(i=0; i<16; i++)
	{
		k=iblk[i];
		if(k>a)
		{
			b|=1<<i;
			a=a+d1;
		}else
		{
			a=a-d1;
		}
	}
//	la=(la+a)/2;
	la=a;
		
	blk=b|(c<<16)|(d<<24);
	*oblk=blk;

	return(0);
}

int bltac_decblock(u32 blk, s16 *oblk)
{
	static int la=0;
	int m, n, a, b, c, d;
	int i, j, k, l;
	
	b=blk&65535;
	c=(blk>>16)&255;
	d=(blk>>24)&255;
	
	c=(c-128)<<8;
	d=(d-128)<<8;
	
//	m=c-(d>>1);
//	n=c+d;
//	m=clamp(m, -32767, 32767);
//	n=clamp(n, -32767, 32767);
	
	a=la; l=c;
	for(i=0; i<16; i++)
	{
		if(b&(1<<i))
		{
			l=l+d;
		}else
		{
			l=l-d;
		}
		
//		a=(a+l)/2;
		a=l;

		a=clamp(a, -32767, 32767);
		oblk[i]=a;
	}
	la=a;

	return(0);
}
#endif

#if 0
int bltac_encblock(u16 *iblk, u32 *oblk)
{
	static int la=0;
	static int ls=0;
	u32 blk;
	int m, n, a, b, c, d, s;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;
	
	a=la; s=ls; blk=0;
	for(i=0; i<16; i++)
	{
		k=iblk[i];
//		d=1<<s;
//		d=1<<(s>>1);
		d=1<<(s>>2);
//		if(s&1)d+=d>>1;

		d1=d>>1;
		if(k>a)
		{
			c0=a+d1;
//			c0=a+d;
//			c0=a+(3*d)/4;
//			c0=a+(3*d)/2;
			if(k>c0)
				b=0;
			else
				b=1;
		}else
		{
			c0=a-d1;
//			c0=a-d;
//			c0=a-(3*d)/4;
//			c0=a-(3*d)/2;
			if(k<c0)
				b=2;
			else
				b=3;
		}
		
		blk|=b<<(i*2);
		switch(b)
		{
		case 0:
			a+=d; s++;
			s|=1;
			break;
		case 1:
			a+=d1; s--;
			s&=~1;
			break;
		case 2:
			a-=d; s++;
			s|=1;
			break;
		case 3:
			a-=d1; s--;
			s&=~1;
			break;
		}

		a=clamp(a, -32767, 32767);
//		s=clamp(s, 0, 15);
//		s=clamp(s, 0, 31);
		s=clamp(s, 0, 63);
	}
	la=a;
	ls=s;
	
	*oblk=blk;
}
	
int bltac_decblock(u32 blk, u16 *oblk)
{
	static int la=0;
	static int ls=0;
	int m, n, a, b, c, d, s;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;
	
	a=la; s=ls;
	for(i=0; i<16; i++)
	{
		b=(blk>>(i*2))&3;
	
//		d=1<<s;
//		d=1<<(s>>1);
		d=1<<(s>>2);
//		if(s&1)d+=d>>1;

		d1=d>>1;

		switch(b)
		{
		case 0:
			a+=d; s++;
			s|=1;
			break;
		case 1:
			a+=d1; s--;
			s&=~1;
			break;
		case 2:
			a-=d; s++;
			s|=1;
			break;
		case 3:
			a-=d1; s--;
			s&=~1;
			break;
		}

		a=clamp(a, -32768, 32767);
		s=clamp(s, 0, 63);
		
		oblk[i]=a;
	}
	la=a;
	ls=s;
}
#endif

#if 1
int bltac_encblock2(s16 *iblk, u64 *oblk)
{
	static int la=0;
	static int ls=0;
	static u16 *lpn=NULL;
	u64 blk;
	int m, n, a, b, c, d, s;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;
	
	if(iblk==lpn)
	{
//		a=la;
		la=(iblk[0]+la)/2;
		s0=(la&0xFFC0)|ls;
		s1=ls;
	}else
	{
		la=(iblk[0]+iblk[1])/2;
		ls=8;
		s0=(la&0xFFC0)|ls;
		s1=ls;
	}

	a=(s16)(s0&0xFFC0);
	s=s0&63;
	blk=((u64)s0)<<48;
	for(i=0; i<16; i++)
	{
//		k=iblk[i];
//		k=(s16)(iblk[i]&0xFFC0);
		k=(iblk[i]+31)&(~63);
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

		blk|=((u64)b)<<(i*3);

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
	lpn=iblk+16;
	
	*oblk=blk;
	return(0);
}
	
int bltac_decblock2(u64 blk, s16 *oblk)
{
	static int la;
	int m, n, a, b, c, d, s;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;
	
	s0=(s16)(blk>>48);
	a=(s16)(s0&0xFFC0);
	s=s0&63;
	
//	if(a==(la&0xFFC0))
//		a|=la&63;
	
	for(i=0; i<16; i++)
	{
		b=(blk>>(i*3))&7;
		
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
		oblk[i]=a;
	}
	la=a;
	return(0);
}
#endif

int bltac_encblock3_63(s16 *iblk, u64 *oblk)
{
	u64 blk;
	int m, n, a, b, c, d, s;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;

	blk=(63LL<<48);
	for(i=0; i<16; i++)
	{
		k=iblk[i];
		b=(k+32768)>>13;
		blk|=((u64)b)<<(i*3);
	}

	*oblk=blk;
	return(0);
}

int bltac_encblock3_6n(s16 *iblk, u64 *oblk, int bt)
{
	u64 blk;
	int m, n, a, b, c, d, s;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;

	m=65536; n=-65536;
	for(i=0; i<16; i++)
	{
		k=iblk[i];
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

	blk=(((u64)s0)<<48);
	for(i=0; i<16; i++)
	{
		k=iblk[i];
		
		b=(((k-c)*l)>>12)+4;
		b=clamp(b, 0, 7);
		
//		b=(k+32768)>>13;
		blk|=((u64)b)<<(i*3);
	}

	*oblk=blk;
	return(0);
}

int bltac_encblock3_err(s16 *iblk, s16 *oblk)
{
	double e;
	int i, j, k;
	
	e=0;
	for(i=0; i<16; i++)
	{
		j=iblk[i]-oblk[i];
		e+=((double)j)*j;
	}

	for(i=1; i<16; i++)
	{
		j=(iblk[i]-iblk[i-1])-(oblk[i]-oblk[i-1]);
		e+=((double)j)*j;
	}

	return(sqrt(e/16));
}

int bltac_encblock3(s16 *iblk, u64 *oblk)
{
	s16 tblk[16];
	u64 blk0, blk1;
	u64 blk2, blk3;
	u64 blk;
	int e, e0, e1, e2, e3;
	int i, j, k;
	
	bltac_encblock2(iblk, &blk0);
	bltac_encblock3_63(iblk, &blk1);

	blk2=0; e2=999999;
	for(i=0; i<4; i++)
	{
		bltac_encblock3_6n(iblk, &blk3, i);

		bltac_decblock3(blk3, tblk);
		e3=bltac_encblock3_err(iblk, tblk);
		if(e3<e2)
			{ blk2=blk3; e2=e3; }
	}
	
	bltac_decblock3(blk0, tblk);
	e0=bltac_encblock3_err(iblk, tblk);
	bltac_decblock3(blk1, tblk);
	e1=bltac_encblock3_err(iblk, tblk);
	
	blk=blk0; e=e0;
	if(e1<e) { blk=blk1; e=e1; }
	if(e2<e) { blk=blk2; e=e2; }
	
//	blk=blk0;
//	blk=blk1;
//	blk=blk2;
	
	*oblk=blk;

	return(0);
}

int bltac_decblock3(u64 blk, s16 *oblk)
{
	int m, n, a, b, c, d, s;
	int n2, m2, c0, c1, d1;
	int s0, s1;
	int i, j, k, l;
	
	s0=(s16)(blk>>48);
	a=(s16)(s0&0xFFC0);
	s=s0&63;
	
	if(s<58)
	{
		bltac_decblock2(blk, oblk);
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
		b=(blk>>(i*3))&7;
		a=((m*(15-b*2))+(n*(1+b*2)))/16;
		oblk[i]=a;
	}
	return(0);
}

int main()
{
	int btcnt[64];
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
	
//	ibuf=BGBMID_LoadWAV_44Mono16("sound_dev/SonicBoom_E60.wav", &len);
//	ibuf=BGBMID_LoadWAV_16Mono16("sound_dev/SonicBoom_E60.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Mono16("sound_dev/SonicBoom_E60.wav", &len);
//	ibuf=BGBMID_LoadWAV_8Mono16("sound_dev/SonicBoom_E60.wav", &len);

//	ibuf=BGBMID_LoadWAV_44Mono16("sound_dev/02_Rise.wav", &len);
//	ibuf=BGBMID_LoadWAV_16Mono16("sound_dev/02_Rise.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Mono16("sound_dev/02_Rise.wav", &len);

//	ibuf=BGBMID_LoadWAV_16Mono16("sound_dev/Skrillex_Reptile.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Mono16("sound_dev/Skrillex_Reptile.wav", &len);

//	ibuf=BGBMID_LoadWAV_32Mono16("sound_dev/Skrillex_FirstOfTheYear.wav", &len);
	ibuf=BGBMID_LoadWAV_32Mono16("sound_dev/Skrillex_BreaknASweat.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Mono16("sound_dev/Skrillex_KillEverybody.wav", &len);
//	ibuf=BGBMID_LoadWAV_32Mono16("sound_dev/Skrillex_Cinema.wav", &len);


//	ibuf=BGBMID_LoadWAV_32Mono16("sound_dev/OwenWasHer_Touhou6_PCM16M_22.wav", &len);
//	ibuf=BGBMID_LoadWAV_16Mono16("sound_dev/OwenWasHer_Touhou6_PCM16M_22.wav", &len);
	
//	if(len>8388608)
//		len=8388608;
	
	bbuf=malloc((len/16)*2*sizeof(u64));
	obuf=malloc(len*2*sizeof(u16));
	
	for(i=0; i<64; i++)
		btcnt[i]=0;
	
	nb=len/16;
	for(i=0; i<nb; i++)
	{
//		bltac_encblock(ibuf+(i*16), bbuf+i);
//		bltac_decblock(bbuf[i], obuf+(i*16));

//		bltac_encblock2(ibuf+(i*16), bbuf+i);
//		bltac_decblock2(bbuf[i], obuf+(i*16));

		bltac_encblock3(ibuf+(i*16), bbuf+i);
		bltac_decblock3(bbuf[i], obuf+(i*16));
		
		j=(bbuf[i]>>48)&63;
		btcnt[j]++;
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
	
	e=0;
	for(i=0; i<len; i++)
	{
		k=((s16 *)obuf)[i]-((s16 *)ibuf)[i];
		e+=k*k;
	}
	printf("e=%f\n", sqrt(e/len));

#if 0
	e=0;
	for(i=0; i<len; i++)
	{
//		j=((s16 *)ibuf)[i&(~1)];
		j=(((s16 *)ibuf)[i&(~1)] + ((s16 *)ibuf)[i|1])/2;
//		j=((j+127)>>8)<<8;

//		j=((s16 *)ibuf)[i];
		j=(j>>12)<<12;
//		j=(j>>14)<<14;

#if 0
		j=((j+127)>>8)<<8;
		j=(j>=0)?(8+sqrt(j)*0.6187):(8-sqrt(-j)*0.6187);
		j=clamp(j, 0, 15);
		j=(j-8)*1.616; j=(j>0)?(j*j):(-j*j);
		j=j*256;
		j=clamp(j, -32768, 32767);
#endif

//		obuf[i]=j;

		k=j-((s16 *)ibuf)[i];
		e+=k*k;
	}
	printf("8kHz e=%f\n", sqrt(e/len));
#endif
	
	len2=len;
	BGBMID_StoreWAV("filt0.wav", obuf, 1, 32000, 16, len2);
}
