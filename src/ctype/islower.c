#include <c2go.h>
#include <ctype.h>
#undef islower

c2go_extern int islower(int c)
{
	return (unsigned)c-'a' < 26;
}

c2go_extern int islower_l(int c, locale_t l)
{
	return islower(c);
}

