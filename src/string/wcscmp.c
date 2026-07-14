#include <c2go.h>
#include <wchar.h>

c2go_extern int wcscmp(const wchar_t *l, const wchar_t *r)
{
	for (; *l==*r && *l && *r; l++, r++);
	return *l < *r ? -1 : *l > *r;
}
