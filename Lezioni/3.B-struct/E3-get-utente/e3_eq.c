
#include "e3.h"

/*
 typedef struct {        	base
	char privilegi;      	offset	0	|x-|
	short user_id;       	offset 	2	|xx|
} stud_t; 					sizeof	4
*/

void get_utente(char* privilegi, short* user_id) {
    stud_t a;
    curr_user(&a);
    
    char* c = privilegi;
    char d = a.privilegi;
    *c = d;
    
    short* c1 = user_id;
    short d1 = a.user_id;
    *c1 = d1;
}
