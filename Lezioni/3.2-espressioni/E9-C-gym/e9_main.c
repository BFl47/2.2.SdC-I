#include <stdio.h>
#include "e9.h"

int main() {

	int strl = mystrlen("ciao");
	printf("%d\n", strl);

	int x = 
		is_palindrome(
		   "docnoteidissentafastneverpreventsafatnessidietoncod");
	printf("%d\n", x);

	x = is_palindrome("nonepalindroma");
	printf("%d\n", x);

	x = is_palindrome("n");
	printf("%d\n", x);

	x = is_palindrome("");
	printf("%d\n", x);

	char buf[64] = "Hello ";
	mystrcat(buf, "World!");
	printf("%s\n", buf);

	return 0;
}

