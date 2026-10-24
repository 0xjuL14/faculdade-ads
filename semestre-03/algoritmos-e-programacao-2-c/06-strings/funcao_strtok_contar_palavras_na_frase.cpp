#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
	
    char frase[101], fraseinvertida[101];
    int palavra = 0;
	char* quebra;
	
    printf("Digite uma frase: ");
    scanf("%100[^\n]s", frase);
    
	quebra = strtok(frase, " ");
	
	if(quebra == NULL)
		printf("\n");
	else
	{
		while (quebra != NULL)
		{
			palavra++;
		//	printf("%s\n", quebra);
			quebra = strtok(NULL, " ");
		}
	}
	
	printf("Há %d palavra(s) na string digitada.", palavra);
	
    return 0;
}
