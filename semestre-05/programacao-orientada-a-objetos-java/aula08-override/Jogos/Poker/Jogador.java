package Poker;

public class Jogador extends Participante {

    private String nome;

    public Jogador(String nome) {
        super();
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void mostrarCartas() {

        System.out.println("\nCartas de " + nome + ":");

        for (Carta carta : cartas) {
            System.out.println("- " + carta);
        }

        System.out.println("Pontuação: " + calcularPontuacao());
    }
}