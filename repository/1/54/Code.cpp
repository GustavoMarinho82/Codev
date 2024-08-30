#include <stdio.h>


double calc_dist(double v, double a, double t) {
	/* insert your code here */
}

int main() {
	double v, a, t;
	
	while (scanf("%lf %lf %lf", &v, &a, &t)>0) {
		printf("%.16g\n", calc_dist(v, a, t));
	}
	
	return 0;
}