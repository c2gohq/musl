#include <math.h>
#include <c2go.h>

c2go_extern double remainder(double x, double y)
{
	int q;
	return remquo(x, y, &q);
}

/* c2go: weak_alias drem omitted (BSD-legacy name, no consumer). */
