#include <time.h>
#include <c2go.h>

c2go_extern char *ctime(const time_t *t)
{
	struct tm *tm = localtime(t);
	if (!tm) return 0;
	return asctime(tm);
}
