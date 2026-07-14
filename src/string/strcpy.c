#include <c2go.h>
#include <string.h>

c2go_extern char *strcpy(char *restrict dest, const char *restrict src)
{
	stpcpy(dest, src);
	return dest;
}
