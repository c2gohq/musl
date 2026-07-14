#include <c2go.h>
#include <wchar.h>

c2go_extern int wcscasecmp_l(const wchar_t *l, const wchar_t *r, locale_t locale)
{
	return wcscasecmp(l, r);
}
