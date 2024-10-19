#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int conta_occorrenze(char* s, const char c) {
	int ris = 0;
	while (*s) {
		if (*s == c) 
			ris++;
		s++;
	}
	return ris;	
}

int wordWithMaxCount(const char* text, const char c, char ** word) {
	if (strlen(text) == 0)
		return 0;
	int max = 0;
	
	char* copia = strdup(text);
	char* token = strtok(copia, " ");
	while (token) {
		int count = conta_occorrenze(token, c);
		if (count > max) {
			max = count;
			*word = strdup(token);
		}
		token = strtok(NULL, " ");
	}
	
	return max;
}
