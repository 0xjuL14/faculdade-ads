#include <stdio.h>
#include <string.h>  
#include <math.h>
#include <stdbool.h>
#include <locale.h>   


int ehPar(int num) {
   return (num % 2 == 0);
}

int main() {
    setlocale(LC_ALL, "portuguese-brazilian"); 
    
    int num; 

    printf("Digite um nº inteiro: ");
    scanf("%d", &num);
    
    if (ehPar(num)) {
    	printf("O número %d é PAR", num);
	} else {
		printf("O número %d é ÍMPAR", num);
	}

    return 0;
}

