#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "e1.h"

int parseCSV(const char* file, person_t** out, int minAge) {
	*out = NULL;
	
	FILE* f = fopen(file, "r");
	if (f == NULL) return -1;
	
	person_t* last = NULL;
	while (1) {
		char line[64];
		char* res = fgets(line, sizeof(line), f);
		if (res == NULL) break;
		
		//printf("Line: %s\n", line);
		char nome[64], surname[64], data[11], phd[5];
		for(int i = 0; i < 4; i++) {
			char* token = strtok(res, ",");
			if (token == NULL) {
				fclose(f);
				return -1;
			}
			int len = strlen(token);
			if (token[len-1] == '\n') 
				token[len-1] = '\0';
			//printf("Token: %s\n", token);
			
			switch(i) {
				case 0: {strcpy(nome, token); break;}
				case 1: {strcpy(surname, token); break;}
				case 2: {strcpy(data, token); break;}
				case 3: {strcpy(phd, token); break;}
				default: {fclose(f); return -1;}
			}
			res = NULL;
		}
		int year = atoi(data+6);
		if (year >= minAge) {
			person_t* current = malloc(sizeof(person_t));
			if (current == NULL) {fclose(f); return -1;}
			
			//copia allocata dinamicamente con strdup -> riassume:
			//current->name = malloc(strlen(nome)+1);
			//strcpy(current->name, nome);
			
			current->name = strdup(nome);
			current->surname = strdup(surname);
			current->year = year;
			current->has_phd = strcmp(phd, "yes") == 0 ? 1 : 0; //operatore ternario
			current->next = NULL;
			
			if (last == NULL) {
				*out = current;
			} else {
				last->next = current;
			}
			last = current;
		}
	}
	if (fclose(f) != 0) return -1;
	
	return 0;
	
}
