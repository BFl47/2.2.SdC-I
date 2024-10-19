#include "e1B.h"

int crc32b(char *bytes, int n) {
    int ebx = ~0; // operazione: not
    int edi = ebx;
    int ebp = n;
    char* esi = bytes;
L:
    if (ebp == 0)
        goto E;
    
    int value;
    int a = *esi;
    esi++;
    a = edi ^ a;
    a = a & 0xFF;
    get_constant(&value, a);
    edi = edi >> 8;
    edi = edi ^ value;
    ebp--;
    goto L;
E:
    return edi ^ ebx;
}

//magic -> ebx
//crc   -> edi
//n     -> ebp  
//bytes -> esi  