#include <c2go.h>
#include <wchar.h>
#include <stdint.h>

c2go_extern wchar_t *wmemmove(wchar_t *d, const wchar_t *s, size_t n)
{
	wchar_t *d0 = d;
	if (d == s) return d;
	if ((uintptr_t)d-(uintptr_t)s < n * sizeof *d)
		while (n--) d[n] = s[n];
	else
		while (n--) *d++ = *s++;
	return d0;
}
