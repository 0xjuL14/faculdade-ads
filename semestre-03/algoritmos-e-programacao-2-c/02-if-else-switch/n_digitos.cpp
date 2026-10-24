#include <stdio.h>
#include <locale.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

    int num;
    
    printf("Informe um número inteiro: \n");
    scanf("%d",&num);
    
	if (num > -10 && num < 10) {
        printf("O número %d tem 1 dígito.\n", num);
    } 
    else {
        if (num > -100 && num < 100) {
            printf("O número %d tem 2 dígitos.\n", num);
        }
        else {
            if (num > -1000 && num < 1000) {
                printf("O número %d tem 3 dígitos.\n", num);
            }
            else {
                printf("O número %d tem quatro ou mais dígitos.\n", num);
            }
        }
	}
	  return 0;
}

