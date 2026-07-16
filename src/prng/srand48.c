#include <stdlib.h>
#include <c2go.h>

c2go_extern void srand48(long seed)
{
	seed48((unsigned short [3]){ 0x330e, seed, seed>>16 });
}
