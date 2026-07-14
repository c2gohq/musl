#include <c2go.h>
#include <ctype.h>

c2go_extern int ispunct(int c)
{
	return isgraph(c) && !isalnum(c);
}

c2go_extern int ispunct_l(int c, locale_t l)
{
	return ispunct(c);
}

