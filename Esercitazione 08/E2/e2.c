// scrivi qui la tua soluzione
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "e2.h"

struct booking * getBookings_aux(char * data2, int hh, int mm) {
	if (*data2 == '\0')
		return NULL;
		
	char* cognome = malloc(30);
	char* posti = malloc(2);
	char* tempo = malloc(5);

	memcpy(cognome, data2, 30);
	data2 += 30;
	memcpy(posti, data2, 2);
	data2 += 2;
	memcpy(tempo, data2, 5);
	data2 += 5;
	
	int ore, minuti;
	sscanf(tempo, "%d:%d", &ore, &minuti);
	char* token = strtok(cognome, "_");
	
	struct booking* ris = NULL;
	
	if (ore == hh && minuti >= mm || ore > hh) {
		ris = malloc(sizeof(struct booking));
		ris->surname = cognome;
		ris->places = atoi(posti);
		ris->time = tempo;
		ris->next = getBookings_aux(data2, hh, mm);	
	}
	else ris = getBookings_aux(data2, hh, mm);
	
	return ris;
}

void getBookingsAfterTime(struct booking ** list, const char * data, int size, const char * time) {
	
	char* data2 = (char*) data;
	int hh, mm;
	sscanf(time, "%d:%d", &hh, &mm);
	
	*list = getBookings_aux(data2, hh, mm);
	/*
	//ATTENZIONE! Questa stampa modifica il valore di list
	struct booking ** copia = list;
	while (*copia) {
		printf("elem struct_cognome: %s - posti: %d - tempo: %s\n", (*copia)->surname, (*copia)->places, (*copia)->time);
		*copia = (*copia)->next;
	}
	*/
}


