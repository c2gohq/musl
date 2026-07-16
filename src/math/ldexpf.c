#include <math.h>
#include <c2go.h>

c2go_extern float ldexpf(float x, int n)
{
	return scalbnf(x, n);
}
