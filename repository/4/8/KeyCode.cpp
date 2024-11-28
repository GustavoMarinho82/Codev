#include <stdio.h>
#include <stdlib.h>

bool EhPalindromo(char C[], int i, int j) {
	if (i>=j) {
		return true;
	} else {
		return (C[i]==C[j]) && (EhPalindromo(C,i+1,j-1));
	}
}

bool EhPalindromo(char C[], int n) {
	return EhPalindromo(C, 0, n-1);
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n; char * C;
	while (scanf("%d", &n)>0) {
		if (n>=0) {
			/* teste manual: 'n <cadeia de n caracteres>' */
			C = (char *) malloc(sizeof(char) * (n+1));
			scanf("%s", C);
			printf("%d\n", EhPalindromo(C, n));
			free(C);
		} else {
			/* teste automático */
			int nlin = n;
			n = 50000;
			C = (char *) malloc(sizeof(char) * (n+1));
			if (nlin==-1) {
				for (int i=0; i<n; i++) {
					C[i] = 'a'+(i%26);
				}	
				printf("%d\n", EhPalindromo(C, n));
			} else {
				for (int i=0; i<(n+1)/2; i++) {
					C[i] = 'a'+(i%26); C[n-i-1] = C[i];
				}
				printf("%d\n", EhPalindromo(C, n));
			}
			free(C);
		}
	}

	return 0;
}