#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double ContaMisteriosa(int n) { //O~[10^n]
	double calculo = 0;
	double i = 1;
	double j = 1;
	
	/* Não otimizado
	for(int k=1; k<=pow(10, n); k++)
		calculo += pow(-1, k+1) / (2*k-1);
	*/
	
	for(long long int k=1; k<=pow(10, n); k++){ //O~[10^n]
		calculo += i / j;
		i*= -1;
		j+= 2;
	}
	
	return 4 * calculo;
}

int main() {
	int n;  
	while (scanf("%d", &n)>0) {
		printf("%.8f\n", ContaMisteriosa(n));
	}
}