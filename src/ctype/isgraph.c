#include <c2go.h>
#include <ctype.h>
#undef isgraph

c2go_extern int isgraph(int c)
{
	return (unsigned)c-0x21 < 0x5e;
}

c2go_extern int isgraph_l(int c, locale_t l)
{
	return isgraph(c);
}

