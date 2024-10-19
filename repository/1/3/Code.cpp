#include <stdio.h>
#include <stdlib.h>

long long int CalculaSoma(int n, int m[], int k) { //O[n*k]
	long long int soma = 0;
	
	/* TENTATIVA DE O[n]
	for(int j=1; j<=k; j++){
        long long int p = n/m[j];
        
        soma += m[j]* (p*(p+1)/2);
		soma -= numeros_repetidos;
	}
	*/
	
	for(int i=1; i<=n; i++){ //0~[n*k]
		for(int j=0; j<k; j++){ //O[k]
			if(i%m[j] == 0){
				soma+= i;
				break; 
			}
		}
	}
	
	return soma;
}

int main() {
	int n; int k; 
	int * m;
	while (scanf("%d %d", &n, &k)>0) {
		m = (int *) malloc(sizeof(int)*n);
		for (int i=0; i<k; i++) {
			scanf("%d", &m[i]);
		}
		printf("%lld\n", CalculaSoma(n, m, k));
		free(m);
	}
}