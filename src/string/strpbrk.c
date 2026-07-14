#include <c2go.h>
#include <string.h>

c2go_extern char *strpbrk(const char *s, const char *b)
{
	s += strcspn(s, b);
	return *s ? (char *)s : 0;
}
