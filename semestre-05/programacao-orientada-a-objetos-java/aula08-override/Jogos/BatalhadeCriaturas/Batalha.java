package BatalhadeCriaturas;

public class Batalha {
    public static void main(String[] args){
        Criatura CriaturaFogo = new CriaturaFogo();
        Criatura CriaturaAgua = new CriaturaAgua();
        Criatura CriaturaPlanta = new CriaturaPlanta();

        CriaturaFogo.atacar();
        CriaturaPlanta.atacar();
        CriaturaAgua.atacar();
    }
}
