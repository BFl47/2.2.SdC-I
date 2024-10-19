#include "e2B.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void getBookingsAfterTime(struct booking ** list, const char * filename, const char * time) {
	int h, m, tempo;
	sscanf(time, "%d:%d", &h, &m);
	tempo = m + h*60;
	
	*list = NULL;
	struct booking* elem;
	struct booking* last = NULL;
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		perror("fopen");
		return;
	}
	
	fseek(f, 0, SEEK_END);
	int dim = ftell(f);
	fseek(f, 0, SEEK_SET);
	
	char buf[dim];
	fread(buf, dim, 1, f);
	
	int i = 0;
	while (i < dim) {		
		char* cognome = malloc(31);
		char* posti = malloc(3);
		char* orario = malloc(6);
		
		memcpy(cognome, buf+i, 30);
		strtok(cognome, "_");
		i += 30;
		memcpy(posti, buf+i, 2);
		posti[2] = '\0';
		i += 2;
		memcpy(orario, buf+i, 5);
		orario[5] = '\0';
		i+= 5;
		
		int pl = atoi(posti);
		int ore, minuti, tcorr;
		sscanf(orario, "%d:%d", &ore, &minuti);
		tcorr = minuti + ore*60;
		
		if (tcorr >= tempo) {
			elem = malloc(sizeof(struct booking));
			elem->surname = strdup(cognome);
			elem->places = atoi(posti);
			elem->time = strdup(orario);
			elem->next = NULL;
			//printf("cognome: %s, posti: %d, orario: %s\n", elem->surname, elem->places, elem->time);
			if (*list == NULL) {
				*list = elem;
			}
			else
				last->next = elem;
			last = elem;
		}
		
		free(cognome);
		free(posti);
		free(orario);
		
	}
	struct booking* vecchio = *list;
	while (*list != NULL) {
		printf("cognome: %s, posti: %d, orario: %s\n", (*list)->surname, (*list)->places, (*list)->time);
		*list = (*list)->next;
	}
	*list = vecchio;
	if (f != NULL)
		fclose(f);
	
	
	
	
}
