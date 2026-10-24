#include <stdio.h>
#include <locale.h>
#include <string.h>

void dataExtenso(int dia, int mes, int ano) {
    char *nomes_meses[] = {
        "Inválido", //posição 0
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", // posições 1, 2, 3, 4, 5, 6
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro" // posições 7, 8, 9, 10, 11 e 12 respectivamente
    };
    
    if (mes >= 1 && mes <= 12) {
        printf("\nData por Extenso: %d de %s de %d\n", dia, nomes_meses[mes], ano);
    } else {
        printf("\nErro: Mês inválido (%d).\n", mes);
    }
}

int main() {
	
    setlocale(LC_ALL, "portuguese-brazilian"); 
    
    int dia, mes, ano;

    printf("Digite o dia: ");
    scanf("%d", &dia);
    
    printf("Digite o mês (1 a 12): ");
    scanf("%d", &mes);
    
    printf("Digite o ano: ");
    scanf("%d", &ano);

    dataExtenso(dia, mes, ano);

    return 0;
}

