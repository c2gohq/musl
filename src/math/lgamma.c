#include <math.h>
#include "libm.h"

c2go_extern double lgamma(double x)
{
	return __lgamma_r(x, &__signgam);
}
