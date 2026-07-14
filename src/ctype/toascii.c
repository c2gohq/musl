#include <c2go.h>
#include <ctype.h>

/* nonsense function that should NEVER be used! */
c2go_extern int toascii(int c)
{
	return c & 0x7f;
}
