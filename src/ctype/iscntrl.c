#include <c2go.h>
#include <ctype.h>

c2go_extern int iscntrl(int c)
{
	return (unsigned)c < 0x20 || c == 0x7f;
}

c2go_extern int iscntrl_l(int c, locale_t l)
{
	return iscntrl(c);
}

