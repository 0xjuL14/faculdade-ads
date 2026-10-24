//
// Created by juh on 11/12/25 on CLion
//

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define LINHAS 3
#define COLUNAS 3
#define TAMANHO_VETOR (LINHAS * COLUNAS) // número total de células na matriz (3x3=9)
#define TAMANHO_MAX_UNIAO (TAMANHO_VETOR * 2) // para que uniao tenha espaço (9 de A + 9 de B)

enum eTipoOperacao { // ETIQUETAS fixas para cada tipo de operação
    UNIAO, INTERSECAO, DIFERENCA_A_B,
    ADICAO, SUBTRACAO, MULTIPLICACAO
};

struct stConjunto { // MOLDE da ficha de dados para cada matriz de entrada
    char nome[5]; // identificar a matriz com um char (A/B)
    int matriz[LINHAS][COLUNAS]; // espaço para a tabela de números (matriz 3x3)
};

void bubbleSort(int vetor[], int tamanho) { // Bubble Sort para organizar a lista do menor para o maior ;)
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) { // loop até que todos os maiores estejam no fim
        for (j = 0; j < tamanho - 1 - i; j++) { // loop que compara vizinhos
            if (vetor[j] > vetor[j+1]) { // se o número atual for MAIOR que o próximo...
                temp = vetor[j]; // TROCA 1: Guarda o maior na variável temporária
                vetor[j] = vetor[j+1]; // TROCA 2: O menor vai para o lugar do maior
                vetor[j+1] = temp; // TROCA 3: O maior vai para o lugar do menor
            }
        }
    }
}

int contemElemento(int vetor[], int tamanho, int elemento) {
    for (int k = 0; k < tamanho; k++) { // loop que olha cada número na lista
        if (vetor[k] == elemento) { // se o número procurado for encontrado...
            return 1; // devolve 1 (SIM, está contido!!)
        }
    }
    return 0; // Senão, o loop devolve 0 (NÃO está contido!!)
}

void lerMatrizes(struct stConjunto *conjuntoA, struct stConjunto *conjuntoB) { // pede os números das matrizes pro usuário :D
    printf("--- 1. LEITURA DA MATRIZ %s (%dx%d) ---\n", conjuntoA->nome, LINHAS, COLUNAS); // recebe o ENDEREÇO da Matriz A e usa *ponteiro para preenchê-la
    for (int l = 0; l < LINHAS; l++) {
        for (int c = 0; c < COLUNAS; c++) {
            printf("%s[%d][%d]: ", conjuntoA->nome, l, c);
            scanf("%d", &conjuntoA->matriz[l][c]); // guarda o nº digitado na posição [l][c] da matriz A
        }
    }
    printf("\n--- 2. LEITURA DA MATRIZ %s (%dx%d) ---\n", conjuntoB->nome, LINHAS, COLUNAS); // recebe o ENDEREÇO da Matriz B e usa *ponteiro para preenchê-la
    for (int l = 0; l < LINHAS; l++) {
        for (int c = 0; c < COLUNAS; c++) {
            printf("%s[%d][%d]: ", conjuntoB->nome, l, c);
            scanf("%d", &conjuntoB->matriz[l][c]); // guarda o nº digitado na posição [l][c] da matriz B
        }
    }
}

void imprimirConjunto(struct stConjunto conjunto) { // mostra a matriz A ou B respectivamente (recebe a ficha completa da struct)
    printf("\n>>> MATRIZ %s:\n", conjunto.nome); // imprime o nome da matriz (A/B conforme anda o loop)
    for (int l = 0; l < LINHAS; l++) {
        printf("|");
        for (int c = 0; c < COLUNAS; c++) {
            printf("%4d ", conjunto.matriz[l][c]); // imprime o número que está na posição [l][c]
        }
        printf("|\n");
    }
}

void imprimirMatrizPura(const char *nome, int matriz[][COLUNAS]) { // mostra matrizes de soma/multiplicação
    printf("\n>>> MATRIZ %s:\n", nome); // recebe o nome e a matriz que tem o resultado
    for (int l = 0; l < LINHAS; l++) {
        printf("|");
        for (int c = 0; c < COLUNAS; c++) {
            printf("%4d ", matriz[l][c]); // imprime o número da matriz de resultado
        }
        printf("|\n");
    }
}

void operacaoMatricial(struct stConjunto *A, struct stConjunto *B, int matResultado[][COLUNAS], enum eTipoOperacao operacao) { // operações entre matrizes

    if (operacao == ADICAO || operacao == SUBTRACAO) { // se for SOMA ou SUBTRAÇÃO
        for (int l = 0; l < LINHAS; l++) {
            for (int c = 0; c < COLUNAS; c++) {
                if (operacao == ADICAO) {
                    matResultado[l][c] = A->matriz[l][c] + B->matriz[l][c]; // SOMA o número na mesma posição nas duas matrizes
                } else { // SUBTRACAO
                    matResultado[l][c] = A->matriz[l][c] - B->matriz[l][c]; // SUBTRAI o número na mesma posição nas duas matrizes
                }
            }
        }
    }
    else if (operacao == MULTIPLICACAO) { // se for MULTIPLICAÇÃO, faz várias somas e multiplicações!! :O
        for (int l = 0; l < LINHAS; l++) {
            for (int c = 0; c < COLUNAS; c++) {
                matResultado[l][c] = 0; // atribui 0 para inicializar
                for (int k = 0; k < COLUNAS; k++) {
                    matResultado[l][c] += A->matriz[l][k] * B->matriz[k][c];
                }
            }
        }
    }
}

