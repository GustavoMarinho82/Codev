#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Ponto {
	double x;
	double y;
} Ponto;

char ponto_reta(double a, double b, Ponto p) {
	/* insert your code here */
}

int main() {
	double a, b;
	Ponto p;
	
	while (scanf("%lf %lf %lf %lf", &a, &b, &p.x, &p.y)>0) {
		printf("%c\n", ponto_reta(a, b, p));
	}
	return 0;
}