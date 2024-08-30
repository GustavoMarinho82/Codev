#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Reverter(char x[], int n) {
	int i,j; 
	for (i = 0, j = n-1; i < j; i++, j--) {
		char t;
		t = x[i]; x[i] = x[j]; x[j] = t;
	}
}

char* multiplica_lista(char* x, int nx, int y, int & n) {
	/* insert your code here */
}

int main(){
	char * x, * resp; int y;
	
	x = (char *) calloc(1000001, sizeof(char));
	
	while (scanf("%s", x) > 0) {
		scanf("%d", &y);
		int nx, n;

		nx = strlen(x); 
		
		Reverter(x, nx); 

		resp = multiplica_lista(x, nx, y, n);
		
		Reverter(resp, n);
		
		printf("%s\n", resp);

		free(resp);
	}
	free(x);
	
	return 0;

}