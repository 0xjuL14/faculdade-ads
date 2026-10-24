#include <stdio.h>
#include <locale.h>
#include <ctype.h> 

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
     
     // Escreva um programa que leia o nome e o sexo de 10 pessoas. No final, informe a quantidade total de homens e de mulheres.
     char nome[100], sexo;
     int homens = 0, mulheres = 0;
     
     printf("Escreva o nome e o sexo (M/F) de 10 pessoas, respectivamente:\n");
	    
	for(int i = 1; i <= 10; i++) {
		printf("Digite o nome: ");
        scanf("%s", nome);
        fflush(stdin);
		printf("Digite o sexo (M para Masculino / F para Feminino): ");
        scanf(" %c", &sexo);
        
		switch (toupper(sexo)) { 
            case 'M':
                homens++;
                break;

            case 'F':
                mulheres++; 
                break;

            default:
                printf("Opção de sexo inválida! '%c' não será contado(a).\n", sexo);
                break;
        }
    }
    
	printf("Total de homens: %d\n", homens);
    printf("Total de mulheres: %d\n", mulheres);
	 
		return 0;
}
