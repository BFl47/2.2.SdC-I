// Scrivi la soluzione qui...
#include "e1.h"
#include "string.h"

int comparator(const void *x, const void *y) {
	char* xt = (*(person_t*)x).name;
	char* yt = (*(person_t*)y).name;
	return strcmp(xt, yt);
}

void sort_people(person_t p[], size_t n) {
	qsort(p, n, sizeof(person_t), comparator);	
}

person_t *find_person(char *key, person_t sorted[], size_t n) {
	person_t* ris = bsearch(&key, sorted, n, sizeof(person_t), comparator);
	return ris;	
}
