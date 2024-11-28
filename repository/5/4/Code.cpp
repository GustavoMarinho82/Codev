#include <stdio.h>
#include <stdlib.h>
#include "Bib1.h"
#include "Bib2.h"

/* Se achar útil empregar uma pilha ou fila em sua solução,
   utilize-a pela respectiva interface padrão 
   disponibilizada abaixo */ 
   
/* pilha */
void Constroi(Pilha &P);
void Destroi(Pilha &P);
void Empilha(Pilha &P, int x);
int Desempilha(Pilha &P);
int Topo(Pilha &P);
int Tamanho(Pilha &P);
/* pilha */

/* fila */
void Constroi(Fila &F);
void Destroi(Fila &F);
void Enfileira(Fila &F, int x);
int Desenfileira(Fila &F);
int Proximo(Fila &F);
int Tamanho(Fila &F);
/* fila */


typedef struct Parentese {
	char desc; /* '(' ou ')' */
	int tipo;
} Parentese;

bool VerificaParentizacao(Parentese E[], int n) {
	/* insert your code here */
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	Parentese * E; int n; 
	while (scanf("%d", &n)>0) {
		if (n>=0) {
			/* teste manual: 'n <parentização com n elementos>' */
			char * Ec = (char *) malloc(sizeof(char)*4*n);
			E = (Parentese *) malloc(sizeof(Parentese)*n);
			scanf("%s", Ec);
			int j=0;
			for (int i=0; i<n; i++) {
				E[i].desc = Ec[j]; j++;
				char tipo[10];
				int z=j;
				while ((Ec[j] != '\0') && (Ec[j] != '(') && (Ec[j] != ')')) {
					tipo[j-z] = Ec[j];
					j = j+1;
				}
				tipo[j-z] = '\0';
				E[i].tipo = atoi(tipo);
			}
			printf("%d\n", VerificaParentizacao(E,n));
			free(E); free(Ec);
		} else {
			/* teste automático */
			int nlin = n;
			n = 1000000;
			E = (Parentese *) malloc(sizeof(Parentese)*n);
			if (nlin==-1) {
				for (int i=0; i<n/2; i++) {	E[i].desc = '('; E[i].tipo = 1;	}	
				for (int i=n/2; i<n; i++) {	E[i].desc = ')'; E[i].tipo = 1;	}	
			} else if (nlin==-2) {
				for (int i=0; i<n/2; i++) {	E[i].desc = '('; E[i].tipo = i+1;	}	
				for (int i=n/2; i<n; i++) {	E[i].desc = ')'; E[i].tipo = n-(i+1)+1;	}	
			} else if (nlin==-3) {
				for (int i=0; i<n; i += 2) { E[i].desc = '('; E[i].tipo = i+1; E[i+1].desc = ')'; E[i+1].tipo = i+1; }	
			} else if (nlin==-4) {
				for (int i=0; i<n/2-1; i++) {	E[i].desc = '('; E[i].tipo = 1;	}	
				for (int i=n/2-1; i<n; i++) {	E[i].desc = ')'; E[i].tipo = 1; }	
			} else if (nlin==-5) {
				for (int i=0; i<n/2+1; i++) {	E[i].desc = '('; E[i].tipo = 1;	}	
				for (int i=n/2+1; i<n; i++) {	E[i].desc = ')'; E[i].tipo = 1; }	
			}
			printf("%d\n", VerificaParentizacao(E,n));
			free(E); 
		}
	}

	return 0;
}