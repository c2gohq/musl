#include <c2go.h>
#include <ctype.h>
#undef isalpha

c2go_extern int isalpha(int c)
{
	return ((unsigned)c|32)-'a' < 26;
}

c2go_extern int isalpha_l(int c, locale_t l)
{
	return isalpha(c);
}

