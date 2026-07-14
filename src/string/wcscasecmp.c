#include <c2go.h>
#include <wchar.h>
#include <wctype.h>

c2go_extern int wcscasecmp(const wchar_t *l, const wchar_t *r)
{
	return wcsncasecmp(l, r, -1);
}
