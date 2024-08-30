#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void tv(double D, double pL, double pH, double & H, double & L) {
	/* insert your code here */
}
 
int main(){
	double D, pL, pH, H, L;
	
	while (scanf("%lf", &D)>0) {
		scanf("%lf", &pL);
		scanf("%lf", &pH);
		
		tv(D, pL, pH, H, L);
		
		printf("(%.1f, %.1f)\n", L, H);
	}
	return 0;
}