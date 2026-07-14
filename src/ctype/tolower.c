#include <c2go.h>
#include <ctype.h>

c2go_extern int tolower(int c)
{
	if (isupper(c)) return c | 32;
	return c;
}

c2go_extern int tolower_l(int c, locale_t l)
{
	return tolower(c);
}

