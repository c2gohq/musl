#include <math.h>
#include <c2go.h>

c2go_extern double floor(double x)
{
	__asm__ ("frintm %d0, %d1" : "=w"(x) : "w"(x));
	return x;
}
