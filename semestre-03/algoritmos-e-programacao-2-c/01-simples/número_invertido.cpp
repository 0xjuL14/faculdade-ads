#include <stdio.h>
#include <locale.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
	
	int num, d1, d2, d3, aux;
	
	// solicita ao usuário um número inteiro com três dígitos e exibe o número invertido
	
	printf("Digite um nº inteiro de 3 algarismos: ");
	scanf("%d", &num);
	fflush(stdin);
	
	d1 = num / 100;
	aux = num % 100;
	d2 = aux / 10;
	aux = aux % 10;
	d3 = aux / 1;
		
    printf("Inversão = %d%d%d", d3, d2, d1);
   
    return 0;
    
}

