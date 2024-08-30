#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool maiorigual_vetor(char x[], int nx, char y[], int ny) {
	/* insert your code here */
}

char x[1000], y[1000];

int main() {
	
	while (scanf(" %[^\n]", x)>0) {
		if (strcmp(x, "@entradagrande")!=0) {
			scanf(" %[^\n]", y);
		} else {
			for (int i=0; i<999; i++) {
				x[i]=1; y[i]=1;
			}
			y[0]=2; y[999]='\0'; x[999]='\0'; 
		}
				
		printf("%d\n", maiorigual_vetor(x, strlen(x), y, strlen(y)));
	}
	
	return 0;
}