#include <wctype.h>
#include <c2go.h>

c2go_extern int iswlower(wint_t wc)
{
	return towupper(wc) != wc;
}

c2go_extern int iswlower_l(wint_t c, locale_t l)
{
	return iswlower(c);
}
