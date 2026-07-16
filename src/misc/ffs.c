#include <strings.h>
#include "atomic.h"
#include <c2go.h>

c2go_extern int ffs(int i)
{
	return i ? a_ctz_l(i)+1 : 0;
}
