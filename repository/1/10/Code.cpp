#include <stdio.h>
#include <math.h>

void RepresentacaoDecimal(long long int n, int R[], int & k) {
	k = (n !=0) ? floor(log10(n))+1 : 1;
	
	char numero[k];
	sprintf(numero, "%lld", n);
	
	for(int i=0; i<k; i++){
		R[i] = numero[i] - '0';
	}
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