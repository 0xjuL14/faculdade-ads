#include <stdio.h>
#include <locale.h>
#include <string.h> 

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");

	char frase[101], char_;
    char *ptrChar; //ponteiro
    
    printf("Digite uma frase: ");
    scanf("%100[^\n]s", frase);
    fflush(stdin);
    
    printf("Digite um caractere para realizar a busca: ");
    scanf("%c", &char_);
    fflush(stdin);
    
    ptrChar = strchr(frase, char_);
    
    if (ptrChar != NULL)
        printf("Caractere informado encontrado. Substring a partir da primeira ocorrência: %s\n", ptrChar);
    else 
        printf("O caractere informado não foi encontrado na frase.\n");

    return 0;
}

