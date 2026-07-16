#include <math.h>
#include <c2go.h>

c2go_extern double fdim(double x, double y)
{
	if (isnan(x))
		return x;
	if (isnan(y))
		return y;
	return x > y ? x - y : 0;
}
