#include <c2go.h>
#include <string.h>

c2go_extern char *strrchr(const char *s, int c)
{
	return memrchr(s, c, strlen(s) + 1);
}
