#include <stdio.h>

int Fibonacci(int n) { //O~[n]
	const int BASE = 1000000000; //Pede-se o resultado como módulo de 10^9
	
	int Fib = 0, n_ultimo = 0, n_penultimo = 1;
	
	for(int i=1; i<n; i++) {
		Fib = ((n_ultimo % BASE) + (n_penultimo % BASE)) % BASE;
		n_penultimo = n_ultimo;
		n_ultimo = Fib;
	}
	
	return Fib;
}

int main() {
	int n; 
	while (scanf("%d", &n)>0) {
		printf("%d\n", Fibonacci(n));
	}
}