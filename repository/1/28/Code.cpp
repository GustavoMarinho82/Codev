#include <stdio.h>
#include <string.h>

int eh_palindromo(char L[], int n){
	/* insert your code here */
}

char L[2000000];

int main(){
	while(scanf(" %[^\n]", L)>0) {
		if (strcmp(L, "@entradagrande1")==0) {
			for (int i=0; i<500000; i++) {
				L[2*i] = 'a'; L[2*i+1] = 'b';
			}
			L[500000] = 'a'; L[500001] = '\0';
		} else if (strcmp(L, "@entradagrande2")==0) {
			for (int i=0; i<500000; i++) {
				L[2*i] = 'a'; L[2*i+1] = 'b';
			}
			L[500000] = '\0';
		}
		printf("%d\n", eh_palindromo(L, strlen(L)));
	}
	return 0;
}