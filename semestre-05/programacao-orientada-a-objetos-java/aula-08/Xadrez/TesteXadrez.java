package Xadrez;

public class TesteXadrez{
    public static void main(String[] args){
        peca Peao = new Peao();
        peca Rainha = new Rainha();
        peca Rei = new Rei();
        peca Bispo = new Bispo();
        peca Cavalo = new Cavalo();
        peca Torre = new Torre();

        Peao.mover();
        Rainha.mover();
        Rei.mover();
        Bispo.mover();
        Cavalo.mover();
        Torre.mover();

    }
}