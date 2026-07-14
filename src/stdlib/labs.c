#include <c2go.h>
#include <stdlib.h>

c2go_extern long labs(long a)
{
	return a>0 ? a : -a;
}
