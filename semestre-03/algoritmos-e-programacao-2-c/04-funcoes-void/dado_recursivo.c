//
// Created by juh on CLion
//
/*
            Simule um jogo de dado utilizando funções:
    Crie uma função chamada Dado() que retorna um número aleatório de 1 a 6.
    Crie uma função recursiva que simule o lançamento do dado N vezes.
    Ao final, informe:
        Quantas vezes cada número apareceu
        A porcentagem de ocorrência de cada valor
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Dado(void) { // void pq a função n recebe nenhum parâmetro e retorna um nº int
    return 1 + (rand() % 6); // 1 a 6 (soma 1 ao resultado  do índice 0 a 5)
}

void lancamento_recursivo(int n, int contador[6]) { // n devolve nada e só modifica o contador[]
    if (n == 0) { // caso base, se n == 0, não há mais lançamentos disponíveis
        return;
    }

    int valor = Dado(); // chamada da função e guarda 1 a 6 no valor
    printf("Caiu: %d ! Lançamentos restantes: %d\n", n - 1, valor);

    contador[valor - 1]++; // ajuste dos índices + somatório da face do dado

    lancamento_recursivo(n - 1, contador); // chamada recursiva, faltam n - 1 lançamentos
}

int main(void) {
    int N;
    int contador[6] = {0, 0, 0, 0, 0, 0}; // inicializando o vetor com 0s

    srand(time(NULL)); // inicializa rand

    printf("Digite o valor de vezes que você quer rolar o dado! :)\n");
    scanf("%d", &N);

    lancamento_recursivo(N, contador);

    printf("\nResultado:\n");
    for (int i = 0; i < 6; i++) {
        double porcentagem = 0.0;
        if (N > 0) {
            porcentagem = (contador[i] * 100.0) / N; // % de ocorrência
        }
        printf("Valor %d: %d vezes (%.2f%%)\n", i + 1, contador[i], porcentagem);
    }

    return 0;
}
