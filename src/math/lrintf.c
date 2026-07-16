#include <math.h>
#include <c2go.h>

/* uses LONG_MAX > 2^24, see comments in lrint.c */

c2go_extern long lrintf(float x)
{
	return rintf(x);
}
