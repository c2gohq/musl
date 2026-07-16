#include <wctype.h>
#include <string.h>
#include <c2go.h>

c2go_extern wctrans_t wctrans(const char *class)
{
	if (!strcmp(class, "toupper")) return (wctrans_t)1;
	if (!strcmp(class, "tolower")) return (wctrans_t)2;
	return 0;
}

c2go_extern wint_t towctrans(wint_t wc, wctrans_t trans)
{
	if (trans == (wctrans_t)1) return towupper(wc);
	if (trans == (wctrans_t)2) return towlower(wc);
	return wc;
}

c2go_extern wctrans_t wctrans_l(const char *s, locale_t l)
{
	return wctrans(s);
}

c2go_extern wint_t towctrans_l(wint_t c, wctrans_t t, locale_t l)
{
	return towctrans(c, t);
}
