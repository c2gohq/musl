#include <wctype.h>
#include <c2go.h>

#undef iswdigit

c2go_extern int iswdigit(wint_t wc)
{
	return (unsigned)wc-'0' < 10;
}

c2go_extern int iswdigit_l(wint_t c, locale_t l)
{
	return iswdigit(c);
}
