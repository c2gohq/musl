#define _BSD_SOURCE
#include <string.h>
#include <c2go.h>

c2go_extern void explicit_bzero(void *d, size_t n)
{
	d = memset(d, 0, n);
	__asm__ __volatile__ ("" : : "r"(d) : "memory");
}
