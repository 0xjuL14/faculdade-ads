#include <stdio.h>
#include <locale.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
	
	int valorsaque, ced10, ced5, ced2, ced1, saldo;
	
	printf("Informe o valor de saque desejado: ");
	scanf("%d", &valorsaque);
	fflush(stdin);
	
	ced10 = valorsaque / 10;
	saldo = valorsaque % 10;
	ced5 = saldo / 5;
	saldo = saldo % 5;
	ced2 = saldo / 2;
	saldo = saldo % 2;
	ced1 = saldo;
		
    printf(" Cédula(s) de R$10: %d\n Cédula(s) de R$5: %d\n Cédula(s) de R$2: %d\n Cédula(s) de R$1: %d", ced10, ced5, ced2, ced1);
   
    return 0;
    
}

