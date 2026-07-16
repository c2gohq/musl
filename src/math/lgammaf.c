#include <math.h>
#include "libm.h"

c2go_extern float lgammaf(float x)
{
	return __lgammaf_r(x, &__signgam);
}
