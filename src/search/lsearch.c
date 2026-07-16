#include <search.h>
#include <string.h>
#include <c2go.h>

/* c2go: musl's VLA-pointer `char (*p)[width]` is rewritten to explicit
 * `p + i*width` strides in both functions — c2go rejects VLA types;
 * byte-for-byte equivalent addressing. */
c2go_extern void *lsearch(const void *key, void *base, size_t *nelp, size_t width,
	int (*compar)(const void *, const void *))
{
	char *p = base;
	size_t n = *nelp;
	size_t i;

	for (i = 0; i < n; i++)
		if (compar(key, p + i*width) == 0)
			return p + i*width;
	*nelp = n+1;
	return memcpy(p + n*width, key, width);
}

c2go_extern void *lfind(const void *key, const void *base, size_t *nelp,
	size_t width, int (*compar)(const void *, const void *))
{
	char *p = (void *)base;
	size_t n = *nelp;
	size_t i;

	for (i = 0; i < n; i++)
		if (compar(key, p + i*width) == 0)
			return p + i*width;
	return 0;
}


