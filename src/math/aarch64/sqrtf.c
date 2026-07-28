#include <math.h>
#include <c2go.h>

c2go_extern float sqrtf(float x)
{
	__asm__ ("fsqrt %s0, %s1" : "=w"(x) : "w"(x));
	return x;
}
