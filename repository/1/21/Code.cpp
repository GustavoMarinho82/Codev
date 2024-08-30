#include <stdio.h>

	
void reduz(int p, int q, int & plin, int & qlin){
	/* insert your code here */
}

int main() {
	int p, q, plin, qlin;

	while(scanf("%d", &p)>0){
		scanf("%d", &q);
		reduz(p, q, plin, qlin);
		printf("%d/%d\n", plin, qlin);
	}

	return 0;
}