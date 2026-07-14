#define _GNU_SOURCE
#include <c2go.h>
#include <string.h>

c2go_extern void *mempcpy(void *dest, const void *src, size_t n)
{
	return (char *)memcpy(dest, src, n) + n;
}
