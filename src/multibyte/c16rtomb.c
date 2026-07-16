#include <c2go.h>
#include <uchar.h>
#include <errno.h>
#include <wchar.h>

c2go_extern size_t c16rtomb(char *restrict s, char16_t c16, mbstate_t *restrict ps)
{
	static unsigned internal_state;
	if (!ps) ps = (void *)&internal_state;
	unsigned *x = (unsigned *)ps;
	/* c2go: full scalar, not wchar_t — a combined surrogate pair exceeds the
	 * 16-bit wchar_t of the UTF-16 windows target. Identical on unix. */
	unsigned wc;

	if (!s) {
		if (*x) goto ilseq;
		return 1;
	}

	if (!*x && c16 - 0xd800u < 0x400) {
		*x = c16 - 0xd7c0 << 10;
		return 0;
	}

	if (*x) {
		if (c16 - 0xdc00u >= 0x400) goto ilseq;
		else wc = *x + c16 - 0xdc00;
		*x = 0;
	} else {
		wc = c16;
	}
	/* c2go: encode via c32rtomb, whose folding windows block handles the
	 * supplementary scalar a 16-bit wcrtomb cannot (on unix c32rtomb IS
	 * wcrtomb — byte behaviour identical to musl's direct call). */
	return c32rtomb(s, wc, 0);

ilseq:
	*x = 0;
	errno = EILSEQ;
	return -1;
}
