#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Reverter(char L[], int n) {
	/* insert your code here */
}

int main() {
	char * cadeia;
	
	cadeia = (char *) calloc(1000001, sizeof(char));
	
	while (scanf(" %[^\n]", cadeia) > 0) {
		if (strcmp(cadeia, "@entradagrande") == 0) {
			for (int i=0; i<1000000; i = i+2) {
				cadeia[i] = 'a'; cadeia[i+1] = 'b';
			}
			cadeia[1000000] = '\0';
		}
	
		Reverter(cadeia, strlen(cadeia)); 

		printf("%s\n", cadeia);
	}
	free(cadeia);
	
	return 0;
}