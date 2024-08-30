#include <stdio.h>
#include <stdlib.h>

void conta_num(int lista[], int n, int & pos, int & neg){
	/* insert your code here */
}

int main(){
	int n, i, pos, neg, *lista;

	while (scanf("%d", &n) > 0) {

		lista = (int*) calloc(n, sizeof(int));

		for(int i = 0; i < n; i++){
			scanf("%d", &lista[i]);
		}

		conta_num(lista, n, pos, neg);

		printf("(%d, %d)\n", pos, neg);

		free(lista);
	}

	return 0;
}