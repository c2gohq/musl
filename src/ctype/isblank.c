#include <c2go.h>
#include <ctype.h>

c2go_extern int isblank(int c)
{
	return (c == ' ' || c == '\t');
}

c2go_extern int isblank_l(int c, locale_t l)
{
	return isblank(c);
}

