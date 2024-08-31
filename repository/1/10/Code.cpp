#include <stdio.h>
#include <math.h>

bool eh_Primo(long long int x) {
    for(int i=2; i<=floor(sqrt(x)); i++){
        if(x%i==0){
            return 0; //retorna False
        }
    }
    
    return (x == 1) ? 0 : 1; //retorna False se x=1, senão retorna True
}
	
int main(){
	long long int x;

	while(scanf("%lld", &x)>0){
	    if (eh_Primo(x)) {
			printf("Primo\n");
	    } else {
			printf("Composto\n");
	    }
	}

	return 0;
}