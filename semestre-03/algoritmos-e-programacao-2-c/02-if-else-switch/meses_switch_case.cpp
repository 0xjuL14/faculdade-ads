#include <stdio.h>
#include <locale.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

    int mes;
    
    printf("\nDigite o n° do mês (1 a 12): ");
    scanf("%d", &mes);
	printf("\n");
	
	switch (mes) {
        case 1:
            printf("Mês: Janeiro\n");
            printf("Dias: 31\n");
            break; 

        case 2:
            printf("Mês: Fevereiro\n");
            printf("Dias: 28 (desconsiderando anos bissextos)\n");
            break;

        case 3:
            printf("Mês: Março\n");
            printf("Dias: 31\n");
            break;

        case 4:
            printf("Mês: Abril\n");
            printf("Dias: 30\n");
            break;

        case 5:
            printf("Mês: Maio\n");
            printf("Dias: 31\n");
            break;

        case 6:
            printf("Mês: Junho\n");
            printf("Dias: 30\n");
            break;

        case 7:
            printf("Mês: Julho\n");
            printf("Dias: 31\n");
            break;

        case 8:
            printf("Mês: Agosto\n");
            printf("Dias: 31\n");
            break;

        case 9:
            printf("Mês: Setembro\n");
            printf("Dias: 30\n");
            break;

        case 10:
            printf("Mês: Outubro\n");
            printf("Dias: 31\n");
            break;

        case 11:
            printf("Mês: Novembro\n");
            printf("Dias: 30\n");
            break;

        case 12:
            printf("Mês: Dezembro\n");
            printf("Dias: 31\n");
            break;
            
        default:
            printf("Erro: O número do mês informado é inválido.\n");
            break;
    }
    
    return 0;
}

