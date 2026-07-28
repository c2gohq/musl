#include <math.h>
#include <c2go.h>

c2go_extern float sqrtf(float x)
{
	__asm__ ("sqrtss %1, %0" : "=x"(x) : "x"(x));
	return x;
}
