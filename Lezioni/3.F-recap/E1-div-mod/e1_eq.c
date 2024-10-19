// Scrivere C equivalente qui...
#include "e1.h"

void div_mod(int x, int y, int* q, int* r){
	int a = x;
	int b = y;
	
	int* c = q;
	int* edi = r;
	
	int d = a;
	d = d >> 31;
	int a1 = a / b;
	d = a % b;
	
    *c = a1;
    *edi = d;
}
