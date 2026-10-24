//
// Created by juh on CLion
// v.1.0 11/19/25 - código inicial
// v.1.5 20/03/26 - limpeza da main e criação de várias funções! :D
// patchs futuros (se eu conseguir): modo contra o computador, criar versão com interface gráfica (GUI) e preciso atualizar o readme T_T
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m" // vermelho para 'X'
#define ANSI_COLOR_MAGENTA "\x1b[35m" // magenta para 'O'
#define ANSI_COLOR_RESET   "\x1b[0m"  // reseta a cor para o padrão do terminal

void imprime_tabuleiro(char tabuleiro[3][3]) { // base do tabuleiro
  system("clear"); // p/ Windows trocar > system("cls")

  printf("\n     1   2   3\n");
  printf("   -------------\n");

  for (int i = 0; i < 3; i++) {
    printf("%d  |", i + 1);

    for (int j = 0; j < 3; j++) {
      char simbolo = tabuleiro[i][j];

      if (simbolo == 'X') {
        printf(ANSI_COLOR_RED " %c " ANSI_COLOR_RESET, simbolo);
      } else if (simbolo == 'O') {
        printf(ANSI_COLOR_MAGENTA " %c " ANSI_COLOR_RESET, simbolo);
      } else {
        printf(" %c ", simbolo);
      }

      if (j < 2) {
        printf("|"); // separador vertical
      }
    }
    printf("|\n");
    if (i < 2) {
      printf("   |---|---|---|\n"); // separador horizontal
    }
  }
  printf("   -------------\n");
}

int verifica_vencedor(char t[3][3]) { // função de checagem de vitória
    for (int i = 0; i < 3; i++) {
        if (t[i][0] != ' ' && t[i][0] == t[i][1] && t[i][1] == t[i][2]) return 1; // checagem das linhas
        if (t[0][i] != ' ' && t[0][i] == t[1][i] && t[1][i] == t[2][i]) return 1; // checagem das colunas
    }

    if (t[0][0] != ' ' && t[0][0] == t[1][1] && t[1][1] == t[2][2]) return 1; // checagem da diagonal direita (\)
    if (t[0][2] != ' ' && t[0][2] == t[1][1] && t[1][1] == t[2][0]) return 1; // checagem da diagonal esquerda (/)

    return 0; // ninguém ganhou :(
}

int verifica_empate(int ganhou, int rodada) {
  if (ganhou == 0 && rodada == 9) {
    return 1; // empatou
  }
  return 0; // não empatou
}

void jogar() {
  char tabuleiro[3][3], jogador = 0;
  int i, j, linha, coluna, rodada;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tabuleiro[i][j] = ' '; // inicia preenchendo os espaços do tabuleiro com espaços vazios
    }
  }

  imprime_tabuleiro(tabuleiro); // chama a função e desenha o tabuleiro inicial ;)

  int ganhou = 0; // inicia a flag como falsa pq ninguém ganhou ainda né :P

  for (rodada = 1; rodada <= 9 && ganhou == 0; rodada++) { // loop máximo 9 rodadas e enquanto ninguém ganhar
    if (rodada % 2 == 1) { // usa o resto da divisão como determinador da vez do jogador 1 e 2
      jogador = 'X';
    } else {
      jogador = 'O';
    }

    do {
      printf("Digite as coordenadas (Linha e Coluna de 1 a 3) em que quer colocar o '%c': ", jogador);
      scanf("%d %d", &linha, &coluna);

      if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3) {
        printf("Ei! Posição inválida! Use somente valores de 1 a 3 para a linha e para a coluna.\n");
      } else if (tabuleiro[linha - 1][coluna - 1] != ' ') {
        printf("Ops.. Essa casa já tem dono! Escolha outra U.U\n");
      }

    } while (linha < 1 || linha > 3 ||
             coluna < 1 || coluna > 3 ||
             tabuleiro[linha - 1][coluna - 1] != ' ');

    tabuleiro[linha - 1][coluna - 1] = jogador; // coloca 'X' ou 'O' na posição correta (usa -1 para converter 1-3 para índices 0-2)
    imprime_tabuleiro(tabuleiro); // desenha o tabuleiro novamente mas com a nova jogada

    ganhou = verifica_vencedor(tabuleiro); // chama a função de verificar a vitória
    int empatou = verifica_empate(ganhou, rodada); // chamada da função de verificar empate

    if (ganhou == 1) {
      printf("\nParabéns! O jogador '%c' (%s%c%s) ganhou!\n", jogador, (jogador == 'X' ? ANSI_COLOR_RED : ANSI_COLOR_MAGENTA), jogador, ANSI_COLOR_RESET); // código para mostrar 'X' ou '0' com a cor certa
    }
    else if (empatou == 1) {
      printf("\nDeu velha! O jogo empatou T_T\n");
    }
  }
}

int main(void) {

  int escolha;

  do {
    printf("Bem vindo(a) a versão 2.0 do Jogo da Velha da Juh!\n");
    printf("Escolha uma opção: \n");
    printf("1 - Jogar\n2 - Sair\n");
    scanf("%d", &escolha);

    if (escolha == 2) {
      printf("Saindo... até mais!\n");
      break; // sai do do..while
    }

    if (escolha == 1) {
      jogar(); // função chamando o jogo
    } else {
      printf("Ops.. Opção Inválida! :P\n");
    }
  } while (1); // loop controlado pelo break

    return 0;
  }
