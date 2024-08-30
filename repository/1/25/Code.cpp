#include <stdio.h>
#include <string.h>

int contar(char L[], int n, char c) {
	/* insert your code here */
}

int main() {
	char c, L[1000];

	while(scanf(" %[^\n]", L)>0) {
		scanf("\n%c", &c);
		printf("%d\n", contar(L, strlen(L), c));
	}

	return 0;
}