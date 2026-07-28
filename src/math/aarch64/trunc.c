#include <math.h>
#include <c2go.h>

c2go_extern double trunc(double x)
{
	__asm__ ("frintz %d0, %d1" : "=w"(x) : "w"(x));
	return x;
}
