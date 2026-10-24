#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
    char frase[101], fraseinvertida[101];
    int i, j = 0;

    printf("Digite uma frase: ");
    scanf("%100[^\n]s", frase);
    
	int tamanho = strlen(frase);
	
    for(i = tamanho - 1; i >= 0; i--) {
    	fraseinvertida[j] = frase[i];
    	j++;
	}
	
	fraseinvertida[j] = '\0';
    	
	printf("\nString original: %s\n", frase);
    printf("String invertida: %s\n", fraseinvertida);
	
    return 0;
}

