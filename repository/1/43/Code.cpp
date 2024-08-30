#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Saque {
	long long int qtd;
	int valor;
} Saque;

Saque* saque(long long int S, int & n) {
	/* insert your code here */
}

int main() {
	long long int S;
	
	while (scanf("%lld", &S)>0) {
		int i, n;
		
		Saque* saques;
		saques = saque(S, n);
		
		printf("[");
		for (i = 0; i < n; i++) {
			if (i>0) printf(", ");
			printf("(%lld, %d)", saques[i].qtd, saques[i].valor);
		}
		printf("]\n");
	}
	return 0;
}