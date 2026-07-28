#include <math.h>
#include <c2go.h>

c2go_extern double fmin(double x, double y)
{
	__asm__ ("fminnm %d0, %d1, %d2" : "=w"(x) : "w"(x), "w"(y));
	return x;
}
