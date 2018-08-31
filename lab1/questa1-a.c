#include <stdio.h>
#include <math.h>

void Fib(int i, int f){
	int a = 0, b = 1, fib = 0;

	for (int j = 1; j <= f; ++j){
		fib = a;
		a = b;
		b += fib;
		if (j >= i){
			printf("%d ", fib);
		}
	}

	printf("\n");
}

int main(int argc, char const *argv[]){
	
	int ini, fim;

	printf("Digite o intervalo desejado da sequencia de fibonacci: \n");
	scanf("%d%d", &ini, &fim);

	while ( (ini <= 0 || fim <=0) || (fim < ini) ){
		printf("Digite o intervalo novamente: \n");
		scanf("%d%d", &ini, &fim);		
	}

	Fib(ini, fim);

	return 0;
}