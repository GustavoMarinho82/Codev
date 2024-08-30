#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long int raiz (long long int n, long long int inf, long long int sup) {
	/* insert your code here */
}

int main(){
	long long int n;
	
	while (scanf("%lld", &n)>0) {
		printf("%lld\n", raiz(n, 0, n+1));
	}
	
	return 0;
}