#include <math.h>
#include <c2go.h>

c2go_extern long long llroundf(float x)
{
	long long n;
	__asm__ ("fcvtas %x0, %s1" : "=r"(n) : "w"(x));
	return n;
}
