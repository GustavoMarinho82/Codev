#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void Reverter(char x[], int n) {
	int i,j; 
	for (i = 0, j = n-1; i < j; i++, j--) {
		char t;
		t = x[i]; x[i] = x[j]; x[j] = t;
	}
}

char * soma_lista(char x[], int nx, char y[], int ny, int & n) {
	/* insert your code here */
}

int main(){
	char * x, * y, * resp;
	
	x = (char *) calloc(1000001, sizeof(char));
	y = (char *) calloc(1000001, sizeof(char));
	
	while (scanf("%s", x) > 0) {
		if (strcmp(x, "@entradagrande") != 0) {
			scanf("%s", y);
		} else {
			for (int i=0; i<1000000; i++) {
				x[i] = '9'; y[i] = '9';
			}
			x[1000000] = '\0'; y[1000000] = '\0'; 
		}
		int nx, ny, n, i, j;
		nx = strlen(x); ny = strlen(y);
		
		Reverter(x, nx); Reverter(y, ny); 

		resp = soma_lista(x, nx, y, ny, n);
		
		Reverter(resp, n);
		
		printf("%s\n", resp);

		free(resp);
	}
	free(x);
	free(y);
	
	return 0;
}