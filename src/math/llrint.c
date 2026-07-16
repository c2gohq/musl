#include <math.h>
#include <c2go.h>

/* uses LLONG_MAX > 2^53, see comments in lrint.c */

c2go_extern long long llrint(double x)
{
	return rint(x);
}
