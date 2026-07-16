#include <wchar.h>
#include <locale.h>
#include <c2go.h>
/* c2go: locale_impl.h dropped — single C.UTF-8 locale, CURRENT_LOCALE is 0. */

/* collate only by code points */
/* c2go: KEEPCASE — a CamelCase Go alias would collide with wcsxfrm_l's. */
c2go_extern_as(C2GO_KEEPCASE)
size_t __wcsxfrm_l(wchar_t *restrict dest, const wchar_t *restrict src, size_t n, locale_t loc)
{
	size_t l = wcslen(src);
	if (l < n) {
		wmemcpy(dest, src, l+1);
	} else if (n) {
		wmemcpy(dest, src, n-1);
		dest[n-1] = 0;
	}
	return l;
}

c2go_extern size_t wcsxfrm(wchar_t *restrict dest, const wchar_t *restrict src, size_t n)
{
	return __wcsxfrm_l(dest, src, n, 0);
}

/* c2go: weak_alias(__wcsxfrm_l, wcsxfrm_l) collapsed to an exported wrapper. */
c2go_extern size_t wcsxfrm_l(wchar_t *restrict dest, const wchar_t *restrict src, size_t n, locale_t loc)
{
	return __wcsxfrm_l(dest, src, n, loc);
}
