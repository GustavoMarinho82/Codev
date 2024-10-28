#include <stdio.h>
#include <stdlib.h>

bool Busca(int **B, int n, int x) {
	int i=0, j=(n-1);
	
	while((i < n) && (j >= 0)){
		if (B[i][j] == x)
			return true;
		
		else if(B[i][j] > x)
			j--;
		
		else
			i++;
	}
	
	return false;
}

bool C_Busca(int **B, int n, int x, int q=1) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	bool r;
	for (int t=0; t<q; t++) {
		r = Busca(B,n,x);
	}
#ifndef CODEV
	printf("CODEV_END_EXEC\n");
#endif
	return r;
}


int main() {	
	setbuf(stdout, NULL); setbuf(stderr, NULL);
    int n; int ** B; 
	while (scanf("%d", &n)>0) {
		if (n>-1) {
			/* lê n, B, x */
			B = (int **) malloc(sizeof(int*)*n); 
			for (int i=0; i<n; i++) {
				B[i] = (int *) malloc(sizeof(int)*n); 
				for (int j=0; j<n; j++) {
					scanf("%d", &(B[i][j]));
				}
			}
			int x; scanf("%d", &x);	
			printf("%d\n", C_Busca(B,n,x)); 
			for (int i=0; i<n; i++) {
				free(B[i]);
			}
			free(B);
		} else {
			/* automatic test */
			int nlin = n;
			n = 16000; int x; 
			B = (int **) malloc(sizeof(int*)*n); 
			for (int i=0; i<n; i++) {
				B[i] = (int *) malloc(sizeof(int)*n); 
			}
			if ((nlin==-1)|| (nlin==-2)) {
				/* teste 1 */
				for (int i=0; i<n; i++) {
					for (int j=0; j<n; j++) {
						B[i][j] = i;
					}
				}
				B[n-1][n-2] = n; B[n-1][n-1] = n+1; 
				if (nlin==-1) {
					printf("%d\n", C_Busca(B,n,n)); 
				} else {
					printf("%d\n", C_Busca(B,n,n+2)); 
				}
			} else if ((nlin==-3)|| (nlin==-4)) {
				/* teste 2 */
				for (int i=0; i<n; i++) {
					for (int j=0; j<n; j++) {
						B[i][j] = j;
					}
				}
				B[n-1][n-2] = n; B[n-1][n-1] = n+1; 
				if (nlin==-3) {
					printf("%d\n", C_Busca(B,n,n)); 
				} else {
					printf("%d\n", C_Busca(B,n,n+2)); 
				}
			} else {
				/* teste 3 */
				for (int i=0; i<n; i++) {
					for (int j=0; j<n; j++) {
						B[i][j] = 3;
					}
				}
				B[0][1] = 2; B[0][0] = 1; 
				if (nlin==-5) {
					printf("%d\n", C_Busca(B,n,2)); 
				} else {
					printf("%d\n", C_Busca(B,n,0)); 
					C_Busca(B,n,0,1000);
				}
			}
			for (int i=0; i<n; i++) {
				free(B[i]);
			}
			free(B);
		}
	}
	return 0;
}