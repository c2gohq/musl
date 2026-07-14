#include <c2go.h>
#include <wchar.h>

c2go_extern size_t wcsspn(const wchar_t *s, const wchar_t *c)
{
	const wchar_t *a;
	for (a=s; *s && wcschr(c, *s); s++);
	return s-a;
}
