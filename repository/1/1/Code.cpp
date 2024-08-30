#include <stdio.h>

double operacao(int x, int y, char op){
    switch(op){
	    case '+':
	        return (x+y);
	        
	   case '-':
	       return (x-y);
	       
	   case 'x':
	        return (x*y);
	        
	   case '/':
	       //Para que o resultado da operação seja um decimal pelo menos uma das variavéis tem que ser do tipo double/float. 
	       //Com isso, é necessário converter um dos int's com '(double/float) ou adicionar um '1.0*' na operação
	       //return ((double)x/y); OU
	       return (1.0 * x/y);
	   
	   default:
	       return 0;
	}
}

int main(){
	int x, y;
	char op;

	while(scanf("%d", &x)>0){
		scanf("%d", &y);
		scanf("\n%c", &op);

		printf("%0.16g\n", operacao(x, y, op));
	}
	return 0;
}