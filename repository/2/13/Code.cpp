#include <stdio.h>
#include <stdlib.h>

typedef struct E1 {
	/* insert your code here */
} E1;

typedef struct E2 {
	/* insert your code here */
} E2;

/* insert your code here */

void TestarMemoria(int t) {
	/* Atente para o que está sendo impresso nesse teste, e 
	   elabore o programa para ser coerente com que está sendo
	   impresso aqui! */
	if (t==1) printf("%d %d %d\n", V[0].Idade, V[1].Idade, V[2].Idade);
	if (t==2) printf("%c %c %c %c\n", V[0].Nome[0], V[0].Nome[1], V[0].Nome[2], V[0].Nome[3]);
	if (t==3) printf("%c %c %c\n", V[1].Nome[0], V[1].Nome[1], V[1].Nome[2]);
	if (t==4) printf("%c %c %c\n", V[2].Nome[0], V[2].Nome[1], V[2].Nome[2]);
	if (t==5) printf("%d %d %d %d\n", L->Turma, L->Prox->Turma, L->Prox->Prox->Turma, L->Prox->Prox->Prox->Turma);
	if (t==6) printf("%d\n", L->Prox->Prox->Prox->Prox == NULL ? 1 : 0);
	if (t==7) printf("%d %d %d %d\n", L->Aluno->Idade, L->Prox->Aluno->Idade, L->Prox->Prox->Aluno->Idade, L->Prox->Prox->Prox->Aluno->Idade);
}

int main() {
	/* insert your code here */
	int t;
	while (scanf("%d", &t) > 0) {
		TestarMemoria(t);
	}
}