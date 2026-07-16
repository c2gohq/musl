#include <fenv.h>
#include <c2go.h>

/* __fesetround wrapper for arch independent argument check */

int __fesetround(int)
    c2go_linkname("github.com/c2gohq/c2go_libc.__fesetround", C2GO_GOABI0);

c2go_extern int fesetround(int r)
{
	if (r != FE_TONEAREST
#ifdef FE_DOWNWARD
		&& r != FE_DOWNWARD
#endif
#ifdef FE_UPWARD
		&& r != FE_UPWARD
#endif
#ifdef FE_TOWARDZERO
		&& r != FE_TOWARDZERO
#endif
	)
		return -1;
	return __fesetround(r);
}
