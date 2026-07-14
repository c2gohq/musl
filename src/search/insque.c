#include <c2go.h>
#include <search.h>

struct node {
	struct node *next;
	struct node *prev;
};

c2go_extern void insque(void *element, void *pred)
{
	struct node *e = element;
	struct node *p = pred;

	if (!p) {
		e->next = e->prev = 0;
		return;
	}
	e->next = p->next;
	e->prev = p;
	p->next = e;
	if (e->next)
		e->next->prev = e;
}

c2go_extern void remque(void *element)
{
	struct node *e = element;

	if (e->next)
		e->next->prev = e->prev;
	if (e->prev)
		e->prev->next = e->next;
}
