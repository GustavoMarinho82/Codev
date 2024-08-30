#include <stdio.h>
#include <stdlib.h>


double menor_angulo(int H, int M) {
	/* insert your code here */
}

int main() {
	int H, M;
	
	while (scanf("%d %d", &H, &M)>0) {
		printf("%.16g\n", menor_angulo(H, M));
	}
	
	return 0;
}