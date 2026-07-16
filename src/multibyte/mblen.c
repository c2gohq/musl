#include <stdlib.h>
#include <c2go.h>

c2go_extern int mblen(const char *s, size_t n)
{
	return mbtowc(0, s, n);
}
