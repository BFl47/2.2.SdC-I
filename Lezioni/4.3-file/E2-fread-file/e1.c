#include "e1.h"
#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

int read_file(char *filename, void **buffer, size_t *size){
	FILE* f = fopen(filename, "r");
	*size = 0;
	*buffer = NULL;
	int err;
	
	if (f == NULL) {
		perror("errore apertura");
		return -1;
	}
	
	err = fseek(f, 0, SEEK_END);
	if (err == -1) {
		perror("errore fseek");
		return -1;
	}
	
	*size = ftell(f);
	if (*size == -1) {
		perror("errore fseek");
		return -1;
	}
	
	err = fseek(f, 0, SEEK_SET);
	if (err == -1) {
		perror("errore fseek");
		return -1;
	}
	
	*buffer = malloc(*size);
	if (*buffer == NULL) {
		perror("errore malloc");
		return -1;
	}
	
	err = fread(*buffer, *size, 1, f); 
	if (err != *size) {
		perror("errore lettura");
		return -1;
	}
	
	err = fclose(f);
	if (err != EOF) {
		perror("errore chiusura");
		return -1;
	}
	
	return 0;
	
	
}
