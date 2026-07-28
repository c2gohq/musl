#include <math.h>
#include <c2go.h>

#if __FMA__

c2go_extern float fmaf(float x, float y, float z)
{
	__asm__ ("vfmadd132ss %1, %2, %0" : "+x" (x) : "x" (y), "x" (z));
	return x;
}

#elif __FMA4__

c2go_extern float fmaf(float x, float y, float z)
{
	__asm__ ("vfmaddss %3, %2, %1, %0" : "=x" (x) : "x" (x), "x" (y), "x" (z));
	return x;
}

#else

#include "../fmaf.c"

#endif
