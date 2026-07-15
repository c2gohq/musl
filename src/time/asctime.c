#include <time.h>
#include <c2go.h>

c2go_extern char *asctime(const struct tm *tm)
{
	static char buf[26];
	return asctime_r(tm, buf);
}
