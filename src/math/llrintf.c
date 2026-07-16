#include <math.h>
#include <c2go.h>

/* uses LLONG_MAX > 2^24, see comments in lrint.c */

c2go_extern long long llrintf(float x)
{
	return rintf(x);
}
