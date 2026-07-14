#include <c2go.h>
#include <ctype.h>
#undef isupper

c2go_extern int isupper(int c)
{
	return (unsigned)c-'A' < 26;
}

c2go_extern int isupper_l(int c, locale_t l)
{
	return isupper(c);
}

