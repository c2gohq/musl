#include <c2go.h>
#include <uchar.h>
#include <errno.h>
#include <wchar.h>

c2go_extern size_t c32rtomb(char *restrict s, char32_t c32, mbstate_t *restrict ps)
{
	/* c2go: on the 16-bit-wchar_t (UTF-16 windows) target a supplementary
	 * scalar does not fit wcrtomb's wchar_t parameter — encode its 4 UTF-8
	 * bytes here, and reject > U+10FFFF (which truncation would otherwise
	 * fold into a bogus small scalar). Folds away where wchar_t is 32-bit
	 * (unix), leaving musl's plain delegation to wcrtomb. */
	if (sizeof(wchar_t) < 4 && s && (unsigned)c32 >= 0x10000) {
		if ((unsigned)c32 - 0x10000 >= 0x100000) {
			errno = EILSEQ;
			return -1;
		}
		*s++ = 0xf0 | (c32>>18);
		*s++ = 0x80 | ((c32>>12)&0x3f);
		*s++ = 0x80 | ((c32>>6)&0x3f);
		*s = 0x80 | (c32&0x3f);
		return 4;
	}
	return wcrtomb(s, c32, ps);
}
