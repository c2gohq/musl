#include <c2go.h>
#include <inttypes.h>

c2go_extern intmax_t imaxabs(intmax_t a)
{
	return a>0 ? a : -a;
}
