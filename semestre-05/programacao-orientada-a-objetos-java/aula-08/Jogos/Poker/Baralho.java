package Poker;

import java.util.ArrayList;
import java.util.Collections;

public class Baralho {

    private ArrayList<Carta> cartas;

    public Baralho() {
        cartas = new ArrayList <> ();
        criarBaralho();
    }

    private void criarBaralho() {

        String[] naipes = {
                "Copas",
                "Ouros",
                "Paus",
                "Espadas"
        };

        String[] valores = {
                "Ás",
                "2",
                "3",
                "4",
                "5",
                "6",
                "7",
                "8",
                "9",
                "10",
                "Valete",
                "Dama",
                "Rei"
        };

        for (String naipe : naipes) {

            for (String valor : valores) {

                int pontos;

                switch (valor) {

                    case "Ás":
                        pontos = 1;
                        break;

                    case "Valete":
                    case "Dama":
                    case "Rei":
                        pontos = 10;
                        break;

                    default:
                        pontos = Integer.parseInt(valor);
                }

                cartas.add(new Carta(valor, naipe, pontos));
            }
        }
    }

    public void embaralhar() {
        Collections.shuffle(cartas);
    }

    public Carta pescarCarta() {

        if (cartas.isEmpty()) {
            return null;
        }

        return cartas.remove(0);
    }

    public int quantidadeCartas() {
        return cartas.size();
    }
}