#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

	int n;
	bool primo;
	
	primo = true;
	
	printf("Informe um nº inteiro e não negativo para verificar se é um nº primo ou não:\n");
    scanf("%d", &n);
    
    if(n > 0 && n != 1) {
    	for (int i = 2; i <= n/2; i++) {
	    	
			if(n%i == 0) {
	       		primo = false;
	       		
	       		break;
			}
	} 
				if(primo) {
					printf("O nº %d É um nº primo!", n);
				}
				else {
					printf("O nº %d NÃO é um nº primo!", n);
				}
		}
	else if(n == 0 || n == 1) {
		printf("%d NÃO é um nº primo pois para ser primo um número precisa ter exatamente dois divisores positivos.", n);
	}
	else {
		printf("Número inválido! Deve ser inteiro e não negativo!");
	}
		
	return 0;
}
