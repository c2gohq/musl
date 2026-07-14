#include <c2go.h>
#include <ctype.h>
#undef isprint

c2go_extern int isprint(int c)
{
	return (unsigned)c-0x20 < 0x5f;
}

c2go_extern int isprint_l(int c, locale_t l)
{
	return isprint(c);
}

