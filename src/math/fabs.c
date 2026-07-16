#include <math.h>
#include <c2go.h>
#include <stdint.h>

c2go_extern double fabs(double x)
{
	union {double f; uint64_t i;} u = {x};
	u.i &= -1ULL/2;
	return u.f;
}
