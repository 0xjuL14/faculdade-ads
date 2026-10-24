#include <stdio.h>
#include <locale.h>

#define linha 3
#define coluna 3

int main() {
    setlocale(LC_ALL, "portuguese-brazilian");

    int matriz[linha][coluna];

    for(int l = 0; l < linha; l++) {
        for(int c = 0; c < coluna; c++) {
            matriz[l][c] = 0;
        }
    }

    for(int l = 0; l < linha; l++) {
        for(int c = 0; c < coluna; c++) {
            printf("informe um valor para a posição [%d,%d] da matriz:\n", l, c);
            scanf("%d", &matriz[l][c]);
            fflush(stdin);
        }
    }

    for(int l = 0; l < linha; l++) {
        for(int c = 0; c < coluna; c++) {
            printf("%d ", matriz[l][c]);

        }
    }


    return 0;
}