#include <c2go.h>
#include <wchar.h>

c2go_extern wchar_t *wmemset(wchar_t *d, wchar_t c, size_t n)
{
	wchar_t *ret = d;
	while (n--) *d++ = c;
	return ret;
}
