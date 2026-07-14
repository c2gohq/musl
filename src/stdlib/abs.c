#include <c2go.h>
#include <stdlib.h>

c2go_extern int abs(int a)
{
	return a>0 ? a : -a;
}
