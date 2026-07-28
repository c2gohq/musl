#include <math.h>
#include <c2go.h>

c2go_extern long lrint(double x)
{
	long n;
	__asm__ (
		"frintx %d1, %d1\n"
		"fcvtzs %x0, %d1\n" : "=r"(n), "+w"(x));
	return n;
}
