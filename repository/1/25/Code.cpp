#include <stdio.h>
#include <string.h>

int contar(char L[], int n, char c) {
	int contador = 0;
	
	for(int i=0; i<n; i++){
		if(L[i] == c)
			contador++;
	}
	
	return contador;
}

int main() {
	char c, L[1000];

	while(scanf(" %[^\n]", L)>0) {
		scanf("\n%c", &c);
		printf("%d\n", contar(L, strlen(L), c));
	}

	return 0;
}