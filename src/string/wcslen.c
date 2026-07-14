#include <c2go.h>
#include <wchar.h>

c2go_extern size_t wcslen(const wchar_t *s)
{
	const wchar_t *a;
	for (a=s; *s; s++);
	return s-a;
}
