package Poker;

import java.util.ArrayList;

public class Mesa extends Participante {

    public Mesa() {
        super();
    }

    public void mostrarCartas() {

        System.out.println("\nCartas da mesa:");

        for (Carta carta : cartas) {
            System.out.println("- " + carta);
        }

        System.out.println("Pontuação da mesa: " + calcularPontuacao());
    }
}