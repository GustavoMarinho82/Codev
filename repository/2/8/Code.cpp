#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PermutacaoCircular(char A[], int n, int k) {
	/* insert your code here */
}

int main() {
	int n,k; 
	char * A; 
	while (scanf("%d %d", &n, &k)>0) {
		A = (char *) malloc(sizeof(char)*(n+600000));
		scanf("%s", A);
		PermutacaoCircular(A, n, k);
		printf("%s\n", A);
		free(A);
	}
}