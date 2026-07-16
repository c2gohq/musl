#include <string.h>
#include <locale.h>
#include <c2go.h>
/* c2go: locale_impl.h dropped — single C.UTF-8 locale, CURRENT_LOCALE is 0. */

/* collate only by code points */
/* c2go: KEEPCASE — a CamelCase Go alias would collide with strxfrm_l's. */
c2go_extern_as(C2GO_KEEPCASE)
size_t __strxfrm_l(char *restrict dest, const char *restrict src, size_t n, locale_t loc)
{
	size_t l = strlen(src);
	if (n > l) strcpy(dest, src);
	return l;
}

c2go_extern size_t strxfrm(char *restrict dest, const char *restrict src, size_t n)
{
	return __strxfrm_l(dest, src, n, 0);
}

/* c2go: weak_alias(__strxfrm_l, strxfrm_l) collapsed to an exported wrapper. */
c2go_extern size_t strxfrm_l(char *restrict dest, const char *restrict src, size_t n, locale_t loc)
{
	return __strxfrm_l(dest, src, n, loc);
}
