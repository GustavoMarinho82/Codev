#include <stdio.h>

double calc_dist(double v, double a, double t) {
	/* insert your code here */
}
	
int main() {
	float v, a, t;

	while (scanf("%f %f %f", &v, &a, &t) > 0) {
	    printf("%0.16g\n", calc_dist(v, a, t));
	}

	return 0;
}