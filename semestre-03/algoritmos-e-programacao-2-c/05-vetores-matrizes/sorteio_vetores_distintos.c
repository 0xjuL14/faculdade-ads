//
// Created by juh on 11/11/25 on CLion
//

#include <stdio.h>
#include <stdlib.h> // para as funções rand(), srand()
#include <time.h>   // para a função time()
#include <locale.h>

//  limite do sorteio
#define LIMITE_INFERIOR 1
#define LIMITE_SUPERIOR 100
#define TAMANHO_ORIGINAL 50

int verificaSeDistinto(int vetor[], int tamanho_atual, int numero) {
    for (int k = 0; k < tamanho_atual; k++) {
        if (vetor[k] == numero) {
            return 0; // já existe
        }
    }

    return 1; // É distinto
}

int main() {
    setlocale(LC_ALL, "portuguese-brazilian");

    int vetor_original[TAMANHO_ORIGINAL];
    int vetor_distintos[TAMANHO_ORIGINAL]; // Máx. 50 nºs distintos
    int i;
    int contador_distintos = 0;

    srand(time(NULL)); // inicia o modo sorteio :)

    printf("--- 1. Vetor Original (%d Números entre %d e %d) ---\n",
           TAMANHO_ORIGINAL, LIMITE_INFERIOR, LIMITE_SUPERIOR);

    for (i = 0; i < TAMANHO_ORIGINAL; i++) {  // Sorteia e atribui à variável
        int numeroSorteado = (rand() % (LIMITE_SUPERIOR - LIMITE_INFERIOR + 1)) + LIMITE_INFERIOR;

        vetor_original[i] = numeroSorteado;

        printf("%4d", vetor_original[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }

    for (i = 0; i < TAMANHO_ORIGINAL; i++) {
        int numero_atual = vetor_original[i];

        // Verifica se o número ainda não está no vetor de distintos
        if (verificaSeDistinto(vetor_distintos, contador_distintos, numero_atual)) {
            vetor_distintos[contador_distintos] = numero_atual;
            contador_distintos++;
        }
    }

    printf("\n\tVetor de Números Distintos\n");
    printf("Total de Números Distintos Encontrados: %d\n", contador_distintos);

    for (i = 0; i < contador_distintos; i++) {
        printf("%4d", vetor_distintos[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }

    printf("\n");

    return 0;
}