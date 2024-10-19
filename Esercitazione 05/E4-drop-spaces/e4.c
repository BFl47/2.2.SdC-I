#include <stdlib.h>

int my_len(char* text) {
	if (*text == '\0')
		return 0;
	return 1 + my_len(text+1);
}

void drop_spaces(char* text) {
	int i, j;
	char* ris = (char*) malloc(80* sizeof(char));
	for (i = 0, j = 0; text[i] != '\0'; i++) {
		if (text[i] != ' ') {
			ris[j] = text[i];
			j++;
		}
	}
	for (i = 0; i < my_len(text); i++) {
		text[i] = ris[i];
	}
	text[i] = '\0';
}
