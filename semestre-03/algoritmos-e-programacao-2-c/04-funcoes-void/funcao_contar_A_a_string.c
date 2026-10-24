#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int contaVogais(const char *str) {
    int contador = 0;
    int i;

    // Itera até encontrar o char '\0'
    for (i = 0; str[i] != '\0'; i++) {
        // Converte o char para min.
        char c = tolower(str[i]);

        // Verifica se é uma vogal
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                contador++;
                break;
            default:
                break;
        }
    }
    return contador;
}

int contaConsoantes(const char *str) {
    int contador = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        if (isalpha(c)) {
            c = tolower(c);

            // Se for uma letra E não for vogal = consoante
            if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
                contador++;
            }
        }
    }
    return contador;
}

int main() {
    setlocale(LC_ALL, "portuguese-brazilian");

    char frase[100];
    int total_vogais, total_consoantes;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    total_vogais = contaVogais(frase);
    total_consoantes = contaConsoantes(frase);

    printf("\n-----------------------\n");
    printf("\"%s\"\n", frase);
    printf("VOGAIS: %d\n", total_vogais);
    printf("CONSOANTES: %d\n", total_consoantes);
    printf("------------------------\n");

    return 0;
}