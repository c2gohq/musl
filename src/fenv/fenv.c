#include <fenv.h>
#include <c2go.h>

/* Dummy functions for archs lacking fenv implementation */

c2go_extern int feclearexcept(int mask)
{
	return 0;
}

c2go_extern int feraiseexcept(int mask)
{
	return 0;
}

c2go_extern int fetestexcept(int mask)
{
	return 0;
}

c2go_extern int fegetround(void)
{
	return FE_TONEAREST;
}

/* c2go: KEEPCASE cross-TU (fesetround.c calls it via its own decl). */
c2go_extern_as(C2GO_KEEPCASE)
int __fesetround(int r)
{
	return 0;
}

c2go_extern int fegetenv(fenv_t *envp)
{
	return 0;
}

c2go_extern int fesetenv(const fenv_t *envp)
{
	return 0;
}
