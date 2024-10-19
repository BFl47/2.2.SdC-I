#include "e2.h"

int crc32b(char *bytes, int n) {
    int esi = 0; // operazione: not
    esi = ~esi;
    int ebi = esi;
    int esb = n;
    char* b = bytes;
    int value, c;
L:
	if (esb == 0) goto E;
	c = *b;
	b++;
	c = ebi ^ c;
	c = c & 0xFF;
	get_constant(&value, c);
	ebi = ebi >> 8;
	ebi ^= value;	
	esb--;
	goto L;
E:
	esi ^= ebi;
	int a = esi;
	return a;
}

//magic -> esi
//crc -> ebi
//n -> esb
//bytes -> ebx
//byte -> c
//index -> c

/*
 * n		36
 * bytes	32
 * ret		28
 * esi		24
 * edi		20
 * esb		16
 * ebx		12
 * value	8
 * c		4
 * &value
 */ 
