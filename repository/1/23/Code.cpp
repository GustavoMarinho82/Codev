#include <stdio.h>



void multiplica(int p1, int q1, int p2, int q2, long long int & plin, long long int & qlin) {
    /* insert your code here */
}

int main() {
    int p1, q1, p2, q2; long long int plin, qlin;

    while(scanf("%d", &p1) > 0) {
		scanf("%d", &q1);
		scanf("%d", &p2);
		scanf("%d", &q2);

		multiplica(p1, q1, p2, q2, plin, qlin);

		printf("%lld/%lld\n", plin, qlin);
    }

    return 0;
}