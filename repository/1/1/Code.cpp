#include <stdio.h>
#include <stdlib.h>

long long int CalculaSoma(int n) {
	long long int soma = 0;
	while (n>0) {
	    soma+=n;
	    n--;
	}
	return soma;
}

int main() {
	int n;
	while (scanf("%d", &n)>0) {
		printf("%lld\n", CalculaSoma(n));
	}
}