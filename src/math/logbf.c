#include <math.h>
#include <c2go.h>

c2go_extern float logbf(float x)
{
	if (!isfinite(x))
		return x * x;
	if (x == 0)
		return -1/(x*x);
	return ilogbf(x);
}
