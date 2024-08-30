#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double pi(int N) {
	/* insert your code here */
}
	
int main() {
	int N;
	
	while (scanf("%d", &N)>0) {
		printf("%.14f\n", pi(N));
	}
	
	return 0;
}