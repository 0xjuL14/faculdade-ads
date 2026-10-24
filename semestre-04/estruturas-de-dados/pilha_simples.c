//
// Made by Juh on CLion 04/24/26
//

// queria colocar opção de prioridade caso um nº tenha um char P

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 50

typedef struct {
    int n;
    float vet[MAX];
} Pilha;

Pilha* cria(void) {
    Pilha* p;
    p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0; // inicializa com 0 elementos
    return p;
}

void push(Pilha* p, float v) { // inserir um elemento no topo
    if (p->n == MAX) {
        printf("A capacidade da pilha estourou!\n");
        exit(1); // abortar
    }
    p->vet[p->n] = v; // inserir elemento na prox posição livre
    p->n++;
}

int vazia(Pilha* p) {
    return (p->n == 0);
}

float pop(Pilha* p) { // remover elemento do topo
    float v;
    if (vazia(p)) {
        printf("Pilha vazia!\n");
        exit(1); // abortar
    }
    v = p->vet[p->n-1]; // retira elemento do topo
    p->n--;
    return v;
}

void imprime(Pilha* p) {
    int i;
    printf("Pilha: ");
    for (i = p->n - 1; i >= 0; i--) {
        printf("%.2f ", p->vet[i]);
    }
    printf("\n");
}

void libera(Pilha* p) { // liberar a struct
    free(p);
}
int main() {
    setlocale(LC_ALL, "Portuguese");
    Pilha* p = cria();
    push(p, 20.0);
    push(p, 20.8);
    push(p, 20.3);
    push(p, 44.5);
    push(p, 33.3);
    push(p, 20.9);
    imprime(p);
    printf("Retirado: %4.2f\n", pop(p));
    printf("Retirado: %4.2f\n", pop(p));
    printf("Configuração da fila:\n");
    imprime(p);
    libera(p);
    system("pause");

    return 0;
}