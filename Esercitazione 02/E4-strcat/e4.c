// scrivere la soluzione qui...
int my_len(const char *src) {
	if (*src == '\0')
		return 0;
	return 1 + my_len(src + 1);
}

char *my_strcat(char *dest, const char *src) {
	int i = 0, j = 0;
	while (dest[i] >= 'a' && dest[i] <= 'z' || dest[i] == ' ')
		i++;
	while (j <= my_len(src)) {
		dest[i] = src[j];
		i++;
		j++;
	}
	return dest;
}


	
