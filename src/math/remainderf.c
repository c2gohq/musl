#include <math.h>
#include <c2go.h>

c2go_extern float remainderf(float x, float y)
{
	int q;
	return remquof(x, y, &q);
}

/* c2go: weak_alias dremf omitted (BSD-legacy name, no consumer). */
