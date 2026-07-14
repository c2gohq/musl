#include <c2go.h>
#include <ctype.h>

c2go_extern int isxdigit(int c)
{
	return isdigit(c) || ((unsigned)c|32)-'a' < 6;
}

c2go_extern int isxdigit_l(int c, locale_t l)
{
	return isxdigit(c);
}

