//
// Made by Juh on CLion 17/04/26
//

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct Node {
    int num;
    struct Node *prox; // ponteiro p/ o próximo nó na lista (NULL se for o último)
}; typedef struct Node node; // cria um alias

int vazia(node *LISTA);
node *aloca(void);
void insereInicio(node *LISTA);
void insereFim(node *LISTA);
void insere(node *LISTA);
node *retiraInicio(node *LISTA);
node *retiraFim(node *LISTA);
node *retira(node *LISTA);
void exibe(node *LISTA);
void libera(node *LISTA);

int tam = 0; // começa coma lista vazia

int vazia(node *LISTA) { // verifica se a lista está vazia
    return (LISTA->prox == NULL); // vazia quando o nó cabeça (LISTA) aponta para NULL, devolve 1 se true se estiver vazia e 0 se false
}

node *aloca(void) { // aloca um novo node e le o valor
    node *novo = (node *) malloc(sizeof(node));
    if (!novo) {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    printf("Digite um número: ");
    scanf("%d", &novo->num);
    novo->prox = NULL; // novo nó n aponta para ninguém ainda
    return novo; // devolve o ponteiro para esse nó para quem chamou
}

void insereInicio(node *LISTA)
{
    node *novo = aloca();
    node *oldHead = LISTA->prox; // guarda quem era o 1º nó antigo, NULL se a lista estiver vazia
    LISTA->prox = novo; // o 1º nó passa a ser o novo nó
    novo->prox = oldHead; // novo nó aponta para o antigo 1º ou NULL se não tinha nenhum ainda
    tam++;
}

void insereFim(node *LISTA) {
    node *novo = aloca(); // cria um nó no final da lista
    novo->prox = NULL; // indicando que ele será o último que é após o NULL
    if (vazia(LISTA))
        LISTA->prox = novo; // se a lista estiver vazia, o elemento novo será o 1º da lista
    else {
        node *tmp = LISTA->prox; // senão percorre a lista
        while (tmp->prox != NULL) // até chegar no próximo onde é o NULL
            tmp = tmp->prox;
        tmp->prox = novo; // o último nó passa a apontar para o novo
    }
    tam++;
}

void insere(node *LISTA) {
    int pos, count;
    printf("Em que posicao [de 1 ate %d] voce deseja inserir: ", tam + 1);
    scanf("%d", &pos);

    if (pos > 0 && pos <= tam + 1) { // antes de cada passo: anterior recebe atual, e atual anda para atual -> prox.
        if (pos == 1) {
            insereInicio(LISTA);
        } else {
            node *atual = LISTA->prox;
            node *anterior = LISTA;
            node *novo = aloca();
            for (count = 1; count < pos; count++) {
                anterior = atual; // anterior está no nó antes da posição
                atual = atual->prox; // atual está na posição onde vai enfiar o novo
            }
            anterior->prox = novo;
            novo->prox = atual;
            tam++;
        }
    } else {
        printf("Posicao invalida\n\n");
    }
}

node *retiraInicio(node *LISTA)
{
    if (LISTA->prox == NULL) { //  não há o que tirar
        printf("Lista ja esta vazia\n");
        return NULL;
    } else {
        node *tmp = LISTA->prox;
        LISTA->prox = tmp->prox; // agora o 2º nó vira o 1º
        tam--;
        return tmp;
    }
}

node *retiraFim(node *LISTA) {
    if (LISTA->prox == NULL) {
        printf("Lista ja vazia\n\n");
        return NULL;
    } else {
        node *ultimo = LISTA->prox; // ultimo começa no 1º
        node *penultimo = LISTA; // penultimo começa no nó cabeça (LISTA)
        while (ultimo->prox != NULL) {
            penultimo = ultimo; // cada passo, penultimo recebe ultimo, e ultimo anda
            ultimo = ultimo->prox;
        }
        penultimo->prox = NULL; // o novo último não aponta para ninguém
        tam--;
        return ultimo;
    }
}

node *retira(node *LISTA)
{
    int opt, count;
    printf("Que posicao [de 1 ate %d] voce deseja retirar: ", tam);
    scanf("%d", &opt);

    if (opt > 0 && opt <= tam) { // anda com anterior e atual até a posição desejada
        if (opt == 1)
            return retiraInicio(LISTA);
        else {
            node *atual = LISTA->prox;
            node *anterior = LISTA;
            for (count = 1; count < opt; count++) {
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = atual->prox; // desvio: pula o atual, desconectando-o da lista
            tam--;
            return atual;
        }
    } else {
        printf("Posicao invalida\n\n");
        return NULL;
    }
}

void exibe(node *LISTA) { // mostra a lista percorrendo do 1º até o último nó
    if (vazia(LISTA)) {
        printf("Lista vazia!\n");
        return;
    }

    node *tmp = LISTA->prox;
    printf("Lista: ");
    while (tmp != NULL) {
        printf("%d ", tmp->num);
        tmp = tmp->prox;
    }
    printf("\n");
}


void libera(node *LISTA) {
    node *atual = LISTA->prox;
    while (atual != NULL) {
        node *prox = atual->prox;
        free(atual); // libera cada nó com free e põe a lista de volta ao estado vazia
        atual = prox;
    }
    LISTA->prox = NULL;
    tam = 0;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    node *LISTA = (node *) malloc(sizeof(node)); // aponta para o primeiro elemento da lista verdadeira
    if (!LISTA) {
        printf("Sem memoria!\n");
        return 1;
    }
    LISTA->prox = NULL; // n há nenhum nó ainda

    int opcao;

    do {
        printf("\nMENU:\n");
        printf("1 - limpar a lista\n");
        printf("2 - Mostra a Lista\n");
        printf("3 - Adiciona node no inicio\n");
        printf("4 - Adiciona node no final\n");
        printf("5 - Escolher onde inserir\n");
        printf("6 - Retirar do inicio\n");
        printf("7 - Retirar no fim\n");
        printf("8 - Escolher onde retirar\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        node *ret; // guarda os nós retornados por funções de remoção p/ imprimir e liberar

        switch (opcao) { // cada caso chama uma função
            case 1:
                libera(LISTA);
                printf("Lista limpa!\n");
                break;
            case 2:
                exibe(LISTA);
                break;
            case 3:
                insereInicio(LISTA);
                break;
            case 4:
                insereFim(LISTA);
                break;
            case 5:
                insere(LISTA);
                break;
            case 6:
                ret = retiraInicio(LISTA); // quando remove, imprime o valor removido e dá free(ret); para liberar memória.
                if (ret) {
                    printf("Retirado: %d\n", ret->num);
                    free(ret);
                }
                break;
            case 7:
                ret = retiraFim(LISTA);
                if (ret) {
                    printf("Retirado: %d\n", ret->num);
                    free(ret);
                }
                break;
            case 8:
                ret = retira(LISTA);
                if (ret) {
                    printf("Retirado: %d\n", ret->num);
                    free(ret);
                }
                break;
            case 0:
                printf("Saindo do programa\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (opcao != 0);

    libera(LISTA); // limpa todos os nós
    free(LISTA); // libera o nó cabeça
    return 0;
}
