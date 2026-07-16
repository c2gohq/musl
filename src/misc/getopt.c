#define _BSD_SOURCE
#include <unistd.h>
#include <wchar.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <c2go.h>
/* c2go: locale_impl.h/stdio_impl.h dropped — no message catalogs (the
 * LC_MESSAGES translation is the identity) and the FLOCK bracket becomes a
 * no-op: each fputs/fwrite/putc self-locks its FILE; only the diagnostic's
 * atomicity vs concurrent stderr writers is lost (cosmetic). The BSD optreset
 * alias is a <getopt.h> #define onto __optreset (c2go doesn't lower
 * weak_alias); __posix_getopt is omitted. */
#define __lctrans_cur(msg) (msg)
#define FLOCK(f) ((void)0)
#define FUNLOCK(f) ((void)0)

char *optarg;
int optind=1, opterr=1, optopt, __optpos, __optreset=0;

#define optpos __optpos

/* c2go: KEEPCASE cross-TU export (getopt_long.c calls it; the linkname
 * declaration lives in <getopt.h>). */
c2go_extern_as(C2GO_KEEPCASE)
void __getopt_msg(const char *a, const char *b, const char *c, size_t l)
{
	FILE *f = stderr;
	b = __lctrans_cur(b);
	FLOCK(f);
	fputs(a, f)>=0
	&& fwrite(b, strlen(b), 1, f)
	&& fwrite(c, 1, l, f)==l
	&& putc('\n', f);
	FUNLOCK(f);
}

c2go_extern int getopt(int argc, char * const argv[], const char *optstring)
{
	int i;
	wchar_t c, d;
	int k, l;
	char *optchar;

	if (!optind || __optreset) {
		__optreset = 0;
		__optpos = 0;
		optind = 1;
	}

	if (optind >= argc || !argv[optind])
		return -1;

	if (argv[optind][0] != '-') {
		if (optstring[0] == '-') {
			optarg = argv[optind++];
			return 1;
		}
		return -1;
	}

	if (!argv[optind][1])
		return -1;

	if (argv[optind][1] == '-' && !argv[optind][2])
		return optind++, -1;

	if (!optpos) optpos++;
	if ((k = mbtowc(&c, argv[optind]+optpos, MB_LEN_MAX)) < 0) {
		k = 1;
		c = 0xfffd; /* replacement char */
	}
	optchar = argv[optind]+optpos;
	optpos += k;

	if (!argv[optind][optpos]) {
		optind++;
		optpos = 0;
	}

	if (optstring[0] == '-' || optstring[0] == '+')
		optstring++;

	i = 0;
	d = 0;
	do {
		l = mbtowc(&d, optstring+i, MB_LEN_MAX);
		if (l>0) i+=l; else i++;
	} while (l && d != c);

	if (d != c || c == ':') {
		optopt = c;
		if (optstring[0] != ':' && opterr)
			__getopt_msg(argv[0], ": unrecognized option: ", optchar, k);
		return '?';
	}
	if (optstring[i] == ':') {
		optarg = 0;
		if (optstring[i+1] != ':' || optpos) {
			optarg = argv[optind++];
			if (optpos) optarg += optpos;
			optpos = 0;
		}
		if (optind > argc) {
			optopt = c;
			if (optstring[0] == ':') return ':';
			if (opterr) __getopt_msg(argv[0],
				": option requires an argument: ",
				optchar, k);
			return '?';
		}
	}
	return c;
}
