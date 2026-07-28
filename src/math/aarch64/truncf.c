#include <math.h>
#include <c2go.h>

c2go_extern float truncf(float x)
{
	__asm__ ("frintz %s0, %s1" : "=w"(x) : "w"(x));
	return x;
}
