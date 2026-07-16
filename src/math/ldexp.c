#include <math.h>
#include <c2go.h>

c2go_extern double ldexp(double x, int n)
{
	return scalbn(x, n);
}
