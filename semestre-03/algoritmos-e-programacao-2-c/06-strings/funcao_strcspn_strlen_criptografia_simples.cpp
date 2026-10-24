#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
    char frase[101], fraseCriptografada[101];
    int chave = 0;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    
    frase[strcspn(frase, "\n")] = '\0';
    
    printf("Informe a chave de Criptografia (nº inteiro): ");
    scanf("%d", &chave);

    for(int i = 0; i < strlen(frase); i++) { 
        fraseCriptografada[i] = frase[i] + chave;
	}
    
    fraseCriptografada[strlen(frase)] = '\0';

    printf("A frase criptografada é: %s\n", fraseCriptografada);
	
    return 0;
}
