package Poker;

public class Carta {

    private String valor;
    private String naipe;
    private int pontos;

    public Carta(String valor, String naipe, int pontos) {
        this.valor = valor;
        this.naipe = naipe;
        this.pontos = pontos;
    }

    public String getValor() {
        return valor;
    }

    public String getNaipe() {
        return naipe;
    }

    public int getPontos() {
        return pontos;
    }

    public String toString() {
        return valor + " de " + naipe;
    }
}