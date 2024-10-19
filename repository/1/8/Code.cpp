#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PermutacaoCircular(char A[], int n, int k) { //O~[n]
	//Provavelmente o uso de uma copia de A é desnecessaria
	char * B;
	B = (char *) malloc(sizeof(char)*(n+600000));
	strncpy(B, A, n);
	
	for(int i=0; i<n; i++)
		A[i] = B[(n-k+i)%n];
	
	free(B);
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