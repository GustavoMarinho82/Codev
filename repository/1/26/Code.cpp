#include <stdio.h>
#include <string.h>

void removeCaractere(char L[], int n, char c) {
	/* insert your code here */
}

char L[2000000];

int main() {
	char c;

	while (scanf(" %[^\n]", L)>0) {
		if (strcmp(L, "@entradagrande")==0) {
			for (int i=0; i<500000; i++) {
				L[2*i] = 'c'; L[2*i+1] = 'a';
			}
		}
		scanf("\n%c", &c);
		removeCaractere(L, strlen(L), c);

		printf("%s\n", L);
	}

	return 0;
}