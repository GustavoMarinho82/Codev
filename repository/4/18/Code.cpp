#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

bool DEBUG;

int Maximo(int A[], int n) { //O~(n)
	// Assume A[] é um vetor de naturais
	
	if (n == 0) {
		return 0;
		
	} else {
		int x = Maximo(A, n-1);
		return (x > A[n-1]) ? x : A[n-1];
	}
}

int main(int argc, char * argv[]) {
	setbuf(stdout, NULL); setbuf(stderr, NULL); DEBUG = (argc > 1);
	int n; int * A; 
	while (scanf("%d", &n)>0) {
		if (n>=0) {
			/* teste manual */
			A = (int *) malloc(sizeof(int)*n); 
			for (int i=0; i<n; i++) scanf("%d", &A[i]);
			printf("%d\n", Maximo(A,n));
			free(A); 
		} else {
			/* teste automático */
			n = 50000; 
			A = (int *) malloc(sizeof(int)*n); 
			for (int i=0; i<n/2; i++) A[i]=i;
			for (int i=n/2+1; i<n; i++) A[i]=n-i;
			for (int i=0; i<20; i++) Maximo(A,n);
			printf("%d\n", Maximo(A,n));
			free(A); 
		}
	}

	return 0;
}
