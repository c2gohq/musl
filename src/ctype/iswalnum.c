#include <wctype.h>
#include <c2go.h>

c2go_extern int iswalnum(wint_t wc)
{
	if (iswdigit(wc)) return 1;
	return iswalpha(wc);
}

c2go_extern int iswalnum_l(wint_t c, locale_t l)
{
	return iswalnum(c);
}
