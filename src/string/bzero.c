#define _BSD_SOURCE
#include <c2go.h>
#include <string.h>
#include <strings.h>

c2go_extern void bzero(void *s, size_t n)
{
	memset(s, 0, n);
}
