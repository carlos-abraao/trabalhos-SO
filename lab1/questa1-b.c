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

int main(int argc, char const *argv[]){	

	int ini, fim, rng;

	printf("Digite o intervalo desejado da sequencia de fibonacci: \n");
	scanf("%d%d", &ini, &fim);

	while ( (ini <= 0 || fim <=0) || (fim < ini) ){
		printf("Digite o intervalo novamente: \n");
		scanf("%d%d", &ini, &fim);		
	}

	rng = fim - ini;

	int pid, resul;
    
    pid=fork(); /* criacao do filho */

    if ( pid==-1 ){
        perror("impossivel de criar um filho\n") ;
    }    
    else if ( pid==0 ){
    	if (rng == 1){
    		resul = Fibesimo(ini);
    	}

        printf("\tOu melhor, assim espero!\n") ;
        
    }
    else{

        sleep(10) ; /* para separar bem as saidas do pai e do filho */
        
        printf("Matei, %d, meu filho\n",pid) ;
        // sleep(10) ; /* para separar bem as saidas do pai e do filho */

    }




	return 0;
}