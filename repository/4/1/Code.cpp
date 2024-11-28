#include <stdio.h>
#include <stdlib.h>

int Impar(int n) {
	// assume n >= 0
	// retorna o n-ésimo ímpar
	/* insert your code here */
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n; 
	while (scanf("%d", &n)>0) {
		if (n>=0) {
			/* teste manual: 'n' */
			printf("%d\n", Impar(n));
		} else {
			/* teste automático */
			n = 50000;
			for (int t=1; t<=200; t++) Impar(n);
			printf("%d\n", Impar(n));
		}
	}

	return 0;
}