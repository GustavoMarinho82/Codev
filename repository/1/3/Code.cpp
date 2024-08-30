#include <stdio.h>
#include <stdlib.h>

int calc_sec(int hora1, int min1, int hora2, int min2){
	/* insert your code here */
}

int main(void){
	int h1, m1, h2, m2;

	while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2)>0){
		printf("%d\n", calc_sec(h1, m1, h2, m2));
	}
	return 0;
}