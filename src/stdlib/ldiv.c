#include <c2go.h>
#include <stdlib.h>

c2go_extern ldiv_t ldiv(long num, long den)
{
	return (ldiv_t){ num/den, num%den };
}
