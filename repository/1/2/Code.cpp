#include <stdio.h>

void doishorarios(int h, int m, char horario1[], char horario2[]) {
	/* insert your code here */
}

int main() {
	int h, m; char horario1[6], horario2[6];

	while (scanf("%d", &h)>0) {
		scanf("%d", &m);
		doishorarios(h, m, horario1, horario2);
		printf("%s / %s\n", horario1, horario2);
	}
	return 0;
}