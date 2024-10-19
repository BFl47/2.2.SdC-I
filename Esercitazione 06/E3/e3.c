#include "e3.h"
#include <stdlib.h>
// La funzione my_strpbrk(s1, s2) deve restituire il puntatore alla prima 
// occorrenza in `s1` di un qualsiasi carattere presente nella stringa `s2` 
// oppure `NULL` se alcun carattere di s2 appare in `s1` prima che `s1` 
// stessa termini.

// scrivere la soluzione qui...
char *my_strpbrk(const char *s1, const char *s2) {
	char* c = NULL;
	char* esse1 = (char*) s1;
	while (*esse1) {
		char* esse2 = (char*) s2;
		int ok = 1;
		while (*esse2 && ok) {
			if (*esse1 == *esse2) {
				c = esse1;
				ok = 0;
			}
			esse2++;
		}
		if (c != NULL)
			break;
		esse1++;
	}
	return c;	
}
