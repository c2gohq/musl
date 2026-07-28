#include <math.h>
#include <c2go.h>

c2go_extern double nearbyint(double x)
{
	__asm__ ("frinti %d0, %d1" : "=w"(x) : "w"(x));
	return x;
}
