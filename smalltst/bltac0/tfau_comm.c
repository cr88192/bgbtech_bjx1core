#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

typedef unsigned char byte;
typedef signed char sbyte;

typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#ifdef __x86_64__
typedef unsigned long u64;
typedef signed long s64;
#else
typedef unsigned long long u64;
typedef signed long long s64;
#endif


#define BGBMID_FILE		FILE

#define bgbmid_fopen	fopen
#define bgbmid_fclose	fclose
#define bgbmid_fread	fread
#define bgbmid_fwrite	fwrite
#define bgbmid_fgetc	fgetc
#define bgbmid_fputc	fputc
#define bgbmid_fseek	fseek
#define bgbmid_ftell	ftell

void *bgbmid_malloc(int sz)
{
	void *ptr;
	ptr=malloc(sz);
	memset(ptr, 0, sz);
	return(ptr);
}

void bgbmid_free(void *ptr)
{
	free(ptr);
}


int FRGL_TimeMS()
{
#ifdef _WIN32
	static unsigned int init;
	unsigned int t;

	t=timeGetTime();
	if(!init)init=t;

	return((unsigned int)(t-init));
#else

#ifdef __EMSCRIPTEN__
	struct timeval	tp;
	static int      secbase; 

	gettimeofday(&tp, NULL);  
	if(!secbase)secbase=tp.tv_sec;
	return(((tp.tv_sec-secbase)*1000)+tp.tv_usec/1000);
#endif

#ifndef linux
	static int init;
	int t;

	t=clock();
	t*=CLOCKS_PER_SEC/1000.0;
//	t=FRGL_TimeMS();

	if(!init)init=t;

	return((unsigned int)(t-init));
#endif
#ifdef linux
	struct timeval	tp;
	static int      secbase; 

	gettimeofday(&tp, NULL);  
	if(!secbase)secbase=tp.tv_sec;
	return(((tp.tv_sec-secbase)*1000)+tp.tv_usec/1000);
#endif
#endif
}
