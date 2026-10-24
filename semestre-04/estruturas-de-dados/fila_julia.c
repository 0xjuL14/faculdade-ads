//
// Made by Juh on CLion 04/24/26
//


#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

struct Fila {
    int capacidade;
    float *dados;
    int primeiro;
    int ultimo;
    int nItens;
};

void criarFila(struct Fila *f, int c) {
    f -> capacidade = c;
    f -> dados = (float*) malloc(f -> capacidade *sizeof(float));
    f -> primeiro = 0; // inicialização
    f -> ultimo = -1; // anterior do próximo
    f -> nItens = 0; // capacidade que se está atribuindo
}

void inserir(struct Fila *f, float v) {
    if (f -> ultimo == f -> capacidade - 1) {
        f -> ultimo = -1; // volta pro início pq é uma fila circular
    }
    f -> ultimo++; // avança
    f -> dados[f -> ultimo] = v; // insere
    f -> nItens++; // atualiza a quantidade = + um item inserido
}

float remover(struct Fila *f) {
    float temp = f -> dados[f -> primeiro++]; // pega o valor do começo da fila e incrementa o 1º numa var temporária
    if (f -> primeiro == f -> capacidade) { // se chegou no fim
        f -> primeiro = 0; // volta pro início
    }
    f -> nItens--; // um item retirado
    return temp;
}

int estaVazia(struct Fila *f) {
    return (f -> nItens == 0); // o nº de itens determina o estado da fila
}

int estaCheia(struct Fila *f) {
    return (f -> nItens == f -> capacidade); // true se a fila está cheia, compara a capacidade com o n de itens
}

void mostrarFila(struct Fila *f) {
    int cont, i;
    for (cont = 0, i = f -> primeiro; cont < f -> nItens; cont++) {
        printf("%.2f\t", f -> dados[i++]);
        if (i == f -> capacidade)
            i = 0;
    }
    printf("\n\n");
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int opcao, capa;
    float valor;
    struct Fila umaFila;

    printf("\nInforme a capacidade máxima desejada para o atendimento:\n");
    scanf("%d", &capa);
    criarFila(&umaFila, capa);

    while (1) {
        printf("\n Informe a opção escolhida: ");
        printf("\n 1 | Inserir nº da ficha na fila;");
        printf("\n 2 | Remover nº atendido da fila;");
        printf("\n 3 | Mostrar andamento da fila;");
        printf("\n 0 | Sair! \n ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                free(umaFila.dados);
                printf("Encerrando programa... até mais! <3");
                exit(0);
            case 1:
                if (estaCheia(&umaFila)) {
                    printf("\nOps! A fila está cheia!\n\n");
                } else {
                    printf("\nDigite o nº a ser inserido:");
                    scanf("%f", &valor);
                    inserir(&umaFila, valor);
                }
                break;
            case 2:
                if (estaVazia(&umaFila)) {
                    printf("\nAtualmente a fila está vazia!\n\n");
                } else {
                    valor = remover(&umaFila);
                    printf("Ficha %.2f removida com sucesso!\n\n", valor);
                }
                break;
            case 3:
                if (estaVazia(&umaFila)) {
                    printf("\nAtualmente a fila está vazia!\n\n");
                } else {
                    printf("\nFila: ");
                    mostrarFila(&umaFila);
                }
                break;
            default:
                printf("\nErro: Opção Inválida!\n\n");
        }
    }
}