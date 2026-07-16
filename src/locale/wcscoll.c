#include <wchar.h>
#include <locale.h>
#include <c2go.h>
/* c2go: locale_impl.h dropped — single C.UTF-8 locale, CURRENT_LOCALE is 0. */

/* FIXME: stub */
/* c2go: KEEPCASE — a CamelCase Go alias would collide with wcscoll_l's. */
c2go_extern_as(C2GO_KEEPCASE)
int __wcscoll_l(const wchar_t *l, const wchar_t *r, locale_t locale)
{
	return wcscmp(l, r);
}

c2go_extern int wcscoll(const wchar_t *l, const wchar_t *r)
{
	return __wcscoll_l(l, r, 0);
}

/* c2go: weak_alias(__wcscoll_l, wcscoll_l) collapsed to an exported wrapper. */
c2go_extern int wcscoll_l(const wchar_t *l, const wchar_t *r, locale_t loc)
{
	return __wcscoll_l(l, r, loc);
}
