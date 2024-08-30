#include <stdio.h>
#include <math.h>

int raizes(int a, int b, int c, double & r1, double & r2) {
	/* insert your code here */
}

int main(void){
	int a, b, c; int nr;
	double r1, r2;

	while (scanf("%d", &a) > 0) {
		scanf("%d", &b);
		scanf("%d", &c);

		nr = raizes(a, b, c, r1, r2);
		printf("(");
		if (nr >= 1) printf("%0.16g", r1); else printf("-");
		printf(",");
		if (nr == 2) printf("%0.16g", r2); else printf("-");
		printf(")\n");
	}

	return 0;
}