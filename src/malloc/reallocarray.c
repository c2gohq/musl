#define _BSD_SOURCE
#include <errno.h>
#include <stdlib.h>
#include <c2go.h>

c2go_extern void *reallocarray(void *ptr, size_t m, size_t n)
{
	if (n && m > -1 / n) {
		errno = ENOMEM;
		return 0;
	}

	return realloc(ptr, m * n);
}
