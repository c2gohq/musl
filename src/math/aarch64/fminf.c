#include <math.h>
#include <c2go.h>

c2go_extern float fminf(float x, float y)
{
	__asm__ ("fminnm %s0, %s1, %s2" : "=w"(x) : "w"(x), "w"(y));
	return x;
}
