#include <math.h>
#include <c2go.h>

c2go_extern double rint(double x)
{
	__asm__ ("frintx %d0, %d1" : "=w"(x) : "w"(x));
	return x;
}
