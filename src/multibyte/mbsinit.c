#include <c2go.h>
#include <wchar.h>

c2go_extern int mbsinit(const mbstate_t *st)
{
	return !st || !*(unsigned *)st;
}
