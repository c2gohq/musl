#include <math.h>
#include <c2go.h>

c2go_extern long lrintf(float x)
{
	long r;
	__asm__ ("cvtss2si %1, %0" : "=r"(r) : "x"(x));
	return r;
}
