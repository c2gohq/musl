#include <string.h>
#include <locale.h>
#include <c2go.h>
/* c2go: locale_impl.h dropped — single C.UTF-8 locale, CURRENT_LOCALE is 0. */

/* c2go: KEEPCASE — a CamelCase Go alias would collide with strcoll_l's. */
c2go_extern_as(C2GO_KEEPCASE)
int __strcoll_l(const char *l, const char *r, locale_t loc)
{
	return strcmp(l, r);
}

c2go_extern int strcoll(const char *l, const char *r)
{
	return __strcoll_l(l, r, 0);
}

/* c2go: weak_alias(__strcoll_l, strcoll_l) collapsed to an exported wrapper. */
c2go_extern int strcoll_l(const char *l, const char *r, locale_t loc)
{
	return __strcoll_l(l, r, loc);
}
