#include <wctype.h>
#include <c2go.h>

c2go_extern int iswgraph(wint_t wc)
{
	/* ISO C defines this function as: */
	return !iswspace(wc) && iswprint(wc);
}

c2go_extern int iswgraph_l(wint_t c, locale_t l)
{
	return iswgraph(c);
}
