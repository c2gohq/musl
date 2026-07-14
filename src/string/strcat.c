#include <c2go.h>
#include <string.h>

c2go_extern char *strcat(char *restrict dest, const char *restrict src)
{
	strcpy(dest + strlen(dest), src);
	return dest;
}
