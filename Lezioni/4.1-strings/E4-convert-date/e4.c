// Inserisci soluzione qui...

#include <stdio.h> // sscanf, sprintf

int convert_date(const char *input, char *output){
    int uno, due, tre;
    sscanf(input, "%d/%d/%d", &uno, &due, &tre);
    sprintf(output, "%d/%d/%d", due, uno, tre);
    return 0;
}

