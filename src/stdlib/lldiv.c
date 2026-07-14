#include <c2go.h>
#include <stdlib.h>

c2go_extern lldiv_t lldiv(long long num, long long den)
{
	return (lldiv_t){ num/den, num%den };
}
