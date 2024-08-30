#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double converte(int x, char unidade1[], char unidade2[]) {
	/* insert your code here */
}

int main() {
	int x;
	char unidade1[4], unidade2[4];

	while (scanf("%d", &x)>0) {	
		scanf("%s", unidade1); scanf("%s", unidade2);
		printf("%.16g\n", converte(x, unidade1, unidade2));
	}
		
	return 0;
}