//
// Created by juh on 11/18/25 on CLion.
//
// Matriz Identidade = 1 na diagonal principal e 0 no resto :)

#include <stdio.h>
#include <locale.h>

#define qtdLin 5
#define qtdCol 5

void inicializaMatriz(int num[][qtdCol], int qtdLinhas, int qtdColunas) {
    for (int l = 0; l < qtdLinhas; l++) {
        for (int c = 0; c < qtdColunas; c++) {
            if (l == c) {
                num[l][c] = 1;
            } else {
                num[l][c] = 0;
            }
        }
    }
}

void escreveMatriz(int num[][qtdCol], int qtdLinhas, int qtdColunas)
{
    for (int l = 0; l < qtdLinhas; l++)
    {
        printf("| ");
        for (int c = 0; c < qtdColunas; c++)
            printf("%2d ",num[l][c]);
        printf("|\n");
    }

    return;
}


int main()
{
    setlocale(LC_ALL, "portuguese-brazilian");

    int matriz[qtdLin][qtdCol], colInicial, linInicial;

    inicializaMatriz(matriz,qtdLin,qtdCol);
    escreveMatriz(matriz,qtdLin,qtdCol);

    return 0;
}