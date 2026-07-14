#include <c2go.h>
#include <stdlib.h>

c2go_extern long long llabs(long long a)
{
	return a>0 ? a : -a;
}
