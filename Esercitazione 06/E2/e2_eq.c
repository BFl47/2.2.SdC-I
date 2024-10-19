// Inserisci qui il C equivalente...
/*
typedef struct node_t {			base
    short elem;					offset	0	|xx--|
    struct node_t *next;		offset	4	|xxxx|
} node_t;						sizeof	8
*/

#include <stdlib.h>
#include "e2.h"

int list_equal(const node_t *l1, const node_t *l2) {
	const node_t* c = l1;
	const node_t* d = l2;
	int a = 0;
L:
	if (c == NULL) goto E;
	if (d == NULL) goto E;
	if (c->elem != d->elem) goto Z;
    c = c->next;
    d = d->next;
    goto L;
E:;	
	int al = c == NULL;
	int dl = d == NULL;
	a = al && dl;
Z:
	return a;
}
