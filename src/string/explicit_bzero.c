#define _BSD_SOURCE
#include <string.h>
#include <c2go.h>

/* c2go: musl pins the memset with an empty inline-asm memory barrier; c2go
 * has no inline asm, so the pin is an opaque cross-boundary Go no-op
 * (__c2go_opaque_use, conf_bridge.go) -- the optimizer cannot prove the
 * callee ignores the buffer, so the zeroing store cannot be treated as
 * dead. */
void __c2go_opaque_use(void *p)
    c2go_linkname("github.com/c2gohq/c2go_libc.__c2go_opaque_use", C2GO_GOABI0);

c2go_extern void explicit_bzero(void *d, size_t n)
{
	d = memset(d, 0, n);
	__c2go_opaque_use(d);
}
