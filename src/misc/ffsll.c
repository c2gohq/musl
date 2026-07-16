#include <strings.h>
#include "atomic.h"
#include <c2go.h>

c2go_extern int ffsll(long long i)
{
	return i ? a_ctz_64(i)+1 : 0;
}
