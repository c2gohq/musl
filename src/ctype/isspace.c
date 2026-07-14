#include <c2go.h>
#include <ctype.h>
#undef isspace

c2go_extern int isspace(int c)
{
	return c == ' ' || (unsigned)c-'\t' < 5;
}

c2go_extern int isspace_l(int c, locale_t l)
{
	return isspace(c);
}

