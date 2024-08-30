#include <stdio.h>

int mdc (int x, int y){
	/* insert your code here */
}

int main() {
	int x, y;

	while(scanf("%d", &x)>0){
		scanf("%d", &y);

		printf("%d\n", mdc(x, y));
	}

	return 0;
}