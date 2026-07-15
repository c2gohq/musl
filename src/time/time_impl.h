#include <time.h>
#include <locale.h>   /* c2go: locale_t appears in the __strftime_fmt_1 decl below */
#include <c2go.h>

/* c2go: musl force-includes features.h (which defines `hidden` = ELF hidden
 * visibility). We do not pull it, and c2go governs export via c2go_extern, so
 * neutralise `hidden`. */
#ifndef hidden
#define hidden
#endif

/* c2go: these package-internal helpers are referenced across TUs (musl splits
 * them into their own files). A bare-extern reference would be misjudged by
 * c2go-lto as an unmanaged host import, so mark the declarations package-internal
 * with the C2GO_FUNC world bit -- this keeps the default internal calling
 * convention (matching the plain C definitions). It is NOT a c2go_extern export
 * and NOT a c2go_linkname (which targets a Go-boundary ABI). __ensure_tz is
 * defined in csrc/time.c (the tz snapshot); the rest live in musl's own files. */
#pragma c2go managed(1) push
hidden int __days_in_month(int, int);
hidden int __month_to_secs(int, int);
hidden long long __year_to_secs(long long, int *);
hidden long long __tm_to_secs(const struct tm *);
hidden const char *__tm_to_tzname(const struct tm *);
hidden int __tzname_to_isdst(const char *restrict *);
hidden int __secs_to_tm(long long, struct tm *);
hidden void __secs_to_zone(long long, int, int *, long *, long *, const char **);
hidden const char *__strftime_fmt_1(char (*)[100], size_t *, int, const struct tm *, locale_t, int);
hidden void __ensure_tz(void);
#pragma c2go pop
extern hidden const char __utc[];
