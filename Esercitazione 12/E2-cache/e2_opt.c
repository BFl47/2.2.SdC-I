#include "e2.h"

long f_opt(const short *v, unsigned n){
    long x = 0;
    unsigned i, j;
    for (j = 0; j < n; j += 64) {
		for (i = 0; i < 64; i++) 
			x += v[i+j];
	}
    return x;
}
//n = 150

//i - j
//0+0 		0
//0+64		64
//0+128		128

//1+0		1
//1+64		65
//1+128		129

//..

//j - i
//0+0		0
//0+1		1
//..		..
//0+63		63

//64+0		64
//64+1		65
//..		..
//64+63		127

//..
