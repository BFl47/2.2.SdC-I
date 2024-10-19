int myabs(int x) {
	int a = x;
	if (a >= 0) goto E;			//if (a >= 0) <-> if (a - 0 >= 0)
	a = -a;										//	  D   S
	E: return a;
}
