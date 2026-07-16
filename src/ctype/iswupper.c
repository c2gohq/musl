#include <wctype.h>
#include <c2go.h>

c2go_extern int iswupper(wint_t wc)
{
	return towlower(wc) != wc;
}

c2go_extern int iswupper_l(wint_t c, locale_t l)
{
	return iswupper(c);
}
