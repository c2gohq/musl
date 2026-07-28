#include <math.h>
#include <c2go.h>

c2go_extern float ceilf(float x)
{
	__asm__ ("frintp %s0, %s1" : "=w"(x) : "w"(x));
	return x;
}
