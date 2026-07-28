#include <math.h>
#include <c2go.h>

c2go_extern double ceil(double x)
{
	__asm__ ("frintp %d0, %d1" : "=w"(x) : "w"(x));
	return x;
}
