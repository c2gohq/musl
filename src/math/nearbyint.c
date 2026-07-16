#include <fenv.h>
#include <math.h>
#include <c2go.h>

/* nearbyint is the same as rint, but it must not raise the inexact exception */

c2go_extern double nearbyint(double x)
{
#ifdef FE_INEXACT
	#pragma STDC FENV_ACCESS ON
	int e;

	e = fetestexcept(FE_INEXACT);
#endif
	x = rint(x);
#ifdef FE_INEXACT
	if (!e)
		feclearexcept(FE_INEXACT);
#endif
	return x;
}
