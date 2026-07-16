#include <stdlib.h>
#include <string.h>
#include "rand48.h"

c2go_extern void lcong48(unsigned short p[7])
{
	memcpy(__seed48, p, sizeof __seed48);
}
