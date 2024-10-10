#include <stdio.h>

double raiz(int a, int b, bool & existe) {
	existe = (a == 0) ? false : true;
	
	if (existe)
		return -b/(double)a;
	else
		return 0;
}
	
int main() {
	int a, b; bool existe;

	while(scanf("%d", &a) > 0){
		scanf("%d", &b);
		double r = raiz(a, b, existe);
		if (existe) {
			printf("%g\n", r);
		} else {
			printf("sem raiz\n");
		}
	}

	return 0;
}