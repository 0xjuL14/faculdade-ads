//
// Created by juh on 11/11/25 on CLion
//

#include <stdio.h> // a de sempre >_<
#include <stdlib.h> // para a função rand() - para sortear números
#include <time.h> // para a função time() - para que o sorteio seja diferente a cada vez
#include <locale.h> // para usar em PT-BR/ABNT2

#define TAMANHO 15 // a lista de números terá 15 índices
#define LIMITE_MAXIMO 15 // números sorteados vão de 1 a 15

//  FUNÇÃO BUBBLE SORT oºOºoº
void bubbleSort(int vetor[], int tamanho) {
    int i, j, temp;

    for (i = 0; i < tamanho - 1; i++) { // repete a organização do bubble sort conforme o tamanho definido
        for (j = 0; j < tamanho - 1 - i; j++) { // COMPARAÇÃO: "tamanho - 1 - i" é para que o loop ignore o que já foi organizado
            if (vetor[j] > vetor[j+1]) { // O número atual (vetor[j]) é maior que o próximo (vetor[j+1])? Se SIM, trocam de lugar:
                temp = vetor[j]; //  Guarda o número maior na variável temporária
                vetor[j] = vetor[j+1]; // Coloca o número menor no lugar do maior
                vetor[j+1] = temp; // Coloca o número maior no lugar que estava vazio
            }
        }
    }
}

// FUNÇÃO Imprimir APENAS os Números Distintos
// obs.: A ordenação é necessária para que a função funcione corretamente
void imprimirDistintos(const char *nome, int vetor[], int tamanho) {
    printf("%s: [", nome); // o %s usa a string para o que estará na main "Vetor Final" + ':' :O

    if (tamanho > 0) {
        printf("%d", vetor[0]); // O 1º número sempre deve ser impresso pois não tem nada antes dele :)
    }

    for (int i = 1; i < tamanho; i++) { // o loop percorre a lista, começando do SEGUNDO número (i = 1)!!
        // nesse ponto, a lista já está organizada, então os repetidos estão lado a lado!!!
        if (vetor[i] != vetor[i-1]) { // Este número (vetor[i]) é diferente do número que veio antes (vetor[i-1])?
            printf(", %d", vetor[i]); // Se SIM, ele é um número único e deve ser impresso :)
        }
    }
    printf("]\n");
}

int main() { // FUNÇÃO PRINCIPAL
    setlocale(LC_ALL, "portuguese-brazilian");

    int vetor[TAMANHO]; // vetor principal com 15 índices vazios

    srand(time(NULL)); // Prepara o sorteador, usando o relógio para garantir que os números sejam novos ;)

    // Sorteio e Preenchimento do Vetor
    for (int i = 0; i < TAMANHO; i++) { // o loop vai do índice 0 até o 14
        vetor[i] = (rand() % LIMITE_MAXIMO) + 1; // sorteia um nº de 1 a 15 e guarda no índice 'i' do vetor
    }

    printf("\tNúmeros Sorteados:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", vetor[i]); // Exibe o vetor ANTES da ordenação
    }
    printf("\n\n");

    // ORDENAÇÃO
    bubbleSort(vetor, TAMANHO); // manda a lista para a função de organizar
    printf("\tApós Bubble Sort:\n");
    for (int i = 0; i < TAMANHO; i++) { // o loop anda e imprime a lista organizada
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("\n\tOrdem crescente dos Nºs Distintos:\n");
    imprimirDistintos("Vetor Final",vetor, TAMANHO); // imprime somente os nºs distintos
    // não precisa de marcadores % pois é a chamada da função, ou seja, na função já tem :)

    return 0; // GG! deu tudo certo >.<'
}