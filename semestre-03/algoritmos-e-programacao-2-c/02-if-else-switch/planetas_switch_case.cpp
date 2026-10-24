#include <stdio.h>
#include <locale.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

    int p;
    
    printf("\nDigite o n° do planeta desejado: \n");
    printf("\n1 - Mercúrio\n");
    printf("\n2 - Vênus\n");
    printf("\n3 - Terra\n");
    printf("\n4 - Marte\n");
    printf("\n5 - Júpiter\n");
    printf("\n6 - Saturno\n");
    printf("\n7 - Netuno\n");
    printf("\n8 - Urano\n");
    printf("\n9 - Plutão\n");
    printf("\n");
    scanf("%d", &p);
	printf("\n");
	
	switch (p) {
        case 1:
            printf("A distância do Sol até Mercúrio é de 59 milhões de km.\n");
            break; 

        case 2:
            printf("A distância do Sol até Vênus é de 108 milhões de km.\n");
            break;

        case 3:
            printf("A distância do Sol até Terra é de 150 milhões de km.\n");
            break;

        case 4:
            printf("A distância do Sol até Marte é de 228 milhões de km.\n");
            break;

        case 5:
            printf("A distância do Sol até Júpiter é de 750 milhões de km.\n");
            break;

        case 6:
            printf("A distância do Sol até Saturno é de 1431 milhões de km.\n");
            break;

        case 7:
            printf("A distância do Sol até Netuno é de 2877 milhões de km.\n");
            break;

        case 8:
            printf("A distância do Sol até Urano é de 4509 milhões de km.\n");
            break;

        case 9:
            printf("A distância do Sol até Plutão é de 5916 milhões de km.\n");
            break;
        default:
            printf("Erro: O número %d é inválido.\n", p);
            break;
    }
    
	return 0;
}

