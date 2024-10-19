#include <stdio.h>

int main() {
   unsigned x = 0xDEADBEEF;
   //unsigned char y = *(unsigned char*)&x;		//EF
   unsigned short y = *(unsigned short*)&x;		//BEEF
   
   printf("%X\n", y);
   return 0;
}
