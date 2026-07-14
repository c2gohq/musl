#include <c2go.h>
#include <wchar.h>

c2go_extern wchar_t *wcspbrk(const wchar_t *s, const wchar_t *b)
{
	s += wcscspn(s, b);
	return *s ? (wchar_t *)s : NULL;
}
