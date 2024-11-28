#include <stdio.h>
#include <stdlib.h>

int RaizQuad(int n) {
	// assume n >= 0
	// retorna r tal que r^2 <= n < (r+1)^2
	if (n==0) {
		return 0;
	} else {
		int x = RaizQuad(n-1);
		if ((x+1)*(x+1) == n) {
			x = x+1;
		}
		return x;
	}
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