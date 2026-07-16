#include <c2go.h>
#include <uchar.h>
#include <wchar.h>

c2go_extern size_t mbrtoc32(char32_t *restrict pc32, const char *restrict s, size_t n, mbstate_t *restrict ps)
{
	static unsigned internal_state;
	if (!ps) ps = (void *)&internal_state;
	if (!s) return mbrtoc32(0, "", 1, ps);
	/* c2go: decode via the width-independent scalar core, not mbrtowc — on the
	 * 16-bit-wchar_t (UTF-16 windows) target mbrtowc reports EILSEQ for a
	 * supplementary scalar, but char32_t must carry it. Identical on unix. */
	unsigned cp;
	size_t ret = __mbrtoc32(&cp, s, n, ps);
	if (ret <= 4 && pc32) *pc32 = cp;
	return ret;
}
