#include "time_impl.h"

c2go_extern struct tm *localtime(const time_t *t)
{
	static struct tm tm;
	return localtime_r(t, &tm);
}
