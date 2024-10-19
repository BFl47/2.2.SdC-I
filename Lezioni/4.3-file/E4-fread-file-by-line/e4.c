#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "e4.h"

int read_file_by_line(const char *filename, char ***lines, int *num_lines) {
	FILE* f  = NULL;
	
	f = fopen(filename, "r");
	if (f == NULL) goto cleanup;
	
	*num_lines = 0;
	char corrente[80];
	
	while (fgets(corrente, 80, f) != NULL) {
		printf("%s", corrente);
		(*num_lines)++;
	}
	printf("righe: %d\n", *num_lines);
	
	int close = fclose(f);
	if (close == EOF) goto cleanup;
	
	FILE* f1 = NULL;
	f1 = fopen(filename, "r");
	if (f1 == NULL) goto cleanup;
	
	*lines = malloc(*num_lines * sizeof(char*));
	for (int i = 0; i < *num_lines; i++) {
		(*lines)[i] = malloc(20);
		fgets((*lines)[i], 20, f1);
	}
	
	close = fclose(f1);
	if (close == EOF) goto cleanup;

	return 0;

cleanup:
	return -1;
}

void deallocate_lines(char **lines, int num_lines) {
	for (int i = 0; i < num_lines; i++) 
		free(lines[i]);
	free(lines);
}
