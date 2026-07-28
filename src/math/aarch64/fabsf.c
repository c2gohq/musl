#include <math.h>
#include <c2go.h>

c2go_extern float fabsf(float x)
{
	__asm__ ("fabs %s0, %s1" : "=w"(x) : "w"(x));
	return x;
}
