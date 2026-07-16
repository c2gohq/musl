#define _GNU_SOURCE
#include <string.h>
#include <dirent.h>
#include <c2go.h>

c2go_extern int versionsort(const struct dirent **a, const struct dirent **b)
{
	return strverscmp((*a)->d_name, (*b)->d_name);
}
