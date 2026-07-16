#include <wctype.h>
#include <ctype.h>
#include <c2go.h>

c2go_extern int iswblank(wint_t wc)
{
	return isblank(wc);
}

c2go_extern int iswblank_l(wint_t c, locale_t l)
{
	return iswblank(c);
}
