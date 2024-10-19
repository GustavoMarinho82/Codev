#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int QtdePrimos(int n) { //O[n*sqrt(n)]
	int qtd = 0;
	
	for(int i=2; i<=n; i++){ //O~[n*sqrt(n)]
		qtd++;
		
		for(int j=2; j<=sqrt(i); j++){ //O[sqrt(n)]
			if(i%j == 0){
				qtd--;
				break;
			}
		}
	}
	
	return qtd;
}

int main() {
	int n;  
	while (scanf("%d", &n)>0) {
		printf("%d\n", QtdePrimos(n));
	}
}