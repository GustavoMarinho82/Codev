#include <stdio.h>
#include <stdlib.h>

typedef struct E1 {
	char Nome[4];
	int Idade;
} E1;

typedef struct E2 {
	int Turma;
	E1* Aluno;
	E2* Prox;
} E2;

E1 V[3];
E2* L;

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
	V[0].Nome[0] = 'J'; V[0].Nome[1] = 'O'; V[0].Nome[2] = 'A'; V[0].Nome[3]= 'O';
	V[0].Idade = 5;
	
	V[1].Nome[0] = 'L'; V[1].Nome[1] = 'E'; V[1].Nome[2] = 'O';
	V[1].Idade = 8;
	
	V[2].Nome[0] = 'L'; V[2].Nome[1] = 'I'; V[2].Nome[2] = 'A';
	V[2].Idade = 9;
	
	L = (E2*) malloc(sizeof(E2));
	
	L->Turma = 1;
	L->Aluno = &(V[0]);
	L->Prox = (E2*) malloc(sizeof(E2));
	
	L->Prox->Turma = 1;
	L->Prox->Aluno = &(V[1]);
	L->Prox->Prox = (E2*) malloc(sizeof(E2));
	
	L->Prox->Prox->Turma = 2;
	L->Prox->Prox->Aluno = &(V[1]);
	L->Prox->Prox->Prox = (E2*) malloc(sizeof(E2));
	
	L->Prox->Prox->Prox->Turma = 2;
	L->Prox->Prox->Prox->Aluno = &(V[2]);
	L->Prox->Prox->Prox->Prox = NULL;
	
	int t;
	while (scanf("%d", &t) > 0) {
		TestarMemoria(t);
	}
}