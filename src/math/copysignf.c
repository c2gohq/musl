#include <math.h>
#include <c2go.h>
#include <stdint.h>

c2go_extern float copysignf(float x, float y)
{
	union {float f; uint32_t i;} ux={x}, uy={y};
	ux.i &= 0x7fffffff;
	ux.i |= uy.i & 0x80000000;
	return ux.f;
}
