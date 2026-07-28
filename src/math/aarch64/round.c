#include <math.h>
#include <c2go.h>

c2go_extern double round(double x)
{
	__asm__ ("frinta %d0, %d1" : "=w"(x) : "w"(x));
	return x;
}
