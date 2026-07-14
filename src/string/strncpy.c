#include <c2go.h>
#include <string.h>

c2go_extern char *strncpy(char *restrict d, const char *restrict s, size_t n)
{
	stpncpy(d, s, n);
	return d;
}
