package Zoologico;

public class Zoologico {
    public static void main(String[] args){
        Animal[] animais = new Animal[3];
        animais[0] = new Gato();
        animais[1] = new Cachorro();
        animais[2] = new Animal(); //objeto da classe mãe

        for(Animal animal:animais){
            animal.fazerSom(); // polimofirmo decide qual som fazer
        }
    }
}
