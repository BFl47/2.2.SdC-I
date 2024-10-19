#include <stdlib.h>
#include "e2.h"
/*
typedef struct {    base
    char gender;    offset: 0	|x---|
    char* name;     offset: 4	|xxxx|
    char age;       offset: 8	|x---|
} person_t;			sizeof	12
*/
person_t *find_youngest(person_t *v, int n) {
	person_t* c = v;
	person_t* a = NULL;
	int b = 0;
L:
	if (b >= n) goto E;
	if (a == NULL) goto A;
	char d = c->age;
	if (d >= a->age) goto F;
A:
	a = c;
F:
	c++;
	b++;
	goto L;	
E:
	return a;
}
