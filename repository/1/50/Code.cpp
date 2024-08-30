#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int conta_unicos(char P[], int N){
	/* insert your code here */
}

int main() {
	int N;
	char* P;
	
	while (scanf("%d", &N)>0) {
		bool manual = true;
		if (N < 0){
			manual = false;
			N = 10000*5;
		} 
		P = (char*)calloc(N+1, sizeof(char));
		if (manual) {
			scanf("%s", P);
		} else {
			for (int i = 0; i<10000; i += 5) {
				P[i] = 'a'; P[i+1] = 'b'; P[i+2] = 'c'; P[i+3] = 'd'; P[i+4] = 'e';
			}
		}
		printf("%d\n", conta_unicos(P, N));
		free(P);
	}
	
	return 0;
}