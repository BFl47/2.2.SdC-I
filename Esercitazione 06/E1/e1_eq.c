// Inserisci qui il C equivalente...
/*
typedef struct node_t {			base
    short elem;					offset 0	|xx--|
    struct node_t *next;		offset 4	|xxxx|
} node_t;						sizeof 8
*/
#include <stdlib.h>
#include "e1.h"

int list_add_first(node_t **l, short elem) {
    node_t** b1 = l;
    node_t* b = *b1;
	int d = 8;
    int a1;
    node_t *a = malloc(sizeof(node_t));
    if (a == NULL) goto E;          // allocation error
    short d1 = elem;
    a->elem = elem;
    a->next = b;
    *b1 = a;
    a1 = 0;
    goto E1;
E:
	a1 = -1;
E1:
	return a1;
}
