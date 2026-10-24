#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
    char frase[101], substring[51];
    char *ptr;

    printf("Digite uma frase: ");
    scanf("%100[^\n]s", frase);
    fflush(stdin);

    printf("Digite a substring para buscar: ");
    scanf("%50[^\n]s", substring);
    fflush(stdin);

    ptr = strstr(frase, substring);

    if (ptr != NULL)
	{
        *ptr = '\0';
        printf("Conteúdo anterior a substring inserida: %s\n", frase);
	}
	else 
        printf("A substring inserida não foi encontrada na frase.\n");

    return 0;
}

