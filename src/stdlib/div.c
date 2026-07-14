#include <c2go.h>
#include <stdlib.h>

c2go_extern div_t div(int num, int den)
{
	return (div_t){ num/den, num%den };
}
