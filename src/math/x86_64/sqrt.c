#include <math.h>
#include <c2go.h>

c2go_extern double sqrt(double x)
{
	__asm__ ("sqrtsd %1, %0" : "=x"(x) : "x"(x));
	return x;
}
