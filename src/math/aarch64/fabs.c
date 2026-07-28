#include <math.h>
#include <c2go.h>

c2go_extern double fabs(double x)
{
	__asm__ ("fabs %d0, %d1" : "=w"(x) : "w"(x));
	return x;
}
