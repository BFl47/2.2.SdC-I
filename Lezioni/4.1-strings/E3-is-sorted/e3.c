// Inserisci soluzione qui...

#include <string.h>

int is_sorted(char *v[], int n) {
	if (n-1 == 0 || n == 0)
		return 0;
	if (strcmp(*v, *(v+1)) >= 0)
		return -1;
	else return is_sorted(v+1, n-1);
}



