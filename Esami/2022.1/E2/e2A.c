#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int loadStringsFromFile (const char * filename, char *** list) {
	int e;
	*list = NULL;
	FILE * f = fopen(filename, "r");
	if (f == NULL) {
		perror("fopen");
		return -1;
	}
	
	char line[512];
	int dim = 0;
	while (fgets(line, 512, f)) {
		if (isalpha(line[0])) 
			dim++;
	}
	e = fseek(f, 0, SEEK_SET);
		if (e == -1)
			goto cleanup;

	*list = malloc(sizeof(char*) * dim);
	int i = 0;
	while (fgets(line, 80, f)) {
		if (isalpha(line[0])) {
			(*list)[i] = strdup(line);
			i++;
		}
	}
	if (f != NULL)
		fclose(f);
	return dim;
	
cleanup:
	if (f != NULL)
		fclose(f);
	return -1;
	
}
