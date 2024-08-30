#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Reverter(char x[], int n) {
	int i,j; 
	for (i = 0, j = n-1; i < j; i++, j--) {
		char t;
		t = x[i]; x[i] = x[j]; x[j] = t;
	}
}



void divide_lista(char* x, int nx, char* y, int ny, char* & quociente, int & nq, char* &resto, int &nr) {
	
	int i, j;
	char* candidato; int nc;
	char* ultimo_candidato; int nuc;
	char* novoresto; int nnr;
	int ultimo; 
	
	resto = (char *) calloc(1, sizeof(char)); resto[0] = '\0'; nr = 0;
	quociente = (char *) calloc(1, sizeof(char)); quociente[0] = '\0'; nq = 0;
	
	for (i = nx-1; i >=0; i--) {
		adicionarantes(resto, nr, x[i]);
		ultimo_candidato = NULL; nuc = 0;
		for (j = 0; j <= 10; j++) {
			candidato = multiplica_lista(y, ny, j, nc);
			if (! maiorigual_vetor(resto, nr, candidato, nc)) {
				adicionarantes(quociente, nq, ultimo + '0');
				novoresto = subtrai_lista(resto, nr, ultimo_candidato, nuc, nnr);
				free(resto); resto = novoresto; nr = nnr;
				break;
			}
			ultimo = j;
			free(ultimo_candidato);
			ultimo_candidato = candidato; nuc = nc;
		}
	}
	while ((nq>1) && quociente[nq-1] == '0') {
		nq = nq-1;
	}
	quociente[nq] = '\0';
	while ((nr>1) && resto[nr-1] == '0') {
		nr = nr-1;
	}
	resto[nr] = '\0';
}

int main() {
	char *x, *y, *quociente, *resto;
	
	x = (char *) calloc(1000001, sizeof(char));
	y = (char *) calloc(1000001, sizeof(char));
	
	while (scanf("%s", x) > 0) {
		scanf("%s", y);

		int nx, ny, nq, nr, i, j;
		nx = strlen(x); ny = strlen(y);
		
		Reverter(x, nx); Reverter(y, ny); 

		divide_lista(x, nx, y, ny, quociente, nq, resto, nr);
		
		Reverter(quociente, nq); Reverter(resto, nr);
		
		printf("(%s,%s)\n", quociente, resto);

		free(quociente); free(resto);
	}
	free(x);
	free(y);
	
	return 0;
}