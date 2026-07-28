#include <math.h>
#include <c2go.h>

c2go_extern float fmaf(float x, float y, float z)
{
	__asm__ ("fmadd %s0, %s1, %s2, %s3" : "=w"(x) : "w"(x), "w"(y), "w"(z));
	return x;
}
