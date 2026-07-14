#include <c2go.h>
#include <wchar.h>

c2go_extern wchar_t *wcswcs(const wchar_t *haystack, const wchar_t *needle)
{
	return wcsstr(haystack, needle);
}
