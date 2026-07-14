#include <c2go.h>
#include <ctype.h>
#undef isascii

c2go_extern int isascii(int c)
{
	return !(c&~0x7f);
}
