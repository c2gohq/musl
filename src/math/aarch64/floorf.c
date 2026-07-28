#include <math.h>
#include <c2go.h>

c2go_extern float floorf(float x)
{
	__asm__ ("frintm %s0, %s1" : "=w"(x) : "w"(x));
	return x;
}
