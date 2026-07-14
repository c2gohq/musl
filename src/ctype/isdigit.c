#include <c2go.h>
#include <ctype.h>
#undef isdigit

c2go_extern int isdigit(int c)
{
	return (unsigned)c-'0' < 10;
}

c2go_extern int isdigit_l(int c, locale_t l)
{
	return isdigit(c);
}

