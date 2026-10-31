package Poker;

import java.util.Scanner;

public class Jogo {

    private Baralho baralho;
    private Jogador jogador;
    private Mesa mesa;
    private Scanner scanner;

    public Jogo() {

        baralho = new Baralho();
        mesa = new Mesa();
        scanner = new Scanner(System.in);
    }

    public void iniciar() {

        System.out.println("==============================");
        System.out.println("          JOGO DE 21");
        System.out.println("==============================");

        System.out.print("Digite seu nome: ");
        String nome = scanner.nextLine();

        jogador = new Jogador(nome);

        baralho.embaralhar();

        distribuirCartasIniciais();

        turnoJogador();
    }

    private void distribuirCartasIniciais() {

        jogador.receberCarta(baralho.pescarCarta());
        jogador.receberCarta(baralho.pescarCarta());

        mesa.receberCarta(baralho.pescarCarta());
        mesa.receberCarta(baralho.pescarCarta());

        jogador.mostrarCartas();

        System.out.println("\nCartas da mesa:");
        System.out.println("[ ??? ]");
        System.out.println("[ ??? ]");
    }

    private void turnoJogador() {

        while (true) {

            int pontuacao = jogador.calcularPontuacao();

            if (pontuacao > 21) {

                System.out.println("\n" + jogador.getNome()
                        + " passou de 21!");

                System.out.println(jogador.getNome()
                        + " perdeu!");

                return;
            }

            if (pontuacao == 21) {

                System.out.println("\n" + jogador.getNome()
                        + " chegou a 21!");

                break;
            }

            System.out.println("\n------------------------------");
            System.out.println("1 - Comprar carta");
            System.out.println("2 - Parar");
            System.out.println("------------------------------");

            System.out.print("Escolha: ");

            int opcao = scanner.nextInt();

            if (opcao == 1) {

                Carta carta = baralho.pescarCarta();

                jogador.receberCarta(carta);

                System.out.println("\n" + jogador.getNome()
                        + " pescou:");

                System.out.println(carta);

                jogador.mostrarCartas();

            } else if (opcao == 2) {

                break;

            } else {

                System.out.println("Opção inválida!");
            }
        }

        turnoMesa();
    }

    private void turnoMesa() {

        System.out.println("\n==============================");
        System.out.println("          VEZ DA MESA");
        System.out.println("==============================");

        int pontuacaoMesa = mesa.calcularPontuacao();

        while (pontuacaoMesa < 17) {

            System.out.println("\nA mesa possui "
                    + pontuacaoMesa + " pontos.");

            System.out.println("A mesa irá comprar uma carta.");

            Carta carta = baralho.pescarCarta();

            mesa.receberCarta(carta);

            System.out.println("A mesa comprou uma carta.");

            pontuacaoMesa = mesa.calcularPontuacao();
        }

        if (pontuacaoMesa > 21) {

            System.out.println("\nA mesa passou de 21!");

        } else {

            System.out.println("\nA mesa parou com "
                    + pontuacaoMesa + " pontos.");
        }

        finalizarJogo();
    }

    private void finalizarJogo() {

        System.out.println("\n==============================");
        System.out.println("       REVELANDO A MESA");
        System.out.println("==============================");

        mesa.mostrarCartas();

        int pontosJogador = jogador.calcularPontuacao();
        int pontosMesa = mesa.calcularPontuacao();

        System.out.println("\n" + jogador.getNome()
                + ": " + pontosJogador + " pontos");

        System.out.println("Mesa: " + pontosMesa + " pontos");

        if (pontosJogador > 21) {

            System.out.println("\n" + jogador.getNome()
                    + " perdeu!");

        } else if (pontosMesa > 21) {

            System.out.println("\nA mesa passou de 21!");

            System.out.println(jogador.getNome()
                    + " venceu!");

        } else if (pontosJogador > pontosMesa) {

            System.out.println("\n" + jogador.getNome()
                    + " venceu!");

        } else if (pontosJogador < pontosMesa) {

            System.out.println("\nA mesa venceu!");

        } else {

            System.out.println("\nEmpate!");
        }
    }
}