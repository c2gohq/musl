#include <c2go.h>
#include <stdlib.h>
#include <stdint.h>

static uint64_t seed;

c2go_extern void srand(unsigned s)
{
	seed = s-1;
}

c2go_extern int rand(void)
{
	seed = 6364136223846793005ULL*seed + 1;
	return seed>>33;
}
