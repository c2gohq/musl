#include <math.h>
#include <c2go.h>

c2go_extern float rintf(float x)
{
	__asm__ ("frintx %s0, %s1" : "=w"(x) : "w"(x));
	return x;
}
