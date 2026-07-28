#include <math.h>
#include <c2go.h>

c2go_extern long long llround(double x)
{
	long long n;
	__asm__ ("fcvtas %x0, %d1" : "=r"(n) : "w"(x));
	return n;
}
