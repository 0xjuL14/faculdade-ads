//
// Created by juh on 11/12/25 on CLion
//

#include <stdio.h>
#include <string.h>   // strlen, strcpy, memset, etc.
#include <ctype.h>    // tolower, isalpha
#include <locale.h>
#include <stdbool.h>  // bool, true, false

#define TAMANHO_MAX 50 // Tamanho máximo da string (49 caracteres + '\0')

enum eResultado { // ETIQUETA para o teste de palíndromo
    NAO_ANALISADO, // usada para inicialização
    SIM_EH_PALINDROMO,
    NAO_EH_PALINDROMO
};

struct stEstatisticas { // MOLDE para as estatísticas da String
    char original[TAMANHO_MAX]; // guarda a string original lida
    int vogais; // contagem de vogais
    int consoantes; // contagem de consoantes
    int tamanho_util; // comprimento real sem contar o '\0'
    enum eResultado palindromo; // resultado da checagem do enum
};

bool ehPalindromo(const char *str) { // função para ver se é ou não um palíndromo
    int i = 0; // marca o início (i) da string
    int j = strlen(str) - 1; // marca o fim (j) da string | strlen() descobre o comprimento e -1 leva à última letra

    while (i < j) {
        if (tolower(str[i]) != tolower(str[j])) { // ignora se a letra é maiúscula ou minúscula
            return false; // se for diferente mesmo ignorando M m, retorna que NÃO é palíndromo
        }
        i++;
        j--;
    }
    return true; // se o loop não encontra diferença, retorna que É palíndromo :D
}

int contaVogais(const char *str) { // função para contar vogais (retorna int)
    int contador = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]); // transforma a letra atual em minúscula para ser mais fácil de comparar
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') { // requisitos para ser vogal
            contador++; // se for vogal, + 1 no contador
        }
    }
    return contador; // retorna o resultado do contador
}

int contaConsoantes(const char *str) { // função para contar consoantes (retorna int)
    int contador = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (isalpha(c) && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) { // se não for vogal
            contador++; // se for consoante, + 1 no contador
        }
    }
    return contador; // retorna o resultado do contador
}

void manipularString(char *str) { // função de manipulação de string com ponteiro *str
    printf("\n--- MANIPULAÇÕES E PONTEIROS ---\n");

    // NOTA: A string 'str' aqui já contém os caracteres '#' do memset para simular o lixo

    str[0] = 'X'; // Ex.: trocar o 1º char por 'X' (ponteiros/índice 0)
    printf("1. 1º caractere trocado por 'X': %s\n", str);

    // O código aqui vai imprimir o lixo de memória '#...#' que foi preenchido com memset!
    int len = strlen(str); // descobre onde está o '\0' (fim da string)
    str[len] = 'Z'; // trocar o '\0' por 'Z'
    printf("2. Caractere '\\0' trocado por 'Z': %s (Imprime lixo de memória)\n", str); // imprime 'Z' e o lixo da memória até encontrar outro '\0' aleatório! :O

    str[len + 1] = '\0';  // adicionar um novo "ponto final" '\0' após o 'Z' manualmente para que a string não continue lendo infinitamente babozeiras
    printf("   (Novo '\\0' adicionado, string corrigida: %s)\n", str);

    printf("\n3. Caracteres um abaixo do outro:\n"); // função para quebrar a string em chars um abaixo do outro
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c\n", str[i]); // Imprime a letra atual e PULA a linha
    }
    printf("\n");
}

void stringEspelhada(const char *original, char *invertida) { // função de inversão/string espelhada
    int len = strlen(original); // recebe a palavra ORIGINAL e o espaço VAZIO (invertida) para preencher
    int j = 0; // pega o índice do último char e o índice de escrita (i e j)
    for (int i = len - 1; i >= 0; i--, j++) { // o loop 'i' começa no FIM e 'j' começa no INÍCIO !!!!!
        invertida[j] = original[i]; // pega a letra de trás e coloca na frente da nova palavra
    }
    invertida[j] = '\0'; // finaliza a nova string colocando o "ponto final" '\0'
}

void processarEstatisticas(struct stEstatisticas *est, const char *original) { // função de preencher a struct com estatísticas (já que ela foi feita pra isso XD)
    // >>>>> essa função recebe o ENDEREÇO do ponteiro *est e a palavra <<<<
    strcpy(est->original, original); // Copia o nome original para dentro da struct
    est->tamanho_util = strlen(original); // Preenche os campos da struct com o resultado das funções
    est->vogais = contaVogais(original);
    est->consoantes = contaConsoantes(original);

    if (ehPalindromo(original)) { // preenche o campo enum de acordo com o resultado
        est->palindromo = SIM_EH_PALINDROMO;
    } else {
        est->palindromo = NAO_EH_PALINDROMO;
    }
}

int main() {
    setlocale(LC_ALL, "portuguese-brazilian");

    char entrada[TAMANHO_MAX];
    char entrada_copia[TAMANHO_MAX]; // para manipulação de caracteres
    char entrada_invertida[TAMANHO_MAX];
    struct stEstatisticas stats; // cria a "ficha" de estatísticas

    printf("--- Analise de String ---\n");
    printf("Digite uma string:\n");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = 0; // remove o '\n'

    memset(entrada_copia, '#', TAMANHO_MAX); // FORÇA o lixo de memória ser visível colocando '#'
    strcpy(entrada_copia, entrada);  // copia a string para uma variável que será manipulada ehehe
    manipularString(entrada_copia); // função VOID de manipulação direta
    processarEstatisticas(&stats, entrada); // struct e funções de retorno
    stringEspelhada(entrada, entrada_invertida); // função de inversão/espelhamento

    printf("\n\n=== RESULTADO DAS ESTATÍSTICAS ===\n");
    printf("String Original: %s\n", stats.original);
    printf("Comprimento Total: %d\n", stats.tamanho_util);
    printf("Total de Vogais: %d\n", stats.vogais);
    printf("Total de Consoantes: %d\n", stats.consoantes);

    printf("Palíndromo (Enum): %s\n", (stats.palindromo == SIM_EH_PALINDROMO) ? "SIM" : "NÃO"); // pega o enum usando o ternário

    printf("String Espelhada: %s\n", entrada_invertida);
    printf("==================================\n");

    return 0; // GG! <3
}