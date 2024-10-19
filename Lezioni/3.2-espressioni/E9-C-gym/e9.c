#include "e9.h"

int mystrlen(const char *s){
	int cnt = 0;
	while (*s++) cnt++;
	return cnt;
}

void mystrcat(char *dest, const char *src){
	while (*dest) dest++;
	while (*src) *dest++ = *src++;
}

int is_palindrome(const char* s){
	int len = mystrlen(s);
	int i = 0, j = len-1;
	while (i < j) {
		if (s[i] != s[j])
			return 0;
		i++;
		j--;
	}
	return 1;
}
