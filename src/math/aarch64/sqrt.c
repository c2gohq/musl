#include <math.h>
#include <c2go.h>

c2go_extern double sqrt(double x)
{
	__asm__ ("fsqrt %d0, %d1" : "=w"(x) : "w"(x));
	return x;
}
