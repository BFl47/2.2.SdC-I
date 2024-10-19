int len(const char* s) {
	if (*s == 0)
		return 0;
	return 1 + len(s+1);
}

int equal(const char* s, const char* sub) {
	if (*s != *sub)
		return 0;
	if (*s == 0 && *sub == 0)
		return 1;
	return 1 && equal(s+1, sub+1);
		
}
	
int count_substrings(const char* s, const char* sub) {
	int i = 0;
	int count = 0;
	if (equal(s, sub))
		return 1;
	while (i < len(s)) {
		int j = 0;
		int k = i;
		int ok = 1;
		while (j < len(sub)) {
			if (s[k] != sub[j])
				ok = 0;
			j++;
			k++;
		}
		if (ok) count++;
		i++;
	}
	return count;	
}
