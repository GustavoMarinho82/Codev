#include <stdio.h>
#include <stdlib.h>

long long int CalculaSoma(int n) {
	return (((1 + n)*n)/2);
}

int main() {
	int n;
	while (scanf("%d", &n)>0) {
		printf("%lld\n", CalculaSoma(n));
	}
}