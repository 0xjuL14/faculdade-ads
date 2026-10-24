//
// Created by juh on 11/18/25 on CLion.
//
// Tabuada

#include <stdio.h>
#include <locale.h>

#define qtdLin 10
#define qtdCol 10

void inicializaMatriz(int num[][qtdCol], int qtdLinhas, int qtdColunas) {
    for (int l = 0; l < qtdLinhas; l++) {
        for (int c = 0; c < qtdColunas; c++) {
            num[l][c] = 0;
        }
    }
}

void leMatriz(int num[][qtdCol], int qtdLinhas, int qtdColunas)
{
    for (int l = 0; l < qtdLinhas; l++)
    {
        for (int c = 0; c < qtdColunas; c++)
        {
            num[l][c] = (l + 1) * (c + 1);
        }
        printf("\n");
    }
    return;
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
    leMatriz(matriz,qtdLin,qtdCol);

    escreveMatriz(matriz,qtdLin,qtdCol);

    return 0;
}