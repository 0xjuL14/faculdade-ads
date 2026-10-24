#include <stdio.h>
#include <locale.h>
#include <math.h> 

/* Escreva um programa que leia n números e para cada número digitado imprima, 
o quadrado do número se o número for ímpar ou a raiz quadrada do número se ele for um número par. */

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
     
    float num, imp, par;
    int n, i = 1;
     
    printf("Escolha a quantidade de termos:\n");
    scanf("%d", &n);
	    
	while(i <= n) {
		printf("Digite o %d número: ", i);
        scanf("%f", &num);
        
		if((int)num % 2 == 0) {
            par = sqrt(num);
			printf("v%.1f = %.1f\n", num, par);
        }
        else {
        	imp = pow(num, 2);
			printf("%.1f² = %.1f\n", num, imp);
		}
		
		i++;
    }
	 
	return 0;
}

