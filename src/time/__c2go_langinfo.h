#ifndef __C2GO_LANGINFO_H
#define __C2GO_LANGINFO_H
/* c2go: C-locale langinfo shim. The locale cluster (musl src/locale/langinfo.c)
 * is not yet built in c2go-libc2, so the LC_TIME callers (strftime/strptime/
 * asctime_r) resolve nl_item codes against musl's own C-locale LC_TIME table,
 * carried here verbatim. This mirrors __nl_langinfo_l's LC_TIME branch exactly
 * (musl src/locale/langinfo.c); drop it and route back to the real
 * __nl_langinfo_l once the locale cluster migrates. */
#include <langinfo.h>

static const char __c2go_c_time[] =
	"Sun\0" "Mon\0" "Tue\0" "Wed\0" "Thu\0" "Fri\0" "Sat\0"
	"Sunday\0" "Monday\0" "Tuesday\0" "Wednesday\0"
	"Thursday\0" "Friday\0" "Saturday\0"
	"Jan\0" "Feb\0" "Mar\0" "Apr\0" "May\0" "Jun\0"
	"Jul\0" "Aug\0" "Sep\0" "Oct\0" "Nov\0" "Dec\0"
	"January\0"   "February\0" "March\0"    "April\0"
	"May\0"       "June\0"     "July\0"     "August\0"
	"September\0" "October\0"  "November\0" "December\0"
	"AM\0" "PM\0"
	"%a %b %e %T %Y\0"
	"%m/%d/%y\0"
	"%H:%M:%S\0"
	"%I:%M:%S %p\0"
	"\0"
	"\0"
	"%m/%d/%y\0"
	"0123456789\0"
	"%a %b %e %T %Y\0"
	"%H:%M:%S";

static const char *__c2go_langinfo(nl_item item)
{
	int idx = item & 65535;
	const char *str = __c2go_c_time;
	for (; idx; idx--, str++) for (; *str; str++);
	return str;
}
#endif
