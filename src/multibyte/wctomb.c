#include <c2go.h>
#include <stdlib.h>
#include <wchar.h>

c2go_extern int wctomb(char *s, wchar_t wc)
{
	if (!s) return 0;
	return wcrtomb(s, wc, 0);
}
