#include <c2go.h>
#include <inttypes.h>

c2go_extern imaxdiv_t imaxdiv(intmax_t num, intmax_t den)
{
	return (imaxdiv_t){ num/den, num%den };
}
