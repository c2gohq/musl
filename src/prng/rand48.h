#include <stdint.h>
#include <c2go.h>

/* c2go: cross-TU internal (__rand48_step.c defines KEEPCASE, the rand48
 * family calls) — linkname declaration, same pattern as tsearch.h. The
 * mutable __seed48 DATA definition (__seed48.c, pristine) is referenced as a
 * plain extern, like the __fsmu8 table. */
uint64_t __rand48_step(unsigned short *xi, unsigned short *lc)
    c2go_linkname("github.com/c2gohq/c2go_libc.__rand48_step", C2GO_GOABI0);
extern unsigned short __seed48[7];
