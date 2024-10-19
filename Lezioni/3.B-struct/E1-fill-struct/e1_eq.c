// Inserisci qui il C equivalente
/*
typedef struct {		//base
    char age;  			//offset  	0	|x---|	   
    char* name;     	//offset	4	|xxxx|
    char gender;  		//offset 	8	|x---|
} person_t;				//sizeof	12
*/
#include "e1.h"

void fill(person_t* p, char age, char* name, char gender) {
    person_t* a = p;
    char c = age;
    a->age = c;
    char* c1 = name;
    a->name = c1;
    c = gender;
    a->gender = c;
    
}
