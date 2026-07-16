#include <string.h>
#include <libgen.h>
#include <c2go.h>

c2go_extern char *basename(char *s)
{
	size_t i;
	if (!s || !*s) return ".";
	i = strlen(s)-1;
	for (; i&&s[i]=='/'; i--) s[i] = 0;
	for (; i&&s[i-1]!='/'; i--);
	return s+i;
}
/* c2go: weak_alias __xpg_basename omitted (glibc-compat name, no consumer). */
