#include <stdio.h>
#include <string.h>  
#include <stdbool.h>
#include <locale.h>   

bool ehPalindromo(const char *str) {
	int tamanho = strlen(str);
	int i = 0;
	int j = tamanho - 1;
	
	while (i < j) {
		if (str[i] != str[j]) {
			return false;
		}
	i++;
   	j--;
	}
	
    return true;
}

int main() {
    setlocale(LC_ALL, "portuguese-brazilian"); 
    
    char palavra[100];

    printf("Digite uma palavra ou frase para verificar se é um palíndromo: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0';
    
    if (ehPalindromo(palavra)) {
        printf("\nÉ um PALÍNDROMO.\n");
    } else {
        printf("\nNÃO é um palíndromo.\n");
    }

    return 0;
}

