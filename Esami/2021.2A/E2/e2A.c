#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* load(const char* filename, unsigned* size) {
	int e;
	*size = 0;
	
	FILE* f = fopen(filename, "r");
	if (f == NULL) {	
		perror("fopen");
		return NULL;
	}
	e = fseek(f, 0, SEEK_END);
	if (e == -1) {
		perror("fseek");
		return NULL;
	}
	*size = ftell(f);
	e = fseek(f, 0, SEEK_SET);
	if (e == -1) {
		perror("fseek");
		return NULL;
	}
	
	char line[512];
	e = fread(line, 1, *size, f);
	if (e != *size) {
		perror("fread");
		return NULL;
	}
	
	char* ris = strdup(line); //malloc + strcpy
	return ris;

	
}
