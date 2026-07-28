#include <math.h>
#include <c2go.h>

c2go_extern float roundf(float x)
{
	__asm__ ("frinta %s0, %s1" : "=w"(x) : "w"(x));
	return x;
}
