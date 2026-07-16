/* c2go: unix-only, like nftw (<ftw.h> #errors on windows). */
#if !defined(_WIN32)
#include <ftw.h>
#include <c2go.h>

c2go_extern int ftw(const char *path, int (*fn)(const char *, const struct stat *, int), int fd_limit)
{
	/* The following cast assumes that calling a function with one
	 * argument more than it needs behaves as expected. This is
	 * actually undefined, but works on all real-world machines. */
	return nftw(path, (int (*)())fn, fd_limit, FTW_PHYS);
}

#endif /* !_WIN32 */
