//
// Made by Juh on CLion 05/08/26 - pilha com estrutura
//

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No { // estrutura
    float info;
    struct No* anterior;
} No;

typedef struct {
    No* topo;
} Pilha;

Pilha* cria(void) { // criar a pilha
    Pilha *p;
    p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

Pilha* push(Pilha *p, float v) { // inserir elemento
    No* aux;
    aux = (No*) malloc(sizeof(No));
    aux->info = v;
    aux->anterior = p->topo;
    p->topo = aux;
    return p;
}

int vazia(Pilha* p) {
    return (p->topo == NULL);
}

float pop(Pilha *p) { // remover elemento
    float v;
    No* aux;
    if (vazia(p)) {
        printf("Pilha vazia!\n");
        exit(1); 
    }
    v = p->topo->info;
    aux = p->topo;
    p->topo = aux->anterior;
    free(aux);
    
    return v;
}

void libera(Pilha *p) { // liberar estrutura
    No* q = p->topo;
    while (q != NULL) {
        No *t = q->anterior;
        free(q);
        q = t;
    }
    free(p);
}

void imprime (Pilha* p) { // imprimir a estrutura de pilha
    No* q;
    for (q=p->topo; q!=NULL; q=q->anterior)
        printf("%4.2f\n",q->info);
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

    return 0;
}