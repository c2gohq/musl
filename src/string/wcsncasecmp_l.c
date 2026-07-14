#include <c2go.h>
#include <wchar.h>

c2go_extern int wcsncasecmp_l(const wchar_t *l, const wchar_t *r, size_t n, locale_t locale)
{
	return wcsncasecmp(l, r, n);
}
