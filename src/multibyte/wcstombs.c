#include <stdlib.h>
#include <wchar.h>
#include <c2go.h>

c2go_extern size_t wcstombs(char *restrict s, const wchar_t *restrict ws, size_t n)
{
	return wcsrtombs(s, &(const wchar_t *){ws}, n, 0);
}
