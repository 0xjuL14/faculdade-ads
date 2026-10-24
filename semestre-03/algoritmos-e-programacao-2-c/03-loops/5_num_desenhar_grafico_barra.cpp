#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	
	const int tamanho = 5;
	int num[tamanho];
	int maior, menor;
	int i, y;
	
	printf("Digite %d valores inteiros (positivos ou negativos):\n", tamanho);
	for(i = 0; i < tamanho; i++) {
		printf("Informe o %dº nº: ", i + 1);
		scanf("%d", &num[i]);
	}
	printf("\n");
	
	maior = num[0];
	menor = num[0];
	
	for (i = 1; i < tamanho; i++) {
		if (num[i] > maior) { maior = num[i]; }
		if (num[i] < menor) { menor = num[i]; }
	}

	if(maior < 0) { maior = 0; }
	if(menor > 0) { menor = 0; }
	
    printf("--- Gráfico de Barras ---\n\n");

	for (y = maior; y >= menor; y--) {
		if (y == 0) {
			printf("--------------------------\n");
			continue;
		}
		printf("  "); 
		
		for (i = 0; i < tamanho; i++) {
			if ((y > 0 && num[i] >= y) || (y < 0 && num[i] <= y)) {
				printf("*** "); 
			} else {
				printf("     "); 
			}
		}
		printf("\n"); 
	}
	system("pause");
	return 0;
}

