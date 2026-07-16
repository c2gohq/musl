#include <math.h>
#include "libm.h"

int __signgam = 0;

/* c2go: data weak_alias -> #define signgam __signgam in <math.h> (optreset precedent). */
