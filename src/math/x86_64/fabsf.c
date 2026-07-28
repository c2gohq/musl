#include <math.h>
#include <c2go.h>

c2go_extern float fabsf(float x)
{
	float t;
	__asm__ ("pcmpeqd %0, %0" : "=x"(t));          // t = ~0
	__asm__ ("psrld   $1, %0" : "+x"(t));          // t >>= 1
	__asm__ ("andps   %1, %0" : "+x"(x) : "x"(t)); // x &= t
	return x;
}
