#include <math.h>
#include <c2go.h>
#include <stdint.h>

c2go_extern float fabsf(float x)
{
	union {float f; uint32_t i;} u = {x};
	u.i &= 0x7fffffff;
	return u.f;
}
