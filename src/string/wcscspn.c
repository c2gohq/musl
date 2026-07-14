#include <c2go.h>
#include <wchar.h>

c2go_extern size_t wcscspn(const wchar_t *s, const wchar_t *c)
{
	const wchar_t *a;
	if (!c[0]) return wcslen(s);
	if (!c[1]) return (s=wcschr(a=s, *c)) ? s-a : wcslen(a);
	for (a=s; *s && !wcschr(c, *s); s++);
	return s-a;
}
