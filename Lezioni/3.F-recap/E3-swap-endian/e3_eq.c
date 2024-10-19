// Scrivere C equivalente qui...
#include "e3.h"

unsigned swap_endianness(unsigned c) {
	unsigned c1 = c;
	unsigned d;
	unsigned b = (c1 & 0x000000FF);
	b = b << 24;
	d = b;
	//d = (c1 & 0x000000FF) << 24;
	b = (c1 & 0x0000FF00);
	b = b << 8;
	d ^= b;
	//d ^= (c1 & 0x0000FF00) << 8;
	b = (c1 & 0x00FF0000);
	b = b >> 8;
	d ^= b;
	//d ^= (c1 & 0x00FF0000) >> 8;
	b = (c1 & 0xFF000000);
	b = b >> 24;
	d ^= b;
	//d ^= (c1 & 0xFF000000) >> 24;
	unsigned a = d;
	return a;
}
