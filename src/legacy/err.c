#include <err.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <c2go.h>

/* c2go: musl's __libc_start_main fills __progname from argv[0]; c2go's entry
 * is the c2go-bind Go main wrapper, so it is filled lazily from the Go bridge
 * (basename of os.Args[0]) on first use. The #define rewrites the verbatim
 * bodies' reads into the lazy getter. */
char *__progname;
char *__c2go_progname(void)
    c2go_linkname("github.com/c2gohq/c2go_libc.__c2go_progname", C2GO_GOABI0);
static char *progname(void)
{
	if (!__progname) __progname = __c2go_progname();
	return __progname;
}
#define __progname (progname())

c2go_extern void vwarn(const char *fmt, va_list ap)
{
	fprintf (stderr, "%s: ", __progname);
	if (fmt) {
		vfprintf(stderr, fmt, ap);
		fputs (": ", stderr);
	}
	perror(0);
}

c2go_extern void vwarnx(const char *fmt, va_list ap)
{
	fprintf (stderr, "%s: ", __progname);
	if (fmt) vfprintf(stderr, fmt, ap);
	putc('\n', stderr);
}

c2go_extern _Noreturn void verr(int status, const char *fmt, va_list ap)
{
	vwarn(fmt, ap);
	exit(status);
}

c2go_extern _Noreturn void verrx(int status, const char *fmt, va_list ap)
{
	vwarnx(fmt, ap);
	exit(status);
}

c2go_extern void warn(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vwarn(fmt, ap);
	va_end(ap);
}

c2go_extern void warnx(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vwarnx(fmt, ap);
	va_end(ap);
}

c2go_extern _Noreturn void err(int status, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	verr(status, fmt, ap);
	va_end(ap);
}

c2go_extern _Noreturn void errx(int status, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	verrx(status, fmt, ap);
	va_end(ap);
}
