#include <search.h>
#include <c2go.h>

/* AVL tree height < 1.44*log2(nodes+2)-0.3, MAXH is a safe upper bound.  */
#define MAXH (sizeof(void*)*8*3/2)

struct node {
	const void *key;
	void *a[2];
	int h;
};

/* c2go: cross-TU internal (tsearch.c defines, tdelete.c calls) — linkname
 * declaration here + c2go_extern_as(C2GO_KEEPCASE) on the definition (a bare
 * extern would be an unmanaged HOST import under the default-unmanaged model
 * and trip the c2go-lto name-collision guard). */
int __tsearch_balance(void **)
    c2go_linkname("github.com/c2gohq/c2go_libc.__tsearch_balance", C2GO_GOABI0);
