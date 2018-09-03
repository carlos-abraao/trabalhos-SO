#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void Fib(){

	int ini, fim;

	printf("Digite o intervalo desejado da sequencia de fibonacci: \n");
	scanf("%d%d", &ini, &fim);

	while ( (ini <= 0 || fim <=0) || (fim < ini) ){
		printf("Digite o intervalo novamente: \n");
		scanf("%d%d", &ini, &fim);		
	}

	int a = 0, b = 1, fib = 0;

	for (int j = 1; j <= fim; ++j){
		fib = a;
		a = b;
		b += fib;
		if (j >= ini){
			printf("%d ", fib);
		}
	}

	printf("\n");
}

int Fibesimo (int n){
	return (1/sqrt(5))* pow(( (1+sqrt(5))/2 ), n) - (1/sqrt(5))* pow(( (1-sqrt(5))/2 ), n);
}

void createson(int ini, int fim, int rng);

void FibFork(int pidd, int ini, int fim){

	int rng = fim - ini;

	int resul;    

    if ( pidd == -1 ){
        perror("impossivel de criar um filho\n") ;
    }    
    else if (pidd == 0){
    	if (rng == 1){
    		resul = Fibesimo(ini);
    		printf("eita: %d \n", resul);
    	}
    	else{
    		createson(ini, fim, rng);
    	}

        printf("\tOu melhor, assim espero!\n") ;
        
    }
    else{

        sleep(10) ; /* para separar bem as saidas do pai e do filho */ 
    }

}

void createson(int ini, int fim, int rng){
	int pidd = fork();
	int mid = ini + rng;

	FibFork(pidd, ini, mid);
	FibFork(pidd, mid+1, fim);

}


int main(int argc, char const *argv[]){	

	int ini, fim, rng;

	printf("Digite o intervalo desejado da sequencia de fibonacci: \n");
	scanf("%d%d", &ini, &fim);

	while ( (ini <= 0 || fim <=0) || (fim < ini) ){
		printf("Digite o intervalo novamente: \n");
		scanf("%d%d", &ini, &fim);		
	}	

	int pid;
    
    pid = fork(); /* criacao do filho */

    FibFork(pid, ini, fim);

	return 0;
}