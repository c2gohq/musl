#include <c2go.h>
#include <wchar.h>

c2go_extern int wmemcmp(const wchar_t *l, const wchar_t *r, size_t n)
{
	for (; n && *l==*r; n--, l++, r++);
	return n ? (*l < *r ? -1 : *l > *r) : 0;
}
