#include "time_impl.h"
#include <errno.h>

c2go_extern struct tm *gmtime(const time_t *t)
{
	static struct tm tm;
	return gmtime_r(t, &tm);
}
