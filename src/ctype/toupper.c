#include <c2go.h>
#include <ctype.h>

c2go_extern int toupper(int c)
{
	if (islower(c)) return c & 0x5f;
	return c;
}

c2go_extern int toupper_l(int c, locale_t l)
{
	return toupper(c);
}

