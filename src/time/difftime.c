#include <time.h>
#include <c2go.h>

c2go_extern double difftime(time_t t1, time_t t0)
{
	return t1-t0;
}
