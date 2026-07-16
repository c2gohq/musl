#include <limits.h>
#include <math.h>
#include <c2go.h>

c2go_extern double scalbln(double x, long n)
{
	if (n > INT_MAX)
		n = INT_MAX;
	else if (n < INT_MIN)
		n = INT_MIN;
	return scalbn(x, n);
}
