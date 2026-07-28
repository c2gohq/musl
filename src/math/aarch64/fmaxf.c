#include <math.h>
#include <c2go.h>

c2go_extern float fmaxf(float x, float y)
{
	__asm__ ("fmaxnm %s0, %s1, %s2" : "=w"(x) : "w"(x), "w"(y));
	return x;
}