void imprimirResultadoConjunto(const char *nome, int vetor_original[], int tamanho_original, enum eTipoOperacao tipo) { // operação de conjuntos
    int vetor_copia[tamanho_original]; // recebe o resultado bagunçado
    memcpy(vetor_copia, vetor_original, tamanho_original * sizeof(int)); // cria uma CÓPIA do resultado bagunçado :O

    printf("\n--- %d. RESULTADO CONJUNTO: %s ---\n", tipo + 3, nome);

    printf(">> RESULTADO ORIGINAL: ["); // imprime o resultado bagunçado original, não a cópia ;)
    for (int i = 0; i < tamanho_original; i++) {
        printf("%d", vetor_original[i]);
        if (i < tamanho_original - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    bubbleSort(vetor_copia, tamanho_original); // chama a função bubbleSort para organizar a CÓPIA

    printf(">> SOMENTE ORDENADO (%d elementos): [", tamanho_original); // imprime o resultado organizado e bonitinho a partir da cópia :)
    for (int i = 0; i < tamanho_original; i++) {
        printf("%d", vetor_copia[i]);
        if (i < tamanho_original - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    setlocale(LC_ALL, "portuguese-brazilian");
    // Cria as fichas A e B e dá o nome a elas usando o strcpy
    struct stConjunto conjuntoA;
    struct stConjunto conjuntoB;
    strcpy(conjuntoA.nome, "A");
    strcpy(conjuntoB.nome, "B");
    // cria as caixas para os resultados de cada operação matricial
    int matSoma[LINHAS][COLUNAS];
    int matSubtracao[LINHAS][COLUNAS];
    int matMultiplicacao[LINHAS][COLUNAS];
    // cria as caixas para os resultados de cada operação de conjunto matricial
    int uniao[TAMANHO_MAX_UNIAO];
    int intersecao[TAMANHO_VETOR];
    int diferenca_a_b[TAMANHO_VETOR];
    // cria as caixas para inicializar cada operação de conjunto matricial
    int tam_uniao = 0;
    int tam_intersecao = 0;
    int tam_diferenca = 0;

    int i, j, elemento;

    lerMatrizes(&conjuntoA, &conjuntoB); // chama a função de ler cada matriz

    printf("\n==================================\n");
    printf("   VISUALIZAÇÃO DAS MATRIZES DE ENTRADA"); // imprime as matrizes A e B de acordo com o que foi digitado de uma forma bonitinha :)
    printf("\n==================================");
    imprimirConjunto(conjuntoA); // usa a função para struct de A
    imprimirConjunto(conjuntoB); // usa a função para struct de B
    printf("\n==================================\n");

    // OPERAÇÕES ARITMÉTICAS (matriz)
    operacaoMatricial(&conjuntoA, &conjuntoB, matSoma, ADICAO);
    imprimirMatrizPura("SOMA (A + B)", matSoma);  // função "imprimirMatrizPura" para imprimir o resultado aritmético (que não está na struct) de soma

    operacaoMatricial(&conjuntoA, &conjuntoB, matSubtracao, SUBTRACAO);
    imprimirMatrizPura("SUBTRACAO (A - B)", matSubtracao); // função "imprimirMatrizPura" para imprimir o resultado aritmético (que não está na struct) de subtração

    operacaoMatricial(&conjuntoA, &conjuntoB, matMultiplicacao, MULTIPLICACAO);
    imprimirMatrizPura("MULTIPLICACAO (A * B)", matMultiplicacao); // função "imprimirMatrizPura" para imprimir o resultado aritmético (que não está na struct) de multiplicação

    // OPERAÇÕES DE CONJUNTO (vetor)
    tam_uniao = 0; // UNIÃO (A U B)
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            uniao[tam_uniao++] = conjuntoA.matriz[i][j];
        }
    }
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            uniao[tam_uniao++] = conjuntoB.matriz[i][j];
        }
    }
    imprimirResultadoConjunto("UNIAO (A + B)", uniao, tam_uniao, UNIAO);

    tam_intersecao = 0; // INTERSEÇÃO (A n B)
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            elemento = conjuntoA.matriz[i][j];
            if (contemElemento((int*)conjuntoB.matriz, TAMANHO_VETOR, elemento))
            {
                intersecao[tam_intersecao++] = elemento;
            }
        }
    }
    imprimirResultadoConjunto("INTERSECAO (A n B)", intersecao, tam_intersecao, INTERSECAO);

    tam_diferenca = 0; // DIFERENÇA (A - B)
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            elemento = conjuntoA.matriz[i][j];
            if (!contemElemento((int*)conjuntoB.matriz, TAMANHO_VETOR, elemento))
            {
                diferenca_a_b[tam_diferenca++] = elemento;
            }
        }
    }
    imprimirResultadoConjunto("DIFERENCA (A - B)", diferenca_a_b, tam_diferenca, DIFERENCA_A_B);

    return 0; // GG! <3
}