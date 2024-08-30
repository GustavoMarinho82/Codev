#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void cientifico(double n, char notacao[]) {
	/* insert your code here */
}

int main() {
	double n;
	char r[20];
	while (scanf("%lf", &n)>0) {
		cientifico(n, r);
		printf("%s\n", r);
	}
	
	return 0;
}