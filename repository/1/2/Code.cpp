#include <stdio.h>
#include <stdlib.h>

long long int CalculaSoma(long long int n) {
	//Formula de Progressao Aritmetica
	return ((1 + n) * n) / 2;
}

int main() {
	int n;
	while (scanf("%d", &n)>0) {
		printf("%lld\n", CalculaSoma(n));
	}
}