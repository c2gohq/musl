#define _GNU_SOURCE
#include <unistd.h>
#include <time.h>
#include <c2go.h>

c2go_extern int usleep(unsigned useconds)
{
	struct timespec tv = {
		.tv_sec = useconds/1000000,
		.tv_nsec = (useconds%1000000)*1000
	};
	return nanosleep(&tv, &tv);
}
