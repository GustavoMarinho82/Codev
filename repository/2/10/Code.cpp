#include <stdio.h>
#include <stdlib.h>

void RepresentacaoDecimal(long long int n, int R[], int & k) {
	/* insert your code here */
}

int main() {
	long long int n; 
	int R[16]; int k;
	while (scanf("%lld", &n)>0) {
		RepresentacaoDecimal(n, R, k);
		for (int i=0; i<k; i++) {
			printf("%d ", R[i]);
		}
		printf("\n");
	}
}