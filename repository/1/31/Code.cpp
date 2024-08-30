#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int acima_media(int L[], int n) {
	/* insert your code here */
}

int main() {
	char N[100];
	int n; 
	int * L = (int *) calloc(1000000, sizeof(int));
	while (scanf(" %[^\n]", N)>0) {
		if (strcmp(N, "@entradagrande") != 0) {
			sscanf(N, "%d", &n);
			for (int i=0; i<n; i++) {
				scanf("%d", &L[i]);
			}
		} else {
			n = 1000000;
			for (int i=0; i<n; i++) {
				L[i] = i;
			}
		}
		printf("%d\n", acima_media(L, n));
	}
	free(L);
	return 0;
}