#include <c2go.h>
#include <wchar.h>

c2go_extern wchar_t *wcscat(wchar_t *restrict dest, const wchar_t *restrict src)
{
	wcscpy(dest + wcslen(dest), src);
	return dest;
}
