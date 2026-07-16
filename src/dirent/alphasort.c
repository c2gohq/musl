#include <string.h>
#include <dirent.h>
#include <c2go.h>

c2go_extern int alphasort(const struct dirent **a, const struct dirent **b)
{
	return strcoll((*a)->d_name, (*b)->d_name);
}
