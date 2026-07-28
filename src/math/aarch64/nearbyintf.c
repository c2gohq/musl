#include <math.h>
#include <c2go.h>

c2go_extern float nearbyintf(float x)
{
	__asm__ ("frinti %s0, %s1" : "=w"(x) : "w"(x));
	return x;
}
