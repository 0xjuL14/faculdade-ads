package Poker;

import java.util.ArrayList;

public abstract class Participante { // classe mãe

    protected ArrayList<Carta> cartas;

    public Participante() {
        cartas = new ArrayList <> ();
    }

    public void receberCarta(Carta carta) {
        cartas.add(carta);
    }

    public int calcularPontuacao() {

        int total = 0;

        for (Carta carta : cartas) {
            total += carta.getPontos();
        }

        return total;
    }

    public ArrayList<Carta> getCartas() {
        return cartas;
    }
}