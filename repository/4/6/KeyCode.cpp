#include <stdio.h>
#include <stdlib.h>

int RaizQuad(int n, int i, int f) {
	// assume n >= 0, i <= ⌊√(n)⌋ < f
	// retorna ⌊√(n)⌋
	if (i+1==f) {
		return i;
	} else {
		long long int m = (i+f)/2;
		if (m*m <= n) {
			return RaizQuad(n, m, f);
		} else {
			return RaizQuad(n, i, m);
		}
	}
}

int RaizQuad(int n) {
	// assume n >= 0
	// retorna ⌊√(n)⌋
	return RaizQuad(n, 0, n+1);
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n; 
	while (scanf("%d", &n)>0) {
		if (n>=0) {
			/* teste manual */
			printf("%d\n", RaizQuad(n));
		} else {
			/* teste automático */
			n = 50000; 
			for (int t=1; t<=200; t++) RaizQuad(n);
			printf("%d\n", RaizQuad(n));
		}
	}

	return 0;
}