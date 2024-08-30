#include <stdio.h>


void soma(int p1, int q1, int p2, int q2, int & plin, int & qlin) {
    /* insert your code here */
}

int main(void){
    int p1, q1, p2, q2, plin, qlin;

    while(scanf("%d", &p1) > 0) {
		scanf("%d", &q1);
		scanf("%d", &p2);
		scanf("%d", &q2);

		soma(p1, q1, p2, q2, plin, qlin);

		printf("%d/%d\n", plin, qlin);
    }

    return 0;
}