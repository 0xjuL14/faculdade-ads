//
// Created by juh on 11/18/25 on CLion.
//

#include <stdio.h>
#include <locale.h>

#define qtdLin 5
#define qtdCol 5

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
            printf("Informe o elemento [%d][%d]: ",l+1,c+1);
            scanf("%d", &num[l][c]);
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

void localizaValor(int num[][qtdCol], int qtdLinhas, int qtdColunas, int alvo) {
    int encontrou = 0;
    for (int l = 0; l < qtdLinhas; l++) { // Percorre a matriz inteira
        for (int c = 0; c < qtdColunas; c++) {
            if (num[l][c] == alvo) { // Se o número atual for igual ao valor solicitado;
                printf("Encontrado! Localização: Linha %d, Coluna %d\n", l + 1, c + 1);
                encontrou = 1;
            }
        }
    }
    if (encontrou == 0) {
        printf("O valor %d não existe na matrix. \n", alvo);
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese-brazilian");

    int matriz[qtdLin][qtdCol], colInicial, linInicial;
    int valor;

    inicializaMatriz(matriz,qtdLin,qtdCol);
    leMatriz(matriz,qtdLin,qtdCol);
    escreveMatriz(matriz,qtdLin,qtdCol);

    printf("\n Informe um valor para localizar na matriz: \n");
    scanf("%d", &valor);
    localizaValor(matriz, qtdLin, qtdCol, valor);

    return 0;
}