#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

long long int ParesIguais(int A[], int B[], int n) {
	/* insert your code here */
}

void Insere(int L[], int &n, int e) {
	L[n] = e; n = n+1;
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int max_n; int * A, * B; int na, nb;
	while (scanf("%d", &max_n)>0) {
		if (max_n>-1) {
			/* lê n, a1, a2, ..., an, b1, b2, ..., bn */
			A = (int *) malloc(sizeof(int)*max_n); na = 0;
			B = (int *) malloc(sizeof(int)*max_n); nb = 0;
			for (int i=0; i<max_n; i++) {
				int e; scanf("%d", &e);	Insere(A,na,e);
			}
			for (int i=0; i<max_n; i++) {
				int e; scanf("%d", &e);	Insere(B,nb,e);
			}
			printf("%lld\n", ParesIguais(A,B,na)); 
			free(A); free(B);
		} else {
			/* automatic test */
			int nlin = max_n;
			max_n = 200000;
			A = (int *) malloc(sizeof(int)*max_n); na = 0;
			B = (int *) malloc(sizeof(int)*max_n); nb = 0;
			if (nlin == -1) {
				for (int i=0; i<max_n; i++) {
					Insere(A,na,i);
					Insere(B,nb,i);
				}
			} else if (nlin == -2) {
				for (int i=0; i<max_n; i++) {
					Insere(A,na,1);
					Insere(B,nb,1);
				}
			} else {
				for (int i=0; i<max_n/10000; i++) {
					for (int j=0; j<10000; j++) {
						Insere(A,na,i);
						Insere(B,nb,i);
					}
				}
			}
			printf("%lld\n", ParesIguais(A,B,na)); 
			free(A); free(B);
		}
	}
	return 0;
}