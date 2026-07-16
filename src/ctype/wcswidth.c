#include <wchar.h>
#include <c2go.h>

c2go_extern int wcswidth(const wchar_t *wcs, size_t n)
{
	int l=0, k=0;
	for (; n-- && *wcs && (k = wcwidth(*wcs)) >= 0; l+=k, wcs++);
	return (k < 0) ? k : l;
}
