#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
    char frase[101], stringConsonants[101];
    int contConsonants = 0;

    printf("Digite uma frase: ");
    scanf("%100[^\n]s", frase);
    fflush(stdin);

    for(int p = 0; p < strlen(frase); p++)
    	if(tolower(frase[p]) != 'a' && tolower(frase[p]) != 'e' && tolower(frase[p]) != 'i' && tolower(frase[p]) != 'o' && tolower(frase[p]) != 'u')
    	{
    		stringConsonants[contConsonants] = frase[p];
    		contConsonants++;
		}
		
	stringConsonants[contConsonants] = NULL;
	
	printf("String com apenas consoantes: %s\n", stringConsonants);
	
    return 0;
}

