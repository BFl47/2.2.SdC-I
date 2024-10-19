#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "e2.h"

int getTimestamp(const char* time) {
	//formato hh:mm
	int ora, minuti;
	sscanf(time, "%d:%d", &ora, &minuti);
	return ora * 60 + minuti;
}

void getBookingsAfterTime(struct booking ** list, const char * data, int size, const char * time) {
	*list = NULL;
	int start = getTimestamp(time);
	int i = 0;
	
	struct booking * last = NULL;
	
	while(i < size) {
		const char* buf = &data[i];
		i += 37;
		
		int j = 32;
		char time_tmp[6];
		while (j < 37) {
			time_tmp[j-32] = buf[j];
			j += 1;
		}	
		time_tmp[j-32] = '\0';
		
		if (getTimestamp(time_tmp) >= start) {
			struct booking * current = malloc(sizeof(struct booking));
			
			//estrazione del campo cognome
			char cognome[31]; 
			j = 0;
			while (j < 30 && buf[j] != '_') {
				cognome[j] = buf[j];
				j++;
			}
			cognome[j] = '\0';
			//copia del cognome in un buffer allocato dinamicamente
			char* surname = malloc(strlen(cognome)+1);
			strcpy(surname, cognome);
			
			//estratto campo posti
			char posti[3];
			posti[0] = buf[30];
			posti[1] = buf[31];
			posti[2] = '\0';
			//converto da stringa a intero
			int places = atoi(posti);
			
			char* time_curr = malloc(strlen(time_tmp) + 1);
			strcpy(time_curr, time_tmp);
			
			current->surname = surname;
			current->places = places;
			current->time = time_curr;
			current->next = NULL;
			
			//inserire in coda il nodo current
			if (*list == NULL) 
				*list = current;
			else {
				assert(last != NULL);
				last->next = current;
			}
			last = current;
		}
		
		
	}	
}
