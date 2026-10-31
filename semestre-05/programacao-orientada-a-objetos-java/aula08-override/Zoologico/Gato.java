package Zoologico;

public class Gato extends Animal {
    @Override  // sobrepoe o método da classe mãe
    public void fazerSom(){
        System.out.println("O gato mia: Miau!");
    }
}
