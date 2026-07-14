#include <c2go.h>
#include <string.h>

c2go_extern size_t strnlen(const char *s, size_t n)
{
	const char *p = memchr(s, 0, n);
	return p ? p-s : n;
}
