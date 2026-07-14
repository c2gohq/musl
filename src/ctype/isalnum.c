#include <c2go.h>
#include <ctype.h>

c2go_extern int isalnum(int c)
{
	return isalpha(c) || isdigit(c);
}

c2go_extern int isalnum_l(int c, locale_t l)
{
	return isalnum(c);
}

