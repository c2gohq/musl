#include <c2go.h>
#include <wchar.h>

c2go_extern wchar_t *wmemchr(const wchar_t *s, wchar_t c, size_t n)
{
	for (; n && *s != c; n--, s++);
	return n ? (wchar_t *)s : 0;
}
