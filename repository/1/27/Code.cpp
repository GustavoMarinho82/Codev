#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* duplica(char L[], int n) {
	/* insert your code here */
}

int main() {
	char *L, *L_dup; int n;
	L = (char *) calloc(500001, sizeof(char));
	while (scanf(" %[^\n]", L)>0) {
		if (strcmp(L, "@entradagrande")==0) {
			n = 500000;
			for (int i=0; i<n; i++) {
				L[i] = 'a';
			}
			L[n] = '\0';
		}
		L_dup = duplica(L, strlen(L));
		printf("%s\n", L_dup);
		free(L_dup);
	}

	return 0;
}