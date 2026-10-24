#include <stdio.h>
#include <locale.h>
#include <string.h> 

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");

	char frase[100];
	char* quebra;
	
	printf("Digite uma frase: ");
    scanf("%100[^\n]s", frase);
    fflush(stdin);
    
	quebra = strtok(frase," ");
	
	if(quebra == NULL)
		printf("Não encontrado.\n");
	else
	{
		while (quebra != NULL)
		{
			printf("%s\n", quebra);
			quebra = strtok(NULL," ");
		}
	}

    return 0;
}

