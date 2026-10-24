//
// Created by Juh on 15/03/2026 on CLion.
//

#include <stdio.h>
#include <stdlib.h>  // rand() e srand()
#include <time.h>    // time()

int dado() {
    return 1 + (rand() % 6); // gerar n°s aleatórios de 1 a 6
}

int maior(int num1, int num2, int num3) {
    if (num1 >= num2 && num1 >= num3) {
        return num1;
    }
    if (num2 >= num1 && num2 >= num3) {
        return num2;
    }
    return num3;
}

int menor(int num1, int num2, int num3) {
    if (num1 <= num2 && num1 <= num3) {
        return num1;
    }
    if (num2 <= num1 && num2 <= num3) {
        return num2;
    }
    return num3;
}

int iguais(int num1, int num2, int num3) {
    if (num1 == num2 && num2 == num3) {
        return 1;
    }
    return 0;
}

int main() {
    int num1, num2, num3;
    int escolha, rolagem;

    printf("MENU DE OPÇÔES DA JUH\n"
           "Digite o valor correspondente a sua escolha:\n");
    printf("1 - Lançamento de um dado de 4 faces\n"
           "2 - Comparação de 3 n°s inteiros\n");
    scanf("%d", &escolha);

    srand(time(NULL)); // chamada da função do dado alterada para fora do switch case

    switch (escolha) {
        case 1: {
            printf("Quantas vezes você quer rolar o dado?\n");
            scanf("%d", &rolagem);

            for (int i = 0; i < rolagem; i++) {
                printf("Lancamento %d: %d\n", i+1, dado());
            }
        } break;
        case 2: {
            printf("Informe 3 n°s inteiros:\n");
            scanf("%d %d %d", &num1, &num2, &num3);
            if (iguais(num1, num2, num3) != 1) {
                printf("O maior n° é: %d\n", maior(num1, num2, num3));
                printf("O menor n° é: %d\n", menor(num1, num2, num3));
            }

            else if (iguais(num1, num2, num3) == 1) {
                printf("Os n°os escolhidos são iguais!");
            }
        } break;
    }

    return 0;
}
