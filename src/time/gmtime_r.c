#include "time_impl.h"
#include <errno.h>

c2go_extern struct tm *gmtime_r(const time_t *restrict t, struct tm *restrict tm)
{
	if (__secs_to_tm(*t, tm) < 0) {
		errno = EOVERFLOW;
		return 0;
	}
	tm->tm_isdst = 0;
	tm->tm_gmtoff = 0;
	tm->tm_zone = "UTC";
	return tm;
}
