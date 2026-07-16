#define _BSD_SOURCE
#include <stdlib.h>
#include <c2go.h>

typedef int (*cmpfun)(const void *, const void *);

static int wrapper_cmp(const void *v1, const void *v2, void *cmp)
{
	return ((cmpfun)cmp)(v1, v2);
}

c2go_extern void qsort(void *base, size_t nel, size_t width, cmpfun cmp)
{
	__qsort_r(base, nel, width, wrapper_cmp, (void *)cmp);
}
