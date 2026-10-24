#include <stdio.h>
#include <locale.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
	
	int conta, d1, d2, d3, d4, dv, aux;
	
	printf("Informe a conta (4 dígitos): ");
	scanf("%d", &conta);
	fflush(stdin);
	
	d1 = conta / 1000;
	aux = conta % 1000;
	d2 = aux / 100;
	aux = aux % 100;
	d3 = aux / 10;
	d4 = aux % 10;

	/* passo 1 = dígito 1 + dígito 2 +dígito 3 + dígito 4
	   passo 2 = dígito 1 * dígito 2 * dígito 3 * dígito 4
	   passo 3 = resultado passo 2 - resultado passo 1
	   passo 4 = resultado passo3 % 9         */
	   
	aux = (d1 + d2 + d3 + d4);
	aux = (d1 * d2 * d3 * d4) - aux;
	dv = aux % 9;
		
    printf("O número da conta é %d-%d", conta, dv);
   
    return 0;
    
}

